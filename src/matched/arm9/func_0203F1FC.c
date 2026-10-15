/*
 * unit:     no
 * function: func_0203F1FC
 * address:  0x0203F1FC
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469F8     0x021469F8  data
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *
 * TU: gf_standard.c.
 *
 * Push bytes into the 0x200-byte buffer at +0x9cc of the random-number
 * block.  A length below two is padded out to two by duplicating the first
 * byte through a two-byte stack buffer.  0x9cc is out of reach of a single
 * ARM immediate, so the base is always two `add`s (+0x1cc then +0x800).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F1FC.c \
 *       --func func_0203F1FC --addr 0x0203F1FC --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;
typedef signed int    s32;

struct Mt {
    u32 mt[624];
    s32 index;
    u32 unk_9c4;
    u32 unk_9c8;
    u8  unk_9cc[0x200];
};

extern struct Mt *g_021469F8;

struct MATHCRC16Table;
extern u16 MATH_CalcCRC16CCITT(struct MATHCRC16Table *table, void *data, u32 dataLength);

u16 func_0203F1FC(const u8 *src, u32 len)
{
    if (len < 2) {
        u8 pair[2];

        pair[0] = src[0];
        pair[1] = src[0];
        return MATH_CalcCRC16CCITT((struct MATHCRC16Table *)g_021469F8->unk_9cc, pair, 2);
    } else {
        return MATH_CalcCRC16CCITT((struct MATHCRC16Table *)g_021469F8->unk_9cc, (void *)src, len);
    }
}
