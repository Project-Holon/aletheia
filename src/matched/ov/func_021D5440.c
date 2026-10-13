/*
 * function: BTL_POKEPARAM_GetPokeId
 * address:  0x021D5440
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId   0x021D5440  thumb
 *
 * Reads the u8 field at #0x19 of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D5440  ldrb r0,[r0,#0x19] */
u8 BTL_POKEPARAM_GetPokeId(u8 *p) { return p[0x19]; }

