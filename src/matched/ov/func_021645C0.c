/*
 * function: func_021645C0
 * address:  0x021645C0
 * packet:   pkt_021645C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Size the third argument through the arm9 helper, bail when the arm9
 * status is set, otherwise copy it out.
 *
 * symbols:
 *   func_02012AC8   0x02012AC8  thumb
 *   func_02013D20   0x02013D20  thumb
 *   func_02013E04   0x02013E04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec44;
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D20(u32 id);
extern u32 func_02013E04(u32 id);

int func_021645C0(void *a0, void *a1, void *a2)
{
    int r = func_02012AC8(a2);

    if (func_02013D20(r) != 0)
        return 0;

    return func_02013E04(r);
}

