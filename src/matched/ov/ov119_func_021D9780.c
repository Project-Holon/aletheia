/*
 * function: func_021D9780
 * address: 0x021D9780
 * packet: pkt_ov119_021D9780
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021E5B6C 0x021E5B6C thumb ov119
 *   func_021E219C 0x021E219C thumb ov119
 *   d_021E7580 0x021E7580 data a2
 *   d_021E757C 0x021E757C data a2
 */
typedef unsigned short u16;
typedef struct Pt { u16 x; u16 y; } Pt;
extern const Pt d_021E7580;
extern const Pt d_021E757C;
extern int func_0204B404(int a, void *b, int c);
extern int func_020355C4(void);
extern int func_0204B3DC(int a, int b);
extern void *func_021D8FA4(void *p, int a);
extern void func_021E5B6C(void *p, int a, int b);
extern void func_021E219C(void *p, void *a, int b, int c);
void func_021D9780(char *p, int a1, int a2)
{
    Pt t0, t1;
    if (a1 == 0) {
        t0 = d_021E7580;
        func_0204B404(*(int *)(p + 0xf0c), &t0, 1);
    } else {
        t1 = d_021E757C;
        func_0204B404(*(int *)(p + 0xf0c), &t1, 1);
    }
    if (func_020355C4()) {
        func_021E5B6C(p, a1, 0);
        func_0204B3DC(*(int *)(p + 0xf0c), 0);
    } else {
        func_021E5B6C(p, a1, 1);
        func_0204B3DC(*(int *)(p + 0xf0c), 1);
    }
    if (a2 != 0) {
        void *v;

        v = func_021D8FA4(p, *(int *)(p + 0x10a0));
        func_021E219C(p, v, *(int *)(p + 0x10a0), 1);
    }
}
