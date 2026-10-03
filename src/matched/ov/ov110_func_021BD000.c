/*
 * function: func_021BD000
 * address: 0x021BD000
 * packet: pkt_ov110_021BD000
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BD026.
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B878 0x0204B878 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0204B3F4(void *);
extern void func_0204B878(void *,u16);
int func_021BD000(char *p) { if (func_0204B3F4(*(void **)(p+0x28)) && *(int *)(p+0x2c)==0) { func_0204B878(*(void **)(p+0x28),9); *(int *)(p+0x2c)=1; return 1; } return 0; }
