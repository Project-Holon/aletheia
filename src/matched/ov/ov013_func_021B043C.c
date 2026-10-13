/*
 * function: VCT_ADPCM_DecodePacket
 * address:  0x021B043C
 * packet:   pkt_ov013_021B043C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   VCT_ADPCM_Decode2Bit  0x021AFFE4  arm  ov013
 *   VCT_ADPCM_Decode3Bit  0x021AF628  arm  ov013
 *   VCT_ADPCM_Decode4Bit  0x021AF340  arm  ov013
 */

typedef unsigned char u8;
typedef short s16;

typedef struct AdpcmState {
    s16 pred;
    u8 index;
} AdpcmState;

typedef unsigned int   u32;
extern void VCT_ADPCM_Decode2Bit(const u8 *src, s16 *dst, u32 n, struct AdpcmState *st);
extern void VCT_ADPCM_Decode3Bit(const u8 *src, s16 *dst, u32 n, struct AdpcmState *st);
extern void VCT_ADPCM_Decode4Bit(const u8 *src, s16 *dst, u32 n, struct AdpcmState *st);

void VCT_ADPCM_DecodePacket(AdpcmState *hdr, void *dst, int n, int mode)
{
    AdpcmState st;

    st.pred = hdr->pred;
    st.index = hdr->index;
    switch (mode) {
    case 2:
        VCT_ADPCM_Decode2Bit((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 3:
        VCT_ADPCM_Decode3Bit((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    case 4:
        VCT_ADPCM_Decode4Bit((u8 *)hdr + 4, dst, n - 4, &st);
        break;
    }
}
