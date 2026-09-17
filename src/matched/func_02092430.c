/*
 * function: func_02092430
 * address:  0x02092430
 * packet:   pkt_02092430
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

void func_02092430(u8 *dest, u32 val, u32 count)
{
    u32 byte_val;
    u32 align;
    u32 tmp;
    u32 blocks;
    u32 words;

    byte_val = val & 0xff;
    if (count >= 0x20) {
        align = (u32)(-(s32)(u32)dest) & 3;
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
                *(u32 *)(dest + 0x00) = byte_val;
                *(u32 *)(dest + 0x04) = byte_val;
                *(u32 *)(dest + 0x08) = byte_val;
                *(u32 *)(dest + 0x0c) = byte_val;
                *(u32 *)(dest + 0x10) = byte_val;
                *(u32 *)(dest + 0x14) = byte_val;
                *(u32 *)(dest + 0x18) = byte_val;
                *(u32 *)(dest + 0x1c) = byte_val;
                dest += 0x20;
            } while (--blocks != 0);
        }

        words = (count & 0x1f) >> 2;
        if (words != 0) {
            do {
                *(u32 *)dest = byte_val;
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
