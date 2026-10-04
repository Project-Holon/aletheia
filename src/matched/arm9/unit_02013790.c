/*
 * unit:     yes
 * function: func_02013790
 * address:  0x02013790
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
 * The id-0 member of the second builder family in this packet: the fourth
 * argument of the shared 8-argument helper func_02013528 is 0, and the
 * object's argument is first run through func_0203D1A4 (ARM) whose result
 * becomes the seventh argument.  func_02013528's last four parameters live
 * on the stack, which is the sixteen-byte frame.

 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013790.c \
 *       --func func_02013790 --addr 0x02013790 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02013528(u32 p0, u32 p1, u32 id, u32 b, u32 c, u32 d, u32 e, u32 f);
struct Link;
extern u32 func_0203D1A4(struct Link *p);
void func_02013790(u32 p0, u32 p1, u32 p2, u32 p3, u16 p4)
{
    u32 r = func_0203D1A4((struct Link *)p2);

    func_02013528(p0, p1, 0, 0, p2, p3, r, p4);
}

