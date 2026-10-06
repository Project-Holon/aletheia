/*
 * function: func_021AE8B4
 * address:  0x021AE8B4
 * packet:   pkt_ov021_021AE8B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216D5B8  0x0216D5B8  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u32 f4; u32 f8; u32 fc; u32 f10; } S;

extern u32 func_0216D5B8(void *p);
extern int func_021AE884(u32 a);

void func_021AE8B4(S *s, u32 a, u32 b, u32 c)
{
    s->f4 = b;
    s->f8 = c;
    s->fc = func_0216D5B8((void *)a);
    s->f10 = func_021AE884(a);
    s->f0 = a;
}
