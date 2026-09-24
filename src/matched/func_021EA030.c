/*
 * function: func_021EA030
 * address:  0x021EA030
 * packet:   pkt_021E8CE0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EA030   0x021EA030  thumb
 *
 * Leaf with no calls and no pool; 10 instructions, 20 bytes: adds r1, r0, #0; adds r1, #0xe1; ldrb r1, [r1]; cmp r1, #0; beq loc_021EA040; adds r0, #0xe0; ldrb r0, [r0]; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EA030  if (p[0xe1]) return p[0xe0]; return 0; */
u8 func_021EA030(u8 *p)
{
    if (p[0xe1] != 0)
        return p[0xe0];
    return 0;
}

