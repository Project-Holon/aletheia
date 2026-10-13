/*
 * function: UI_ChangeFrameRate
 * address:  0x02035660
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
 *   UI_SetFrameRateOf   0x020355F8  arm
 *   KEY_ClearFrameRateWork   0x02036390  arm
 *   TOUCHPANEL_ClearFrameRateWork   0x02035E54  arm
 *
 * The one labelled function of the 0x021469BC accessor block (the other
 * eight are in src/matched/unit_020355C4.c): write the u8 at +0x3d of the
 * singleton, then run the two follow-up passes at 0x02036390 and
 * 0x02035E54 over it.
 *
 * Previously parked at MATCH: 0x02036390 and 0x02035E54 are called from
 * nowhere else in the image, so neither PC24 site had an outside witness of
 * any class and --suggest-split could not help.  Both now close on the
 * `matched` class (src/matched/KEY_ClearFrameRateWork.c and src/matched/TOUCHPANEL_ClearFrameRateWork.c);
 * nothing in this file had to change.
 *
 * The global is re-read between the three calls: all three callees are
 * externs that may store to it, so the load cannot be hoisted, and
 * holding &gUiState in r4 across the calls is what that costs.
 * UI_SetFrameRateOf ignores its first argument (see the unit file); the call
 * still passes the singleton.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/UI_ChangeFrameRate.c \
 *       --func UI_ChangeFrameRate --addr 0x02035660 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

struct Sys {
    u8 pad_00[0x3c];
    u8 unk_3c;
    u8 unk_3d;
    u8 unk_3e;
};

extern struct Sys *gUiState;

extern void UI_SetFrameRateOf(struct Sys *unused, u8 v);
extern void KEY_ClearFrameRateWork(struct Sys *p);
extern void TOUCHPANEL_ClearFrameRateWork(struct Sys *p);

void UI_ChangeFrameRate(u8 v)
{
    UI_SetFrameRateOf(gUiState, v);
    KEY_ClearFrameRateWork(gUiState);
    TOUCHPANEL_ClearFrameRateWork(gUiState);
}
