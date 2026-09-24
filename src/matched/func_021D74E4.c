/*
 * function: func_021D74E4
 * address:  0x021D74E4
 * packet:   pkt_021D6D7C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D74E4   0x021D74E4  thumb
 *   func_021D74C8   0x021D74C8  thumb
 * 7 instructions, 16 bytes: push {r3, lr}; ldr r0, pool_021D74F4; ldr r0, [r0]; cmp r0, #0; beq loc_021D74F2; bl func_021D74C8; pop {r3, pc}.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021D74E4  call through a global pointer when it is set */
void func_021D74E4(void)
{
    u32 g = *(u32 *)0x021F3ECC;
    if (g != 0)
        func_021D74C8(g);
}

