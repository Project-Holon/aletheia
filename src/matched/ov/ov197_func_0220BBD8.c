/*
 * function: func_0220BBD8
 * address: 0x0220BBD8
 * packet: pkt_ov197_0220BBD8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Forward entry r0 as the key. The explicit result truncation requires a wide extern return.
 * symbols:
 *   sub_0202F144 0x0202F144 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 sub_0202F144(u32);
int func_0220BBD8(u32 key) { return (u16)sub_0202F144(key); }
