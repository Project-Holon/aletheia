/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: UI_GetInputMode, UI_SetInputMode, UI_ResetFrameCounterOf, UI_SetFrameRateOf,
 *           UI_GetFrameRateOf, UI_SetFrameRate, UI_GetFrameRate, UI_ResetFrameCounter
 * address:  0x020355C4
 * packet:   pkt_020353B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState     0x021469BC  data
 *
 * The accessor block of the singleton reached through the pointer at
 * 0x021469BC.  None of these eight functions saves lr, so disasm.py
 * labels none of them; they are visible only by sweeping addresses
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The block is written as instance accessors plus global wrappers that
 * fetch the singleton and forward:
 *
 *   UI_GetInputMode  read the u8 at +0x3c of the singleton.
 *   UI_SetInputMode  write it.
 *   UI_ResetFrameCounterOf  clear the u8 at +0x3e of a caller-supplied instance.
 *   UI_SetFrameRateOf  write the u8 at +0x3d.  Takes an instance pointer for
 *                 symmetry with UI_GetFrameRateOf but ignores it and goes
 *                 through the singleton anyway; the reload of the global
 *                 over r0 is the whole tell.
 *   UI_GetFrameRateOf  read the u8 at +0x3d of a caller-supplied instance.
 *   UI_SetFrameRate  global wrapper over UI_SetFrameRateOf.
 *   UI_GetFrameRate  global wrapper over UI_GetFrameRateOf.
 *   UI_ResetFrameCounter  global wrapper over UI_ResetFrameCounterOf.
 *
 * The range deliberately stops before UI_ChangeFrameRate, the one labelled
 * function of this file: its calls to 0x02036390 and 0x02035E54 have no
 * witness outside the file, so including it caps the whole unit at MATCH.
 * It is parked in src/pending/UI_ChangeFrameRate.c.
 *
 * Every wrapper is a pool word and a `bx ip`, never a displacement
 * branch, because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020355C4.c \
 *       --addr 0x020355C4 --arm
 */

typedef unsigned char u8;

struct Sys {
    u8 pad_00[0x3c];
    u8 unk_3c;
    u8 unk_3d;
    u8 unk_3e;
};

extern struct Sys *gUiState;

u8 UI_GetInputMode(void)
{
    return gUiState->unk_3c;
}

void UI_SetInputMode(u8 v)
{
    gUiState->unk_3c = v;
}

void UI_ResetFrameCounterOf(struct Sys *p)
{
    p->unk_3e = 0;
}

void UI_SetFrameRateOf(struct Sys *unused, u8 v)
{
    gUiState->unk_3d = v;
}

u8 UI_GetFrameRateOf(struct Sys *p)
{
    return p->unk_3d;
}

void UI_SetFrameRate(u8 v)
{
    UI_SetFrameRateOf(gUiState, v);
}

u8 UI_GetFrameRate(void)
{
    return UI_GetFrameRateOf(gUiState);
}

void UI_ResetFrameCounter(void)
{
    UI_ResetFrameCounterOf(gUiState);
}
