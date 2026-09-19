/*
 * function: sub_020352DC
 * address:  0x020352DC
 * packet:   pkt_020352DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
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
 *
 * symbols:
 *   unk_021469BC   0x021469BC  data
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   PM_GetBattery  0x0208BF6C  arm
 *   PM_GetACAdapter 0x0208BFAC  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define unk_02FFFC3C (*(volatile u32 *)0x02FFFC3C)

struct IconState {
    u8 pad[0x3f];
    u8 f3f;
};

extern struct IconState *unk_021469BC;

extern int OS_IsRunOnTwl(void);
extern int PM_GetBattery(u32 *out);
extern int PM_GetACAdapter(u16 *out);

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
