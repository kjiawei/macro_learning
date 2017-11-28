#include "../gui/gui/core/GUI.h"
#include "../app/mygui.h"
#include	"../ucos-ii/includes.h"               /* uC/OS interface */
#include "../gui/gui/widget/Edit.h"
#include "../gui/gui/Widget/PROGBar.h"
#include "../mygui/jihua.h"
#include "../mygui/extern_var.h"

#if KTV

#define EDITHP    20                       //�༭��߶�
#define EDIT1LP   12                       //һλ���ݱ༭�򳤶�
#define EDIT2LP   20                       //һλ���ݱ༭�򳤶�
#define EDIT3LP   26                       //һλ���ݱ༭�򳤶�
#define EDIT4LP   40         

#define EDITH     40                       //�༭��߶�
#define EDIT1L    24                       //һλ���ݱ༭�򳤶�
#define EDIT2L    40                       //һλ���ݱ༭�򳤶�
#define EDIT3L    55                       //һλ���ݱ༭�򳤶�
#define EDIT4L    70 

#define EDITHM    30                       //�༭��߶�
#define EDIT1LM   16                       //һλ���ݱ༭�򳤶�
#define EDIT2LM   24                       //һλ���ݱ༭�򳤶�
#define EDIT3LM   50                       //һλ���ݱ༭�򳤶�
#define EDIT4LM   60 

#define  GUI_STOP    0xa0c0a0//0xaaaaaa
#define  GUI_RUN     0x00ff00

#define PANOX      2
#define PANOY      UPY+2
#define PANOL      636
#define PANOH      476

#define PANX2      (PANOX+PANOL)
#define PANY2      (PANOY+PANOH)


#define ARAE1L     444
#define ARAE2L     174

#define ARAE1X1    (PANOX+6)
#define ARAE1X2    (ARAE1X1+ARAE1L)
#define ARAE1Y1    (PANOY+70) 
#define ARAE1Y2    476

#define ARAE2X1    (ARAE1X2+6)
#define ARAE2X2    (ARAE2X1+ARAE2L)
#define ARAE2Y1    (PANOY+36)
#define ARAE2Y2    (ARAE2Y1+140)

#define ARAE3X1    ARAE2X1
#define ARAE3X2    ARAE2X2
#define ARAE3Y1    (ARAE2Y2+20)
#define ARAE3Y2    (ARAE3Y1+198)

#define KEYX       (ARAE2X1+6)
#define KEYY       (ARAE3Y1+20)

#define BUTEXITL   96
#define BUTEXITH   34
#define BUTEXITX   (PANX2-BUTEXITL-16)
#define BUTEXITY   (ARAE3Y2+8)

#define BUTSELL    70
#define BUTSELH    30
#define BUTSELLL   88
#define BUTSELX    (ARAE1X1+5)    
#define BUTSELY    (ARAE1Y1-32)

#define CHAR1X     (ARAE1X1+5)  //440
#define CHAR1Y     (ARAE1Y1+8) 

#define CHAR2X     (ARAE2X1+5) //160
#define CHAR2Y     (ARAE2Y1+12)
 
#define A2CHARX1   (ARAE2X1+10)
#define A2EDITX1   (A2CHARX1+40) 
#define A2DANX1    (A2EDITX1+EDIT4LP+4)

#define A2CHARY1   (CHAR2Y+6)
#define A2EDITY1   (A2CHARY1+8-EDITHP/2)
#define A2DANY1    (A2CHARY1+2)


#define A2CHARX2   (A2DANX1+20)
#define A2EDITX2   (A2CHARX2+40) 
#define A2DANX2    (A2EDITX2+EDIT4LP+4)

#define A2YY       30 
#define A2CHARY2   (A2CHARY1+A2YY)
#define A2EDITY2   (A2EDITY1+A2YY)
#define A2DANY2    (A2DANY1+A2YY)
 
#define A2CHARY3   (A2CHARY2+A2YY+16)
#define A2EDITY3   (A2EDITY2+A2YY+16)
#define A2DANY3    (A2DANY2+A2YY+16)

#define A2CHARY4   (A2CHARY3+A2YY)
#define A2EDITY4   (A2EDITY3+A2YY)
#define A2DANY4    (A2DANY3+A2YY) 
 
#define A2EDIT1X  (ARAE2X1+20)
#define A2EDIT1Y  (CHAR2Y+20)
#define A2EDIT2X  (A2EDIT1X+ARAE2L/2-6)

#define A2CHAR1X  (A2EDIT1X+EDIT3LM/2-16)
#define A2CHAR1Y  (A2EDIT1Y-18)
#define A2CHAR2X  (A2EDIT2X+EDIT3LM/2-16)

#define A2DAN1X   (A2EDIT1X+EDIT3LM+4)
#define A2DAN1Y   (A2EDIT1Y+EDITHM/2-8)
#define A2DAN2X   (A2EDIT2X+EDIT3LM+4)

#define KTVCHARX1  (ARAE1X1+300)
#define KTVEDITX1  (KTVCHARX1+70)
#define KTVDANX1   (KTVEDITX1+34)

#define KTVCHARY1  (CHAR1Y+20)
#define KTVEDITY1  (KTVCHARY1-12)
#define KTVDANY1   KTVCHARY1

#define URRCHARX   (ARAE1X1+30)
#define URREDITX   (URRCHARX+180)
#define URRDANX    (URREDITX+80)

#define URRCHARY1  (CHAR1Y+120)
#define URREDITY1  (URRCHARY1-12)
#define URRDANY1   (URRCHARY1)

#define URRYY      60

#define URRCHARY2  (URRCHARY1+URRYY)
#define URREDITY2  (URREDITY1+URRYY)
#define URRDANY2   (URRDANY1+URRYY)

#define URRCHARY3  (URRCHARY2+URRYY)
#define URREDITY3  (URREDITY2+URRYY)
#define URRDANY3   (URRDANY2+URRYY)
//
#define PCRCHARX   (ARAE1X1+30)
#define PCREDITX   (PCRCHARX+180)
#define PCRDANX    (PCREDITX+EDIT4LM+10)

#define PCRCHARY1  (CHAR1Y+120)
#define PCREDITY1  (PCRCHARY1-8)
#define PCRDANY1   (PCRCHARY1)

#define PCRYY      40

#define TACCHARX   (ARAE1X1+30)
#define TACEDITX   (TACCHARX+180)
#define TACDANX    (TACEDITX+70)

#define TACCHARY1  (CHAR1Y+120)
#define TACEDITY1  (TACCHARY1-8)
#define TACDANY1   (TACCHARY1)

#define TACYY      40

#define ARAEHCOX1   50
#define ARAEHCOX2   (ARAEHCOX1+380)
#define ARAEHCOY1   214
#define ARAEHCOY2   (ARAEHCOY1+210)

#define SCALESTARTX  (ARAEHCOX1)
#define SCALESTARTY  (ARAEHCOY2)  

#define SCALEHIGH    10
#define SCALELONG    60

#define KTVDDLJBX  (ARAE1X1+50)
#define KTVDDLJBY  (ARAEHCOY1+35)
#define KTVDDLPBX  (KTVDDLJBX+BUTSELL+20)
#define KTVDDLPBL  200

#define KTVNOX     100
#define KTVNOY     (KTVDDLJBY+40) 

#define KTVDDLJTIME  400 

#define DISKTV       0
#define DISURR       1
#define DISSRI       2
#define DISPCR       3
#define DISTAC       4   

#define BSELCOLOR     0xe0f0e0
#define BNSELCOLOR    0xa0c0a0

extern WM_HWIN  WM__hWinFocus;

static EDIT_Handle SaveEdit;
static EDIT_Handle hEdit[8];
static RADIO_Handle hRadio[2];
static BUTTON_Handle KTVButton[5];
static BUTTON_Handle KTVButtonS1;
static BUTTON_Handle KTVButtonExit; 
static PROGBAR_Handle hProgBar;

static INT16U ui_st_ddl_before,ui_st_ddl_after;
static INT16U ui_ddl_before_back,ui_ddl_after_back;
static INT8U  uc_st_by_pass_back;
static INT8U DisMode; 
static INT16U Ct,Co,Co2;
static INT16U DDL_J_Time;

static void DelKTV(void);
static void stop_ddl_jz_cancel_pl(void);
static MYBOOL StartDDLJ(void);
static void DDLJWork(void);
extern INT16U abs_absolute(INT16U ui_temp_data_a, INT16U ui_temp_data_b);

static void AraeaInit(INT16U y )
    {
    GUI_SetColor(0x608060);
    GUI_FillRect(ARAE1X1+2, ARAE1Y1,ARAE1X2-2, ARAE1Y2-2);
    GUI_SetColor(0x204020);
    GUI_DrawLine(ARAE1X1+1,y, ARAE1X2-1,y); 
    GUI_SetColor(0xa0c0a0);
    GUI_DrawLine(ARAE1X1+1,y+1, ARAE1X2-1,y+1); 
    }
    
static void AraeaInit2(INT16U y)
    {
    //x
    GUI_SetColor(0x608060);
    GUI_FillRect(ARAE1X1+2, ARAE1Y1,ARAE1X2-2, ARAE1Y2-2);
    GUI_SetColor(0x204020);
    GUI_DrawLine(ARAE1X1+1,y,ARAE1X2-1 ,y); 
    GUI_SetColor(0xa0c0a0);
    GUI_DrawLine(ARAE1X1+1,y+1, ARAE1X2-1,y+1); 
    
    //y1
    GUI_SetColor(0x204020);
    GUI_DrawLine(KTVCHARX1+5,ARAE1Y1,KTVCHARX1+5 ,ARAE1Y1+70); 
    GUI_SetColor(0xa0c0a0);
    GUI_DrawLine(KTVCHARX1+5+1,ARAE1Y1, KTVCHARX1+5+1,ARAE1Y1+70+1);
    
    //x1
    GUI_SetColor(0x204020);
    GUI_DrawLine(KTVCHARX1+5,ARAE1Y1+70,ARAE1X2-1 ,ARAE1Y1+70); 
    GUI_SetColor(0xa0c0a0);
    GUI_DrawLine(KTVCHARX1+5+1,ARAE1Y1+70+1, ARAE1X2-1,ARAE1Y1+70+1);
    
    }    
    
