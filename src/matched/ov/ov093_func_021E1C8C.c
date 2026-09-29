/*
 * function: func_021E1C8C
 * address:  0x021E1C8C
 * packet:   pkt_ov093_021E1C8C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C804C  0x021C804C  thumb  ov093
 *   func_021D8340  0x021D8340  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *
 * The 12-byte tail (movs r1,#3; str r1,[r0]; ldr r0,[pc]; bx lr; .word) is an
 * unlabelled follower stub, not part of this function.
 * Lever: q = func_021C7CF4(...) bound to a local before `ok = 0` keeps the
 * `movs r4, #0` between the argument setup and the func_021D5BB0 call.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D5BB0(void *q, u32 n);
extern int func_021C804C(int a, int b, u32 *out);
extern u32 func_021D8340(u32 *m);
extern int func_0201C314(void);
extern int func_021D76BC(int a, int b);
extern void func_021C8838(void *p, int a, int b);

void func_021E1C8C(int u, int a, int b)
{
    u32 buf;
    u8 k;
    int ok;
    void *q;

    if (b == func_021D775C(3)) {
        k = func_021D775C(4);
        q = func_021C7CF4(a, k);
        ok = 0;
        if (func_021D5BB0(q, 3) == 0) {
            if (func_021C804C(a, k, &buf) != 0 && func_021D8340(&buf) != 0 && func_0201C314() != 0)
                ok = 1;
        }
        if (ok == 0) {
            if (func_021D8340(&buf) == 0 || func_0201C314() == 0) {
                if (func_021D76BC(0x40, 1) != 0)
                    func_021C8838((void *)func_021D775C(0x3f), 1, 0x47);
            }
        }
    }
}
