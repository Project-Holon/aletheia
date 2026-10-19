/*
 * file:     sealed_cipher.c
 * unit:     yes
 * function: OV230_StreamInit, OV230_StreamNextByte, OV230_FillReverseTable, OV230_SealStream, OV230_OpenStream, OV230_SealBuffer, OV230_OpenBuffer, LOADER_ENTRY_DecryptCipher
 * address:  0x0218949C
 * region:   ov230d
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): the stream cipher that seals and opens
 * the second-layer bodies, and the initialiser entry that decrypts it.
 *
 * Six of the seven functions are asm stand-ins holding the original words: a C draft of each exists
 * (stream key schedule, keystream byte, seal/open of a word stream, the two buffer wrappers) but
 * does not reproduce the bytes yet (register colours and instruction order). OV230_FillReverseTable
 * is matched C.
 *
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

/* stand-in: the C draft of this function does not match yet; these are the original words */
asm void OV230_StreamInit(OvStream *st, const u8 *key, u32 keyLen)
{
    DCD     0xE92D41F0
    DCD     0xE3A040AA
    DCD     0xE3A03000
    DCD     0xE5804000
    DCD     0xE5803004
    DCD     0xE59F5068
    DCD     0xE59FC068
    DCD     0xE1A08003
    DCD     0xE5803008
    DCD     0xE280600C
    DCD     0xE2804F43
    DCD     0xE4865004
    DCD     0xE1560004
    DCD     0xE085500C
    DCD     0x3AFFFFFB
    DCD     0xE3A070FF
    DCD     0xE3A0C000
    DCD     0xE7D14003
    DCD     0xE0806007
    DCD     0xE5D6500C
    DCD     0xE0884004
    DCD     0xE2833001
    DCD     0xE0854004
    DCD     0xE20480FF
    DCD     0xE0804008
    DCD     0xE5D4E00C
    DCD     0xE1530002
    DCD     0x21A0300C
    DCD     0xE5C4500C
    DCD     0xE5C6E00C
    DCD     0xE2577001
    DCD     0x5AFFFFF0
    DCD     0xE8BD81F0
    DCD     0x03020100
    DCD     0x04040404
}


/* stand-in: the C draft of this function does not match yet; these are the original words */
asm u8 OV230_StreamNextByte(OvStream *st)
{
    DCD     0xE92D4010
    DCD     0xE5901004
    DCD     0xE5902000
    DCD     0xE2811001
    DCD     0xE0811002
    DCD     0xE20140FF
    DCD     0xE280E00C
    DCD     0xE7DEC004
    DCD     0xE5901008
    DCD     0xE08C1001
    DCD     0xE0821001
    DCD     0xE20130FF
    DCD     0xE7DE2003
    DCD     0xE5804004
    DCD     0xE5803008
    DCD     0xE08C1002
    DCD     0xE7CEC003
    DCD     0xE20110FF
    DCD     0xE7CE2004
    DCD     0xE0800001
    DCD     0xE5D0000C
    DCD     0xE8BD8010
}


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


/* stand-in: the C draft of this function does not match yet; these are the original words */
asm int OV230_SealStream(OvStream *st, u8 *src, u8 *dst, u32 size)
{
    DCD     0xE92D4FF8
    DCD     0xE24DDC01
    DCD     0xE1A07003
    DCD     0xE3170003
    DCD     0xE1A0A000
    DCD     0xE1A09001
    DCD     0xE1A08002
    DCD     0x128DDC01
    DCD     0x13E00000
    DCD     0x18BD8FF8
    DCD     0xE28D0000
    DCD     0xEBFFFFE5
    DCD     0xE3570000
    DCD     0xE3A04000
    DCD     0x9A000033
    DCD     0xE28DB000
    DCD     0xE7990004
    DCD     0xE0896004
    DCD     0xEBFFFD01
    DCD     0xE3500001
    DCD     0x13500002
    DCD     0x0A000004
    DCD     0xE3500003
    DCD     0x05960000
    DCD     0x02200401
    DCD     0x05860000
    DCD     0xEA00000D
    DCD     0xE5961000
    DCD     0xE3C104FF
    DCD     0xE20124FF
    DCD     0xE7881004
    DCD     0xE2800082
    DCD     0xE2800C05
    DCD     0xE59A1000
    DCD     0xE2222401
    DCD     0xE0811C22
    DCD     0xE3C004FF
    DCD     0xE58A1000
    DCD     0xE1820000
    DCD     0xE7880004
    DCD     0xEA000016
    DCD     0xE1A0000A
    DCD     0xEBFFFFB0
    DCD     0xE5D61000
    DCD     0xE0885004
    DCD     0xE0211000
    DCD     0xE58A1000
    DCD     0xE1A0000A
    DCD     0xE7C81004
    DCD     0xEBFFFFA9
    DCD     0xE5D61001
    DCD     0xE0210000
    DCD     0xE58A0000
    DCD     0xE5C50001
    DCD     0xE5D60002
    DCD     0xE7DB0000
    DCD     0xE5C50002
    DCD     0xE5D62003
    DCD     0xE5C52003
    DCD     0xE5D50002
    DCD     0xE59A1000
    DCD     0xE0000091
    DCD     0xE0400002
    DCD     0xE58A0000
    DCD     0xE2844004
    DCD     0xE1540007
    DCD     0x3AFFFFCC
    DCD     0xE3A00000
    DCD     0xE28DDC01
    DCD     0xE8BD8FF8
}


