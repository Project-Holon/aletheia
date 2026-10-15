/*
 * function: BOX2_UI_UpdateCursorInputF
 * address:  0x021EEB40
 * packet:   pkt_ov170_021EEB40
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of src/matched/ov170_func_021EE8A8.c.  The image tests the first
 * range as subs/cmp #2, which only the `r - 9 <= 2` spelling gives; the
 * two-compare form r >= 9 && r <= 11 keeps two branches.
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_UI_UpdateCursor 0x021EE408 thumb
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 */

typedef unsigned int u32;

struct WinMgr;
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern int func_02025DE8(struct Sound *obj);
extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);
extern void BOX2_UI_UpdateCursor(char *p, int v);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);

#define WORK(p) (*(char **)((p) + 0x2C))

unsigned BOX2_UI_UpdateCursorInputF(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (BOX2_UI_IsListOpen(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 9 <= 2) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            BOX2_UI_UpdateCursor(p, sel);
            return -1;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        BOX2_UI_UpdateCursor(p, sel);
        return -1;
    }
    return r;
}
