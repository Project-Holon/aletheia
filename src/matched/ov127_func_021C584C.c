/*
 * function: func_021C584C
 * address:  0x021C584C
 * packet:   pkt_ov127_021C584C
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 8-byte ov127 accessor veneer in a .word run (0x021C5834,
 * 0x021C5840, 0x021C584C, 0x021C5858 are four in a row): `ldr r0,[r0,#0];
 * ldr r3,=func_021C424C; bx r3`.  Blocker target of src/pending/
 * ov099_func_021B98E4.c.
 *
 * symbols:
 *   func_021C424C  0x021C424C  thumb  ov127
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021C424C(u32 a);

void func_021C584C(u8 *p)
{
    func_021C424C(*(u32 *)(p + 4));
}
