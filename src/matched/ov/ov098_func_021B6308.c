/*
 * function: PDC_MAIN_Update
 * address: 0x021B6308
 * packet: pkt_ov098_021B6308
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   BTLV_EFFECT_Main 0x021F78E4 thumb ov094
 *   BTLV_INPUT_UpdateInfoWindow 0x02202228 thumb ov094
 */
#include "../include/Obj10196.h"
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void BTLV_EFFECT_Main(void);
extern void BTLV_INPUT_UpdateInfoWindow(void **);
int PDC_MAIN_Update(unsigned p)
{
    int (*cb)(unsigned);
    TCBL_Main(((struct Obj10196 *)p)->f18);
    BTLV_EFFECT_Main();
    BTLV_INPUT_UpdateInfoWindow(*(void ** *)&((struct Obj10196 *)p)->f10);
    cb = *(int (**)(unsigned))(p + 0x68);
    if (cb != 0) return cb(p);
    return 0;
}
