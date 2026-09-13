/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E938
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200E938, sub_0200E958, sub_0200E978
 *
 * symbols:
 *   _u32_div_f    0x0209C2B0  arm
 *   MI_CpuCopy8   0x02082D44  arm
 *
 * alias: three accessors on an array of 6-byte records that starts 0xa bytes
 * into the object, indexed by "id mod 10".  sub_0200E938 reads a record out,
 * sub_0200E958 stores one in, and sub_0200E978 writes a single byte field at
 * +0x10 past an extra caller-given offset from the same slot.  Each divides
 * by 10 for the remainder only; the
 * quotient the helper also returns is never used, per
 * docs/idioms/div-and-mod-are-two-calls.md and
 * docs/idioms/runtime-helper-reloc.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200E938.c \
 *       --addr 0x0200E938 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void sub_0200E938(u8 *obj, u32 id, void *dest)
{
    u32 idx = id % 10;

    MI_CpuCopy8(obj + 0xa + idx * 8, dest, 6);
}

void sub_0200E958(u8 *obj, u32 id, const void *src)
{
    u32 idx = id % 10;

    MI_CpuCopy8(src, obj + 0xa + idx * 8, 6);
}

void sub_0200E978(u8 *obj, u32 id, u32 extra, u8 value)
{
    u32 idx = id % 10;
    u8 *p = obj + idx * 8;

    p += extra;
    p[0x10] = value;
}
