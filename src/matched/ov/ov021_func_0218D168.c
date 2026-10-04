/*
 * function: func_0218D168
 * address:  0x0218D168
 * packet:   pkt_ov021_0218D168
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021694FC  0x021694FC  thumb ov010
 *   func_02169510  0x02169510  thumb ov010
 */

typedef unsigned short u16;

typedef unsigned char  u8;
struct V3;
extern u16 func_021694FC(u8 *p);
extern void func_02169510(u8 *src, struct V3 *dst);

int func_0218D168(char *p)
{
    int v[3];
    unsigned int i;

    for (i = 0; i < *(u16 *)(p + 0x2e); i++) {
        if (func_021694FC((u8 *)(*(int *)(*(char **)(p + 0x24) + i * 0x28)))) {
            int h;
            int x;
            int z;
            int x0;
            int x1;
            int z0;
            int z1;
            func_02169510((u8 *)(*(int *)(*(char **)(p + 0x24) + i * 0x28)), (struct V3 *)v);
            h = *(int *)(p + 4) / 2;
            x = v[0];
            z = v[2];
            x0 = x - h;
            z0 = z - h;
            x1 = x + h;
            z1 = z + h;
            if (*(int *)(p + 0x34) >= x0 && *(int *)(p + 0x34) < x1
                && *(int *)(p + 0x3c) >= z0 && *(int *)(p + 0x3c) < z1)
                return i;
        }
    }
    return 0;
}
