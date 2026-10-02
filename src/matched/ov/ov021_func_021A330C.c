/*
 * function: func_021A330C
 * address:  0x021A330C
 * packet:   pkt_ov021_021A330C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb
 *   func_02188CFC  0x02188CFC  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_021A3074(unsigned char *p);
extern int func_02188CFC();
extern s16 func_0216D83C();
extern s16 func_0216D854();
extern s16 func_0216D86C();
extern int func_021641E8();
extern int func_021641F8();

void func_021A330C(u32 *a, u32 b, s16 *c, s16 *d, s16 *e)
{
    void *t = func_021A3074(a);

    if (func_02188CFC(a[0]) == 0) {
        *c = func_0216D83C(t);
        *d = func_0216D854(t);
        *e = func_0216D86C(t);
        *c = *c + func_021641E8(b);
        *e = *e + func_021641F8(b);
    }
}
