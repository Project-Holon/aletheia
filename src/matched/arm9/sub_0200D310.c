/*
 * function: sub_0200D310
 * address:  0x0200D310
 * packet:   pkt_0200D2D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200C7A0   0x0200C7A0  thumb
 *   sub_0200CED4   0x0200CED4  thumb
 *   sub_0201AF80   0x0201AF80  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;

typedef unsigned int   u32;
struct Blk37;
extern u32 sub_0200CED4(struct Blk37 *p, u16 id);
extern int sub_0200C7A0(u32 v);
extern u16 *sub_0201AF80(u32 heap, u16 *countOut);
extern void  func_020307B0(void *p);

int sub_0200D310(void *a0, int a1)
{
    u16 *t = sub_0201AF80(a1, 0);
    u16 i;
    u16 n = 0;

    for (i = 1; i <= 0x289; i++) {
        if (sub_0200CED4(a0, i) != 1) {
            continue;
        }
        if (t[i] == 0x3e7) {
            continue;
        }
        if (sub_0200C7A0(i) == 1) {
            n++;
        }
    }
    func_020307B0(t);
    return n;
}
