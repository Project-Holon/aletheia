/*
 * unit:     yes
 * function: CURSOR_MOVE_GetCurrent
 * address:  0x020260E0
 * packet:   pkt_020260E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c accessors following src/matched/CURSOR_MOVE_MoveCursor.c:
 * read the current cursor entry, set it (clearing the two trailing
 * cached indices to 0xff), and read field_4.  All leaves; calls nothing.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Entry {
    u32 a;
    u32 b;
    u32 c;
};

struct Vtbl;

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

u8 CURSOR_MOVE_GetCurrent(struct Sound *obj)
{
    return obj->field_D;
}

void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel)
{
    obj->field_D = sel;
    obj->field_E = 0xff;
    obj->field_F = 0xff;
}

u32 CURSOR_MOVE_GetState(struct Sound *obj)
{
    return obj->field_4;
}
