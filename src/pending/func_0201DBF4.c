/*
 * function: func_0201DBF4
 * address:  0x0201DBF4
 * packet:   pkt_0201DB20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204960C   0x0204960C  arm
 *   func_020495F4   0x020495F4  arm
 *   func_0201DC44   0x0201DC44  thumb
 *
 * The same tail as func_0201DBBC, with two ARM calls in front: the second
 * argument of the first is a three-term sum whose terms are accumulated
 * right to left (the halfword height at 0x76 times a1 added to the word at
 * 0x8C, then the word at 0x80 added to that).  The halfword is bound to a
 * local because it is live across the first call and reused by the second.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201DBF4.c \
 *       --func func_0201DBF4 --addr 0x0201DBF4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0204960C(u32 a0, u32 a1);
extern void func_020495F4(u32 a0, u32 a1, u32 a2);
extern void func_0201DC44(void *a0, u32 a1, u32 a2, int a3, int a4);

void func_0201DBF4(void *a0, int a1, int a2, int a3)
{
    u32 h = *(u16 *)((char *)a0 + 0x76);

    func_0204960C(*(u32 *)((char *)a0 + 0x50),
                  *(u32 *)((char *)a0 + 0x80)
                      + (*(u32 *)((char *)a0 + 0x8C) + a1 * h));
    func_020495F4(*(u32 *)((char *)a0 + 0x50), h,
                  *(u32 *)((char *)a0 + 0x90));
    func_0201DC44(a0, *(u32 *)((char *)a0 + 0x90),
                  *(u16 *)((char *)a0 + 0x7C), a2, a3);
}
