/*
 * function: func_02189A2C
 * address: 0x02189A2C
 * packet: pkt_ov096_02189A2C
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0218A378 0x0218A378 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0218A378(int, int, int);
int func_02189A2C(u8 *a, u8 *b)
{
    *(int *)(b + 0x38) = func_0218A378((int)b, *(u16 *)(b + 2), 2); return *(int *)(b + 0xc4);
}