static void ktv_init_add(void)
    {
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS); 
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        GUI_DisHzAt("���֧� �էڧѧݧڧ�", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DisHzAt("����ݧ� �էڧѧݧڧ٧�", KTVDDLJBX, KTVDDLJBY+160+8);         
        
        #elif COUNTRY == COUNTRY_SA
        GUI_SetFont(&GUI_Font16B_1);    
        GUI_DispStringAt("Pre-di�lisis", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DispStringAt("Post-di�lisis", KTVDDLJBX, KTVDDLJBY+160+8); 
        
        #elif COUNTRY == FARMARIN
        GUI_SetFont(&GUI_Font16B_1);    
        GUI_DispStringAt("Dialisato Novo", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DispStringAt("Dialisato Usado", KTVDDLJBX, KTVDDLJBY+160+8);
        
        #elif COUNTRY == COUNTRY_TNS
        GUI_SetFont(&GUI_Font16B_1);    
        GUI_DispStringAt("Pr?dialyse", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DispStringAt("Post-dialyse", KTVDDLJBX, KTVDDLJBY+160+8); 
        
        #else
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DisHzAt("͸ǰ�絼��", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DisHzAt("͸��絼��", KTVDDLJBX, KTVDDLJBY+160+8);                 
        #endif
        }
    else
        {
        GUI_SetFont(&GUI_Font16B_1);    
        GUI_DispStringAt("Pre-dialysis", KTVDDLJBX, KTVDDLJBY+100+8);  
        GUI_DispStringAt("post-dialysis", KTVDDLJBX, KTVDDLJBY+160+8); 
        }    
    GUI_SetFont(&GUI_Font16_1);
    GUI_DispStringAt("mS/cm",KTVDDLJBX+160, KTVDDLJBY+100+6);
    GUI_DispStringAt("mS/cm",KTVDDLJBX+160, KTVDDLJBY+160+6);
    ui_ddl_before_back = 0xffff;
    ui_ddl_after_back = 0xffff;    
    }
	
static void KTVInit(void)
    {
    if(b_language_select)
    	{
    	#if COUNTRY == COUNTRY_TNS 
    	AraeaInit2(ARAEHCOY1+25);
    	#else
    	AraeaInit(ARAEHCOY1+5);
    	#endif
    	}
    else
    	{	
    	AraeaInit(ARAEHCOY1+5);
    	}
    
    GUI_SetColor(GUI_WHITE);
    GUI_SetTextMode(GUI_TM_TRANS); 
    KTVButtonS1 = BUTTON_Create( KTVDDLJBX-32,  KTVDDLJBY, BUTSELL+32, BUTSELH,GUI_ID_NUMB5 ,
BUTTON_CF_SHOW );
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        GUI_SetFont(&GUI_Font16_1);
        GUI_DisHzAt("����ܧѧݧڧҧ��ӧѧ�� ���� �ߧ֧ӧ֧�ߧ�� ��֧���� Kt/V",CHAR1X+16, CHAR1Y);  
//inaccurately.
        GUI_DisHzAt("���� �ӧ�֧ާ� �ܧѧݧڧҧ��ӧܧ�, �ާѧ�ڧߧ� �է�ݧاߧ� �ҧ��� �� ��֧اڧާ� Prime. ", CHAR1X, 
CHAR1Y+20);// 
        GUI_DisHzAt("����ݧ�ӧڧ� ����֧�ߧ�� �ܧѧݧڧҧ�ѧ�ڧ�: �����ӧ��. �է� �� ����ݧ� �էڧѧݧڧ٧�", CHAR1X, CHAR1Y
+40);
        GUI_DisHzAt("�է�ݧاߧ� �ҧ��� �� �էڧѧ�ѧ٧�ߧ� 13.0-15.0 ms/cm.", CHAR1X, CHAR1Y+60);
        GUI_DisHzAt("���ڧҧܧ� �ާ֧اէ� �ߧڧާ� �է�ݧاߧ� �ҧ��� �ާ֧ߧ��� ��֧� 1.0 ms/��m. ", CHAR1X, CHAR1Y+80
);   
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DisHzAt("���ߧܧ�ڧ� Kt/V", KTVCHARX1, KTVCHARY1);  
        GUI_DisHzAt("�٧ѧ��.", KTVDANX1, KTVDANY1-16);  
        GUI_DisHzAt("����", KTVDANX1, KTVDANY1+16); 
        BUTTON_SetFont(KTVButtonS1,  &GUI_Font8x13); 
        BUTTON_SetText(KTVButtonS1, button_show_char("�ߧѧ�ѧ�� �ܧѧݧڧҧ��ӧܧ�"));
        
        #elif COUNTRY == COUNTRY_SA
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("La calibraci�n se realiza si las pruebas Kt/V son",CHAR1X+16, 
CHAR1Y);  //inaccurately.
        GUI_DispStringAt("imprecisas. En calibraci�n, la m�quina debe estar", CHAR1X, CHAR1Y+
20);// 
        GUI_DispStringAt("en estado de preparaci�n. Preacondicionar con la", CHAR1X, CHAR1Y+
40);
        GUI_DispStringAt("calibraci�n exitosa: La conductividad pre y postdi�lisis debe 
estar", CHAR1X, CHAR1Y+60);
        GUI_DispStringAt("en rango de 13.0-15.0 mS/cm, el error debe ser menor de 1.0 mS/cm."
, CHAR1X, CHAR1Y+80);   
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("Fun. Kt/V", KTVCHARX1+8, KTVCHARY1);  
        GUI_DispStringAt("No", KTVDANX1, KTVDANY1-16);  
        GUI_DispStringAt("Si", KTVDANX1, KTVDANY1+16); 
        BUTTON_SetFont   (KTVButtonS1, &GUI_Font16_1);        
        BUTTON_SetText(KTVButtonS1, "Inicio Calibraci�n");
        
        #elif COUNTRY == FARMARIN
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("No programa de Calibra��o a m�quina dever?estar no ",CHAR1X+16, 
CHAR1Y);  //inaccurately.
        GUI_DispStringAt("modo Prepara��o: a condutividade dever?, CHAR1X, CHAR1Y+20);// 
        GUI_DispStringAt("estar fixa entre 13,0 e 15,0mS/cm, com uma varia��o ", CHAR1X, 
CHAR1Y+40);
        GUI_DispStringAt("inferior a 1,0mS/cm.", CHAR1X, CHAR1Y+60);

        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("Fun��o Kt/V", KTVCHARX1-16, KTVCHARY1);  
        GUI_DispStringAt("Ban", KTVDANX1, KTVDANY1-16);  
        GUI_DispStringAt("OK", KTVDANX1, KTVDANY1+16); 
        BUTTON_SetFont   (KTVButtonS1, &GUI_Font16_1);        
        BUTTON_SetText(KTVButtonS1, "In�cio Calibra��o");
        
        #elif COUNTRY == COUNTRY_TNS     
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Le calibrage devrait �tre fait quand les tests de",CHAR1X+18, 
CHAR1Y-3);  //inaccurately.
        GUI_DispStringAt("Kt/V sont inexacte.Dans calibrage,la machine", CHAR1X, CHAR1Y+16-2
);// 
        GUI_DispStringAt("devrait �tre dans le mode principal statut.", CHAR1X, CHAR1Y+16*2-1
);// 
        GUI_DispStringAt("Conditionner sur un calibrage r�ussi:", CHAR1X, CHAR1Y+16*3);
        GUI_DispStringAt("La conductivit?de la Pr?Dialyse et la la conductivit?de la 
post-dialyse", CHAR1X, CHAR1Y+68);
        GUI_DispStringAt("devrait �tre dans la gamme de 13.0-15.0 mS/cm, l'�cart entre eux 
devrait", CHAR1X, CHAR1Y+84);   
        GUI_DispStringAt("�tre moins de 1.0 mS/cm. ", CHAR1X, CHAR1Y+100);   
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("Fonction ", KTVCHARX1+12, KTVCHARY1-10);  
        GUI_DispStringAt("Kt/V ", KTVCHARX1+20, KTVCHARY1+10);  
        GUI_DispStringAt("Non", KTVDANX1, KTVDANY1-16);  
        GUI_DispStringAt("Oui", KTVDANX1, KTVDANY1+16); 
        BUTTON_SetFont   (KTVButtonS1, &GUI_Font16_1);        
        BUTTON_SetText(KTVButtonS1, "Comm.Calibrage");
        
        #else
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DisHzAt("��Kt/V���Բ�׼ȷʱӦ�ý���У��. У��", CHAR1X+32, CHAR1Y);
        GUI_DisHzAt("ʱ����Ӧ������Ԥ��״̬", CHAR1X, CHAR1Y+20);
        GUI_DisHzAt("У���ɹ���ǰ������: ", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("1:͸ǰ�絼��͸��絼Ӧ����13.0-15.0 mS/cm", CHAR1X, CHAR1Y+60);
        GUI_DisHzAt("2:͸ǰ�絼��͸��絼֮������С��1.0 mS/cm", CHAR1X, CHAR1Y+80);  
        GUI_DisHzAt("Kt/V����", KTVCHARX1, KTVCHARY1);  
        GUI_DispStringAt_UC("����", KTVDANX1, KTVDANY1-16);  
        GUI_DispStringAt_UC("����", KTVDANX1, KTVDANY1+16);
        BUTTON_SetFont   (KTVButtonS1, &GUI_Font16_1);        
        BUTTON_SetText(KTVButtonS1, "��ʼУ��"); 
        #endif
        }
    else
        {     
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Calibration should be done when Kt/V tests inaccurately.",CHAR1X+16
, CHAR1Y);  //inaccurately.
        GUI_DispStringAt("In calibration,machine should be in prime", CHAR1X, CHAR1Y+20);// 
        GUI_DispStringAt("status.Precondition on successful calibration: Pre-dialysis", 
CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("conductivity and post-dialysis conductivity should be in the range 
of ", CHAR1X, CHAR1Y+60);
        GUI_DispStringAt("13.0-15.0 mS/cm,the error between them should be less than 1.0 
mS/cm. ", CHAR1X, CHAR1Y+80);   
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("Kt/V function", KTVCHARX1-16, KTVCHARY1);  
        GUI_DispStringAt("Ban", KTVDANX1, KTVDANY1-16);  
        GUI_DispStringAt("OK", KTVDANX1, KTVDANY1+16); 
        BUTTON_SetFont   (KTVButtonS1, &GUI_Font16_1);        
        BUTTON_SetText(KTVButtonS1, "Begin Calibration");
        }
    ktv_init_add();
    hRadio[1] = RADIO_Create(KTVEDITX1, KTVEDITY1-8, RADIOL, 2*RADIOH, 0, ' ', WM_CF_SHOW, 2
); 
    RADIO_SetValue(hRadio[1], mG_KTVHDInfo.Flag);
    BUTTON_SetBkColor(KTVButtonS1,0,BSELCOLOR); 
    hProgBar = PROGBAR_Create( KTVDDLPBX, KTVDDLJBY, KTVDDLPBL,BUTSELH, WM_CF_SHOW);
    PROGBAR_SetFont(hProgBar, &GUI_Font24B_1);
    PROGBAR_SetBarColor(hProgBar, 0, GUI_GREEN);///GUI_GREEN);
    PROGBAR_SetBarColor(hProgBar, 1, GUI_WHITE);//GUI_RED);
    PROGBAR_SetMinMax(hProgBar, 0,  KTVDDLJTIME);
    ui_st_ddl_before = 0;
    ui_st_ddl_after = 0;
    uc_mg_ktv_ddl_jz_ing = 0;//��ʾ�絼��Ŀǰ��û����У��
    uc_st_by_pass_back = mG_Bypass_Sele;
    }
	
static void SavePu(void)
    {
    INT8U i;
    float f ;
    i = RADIO_GetValue(hRadio[0]);
    if(i == 0)   mG_ManInfo.sex = MAN;
    else         mG_ManInfo.sex = WOMAN;  
    mG_ManInfo.high = EDIT_GetValue(hEdit[0]);
    mG_ManInfo.weight = EDIT_GetValue(hEdit[1]);
    if(mG_ManInfo.sex == MAN)   f = 0.00607*mG_ManInfo.high + 0.0127*mG_ManInfo.weight - 
0.0698;
    else                        f = 0.00586*mG_ManInfo.high + 0.0126*mG_ManInfo.weight - 
0.0461;  
    mG_ManInfo.bodyarea = f;
    } 
	
static ERRBOOL SaveKTV(INT8U *errnum)
    {
    SavePu();
    mG_KTVHDInfo.Flag =  RADIO_GetValue(hRadio[1]);
    *errnum = 0;
    return OK;
    }    
	
static void URRInit(void)
    {
    INT8U i;
    AraeaInit(ARAEHCOY1-30);
    GUI_SetColor(GUI_WHITE);    
    GUI_SetTextMode(GUI_TM_TRANS);     
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        GUI_DisHzAt("�������� ����ѧاѧ֧� �����֧ߧ� ��ާ֧ߧ��֧ߧڧ� ��ѧ��ӧ��� �ӧާ֧��� ��ѧܧ�ڧ�֧�ܧ�ԧ� ", CHAR1X+
16, CHAR1Y);
        GUI_DisHzAt(" �ڧߧէ֧ܧ�� ��էѧݧ֧ߧڧ� ��ѧ��ӧ���. >70% ��ܧѧ٧�ӧѧ֧� �ѧէ֧ܧӧѧ�ߧ���� �էڧѧݧڧ٧�", CHAR1X
, CHAR1Y+20);    
        GUI_DisHzAt("���ݧ� ����ѧӧܧ�! �����ӧ֧էڧ�� ��ѧܧ�ڧ�֧�ܧڧ� �ܧݧڧߧڧ�֧�ܧڧ� �ѧߧѧݧڧ�.", CHAR1X, CHAR1Y+
40);            
        GUI_DisHzAt("1 ����֧էէڧѧݧڧ٧ߧ�� BUN:", URRCHARX, URRCHARY1);
        GUI_DisHzAt("1 ������էڧѧݧڧ٧ߧ�� BUN:", URRCHARX, URRCHARY2);
        GUI_DisHzAt("�����ӧ֧ߧ� ��ާ֧ߧ��֧ߧڧ� �ާ��֧ӧڧߧ� ", URRCHARX, URRCHARY3);  
        GUI_DisHzAt("�էڧѧݧڧ٧� (��������):", URRCHARX+80, URRCHARY3+20);      

        #elif COUNTRY == COUNTRY_SA

        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("�ndice de reducci�n de urea de di�lisis refleja el porcentaje de 
reducci�n", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("de soluto en vez del �ndice real removido de soluto. >70% indica 
idoneidad", CHAR1X, CHAR1Y+20);    
        GUI_DispStringAt("de di�lisis.�Como referencia! Revise los datos cl�nicos reales 
para an�lisis.", CHAR1X, CHAR1Y+40);
        GUI_SetFont(&GUI_Font16_1);   
        GUI_DispStringAt("Primer BUN predi�lisis:", URRCHARX, URRCHARY1);
        GUI_DispStringAt("Primer BUN posdi�lisis:", URRCHARX, URRCHARY2);
        GUI_DispStringAt("�ndice de reducci�n de ", URRCHARX, URRCHARY3-10);        
        GUI_DispStringAt("urea de di�lisis (URR):", URRCHARX, URRCHARY3+10);                

      
       #elif COUNTRY == FARMARIN
       
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("A taxa de redu��o de ur�ia reflete s?a percentagem de redu��o de", 
CHAR1X+16, CHAR1Y);
        GUI_DispStringAt(" soluto; o �ndice de remo��o de soluto acima de 70% indica a 
adequa��o", CHAR1X, CHAR1Y+20);    
        GUI_DispStringAt("de di�lise. Informa��es apenas para refer�ncia!", CHAR1X, CHAR1Y+40
);
        GUI_SetFont(&GUI_Font16_1);   
        GUI_DispStringAt("Primeiro BUN Pr?Capilar:", URRCHARX, URRCHARY1);
        GUI_DispStringAt("Primeiro BUN Pos-Capilar:", URRCHARX, URRCHARY2);
        GUI_DispStringAt("Taxa de Redu��o da Ur�ia(URR):", URRCHARX, URRCHARY3);    

        #elif COUNTRY == COUNTRY_TNS
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Le taux de la r�duction de l'ur�e de la dialyse refl�te juste le 
pourcentage", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("de la r�duction du solut?au lieu de solute r�el - indice 
d'enl�vement. ", CHAR1X, CHAR1Y+16);    
        GUI_DispStringAt(">70% indiquent l'ad�quation de la dialyse.Seulement pour 
r�f�rence!", CHAR1X, CHAR1Y+32);
        GUI_DispStringAt(" S'il vous pla�t reportez-vous ?une clinique actuelle pour 
analyse.", CHAR1X, CHAR1Y+48);
        GUI_SetFont(&GUI_Font16_1);   
        GUI_DispStringAt("Premi�re pr?dialyse de", URRCHARX, URRCHARY1-8);
        GUI_DispStringAt("l'ur�e du sang azot? ", URRCHARX, URRCHARY1+8);
        
        GUI_DispStringAt("Premi�re post-dialyse de", URRCHARX, URRCHARY2-8);
        GUI_DispStringAt("l'ur�e du sang azot? ", URRCHARX, URRCHARY2+8);
        
        GUI_DispStringAt("Taux de r�duction de ", URRCHARX, URRCHARY3-8);        
        GUI_DispStringAt("l'ur�e de la dialyse(URR): ", URRCHARX, URRCHARY3+8);        
        
        #else
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DisHzAt("͸�������½���, ֻ��ӳ�����½��ٷ���, ����ʵ������", CHAR1X+32, CHAR1Y);
        GUI_DisHzAt("�����. >70%��ʾ͸�����. ", CHAR1X, CHAR1Y+20);
        GUI_DisHzAt("�����ο�! �����ٴ��������", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("��һ��͸��ǰBUN:", URRCHARX, URRCHARY1);
        GUI_DisHzAt("��һ��͸����BUN:", URRCHARX, URRCHARY2);
        GUI_DisHzAt("͸�������½���(URR):", URRCHARX, URRCHARY3);
        #endif
        }
    else
        {
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Dialysis urea reduction rate just reflects reduction percentage of 
solute", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("instead of actual solute- removing index. >70% indicates dialysis 
adequacy.", CHAR1X, CHAR1Y+20);    
        GUI_DispStringAt("Only for reference! Please refer to actual clinical for analysis.",
 CHAR1X, CHAR1Y+40);
        GUI_SetFont(&GUI_Font16_1);   
        GUI_DispStringAt("First pre-dialysis BUN:", URRCHARX, URRCHARY1);
        GUI_DispStringAt("First post-dialysis BUN:", URRCHARX, URRCHARY2);
        GUI_DispStringAt("Dialysis urea reduction rate(URR):", URRCHARX, URRCHARY3);        
        }    
    GUI_SetFont(&GUI_Font16_1);
    GUI_DispStringAt("mmol/l",URRDANX, URRDANY1);
    GUI_DispStringAt("mmol/l",URRDANX, URRDANY2);
    GUI_SetFont(&GUI_Font32B_1);
    GUI_DispStringAt("0   %",URREDITX+32, URRCHARY3-8);
 
    hEdit[2] = EDIT_Create(URREDITX, URREDITY1,EDIT4L,EDITH, ' ', 4, 0 );//��һ��͸��ǰBUN
    EDIT_SetDecMode(hEdit[2], Co, 0, 500,1,0); 
 
    hEdit[3] = EDIT_Create(URREDITX, URREDITY2,EDIT4L,EDITH, ' ', 4, 0 );//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[3],Ct, 0, 500,1,0);   
 
    SaveEdit = hEdit[2];
    for(i=2; i<4; i++)
        {
        EDIT_SetFont(hEdit[i], &GUI_Font32B_1);
        }
    } 
    
static ERRBOOL SaveURR(INT8U *errnum)
    {
    INT32U temp;
    Co = EDIT_GetValue(hEdit[2]);
    Ct = EDIT_GetValue(hEdit[3]); 
    if(Co < Ct)
        {
        *errnum =  NOTICEDIS_KTV_URR_BUN_SMALL_BUN;
        return ERROR;
        } 
    if(Co == 0)
        {
        *errnum  = NOTICEDIS_KTV_URR_BEFO_BUN_ZERO;
        return ERROR;
        }
    temp = Co;
    temp -= Ct;
    temp *=100;
    temp =  mDIV_45(temp,Co);
 
    GUI_SetColor(0x608060);
    GUI_FillRect(URREDITX+32,URRCHARY3-8,URREDITX+64,URRCHARY3+24);
    GUI_SetColor(GUI_GREEN);
    GUI_SetFont(&GUI_Font32B_1);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispDecAt(temp,URREDITX+32, URRCHARY3-8, 2); 
    *errnum = 0;
    return OK;
    }    
	
static void SPIInit(void)
    {
    INT8U i;
    AraeaInit(ARAEHCOY1-10);    
    GUI_SetColor(GUI_WHITE);    
    GUI_SetTextMode(GUI_TM_TRANS);     
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        GUI_DisHzAt(" ���ߧէ֧ܧ� �ܧݧڧ�֧ߧ�� ��ѧ��ӧ��� Pool II - ��ѧ�ѧާ֧�� ��ѧ���ڧ�ѧߧߧ��", CHAR1X+16, 
CHAR1Y);
        GUI_DisHzAt(" �ܧڧߧ֧�ڧ�֧�ܧ�� �ާ�է֧ݧ� �ާ��֧ӧڧߧ�, ��ܧѧ٧�ӧѧ֧� �ߧ� �ڧߧէ֧ܧ� ��էѧݧ֧ߧڧ�", CHAR1X, 
CHAR1Y+20);
        GUI_DisHzAt(" ��ѧ��ӧ��� �� �էڧѧݧڧ٧� SRI> 70 % ��ܧѧ٧�ӧѧ֧� �ѧէ֧ܧӧѧ�ߧ���� �էڧѧݧڧ٧�", CHAR1X, 
CHAR1Y+40);
        GUI_DisHzAt(" ���ݧ� ����ѧӧܧ�! �����ӧ֧էڧ�� ��ѧܧ�ڧ�֧�ܧڧ� �ܧݧڧߧڧ�֧�ܧڧ� �ѧߧѧݧڧ�.", CHAR1X, CHAR1Y
+60);            
        GUI_DisHzAt("1 ����֧էէڧѧݧڧ٧ߧ�� BUN:", URRCHARX , URRCHARY1);
        GUI_DisHzAt("1 ������էڧѧݧڧ٧ߧ�� BUN:", URRCHARX , URRCHARY2);
        GUI_DisHzAt("����ܧѧ٧ѧ�֧ݧ� ����", URRCHARX , URRCHARY3);
        GUI_DisHzAt("���ߧէ֧ܧ� �ܧݧڧ�֧ߧ�� ��ѧ��ӧ��� Pool II :", URRCHARX, URRCHARY3+URRDANY3-
URRDANY2-8);
        GUI_DisHzAt("(SRI2pool)", URRCHARX, URRCHARY3+URRDANY3-URRDANY2+8);        
        
        #elif COUNTRY == COUNTRY_SA
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("�ndice de aclaramiento de soluto de Grupo II, par�metro calculado 
por", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("modelo cin�tico, indica �ndice de eliminaci�n de solutos en 
di�lisis.", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("SRI>70% idoneidad de di�lisis. �S�lo como referencia! Revise los 
datos", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("cl�nicos reales para an�lisis.", CHAR1X, CHAR1Y+60);            
        GUI_DispStringAt("Primer BUN predi�lisis:", URRCHARX , URRCHARY1);
        GUI_DispStringAt("Primer BUN posdi�lisis", URRCHARX , URRCHARY2);
        GUI_DispStringAt("Volumen UF", URRCHARX , URRCHARY3);
        GUI_DispStringAt("�ndice de aclaramiento de soluto", URRCHARX, URRCHARY3+URRDANY3-
URRDANY2-8);
        GUI_DispStringAt("Grupo II (SRI2pool): ", URRCHARX+63, URRCHARY3+URRDANY3-URRDANY2+8
);        
        
        #elif COUNTRY == FARMARIN
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Pool II �ndice de depura��o de soluto; um par�metro calculado pelo 
", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("modelo da cin�tica da ur�ia o qual indica o �ndice de remo��o de ",
 CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("soluto em di�lise; IRS > 70% indica a. adequa��o da di�lise. 
Informa��es  ", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("somente para refer�ncia! Favor comparar com as condi��es cl�nicas 
atuais.", CHAR1X, CHAR1Y+60);            
        GUI_DispStringAt("Primeiro BUN Pr?Capilar:", URRCHARX , URRCHARY1);
        GUI_DispStringAt("Primeiro BUN P�s-Capilar:", URRCHARX , URRCHARY2);
        GUI_DispStringAt("Volume UF", URRCHARX , URRCHARY3);
        GUI_DispStringAt("Pool II �ndice de depura��o  ", URRCHARX, URRCHARY3+URRDANY3-
URRDANY2-8);
        GUI_DispStringAt("de soluto: (SRI2pool): ", URRCHARX+23, URRCHARY3+URRDANY3-URRDANY2+
8);
        
        #elif COUNTRY == COUNTRY_TNS    
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Indice de liquidation du bain de solut? un param�tre calcul?par 
l'ur�e  ", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("cin�tique,Mod�le qui indique l'indice d'enl�vement du solut?dans 
dialyse,", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("il indique SRI>70% Ad�quation de la dialyse. Seulement pour 
r�f�rence! ", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("S'il vous pla�t reportez-vous ?une clinique actuelle pour analyse",
 CHAR1X, CHAR1Y+60);
                    
        GUI_DispStringAt("Premi�re pr?dialyse de", URRCHARX , URRCHARY1-8);
        GUI_DispStringAt("l'ur�e du sang azot?", URRCHARX , URRCHARY1+8);
        
        GUI_DispStringAt("Premi�re post-dialyse de", URRCHARX , URRCHARY2-8);
        GUI_DispStringAt("l'ur�e du sang azot?", URRCHARX , URRCHARY2+8);
        
        GUI_DispStringAt("Volume Ulrafiltr?", URRCHARX , URRCHARY3);
        GUI_DispStringAt("Indice de liquidation du bain", URRCHARX, URRCHARY3+URRDANY3-
URRDANY2-8);
        GUI_DispStringAt(" de solut?(SRI2pool): ", URRCHARX, URRCHARY3+URRDANY3-URRDANY2+8);
        
        #else
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DisHzAt("�����������ָ��, ��ͨ�����ض���ѧģ������Ĳ���, ", CHAR1X+32, CHAR1Y);
        GUI_DisHzAt("���ʾ͸���������ų���. SRI>70% ��ʾ͸�����. ", CHAR1X, CHAR1Y+20);
        GUI_DisHzAt("�����ο�! �����ٴ��������", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("��һ��͸��ǰBUN:", URRCHARX, URRCHARY1);
        GUI_DisHzAt("��һ��͸����BUN:", URRCHARX, URRCHARY2);
        GUI_DisHzAt("������:", URRCHARX , URRCHARY3);
        GUI_DisHzAt("�����������ָ��", URRCHARX, URRCHARY3+URRDANY3-URRDANY2-8);
        GUI_SetFont(&GUI_Font16_1);        
        GUI_DispStringAt("(SRI2pool): ", URRCHARX+63, URRCHARY3+URRDANY3-URRDANY2+8);
        #endif
        }
    else
        {    
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Pool II solute clearance index, a parameter calculated by urea 
kinetic ", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("model, indicates solute removing index in dialysis. SRI>70% 
indicates", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("dialysis adequacy. Only for reference! Please refer to actual 
clinical", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("for analysis", CHAR1X, CHAR1Y+60);            
        GUI_DispStringAt("First pre-dialysis BUN:", URRCHARX , URRCHARY1);
        GUI_DispStringAt("First post-dialysis BUN", URRCHARX , URRCHARY2);
        GUI_DispStringAt("UF Volume", URRCHARX , URRCHARY3);
        GUI_DispStringAt("Pool II solute clearance index: ", URRCHARX, URRCHARY3+URRDANY3-
URRDANY2-8);
        GUI_DispStringAt("(SRI2pool): ", URRCHARX+63, URRCHARY3+URRDANY3-URRDANY2+8);
        }
    GUI_SetFont(&GUI_Font16_1);    
    GUI_DispStringAt("mmol/l",URRDANX, URRDANY1);
    GUI_DispStringAt("mmol/l",URRDANX, URRDANY2);
    GUI_DispStringAt("ml",    URRDANX, URRDANY3);
    GUI_SetFont(&GUI_Font32B_1);
    GUI_DispStringAt("0   %",URREDITX+40, URRCHARY3+URRDANY3-URRDANY2-8);
 
    hEdit[2] = EDIT_Create(URREDITX, URREDITY1,EDIT4L,EDITH, ' ', 4, 0 );//��һ��͸��ǰBUN
    EDIT_SetDecMode(hEdit[2], Co, 0, 500,1,0); 
 
    hEdit[3] = EDIT_Create(URREDITX, URREDITY2,EDIT4L,EDITH, ' ', 4, 0 );//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[3],Ct, 0, 500,1,0);   
 
    hEdit[4] = EDIT_Create(URREDITX, URREDITY3,EDIT4L,EDITH, ' ', 4, 0);//UF
    EDIT_SetDecMode(hEdit[4],0, 0, 9999,0,0);  
 
    SaveEdit = hEdit[2];
    for(i=2; i<5; i++)
        {
        EDIT_SetFont(hEdit[i], &GUI_Font32B_1);
        }
    } 

static ERRBOOL SaveSRI(INT8U *errnum)
    {
    INT16U ui_temp_data_uf;
    INT32U ul_temp_data_vtd;
    INT32U ul_temp_vo;
 
    Co = EDIT_GetValue(hEdit[2]);
    Ct = EDIT_GetValue(hEdit[3]); 
    ui_temp_data_uf = EDIT_GetValue(hEdit[4]);
    if(Co <= Ct)
        {
        *errnum = NOTICEDIS_KTV_URR_BUN_SMALL_BUN;
        return ERROR;
        }
    if(Ct == 0)
        {
        *errnum  = NOTICEDIS_KTV_URR_AFTER_BUN_ZERO;
        return ERROR;
        } 
    if(Co == 0)
        {
        *errnum  = NOTICEDIS_KTV_URR_BEFO_BUN_ZERO;
        return ERROR;
        }
    ul_temp_data_vtd = Co * Co * ui_temp_data_uf;   
    ul_temp_data_vtd = 1000*Ct - ul_temp_data_vtd;
    ul_temp_data_vtd =  mDIV_45(ul_temp_data_vtd , (Co * (Co -  Ct)) * 1000 );
    ul_temp_vo = mDIV_45(ul_temp_data_vtd * 1000 + ui_temp_data_uf , 1000);
    ul_temp_data_vtd = 100 * (ul_temp_vo * Co - ul_temp_data_vtd * Ct);
    if(ul_temp_vo == 0)
        {
        *errnum  = NOTICEDIS_KTV_CAN_SHU_ERR;
        return ERROR;
        }
    else
        {    
        ul_temp_data_vtd = mDIV_45(ul_temp_data_vtd , (Co * ul_temp_vo));
        }
    GUI_SetColor(0x608060);
    GUI_FillRect(URREDITX+40, URRCHARY3+URRDANY3-URRDANY2-8, URREDITX+70 , 445);
    GUI_SetColor(GUI_GREEN);
    GUI_SetFont(&GUI_Font32B_1);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispDecAt(ul_temp_data_vtd,URREDITX+40, URRCHARY3+URRDANY3-URRDANY2-8, 2); 
    *errnum = 0;
    return OK;
    }
	
static void PCRInit(void)
    {
    INT8U i;
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);             
        GUI_DisHzAt("�����ާѧݧ�ߧѧ� �ߧ��ާ� �ܧѧ�ѧҧ�ݧڧ٧ާ� �ҧ֧ݧܧ�. ������֧ҧݧ֧ߧڧ� �ҧ֧ݧܧ� �էݧ� ��ѧ�ڧ֧ߧ��� 
�էڧѧݧڧ٧� ", CHAR1X+16, CHAR1Y);
        GUI_DisHzAt("�է�ݧا֧� �ҧ��� �ҧ�ݧ��� ��֧� 1.1 (g/kg.d), ���ԧէ� nPCR ��ѧܧا� �ҧ�է�� �ҧ�ݧ��� ��֧� 
1.1 (g/kg.d).", CHAR1X, CHAR1Y+20);
        GUI_DisHzAt(" ����ԧէ� nPCR - �ާ֧ߧ��� ��֧� 0.8 (g/kg.d), ���� ��٧ߧѧ�ѧ֧� �ߧ֧է�֧էѧߧڧ� �� 
�ߧ֧ѧէ֧ܧӧѧ�ߧѧ� �ߧ��ާ� ", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("�էڧѧݧڧ٧� �ҧ�է֧� �ӧ���ܧ�. ���ݧ� ����ѧӧܧ�! �����ӧ֧էڧ�� ��ѧܧ�ڧ�֧�ܧڧ� �ܧݧڧߧڧ�֧�ܧڧ� 
�ѧߧѧݧڧ�.", CHAR1X, CHAR1Y+60);
        GUI_DisHzAt("���ҧ�֧� �ާ��� �� �ާ֧ا�ѧ٧� �էڧѧݧڧ٧�:", PCRCHARX, PCRCHARY1);
        GUI_DisHzAt("����֧ާ� �ڧߧ�֧�ӧѧݧ� �էڧѧݧڧ٧�:", PCRCHARX, PCRCHARY1+PCRYY*1);
        GUI_DisHzAt("BUN �ާ��� �� �ާ֧ا�ѧ٧� �էڧѧݧڧ٧�:", PCRCHARX, PCRCHARY1+PCRYY*2);
//͸������������BUN:
        GUI_DisHzAt("1 ������էڧѧݧڧ٧ߧ�� BUN:", PCRCHARX, PCRCHARY1+PCRYY*3);
        GUI_DisHzAt("2 ����֧էէڧѧݧڧ٧ߧ�� BUN:", PCRCHARX, PCRCHARY1+PCRYY*4);
        GUI_DisHzAt("�����ӧ֧ߧ� �ܧѧ�ѧҧ�ݧڧ٧ާ� �ߧ��ާѧݧ�ߧ�ԧ� �ҧ֧ݧܧ� (nPCR):", PCRCHARX, PCRCHARY1+
PCRYY*5);        
        
        #elif COUNTRY == COUNTRY_SA
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);             
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("�ndice normal de catabolismo de prote�nas. La ingesta de prote�nas 
para", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("los pacientes de di�lisis debe ser mayor que 1.1 (g/kg.d), luego 
nPCR ", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("ser?mayor que 1.1 (g/kg.d). Si nPCR es menor a 0.8 (g/kg.d), 
significa", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("malnutrici�n y el �ndice de di�lisis inadecuado ser?alto. ", CHAR1X
, CHAR1Y+60);
        GUI_DispStringAt("�S�lo como referencia! Revise los datos cl�nicos reales para 
an�lisis.", CHAR1X, CHAR1Y+80);
        GUI_DispStringAt("Vol. de orina en interfase de di�lisis:", PCRCHARX, PCRCHARY1);
        GUI_DispStringAt("Tiempo de intervalo de di�lisis:", PCRCHARX, PCRCHARY1+PCRYY*1);
        GUI_DispStringAt("BUN de orina en interfase de di�lisis:", PCRCHARX, PCRCHARY1+PCRYY*
2);//͸������������BUN:
        GUI_DispStringAt("Primer BUN posdi�lisis:", PCRCHARX, PCRCHARY1+PCRYY*3);
        GUI_DispStringAt("Segundo BUN predi�lisis:", PCRCHARX, PCRCHARY1+PCRYY*4);
        GUI_DispStringAt("�ndice normal de catabolismo ", PCRCHARX, PCRCHARY1+PCRYY*5-10);
        GUI_DispStringAt("de prote�nas (nPCR):", PCRCHARX+40, PCRCHARY1+PCRYY*5+10);        
        
        #elif COUNTRY == FARMARIN
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);             
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Taxa de Catabolismo Proteico normal: a taxa de injesta de proteina 
pelo", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("paciente renal deve ser maior que 1,1 g/ Kg/ dia; ent�o a TCPn 
dever?ser ", CHAR1X, CHAR1Y+16);
        GUI_DispStringAt("significa m?nutri��o e taxa de  maior que 1,1(g/Kg/dia) tamb�m. 
Qdo o", CHAR1X, CHAR1Y+32);
        GUI_DispStringAt("TCPn for menor 0,8 (g/Kg/Dia) isto di�lise inadequada, e devera 
ser elevada.", CHAR1X, CHAR1Y+48);
        GUI_DispStringAt("Informa��o somente para refer�ncia. Favor comparar com as 
condi��es ", CHAR1X, CHAR1Y+64);
        GUI_DispStringAt("cl�nicas atuais.", CHAR1X, CHAR1Y+80);        
        GUI_DispStringAt("Volume de urina entre a di�lise:", PCRCHARX, PCRCHARY1);
        GUI_DispStringAt("Intervalo interdial�tico:", PCRCHARX, PCRCHARY1+PCRYY*1);
        GUI_DispStringAt("Depura��o interdial�tica:", PCRCHARX, PCRCHARY1+PCRYY*2);
//͸������������BUN:
        GUI_DispStringAt("Primeiro BUN P�s-Capilar:", PCRCHARX, PCRCHARY1+PCRYY*3);
        GUI_DispStringAt("Segundo BUN Pr?Capilar:", PCRCHARX, PCRCHARY1+PCRYY*4);
        GUI_DispStringAt("Taxa de Catabolismo ", PCRCHARX, PCRCHARY1+PCRYY*5-10);
        GUI_DispStringAt("Proteico normal (TCPn):", PCRCHARX, PCRCHARY1+PCRYY*5+10);        
        
        #elif COUNTRY == COUNTRY_TNS
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);             
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Taux du catabolisme de la prot�ine normale. Les prot�ines prises 
pour", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("les malades de la dialyse doivent �tre plus que 1.1(g/kg.d),puis 
nPCR", CHAR1X, CHAR1Y+16);
        GUI_DispStringAt("seront plus que 1.1(g/kg.d)aussi.Quand le nPCR est moins que 
0.8(g/kg.d),", CHAR1X, CHAR1Y+32);
        GUI_DispStringAt("�a veut dire la malnutrition et Le taux d'indication de la dialyse 
sera", CHAR1X, CHAR1Y+48);
        GUI_DispStringAt("haut. Seulement pour r�f�rence! S'il vous pla�t reportez-vous", 
CHAR1X, CHAR1Y+64);
        GUI_DispStringAt("?une clinique actuelle pour l'analyse", CHAR1X, CHAR1Y+80);
        
        GUI_DispStringAt("Volume de l'urine dans l'interphase", PCRCHARX, PCRCHARY1-8);
        GUI_DispStringAt("de la dialyse:", PCRCHARX, PCRCHARY1+8);
        
        GUI_DispStringAt("Intervalle du temps de la dialyse: ", PCRCHARX, PCRCHARY1+PCRYY*1);
        
        GUI_DispStringAt("L'urine dans la zone du sang azot?, PCRCHARX, 
PCRCHARY1+PCRYY*2-8);//͸������������BUN:
        GUI_DispStringAt("dans l'interphase de la dialyse:", PCRCHARX, PCRCHARY1+PCRYY*2+8);
//͸������������BUN:
        
        GUI_DispStringAt("Premi�re post-dialyse de l'ur�e", PCRCHARX, PCRCHARY1+PCRYY*3-8);
        GUI_DispStringAt("du sang azot?", PCRCHARX, PCRCHARY1+PCRYY*3+8);
        
        GUI_DispStringAt("Deuxi�me pr?dialyse de l'ur�e", PCRCHARX, PCRCHARY1+PCRYY*4-8);
        GUI_DispStringAt("du sang azot? ", PCRCHARX, PCRCHARY1+PCRYY*4+8);
        
        GUI_DispStringAt("Le taux normale du catabolisme", PCRCHARX, PCRCHARY1+PCRYY*5-8);
        GUI_DispStringAt("de la prot�ine (nPCR):", PCRCHARX, PCRCHARY1+PCRYY*5+8);
        
        #else
        AraeaInit(ARAEHCOY1-10);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);     
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DisHzAt("��׼�����ʷֽ���, ͸�����ߵ������������� >1.1(g/kg.d),", CHAR1X+32, 
CHAR1Y);
        GUI_DisHzAt("����,nPCR ҲӦ>1.1(g/kg.d). ��nPCR<0.8(g/kg.d)��ʾӪ������, ", CHAR1X, 
CHAR1Y+20);
        GUI_DisHzAt("͸������ָ��ʸ�, ����ֵ�����ٴ�����. ", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("�����ο�! �����ٴ��������", CHAR1X, CHAR1Y+60);
        GUI_DisHzAt("͸����������:", PCRCHARX, PCRCHARY1);
        GUI_DisHzAt("͸�����ʱ��:", PCRCHARX, PCRCHARY1+PCRYY*1);
        GUI_DisHzAt("͸������������BUN:", PCRCHARX, PCRCHARY1+PCRYY*2);
        GUI_DisHzAt("��һ��͸����BUN:", PCRCHARX, PCRCHARY1+PCRYY*3);
        GUI_DisHzAt("�ڶ���͸��ǰBUN:", PCRCHARX, PCRCHARY1+PCRYY*4);
        GUI_DisHzAt("��׼�����ʷֽ���(nPCR): ", PCRCHARX, PCRCHARY1+PCRYY*5);
        #endif
        }
    else
        {
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);    
        GUI_SetTextMode(GUI_TM_TRANS);             
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Normal protein catabolism rate.The protein intakes for dialysis 
patients", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("should be more than 1.1(g/kg.d),then nPCR will be more than 
1.1(g/kg.d)", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("too. When nPCR is less than 0.8(g/kg.d),it means malnutrition and "
, CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("inadequate dialysis rate will be high. Only for reference! Please 
refer", CHAR1X, CHAR1Y+60);
        GUI_DispStringAt("to actual clinical for analysis", CHAR1X, CHAR1Y+80);
        GUI_DispStringAt("Urine volume in dialysis interphase:", PCRCHARX, PCRCHARY1);
        GUI_DispStringAt("Interval time of dialysis:", PCRCHARX, PCRCHARY1+PCRYY*1);
        GUI_DispStringAt("Urine BUN in dialysis interphase:", PCRCHARX, PCRCHARY1+PCRYY*2);
//͸������������BUN:
        GUI_DispStringAt("First post-dialysis BUN:", PCRCHARX, PCRCHARY1+PCRYY*3);
        GUI_DispStringAt("Second pre-dialysis BUN:", PCRCHARX, PCRCHARY1+PCRYY*4);
        GUI_DispStringAt("Normal protein catabolism rate(nPCR):", PCRCHARX, PCRCHARY1+PCRYY*5
);
        }
    GUI_SetFont(&GUI_Font16_1);    
    GUI_DispStringAt("ml",PCRDANX+40, PCRDANY1);
    GUI_DispStringAt("min",PCRDANX+40, PCRDANY1+PCRYY*1);
    GUI_DispStringAt("mmol/l",PCRDANX+40, PCRDANY1+PCRYY*2);
    GUI_DispStringAt("mmol/l",PCRDANX+40, PCRDANY1+PCRYY*3);
    GUI_DispStringAt("mmol/l",PCRDANX+40, PCRDANY1+PCRYY*4);
    GUI_DispStringAt("g/kg.d",PCRDANX+40, PCRDANY1+PCRYY*5);
    GUI_SetFont(&GUI_Font24B_1);
    GUI_DispStringAt("0",PCREDITX+30+40, PCRCHARY1+PCRYY*5-2);
 
    hEdit[2] = EDIT_Create(PCREDITX+40, PCREDITY1,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸��ǰBUN
    EDIT_SetDecMode(hEdit[2], 0, 0, 9999,0,0); 
 
    hEdit[3] = EDIT_Create(PCREDITX+40, PCREDITY1+PCRYY*1,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[3],0, 0, 9999,0,0);   
 
    hEdit[4] = EDIT_Create(PCREDITX+40, PCREDITY1+PCRYY*2,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[4],0, 0, 500,1,0); 
 
    hEdit[5] = EDIT_Create(PCREDITX+40, PCREDITY1+PCRYY*3,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[5],Ct, 0, 500,1,0); 
 
    hEdit[6] = EDIT_Create(PCREDITX+40, PCREDITY1+PCRYY*4,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[6],Co2, 0, 500,1,0); 
 
    SaveEdit = hEdit[2];
    for(i=2; i<7; i++)
        {
        EDIT_SetFont(hEdit[i], &GUI_Font24B_1);
        }
    } 
	
static ERRBOOL SavePCR(INT8U *errnum)
    {
    INT16U Cu,V, Q;
    INT32U temp;
    float f;
    mG_ManInfo.weight = EDIT_GetValue(hEdit[1]);
    V    = EDIT_GetValue(hEdit[2]);
    Q    = EDIT_GetValue(hEdit[3]); 
    Cu   = EDIT_GetValue(hEdit[4]);
    Ct   = EDIT_GetValue(hEdit[5]); 
    Co2  = EDIT_GetValue(hEdit[6]);

    if(Co2 < Ct)
        {
        *errnum = NOTICEDIS_KTV_URR_BUN_SMALL_BUN;
        return ERROR;
        }
    if(Q == 0)
        {
        *errnum =NOTICEDIS_KTV_JIAN_GE_TIME_ZERO;
        return ERROR;
        }
    temp = ((Co2-Ct)*mG_ManInfo.weight+V*Cu)/Q;
    f = (9.35*temp+0.29*mG_ManInfo.weight)/mG_ManInfo.weight/0.58;
    GUI_SetColor(0x608060);
    GUI_FillRect(PCREDITX+30+40, PCRCHARY1+PCRYY*5-2,PCREDITX+30+40+24,(PCRCHARY1+PCRYY*5)+23
);
    GUI_SetColor(GUI_GREEN);
    GUI_SetFont(&GUI_Font24B_1);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispDecAt(f,PCREDITX+30+40, PCRCHARY1+PCRYY*5-2, 2); 
    *errnum = 0;
    return OK;
    }
	
static void TACInit(void)
    {
    INT8U i;

    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DisHzAt("�����֧էߧ֧ߧߧ�� ��� �ӧ�֧ާ֧ߧ� �ާ��֧ӧڧߧ� ����ѧاѧ�� ��ڧߧ�֧٧� ��ڧ��ѧ�ڧ� �էڧѧݧڧ٧� 
��էѧݧ֧ߧڧ� ", CHAR1X+16, CHAR1Y);
        GUI_DisHzAt("�ާ��� �� �ާ֧�ѧҧ�ݧڧ٧� �ҧ֧ݧܧ� ��֧ݧ�ӧ֧ܧ�. TAC�ާ��֧ӧڧߧ�> 50 (mg/dl) ��٧ߧѧ�ѧ֧� 
����ѧӧ��ߧ�� ", CHAR1X, CHAR1Y+20);
        GUI_DisHzAt("�ڧߧէ֧ܧ� �էݧ� �ѧէ֧ܧӧѧ�ߧ���� �էڧѧݧڧ٧� ����� �ާ�ا֧� ���ڧӧ֧��� �� ���ӧ��֧ߧڧ� ", CHAR1X
, CHAR1Y+40);
        GUI_DisHzAt("�է�ݧԧ�ӧ�֧ާ֧ߧߧ�� �٧ѧ���էߧ֧ߧڧ� ��֧�է֧�ߧ�-�����էڧ����, �ߧ֧�ӧߧ�� ��ڧ��֧ާ� ", 
CHAR1X, CHAR1Y+60);
        GUI_DisHzAt("�� ��ڧ�֧ӧѧ�ڧ�֧ݧ�ߧ�ԧ� ���ѧܧ��.���ݧ� ����ѧӧܧ�! �����ӧ֧էڧ�� ��ѧܧ�ڧ�֧�ܧڧ� 
�ܧݧڧߧڧ�֧�ܧڧ� �ѧߧѧݧڧ�.", CHAR1X, CHAR1Y+80);    
    
        GUI_DisHzAt("1 ����֧էէڧѧݧڧ٧ߧ�� BUN:", TACCHARX, TACCHARY1);
        GUI_DisHzAt("1 ������էڧѧݧڧ٧ߧ�� BUN:", TACCHARX, TACCHARY1+TACYY*1);
        GUI_DisHzAt("2 ����֧էէڧѧݧڧ٧ߧ�� BUN:", TACCHARX, TACCHARY1+TACYY*2);
        GUI_DisHzAt("�ӧ�֧ާ� �էڧѧݧڧ٧�:", TACCHARX, TACCHARY1+TACYY*3);
        GUI_DisHzAt("����֧ާ� �ڧߧ�֧�ӧѧݧ� �էڧѧݧڧ٧�:", TACCHARX, TACCHARY1+TACYY*4);
        GUI_DisHzAt("�����֧էߧ֧ߧߧ�� ��� �ӧ�֧ާ֧ߧ� ", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DisHzAt("�ܧ�ߧ�֧ߧ��ѧ�ڧ� �ާ��֧ӧڧߧ� (�������ާ���)", TACCHARX, TACCHARY1+TACYY*5+8); 
        
        #elif COUNTRY == COUNTRY_SA
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DispStringAt("Tiempo de concentraciones medias de urea refleja situaci�n de 
s�ntesis", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("de eliminaci�n de urea de di�lisis y metabolismo de prote�nas del 
pa-", CHAR1X, CHAR1Y+16);
        GUI_DispStringAt("ciente. TACurea > 50 (mg/dl) es el �ndice de referencia para 
di�lisis", CHAR1X, CHAR1Y+32);
        GUI_DispStringAt("idonea. Indica complicaciones del sistema cardiovascular nervioso 
del", CHAR1X, CHAR1Y+48);
        GUI_DispStringAt("canal alimentario y otras complicaciones a largo plazo. �Como 
referencia!", CHAR1X, CHAR1Y+64);    
        GUI_DispStringAt(" Revise los datos cl�nicos reales para an�lisis.", CHAR1X, CHAR1Y+
80);            
    
        GUI_DispStringAt("Primer BUN predi�lisis:", TACCHARX, TACCHARY1);
        GUI_DispStringAt("Primer BUN posdi�lisis:", TACCHARX, TACCHARY1+TACYY*1);
        GUI_DispStringAt("Segundo BUN predi�lisis:", TACCHARX, TACCHARY1+TACYY*2);
        GUI_DispStringAt("Tiempo de di�lisis:", TACCHARX, TACCHARY1+TACYY*3);
        GUI_DispStringAt("Tiempo de intervalo de di�lisis:", TACCHARX, TACCHARY1+TACYY*4);
        GUI_DispStringAt("Tiempo de concentraciones ", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DispStringAt(" medias de urea (TACurea):", TACCHARX, TACCHARY1+TACYY*5+8);    
        
        #elif COUNTRY == FARMARIN
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DispStringAt("A taxa de concentra�ao de ur�ia reflete a s�ntese de ur�ia e a 
taxa de ", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("remo��o de ur�ia; TAC Ur�ia >50 mg/dl significa que a di�lise est?"
, CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("adequada. Isso significa menores complica��es cardiovasculares e ",
 CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("neurologicas a longo prazo. Informa��es apenas para refer�ncia. 
Favor", CHAR1X, CHAR1Y+60);
        GUI_DispStringAt("comparar com as condi��es cl�nicas atuais.", CHAR1X, CHAR1Y+80);    
    
        GUI_DispStringAt("Primeiro BUN Pr?Capilar:", TACCHARX, TACCHARY1);
        GUI_DispStringAt("Primeiro BUN P�s-Capilar:", TACCHARX, TACCHARY1+TACYY*1);
        GUI_DispStringAt("Segundo BUN Pr?Capilar:", TACCHARX, TACCHARY1+TACYY*2);
        GUI_DispStringAt("Tempo Di�lise:", TACCHARX, TACCHARY1+TACYY*3);
        GUI_DispStringAt("Intervalo Interdialitico:", TACCHARX, TACCHARY1+TACYY*4);
        GUI_DispStringAt("Concentra��es de ", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DispStringAt("Ur�ia (TACureia):", TACCHARX, TACCHARY1+TACYY*5+8);    
        
        #elif COUNTRY == COUNTRY_TNS     
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);
        
        GUI_SetFont(&GUI_Font13_1);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DispStringAt("Le temps moyen des Concentrations de l'Ur�e refl�te la situation 
de la synth�se de ", CHAR1X+20, CHAR1Y);
        GUI_DispStringAt("la dialyse Les indices d'enl�vement d'ur�e et la prot�ine du 
metabolisme du malade.", CHAR1X+4, CHAR1Y+16);
        GUI_DispStringAt("TACurea >50 (mg/dl) signifie les indices de r�f�rences pour la 
dialyse ad�quate. ", CHAR1X+4, CHAR1Y+32);
        GUI_DispStringAt("Il indique cardio-vasculaire,Le syst�me nerveux du canal 
alimentaire et autres ", CHAR1X+4, CHAR1Y+48);
        GUI_DispStringAt("complications ?long terme augmente. Seulement pour r�f�rence!", 
CHAR1X+4, CHAR1Y+64);
        GUI_DispStringAt("S'il vous pla�t reportez-vous ?une clinique actuelle pour 
l'analyse. ", CHAR1X+4, CHAR1Y+80);
        
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Premi�re pr?dialyse de", TACCHARX, TACCHARY1-8);
        GUI_DispStringAt("l'ur�e du sang azot?", TACCHARX, TACCHARY1+8);
        
        GUI_DispStringAt("Premi�re post-dialyse de", TACCHARX, TACCHARY1+TACYY*1-8);
        GUI_DispStringAt("l'ur�e du sang azot? ", TACCHARX, TACCHARY1+TACYY*1+8);
        
        GUI_DispStringAt("Deuxi�me pr?dialyse de", TACCHARX, TACCHARY1+TACYY*2-8);
        GUI_DispStringAt("l'ur�e du sang azot? ", TACCHARX, TACCHARY1+TACYY*2+8);
        
        GUI_DispStringAt("Temps de la dialyse: ", TACCHARX, TACCHARY1+TACYY*3);
        
        GUI_DispStringAt("Intervalle du temps", TACCHARX, TACCHARY1+TACYY*4-8);
        GUI_DispStringAt("de la dialyse: ", TACCHARX, TACCHARY1+TACYY*4+8);
        
        GUI_DispStringAt("La moyenne du temps de la", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DispStringAt("concentration d'Ur�e (TACurea):", TACCHARX, TACCHARY1+TACYY*5+8);
    	
        #else
        AraeaInit(ARAEHCOY1-10);
        GUI_SetColor(GUI_WHITE);
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DisHzAt("ʱ��ƽ������Ũ��, ��ӳ��͸������������뻼�ߵ�����", CHAR1X+32, CHAR1Y);
        GUI_DisHzAt("��л���ۺ����, TACurea>50(mg/dl) Ϊ͸������ԵĲο�ָ��. ", CHAR1X, 
CHAR1Y+20);
        GUI_DisHzAt("��ʾ��Ѫ��, ��������ϵͳ��Զ�ڲ���֢����. ", CHAR1X, CHAR1Y+40);
        GUI_DisHzAt("�����ο�! �����ٴ��������", CHAR1X, CHAR1Y+60);  
        GUI_DisHzAt("��һ��͸��ǰBUN:", TACCHARX, TACCHARY1);
        GUI_DisHzAt("��һ��͸����BUN:", TACCHARX, TACCHARY1+TACYY*1);
        GUI_DisHzAt("�ڶ���͸��ǰBUN:", TACCHARX, TACCHARY1+TACYY*2);
        GUI_DisHzAt("͸��ʱ��: ", TACCHARX, TACCHARY1+TACYY*3);
        GUI_DisHzAt("͸�����ʱ��: ", TACCHARX, TACCHARY1+TACYY*4);
        GUI_DisHzAt("ʱ��ƽ������Ũ��", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DisHzAt(" (TACurea): ", TACCHARX, TACCHARY1+TACYY*5+8);    
        #endif
        }
    else
        {     
        AraeaInit(ARAEHCOY1+5);
        GUI_SetColor(GUI_WHITE);
        GUI_SetFont(&GUI_Font16_1);
        GUI_SetTextMode(GUI_TM_TRANS); 
        GUI_DispStringAt("Time Average Concentrations of Urea reflects synthesis situation 
of dialy-", CHAR1X+16, CHAR1Y);
        GUI_DispStringAt("sis urea remov index and patient's protein 
metabolism.TACurea>50(mg/dl)", CHAR1X, CHAR1Y+20);
        GUI_DispStringAt("means reference index for dialysis adequacy.It indicates 
cardiovascular,", CHAR1X, CHAR1Y+40);
        GUI_DispStringAt("nervous system of alimentary canal and other long-term 
complications", CHAR1X, CHAR1Y+60);
        GUI_DispStringAt("increase.Only for reference! Please refer to actual clinical for 
analysis.", CHAR1X, CHAR1Y+80);    
    
        GUI_DispStringAt("First pre-dialysis BUN:", TACCHARX, TACCHARY1);
        GUI_DispStringAt("First post-dialysis BUN:", TACCHARX, TACCHARY1+TACYY*1);
        GUI_DispStringAt("Second pre-dialysis BUN:", TACCHARX, TACCHARY1+TACYY*2);
        GUI_DispStringAt("Dialysis time:", TACCHARX, TACCHARY1+TACYY*3);
        GUI_DispStringAt("Dialysis interval time:", TACCHARX, TACCHARY1+TACYY*4);
        GUI_DispStringAt("Time Average Concentrations", TACCHARX, TACCHARY1+TACYY*5-8);
        GUI_DispStringAt("of Urea(TACurea):", TACCHARX, TACCHARY1+TACYY*5+8);    
        }
    GUI_SetFont(&GUI_Font16_1);    
    GUI_DispStringAt("mmol/l",TACDANX, TACDANY1);
    GUI_DispStringAt("mmol/l",TACDANX, TACDANY1+TACYY*1);
    GUI_DispStringAt("mmol/l",TACDANX, TACDANY1+TACYY*2);
    GUI_DispStringAt("min",TACDANX, TACDANY1+TACYY*3);
    GUI_DispStringAt("min",TACDANX, TACDANY1+TACYY*4);
    GUI_DispStringAt("mg/dl",TACDANX, TACDANY1+TACYY*5);
    GUI_SetFont(&GUI_Font24B_1);
    GUI_DispStringAt("0",TACEDITX+30, TACCHARY1+TACYY*5-2);
 
    hEdit[2] = EDIT_Create(TACEDITX, TACEDITY1,EDIT4LM,EDITHM, ' ', 4, 0 );//��һ��͸��ǰBUN
    EDIT_SetDecMode(hEdit[2], Co, 0, 500,1,0); 
 
    hEdit[3] = EDIT_Create(TACEDITX, TACEDITY1+TACYY*1,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[3],Ct, 0, 500,1,0);   
 
    hEdit[4] = EDIT_Create(TACEDITX, TACEDITY1+TACYY*2,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[4],Co2, 0, 500,1,0); 
 
    hEdit[5] = EDIT_Create(TACEDITX, TACEDITY1+TACYY*3,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[5],0, 0, 9999,0,0); 
 
    hEdit[6] = EDIT_Create(TACEDITX, TACEDITY1+TACYY*4,EDIT4LM,EDITHM, ' ', 4, 0 );
//��һ��͸����BUN
    EDIT_SetDecMode(hEdit[6],0, 0, 9999,0,0); 
 
    SaveEdit = hEdit[2];
    for(i=2; i<7; i++)
        {
        EDIT_SetFont(hEdit[i], &GUI_Font24B_1);
        }
    } 
static ERRBOOL SaveTAC(INT8U *errnum)
    {
    INT16U Td,Id;
    INT32U temp1,temp2;
    Co  = EDIT_GetValue(hEdit[2]);
    Ct  = EDIT_GetValue(hEdit[3]); 
    Co2 = EDIT_GetValue(hEdit[4]); 
    Td  = EDIT_GetValue(hEdit[5]); 
    Id  = EDIT_GetValue(hEdit[6]); 
    if(Td == 0)
        {
        *errnum = NOTICEDIS_KTV_TX_TIME_ZERO;
        return ERROR;
        } 
    if(Id == 0)
        {
        *errnum = NOTICEDIS_KTV_JIAN_GE_TIME_ZERO;
        return ERROR;
        }         
    temp1  = ( (Co+Ct)*Td + (Ct+Co2) *Id)/10;
    temp2 = 2*(Td+Id); 
    temp1 =  mDIV_45(temp1,temp2);
    GUI_SetColor(0x608060);
    GUI_FillRect(TACEDITX+30,(TACCHARY1+TACYY*5)-2,TACEDITX+66,(TACCHARY1+TACYY*5)+23);
    GUI_SetColor(GUI_GREEN);
    GUI_SetFont(&GUI_Font24B_1);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_DispDecAt(temp1,TACEDITX+30, (TACCHARY1+TACYY*5)-2, 2); 
    *errnum = 0;
    return OK;
    }

static void MainInit(void)
    {
    INT8U i;
    GUI_SetColor(GUI_BLACK);
    GUI_FillRect(0, UPY+1,640, 480);
 
    DrawWindow(PANOX, PANOY, PANOX+PANOL, PANOY+PANOH,GUI_BLUE,0x406040);   ////��3D����
 
    DrawPane(ARAE1X1,ARAE1Y1,ARAE1X2,ARAE1Y2,0x608060);     //��3D͹�ͷ��� 
    if(b_language_select)
    	{
	    #if COUNTRY == FARMARIN
	    DrawFrame(ARAE2X1,ARAE2Y1,ARAE2X2,ARAE2Y2, 102, 0x80a080, 0x204020);
	    DrawFrame(ARAE3X1,ARAE3Y1,ARAE3X2,ARAE3Y2, 58, 0x80a080, 0x204020);
	    #elif COUNTRY == COUNTRY_TNS
	    DrawFrame(ARAE2X1,ARAE2Y1,ARAE2X2,ARAE2Y2, 118, 0x80a080, 0x204020);
	    DrawFrame(ARAE3X1,ARAE3Y1,ARAE3X2,ARAE3Y2, 40, 0x80a080, 0x204020);    
	    #else
	    DrawFrame(ARAE2X1,ARAE2Y1,ARAE2X2,ARAE2Y2, 72, 0x80a080, 0x204020);
	    DrawFrame(ARAE3X1,ARAE3Y1,ARAE3X2,ARAE3Y2, 58, 0x80a080, 0x204020);
	    #endif
	    }
	else
		{
		DrawFrame(ARAE2X1,ARAE2Y1,ARAE2X2,ARAE2Y2, 72, 0x80a080, 0x204020);
		DrawFrame(ARAE3X1,ARAE3Y1,ARAE3X2,ARAE3Y2, 58, 0x80a080, 0x204020);
		}
 
    KTVButtonExit = BUTTON_Create(BUTEXITX, BUTEXITY, BUTEXITL, BUTEXITH,GUI_ID_CANCEL ,
BUTTON_CF_SHOW );
    GUI_SetTextMode(GUI_TM_TRANS);   
    GUI_SetColor(0xff00ff);  
    if(b_language_select)
        {
        #if COUNTRY == WZBKST
        GUI_DisHzAt("�ާ֧�� ��ҧ�֧ާ� �էڧѧݧڧ٧�", PANOX+PANOL/2-32, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DisHzAt("�էѧߧߧ�� ��ѧ�ڧ֧ߧ��", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DisHzAt("�ܧݧѧӧڧѧ����", ARAE3X1+12, ARAE3Y1-8);
        GUI_DisHzAt("�����", A2CHAR1X, A2CHAR1Y);  
        GUI_DisHzAt("�ӧ֧�", A2CHAR2X, A2CHAR1Y); 
        GUI_DisHzAt("����", A2CHARX1+20, A2CHARY3);  
        GUI_DisHzAt("�ާ�ا�ܧ��", A2DANX1-10+30, A2DANY3-14);  
        GUI_DisHzAt("�ا֧ߧ�ܧڧ�", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetFont(KTVButtonExit , &GUI_Font8x13);         
        BUTTON_SetText(KTVButtonExit, button_show_char("�ӧ����"));
           
        #elif COUNTRY == COUNTRY_SA     
        GUI_SetFont(&GUI_Font16B_1);
        GUI_DispStringAt("medida de volumen de di�lisis", PANOX+PANOL/2-32, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DispStringAt("Datos del paciente", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DispStringAt("teclado", ARAE3X1+12, ARAE3Y1-8);
        GUI_DispStringAt("Estatura", A2CHAR1X, A2CHAR1Y);  
        GUI_DispStringAt("Peso", A2CHAR2X, A2CHAR1Y); 
        GUI_DispStringAt("Sexo", A2CHARX1+20, A2CHARY3);  
        GUI_DispStringAt("Masc", A2DANX1-10+30, A2DANY3-14);  
        GUI_DispStringAt("Fem", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetFont(KTVButtonExit , &GUI_Font24B_1);         
        BUTTON_SetText(KTVButtonExit, "Salir");     
            
        #elif COUNTRY == FARMARIN      
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("Medi��o Volume Dialisato", PANOX+PANOL/2-32, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DispStringAt("Dados Paciente", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DispStringAt("Teclado", ARAE3X1+12, ARAE3Y1-8);
        GUI_DispStringAt("Altura", A2CHAR1X, A2CHAR1Y);  
        GUI_DispStringAt("Peso", A2CHAR2X, A2CHAR1Y); 
        GUI_DispStringAt("Idade", A2CHARX1+20, A2CHARY3);  
        GUI_DispStringAt("Homem", A2DANX1-10+30, A2DANY3-14);  
        GUI_DispStringAt("Mulher", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetFont(KTVButtonExit , &GUI_Font24B_1);         
        BUTTON_SetText(KTVButtonExit, "Sair");      
            
        #elif COUNTRY == COUNTRY_TNS
        
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("mesure du volume de la dialyse", PANOX+PANOL/2-60, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DispStringAt("Donn�es du malade", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DispStringAt("clavier", ARAE3X1+12, ARAE3Y1-8);
        GUI_DispStringAt("Hauteur", A2CHAR1X, A2CHAR1Y);  
        GUI_DispStringAt("Poids", A2CHAR2X, A2CHAR1Y); 
        GUI_DispStringAt("Genre:", A2CHARX1+20, A2CHARY3);  
        GUI_DispStringAt("Masculin", A2DANX1-10+30, A2DANY3-14);  
        GUI_DispStringAt("Feminin", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetFont(KTVButtonExit , &GUI_Font24B_1);         
        BUTTON_SetText(KTVButtonExit, "Quitter");
               
        #else
        GUI_SetFont(&GUI_Font_HZ16);
        GUI_DispStringAt_UC("͸����������", PANOX+PANOL/2-32, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DispStringAt_UC("��������", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DispStringAt_UC("����", ARAE3X1+20, ARAE3Y1-8);
        GUI_DispStringAt_UC("���", A2CHAR1X, A2CHAR1Y);  
        GUI_DispStringAt_UC("����", A2CHAR2X, A2CHAR1Y); 
        GUI_DispStringAt_UC("�Ա�", A2CHARX1+30, A2CHARY3);  
        GUI_DispStringAt_UC("��", A2DANX1-10+30, A2DANY3-14);  
        GUI_DispStringAt_UC("Ů", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetText(KTVButtonExit, "�˳�");
        #endif
        }

    else
        {
        GUI_SetFont(&GUI_Font16_1);
        GUI_DispStringAt("dialysis volume measure", PANOX+PANOL/2-32, PANOY+4);  
        GUI_SetColor(GUI_WHITE);            
        GUI_DispStringAt("Patient data", ARAE2X1+12, ARAE2Y1-8);  
        GUI_DispStringAt("keyboard", ARAE3X1+12, ARAE3Y1-8);
        GUI_DispStringAt("Height", A2CHAR1X, A2CHAR1Y);  
        GUI_DispStringAt("Weight", A2CHAR2X, A2CHAR1Y); 
        GUI_DispStringAt("Gender", A2CHARX1+20, A2CHARY3);  
        GUI_DispStringAt("Male", A2DANX1-10+30, A2DANY3-14);  
        GUI_DispStringAt("Female", A2DANX1-10+30, A2DANY3+14); 
        BUTTON_SetFont(KTVButtonExit , &GUI_Font24B_1);         
        BUTTON_SetText(KTVButtonExit, "Exit");
        }
 
    GUI_SetFont(&GUI_Font16_1);
    GUI_DispStringAt("cm",A2DAN1X, A2DAN1Y);
    GUI_DispStringAt("kg",A2DAN2X, A2DAN1Y);
 
    hEdit[0] = EDIT_Create(A2EDIT1X, A2EDIT1Y,EDIT3LM,EDITHM, ' ', 3, 0 );//���
    EDIT_SetDecMode(hEdit[0], mG_ManInfo.high, 40, 250,0,0); 
 
    hEdit[1] = EDIT_Create(A2EDIT2X, A2EDIT1Y, EDIT3LM,EDITHM, ' ', 3, 0 );//����
    EDIT_SetDecMode(hEdit[1],mG_ManInfo.weight, 1, 500,0,0);   
 
    SaveEdit = hEdit[0];
 
    hRadio[0] = RADIO_Create(A2EDITX1+30, A2EDITY3-16, RADIOL, 2*RADIOH, 0, ' ', WM_CF_SHOW, 
2); 
    if(mG_ManInfo.sex == MAN)    RADIO_SetValue(hRadio[0], 0);
    else                         RADIO_SetValue(hRadio[0], 1);
    for(i=0; i<2; i++)
        {
        EDIT_SetFont(hEdit[i], &GUI_Font24B_1);
        }
    KTVButton[0] = BUTTON_Create(BUTSELX, BUTSELY, BUTSELL, BUTSELH,GUI_ID_NUMB0 ,
BUTTON_CF_SHOW );
    BUTTON_SetText(KTVButton[0], "Kt/V");
 
    KTVButton[1] = BUTTON_Create(BUTSELX+BUTSELLL, BUTSELY, BUTSELL, BUTSELH,GUI_ID_NUMB1 ,
BUTTON_CF_SHOW );
    BUTTON_SetText(KTVButton[1], "URR");
 
    KTVButton[2] = BUTTON_Create(BUTSELX+2*BUTSELLL, BUTSELY, BUTSELL, BUTSELH,GUI_ID_NUMB2 ,
BUTTON_CF_SHOW );
    BUTTON_SetText(KTVButton[2], "SRI2pool");
 
    KTVButton[3] = BUTTON_Create(BUTSELX+3*BUTSELLL, BUTSELY, BUTSELL, BUTSELH,GUI_ID_NUMB3 ,
BUTTON_CF_SHOW );
    BUTTON_SetText(KTVButton[3], "nPCR");
 
    KTVButton[4] = BUTTON_Create(BUTSELX+4*BUTSELLL, BUTSELY, BUTSELL, BUTSELH,GUI_ID_NUMB4 ,
BUTTON_CF_SHOW );
    BUTTON_SetText(KTVButton[4], "TACurea");
 
    for(i=0; i<5; i++)
        {
        BUTTON_SetFont(KTVButton[i],&GUI_Font16_1); 
        BUTTON_SetBkColor(KTVButton[i],0,BNSELCOLOR); 
        }
    BUTTON_SetBkColor(KTVButtonExit,0,0xc0c0f0);   
    BUTTON_SetBkColor(KTVButton[0],0,BSELCOLOR);   
    CreateKey(KEYX,KEYY); 
    }
	
void SetUpInitKTV(void)
    { 
    DisMode = 0;
    MainInit();
    KTVInit();
    }

void ktv_alarm_select(INT8U uc_data)
    {
    DelKTV();
    show_notice(TYPE_ERR, NOTICE_SIZE_SMALL, uc_data ,KTVNOX , KTVNOY );

    }
    
static void SetUpSaveKTV(void)
    {
    INT8U err;
    ERRBOOL t;
    switch(DisMode)
        {
        case DISKTV:
            t = SaveKTV(&err);
            break;
        case  DISURR:
            t = SaveKTV(&err);          
            if( struct_mg_notice_flag.Flag == NO)
                {
                t = SaveURR(&err);
                if(t == ERROR )ktv_alarm_select(err);
                }
            break;       
        case  DISSRI:
            t = SaveKTV(&err);          
            if( struct_mg_notice_flag.Flag == NO)
                {          
                t = SaveSRI(&err);
                if(t == ERROR )ktv_alarm_select(err);
                }
            break;
        case  DISPCR:
            t = SaveKTV(&err);          
            if( struct_mg_notice_flag.Flag == NO)
                {
                t = SavePCR(&err);
                if(t == ERROR )ktv_alarm_select(err);
                }
            break;
        case  DISTAC:    
            t = SaveKTV(&err);          
            if( struct_mg_notice_flag.Flag == NO)
                {          
                t = SaveTAC(&err);
                if(t == ERROR )ktv_alarm_select(err);
                }
            break;
        default:   break;    
        }
    }

static void DelKTV(void)
    {
    INT8U i;
    switch(DisMode)
        {
        case DISKTV:
            WM_DeleteWindow(hRadio[1]); 
            PROGBAR_Delete(hProgBar);
            BUTTON_Delete(KTVButtonS1);    
            if(uc_mg_ktv_ddl_jz_ing)//���������У���еĻ�
                {
                uc_mg_ktv_ddl_jz_ing = 0;//ȡ��У��
                if(!uc_st_by_pass_back)//���ԭ���ǲ�����·
                    {
                    stop_ddl_jz_cancel_pl();//ȡ����·
                    }
                }
            break;
        case  DISURR:  
            if(struct_mg_notice_flag.Flag == NO)            
                {            
                for(i=2; i<4; i++) EDIT_Delete(hEdit[i]);           
                }
            break;       
        case  DISSRI:           
            if(struct_mg_notice_flag.Flag == NO)
                {    
                for(i=2; i<5; i++) EDIT_Delete(hEdit[i]);
                }
            break;
        case  DISPCR: 
            if(struct_mg_notice_flag.Flag == NO)
                {        
                for(i=2; i<7; i++) EDIT_Delete(hEdit[i]);
                }
            break;
        case  DISTAC:
            if(struct_mg_notice_flag.Flag == NO)
                { 
                for(i=2; i<7; i++)EDIT_Delete(hEdit[i]); 
                }
            break;
        default:   break;   
        }
    if(struct_mg_notice_flag.Flag == YES)            DelNotice(struct_mg_notice_flag.Type);  
    }
    
void show_ktv_tq_th_ddl(void)
    {
    if( (DisMode == DISKTV) && (struct_mg_notice_flag.Flag == NO) )
        {
        if((ui_st_ddl_before != ui_ddl_before_back)||(ui_st_ddl_after != ui_ddl_after_back))
            {
            EditSet();
            ui_ddl_before_back = ui_st_ddl_before ;
            ui_ddl_after_back = ui_st_ddl_after ;
            GUI_GotoXY(KTVDDLJBX+100, KTVDDLJBY+100);
            GUI_DispDecShift(ui_st_ddl_before,4, 1);
            GUI_GotoXY(KTVDDLJBX+100, KTVDDLJBY+160);
            GUI_DispDecShift(ui_st_ddl_after,4, 1);
            }
        }
    }    
	
void SetUpWorkKTV(int Key)
    {
    INT8U i,k;
    switch (Key)
        {
        case GUI_ID_OK: SetUpSaveKTV(); break;         
        case GUI_ID_NUMB0:
            if(DisMode != DISKTV)
                {
                BUTTON_SetBkColor(KTVButton[0],0,BSELCOLOR);  
                BUTTON_SetBkColor(KTVButton[DisMode],0,BNSELCOLOR);  
                DelKTV();
                KTVInit();
                DisMode = DISKTV;
                }
            break;           
        case GUI_ID_NUMB1:
            if(DisMode != DISURR)
                {
                BUTTON_SetBkColor(KTVButton[1],0,BSELCOLOR); 
                BUTTON_SetBkColor(KTVButton[DisMode],0,BNSELCOLOR); 
                DelKTV();
                URRInit();
                DisMode = DISURR;
                } 
            break;              
        case GUI_ID_NUMB2:
            if(DisMode != DISSRI)
                {
                BUTTON_SetBkColor(KTVButton[2],0,BSELCOLOR); 
                BUTTON_SetBkColor(KTVButton[DisMode],0,BNSELCOLOR); 
                DelKTV();
                SPIInit();
                DisMode = DISSRI;
                }  
            break;            
        case GUI_ID_NUMB3:
            if(DisMode != DISPCR)
                {
                BUTTON_SetBkColor(KTVButton[3],0,BSELCOLOR); 
                BUTTON_SetBkColor(KTVButton[DisMode],0,BNSELCOLOR); 
                DelKTV();
                PCRInit();
                DisMode = DISPCR;
                }
            break;            
        case GUI_ID_NUMB4:
            if(DisMode != DISTAC)
                {
                BUTTON_SetBkColor(KTVButton[4],0,BSELCOLOR); 
                BUTTON_SetBkColor(KTVButton[DisMode],0,BNSELCOLOR); 
                DelKTV();
                TACInit();
                DisMode = DISTAC;
                }
            break;                  
        case GUI_ID_NUMB5:
            if(struct_mg_notice_flag.Flag == NO)
                {
                if(uc_mg_ktv_ddl_jz_ing)//����絼������У��
                    {
                    uc_mg_ktv_ddl_jz_ing = 0;//ȡ��У��
                    if(!uc_st_by_pass_back)//���ԭ���ǲ�����·
                        {
                        stop_ddl_jz_cancel_pl();//ȡ����·
                        }
                    }
                else//û����У��
                    {
                    if(StartDDLJ() == YES)  
                        {
                        uc_mg_ktv_ddl_jz_ing = 1; //��ʾ����У��
                        }
                    }
                }  
            break;              
        case GUI_ID_NO:
            DelNotice(struct_mg_notice_flag.Type);
            GUI_SetColor(0x608060);
            GUI_FillRect(KTVNOX, KTVNOY,KTVNOX+AAREAXX, KTVNOY+AAREAYY);               
            switch(DisMode)
                {
                case DISKTV: ktv_init_add();break;
                case DISURR: URRInit();  break;
                case DISSRI: SPIInit();  break;
                case DISPCR: PCRInit();  break;
                case DISTAC: TACInit();  break;
                }
            break;  
        default:  
            switch(DisMode)
                {
                case DISKTV: k = 2;    break;
                case DISURR: k = 4;    break;       
                case DISSRI: k = 5;    break;
                case DISPCR: k = 7;    break;
                case DISTAC: k = 7;    break;
                default:   break;    
                }
            if( struct_mg_notice_flag.Flag == YES)k = 2;      
            for(i=0; i<k; i++)
                { 
                if(SaveEdit == hEdit[i]) 
                    {
                    EDIT_AddKey(SaveEdit, Key);
                    break;
                    }
                }
           break;  
        }
    if(uc_mg_ktv_ddl_jz_ing)       //���ڽ���У��У��
        {
        DDLJWork(); 
        }
    show_ktv_tq_th_ddl();
    }

void  FoundFoucKTV(void)  
    {
    INT8U i, k;
    switch(DisMode)
        {
        case DISKTV: k = 2;    break;
        case DISURR: k = 4;    break;       
        case DISSRI: k = 5;    break;
        case DISPCR: k = 7;    break;
        case DISTAC: k = 7;    break;
        default:   break;    
        }
    if( struct_mg_notice_flag.Flag == YES)k = 2;      
    for(i=0; i<k; i++)
        {
        if(WM__hWinFocus == hEdit[i])
            {
            SaveEdit = hEdit[i];
            break;
            } 
        } 
    }
	
void SetUpDelKTV(void)
    {
    INT8U i; 
    for(i=0; i<2; i++)    EDIT_Delete(hEdit[i]);
    for(i=0; i<1; i++)    WM_DeleteWindow(hRadio[i]);      
    DelKTV();
    DelKey();
    for(i=0; i<5; i++)   BUTTON_Delete(KTVButton[i]);
    BUTTON_Delete(KTVButtonExit);     
   }

   
static void stop_ddl_jz_cancel_pl(void)
   {
   INT8U err;
   mG_Bypass_Sele = 0;
   CommQBuf[Q_COMM_CANCEL_BYPASS - Q_COMM_START] = Q_COMM_CANCEL_BYPASS;        
//Ҫ��ˮ·ȡ����·
   err = OSQPost(CommQ,(void *)&CommQBuf[Q_COMM_CANCEL_BYPASS - Q_COMM_START]);
   }
   
static MYBOOL StartDDLJ(void)
   {
   MYBOOL uc_temp_bool;
   INT8U err;
   if(ui_mg_water_run_status != WATER_YC)                                                   
//������Ԥ����У��
       {
       show_notice(TYPE_ERR, NOTICE_SIZE_SMALL, NOTICEDIS_KTV2 ,KTVNOX , KTVNOY );
       uc_temp_bool = NO;
       }

   else if( ui_mg_water_ddl < KTV_DDL_JZ_MIN   )
       {  
       show_notice(TYPE_ERR, NOTICE_SIZE_SMALL, NOTICEDIS_KTV1 ,KTVNOX , KTVNOY );
       uc_temp_bool = NO;
       }
   else if( ui_mg_water_ddl > KTV_DDL_JZ_MAX   )
       {
       show_notice(TYPE_ERR, NOTICE_SIZE_SMALL, NOTICEDIS_KTV5 ,KTVNOX , KTVNOY );
       uc_temp_bool = NO;
       }       
   else 
       {
       DDL_J_Time = 0;
       GUI_SetColor(GUI_WHITE);
       GUI_SetFont(&GUI_Font16_1);
       GUI_SetTextMode(GUI_TM_TRANS); 
       
       if (b_language_select)
           {
           #if COUNTRY == COUNTRY_SA
           GUI_DisHzAt("Calibrating,please wait!", KTVNOX, KTVNOY+20);   
           #elif COUNTRY == FARMARIN
           GUI_DisHzAt("Calibrating,please wait!", KTVNOX, KTVNOY+20); 
           #elif COUNTRY == COUNTRY_TNS
           GUI_DisHzAt("Calibrage, patientez s'il vous pla�t!", KTVNOX, KTVNOY+20);  
           
                      
           #else
           GUI_DisHzAt("Calibrating,please wait!", KTVNOX, KTVNOY+20);  
           #endif
           }
       else
           {
           GUI_DisHzAt("Calibrating,please wait!", KTVNOX, KTVNOY+20);  
           }    
       
       if(!uc_st_by_pass_back)
           {
           mG_Bypass_Sele = 1;       
           CommQBuf[Q_COMM_BYPASS_WATER - Q_COMM_START] = Q_COMM_BYPASS_WATER;        
//Ҫ��ˮ·��·
           err = OSQPost(CommQ,(void *)&CommQBuf[Q_COMM_BYPASS_WATER - Q_COMM_START]);       
           }
       uc_temp_bool = YES;  
       }   
   return uc_temp_bool;
   }
   
static void DDLJWork(void)
   { 
   INT8U err;
   INT16U ui_temp_data;
   DDL_J_Time++;
   PROGBAR_SetValue(hProgBar, DDL_J_Time);
   
   if(DDL_J_Time == (KTVDDLJTIME-20))                                         
//��ʼ���������絼
       {
       ui_temp_data = abs_absolute(ui_mg_water_ddl , ui_mg_th_ddl);
       if(ui_temp_data < KTV_TQ_TH_DDL_ALLOW_MAX_ERR)//���ǰ��絼���������1.0ms/cm
           {
           CommQBuf[Q_COMM_KTVDDL - Q_COMM_START] = Q_COMM_KTVDDL;
           err = OSQPost(CommQ,(void *)&CommQBuf[Q_COMM_KTVDDL - Q_COMM_START]);
           }
       else
           {
           DDL_J_Time = KTVDDLJTIME;      
           PROGBAR_SetValue(hProgBar, DDL_J_Time);                
           uc_mg_ktv_ddl_jz_ing = 0;//��ʾ�Ѿ����ڽ���У���� 
           if(!uc_st_by_pass_back)//���ԭ���ǲ�����·
              {
              stop_ddl_jz_cancel_pl();          
              }
           show_notice(TYPE_ALARM, NOTICE_SIZE_SMALL, NOTICEDIS_KTV6 ,KTVNOX , KTVNOY );
           }    
       } 
       
   else if(DDL_J_Time >= KTVDDLJTIME)
       {
       uc_mg_ktv_ddl_jz_ing = 0;//��ʾ�Ѿ����ڽ���У����
       if(!uc_st_by_pass_back)//���ԭ���ǲ�����·
           {
           stop_ddl_jz_cancel_pl();
           }
       ui_st_ddl_before  = mG_KTVHDInfo.ddlIn[mG_KTVHDInfo.Counter-1];
       ui_st_ddl_after   = mG_KTVHDInfo.ddlOut[mG_KTVHDInfo.Counter-1];
       mG_KTVHDInfo.Counter = 0;
       ui_temp_data = abs_absolute(ui_st_ddl_before , ui_st_ddl_after);
       if( (ui_st_ddl_before > KTV_DDL_JZ_MAX) || (ui_st_ddl_before < KTV_DDL_JZ_MIN)  
         ||(ui_st_ddl_after > KTV_DDL_JZ_MAX)  || (ui_st_ddl_after < KTV_DDL_JZ_MIN)  
         || ui_temp_data >=  KTV_TQ_TH_DDL_ALLOW_MAX_ERR) 
            {
            show_notice(TYPE_ALARM, NOTICE_SIZE_SMALL, NOTICEDIS_KTV3 ,KTVNOX , KTVNOY );
            }       
       else                                                                     //У���ɹ� 
           {
           ui_temp_data = ui_st_ddl_before;
           ui_st_ddl_before =ui_st_ddl_before * 100;
           if(ui_st_ddl_after)
               {
               mG_KTVHDInfo.DDL_para = mDIV_45(ui_st_ddl_before , ui_st_ddl_after);
               }
           else
               {
               mG_KTVHDInfo.DDL_para = 100;
               }    
           uinion_data_buff_fill(&mG_KTVHDInfo.DDL_para, 1);
           write_in_1024(SAVE_UCHAR_KTV_DDL_PARA, &union_write_data_buff_in_1024 , 1);
                                                       
           
           show_notice(TYPE_OK, NOTICE_SIZE_SMALL, NOTICEDIS_KTV4 ,KTVNOX , KTVNOY );
           ui_st_ddl_before = ui_temp_data;
           uc_mg_ktv_already_jy = 1;//��ʾ�Ѿ�������У��
               
           }
       }
   }
#endif