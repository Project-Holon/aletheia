/*
 * file:     sealed_cipher.c
 * unit:     yes
 * function: OV230_StreamInit, OV230_StreamNextByte, OV230_FillReverseTable, OV230_SealStream, OV230_OpenStream, OV230_SealBuffer, OV230_OpenBuffer, LOADER_ENTRY_DecryptCipher
 * address:  0x0218949C
 * region:   ov230d
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Decrypted code of overlay 230 (region ov230d, tools/ovcrypt.py): the stream cipher that seals and opens
 * the second-layer bodies, and the initialiser entry that decrypts it.
 *
 * The cipher was compiled with the 2.0/sp2 compiler, like the loader. All of it is matched C except the
 * hand-written initialiser entry. The swap, the seal step and the open step are static inline helpers: their
 * inline locals set the register colours, so the functions only match with them.
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
#include "../types.h"

extern int LOADER_DECRYPT_ClassifyOpcode(u32 instr);
extern void LOADER_DECRYPT_DecodeBlocks(u32 *desc);

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

/* Next keystream byte: one step of the permutation, offset by the running key word. */
u8 OV230_StreamNextByte(OvStream *st)
{
    u32 x = (st->x + 1 + st->key) & 0xFF;
    u32 a = st->box[x];
    u32 y = (st->key + (a + st->y)) & 0xFF;
    u32 b = st->box[y];

    st->x = x;
    st->y = y;
    st->box[y] = a;
    st->box[x] = b;
    return st->box[(u8)(a + b)];
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

/* Seals a word buffer with a 16-byte key; the result is 0 or -1 (size not a multiple of 4). */
int OV230_SealBuffer(const u8 *key, u8 *src, u8 *dst, u32 size)
{
    OvStream st;

    OV230_StreamInit(&st, key, 16);
    return -(OV230_SealStream(&st, src, dst, size) == -1);
}

/* Opens a sealed word buffer with a 16-byte key; the result is 0 or -1 (size not a multiple of 4). */
int OV230_OpenBuffer(const u8 *key, u8 *src, u8 *dst, u32 size)
{
    OvStream st;

    OV230_StreamInit(&st, key, 16);
    return -(OV230_OpenStream(&st, src, dst, size) == -1);
}

/* hand-written in the original: initialiser entry, r0 = pc + 4 names the range table that follows (the cipher), always nonzero so the bne reaches the decoder; one filler word follows the terminator, never read */
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
    DCD     0xE8DFFE17
}
