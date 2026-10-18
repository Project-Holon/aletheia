/*
 * function: ZUKAN_TOROKU_GRAPHIC_Main
 * address: 0x0220B0A4
 * packet: pkt_ov207_0220B0A4
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C60 is void in its matched forwarder, but this caller keeps and tests live r0.
 * symbols:
 *   ZUKAN_INFO_Update 0x021BA374 thumb ov206
 *   ZUKAN_NICKNAME_Main 0x0220B72C thumb ov207
 *   FADE_IsActive 0x0204E804 arm
 *   ZUKAN_INFO_Start 0x021BA544 thumb ov206
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   ZUKAN_INFO_NotifyMoveDone 0x021BA514 thumb ov206
 *   ZUKAN_INFO_IsMoving 0x021BA524 thumb ov206
 *   ZUKAN_INFO_IsDone 0x021BA534 thumb ov206
 *   G2x_SetBlendBrightnessExt_ 0x0207D67C arm
 *   ZUKAN_INFO_ClearDisplay 0x021BA4CC thumb ov206
 *   ZUKAN_TOROKU_GRAPHIC_CreateBg 0x0220B260 thumb ov207
 *   ZUKAN_INFO_NotifyFadeDone 0x021BA51C thumb ov206
 *   ZUKAN_NICKNAME_SetupScreen 0x0220B908 thumb ov207
 *   FADE_Start 0x0204E720 arm
 *   ZUKAN_NICKNAME_GetResult 0x0220B940 thumb ov207
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   ZUKAN_TOROKU_GRAPHIC_Draw 0x0220B40C thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_Update 0x0220B420 thumb ov207
 *   ZUKAN_TOROKU_GRAPHIC_UpdateSub 0x0220B424 thumb ov207
 */
typedef unsigned int u32;
typedef unsigned char u8;
struct PrintSys;
extern void ZUKAN_INFO_Update(char *);
extern int ZUKAN_NICKNAME_Main(char *);
extern int FADE_IsActive(void);
extern void ZUKAN_INFO_Start(char *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void UI_SetInputMode(u8);
extern void ZUKAN_INFO_NotifyMoveDone(char *);
extern int ZUKAN_INFO_IsMoving(char *);
extern int ZUKAN_INFO_IsDone(char *);
extern void G2x_SetBlendBrightnessExt_(u32,int,int,int,int,int);
extern void ZUKAN_INFO_ClearDisplay(char *);
extern void ZUKAN_TOROKU_GRAPHIC_CreateBg(u32 *);
extern void ZUKAN_INFO_NotifyFadeDone(char *);
extern void ZUKAN_NICKNAME_SetupScreen(char *);
extern void FADE_Start(u32,int,int,int);
extern int ZUKAN_NICKNAME_GetResult(char *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern void ZUKAN_TOROKU_GRAPHIC_Draw(u8 *p);
extern void ZUKAN_TOROKU_GRAPHIC_Update(void *);
extern void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *);
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,u32 *p)
{
    int done=0;
    int result,flag,input;
    ZUKAN_INFO_Update((char *)p[8]);
    result=ZUKAN_NICKNAME_Main((char *)p[9]);
    switch(p[4]) {
    case 0:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { ZUKAN_INFO_Start((char *)p[8]); p[5]=1; }
            break;
        case 1:
            flag=0;
            input=TOUCHPANEL_GetTrg();
            if(KEY_GetTrg()&3) { UI_SetInputMode(0); flag=1; }
            if(input!=0) { UI_SetInputMode(1); flag=1; }
            if(flag!=0) { ZUKAN_INFO_NotifyMoveDone((char *)p[8]); p[5]=2; }
            break;
        case 2:
            if(ZUKAN_INFO_IsMoving((char *)p[8])!=0 || ZUKAN_INFO_IsDone((char *)p[8])!=0) { p[7]=0; p[6]=16; p[5]=3; }
            break;
        case 3:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]--; }
            G2x_SetBlendBrightnessExt_(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==0) { ZUKAN_INFO_ClearDisplay((char *)p[8]); ZUKAN_TOROKU_GRAPHIC_CreateBg(p); p[5]=4; }
            break;
        case 4:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]++; }
            G2x_SetBlendBrightnessExt_(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==16) p[5]=5;
            break;
        case 5:
            if(ZUKAN_INFO_IsDone((char *)p[8])!=0) { p[4]=1; p[5]=1; }
            break;
        }
        break;
    case 1:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { ZUKAN_INFO_NotifyFadeDone((char *)p[8]); p[5]=1; }
            break;
        case 1:
            ZUKAN_NICKNAME_SetupScreen((char *)p[9]); p[5]=2;
            break;
        case 2:
            if(result==1) { FADE_Start(3,0,16,2); p[5]=3; }
            break;
        case 3:
            if(FADE_IsActive()==0) {
                switch(ZUKAN_NICKNAME_GetResult((char *)p[9])) {
                case 0: args[7]=0; break;
                case 1: args[7]=1; break;
                }
                p[5]=4; done=1;
            }
            break;
        }
        break;
    }
    PRINTSYS_QUE_Main((struct PrintSys *)p[3]);
    ZUKAN_TOROKU_GRAPHIC_Draw((void *)p[1]);
    ZUKAN_TOROKU_GRAPHIC_Update((void *)p[1]);
    ZUKAN_TOROKU_GRAPHIC_UpdateSub((void *)p[1]);
    return done;
}
