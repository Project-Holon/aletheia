/*
 * function: func_02069BA0
 * address:  0x02069BA0
 * packet:   pkt_02069BA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g2d's MSB-first bit reader: return the next nBits bits of the
 * stream as a right-aligned value.  The reader holds the source cursor, the
 * number of bits still unread in the current byte and that byte itself.
 * When the request is wider than what is left, the leftover bits are taken,
 * the next byte is loaded (the static inline below) and the rest comes from
 * a recursive call; otherwise the byte is shifted down and the count drops.
 *
 * Closed 2026-09-24 (wave 21, lane G) from DIFF 6
 * (docs/notes/func_02069BA0.c.txt).  PINNED ../2.0/sp2 on the schedule tell
 * already recorded for the NitroSystem g2d block (func_02062BAC /
 * func_02062BF4 in docs/FRONTEND-PINS.md): the image sets the recursive
 * call's argument before the constant, `mov r1, r6` at 0x02069BD8 then
 * `mov r2, #8` at 0x02069BDC.  dsi/1.1p1 -O4,p emits the pair the other way
 * round on this exact source (96 bytes, 6 concrete out), as on every
 * spelling measured in waves 16 to 20; under ../2.0/sp2 (and sp1) it is 96
 * bytes, 0 out, and ../1.2/sp2 is 108 bytes.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02069BA0.c \
 *       --func func_02069BA0 --addr 0x02069BA0 --arm --cc ../2.0/sp2
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned int  u32;

struct BitReader {
    const u8 *src;
    s8        avail;
    u8        bits;
    u8        pad_06[2];
};

u32 func_02069BA0(struct BitReader *reader, int nBits);

static inline void BitReaderNextByte(struct BitReader *reader)
{
    reader->bits = *(reader->src)++;
    reader->avail = 8;
}

u32 func_02069BA0(struct BitReader *reader, int nBits)
{
    u32 val = reader->bits;
    int avail = reader->avail;

    if (avail < nBits) {
        int lack = nBits - avail;
        val <<= lack;
        BitReaderNextByte(reader);
        val |= func_02069BA0(reader, lack);
    } else {
        val >>= (avail - nBits);
        reader->avail = (s8)(avail - nBits);
    }

    val &= 0xFF >> (8 - nBits);
    return val;
}
