/*
 * function: func_02184BF8
 * address:  0x02184BF8
 * packet:   pkt_ov020_02184BF8
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012374  0x02012374  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BFDD0  0x021BFDD0  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */

extern char ov011_id[];
extern char ov012_id[];

void func_02012374(void *ctx, int v);
void func_02034A5C(int id);
int func_02034AC4(int id);
typedef unsigned short u16;
int func_02158780(void *p, int b, int c, int d, u16 e);
int func_02184360(int *p, int n);
int func_021BFDD0(void *ctx, int a, int b, int c);

int func_02184BF8(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];
    int r;

    switch (*st) {
    case 0:
        r = func_021BFDD0(ctx, a, b, 0);
    join:
        func_02012374(ctx, r);
        (*st)++;
        break;
    case 1:
        r = func_02184360(p, 0);
        goto join;
    case 2:
        func_02034A5C((int)ov012_id);
        func_02034AC4((int)ov011_id);
        func_02158780(ctx, 0x83A, 0, 0, 0x15);
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
