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
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 */
#include "../include/Obj12844.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void SCRCMD_PROC_FLD_FreeShopWindows(u8 *w)
{
    int i;

    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj12844 *)w)->f1B0));
    for (i = 0; i < 7; i++) {
        BMP_WIN_Delete((struct Descriptor *)(*(u32 *)(w + 0x164 + i * 4)));
    }
}
