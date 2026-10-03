/*
 * function: func_02184C78
 * address:  0x02184C78
 * packet:   pkt_ov020_02184C78
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
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02173744  0x02173744  thumb  ov012
 *   func_02184360  0x02184360  thumb  ov020
 *   func_021BF66C  0x021BF66C  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */

extern char ov011_id[];
extern char ov012_id[];

void func_02012374(void *ctx, int v);
void func_02034A5C(int id);
int func_02034AC4(signed int id);
int func_02161824(int a, int b);
void func_02173744(int a);
int func_02184360(int *p, int n);
int func_021BF66C(void *ctx, int a, int b);

int func_02184C78(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];

    switch (*st) {
    case 0:
        func_02012374(ctx, func_02161824(a, b));
        (*st)++;
        break;
    case 1:
        func_02034A5C((int)ov011_id);
        func_02034AC4((int)ov012_id);
        func_02012374(ctx, func_02184360(p, 4));
        (*st)++;
        break;
    case 2:
        func_02173744(a);
        (*st)++;
        break;
    case 3:
        func_02012374(ctx, func_021BF66C(ctx, a, b));
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
