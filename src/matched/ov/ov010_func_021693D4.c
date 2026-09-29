/*
 * function: func_021693D4
 * address:  0x021693D4
 * packet:   pkt_ov010_021693D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (blocker of ov021 func_0218C4A0).  Stores a 0x14-byte
 * record (word, 12 bytes, halfword) into entry idx of the table at +0x9C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct V3 {
    u32 a, b, c;
} V3;

void func_021693D4(u8 *base, u8 *src, u32 idx)
{
    *(u32 *)(*(u8 **)(base + 0x9C) + idx * 0x14) = *(u32 *)src;
    *(V3 *)(*(u8 **)(base + 0x9C) + idx * 0x14 + 4) = *(V3 *)(src + 4);
    *(u16 *)(*(u8 **)(base + 0x9C) + idx * 0x14 + 0x10) = *(u16 *)(src + 0x10);
}
