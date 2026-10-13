/*
 * function: func_021F15B0
 * address: 0x021F15B0
 * packet: pkt_ov107_021F15B0
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   func_02028484 0x02028484 thumb
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 */
#include "../include/Obj22302.h"
typedef unsigned short u16;
struct Descriptor;
struct Ctx;
struct Rec3;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void APP_TASKMENU_UpdateMenu(void *);
typedef signed int     s32;
struct Blk;
struct PrintSys;
extern s32 func_02028484(struct Blk *blk, void *h);
extern unsigned int PRINTSYS_QUE_Main(struct PrintSys *ps);
extern unsigned int PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);
#define P(k) (*(void **)(p+(k)))
#define I(k) (*(int *)(p+(k)))
void func_021F15B0(char *p)
{
    int done;
    TCBL_Main(P(12));
    if(P(0x18)){
        done=func_02028484((struct Blk *)(p+0x28),P(0x18));
        APP_KEYCURSOR_Update(P(0x44),P(0x18),P(0x10));
        if(done==1){PRINTSYS_PrintStreamDelete(P(0x18));P(0x18)=0;}
    }
    PRINTSYS_QUE_Main(P(0x30));
    if(I(0x34)==1 && PRINTSYS_QUE_IsFinished(P(0x30))==1){
        BMP_WIN_TransferChars(P(0x10));I(0x34)=0;
        if(I(0x58)==1){I(0x58)=0;P(0x5C)=TIME_ICON_CreateNode((u32)P(12),P(0x10),15,16,((struct Obj22302 *)p)->f0);}
    }
    if(P(0x3C))APP_TASKMENU_UpdateMenu(P(0x3C));
}
