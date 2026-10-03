/*
 * function: func_020390BC
 * address:  0x020390BC
 * packet:   pkt_020390BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0      0x021469D0  data
 *   func_0203D6BC   0x0203D6BC  arm
 *   func_0203D680   0x0203D680  arm
 *   func_0203666C   0x0203666C  arm
 *   func_020365E8   0x020365E8  arm
 *   func_02038DF0   0x02038DF0  arm
 *
 * n slots of 0x10 bytes at g+0x4c, each prepared by func_0203666C and then
 * offered to func_02038DF0 up to four times, with the record at g+0x11c and
 * the frame returned by func_0203D6BC handed to each call.
 *
 * Three spellings are load-bearing.  The global is re-read through
 * g_021469D0 itself in every statement (mwcc keeps its address in `sb` and
 * reloads the value, because the calls may store through it).  There is no
 * explicit `if (n <= 0) return;`: with `n = func_0203D680();` followed
 * straight by `for (i = 0; i < n; i++)` the loop's pre-test folds to
 * `cmp r7, #0` / `pople` because i is known zero, and the loop-exit
 * epilogue tail-merges with the function's own.  And the inner body is
 * `if (test > 0) call(...)` rather than `if (test <= 0) break;`, because
 * the original's branch lands on the inner increment (the continue path).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020390BC.c \
 *       --func func_020390BC --addr 0x020390BC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

extern u8  *g_021469D0;

extern u8  *func_0203D6BC(void);
extern u32 func_0203D680(void);
extern void func_0203666C(u8 *p);
extern int  func_020365E8(u8 *p);
extern void func_02038DF0(u8 *p, s32 i, u32 v, u8 *q, u8 *s);

void func_020390BC(void)
{
    s32 i, j, n;
    u8 *s;

    s = func_0203D6BC();
    if (g_021469D0 == 0)
        return;

    n = func_0203D680();

    for (i = 0; i < n; i++) {
        func_0203666C(g_021469D0 + 0x4C + (i << 4));
        for (j = 0; j < 4; j++) {
            if (func_020365E8(g_021469D0 + 0x4C + (i << 4)) > 0)
                func_02038DF0(g_021469D0 + 0x4C + (i << 4), i,
                              *(u32 *)(g_021469D0 + 0x18),
                              g_021469D0 + 0x11C + (i << 4), s);
        }
    }
}
