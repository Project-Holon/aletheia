/*
 * function: func_02169004
 * address:  0x02169004
 * packet:   pkt_ov010_02169004
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02169138  0x02169138  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020143F0  0x020143F0  thumb
 *   func_0200D440  0x0200D440  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201B100  0x0201B100  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008E30  0x02008E30  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200952C  0x0200952C  thumb
 *   func_021862A8  0x021862A8  thumb
 *   func_0200E394  0x0200E394  thumb
 *   func_0200E518  0x0200E518  thumb
 *   func_0200A8A0  0x0200A8A0  thumb
 *   func_0200AB04  0x0200AB04  thumb
 *
 * evidence: 0x0200E518 is an unlabelled ARM9 leaf ("push {r4, r5, r6, r7}",
 * no lr, right after the "pop {r4, pc}" at 0x0200E516) that the prologue
 * sweep misses.  The bl at +0x52 is its only reference in the image; its
 * start is seeded in layout/function_starts.txt, and the callee itself is
 * matched EXACT* (src/matched/arm9/func_0200E518.c), so +0x52 attests as
 * `matched`.
 */

extern void func_02169138(int);
extern int func_02012EBC(int);
extern int func_0201296C(int);
extern void func_020143F0(int);
extern void func_0200D440(int);
extern void *func_02012934(void *p);
extern void func_0201B100(void *, int);
extern int func_02012F2C(int);
extern void func_02008E30(int);
extern int func_02009470(int);
extern void func_0200952C(int);
extern void func_021862A8(int, int, int);
extern void *func_0200E394(void *a0);
extern void func_0200E518(void *);
extern int func_0200A8A0(int);
extern void func_0200AB04(int);

void func_02169004(int a, int b)
{
    int x;
    func_02169138(a);
    x = func_02012EBC(a);
    func_020143F0(func_0201296C(a));
    func_0200D440(x);
    func_0201B100(func_02012934((void *)a), b);
    func_02008E30(func_02012F2C(a));
    func_0200952C(func_02009470(x));
    func_021862A8(a, b, 4);
    func_0200E518(func_0200E394((void *)x));
    func_0200AB04(func_0200A8A0(x));
}
