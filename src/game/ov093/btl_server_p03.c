/*
 * file:     btl_server_p03.c
 * unit:     yes
 * function: func_021B9A00, func_021B9A24, func_021B9A40, func_021B9A50, func_021B9A5C, func_021B9A6C, func_021B9AB0, func_021B9AC8
 * address:  0x021B9A00
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
 *   func_021B99F0 0x021B99F0 thumb ov093
 *   func_021B8C20 0x021B8C20 thumb ov093
 *   func_021B99E0  0x021B99E0  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Unk021EFD70 { u16 n0; volatile u16 n1; u8 b[6]; };

extern u32 func_021B99F0(u32);
extern u8 func_021B8C20(int, u32, u32);
extern struct Unk021EFD70 *func_021B99E0(int i);
int func_021B9A00(u32 x, u8 *out);
int func_021B9A24(unsigned int a, unsigned int b);
unsigned char func_021B9A40(unsigned int x);
unsigned char func_021B9A50(unsigned int x);
/* 021B9A5C cmp r0,#0; bne; movs r0,#1; else 0; zext8 */ u8 func_021B9A5C(u32 x);
int func_021B9A6C(int a, u32 b);
int func_021B9AB0(int x);
int func_021B9AC8(int a);

int func_021B9A00(u32 x, u8 *out)
{
    if (func_021B99F0(x) == 0) {
        *out = func_021B8C20(2, x, (u8)(x >> 1));
        return 1;
    }
    return 0;
}

int func_021B9A24(unsigned int a, unsigned int b)
{
    unsigned char v = func_021B9A40(a);
    if (v == func_021B9A40(b)) return 1;
    return 0;
}

unsigned char func_021B9A40(unsigned int x)
{
    BOOL result;
    if (x < 12) result = FALSE;
    else result = TRUE;
    return result;
}


unsigned char func_021B9A50(unsigned int x)
{
    return func_021B9A5C(func_021B9A40(x));
}


/* 021B9A5C  cmp r0,#0; bne; movs r0,#1; else 0; zext8 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: cmp r0, #0; bne loc_021B9A64; movs r0, #1; b loc_021B9A66; movs r0, #0; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 func_021B9A5C(u32 x) { return x == 0; }


int func_021B9A6C(int a, u32 b)
{
    struct Unk021EFD70 *p = func_021B99E0(a);
    u32 i;

    for (i = 0; i < p->n0; i++) {
        if (b == p->b[i])
            return 1;
    }
    for (i = 0; i < p->n1; i++) {
        if (b == *((u8 *)p + 7 + i))
            return 1;
    }
    return 0;
}

int func_021B9AB0(int x)
{
    switch (x) {
    case 2: return 1;
    case 3: return 2;
    default: return 0;
    }
}

int func_021B9AC8(int a) {
    switch (a) { case 2: return 2; case 3: return 1; default: return 0; }
}
