/*
 * unit:     no
 * address:  0x02022268
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02022268
 *
 * symbols:
 *   g_021468E4     0x021468E4  data
 *   func_020222CC  0x020222CC  thumb
 *
 * Same sentinel-mapping shape as func_0202223C.c, but read-modify-write:
 * it substitutes the sentinel readback the same way, maps the result to
 * one of the same two hardware constants, forwards it to both of
 * func_020222CC's hardware selections (0 and 1), and then stores the
 * *pre-mapping* colour back into the same halfword field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022268.c \
 *       --func func_02022268 --addr 0x02022268 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

extern void func_020222CC(u32 which, u32 v);

struct G {
    u8  pad[0x10];
    u16 f10;
};
extern struct G g_021468E4;

void func_02022268(u32 color)
{
    u32 mapped;

    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        mapped = 0x10;
    } else {
        mapped = ~(u32)0xF;
    }
    func_020222CC(0, mapped);
    func_020222CC(1, mapped);
    g_021468E4.f10 = color;
}
