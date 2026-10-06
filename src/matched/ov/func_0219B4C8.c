/*
 * function: func_0219B4C8
 * address:  0x0219B4C8
 * packet:   pkt_0219B4C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);

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

