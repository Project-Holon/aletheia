/*
 * function: func_021DD90C
 * address: 0x021DD90C
 * packet: pkt_ov119_021DD90C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02 lane R1: closed by storing the call result straight into items[i] and reading it back
 * (w=items[i]): the pointer local stays live across the call and the forwarded value is spilled.
 * symbols:
 *   d_021E76FC 0x021E76FC data a4
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int a,b; } Pair;
extern const Pair d_021E76FC;
extern int func_021D8AA8(void *);
typedef signed short   s16;
struct Cfg;
struct Descriptor;
struct MsgBank;
extern u32 func_020452E8(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021DD90C(u8 *p,int i,int msg,int force)
{
    Pair t=d_021E76FC;
    int w;
    int *items;
    if(force==0) {
        if((p+i)[0x11e8]==3) return;
        if(p[0x11ea]==0) return;
        if(func_021D8AA8(p)==0) return;
    }
    if(*(int *)(p+i*4+0x5bc)) func_020452E8((struct Descriptor *)(*(int *)(p+i*4+0x5bc)));
    items=(int *)(p+0x5bc); items[i]=(int)BMP_WIN_Create(3,(u8)(((int *)&t)[i]),16,12,2,5,0); w=items[i];
    GF_FONT_SetTextColor(5,6,0);
    msg+=0x72;
    func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),msg,(void *)(*(int *)&((struct Obj00001 *)p)->f730));
    PRINTSYS_Print(func_02045770((struct Descriptor *)w),0,0,(void *)(*(int *)&((struct Obj00001 *)p)->f730),(void *)(*(int *)&((struct Obj00001 *)p)->f728));
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(3);
    (p+i)[0x11e8]=3;
}
