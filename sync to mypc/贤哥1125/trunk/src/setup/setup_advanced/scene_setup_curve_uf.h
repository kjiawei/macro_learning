/*****************************************************
** 作者： Huangjunxian
** 创始时间：2014-11-18
** 修改人：Huangjunxian
** 修改时间：2014-11-26
** 描述：
**    UF曲线功能 《头文件》
*****************************************************/
#ifndef SCENE_SETUP_CURVE_UF_H
#define SCENE_SETUP_CURVE_UF_H

#include <QtGui>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QBrush>

#include "data_custom.h"
#include "config_ui.h"
#include "lang_switch.h"
#include "page_info.h"
#include "common_customwidget.h"

class SceneSetupCurveUF;

extern bool ufEnableEdit; //预定义曲线是否可编辑 true 可以 false 不可以#/
extern char select_ufcure_num;   //从外部进来该页面时，选择的曲线#/

/*-------------------------柱状图类-------------------------------*/
//每个治疗时段的柱状图类#/
class ColumnarCurveUf: public QLabel
{
    Q_OBJECT

public:
    ColumnarCurveUf(QWidget *parent,SceneSetupCurveUF *p,int x,int y,int order);
    void setShow(bool vis);
    float reviseCurve(float oldvalue,float newvalue);
    void calHandle(float value, bool add=true);

protected:
    void mousePressEvent(QMouseEvent *ev); //点击事件#/
    void mouseMoveEvent(QMouseEvent *ev); //鼠标移动事件#/
    void mouseReleaseEvent(QMouseEvent *ev);//鼠标释放事件#/
    void focusInEvent(QFocusEvent *ev);//焦点选中#/
    void focusOutEvent(QFocusEvent *ev);//失去焦点#/
    void paintEvent(QPaintEvent *);//重绘事件#/

private:
    inline void setUi();

public:
    bool seqMode; // false：HD模式  true：SEQ模式#/
    int orderNum;//本柱状图编号#/
    float ufrate;//平均超滤量的百分比 0---200#/
    float periodTime;//本治疗时段对应的时间长度 单位min#/
    char selectMark; //是否选择本柱状图#/

private:
    int xAxis; //本柱状图的x坐标#/
    int yAxis;//y坐标#/
    bool passMark; //点击标记#/
    SceneSetupCurveUF *topscene; //为了操控上层页面的控件而定义#/
    QLabel labeltop;  //柱状图顶部显示数据 超滤率=平均超滤量*百分比 [ml/h]#/
    QLabel labelbottom; //柱状图底部显示数据 超滤量=超滤率*该段时间#/
};

/*-------------------------UF曲线显示编辑页面类-------------------------------*/
//UF曲线显示编辑页面类#/
class SceneSetupCurveUF:public QObject,public ActionCustom,public PieceVisible,public LangSetText
{
    Q_OBJECT

public:
    SceneSetupCurveUF(QWidget *parent=0); //构造函数#/
    ~SceneSetupCurveUF();
    void CustomSetText(); //设置相应的显示文字#/
    void setCusVisible(bool vis=false,char* para=NULL);//显示调用函数#/
    void ActionHandle(const void* dataPtr=NULL, int name=0);

private:
    inline void setUi();

public:
    //相应的变量#/
    int nowSelectCurve; //当前选择的曲线号#/
    int nowSelectNum;   //当前选择的治疗时段#/
    ColumnarCurveUf *curveArray[10]; //指向柱状图的指针，默认数量是10个#/
    //各种文本标签#/
    QLabel labelTitleTop;
    QLabel labelPrompt;
    QLabel labelYaxisUnit;
    QLabel labelLeftTop;
    QLabel labelLeftMiddle;
    QLabel labelRightTop;
    QLabel labelRightMiddle;
    QLabel labelCurveNum;
    QLabel labelSumUF;
    QLabel labelSumTime;
    QLabel labelPeriodTime;
    QLabel labelCurveTime;
    QLabel labelTopUnit;
    QLabel labelBottomUnit;
    //y坐标轴标签#/
    QLabel label200;
    QLabel label150;
    QLabel label100;
    QLabel label50;
    QLabel label0;
    //每个治疗时段数值编辑框#/
    MyLineEdit lineEditSetNum;
    //页面相应的按钮#/
    QPushButton buttonHD;//HD模式#/
    QPushButton buttonSEQ;//SEQ模式#/
    QPushButton buttonSelectAdd;//曲线选择+#/
    QPushButton buttonSelectSub;//曲线选择-#/
    QPushButton buttonSave; //保存#/
    QPushButton buttonOk;//应用按钮#/
    QPushButton buttonCancel;//返回按钮#/

public slots:
    void selectedCurve(int num);

protected slots:
    void lineEditInFocus(); //编辑框选中时#/
    void buttonHDClicked();//HD按钮点击时#/
    void buttonSEQClicked();//SEQ按钮点击#/
    void selectAddClicked();
    void selectSubClicked();
    void buttonSaveClicked();//保存按钮#/
    void buttonOkClicked();//应用按钮点击#/
    void buttonCancelClicked();
};






#endif
