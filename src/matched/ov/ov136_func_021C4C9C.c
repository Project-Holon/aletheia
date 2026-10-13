/*
 * function: func_021C4C9C
 * address: 0x021C4C9C
 * packet: pkt_ov136_021C4C9C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021C4B88 0x021C4B88 thumb ov136
 *   d_021C7EF8 0x021C7EF8 data a1
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   PALANM_BlendChannel  0x02021FD8  thumb  arm9
 */
#include "../include/Obj02865.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Chan02021FD8;
struct Ctx;
struct Obj02021EE4;
struct S02021D50;
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), u8 *, int);
extern void func_021C4B88(void *, u8 *);
extern char d_021C7EF8[];
void func_021C4C9C(u8 *p)
{
    void *q;
    PALANM_BlendChannel(((struct Obj02865 *)p)->f38, 0, 0, 112, 16, 0);
    PALANM_SetAutoTransfer(((struct Obj02865 *)p)->f38, 1);
    PALANM_TransferPalettes(((struct Obj02865 *)p)->f38);
    p[0x18] = 0;
    p[0x19] = 0;
    q = func_02030734((u16)((struct Obj02865 *)p)->f0, func_02030CB0(3), 0, d_021C7EF8, 0x4F3);
    ((struct Obj02865 *)p)->fF4 = q;
    ((struct Obj02865 *)p)->fF8 = func_02030CBC(3, q);
    ((struct Obj02865 *)p)->fFC = func_02030DA8(((struct Obj02865 *)p)->fF8, func_021C4B88, p, 0);
}
