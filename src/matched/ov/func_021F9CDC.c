/*
 * function: func_021F9CDC
 * address:  0x021F9CDC
 * packet:   pkt_021F9CDC
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
 *   func_021F4FF4  0x021F4FF4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_021F9A1C  0x021F9A1C  thumb
 *   func_021F9CB0  0x021F9CB0  thumb
 *   tbl_02203260   0x02203260  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 *   tbl_02203324   0x02203324  data  a4
 *
 * Cursor input for the five-entry mode-5 menu: the d-pad walks the link
 * table (entry 3 is the fixed bottom button, leaving it restores the last
 * grid entry from +0x7A), a touch (func_021F9A1C) or A selects. Returns
 * the selected entry, -2 for cancel (B or the button), -1 for nothing or
 * for an entry the per-layout enable row marks unavailable at `base`.
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
    u8 padC[0x38 - 0xC];
    s16 layout;
    u8 pad3A[0x44 - 0x3A];
    int pos;
    u8 pad48[0x7A - 0x48];
    u8 last;
} Obj;

extern const Link tbl_02203260[];
extern const Cell tbl_022032C6[];
extern u8 *const tbl_02203324[];

extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern unsigned int KEY_GetRepeat(void);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int func_021F9A1C(void *p, int mode);
extern int func_021F9CB0(Obj *p, int v);

int func_021F9CDC(Obj *p, int base)
{
    int old = p->pos;
    int r;

    if (old < 3) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_02203260[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_02203260[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_02203260[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_02203260[p->pos].right;
    }
    if (old == 3 && p->pos < 3) {
        p->pos = p->last;
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->pos == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
        } else {
            func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 4);
        }
    }
    r = func_021F9A1C(p, 5);
    if (r != -1) {
        if (r == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
        } else {
            p->pos = r;
            func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
            CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 4);
        }
        r = func_021F9CB0(p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
            if (func_020355C4() == 0) {
                CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
            }
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = func_021F9CB0(p, p->pos);
        if (r == -1) {
            return r;
        }
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}
