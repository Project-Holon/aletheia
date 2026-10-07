/*
 * file:     field_flash_p01.c
 * unit:     yes
 * function: func_021C6E5C, func_021C6E74
 * address:  0x021C6E5C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C6CA8  0x021C6CA8  thumb  ov021
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Q Q;

typedef struct { u8 n; u8 pad[3]; Q **f4; u32 *f8; } R;

extern void func_021C6CA8(Q *q);
void func_021C6E5C(R *r, int i, Q *q, u32 v);
void func_021C6E74(R *r, u8 i);

void func_021C6E5C(R *r, int i, Q *q, u32 v)
{
    if (r->f4[i] == 0) {
        r->f4[i] = q;
        r->f8[i] = v;
    }
}

void func_021C6E74(R *r, u8 i)
{
    if (r->f4[i] != 0) {
        func_021C6CA8(r->f4[i]);
        r->f4[i] = 0;
        r->f8[i] = 0;
    }
}
