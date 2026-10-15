/*
 * function: MYSTERY_UTIL_SetMenuMode
 * address: 0x021D9F24
 * packet: pkt_ov121_021D9F24
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: duplicate the case 2/0 drawing bodies; cross-jumping retains the case 2 branch.
 * interface: 02028590 forwards the allocation result of 020285A4 in r0;
 *            this caller stores that result at +0x30 despite the old void definition.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MYSTERY_UTIL_ResetMenuWindow 0x021DA010 thumb ov121
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   PRINTSYS_CTRL_Init  0x02028470  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 */
#include "../include/Obj00236.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct Rec3;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
struct PrintSys;
extern int APP_KEYCURSOR_Delete(int a0);
extern void MYSTERY_UTIL_ResetMenuWindow(u8 *);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void PRINTSYS_CTRL_Init(u8 *p, u32 v);
extern void *APP_KEYCURSOR_CreateDefault(u32,u32,u32,u32);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *,u32,u32,u32,u32,int,void *,u32,u16,u16);
void MYSTERY_UTIL_SetMenuMode(u8 *p,int mode)
{
    u32 q;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00236 *)p)->f10),((struct Obj00236 *)p)->f18);
    if(((struct Obj00236 *)p)->f8) {
        PRINTSYS_PrintStreamDelete(((struct Obj00236 *)p)->f8);
        ((struct Obj00236 *)p)->f8=0;
    }
    if(((struct Obj00236 *)p)->f30) {
        APP_KEYCURSOR_Delete((int)(((struct Obj00236 *)p)->f30));
        ((struct Obj00236 *)p)->f30=0;
    }
    MYSTERY_UTIL_ResetMenuWindow(p);
    switch(mode) {
    case 2:
        ((struct Obj00236 *)p)->f3C=TIME_ICON_Create((void *)func_020056BC(),((struct Obj00236 *)p)->f10,((struct Obj00236 *)p)->f18,16,((struct Obj00236 *)p)->f1A);
        q=((struct Obj00236 *)p)->f24;
        PRINTSYS_PrintQue((struct PrintSys *)q,(u32)BMP_WIN_GetBmp(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 0:
        q=((struct Obj00236 *)p)->f24;
        PRINTSYS_PrintQue((struct PrintSys *)q,(u32)BMP_WIN_GetBmp(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 1:
        PRINTSYS_CTRL_Init(p+0x34,2);
        ((struct Obj00236 *)p)->f30=APP_KEYCURSOR_CreateDefault(((struct Obj00236 *)p)->f18,1,0,((struct Obj00236 *)p)->f1A);
        ((struct Obj00236 *)p)->f8=PRINTSYS_PrintStream(((struct Obj00236 *)p)->f10,0,0,*(u32 *)&((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4,MSG_SPEED_GetWait(),((struct Obj00236 *)p)->fC,0,((struct Obj00236 *)p)->f1A,((struct Obj00236 *)p)->f18);
        ((struct Obj00236 *)p)->f28=1;
        break;
    }
    ((struct Obj00236 *)p)->f2C=0;
}
