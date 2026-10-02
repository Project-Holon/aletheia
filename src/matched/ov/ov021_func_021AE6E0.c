/*
 * function: func_021AE6E0
 * address:  0x021AE6E0
 * packet:   pkt_ov021_021AE6E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct S { u32 f0; u8 pad[0x30]; u8 *f34; } S;

extern void *func_021A3074(unsigned char *p);
extern int func_0216D454(void *a);
extern void func_0216D480(void *a);

int func_021AE6E0(S *s)
{
    void *t = func_021A3074(s->f34);

    if (func_0216D454(t) == 0)
        return 0;
    func_0216D480(t);
    s->f0 = 0x10;
    return 1;
}
