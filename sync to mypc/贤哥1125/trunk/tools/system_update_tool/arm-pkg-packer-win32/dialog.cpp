#include "dialog.h"
#include <QFileDialog>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"
#include "crc32.h"
#include "cmd.h"

dialog::dialog(QWidget *parent) :QDialog(parent)
{
    //
    FILE *fp;
    //
    char *product_file_name = (char *)"product.ini";
    //
    char *module_file_name = (char *)"module.ini";
    //
    errorMessageDialog = new QErrorMessage(this);
    //�����������ļ���һ�����ݵ��á�
    char linebuf[4096];
    //
    char *ch;
    //
    QString str;

    int i;

    QRect rect;

    char *pos;

    product_label = new QLabel(tr("product"),this);
    rect.setRect(20,30,54,12);
    product_label->setGeometry(rect);

    product_combo = new QComboBox(this);
    rect.setRect(80,20,69,22);
    product_combo->setGeometry(rect);

    //���ö�̬�Ĳ�Ʒ�ͺ�
    fp = fopen(product_file_name,"r");
    if (fp == NULL)
    {
        errorMessageDialog->showMessage(tr("can not open config product"));
        return ;
    }

    memset(&linebuf[0],0,sizeof(linebuf));
    while(fgets(linebuf,4096,fp))
    {
        //ȥ���س����з�
        ch  = &linebuf[0];
        while (*ch != '\0')
        {
            if ( (*ch == '\n') || (*ch == '\r') )
            {
                *ch = '\0';
                break;
            }
            ch++;
        }

        //��Ӳ�Ʒ��
        str = QString(QLatin1String(linebuf));
        product_combo->addItem(str);
        memset(&linebuf[0],0,sizeof(linebuf));
    }

    fclose(fp);

    //
    fp = fopen(module_file_name,"r");
    if (fp == NULL)
    {
        errorMessageDialog->showMessage(tr("can not open module file"));
        return;
    }

    memset(&linebuf[0],0,sizeof(linebuf));
    count = 0;
    while(fgets(linebuf,4096,fp))
    {
        //ȥ���س����з�
        ch  = &linebuf[0];
        while (*ch != '\0')
        {
            if ( (*ch == '\n') || (*ch == '\r') )
            {
                *ch = '\0';
                break;
            }
            ch++;
        }

        pos = strstr(linebuf," ");
        if (pos != NULL)
        {
            *pos = '\0';
            pos++;
            i = 0;
        }
        else
        {
            errorMessageDialog->showMessage(tr("can not load tag"));
            return ;
        }

        memset(module[count].tag,0,sizeof(module[count].tag));
        while ( (*pos != ' ') && (*pos != '\0') )
        {
            module[count].tag[i]= *pos;
            *pos = '\0';
            i++;
            pos++;
        }

        //
        str = QString(QLatin1String(linebuf));
        module[count].check = new QCheckBox(str,this);
        rect.setRect(30,70 + (40*count),91,16);
        module[count].check->setGeometry(rect);

        module[count].edit = new QLineEdit(this);
        rect.setRect(130,70 + (40*count),201,20);
        module[count].edit->setGeometry(rect);

        str = ".....";
        module[count].button = new CMyButton(str,this);
        rect.setRect(340,70 +(40*count),31,23);
        module[count].button->setGeometry(rect);
        module[count].button->setId(count);

        connect(module[count].button,
                SIGNAL(ClickedEvent(int)),
                this,
                SLOT(module_Button_clicked(int)));

        count++;
        memset(&linebuf[0],0,sizeof(linebuf));
    }

    fclose(fp);

    output_label = new QLabel(tr("output file"),this);
    rect.setRect(30,70 + (40*count),80,20);
    output_label->setGeometry(rect);

    output_Edit = new QLineEdit(this);
    rect.setRect(130,70 + (40*count),201,20);
    output_Edit->setGeometry(rect);

    str = ".....";
    output_Button = new QPushButton(str,this);
    rect.setRect(340,70 + (40*count),31,23);
    output_Button->setGeometry(rect);

    connect(output_Button,
            SIGNAL(clicked()),
            this,
            SLOT(output_Button_clicked()));

    str = "pack";
    pack_Button = new QPushButton(str,this);
    rect.setRect(24 ,110 + (40*count),351,23);
    pack_Button->setGeometry(rect);

    connect(pack_Button,
            SIGNAL(clicked()),
            this,
            SLOT(pack_Button_clicked()));

    if (output_Edit->text() == "")
    {
        str = "c:\\update.pkg";
        output_Edit->setText(str);
    }
}

dialog::~dialog()
{
    delete errorMessageDialog;
}


void dialog::module_Button_clicked(int i)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "c:\\",
                                                     tr("bin (*.bin)"));

    if (!fileName.isEmpty())
        module[i].edit->setText(fileName);
}

void dialog::output_Button_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                "c:\\update.pkg",
                                tr("pkg (*.pkg)"));

    if (!fileName.isEmpty())
        output_Edit->setText(fileName);
}

