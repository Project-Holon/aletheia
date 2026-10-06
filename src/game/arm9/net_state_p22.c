/*
 * file:     net_state_p22.c
 * unit:     yes
 * function: func_020392B8, func_020392EC
 * address:  0x020392B8
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
 *   func_02039160  0x02039160  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   g_021469D0     0x021469D0  data
 */
typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char u8;

extern u32 func_02039160(u16 slot);
extern void *func_0203D788(void);
extern void *func_0203D798(void);
u32 func_020392B8(void);
int func_020392EC(void);
extern u32 g_021469D0;


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
    s32 i;

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
    u8 *s = func_0203D788();
    u8 *p = func_0203D798();

    if (g_021469D0 != 0 && (u8)(p[0x65] + 0xFF) <= 3)
        return 1;

    return (*(int (**)(void))(*(u32 *)(s + 0x340) + 0x6C))();
}
