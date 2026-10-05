/*
 * function: func_0215A438
 * address:  0x0215A438
 * packet:   pkt_ov010_0215A438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159124  0x02159124  thumb  ov010
 */

typedef struct {
    int w[6];
} S24;

extern int func_021589D0(int);
extern char *func_02159124(char *p, int i);

void func_0215A438(int a, int b, S24 *src)
{
    int *q = (int *)func_02159124((char *)func_021589D0(a), b);

    *(S24 *)q = *src;
    q[6] = 0;
}
