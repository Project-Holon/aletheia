/*
 * file:     ui_p06.c
 * unit:     yes
 * function: func_0203524C, func_02035268, func_02035284, func_020352AC, func_020352DC
 * address:  0x0203524C
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
 *   unk_021469BC   0x021469BC  data
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PM_GetBattery  0x0208BF6C  arm
 *   PM_GetACAdapter 0x0208BFAC  arm
 */
typedef unsigned char u8;

typedef void (*UiCb)(void *);

typedef int  (*UiPred)(void *);

struct UiCtx {
    u8      pad00[0x10];
    UiCb    on_10;
    UiCb    on_14;
    UiCb    on_18;
    UiCb    on_1c;
    UiCb    on_20;
    UiPred  on_24;
    void   *arg_28;
    void   *arg_2c;
    void   *arg_30;
    void   *arg_34;
    u8      always;
    u8      pad39[8];
    u8      armed;
};

typedef unsigned short u16;

typedef unsigned int   u32;

struct IconState {
    u8 pad[0x3f];
    u8 f3f;
};

extern int OS_IsRunOnTwl(void);
extern int PM_GetBattery(u32 *out);
extern int PM_GetACAdapter(u16 *out);
void sub_020352DC(void);
extern struct IconState *unk_021469BC;


/*
 * One of the five optional callback slots the UI context carries: run the
 * hook at +0x14 with its own argument at +0x28 if one is installed, and do
 * nothing otherwise.  The argument is loaded only on the taken path, after
 * the null test, so the null check cannot be folded into the call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203524C.c \n *       --func sub_0203524C --addr 0x0203524C --cc 1.1p1 --arm
 */
void sub_0203524C(struct UiCtx *p)
{
    if (p->on_14 != 0) {
        p->on_14(p->arg_28);
    }
}


/*
 * The +0x10 callback slot, same shape as sub_0203524C and sharing its
 * argument word at +0x28.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035268.c \n *       --func sub_02035268 --addr 0x02035268 --cc 1.1p1 --arm
 */
void sub_02035268(struct UiCtx *p)
{
    if (p->on_10 != 0) {
        p->on_10(p->arg_28);
    }
}


/*
 * Arm the context: run the +0x1c hook with the +0x2c argument and set the
 * armed flag at +0x41.  sub_020352AC is the disarming half.  The flag is set
 * only when a hook was actually installed, so it stays inside the guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02035284.c \n *       --func sub_02035284 --addr 0x02035284 --cc 1.1p1 --arm
 */
void sub_02035284(struct UiCtx *p)
{
    if (p->on_1c != 0) {
        p->on_1c(p->arg_2c);
        p->armed = 1;
    }
}


/*
 * The disarming half of sub_02035284: run the +0x18 hook with the same
 * +0x2c argument and clear the armed flag, but only if the context was armed
 * in the first place.
 *
 * The two conditions are one `&&`, not a nested pair of `if`s: they share a
 * single `popeq` epilogue, which the chain-of-returns spelling would split
 * into two (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020352AC.c \n *       --func sub_020352AC --addr 0x020352AC --cc 1.1p1 --arm
 */
void sub_020352AC(struct UiCtx *p)
{
    if (p->on_18 != 0 && p->armed != 0) {
        p->on_18(p->arg_2c);
        p->armed = 0;
    }
}


#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)


/*
 * BLOCKED on two relocation sites: all 180 concrete bytes are correct,
 * 2 of 4 sites resolve, and the two that do not are
 *
 *   +0044 PC24 PM_GetACAdapter  0x0208BFAC  -> no witness outside range
 *   +0068 PC24 PM_GetBattery    0x0208BF6C  -> no witness outside range
 *
 * Each is called exactly once in the whole image and that call is here,
 * so the `label` class refuses them (every witness would be in-range),
 * and no cut exists inside a single function section, so
 * --suggest-split offers nothing.  Both are plain TwlSDK libspi
 * entry points (pm.o), so they graduate the moment any *other* caller
 * turns up, or when the libspi block around 0x0208BF00 is itself
 * matched.  Nothing about the C can change this.
 *
 * Ten-second power poll: the shared tick word at 0x02FFFC3C is read once
 * and the body only runs on the tick where `tick % 600` is 1, i.e. one
 * tick past each ten-second roll-over.  The modulus is the compiler's
 * own unsigned magic-multiply for the constant 600 (umull by 0x1B4E81B5,
 * high word >> 6, umull by 600, subtract), so the value must be an
 * unsigned 32-bit read -- declaring it signed drops the umull pair.
 *
 * On a DSi the AC adapter state wins and is written straight through;
 * on a DS the battery flag is read as a 32-bit word and is mapped to 5
 * (no charge) or 1 (charging).  Both arms of the second branch are short
 * enough that mwcc predicates them instead of branching, which is why
 * the global pointer is re-loaded in each arm rather than hoisted.
 */
void sub_020352DC(void)
{
    u16 ac;
    u32 bat;

    if (unk_02FFFC3C % 600 != 1)
        return;

    if (OS_IsRunOnTwl() != 0) {
        if (PM_GetACAdapter(&ac) == 0)
            unk_021469BC->f3f = ac;
        return;
    }

    if (PM_GetBattery(&bat) != 0)
        return;
    if (bat == 0)
        unk_021469BC->f3f = 5;
    else
        unk_021469BC->f3f = 1;
}
