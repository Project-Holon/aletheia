/*
 * function: func_021588D0
 * address:  0x021588D0
 * packet:   pkt_021588D0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern u8 *func_020120F8(const struct Ctx *p);
extern int func_02012AC8();

int func_021588D0(int a0)
{
    u8 *p;

    p = func_020120F8((const struct Ctx *)a0);
loc_021588D6:
    a0 = func_02012AC8(p);
loc_021588DA:
    return a0;}
