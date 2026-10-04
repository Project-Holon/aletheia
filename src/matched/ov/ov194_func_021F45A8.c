/*
 * function: func_021F45A8
 * address:  0x021F45A8
 * packet:   pkt_021F45A8
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F23F4 0x021F23F4 thumb
 *   func_021F23F8 0x021F23F8 thumb
 *   func_021F253C 0x021F253C thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_021F23F4(const u8 *p);
extern u32 func_021F23F8(const u8 *p);
extern int func_021F253C(u8 *p);

int func_021F45A8(int p)
{
    int *q = *(int **)(p + 0x2c4);

    if (*q == 0 || *q == 3) {
        if (func_021F23F4((const u8 *)(p + 0x68)) == 0 && func_021F23F8((const u8 *)(p + 0x68)) == 0) {
            return 0;
        }
        if (func_021F253C((u8 *)(p + 0x68)) == 0) {
            return 0;
        }
    }
    return 1;
}
