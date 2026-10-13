/*
 * function: CARD_CalcRomHashBufferLength
 * address:  0x0272EBDC
 * packet:   twl_audio
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct SizeHdr_0272EBDC {
    char pad[0x1fc];
    u32 c;
    u32 b;
    u32 a;
};

u32 CARD_CalcRomHashBufferLength(void *p)
{
    struct SizeHdr_0272EBDC *hdr = p;
    u32 per = hdr->a * 0x14;
    u8 *start = 0;
    u8 *q = start;
    q += (hdr->c + 0x1f) & ~0x1f;
    q += ((hdr->b << 5) + 0x1f) & ~0x1f;
    q += (((((per + 0xff + 0x500) & (u32)(start - 0x600)) << 2) + 0x1f) & ~0x1f);
    return (u32)q + 0x260;
}
