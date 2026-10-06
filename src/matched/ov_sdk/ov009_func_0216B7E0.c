/*
 * function: func_0216B7E0
 * address:  0x0216B7E0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns -3 when func_0216BA08 rejects the pointer, else the func_0216BEA4 result.
 *
 * symbols:
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_0216BEA4  0x0216BEA4  arm  ov009

 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_0216B7E0(void *p)
{
    int func_0216BA08(void);
    int func_0216BEA4(void *);
    if (func_0216BA08() == 0) return -3;
    return func_0216BEA4(p);
}
