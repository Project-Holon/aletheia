/*
 * file:     btl_server_p46.c
 * unit:     yes
 * function: func_021C1194, func_021C1198
 * address:  0x021C1194
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

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021C1194 ldrb r0,[r0,#3] */ u8 func_021C1194(u8 *p);
void func_021C1198(unsigned char *p, int x);


/* 021C1194  ldrb r0,[r0,#3] */
u8 func_021C1194(u8 *p) { return p[3]; }

void func_021C1198(unsigned char *p, int x)
{
    if (p[5] == 3) {
        p[5] = x;
    }
}
