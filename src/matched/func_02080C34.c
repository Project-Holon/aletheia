/*
 * function: func_02080C34
 * address:  0x02080C34
 * packet:   pkt_02080C34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     gx_vramcnt.o GX_GetBankForOBJExtPltt.
 *
 * symbols:
 *   gGXState  0x02150E4C  data  a4
 */

typedef unsigned short u16;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt;

extern GX_VRAMCnt gGXState;

u16 func_02080C34(void)
{
    return gGXState.objExtPltt;
}
