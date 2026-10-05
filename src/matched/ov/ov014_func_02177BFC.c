/*
 * function: func_02177BFC
 * address:  0x02177BFC
 * packet:   pkt_ov014_02177BFC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf (prints as .word data in ov014.s), the sole blocker
 * of ov011 func_02173368 +004A: writes the byte at +0x54 through its second
 * argument and returns the address of +0x58.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[4];
    u8 kind;
    u8 pad5[3];
    u8 rec[4];
} Sub;

typedef struct {
    u8 pad0[0x50];
    Sub sub;
} S;

u8 *func_02177BFC(S *a0, u8 *out)
{
    Sub *s = &a0->sub;

    *out = s->kind;
    return s->rec;
}
