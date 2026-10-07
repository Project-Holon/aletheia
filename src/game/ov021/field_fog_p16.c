/*
 * file:     field_fog_p16.c
 * unit:     yes
 * function: func_021A07F8, func_021A0818
 * address:  0x021A07F8
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
 *   func_02011400  0x02011400  thumb
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct {
    u16 h;
    s16 m;
} Time;

typedef signed int     s32;

extern u8 func_02011400(int row, int col);
int func_021A07F8(u32 a, Time *t);
void func_021A0818(s16 *o, s32 a, u32 b);


/*
 * Addresses are Black-image addresses.
 */
int func_021A07F8(u32 a, Time *t)
{
    int h = func_02011400(a, t->h);
    return h * 3600 + t->m * 60;
}


void func_021A0818(s16 *o, s32 a, u32 b)
{
    o[0] = a & 0x1f;
    o[1] = (s16)(b & 0x1f) - (u16)o[0];
    o[2] = (a & 0x3e0) >> 5;
    o[3] = (s16)((b & 0x3e0) >> 5) - (u16)o[2];
    o[4] = (a & 0x7c00) >> 10;
    o[5] = (s16)((b & 0x7c00) >> 10) - (u16)o[4];
}
