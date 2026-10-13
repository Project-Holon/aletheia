/*
 * function: HAND_WAZA_RemoveMoveHandlerOfPoke
 * address:  0x021E03D8
 * packet:   pkt_021DFEF4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_WAZA_RemoveMoveHandlerOfPoke   0x021E03D8  thumb
 *   BTL_POKEPARAM_GetPokeId   0x021D5440  thumb
 *   HAND_WAZA_RemoveMoveHandlerById   0x021E03F8  thumb
 * Leaf with no calls and no pool; 6 instructions, 16 bytes: push {r4, lr}; adds r4, r1, #0; bl BTL_POKEPARAM_GetPokeId; adds r1, r4, #0; bl HAND_WAZA_RemoveMoveHandlerById; pop {r4, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void HAND_WAZA_RemoveMoveHandlerById(int a, int b);

/* 021E03D8  pass-through: second callee takes the first one's result */
void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b)
{
    HAND_WAZA_RemoveMoveHandlerById(BTL_POKEPARAM_GetPokeId(a), b);
}

