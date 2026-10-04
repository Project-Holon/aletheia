/*
 * function: func_0218CC64
 * address:  0x0218CC64
 * packet:   pkt_ov021_0218CC64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218DFE0  0x0218DFE0  thumb ov021
 *   func_02169510  0x02169510  thumb ov010
 *   func_02169500  0x02169500  thumb ov010
 *   func_02169354  0x02169354  thumb ov010
 *   func_0218B88C  0x0218B88C  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

extern int func_0218DFE0(void *p, int i, int m, int *out);
struct V3;
extern void func_02169510(u8 *src, struct V3 *dst);
extern void func_02169500(u8 *p, u8 *q);
extern int func_02169354(int o, int a);
extern void func_0218B88C(unsigned char *p);

void func_0218CC64(char *p, int a, int m)
{
    int w[3];
    int v[3];
    int idx;
    int i;
    u8 *c;

    if (m == 0 && *(u8 *)(p + 0x40) == 0)
        return;
    for (i = 0; i < *(u16 *)(p + 0x2e); i++) {
        if (func_0218DFE0(p, i, m, &idx)) {
            int r;
            c = (u8 *)p + 0x43;
            func_02169510((u8 *)(*(int *)(*(char **)(p + 0x24) + idx * 0x28)), (struct V3 *)w);
            v[0] = w[0] + *(int *)(p + 0x54);
            v[1] = w[1] + *(int *)(p + 0x58);
            v[2] = w[2] + *(int *)(p + 0x5c);
            func_02169500((u8 *)(*(int *)(*(char **)(p + 0x24) + idx * 0x28)), (u8 *)v);
            r = func_02169354(*(int *)(*(char **)(p + 0x24) + idx * 0x28), a);
            func_02169500((u8 *)(*(int *)(*(char **)(p + 0x24) + idx * 0x28)), (u8 *)w);
            if (r != 0 && *(u8 *)(p + 0x43) < *(u16 *)(p + 0x2e))
                *c = *c + 1;
        }
    }
    if (m == 1)
        func_0218B88C((unsigned char *)(*(int *)(p + 0x64)));
}
