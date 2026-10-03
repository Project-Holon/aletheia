/*
 * function: func_021EDF4C
 * address:  0x021EDF4C
 * packet:   pkt_ov093_021EDF4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040618  0x02040618  arm  arm9
 */
typedef unsigned char u8;
struct W {
    u8 pad[0xa];
    u8 fa;
    u8 fb;
    u8 pad2[0x16];
    u8 f22_0 : 1;
};
typedef unsigned int   u32;
extern void func_02040618(u32 layer, u32 a, u32 b);
void func_021EDF4C(struct W *w)
{
    if (w->fa == 0)
        func_02040618(w->fb, 0, 0x90);
    else
        func_02040618(w->fb, 0, -0x90);
    w->f22_0 = 0;
}
