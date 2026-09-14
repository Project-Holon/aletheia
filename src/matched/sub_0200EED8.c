/*
 * function: sub_0200EED8
 * address:  0x0200EED8
 * packet:   pkt_0200EE64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * A field-by-field marshal from a source record into a differently laid
 * out destination record: several 16-bit source fields narrow to 8-bit
 * destination fields, several signed-halfword source fields (loaded with
 * ldrsh, register-offset addressing being Thumb's only encoding for a
 * signed halfword load, see docs/idioms/ldrsh-register-offset-is-signedness.md)
 * widen back into unsigned destination halfwords, and the tail of the
 * record is two flat 0x10-byte blocks copied with MI_CpuCopy8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200EED8.c \
 *       --func sub_0200EED8 --addr 0x0200EED8 --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void sub_0200EED8(const void *item, void *record)
{
    const u8 *src = (const u8 *)item;
    u8 *dest = (u8 *)record;

    *(u32 *)(dest + 0) = *(const u32 *)(src + 0);
    dest[4] = src[0x7c];
    dest[5] = src[0x7d];
    dest[8] = (u8)*(const u16 *)(src + 0x8);
    *(u16 *)(dest + 0x10) = *(const u16 *)(src + 0xa);
    *(u16 *)(dest + 0x12) = *(const u16 *)(src + 0xc);
    dest[9] = (u8)*(const u16 *)(src + 0xe);
    *(u16 *)(dest + 0x14) = *(const u16 *)(src + 0x10);
    *(u16 *)(dest + 0x16) = *(const u16 *)(src + 0x12);
    *(u16 *)(dest + 0x18) = *(const u16 *)(src + 0x14);
    dest[0xc] = (u8)*(const u16 *)(src + 0x16);
    dest[0xd] = (u8)*(const u16 *)(src + 0x18);
    dest[0xe] = (u8)*(const u16 *)(src + 0x1a);
    *(u16 *)(dest + 0x1a) = *(const u16 *)(src + 0x20);
    *(u16 *)(dest + 0x1c) = *(const u16 *)(src + 0x22);
    *(u16 *)(dest + 0x1e) = *(const u16 *)(src + 0x24);
    dest[0xa] = (u8)*(const s16 *)(src + 0x2c);
    dest[0xb] = (u8)*(const s16 *)(src + 0x2e);
    *(u16 *)(dest + 0x20) = (u16)*(const s16 *)(src + 0x30);
    *(u16 *)(dest + 0x22) = (u16)*(const s16 *)(src + 0x32);
    *(u16 *)(dest + 0x24) = (u16)*(const s16 *)(src + 0x34);
    *(u16 *)(dest + 0x26) = (u16)*(const s16 *)(src + 0x3c);
    *(u16 *)(dest + 0x28) = (u16)*(const s16 *)(src + 0x3e);
    *(u16 *)(dest + 0x2a) = (u16)*(const s16 *)(src + 0x40);
    *(u32 *)(dest + 0x2c) = *(const u32 *)(src + 0x48);

    MI_CpuCopy8(src + 0x94, dest + 0x30, 0x10);
    MI_CpuCopy8(src + 0xa4, dest + 0x40, 0x10);
}