/* stand-in: the C draft of this function does not match yet; these are the original words */
asm int OV230_OpenStream(OvStream *st, u8 *src, u8 *dst, u32 size)
{
    DCD     0xE92D4FF8
    DCD     0xE24DDC01
    DCD     0xE1A05003
    DCD     0xE3150003
    DCD     0xE1A07000
    DCD     0xE1A0B001
    DCD     0xE1A06002
    DCD     0x128DDC01
    DCD     0x13E00000
    DCD     0x18BD8FF8
    DCD     0xE28D0000
    DCD     0xEBFFFF9F
    DCD     0xE3550000
    DCD     0xE3A08000
    DCD     0x9A00004E
    DCD     0xE79B9008
    DCD     0xE08B4008
    DCD     0xE1A00009
    DCD     0xEBFFFCBB
    DCD     0xE3500001
    DCD     0x0A000003
    DCD     0xE3500002
    DCD     0x0A00000D
    DCD     0xE3500003
    DCD     0x1A000028
    DCD     0xE59F0118
    DCD     0xE3C914FF
    DCD     0xE5973000
    DCD     0xE0810000
    DCD     0xE20924FF
    DCD     0xE0833C29
    DCD     0xE2221401
    DCD     0xE3C004FF
    DCD     0xE5873000
    DCD     0xE1810000
    DCD     0xE7860008
    DCD     0xEA000035
    DCD     0xE5D49000
    DCD     0xE1A00007
    DCD     0xEBFFFF6D
    DCD     0xE0290000
    DCD     0xE5879000
    DCD     0xE7C60008
    DCD     0xE5D49001
    DCD     0xE1A00007
    DCD     0xE086A008
    DCD     0xEBFFFF66
    DCD     0xE5879000
    DCD     0xE0290000
    DCD     0xE5CA0001
    DCD     0xE5D41002
    DCD     0xE5972000
    DCD     0xE5D40003
    DCD     0xE0010192
    DCD     0xE0410000
    DCD     0xE5870000
    DCD     0xE5D41002
    DCD     0xE28D0000
    DCD     0xE7D00001
    DCD     0xE5CA0002
    DCD     0xE5D40003
    DCD     0xE5CA0003
    DCD     0xE5940000
    DCD     0xE2200401
    DCD     0xE5840000
    DCD     0xEA000018
    DCD     0xE5D49000
    DCD     0xE1A00007
    DCD     0xEBFFFF50
    DCD     0xE0290000
    DCD     0xE5879000
    DCD     0xE7C60008
    DCD     0xE5D49001
    DCD     0xE1A00007
    DCD     0xE086A008
    DCD     0xEBFFFF49
    DCD     0xE5879000
    DCD     0xE0290000
    DCD     0xE5CA0001
    DCD     0xE5D41002
    DCD     0xE5972000
    DCD     0xE5D40003
    DCD     0xE0010192
    DCD     0xE0410000
    DCD     0xE5870000
    DCD     0xE5D41002
    DCD     0xE28D0000
    DCD     0xE7D00001
    DCD     0xE5CA0002
    DCD     0xE5D40003
    DCD     0xE5CA0003
    DCD     0xE2888004
    DCD     0xE1580005
    DCD     0x3AFFFFB0
    DCD     0xE3A00000
    DCD     0xE28DDC01
    DCD     0xE8BD8FF8
    DCD     0xFFFFFA7E
}


/* stand-in: the C draft of this function does not match yet; these are the original words */
asm int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size)
{
    DCD     0xE92D4078
    DCD     0xE24DDF43
    DCD     0xE1A04000
    DCD     0xE1A06001
    DCD     0xE1A05002
    DCD     0xE1A01004
    DCD     0xE28D0000
    DCD     0xE3A02010
    DCD     0xE1A04003
    DCD     0xEBFFFF06
    DCD     0xE28D0000
    DCD     0xE1A01006
    DCD     0xE1A02005
    DCD     0xE1A03004
    DCD     0xEBFFFF48
    DCD     0xE3E01000
    DCD     0xE1500001
    DCD     0x03A00001
    DCD     0x13A00000
    DCD     0xE2600000
    DCD     0xE28DDF43
    DCD     0xE8BD8078
}


/* stand-in: the C draft of this function does not match yet; these are the original words */
asm int OV230_OpenBuffer(const u8 *key, u8 *src, u8 *dst, u32 size)
{
    DCD     0xE92D4078
    DCD     0xE24DDF43
    DCD     0xE1A04000
    DCD     0xE1A06001
    DCD     0xE1A05002
    DCD     0xE1A01004
    DCD     0xE28D0000
    DCD     0xE3A02010
    DCD     0xE1A04003
    DCD     0xEBFFFEF0
    DCD     0xE28D0000
    DCD     0xE1A01006
    DCD     0xE1A02005
    DCD     0xE1A03004
    DCD     0xEBFFFF78
    DCD     0xE3E01000
    DCD     0xE1500001
    DCD     0x03A00001
    DCD     0x13A00000
    DCD     0xE2600000
    DCD     0xE28DDF43
    DCD     0xE8BD8078
}


/* hand-written in the original: initialiser entry, r0 = pc + 4 names the range table that follows (the cipher), always nonzero so the bne reaches the decoder */
asm void LOADER_ENTRY_DecryptCipher(void)
{
    orr     r0, pc, #0
    adds    r0, r0, #4
    bne     LOADER_DECRYPT_DecodeBlocks
    DCD     0x0218AA9C
    DCD     0x0218B024
    DCD     0x0218AB80
    DCD     0x0218AFD0
    DCD     0x0218ABB8
    DCD     0x0218B0B8
    DCD     0x0218ACD0
    DCD     0x0218B124
    DCD     0x0218AE58
    DCD     0x0218AFF8
    DCD     0x0218AEB0
    DCD     0x0218AFF8
    DCD     0x0218AB28
    DCD     0x0218AFF8
    DCD     0x00000000
    DCD     0x00000000
}
