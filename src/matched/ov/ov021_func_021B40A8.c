/*
 * function: SCRCMD_PROC_FLD_FreeShopWindows
 * address:  0x021B40A8
 * packet:   pkt_ov021_021B40A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_020452E8  0x020452E8  arm
 */
#include "../include/Obj12844.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);

void SCRCMD_PROC_FLD_FreeShopWindows(u8 *w)
{
    int i;

    func_0201C6EC((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    func_0201C4C0((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    for (i = 0; i < 7; i++) {
        func_020452E8((struct Descriptor *)(*(u32 *)(w + 0x164 + i * 4)));
    }
}
