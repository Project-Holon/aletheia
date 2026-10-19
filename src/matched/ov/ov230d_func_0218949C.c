/*
 * function: OV230_StreamInit
 * address:  0x0218949C
 * packet:   pkt_ov230d_0218949C
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

static inline void SwapBytes(u8 *a, u8 *b)
{
    u8 t = *a;

    *a = *b;
    *b = t;
}

/* Key schedule: fills the permutation with 0..255 and mixes it with the 16-byte key, from the top down. */
void OV230_StreamInit(OvStream *st, const u8 *key, u32 keyLen)
{
    int i;
    u32 j;
    u32 fill;
    u32 *p;
    u32 k;

    st->key = 0xAA;
    st->x = 0;
    st->y = 0;
    fill = 0x03020100;
    p = (u32 *)st->box;
    k = 0;
    j = 0;
    do {
        *p = fill;
        p++;
        fill += 0x04040404;
    } while (p < (u32 *)(st->box + 256));
    for (i = 255; i >= 0; i--) {
        j = (st->box[i] + (j + key[k])) & 0xFF;
        SwapBytes(&st->box[j], &st->box[i]);
        k++;
        if (k >= keyLen) {
            k = 0;
        }
    }
}
