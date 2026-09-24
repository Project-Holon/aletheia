/*
 * function: func_021D826C
 * address:  0x021D826C
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D826C   0x021D826C  thumb
 *
 * Reads the u32 field at offset 0 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D826C  ldr r0,[r0] */
u32 func_021D826C(u32 *p) { return *p; }