void dialog::pack_Button_clicked()
{
    FILE *fp;
    FILE *tmp_file;
    struct Args_t args;
    char buf[2048];
    char lf[3] = "\n";
    int i;

    if (product_combo->currentIndex() ==  -1)
    {
        errorMessageDialog->showMessage(tr("you no choose product type"));
        return ;
    }

    fp = fopen("pack.cfg","w");
    if (fp == NULL)
    {
        errorMessageDialog->showMessage(tr("can build config file"));
        return ;
    }

    for(i=0;i<count;i++)
    {
        if (module[i].check->checkState() == Qt::Checked)
        {
            tmp_file = fopen(module[i].edit->text().toLatin1().data(),"rb");
            if (tmp_file == NULL)
            {
                errorMessageDialog->showMessage(tr("no exist input file"));
                fclose(fp);
                return ;
            }
            else
            {
                fclose(tmp_file);
            }
        }
    }


    for(i=0;i<count;i++)
    {
        if (module[i].check->checkState() == Qt::Checked)
        {
            memset(buf,0,sizeof(buf));
            strcpy(buf,"tag=");
            strcat(buf,module[i].tag);
            strcat(buf," ");
            strcat(buf,"input=");
            strcat(buf,module[i].edit->text().toLatin1().data());
            fwrite(&buf[0],strlen(buf),1,fp);
            fwrite(lf,strlen(lf),1,fp);
        }
    }

    fclose(fp);

    args.configFileName = (char *)"pack.cfg";
    args.outFile = NULL;
    args.outFileName = output_Edit->text().toLatin1().data();
    args.productName = product_combo->currentText().toLatin1().data();

    pkg(args);
}

//�����ļ���С
uint32_t dialog::get_file_size(const char *filename)
{
    unsigned long size;
    FILE* fp = fopen( filename, "rb" );

    if(fp==NULL)
    {
        errorMessageDialog->showMessage(tr("ERROR: Open file %s failed.\n", filename));
        return 0;
    }

    fseek( fp, SEEK_SET, SEEK_END );
    size=ftell(fp);

    fclose(fp);
    return size;
}

