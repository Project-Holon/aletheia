/*
 * function: func_0219B45C
 * address:  0x0219B45C
 * packet:   pkt_ov021_0219B45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   d_021D52CC  0x021D52CC  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef void (*Handler)(u32);
extern u16 func_0216D5A8(u8 *p);
extern Handler d_021D52CC[];

void func_0219B45C(u32 a)
{
    d_021D52CC[func_0216D5A8((u8 *)a)](a);
}
