/*
 * file:     net_state_p16.c
 * unit:     yes
 * function: func_020390BC, func_02039160, func_020392B8, func_020392EC
 * address:  0x020390BC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469D0      0x021469D0  data
 *   func_0203D6BC   0x0203D6BC  arm
 *   func_0203D680   0x0203D680  arm
 *   func_0203666C   0x0203666C  arm
 *   func_020365E8   0x020365E8  arm
 *   func_02038DF0   0x02038DF0  arm
 *   lbl_021469D0   0x021469D0  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02039338  0x02039338  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef int           s32_020390BC;

typedef unsigned short u16;

typedef signed int     s32_020392B8;

extern u32 func_0203D6BC(void);
extern u32 func_0203D680(void);
extern void func_0203666C(u8 *p);
extern int func_020365E8(char *p);
extern void func_02038DF0(u8 *p, s32_020390BC i, u32 v, u8 *q, u8 *s);
extern int func_0203D788(void);
extern int func_0203D798(void);
extern int func_02039338(void);
void func_020390BC(void);
int func_02039160(u32 mode);
u32 func_020392B8(void);
int func_020392EC(void);
extern u8  *g_021469D0;
extern u8 *lbl_021469D0;



/*
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
void func_020390BC(void)
{
    s32_020390BC i, j, n;
    u8 *s;

    s = (u8 *)func_0203D6BC();
    if (g_021469D0 == 0)
        return;

    n = func_0203D680();

    for (i = 0; i < n; i++) {
        func_0203666C(g_021469D0 + 0x4C + (i << 4));
        for (j = 0; j < 4; j++) {
            if (func_020365E8((char *)(g_021469D0 + 0x4C + (i << 4))) > 0)
                func_02038DF0(g_021469D0 + 0x4C + (i << 4), i,
                              *(u32 *)(g_021469D0 + 0x18),
                              g_021469D0 + 0x11C + (i << 4), s);
        }
    }
}



int func_02039160(u32 mode)
{
    u8 *p5;
    u8 *p4;
    u8 *g;
    u32 v;
    u16 m;

    p5 = (u8 *)func_0203D788();
    p4 = (u8 *)func_0203D798();
    g = lbl_021469D0;
    if (g == 0)
        return 0;
    v = (u8)(p4[0x65] + 0xff);
    if (v <= 1) {
        if (g[0x1e7] != 0) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x80)))() != -1) {
                if (mode == 0)
                    return 1;
                if (mode == 1)
                    return 1;
            }
        }
        return 0;
    }
    v = (u8)(p4[0x65] + 0xfd);
    if (v <= 1) {
        if (mode < 2 || mode == 0xff) {
            if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() != 0)
                return 1;
        }
        return 0;
    }
    if (func_020392EC() == 0)
        return 0;
    if (((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x70)))() == 0)
        return 0;
    if (mode == (u32)func_02039338())
        return 1;
    if (func_02039338() == 0 || p4[0x64] == 0) {
        m = (u16)((int (*)(void))(*(u32 *)(*(u32 *)(p5 + 0x340) + 0x7c)))();
        if (((1 << mode) & m) != 0)
            return 1;
    } else {
        if (((1 << mode) & *(u16 *)(lbl_021469D0 + 0x100 + 0xe4)) != 0)
            return 1;
    }
    return 0;
}



/*
 * Counts the eight slots whose test function answers non-zero.  The slot
 * number goes in as a `u16` - the `lsl #16` / `lsr #16` pair in the loop is
 * that narrowing - so the callee is declared with a `u16` parameter and the
 * cast costs nothing at the call site.  The counter is in r4 and the index in
 * r5, which is the declaration order below.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392B8.c \
 *       --func func_020392B8 --addr 0x020392B8 --cc 1.1p1 --arm
 */
u32 func_020392B8(void)
{
    u32 count;
    s32_020392B8 i;

    count = 0;
    for (i = 0; i < 8; i++) {
        if (func_02039160((u16)i) != 0)
            count++;
    }
    return count;
}



/*
 * Returns 1 while the state byte at +0x65 is one to four, but only while the
 * global at 0x021469D0 is live; otherwise it dispatches through the vtable at
 * +0x340 of the net state and returns that hook's value (+0x6C slot).
 *
 * The `add r0, r0, #0xff` / `and r0, r0, #0xff` pair is `(u8)(v - 1)`: mwcc
 * writes the -1 as +0xFF because the truncation to u8 makes the two
 * equivalent and 0xFF keeps the `and` mask a plain immediate.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020392EC.c \
 *       --func func_020392EC --addr 0x020392EC --cc 1.1p1 --arm
 */
int func_020392EC(void)
{
    u8 *s = (void *)func_0203D788();
    u8 *p = (void *)func_0203D798();

    if (g_021469D0 != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}
