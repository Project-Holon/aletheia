/*
 * file:     weather_task_p57.c
 * unit:     yes
 * function: func_021A5378, func_021A5390, func_021A53A4
 * address:  0x021A5378
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
 *   func_021A5304  0x021A5304  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 *   func_021A5318  0x021A5318  thumb  ov021
 */
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

int func_021A5304(u32 a, u32 b);
int func_021A530C(u32 a, u32 b);
extern int func_021A5318(u32 *p, u32 m);
void func_021A5378(u32 *p, int on);
int func_021A5390(u32 a);
void func_021A53A4(u32 *p, int on);


void func_021A5378(u32 *p, int on)
{
    if (on == 1)
        func_021A5304((u32)p, 8);
    else
        func_021A530C((u32)p, 8);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A5390(u32 a)
{
if (func_021A5318((u32 *)a, 8) != 0) {
    return 1;
}
return 0;
}


void func_021A53A4(u32 *p, int on)
{
    if (on == 1)
        func_021A5304((u32)p, 0x10);
    else
        func_021A530C((u32)p, 0x10);
}
