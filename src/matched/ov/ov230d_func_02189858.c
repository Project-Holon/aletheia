/*
 * function: OV230_SealBuffer
 * address:  0x02189858
 * packet:   pkt_ov230d_02189858
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

extern void OV230_StreamInit(OvStream *st, const u8 *key, u32 keyLen);
extern int OV230_SealStream(OvStream *st, u8 *src, u8 *dst, u32 size);

/* Seals a word buffer with a 16-byte key; the result is 0 or -1 (size not a multiple of 4). */
int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size)
{
    OvStream st;

    OV230_StreamInit(&st, key, 16);
    return -(OV230_SealStream(&st, src, dst, size) == -1);
}
