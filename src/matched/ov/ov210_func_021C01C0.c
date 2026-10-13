/*
 * function: func_021C01C0
 * address: 0x021C01C0
 * packet: pkt_ov210_021C01C0
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   FRAME_LIST_ShowCursor 0x021B940C thumb ov067
 *   d_021C0B24 0x021C0B24 data a4
 */
#include "../include/Obj25635.h"

typedef unsigned int u32;
extern const unsigned d_021C0B24[];
extern int TOUCHPANEL_HitTrg(const void *);
extern void func_020355D8(unsigned char);
extern u32 func_020362DC(void);
extern unsigned char func_020355C4(void);
struct S;
extern void FRAME_LIST_ShowCursor(struct S *s);
int func_021C01C0(char *ctx)
{
    int result = TOUCHPANEL_HitTrg(d_021C0B24);
    if (result != -1) { func_020355D8(1); return result; }
    if (func_020362DC() & 2) { func_020355D8(0); return 8; }
    if (func_020362DC() & 8) { func_020355D8(0); return 8; }
    if (func_020362DC() & 4) {
        if (func_020355C4() == 1) {
            func_020355D8(0);
            FRAME_LIST_ShowCursor(((struct Obj25635 *)ctx)->f1E0);
        }
        return 9;
    }
    return result;
}
