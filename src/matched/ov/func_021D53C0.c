/*
 * function: BTL_POKEPARAM_InitStatStages
 * address:  0x021D53C0
 * packet:   pkt_021D53C0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_SetNeutralStatStages   0x021D53C8  thumb ov093
 *   BTL_POKEPARAM_InitStatStages   0x021D53C0  thumb ov093
 *
 * tail-call thunk to BTL_POKEPARAM_SetNeutralStatStages
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void BTL_POKEPARAM_SetNeutralStatStages(unsigned char *p);

void BTL_POKEPARAM_InitStatStages(unsigned char *p)
{
    BTL_POKEPARAM_SetNeutralStatStages(p);
}