int dialog::pkg(struct Args_t args)
{
    //�����ļ�������˵��Ҫ�����Щ�ļ����ļ�
    FILE *config_file = NULL;
    //�����ļ������������ļ������һ����ļ�
    FILE *input_file = NULL;
    //�����������ļ���һ�����ݵ��á�
    char linebuf[4096];
    //�����ļ�������
    char input_file_name[1024];
    //���ڷ����Ͷ�λtag��input�ȹؼ�������
    char *tag_pos,*input_pos,*tag_value_pos,*input_value_pos;
    //����Ľṹ
    UPDATE_PKG pkg;
    //���������ж��ٸ���Ҫ��������
    uint32_t target_components_num;
    //������ʱ��Ŵ�����������data��һ������
    struct TMP_DATA * data = NULL;
    struct TMP_DATA * first_data = NULL;
    struct TMP_DATA * tmp_data = NULL;
    //������ʱ��Ŵ�������compoent
    TARGET_COMPONENT component[256];
    P_TARGET_COMPONENT p_component;
    //������
    uint32_t i;

    //�������ļ�
    config_file = fopen(args.configFileName,"r");
    if (config_file == NULL)
    {
        errorMessageDialog->showMessage(tr("can not open config file"));
        return false;
    }

    //������������
    target_components_num = 0;

    //ѭ������ȡ�����ļ���ÿһ�У�Ȼ����ʱ���ڻ�������
    while(fgets(linebuf,4096,config_file))
    {
        //����tag��
        tag_pos = strstr(linebuf,"tag");
        //����input��
        input_pos = strstr(linebuf,"input");

        //û���ҵ�tag�����������������
        if (tag_pos == NULL)
        {
            errorMessageDialog->showMessage(tr("can not find tag,must be have tag"));
            fclose(config_file);
            return false;
        }

        //û���ҵ�input�����������������
        if (input_pos == NULL)
        {
            errorMessageDialog->showMessage(tr("can not find input,must be have input"));
            fclose(config_file);
            return false;
        }

        //����tag���input��ģ���
        tag_value_pos = strstr(tag_pos,"=");
        input_value_pos = strstr(input_pos,"=");

        //û�в��ҵ�=�ţ����������������ء����ҵ����Ͷ�=��һ��λ��
        if ( tag_value_pos != NULL )
        {
            tag_value_pos++;
        }
        else
        {
            errorMessageDialog->showMessage(tr("can not find = , must be have ="));
            return false;
        }

        //û�в��ҵ�=�ţ����������������ء����ҵ����Ͷ�=��һ��λ��
        if ( input_value_pos != NULL )
        {
            input_value_pos++;
        }
        else
        {
            printf("can not find = , must be have =\n");
            printf("\n");
            return false;
        }

        //������comonent��λ��
        p_component = (P_TARGET_COMPONENT) (&component[target_components_num]);

        //
        memset(&p_component->reserved[0],0,sizeof(p_component->reserved));
        memset(&p_component->tag[0],0,sizeof(p_component->tag));

        //input�����ƶ�ȡ����input�Ⱥź�����ַ���
        i = 0;
        memset(&input_file_name[0],0,sizeof(input_file_name));
        while ( ( *input_value_pos != ' ' ) &&  ( *input_value_pos != '\r' ) &&( *input_value_pos != '\n' )  )
        {
            *(input_file_name + i) = *input_value_pos;
            input_value_pos++;
            i++;
        }

        //tag�����ƶ�ȡ����tag�Ⱥź�����ַ���
        i = 0;
        memset(&p_component->tag[0],0,sizeof(p_component->tag));
        while ( ( *tag_value_pos != ' ' ) &&  ( *tag_value_pos != '\r' ) && ( *tag_value_pos != '\n' )  )
        {
            p_component->tag[i] = *tag_value_pos;
            tag_value_pos++;
            i++;
        }

        //�������ļ�����һ�������ڵ��ļ����ʹ���֪ͨ�����˳�
        input_file = fopen(input_file_name,"rb");
        if ( input_file == NULL )
        {
            errorMessageDialog->showMessage(tr("can not find input file\n"));
            return false;
        }

        //��ȡ����ļ��Ĵ�С
        p_component->data_size = get_file_size(input_file_name);

        //�������ļ���С�ڵ���0������󣬲�����
        if (p_component->data_size <= 0)
        {
            errorMessageDialog->showMessage(tr("input file length is less than or equ 0"));
            fclose(config_file);
            fclose(input_file);
            return false;
        }

        //���仺�������
        data = (struct TMP_DATA *)malloc(sizeof(struct TMP_DATA));
        if (data == NULL)
        {
            printf("can't malloc\n");
        }

        //���������С�����仺��������ļ���С
        data->data = (uint8_t *)malloc(p_component->data_size);
        if (data->data == NULL)
        {
            errorMessageDialog->showMessage(tr("can't malloc"));
        }

        //����������ݣ�д���������ȥ��
        fread(data->data,p_component->data_size,1,input_file);
        fclose(input_file);

        //���û�������Ĵ�С
        data->size = p_component->data_size;

        //�ѻ����������ȥ�����������������ȥ
        if ( target_components_num == 0 )
        {
            tmp_data = data;
            first_data = data;
            data->next = NULL;
        }
        else
        {
            tmp_data->next = data;
            tmp_data = tmp_data->next;
            data->next = NULL;
        }

        //��ȡ�����������һ
        target_components_num++;
    }

    fclose(config_file);

    //��ȡ�����ļ������ǲ���ֻ������0�
    if ( target_components_num <= 0 )
    {
        errorMessageDialog->showMessage(tr("target_componets_num is less than or equ 0"));
        return false;
    }

    //����pkg��ֻ����һ���֡�
    memset(&pkg.product_tag[0],0,sizeof(pkg.product_tag));
    memcpy(&pkg.product_tag[0],args.productName,strlen(args.productName));
    pkg.target_components_num = target_components_num;

    //����crc
    pkg.CRC = 0xffffffff;
    pkg.CRC = my_crc32(pkg.CRC,(const unsigned char *)&pkg.product_tag[0],sizeof(pkg.product_tag));
    pkg.CRC = my_crc32(pkg.CRC,(const unsigned char *)&pkg.target_components_num,sizeof(pkg.target_components_num));
    pkg.CRC = my_crc32(pkg.CRC,(const unsigned char *)&component[0],sizeof(TARGET_COMPONENT)*pkg.target_components_num);

    tmp_data = first_data;

    for(i=0;i<pkg.target_components_num;i++)
    {
        pkg.CRC = my_crc32(pkg.CRC,tmp_data->data,tmp_data->size);
        tmp_data = tmp_data->next;
    }

    //���ɴ���ļ�
    args.outFile = fopen(args.outFileName,"wb+");
    if (args.outFile == NULL)
    {
        errorMessageDialog->showMessage(tr("output file fail"));
        tmp_data = first_data;
        for(i=0;i<pkg.target_components_num;i++)
        {
            first_data = tmp_data->next;
            tmp_data->next = NULL;
            free(tmp_data->data);
            free(tmp_data);
            tmp_data = first_data;
        }
        return false;
    }

    fwrite(&pkg.CRC,sizeof(pkg.CRC),1,args.outFile);
    fwrite(&pkg.product_tag[0],sizeof(pkg.product_tag),1,args.outFile);
    fwrite(&pkg.target_components_num,sizeof(pkg.target_components_num),1,args.outFile);
    fwrite(&component[0],sizeof(TARGET_COMPONENT) * pkg.target_components_num,1,args.outFile);

    tmp_data = first_data;

    for(i=0;i<pkg.target_components_num;i++)
    {
        fwrite(tmp_data->data,tmp_data->size,1,args.outFile);
        first_data = tmp_data->next;
        tmp_data->next = NULL;
        free(tmp_data->data);
        free(tmp_data);
        tmp_data = first_data;
    }

    fclose(args.outFile);

    errorMessageDialog->showMessage(tr("finish"));

    return true;
}
