/*
 * function: OV230_SealStream
 * address:  0x021895B8
 * packet:   pkt_ov230d_021895B8
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

static inline void SealWord(OvStream *st, u8 *in, u8 *out, const u8 *table)
{
    u32 v;

    v = in[0] ^ OV230_StreamNextByte(st);
    st->key = v;
    out[0] = v;
    v = in[1] ^ OV230_StreamNextByte(st);
    st->key = v;
    out[1] = v;
    out[2] = table[in[2]];
    v = in[3];
    out[3] = v;
    st->key = st->key * out[2] - v;
}

/* Seals a word stream: words of class 1 and 2 keep their top byte (bit 24 flipped) and get the low 24 bits moved by 0x582, the other words go through the keystream. The result is 0 or -1 (size not a multiple of 4). */
int OV230_SealStream(OvStream *st, u8 *src, u8 *dst, u32 size)
{
    u8 table[256];
    long off;

    if (size & 3) {
        return -1;
    }
    OV230_FillReverseTable(table);
    for (off = 0; off < size; off += 4) {
        switch (LOADER_DECRYPT_ClassifyOpcode(*(u32 *)(src + off))) {
        case 1:
        case 2: {
            u32 low;
            u32 top;

            *(u32 *)(dst + off) = *(u32 *)(src + off);
            low = *(u32 *)(dst + off) & 0x00FFFFFF;
            top = (*(u32 *)(dst + off) & 0xFF000000) ^ 0x01000000;
            st->key += top >> 24;
            *(u32 *)(dst + off) = top | ((low + 0x582) & 0x00FFFFFF);
            break;
        }
        case 3:
            *(u32 *)(src + off) ^= 0x01000000;
        default:
            SealWord(st, src + off, dst + off, table);
            break;
        }
    }
    return 0;
}
