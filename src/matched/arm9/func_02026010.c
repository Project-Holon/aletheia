/*
 * function: CURSOR_MOVE_MoveCursor
 * address:  0x02026010
 * packet:   pkt_02026010
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * field_sound_system.c.  Moves the cursor from the current entry to the
 * one CURSOR_MOVE_GetNeighbour names for `dir`, skipping entries whose bit is clear
 * in the object's 32-bit-word skip bitmap, then notifies the owner.
 *
 * symbols:
 *   UI_SetInputMode  0x020355D8  arm
 *   CURSOR_MOVE_GetNeighbour  0x02025F60  thumb
 *   CURSOR_MOVE_IsWrapNeighbour  0x02026178  thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Entry {
    u32 a;
    u32 b;
    u32 c;
};

struct Owner;

struct Vtbl {
    void (*f0)(void);
    void (*f4)(void);
    void (*f8)(void *ctx, u32 now, u32 prev);
};

struct Sound {
    struct Entry *entries;
    u32 field_4;
    u32 field_8;
    u8  field_C;
    u8  field_D;
    u8  field_E;
    u8  field_F;
    u32 bits[2];
    struct Vtbl *vt;
    void *ctx;
};

extern void UI_SetInputMode(u8 v);
extern u32 CURSOR_MOVE_GetNeighbour(const u8 *ptr, u32 idx, u32 type);
extern int CURSOR_MOVE_IsWrapNeighbour(const u8 *ptr, u32 type);

int CURSOR_MOVE_MoveCursor(struct Sound *obj, u32 dir, int sel)
{
    int direct;
    u32 n;

    UI_SetInputMode(0);

    if (sel & 0x80) {
        if (obj->field_F != 0xff) {
            sel = obj->field_F;
        } else {
            sel ^= 0x80;
        }
    }

    direct = 1;
loop:
    if ((obj->bits[(u32)sel >> 5] & (1 << (sel % 32))) == 0) {
        direct = 0;
        n = (u8)(CURSOR_MOVE_GetNeighbour((const u8 *)obj->entries, sel, dir) & 0x7f);
        if (n == (u32)sel || n == obj->field_D) {
            sel = obj->field_D;
        } else {
            sel = n;
            goto loop;
        }
    }

    if (obj->field_D != sel) {
        if (CURSOR_MOVE_IsWrapNeighbour((const u8 *)(&obj->entries[sel]), dir) == 1 && direct) {
            obj->field_F = obj->field_D;
        } else {
            obj->field_F = 0xff;
        }

        {
            u8 prev = obj->field_D;
            struct Vtbl *vt = obj->vt;
            void *ctx = obj->ctx;

            obj->field_D = (u8)sel;
            obj->field_E = prev;
            vt->f8(ctx, obj->field_D, obj->field_E);
        }
        return -3;
    }

    if (dir == 0) {
        return -8;
    }
    if (dir == 1) {
        return -7;
    }
    if (dir == 2) {
        return -6;
    }
    if (dir == 3) {
        return -5;
    }
    return -1;
}
