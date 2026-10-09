/*
 * file:     net_state_p66.c
 * unit:     yes
 * function: func_0203DA68, func_0203DA7C
 * address:  0x0203DA68
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
 *   d_021469F0 0x021469F0 data a4
 *   g_021469F0     0x021469F0  data
 *   func_0203DC04  0x0203DC04  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x84];
    u32 unk_84;
    u32 unk_88;
    u32 unk_8c;
};

extern void func_0203DC04(void);
void func_0203DA68(unsigned int value);
void *func_0203DA7C(void *a0, void *a1, void *a2);
extern unsigned char *d_021469F0;
extern struct Ctx *g_021469F0;

/*
 * Stores a word into the singleton at +0x74.
 */
void func_0203DA68(unsigned int value)
{
    *(unsigned int *)(d_021469F0 + 0x74) = value;
}


/*
 * Install the three wireless callbacks and hand back the state machine that
 * drives them.  With no live context (0x021469F0 null) the function returns
 * its first argument untouched - the image leaves r0 alone on that path, so
 * the early exit is `bxeq lr`, not a `moveq r0, #0`.  Otherwise each non-null
 * argument is stored at +0x84, +0x88 and +0x8C of the context, and the
 * function returns func_0203DC04.
 *
 * The context is re-read from the global for the second and third stores
 * (`ldrne r0, [pc, ...]; ldrne r0, [r0]`), because the first store could
 * alias the global: the source spells them g_021469F0->unk_88 rather than
 * reusing a cached local.  The first store uses the value already in r3.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DA7C.c \
 *       --func func_0203DA7C --addr 0x0203DA7C --cc 1.1p1 --arm
 */
void *func_0203DA7C(void *a0, void *a1, void *a2)
{
    struct Ctx *p = g_021469F0;

    if (p == 0)
        return a0;
    if (a0 != 0)
        p->unk_84 = (u32)a0;
    if (a1 != 0)
        g_021469F0->unk_88 = (u32)a1;
    if (a2 != 0)
        g_021469F0->unk_8c = (u32)a2;
    return func_0203DC04;
}
