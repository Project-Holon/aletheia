/*
 * function: func_021F10D8
 * address:  0x021F10D8
 * packet:   pkt_ov032_021F10D8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F10D8 0x021F10D8 thumb
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   PALANM_CopyToSlot 0x020215BC thumb
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 func_02165CB4(int a);
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);

void func_021F10D8(char *this, u8 *p, int a)
{
    u8 v;
    int k;

    p[3] = func_02165CB4(a);
    v = p[3];
    if (v == 0) {
        k = 0x30;
        v = 5;
    } else {
        k = 0x35;
    }
    PALANM_CopyToSlot((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + 0x30, (int)3, (u16)((p[0] + 4) * 16 + 8), 10);
    PALANM_CopyToSlot((struct PalAnmSlot *)(*(int *)&((struct Obj00007 *)this)->fAC), *(u16 * *)&((struct Obj00007 *)this)->f3C8 + k, (int)3, (u16)((p[0] + 4) * 16 + 8), v * 2);
}
