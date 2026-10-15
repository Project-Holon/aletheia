/*
 * function: ZUKAN_DETAIL_INFO_Main
 * address: 0x021BEB18
 * packet: pkt_ov208_021BEB18
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are BG_SYS_FillScrollArea(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_COMMON_GetCursorValue 0x021BC3B8 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled 0x021BDC48 thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq 0x021BDC14 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   ZUKAN_DETAIL_INFO_CreateLanguageButtons 0x021BF308 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_DETAIL_GRAPHIC_Reset3dState 0x021BCF4C thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_DETAIL_INFO_GetPanelParams 0x021BF4FC thumb
 *   ZUKAN_DETAIL_COMMON_GetGraphics 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   ZUKAN_DETAIL_INFO_ResetButtons 0x021BF4C4 thumb
 *   ZUKAN_DETAIL_INFO_LoadHighlightPalettes 0x021BF5B8 thumb
 *   ZUKAN_DETAIL_INFO_StartHighlightBlink 0x021BF620 thumb
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled 0x021BDAE8 thumb
 *   ZUKAN_DETAIL_INFO_HandleTouchLanguageButton 0x021BEFA0 thumb
 *   ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect 0x021BF088 thumb
 *   ZUKAN_DETAIL_INFO_UpdateButtonPressAnim 0x021BF450 thumb
 *   func_021BA374 0x021BA374 thumb ov206
 *   ZUKAN_DETAIL_INFO_UpdateHighlightBlink 0x021BF664 thumb
 *   func_021BC46C 0x021BC46C thumb
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Blend;
struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    char pad98[0x110 - 0x98];
    void *font; void *msg0; void *msg1; void *msg2;
};
struct Ov208Heap { u16 heap; };
struct Blk37;
struct GfFont;
struct MsgBank;
struct S;
extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);
extern int ZUKAN_DETAIL_COMMON_GetCursorValue(char *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_FreeSlot(u8 a);
extern int func_021BDAD0(void *s);
extern u16 func_021BC3BC(int *ctx);
extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);
extern void func_021BDAD4(void *s, int a);
extern void func_021BDBB8(void *s, u32 a);
extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 a);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *ctx);
extern int GAME_DATA_CheckSaveFlag(int a, int b);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(char *p, int b);
extern int func_021BE840(void *s);
extern void func_021BE82C(void *s, int a);
extern void func_021BE844(void *s);
extern void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, int key);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern int ZUKAN_DETAIL_COMMON_GetDisplay(int *ctx);
extern int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);
extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);
extern void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, int key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
extern int ZUKAN_DETAIL_COMMON_GetGraphics(int *ctx);
extern void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
extern void func_021BA7C8(void *p);
extern void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, int c, int *tbl);
extern void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, int *ctx);
extern void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, int *p, int *ctx);
extern void func_021BC4D8(struct Ov208Blend *b);
extern int func_021BC4C8(struct Ov208Blend *b);
extern void func_021BDBA0(void *s);
extern void func_021BC4E4(struct Ov208Blend *b);
extern void func_021BE854(void *s);
extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(char *p, int v);
extern int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *a0, struct S *st, int *obj);
extern int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first, char *p, int key);
extern void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, int key);
extern void func_021BA374(char *p);
extern void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);
int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    void *icon = (void *)ZUKAN_DETAIL_COMMON_GetCursorValue((char *)ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = GF_FONT_Create(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_FillScrollArea(i, 0, 0);
                BG_SYS_FillScrollArea(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 0);
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scn, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        ZUKAN_DETAIL_INFO_CreateLanguageButtons((u16 *)h, (char *)p, (int)ctx);
        t = (int)ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource(ctx));
        v40 = ZUKAN_DETAIL_GRAPHIC_Reset3dState((char *)ZUKAN_DETAIL_COMMON_GetDisplay(ctx));
        v44 = ZUKAN_SAVE_GetViewMode((void *)t);
        ZUKAN_DETAIL_INFO_GetPanelParams((const u16 *)h, (u8 *)p, (int)ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, ZUKAN_DETAIL_COMMON_GetGraphics(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        func_021BA7C8(p->f8);
        ZUKAN_DETAIL_INFO_ResetButtons((int)h, (char *)p, (int)ctx, (int *)tbl);
        ZUKAN_DETAIL_INFO_LoadHighlightPalettes((u16 *)h, (u8 *)p, ctx);
        ZUKAN_DETAIL_INFO_StartHighlightBlink(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scn, 0);
        } else if (p->f18 != 0) {
            if (ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(h, (struct S *)p, ctx) == 0)
                ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(h, (char *)p, (int)ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(h, (char *)p, (int)ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            ZUKAN_DETAIL_INFO_UpdateHighlightBlink(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}
