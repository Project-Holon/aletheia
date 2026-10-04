/*
 * unit:     yes
 * function: func_020137C0
 * address:  0x020137C0
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013528     0x02013528  thumb
  *   func_0203D1A4     0x0203D1A4  arm
 *
 * The id-1 member of the same family - byte for byte func_02013790 with a 1
 * where it has a 0 (the third argument of func_02013528).

 * Verified with:
 *   python tools/match.py one --src src/matched/func_020137C0.c \
 *       --func func_020137C0 --addr 0x020137C0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013528(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d, u32 e, u32 f);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_020137C0(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4)
{
    u32 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 1, 0, p2, p3, r, p4);
}

