/*
 * file:     msl_string_mem.c
 * unit:     yes
 * function: memcpy, memmove, MSL_C_LIB_MemsetPtr, memchr, memcmp, __fill_mem
 * address:  0x02092344
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from msl_c_lib.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "msl_crt_shared_types.h"

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u32 w5;
    u32 w6;
    u32 w7;
} MslMemsetBlock;

void *memcpy(void *dest, const void *src, size_t n);

void *memmove(void *dest, const void *src, size_t n);

void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n);

u8 *memchr(u8 *s, u32 c, u32 n);

int memcmp(const u8 *s1, const u8 *s2, u32 n);

void __fill_mem(u8 *dest, u32 val, u32 count);

/*
 * A whole translation unit, matched as one byte range.
 *
 * Byte-wise memcpy (memcpy) and memmove (memmove).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02092344.c \
 *       --addr 0x02092344 --arm
 */
void *memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;

    if (n == 0) {
        return dest;
    }

    do {
        *d++ = *s++;
    } while (--n != 0);

    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    if ((const unsigned char *)src >= (unsigned char *)dest) {
        unsigned char *d = (unsigned char *)dest;
        const unsigned char *s = (const unsigned char *)src;

        if (n == 0) {
            return dest;
        }

        do {
            *d++ = *s++;
        } while (--n != 0);

        return dest;
    } else {
        const unsigned char *s = (const unsigned char *)src + n;
        unsigned char *d = (unsigned char *)dest + n;

        if (n == 0) {
            return dest;
        }

        do {
            *--d = *--s;
        } while (--n != 0);

        return dest;
    }
}

/*
 * String / memory utilities:
 *   MSL_C_LIB_MemsetPtr (20 B)  wraps __fill_mem (memset) and returns ptr
 *   memchr (44 B)  memchr (byte search)
 *   memcmp (64 B)  memcmp (memory comparison)
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020923B0.c \
 *       --addr 0x020923B0
 */
void *MSL_C_LIB_MemsetPtr(void *dest, int c, u32 n)
{
    __fill_mem(dest, c, n);
    return dest;
}

u8 *memchr(u8 *s, u32 c, u32 n)
{
    u8 val = (u8)c;

    if (n != 0) {
        do {
            if (*s++ == val) {
                return s - 1;
            }
        } while (--n != 0);
    }
    return 0;
}

int memcmp(const u8 *s1, const u8 *s2, u32 n)
{
    u8 b1;
    u8 b2;

    if (n != 0) {
        do {
            b1 = *s1++;
            b2 = *s2++;
            if (b1 != b2) {
                b1 = *(s1 - 1);
                b2 = *(s2 - 1);
                return (b1 < b2) ? -1 : 1;
            }
        } while (--n != 0);
    }
    return 0;
}

void __fill_mem(u8 *dest, u32 val, u32 count)
{
    u32 byte_val;
    u32 align;
    u32 tmp;
    u32 blocks;
    u32 words;

    byte_val = val & 0xff;
    if (count >= 0x20) {
        align = (u32)(-(int)(u32)dest) & 3;
        if (align != 0) {
            count -= align;
            do {
                *dest++ = (u8)byte_val;
            } while (--align != 0);
        }

        if (byte_val != 0) {
            tmp = byte_val << 8;
            tmp |= (byte_val << 24) | (byte_val << 16);
            byte_val |= tmp;
        }

        blocks = count >> 5;
        if (blocks != 0) {
            do {
                ((MslMemsetBlock *)dest)->w0 = byte_val;
                ((MslMemsetBlock *)dest)->w1 = byte_val;
                ((MslMemsetBlock *)dest)->w2 = byte_val;
                ((MslMemsetBlock *)dest)->w3 = byte_val;
                ((MslMemsetBlock *)dest)->w4 = byte_val;
                ((MslMemsetBlock *)dest)->w5 = byte_val;
                ((MslMemsetBlock *)dest)->w6 = byte_val;
                ((MslMemsetBlock *)dest)->w7 = byte_val;
                dest += 0x20;
            } while (--blocks != 0);
        }

        words = (count & 0x1f) >> 2;
        if (words != 0) {
            do {
                ((MslMemsetBlock *)dest)->w0 = byte_val;
                dest += 4;
            } while (--words != 0);
        }

        count &= 3;
    }

    if (count != 0) {
        do {
            *dest++ = (u8)byte_val;
        } while (--count != 0);
    }
}
