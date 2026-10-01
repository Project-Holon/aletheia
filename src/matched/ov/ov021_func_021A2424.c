/*
 * function: func_021A2424
 * address:  0x021A2424
 * packet:   pkt_ov021_021A2424
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048B30  0x02048B30  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A2424;

u32 func_0218EC2C(u32 x);
void func_02048B30(u32 x, Vec021A2424 *out);

void func_021A2424(u8 *p)
{
    Vec021A2424 v;

    if (*(u32 *)(p + 0x14) != 0) {
        func_02048B30(func_0218EC2C(*(u32 *)(p + 0x14)), &v);
        *(Vec021A2424 *)(p + 0x68) = v;
    }
}
