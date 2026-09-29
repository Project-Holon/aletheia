/*
 * function: func_021880BC
 * address:  0x021880BC
 * packet:   pkt_ov096_021880BC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02011324  0x02011324  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8 *func_02011324(int);
extern u32 func_0203F0A8(void);

void func_021880BC(int a, u8 *b, int c)
{
    u8 *p;
    int i;
    int z;

    p = func_02011324(a);
    p[0] = 0;
    *(u16 *)(p + 2) = 0;
    p[1] = 0;
    *(int *)(p + 0x38) = 0;
    p[0x44] = 0;
    p[0x45] = 0;
    p[0x94] = c;
    *(int *)(p + 0x3c) = *(int *)(p + 0x40);
    *(int *)(p + 0xc8) = 4;
    z = 0;
    for (i = 0; i < 4; i++) {
        if (b[i] == 0)
            *(int *)(p + 0x14 + i * 4) = z;
        else
            *(int *)(p + 0x14 + i * 4) = 100;
        p[0x48 + i] = 100 - (u32)(((u64)func_0203F0A8() * 0x10) >> 32);
    }
    *(u32 *)(p + 0xcc) = (u32)(((u64)func_0203F0A8() * 0x100) >> 32);
}
