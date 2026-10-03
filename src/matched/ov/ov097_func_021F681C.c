/*
 * function: func_021F681C
 * address: 0x021F681C
 * packet: pkt_ov097_021F681C
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding.
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_021F681C(u8 *p, int count, int result) { *(int *)(p + 0x11c) = count; *(int *)(p + 0x114) = result; return 3; }
