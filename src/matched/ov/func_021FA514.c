/*
 * function: WORLDTRADE_INPUT_UpdateCategoryGridAlt
 * address:  0x021FA514
 * packet:   pkt_021FA514
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   WORLDTRADE_SetActorPos  0x021F4FF4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   WORLDTRADE_INPUT_CheckTouch  0x021F9A1C  thumb
 *   WORLDTRADE_INPUT_MapModeToLabel  0x021FA4FC  thumb
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *
 * Cursor input for the eleven-entry mode-6 menu: a 3-column grid of nine
 * entries plus two buttons (9, 10). Leaving a button with up or down
 * returns to the last grid entry (+0x7A) moved to the bottom or top row.
 * A touch (WORLDTRADE_INPUT_CheckTouch) or A selects. Returns the entry, -2 for cancel
 * (B or entry 9), -1 for nothing or a grid entry `enable` marks off.
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 up;
    u8 down;
    u8 left;
    u8 right;
} Link;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    u8 pad0[8];
    u32 cursor;
    u8 padC[0x44 - 0xC];
    int pos;
    u8 pad48[0x7A - 0x48];
    u8 last;
} Obj;

extern const Link tbl_0220339C[];
extern const Cell tbl_02203298[];

extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern unsigned int KEY_GetRepeat(void);
extern void WORLDTRADE_SetActorPos(u32 a, u32 b, u32 c);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int WORLDTRADE_INPUT_CheckTouch(void *p, int mode);
extern int WORLDTRADE_INPUT_MapModeToLabel(int unused, int mode);

int WORLDTRADE_INPUT_UpdateCategoryGridAlt(Obj *p, u8 *enable)
{
    int old = p->pos;
    int r;

    if (old < 9) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_0220339C[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_0220339C[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_0220339C[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_0220339C[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (KEY_GetRepeat() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (KEY_GetRepeat() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[p->pos].x + 0x10) * 8, tbl_02203298[p->pos].y * 8);
        switch (p->pos) {
        case 9:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 0x12);
            break;
        }
    }
    r = WORLDTRADE_INPUT_CheckTouch(p, 6);
    if (r != -1) {
        WORLDTRADE_SetActorPos(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 0x12);
            p->pos = r;
            break;
        }
        r = WORLDTRADE_INPUT_MapModeToLabel((int)p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
        }
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = WORLDTRADE_INPUT_MapModeToLabel((int)p, p->pos);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        WORLDTRADE_SetActorPos(p->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}
