/*
 * function: GetAPP1
 * address:  0x021C0440
 * packet:   pkt_ov172_021C0440
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF   (parked; not EXACT/MATCH)
 *
 * sdk:      GetAPP1 (libssp exifdec.o, static)
 *
 * BLOCKER (codegen + evidence): dsi/1.1p1 builds this at 1924 bytes against
 * the 1908-byte object, with 1294 concrete bytes differing -- register
 * allocation and stack-slot order diverge early (cur lands in r4 instead of
 * r8, and the extra `w` temporary widens the frame to 0x28).  Even if the
 * body were brought byte-for-byte into codegen agreement it could not pass
 * EXACT: the two ABS32 sites g_021CADB0 (SSPiDateTime) and g_021CADC4
 * (SSPiSoftwareBuffer) have no witness anywhere outside 021C0440..021C0BC4,
 * so 35 of 37 relocations resolve and the best verdict is MATCH.  GetLong
 * (0x021C03C0) is already EXACT; GetWord (0x021C0370) resolves as sole-ref
 * code today.
 *
 * Reconstructed from the DWARF of the defining object (param/local names and
 * registers) plus the object disassembly.  Parses the Exif APP1 payload at
 * src[cur]: validates the "Exif\0\0" signature, walks IFD0 for the Exif IFD
 * pointer, DateTime (0x132) and Software (0x131) tags, then follows the Exif
 * IFD for the MakerNote (0x927c) and Interoperability (0xa005) pointers, and
 * finally walks the three IFDs in increasing offset order, capturing the
 * MakerNote size/offset pair and the thumbnail offset (0x201).
 *
 * symbols:
 *   func_021C0370  0x021C0370  arm   ov172
 *   func_021C03C0  0x021C03C0  arm   ov172
 *   MI_CpuCopy     0x02082EA4  arm
 *   g_021CAD9C     0x021CAD9C  data
 *   g_021CADB0     0x021CADB0  data
 *   g_021CADC4     0x021CADC4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed short s16;

struct ExifState {
    u16 h0;
    u16 h2;
    u16 h4;
    char pad[0xc - 6];
    u32 f0c;
    u32 f10;
};

extern u16 func_021C0370(u8 *src, u32 cur, s16 Endian);
extern u32 func_021C03C0(u8 *src, u32 cur, s16 Endian);
extern void MI_CpuCopy(void *src, void *dst, u32 size);
extern struct ExifState g_021CAD9C;
extern u8 g_021CADB0[20];
extern char g_021CADC4[30];

s16 GetAPP1(u8 *src, u32 src_size, u32 cur, long *soi_addr, int option)
{
    u32 exif_ifd_offset = 0xffff;
    u32 inter_ifd_offset = 0xffff;
    u32 maker_ifd_offset = 0xffff;
    u32 next_ifd_offset;
    u32 thumb_ifd_offset;
    u32 count;
    u32 ValueOffset;
    u32 p;
    u32 w;
    u16 tag;
    u16 type;
    u16 AppLen;
    u16 len;
    s16 Endian;

    if (cur + 18 >= src_size)
        return 2;

    Endian = 1;
    AppLen = func_021C0370(src, cur, 1);

    if (src[cur + 2] != 'E') return 2;
    if (src[cur + 3] != 'x') return 2;
    if (src[cur + 4] != 'i') return 2;
    if (src[cur + 5] != 'f') return 2;
    if (src[cur + 6] != 0) return 2;
    if (src[cur + 7] != 0) return 2;

    type = func_021C0370(src, cur + 8, Endian);
    if (type == 0x4949) {
        Endian = 0;
    } else if (type != 0x4d4d) {
        return 2;
    }

    len = func_021C0370(src, cur + 0x10, Endian);
    p = cur + 0x12;
    if ((u32)len * 12 + p + 4 >= src_size)
        return 2;

    while (len != 0) {
        tag = func_021C0370(src, p, Endian);
        type = func_021C0370(src, p + 2, Endian);
        count = func_021C03C0(src, p + 4, Endian);
        ValueOffset = func_021C03C0(src, p + 8, Endian);
        p += 12;

        if (tag == 0x8769)
            exif_ifd_offset = ValueOffset;

        if (tag == 0x132) {
            if (ValueOffset + 0x20 >= src_size)
                return 2;
            MI_CpuCopy(src + ValueOffset + 0xc, g_021CADB0, 0x14);
        }

        if (tag == 0x131) {
            if (count > 0x1e)
                count = 0x1e;
            if (ValueOffset + 0xc + count >= src_size)
                return 2;
            MI_CpuCopy(src + ValueOffset + 0xc, g_021CADC4, count);
            g_021CAD9C.h4 = count;
        }

        len--;
    }

    next_ifd_offset = func_021C03C0(src, p, Endian);
    if (next_ifd_offset == 0)
        next_ifd_offset = 0xffff;

    if (exif_ifd_offset + 0xe >= src_size)
        return 2;

    thumb_ifd_offset = 0xffffffff;

    len = func_021C0370(src, exif_ifd_offset + 0xc, Endian);
    p = exif_ifd_offset + 0xe;
    if ((u32)len * 12 + p >= src_size)
        return 2;

    while (len != 0) {
        tag = func_021C0370(src, p, Endian);
        type = func_021C0370(src, p + 2, Endian);
        count = func_021C03C0(src, p + 4, Endian);
        ValueOffset = func_021C03C0(src, p + 8, Endian);
        p += 12;

        if (tag == 0x927c) {
            if (count > 4)
                maker_ifd_offset = ValueOffset;
        }
        if (tag == 0xa005)
            inter_ifd_offset = ValueOffset;

        len--;
    }

    for (;;) {
        if (maker_ifd_offset == 0xffff && inter_ifd_offset == 0xffff &&
            next_ifd_offset == 0xffff) {
            if (option & 1) {
                if (thumb_ifd_offset == 0xffffffff)
                    return 2;
                *soi_addr = thumb_ifd_offset + 0xc;
                return 0;
            }
            *soi_addr = AppLen + 4;
            return 1;
        }

        if (maker_ifd_offset < inter_ifd_offset &&
            maker_ifd_offset < next_ifd_offset) {
            if (maker_ifd_offset + 0x1a >= src_size)
                return 2;

            len = func_021C0370(src, maker_ifd_offset + 0xc, Endian);
            tag = func_021C0370(src, maker_ifd_offset + 0xe, Endian);
            type = func_021C0370(src, maker_ifd_offset + 0x10, Endian);
            ValueOffset = func_021C03C0(src, maker_ifd_offset + 0x12, Endian);
            count = func_021C03C0(src, maker_ifd_offset + 0x16, Endian);
            p = maker_ifd_offset + 0x1a;

            if (tag != 0x1000 || type != 7 || ValueOffset != 0x1c) {
                maker_ifd_offset = 0xffff;
                continue;
            }

            len = len - 1;
            if ((u32)len * 12 + p >= src_size)
                return 2;
            if (len == 0) {
                maker_ifd_offset = 0xffff;
                continue;
            }

            while (len != 0) {
                tag = func_021C0370(src, p, Endian);
                type = func_021C0370(src, p + 2, Endian);
                count = func_021C03C0(src, p + 4, Endian);
                ValueOffset = func_021C03C0(src, p + 8, Endian);
                p += 12;

                if (tag == 0x1001) {
                    if (count <= 4)
                        w = p - count;
                    else
                        w = ValueOffset;
                    w &= 0xffff;
                    g_021CAD9C.f10 = w;
                    g_021CAD9C.h0 = count;
                    if (g_021CAD9C.h0 + g_021CAD9C.f10 >= src_size) {
                        g_021CAD9C.f10 = 0;
                        g_021CAD9C.h0 = 0;
                        return 2;
                    }
                } else if (tag == 0x1002) {
                    if (count <= 4)
                        w = p - count;
                    else
                        w = ValueOffset;
                    w &= 0xffff;
                    g_021CAD9C.f0c = w;
                    g_021CAD9C.h2 = count;
                    if (g_021CAD9C.h2 + g_021CAD9C.f0c >= src_size) {
                        g_021CAD9C.f0c = 0;
                        g_021CAD9C.h2 = 0;
                        return 2;
                    }
                }

                len--;
            }

            maker_ifd_offset = 0xffff;
            continue;
        }

        if (inter_ifd_offset < maker_ifd_offset &&
            inter_ifd_offset < next_ifd_offset) {
            if (inter_ifd_offset + 0xe >= src_size)
                return 2;

            len = func_021C0370(src, inter_ifd_offset + 0xc, Endian);
            p = inter_ifd_offset + 0xe;
            if ((u32)len * 12 + p >= src_size)
                return 2;

            while (len != 0) {
                tag = func_021C0370(src, p, Endian);
                type = func_021C0370(src, p + 2, Endian);
                count = func_021C03C0(src, p + 4, Endian);
                ValueOffset = func_021C03C0(src, p + 8, Endian);
                p += 12;
                len--;
            }

            inter_ifd_offset = 0xffff;
            continue;
        }

        if (next_ifd_offset < maker_ifd_offset &&
            next_ifd_offset < inter_ifd_offset) {
            if (next_ifd_offset + 0xe >= src_size)
                return 2;

            len = func_021C0370(src, next_ifd_offset + 0xc, Endian);
            p = next_ifd_offset + 0xe;
            if ((u32)len * 12 + p >= src_size)
                return 2;

            while (len != 0) {
                tag = func_021C0370(src, p, Endian);
                type = func_021C0370(src, p + 2, Endian);
                count = func_021C03C0(src, p + 4, Endian);
                ValueOffset = func_021C03C0(src, p + 8, Endian);
                p += 12;
                if (tag == 0x201) {
                    thumb_ifd_offset = ValueOffset;
                    break;
                }
                len--;
            }

            next_ifd_offset = 0xffff;
            continue;
        }

        return 2;
    }
}
