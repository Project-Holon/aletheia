/*
 * function: BTL_SERVER_FLOW_MarkActionDone
 * address:  0x021BD1D0
 * packet:   pkt_021BD1D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_MarkActionDone   0x021BD1D0  thumb
 *   BTL_SERVER_FLOW_FindActionByPokeId   0x021BCA08  thumb
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; bl BTL_SERVER_FLOW_FindActionByPokeId; cmp r0, #0; beq loc_021BD1DE; movs r1, #1; strb r1, [r0, #0xd]; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *BTL_SERVER_FLOW_FindActionByPokeId(u8 *p, u8 x);

/* 021BD1D0  guard on a callee's pointer result, then set a byte */
void BTL_SERVER_FLOW_MarkActionDone(u8 *p, u8 n)
{
    u8 *e = BTL_SERVER_FLOW_FindActionByPokeId(p, n);
    if (e != 0)
        e[0xd] = 1;
}

