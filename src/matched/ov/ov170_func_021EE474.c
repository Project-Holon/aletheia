/*
 * function: BOX2_UI_UpdateCursorInputA
 * address:  0x021EE474
 * packet:   pkt_ov170_021EE474
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_UI_UpdateCursor 0x021EE408 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 */

typedef unsigned int u32;

struct WinMgr;
typedef unsigned char  u8;
struct Sound;
extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);
extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_UI_UpdateCursor(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void UI_SetInputMode(u8 v);

#define WORK(p) (*(char **)((p) + 0x2C))

unsigned BOX2_UI_UpdateCursorInputA(char *p)
{
    unsigned char sel = CURSOR_MOVE_GetCurrent(*(void **)(WORK(p) + 0x70));
    unsigned r = CURSOR_MOVE_PollRepeatInput(*(void **)(WORK(p) + 0x70));

    if (BOX2_UI_IsListOpen(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 8 && r <= 12) {
            CURSOR_MOVE_SetCurrent(*(void **)(WORK(p) + 0x70), sel);
            BOX2_UI_UpdateCursor(p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            UI_SetInputMode(0);
            return 6;
        }
        if (r == 6) {
            UI_SetInputMode(1);
            return 6;
        }
        if (r == 7) {
            CURSOR_MOVE_SetCurrent(*(void **)(WORK(p) + 0x70), sel);
            return 7;
        }
    } else if (r - 6 <= 1) {
        CURSOR_MOVE_SetCurrent(*(void **)(WORK(p) + 0x70), sel);
        BOX2_UI_UpdateCursor(p, sel);
        return -1;
    }
    return r;
}
