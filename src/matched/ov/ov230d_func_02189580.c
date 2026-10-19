/*
 * function: OV230_FillReverseTable
 * address:  0x02189580
 * packet:   pkt_ov230d_02189580
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

int OV230_FillReverseTable(u8 *table)
{
    u32 *p = (u32 *)table;
    u32 fill = 0x03020100;
    u32 *end = (u32 *)(table + 256);
    u32 v;

    do {
        v = fill ^ 0xFFFFFFFF;
        *p = v;
        p++;
        fill += 0x04040404;
    } while (p < end);
    return 0;
}
