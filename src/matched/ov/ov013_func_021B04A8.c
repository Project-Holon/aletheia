/*
 * function: VCT_ADPCM_EncodePacket
 * address:  0x021B04A8
 * packet:   pkt_ov013_021B04A8
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_ADPCM_Encode2Bit  0x021B01FC  arm  ov013
 *   VCT_ADPCM_Encode3Bit  0x021AFABC  arm  ov013
 *   VCT_ADPCM_Encode4Bit  0x021AF494  arm  ov013
 */

typedef unsigned char u8;
typedef short s16;

typedef struct AdpcmHdr {
    s16 pred;
    u8 index;
    u8 zero;
} AdpcmHdr;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

typedef unsigned int   u32;
extern void VCT_ADPCM_Encode2Bit(u8 *dst, s16 *src, u32 n, struct AdpcmState *st);
extern void VCT_ADPCM_Encode3Bit(u8 *dst, s16 *src, u32 n, struct AdpcmState *st);
extern void VCT_ADPCM_Encode4Bit(u8 *dst, s16 *src, u32 n, struct AdpcmState *st);

void VCT_ADPCM_EncodePacket(AdpcmHdr *out, void *a, int n, AdpcmState *st, int mode)
{
    out->pred = st->pred;
    out->index = st->index;
    out->zero = 0;
    switch (mode) {
    case 2:
        VCT_ADPCM_Encode2Bit((u8 *)out + 4, a, n, st);
        break;
    case 3:
        VCT_ADPCM_Encode3Bit((u8 *)out + 4, a, n, st);
        break;
    case 4:
        VCT_ADPCM_Encode4Bit((u8 *)out + 4, a, n, st);
        break;
    }
}
