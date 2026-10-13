/*
 * file:     unit_02072A08.c
 * unit:     yes
 * function: func_02072A08, func_02072A28, func_02072A44
 * address:  0x02072A08
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
 *   g_0214DEC0  0x0214DEC0  data
 *   func_0207292C    0x0207292C  arm
 *   g_0214DECC       0x0214DECC  data
 */
typedef unsigned int u32;

struct WaveOutState {
    u32 flags;
    u32 usedSlotMask;
    u32 lockedChannelMask;
};

typedef struct {
    u32 channelNo;
    u32 baseRate;
    u32 active;
    u32 started;
    u32 commandTag;
} WaveOutSlot;

extern int func_0207292C(int channelMask);
void func_02072A08(u32 slotNo);
void func_02072A28(void);
WaveOutSlot *func_02072A44(u32 slotNo);
extern struct WaveOutState g_0214DEC0;
extern WaveOutSlot g_0214DECC[];


/*
 * Frees one channel of the 8-bit bitmap at g_0214DEC0+4, the matching release
 * for matched func_020729C0's allocate.
 *
 * The parameter is an INDEX, not a mask: `mov r2,#1 / mvn r0, r2, lsl r0` at
 * 0x02072A0C shows the shift happening INSIDE the complement, i.e. `~(1u << b)`
 * as one expression.  Spelling it `u32 m = 1u << b; ... &= ~m;` splits the
 * complement out and costs an extra instruction.  Compare func_020729A4, whose
 * `mvn r0, r0` on the bare parameter proves IT takes a mask.
 *
 * NO PIN NEEDED: EXACT under both dsi/1.1p1 and ../2.0/sp2 (the base pool word
 * is live at exactly one point, so there is nothing for 1.1p1 to hoist).
 * Recorded because its cluster neighbours DO need ../2.0/sp2; see
 * docs/families/cluster_020726D0.h.
 *
 * This file was parked in src/pending at MATCH only because the `symbols:`
 * block was missing its g_0214DEC0 line, so the single ABS32 site had no
 * address to resolve; the C was always byte-correct.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02072A08.c \
 *       --func func_02072A08 --addr 0x02072A08 --cc 1.1p1 --arm
 */
void func_02072A08(u32 slotNo)
{
    g_0214DEC0.usedSlotMask &= ~(1U << slotNo);
}


void func_02072A28(void)
{
    struct WaveOutState *state = (struct WaveOutState *)0x0214DEC0;
    state->lockedChannelMask = 0;
    state->flags = 0;
    state->usedSlotMask = 0;
}


/*
 * Claims one bit with func_0207292C and, on success, seeds the matching slot of
 * the stride-0x14 table and clears its +8 word; the slot address is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072A44.c \
 *       --func func_02072A44 --addr 0x02072A44 --cc 1.1p1 --arm
 */
WaveOutSlot *func_02072A44(u32 slotNo)
{
    WaveOutSlot *slot;

    if (func_0207292C(1 << slotNo) == 0) {
        return 0;
    }
    slot = &g_0214DECC[slotNo];
    slot->channelNo = slotNo;
    slot->active = 0;
    return slot;
}
