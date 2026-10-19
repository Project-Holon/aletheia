/*
 * function: OV230_OpenStream
 * address:  0x021896D0
 * packet:   pkt_ov230d_021896D0
 * region:   ov230d
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     from src/game/ov230/sealed_cipher.c (decrypted view of overlay 230, region ov230d)
 * symbols:
 *   OV230_StreamInit  0x0218949C  arm  ov230d
 *   OV230_StreamNextByte  0x02189528  arm  ov230d
 *   OV230_FillReverseTable  0x02189580  arm  ov230d
 *   OV230_SealStream  0x021895B8  arm  ov230d
 *   OV230_OpenStream  0x021896D0  arm  ov230d
 *   OV230_SealBuffer  0x02189858  arm  ov230d
 *   OV230_OpenBuffer  0x021898B0  arm  ov230d
 *   LOADER_ENTRY_DecryptCipher  0x02189908  arm  ov230d
 *   LOADER_DECRYPT_ClassifyOpcode  0x02188A0C  arm  ov230
 *   LOADER_DECRYPT_DecodeBlocks  0x02188A48  arm  ov230
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern int LOADER_DECRYPT_ClassifyOpcode(u32 instr);
extern void LOADER_DECRYPT_DecodeBlocks(void);

/* State of the stream cipher: a running key word, two indices and a 256-byte permutation. */
typedef struct OvStream {
    u32 key;
    u32 x;
    u32 y;
    u8 box[256];
} OvStream;

extern u8 OV230_StreamNextByte(OvStream *st);
extern int OV230_FillReverseTable(u8 *table);

static inline void OpenWord(OvStream *st, u8 *in, u8 *out, const u8 *table)
{
    u32 v;
    u32 t;

    v = in[0];
    t = v ^ OV230_StreamNextByte(st);
    st->key = v;
    out[0] = t;
    v = in[1];
    t = v ^ OV230_StreamNextByte(st);
    st->key = v;
    out[1] = t;
    st->key = st->key * in[2] - in[3];
    out[2] = table[in[2]];
    out[3] = in[3];
}

/* Opens a sealed word stream: the inverse of OV230_SealStream. The result is 0 or -1 (size not a multiple of 4). */
#pragma opt_lifetimes off
int OV230_OpenStream(OvStream *st, u8 *src, u8 *dst, u32 size)
{
    u8 table[256];
    long off;

    if (size & 3) {
        return -1;
    }
    OV230_FillReverseTable(table);
    for (off = 0; off < size; off += 4) {
        u32 word = *(u32 *)(src + off);

        switch (LOADER_DECRYPT_ClassifyOpcode(word)) {
        case 1:
        case 3:
            st->key += word >> 24;
            *(u32 *)(dst + off) = ((word & 0xFF000000) ^ 0x01000000) | (((word & 0x00FFFFFF) + 0xFFFFFA7E) & 0x00FFFFFF);
            break;
        case 2:
            OpenWord(st, src + off, dst + off, table);
            *(u32 *)(src + off) ^= 0x01000000;
            break;
        default:
            OpenWord(st, src + off, dst + off, table);
            break;
        }
    }
    return 0;
}
#pragma opt_lifetimes reset
