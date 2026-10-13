/*
 * function: func_021ABE8C
 * address:  0x021ABE8C
 * packet:   pkt_021ABE8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_EFFECT_FindResourceSlot  0x021ABF2C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct T T;
typedef struct E E;
extern E *FIELD_EFFECT_FindResourceSlot(T *, int);

int func_021ABE8C(T *a, int id)
{
if (FIELD_EFFECT_FindResourceSlot(a, id) != 0) {
    return 1;
}
return 0;
}

