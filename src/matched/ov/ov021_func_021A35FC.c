/*
 * function: func_021A35FC
 * address:  0x021A35FC
 * packet:   pkt_ov021_021A35FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3960  0x021A3960  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

void *func_021A3960(unsigned char *p);
int func_0216D83C(void *p);
int func_0216D854(void *p);
int func_0216D86C(void *p);

void func_021A35FC(unsigned char **p, u16 *a, u16 *b, u16 *c)
{
    void *h = func_021A3960(p[1]);

    *a = func_0216D83C(h);
    *b = func_0216D854(h);
    *c = func_0216D86C(h);
}
