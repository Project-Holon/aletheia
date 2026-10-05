/*
 * function: sub_0200EED8
 * address:  0x0200EED8
 * packet:   pkt_0200EE64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
#include "../include/Obj00607.h"
#include "../include/Obj00648.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void sub_0200EED8(const void *item, void *record)
{
    const u8 *src = (const u8 *)item;
    u8 *dest = (u8 *)record;

    ((struct Obj00648 *)dest)->f0 = *(const u32 *)&((struct Obj00607 *)src)->f0;
    dest[4] = src[0x7c];
    dest[5] = src[0x7d];
    dest[8] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f8;
    ((struct Obj00648 *)dest)->f10 = *(const u16 *)&((struct Obj00607 *)src)->fA;
    ((struct Obj00648 *)dest)->f12 = *(const u16 *)&((struct Obj00607 *)src)->fC;
    dest[9] = (u8)*(const u16 *)&((struct Obj00607 *)src)->fE;
    ((struct Obj00648 *)dest)->f14 = *(const u16 *)&((struct Obj00607 *)src)->f10;
    ((struct Obj00648 *)dest)->f16 = *(const u16 *)&((struct Obj00607 *)src)->f12;
    ((struct Obj00648 *)dest)->f18 = *(const u16 *)&((struct Obj00607 *)src)->f14;
    dest[0xc] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f16;
    dest[0xd] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f18;
    dest[0xe] = (u8)*(const u16 *)&((struct Obj00607 *)src)->f1A;
    ((struct Obj00648 *)dest)->f1A = *(const u16 *)&((struct Obj00607 *)src)->f20;
    ((struct Obj00648 *)dest)->f1C = *(const u16 *)&((struct Obj00607 *)src)->f22;
    ((struct Obj00648 *)dest)->f1E = *(const u16 *)&((struct Obj00607 *)src)->f24;
    dest[0xa] = (u8)*(const s16 *)&((struct Obj00607 *)src)->f2C;
    dest[0xb] = (u8)*(const s16 *)&((struct Obj00607 *)src)->f2E;
    ((struct Obj00648 *)dest)->f20 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f30;
    ((struct Obj00648 *)dest)->f22 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f32;
    ((struct Obj00648 *)dest)->f24 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f34;
    ((struct Obj00648 *)dest)->f26 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f3C;
    ((struct Obj00648 *)dest)->f28 = (u16)*(const s16 *)&((struct Obj00607 *)src)->f3E;
    ((struct Obj00648 *)dest)->f2A = (u16)*(const s16 *)&((struct Obj00607 *)src)->f40;
    ((struct Obj00648 *)dest)->f2C = *(const u32 *)&((struct Obj00607 *)src)->f48;

    MI_CpuCopy8(src + 0x94, dest + 0x30, 0x10);
    MI_CpuCopy8(src + 0xa4, dest + 0x40, 0x10);
}
