/*
 * function: BTL_ADAPTER_NotifyNet
 * address:  0x021EEAE8
 * packet:   pkt_021EEAE8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_NotifyNet   0x021EEAE8  thumb
 *   BTL_NET_ExpectReplies   0x021D4C58  thumb
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021EEAF8; ldr r0, [r0]; cmp r0, #0; beq loc_021EEAF6; bl BTL_NET_ExpectReplies; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EEAE8  call through a global pointer when it is set */
void BTL_ADAPTER_NotifyNet(void)
{
    u32 g = *(u32 *)0x021F6384;
    if (g != 0)
        BTL_NET_ExpectReplies(g);
}

