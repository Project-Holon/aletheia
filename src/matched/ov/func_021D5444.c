/*
 * function: BTL_POKEPARAM_GetSpecies
 * address:  0x021D5444
 * packet:   pkt_021D5440
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetSpecies   0x021D5444  thumb
 *
 * Reads the u16 field at #0xc of the argument and returns it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D5444  ldrh r0,[r0,#0xc] */
struct QF { u8 pad[0xc]; u16 v; };
u16 BTL_POKEPARAM_GetSpecies(struct QF *p) { return p->v; }

