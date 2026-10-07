/*
 * file:     unit_02198D3C_p29.c
 * unit:     yes
 * function: func_0219B478, func_0219B494, func_0219B4C8
 * address:  0x0219B478
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
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   d_021D5320  0x021D5320  data  a4
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef void (*Handler)(u32);

extern u16 func_0216D5A8(u8 *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
void func_0219B478(u32 a);
int func_0219B494(int a);
int func_0219B4C8(int a);
extern Handler d_021D5320[];


void func_0219B478(u32 a)
{
    d_021D5320[func_0216D5A8((u8 *)a)](a);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219B494(int a)
{
if (func_0216D83C((void *)a) != func_0216D804((void *)a)) {
    return 1;
}
if (func_0216D86C((void *)a) != func_0216D81C((void *)a)) {
    return 1;
}
return 0;
}


int func_0219B4C8(int a)
{
if (func_0216D83C((void *)a) != func_0216D804((void *)a)) {
    return 0;
}
if (func_0216D86C((void *)a) == func_0216D81C((void *)a)) {
    return 1;
}
return 0;
}
