/*
 * file:     unit_021D794C_p03.c
 * unit:     yes
 * function: func_021D7C70, func_021D7D18, func_021D7D6C
 * address:  0x021D7C70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021D7B8C  0x021D7B8C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89F8  0x021E89F8  thumb  ov093
 *   func_021E8A28  0x021E8A28  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word;

struct Sel { u16 kind : 4; u16 lo : 6; u16 hi : 6; };

union Slot {
    u32 raw;
    struct { u32 kind : 3; u32 lo : 6; u32 hi : 6; u32 rest : 17; } s;
};

extern u8 func_021D5440(u8 *p);
extern Word func_021E899C(u32 a);
extern u32 func_021D7B8C(u32 lo, u32 hi);
extern Word func_021E8940(u8 a);
extern Word func_021E89F8(u8 a, u32 b);
extern Word func_021E8A28(u32 a, u8 b);
void func_021D7C70(struct Sel s, int m, Word *out);
union Slot func_021D7D18(int x);
/* 021D7D6C cmp r0,#6; bge; movs r0,#1; bx lr; movs r0,#0; bx lr */ int func_021D7D6C(int x);


void func_021D7C70(struct Sel s, int m, Word *out)
{
    u8 x;
    u8 y;

    switch (s.kind) {
    case 3:
        *out = func_021E899C(func_021D5440((u8 *)m));
        break;
    case 2:
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8940(y);
        break;
    case 1:
        *out = func_021E89F8(s.hi, s.lo);
        break;
    case 4:
        x = func_021D5440((u8 *)m);
        y = func_021D7B8C(s.lo, s.hi);
        *out = func_021E8A28(x, y);
        break;
    case 0:
    default:
        break;
    }
}

union Slot func_021D7D18(int x)
{
    union Slot s;
    s.raw = 0;
    switch (x) {
    case 1:
    case 3:
    case 4:
    case 5:
        s.s.kind = 1;
        break;
    case 2:
        s.s.kind = 2;
        s.s.lo = func_021D7B8C(2, 4);
        break;
    case 0:
    default:
        s.s.kind = 0;
        break;
    }
    return s;
}


/* 021D7D6C  cmp r0,#6; bge; movs r0,#1; bx lr; movs r0,#0; bx lr */
int func_021D7D6C(int x)
{
    if (x < 6)
        return 1;
    return 0;
}
