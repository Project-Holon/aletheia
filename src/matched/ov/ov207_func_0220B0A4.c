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
 *   func_021BA374 0x021BA374 thumb ov206
 *   ZUKAN_NICKNAME_Main 0x0220B72C thumb ov207
 *   FADE_IsActive 0x0204E804 arm
 *   func_021BA544 0x021BA544 thumb ov206
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_021BA514 0x021BA514 thumb ov206
 *   func_021BA524 0x021BA524 thumb ov206
 *   func_021BA534 0x021BA534 thumb ov206
 *   func_0207D67C 0x0207D67C arm
 *   func_021BA4CC 0x021BA4CC thumb ov206
 *   ZUKAN_TOROKU_GRAPHIC_CreateBg 0x0220B260 thumb ov207
 *   func_021BA51C 0x021BA51C thumb ov206
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
extern void func_021BA374(char *);
extern int ZUKAN_NICKNAME_Main(char *);
extern int FADE_IsActive(void);
extern void func_021BA544(char *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8);
extern void func_021BA514(char *);
extern int func_021BA524(char *);
extern int func_021BA534(char *);
extern void func_0207D67C(u32,int,int,int,int,int);
extern void func_021BA4CC(char *);
extern void ZUKAN_TOROKU_GRAPHIC_CreateBg(u32 *);
extern void func_021BA51C(char *);
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
    func_021BA374((char *)p[8]);
    result=ZUKAN_NICKNAME_Main((char *)p[9]);
    switch(p[4]) {
    case 0:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { func_021BA544((char *)p[8]); p[5]=1; }
            break;
        case 1:
            flag=0;
            input=TOUCHPANEL_GetTrg();
            if(KEY_GetTrg()&3) { func_020355D8(0); flag=1; }
            if(input!=0) { func_020355D8(1); flag=1; }
            if(flag!=0) { func_021BA514((char *)p[8]); p[5]=2; }
            break;
        case 2:
            if(func_021BA524((char *)p[8])!=0 || func_021BA534((char *)p[8])!=0) { p[7]=0; p[6]=16; p[5]=3; }
            break;
        case 3:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]--; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==0) { func_021BA4CC((char *)p[8]); ZUKAN_TOROKU_GRAPHIC_CreateBg(p); p[5]=4; }
            break;
        case 4:
            p[7]++;
            if(p[7]==4) { p[7]=0; p[6]++; }
            func_0207D67C(0x04000050,15,15,p[6],0,p[6]-16);
            if(p[6]==16) p[5]=5;
            break;
        case 5:
            if(func_021BA534((char *)p[8])!=0) { p[4]=1; p[5]=1; }
            break;
        }
        break;
    case 1:
        switch(p[5]) {
        case 0:
            if(FADE_IsActive()==0) { func_021BA51C((char *)p[8]); p[5]=1; }
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
