/*
 * function: func_021A5788
 * address:  0x021A5788
 * packet:   pkt_ov021_021A5788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3898  0x021A3898  thumb  ov021
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A5788;

void func_021A3898(unsigned char *p, Vec021A5788 *v);
void func_02164208(int k, Vec021A5788 *v, int s);
void *func_021A3960(unsigned char *p);
void func_02163E34(void *h, Vec021A5788 *v, int *out);

void func_021A5788(u32 *p, int k, int *out)
{
    Vec021A5788 v;

    func_021A3898(*(unsigned char **)(p + 3), &v);
    if (k != 9)
        func_02164208(k, &v, 0x10000);
    func_02163E34(func_021A3960(*(unsigned char **)(p + 3)), &v, out);
}
