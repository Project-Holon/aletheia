/*
 * function: func_021DBD9C
 * address:  0x021DBD9C
 * packet:   pkt_ov093_021DBD9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_021E896C returns a one-word struct (Word): its return temporary is
 *           the unreferenced third frame word and moves n/k to r6/r7
 *           (an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md);
 *           the enum N keeps n + 1 out of constant folding.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DBE50  0x021DBE50  thumb  ov093
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef enum { N_4 = 4, N_5 = 5 } N;
typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern int func_021C83D4(void *a);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D62C4(void *m, int k);
extern int func_021DBE50(u32 k);
extern int func_021D85C0(void *a, int b);
extern int func_021D5BB0(void *m, u32 n);
extern void *func_021C88A4(void *a, int k, int b);
extern Word func_021E896C(int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DBD9C(int u, void *a, int b)
{
    u8 t;
    u16 k;
    N n;
    void *m;
    u8 *e;
    n = N_4;
    if (b == func_021D775C(4)
        && func_021D775C(0x46) == 0
        && func_021C83D4(a) == 0) {
        t = func_021D775C(3);
        m = func_021C7CF4(a, t);
        if (func_021D62C4(m, 0xd) == 0) {
            k = func_021D775C(0x14);
            if (k != 0 && k != 0xa5 && func_021DBE50(k) == 0
                && func_021D85C0(a, 0x1e) != 0) {
                if (func_021D5BB0(m, 1) != 0) {
                    n = (N)(u8)(n + 1);
                }
                e = func_021C88A4(a, 0xc, b);
                *(u32 *)(e + 4) = 0xd;
                *(Word *)(e + 8) = func_021E896C(n, k);
                e[0xf] = t;
                *(u32 *)e |= 2 << 22;
                func_021C88C8(a, e);
            }
        }
    }
}
