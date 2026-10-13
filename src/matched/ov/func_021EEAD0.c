/*
 * function: BTL_ADAPTER_ResetCommand
 * address:  0x021EEAD0
 * packet:   pkt_021ED450
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_ResetCommand   0x021EEAD0  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0xc]; movs r1, #0; strb r1, [r0, #0xe]; strb r1, [r0, #0xf]; movs r1, #0xf; bics r2, r1; strb r2, [r0, #0xc]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EEAD0  clear the low nibble of byte +0xc and zero bytes +0xe/+0xf */
void BTL_ADAPTER_ResetCommand(u8 *p)
{
    u8 v = p[0xc];

    p[0xe] = 0;
    p[0xf] = 0;
    p[0xc] = v & ~0xf;
}

