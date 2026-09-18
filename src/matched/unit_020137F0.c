/*
 * unit:     yes
 * function: func_020137F0
 * address:  0x020137F0
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
  *
 *
 * The shortest member of the family: no func_0203D1A4 call, and the two stack
 * arguments the caller passes (a byte at +0x00 and a halfword at +0x04 of the
 * caller's stack block) are forwarded as the seventh and eighth arguments.

 * Verified with:
 *   python tools/match.py one --src src/matched/func_020137F0.c \
 *       --func func_020137F0 --addr 0x020137F0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013528(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d, u32 e, u32 f);

void func_020137F0(u32 p0, u32 p1, u32 p2, u32 p3, u8 p4, u16 p5)
{
    func_02013528(p0, p1, 1, 1, p2, p3, p4, p5);
}

