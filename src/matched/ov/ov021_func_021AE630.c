/*
 * function: func_021AE630
 * address:  0x021AE630
 * packet:   pkt_ov021_021AE630
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D454  0x0216D454  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; u32 fc; } S;

extern int func_0216D454(u32 a);

int func_021AE630(S *s)
{
    if (func_0216D454(s->f8) == 0)
        return 0;
    s->fc--;
    s->f0 = 10;
    return 1;
}
