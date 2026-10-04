/*
 * function: func_0204F2FC
 * address: 0x0204F2FC
 * packet: pkt_0204F2FC
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * symbols:
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_0204F2FC(u8 *p, u32 i, u32 value)
{
    u32 off = i * 40;
    *(u32 *)(*(u8 **)(p + 4) + off + 32) = value;
    *(u32 *)(*(u8 **)(p + 4) + off + 12) = (*(u32 *)(*(u8 **)(p + 4) + off + 32) << 16) >> 13;
}
