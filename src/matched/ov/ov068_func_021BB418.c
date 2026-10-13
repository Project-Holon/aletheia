/*
 * function: OPTION_MENU_StateDiscardPrompt
 * address:  0x021BB418
 * packet:   pkt_ov068_021BB418
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   OPTION_MENU_GetListSettings  0x021BA9E0  thumb  ov068
 *   OPTION_MENU_GetTextWait  0x021BB0D0  thumb  ov068
 *   OPTION_MENU_PrintDiscardPrompt  0x021BAE90  thumb  ov068
 *   func_02040588  0x02040588  arm
 *   OPTION_MENU_GetMessageBoxAnswer  0x021BAEBC  thumb  ov068
 *   OPTION_MENU_SetRunnerCallback  0x021BB138  thumb  ov068
 *   OPTION_MENU_StateKeepSaved  0x021BB4A4  thumb  ov068
 *   OPTION_MENU_StateApply  0x021BB4D4  thumb  ov068
 *   OPTION_MENU_UpdateMessageBox  0x021BAE28  thumb  ov068
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Blk;

extern void OPTION_MENU_GetListSettings(u8 *p, Blk *out);
extern u32  OPTION_MENU_GetTextWait(Blk *b);
extern void OPTION_MENU_PrintDiscardPrompt(void *p, u32 value);
extern void func_02040588(unsigned char which, unsigned char enable);
extern u16  OPTION_MENU_GetMessageBoxAnswer(u8 *p);
extern void OPTION_MENU_SetRunnerCallback(void *p, int v);
extern void OPTION_MENU_StateKeepSaved(void *a, u32 b, u8 *p);
extern void OPTION_MENU_StateApply(void *a, u32 b, u8 *p);
extern void OPTION_MENU_UpdateMessageBox(u8 *p);

void OPTION_MENU_StateDiscardPrompt(void *a0, u32 *st, u8 *base)
{
    Blk b;
    u16 r;

    switch (*st) {
    case 0:
        OPTION_MENU_GetListSettings(base + 0x148, &b);
        OPTION_MENU_PrintDiscardPrompt(base + 0x1d8, OPTION_MENU_GetTextWait(&b));
        func_02040588(4, 0);
        *st = 1;
        break;
    case 1:
        r = OPTION_MENU_GetMessageBoxAnswer(base + 0x1d8);
        switch (r) {
        case 1:
            *st = 2;
            break;
        case 2:
            *st = 3;
            break;
        }
        break;
    case 2:
        OPTION_MENU_SetRunnerCallback(a0, (int)OPTION_MENU_StateApply);
        break;
    case 3:
        OPTION_MENU_SetRunnerCallback(a0, (int)OPTION_MENU_StateKeepSaved);
        break;
    }
    OPTION_MENU_UpdateMessageBox(base + 0x1d8);
}
