/*
 * function: VIEWER_MAIN_VBlank
 * address:  0x021C581C
 * packet:   pkt_ov111_021C581C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_MAIN_UpdateBrightness  0x021C5B34  thumb  ov111
 *   VIEWER_MAIN_InitBrightness  0x021C4F80  thumb  ov111
 *   func_02040618  0x02040618  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x32CA];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 dirty : 1;
    u8 pad32CB[0x32D6 - 0x32CB];
    u8 shake;
} Work;

extern void VIEWER_MAIN_UpdateBrightness(Work *p);
extern void VIEWER_MAIN_InitBrightness(Work *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);

void VIEWER_MAIN_VBlank(void *task, Work *p)
{
    int ofs;

    VIEWER_MAIN_UpdateBrightness(p);
    ofs = -(p->shake / 2);
    func_02040618(5, 0, ofs);
    func_02040618(5, 3, ofs);
    func_02040618(3, 0, ofs);
    func_02040618(3, 3, ofs);
    if (p->dirty) {
        VIEWER_MAIN_InitBrightness(p);
    }
    BG_SYS_Update();
    CLACT_VBlankSystem();
}
