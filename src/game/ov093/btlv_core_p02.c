/*
 * file:     btlv_core_p02.c
 * unit:     yes
 * function: func_021E8A98, func_021E8AC8, func_021E8AFC, func_021E8B28, func_021E8B80
 * address:  0x021E8A98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

union Slot_021E8A98 {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

union Slot_021E8AC8 {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

union Slot_021E8AFC {
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
    struct { u32 kind : 3; u32 pad : 6; u32 v : 16; u32 rest : 7; } w;
};

union U {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

union Unk021E8B80 {
    struct { u32 kind : 3; u32 pad : 6; u32 id : 16; u32 rest : 7; } a;
    struct { u32 kind : 3; u32 pad : 12; u32 id : 16; u32 rest : 1; } b;
};

u8 func_021E8A98(union Slot_021E8A98 s);
void func_021E8AC8(union Slot_021E8AC8 *p, u8 v);
u8 func_021E8AFC(union Slot_021E8AFC s);
void func_021E8B28(union U *p, u16 v);
u16 func_021E8B80(union Unk021E8B80 v);


u8 func_021E8A98(union Slot_021E8A98 s)
{
    if (s.s.kind == 3)
        return s.s.lo;
    if (s.s.kind == 4)
        return s.s.hi;
    return 0x1f;
}


void func_021E8AC8(union Slot_021E8AC8 *p, u8 v)
{
    if (p->s.kind == 3)
        p->s.lo = v;
    else if (p->s.kind == 4)
        p->s.hi = v;
}

u8 func_021E8AFC(union Slot_021E8AFC s)
{
    if (s.s.kind == 2) return s.s.lo;
    if (s.s.kind == 4) return s.s.lo;
    return 0;
}

void func_021E8B28(union U *p, u16 v)
{
    if (p->a.kind == 1) p->a.id = v;
    else if (p->a.kind == 3) p->a.id = v;
    else if (p->a.kind == 4) p->b.id = v;
    else if (p->a.kind == 2) p->a.id = v;
}


u16 func_021E8B80(union Unk021E8B80 v)
{
    if (v.a.kind == 1) return v.a.id;
    if (v.a.kind == 3) return v.a.id;
    if (v.a.kind == 4) return v.b.id;
    if (v.a.kind == 2) return v.a.id;
    return 0;
}
