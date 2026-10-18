/*
 * function: CURSOR_MOVE_PollInput
 * address:  0x02025D2C
 * packet:   pkt_02025D2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CURSOR_MOVE_PollTouch  0x02025EA4  thumb
 *   CURSOR_MOVE_HandlePendingInput  0x02025FC8  thumb
 *   CURSOR_MOVE_GetNeighbour  0x02025F60  thumb
 *   CURSOR_MOVE_MoveCursor  0x02026010  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   UI_SetInputMode  0x020355D8  arm
 *
 * field_sound_system.c.  The primary-pad poll: with no pending selection, read the four direction bits of the button word and hand the matching entry to CURSOR_MOVE_MoveCursor; B answers the current slot and A answers -2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CURSOR_MOVE_PollInput.c \
 *       --func CURSOR_MOVE_PollInput --addr 0x02025D2C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Sound {
    const u8 *entries;
    u32 field_4;
    u32 field_8;
    u8  field_C;
    u8  field_D;
    u8  field_E;
    u8  field_F;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
};

extern int  CURSOR_MOVE_PollTouch(struct Sound *obj, int *out);
extern int CURSOR_MOVE_HandlePendingInput(u8 *a0);
extern u32  CURSOR_MOVE_GetNeighbour(const u8 *ptr, u32 idx, u32 type);
extern int CURSOR_MOVE_MoveCursor(struct Sound *obj, u32 dir, int sel);
extern u32  KEY_GetTrg(void);

extern void UI_SetInputMode(u8 v);

int CURSOR_MOVE_PollInput(struct Sound *obj)
{
    int dir;
    int res;
    u32 sel;

    if (CURSOR_MOVE_PollTouch(obj, &res) == 1) {
        return res;
    }
    if (obj->field_4 == 0 && obj->field_C == 1) {
        return CURSOR_MOVE_HandlePendingInput((u8 *)obj);
    }

    if (KEY_GetTrg() & 0x40) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->field_D, 0);
        dir = 0;
    } else if (KEY_GetTrg() & 0x80) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->field_D, 1);
        dir = 1;
    } else if (KEY_GetTrg() & 0x20) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->field_D, 2);
        dir = 2;
    } else if (KEY_GetTrg() & 0x10) {
        sel = CURSOR_MOVE_GetNeighbour(obj->entries, obj->field_D, 3);
        dir = 3;
    } else {
        sel = 0xff;
    }

    if (sel != 0xff) {
        return CURSOR_MOVE_MoveCursor(obj, dir, sel);
    }
    if (KEY_GetTrg() & 1) {
        UI_SetInputMode(0);
        return obj->field_D;
    }
    if (KEY_GetTrg() & 2) {
        dir = 0;
        UI_SetInputMode(0);
        return dir - 2;
    }
    return -1;
}

/*
 * Note: CURSOR_MOVE_MoveCursor takes three arguments; the third is the slot value
 * CURSOR_MOVE_GetNeighbour returned, which reads at the call site as a leftover r2 but
 * is a real argument -- without it the `adds r2, r0, #0` after the call is
 * dead-code eliminated and the function comes out two bytes short.
 */
