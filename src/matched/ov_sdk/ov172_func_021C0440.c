/*
 * function: GetAPP1
 * address:  0x021C0440
 * packet:   pkt_ov172_021C0440
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetAPP1 (libssp exifdec.o, static)
 *
 * Parses the Exif APP1 payload at src[cur]: validates the "Exif\0\0"
 * signature, walks IFD0 for the Exif IFD pointer, DateTime (0x132) and
 * Software (0x131), follows the Exif IFD for the MakerNote (0x927c) and
 * Interoperability (0xa005) pointers, then walks the three IFDs in increasing
 * offset order, capturing the MakerNote size/offset pairs and the thumbnail
 * offset (0x201).
 *
 * lane21 (2026-10-01): closed by rewriting the body from the Debug build of
 * the same object (sdk/TwlSDK/lib/ARM9-TS/Debug/libssp.TWL.HYB.a exifdec.o),
 * whose -O0 code and line table give every statement: `cur += 2/4` after each
 * field read, `src[cur++]` signature checks, `tag` (not `type`) for the byte
 * order mark, `cur = ifd + 0xc` before each bounds check, count == 0x1c in
 * the MakerNote test, if/else for the u16 offset casts, thumb_ifd_offset in an
 * inner block, an else arm around the final return.  This body reproduces the
 * Debug object exactly at -O0 -inline off.  The last 8 B (len/tag colours and
 * the reloaded MakerNote address) closed with the exifdec.o .bss statics as
 * separate zero-initialised file statics (SSPiDecodeSignCheckMode is a layout
 * placeholder), declared in the order that reproduces the vendor offsets.
 *
 * symbols:
 *   GetWord  0x021C0370  arm   ov172
 *   GetLong  0x021C03C0  arm   ov172
 *   MI_CpuCopy     0x02082EA4  arm
 *   SSPiMakerNoteBufferSize      0x021CAD9C  data
 *   SSPiMakerNoteUserBufferSize  0x021CAD9E  data
 *   SSPiSoftwareBufferSize       0x021CADA0  data
 *   SSPiDecodeSignCheckMode      0x021CADA4  data
 *   SSPiMakerNoteUserBufferAddr  0x021CADA8  data
 *   SSPiMakerNoteBufferAddr      0x021CADAC  data
 *   SSPiDateTime                 0x021CADB0  data
 *   SSPiSoftwareBuffer           0x021CADC4  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef signed short s16;

extern u16 GetWord(u8 *src, u32 cur, s16 Endian);
extern u32 GetLong(u8 *src, u32 cur, s16 Endian);
extern void MI_CpuCopy(void *src, void *dst, u32 size);
static u16 SSPiSoftwareBufferSize = 0;
static u16 SSPiMakerNoteUserBufferSize = 0;
static u16 SSPiMakerNoteBufferSize = 0;
static u32 SSPiMakerNoteUserBufferAddr = 0;
static u32 SSPiMakerNoteBufferAddr = 0;
static u32 SSPiDecodeSignCheckMode = 0;
static u8 SSPiDateTime[20] = {0};
static char SSPiSoftwareBuffer[30] = {0};

s16 GetAPP1(u8 *src, u32 src_size, u32 cur, long *soi_addr, int option)
{
    u16 AppLen;
    u16 len;
    s16 Endian;
    u16 tag;
    u16 type;
    u32 count;
    u32 ValueOffset;
    u32 next_ifd_offset = 0xffff;
    u32 exif_ifd_offset = 0xffff;
    u32 maker_ifd_offset = 0xffff;
    u32 inter_ifd_offset = 0xffff;

    if (cur + 18 >= src_size)
        return 2;

    AppLen = GetWord(src, cur, 1);
    cur += 2;

    if (src[cur++] != 'E') return 2;
    if (src[cur++] != 'x') return 2;
    if (src[cur++] != 'i') return 2;
    if (src[cur++] != 'f') return 2;
    if (src[cur++] != 0) return 2;
    if (src[cur++] != 0) return 2;

    tag = GetWord(src, cur, 1);
    cur += 2;
    if (tag == 0x4949)
        Endian = 0;
    else if (tag == 0x4d4d)
        Endian = 1;
    else
        return 2;

    cur += 6;

    len = GetWord(src, cur, Endian);
    cur += 2;
    if (cur + len * 12 + 4 >= src_size)
        return 2;

    while (len != 0) {
        tag = GetWord(src, cur, Endian);
        cur += 2;
        type = GetWord(src, cur, Endian);
        cur += 2;
        count = GetLong(src, cur, Endian);
        cur += 4;
        ValueOffset = GetLong(src, cur, Endian);
        cur += 4;

        if (tag == 0x8769)
            exif_ifd_offset = ValueOffset;

        if (tag == 0x132) {
            if (ValueOffset + 0x20 >= src_size)
                return 2;
            MI_CpuCopy(src + (ValueOffset + 0xc), SSPiDateTime, 0x14);
        }

        if (tag == 0x131) {
            if (count > 0x1e)
                count = 0x1e;
            if (ValueOffset + 0xc + count >= src_size)
                return 2;
            MI_CpuCopy(src + (ValueOffset + 0xc), SSPiSoftwareBuffer, count);
            SSPiSoftwareBufferSize = (u16)count;
        }

        len--;
    }

    next_ifd_offset = GetLong(src, cur, Endian);
    cur += 4;

    if (next_ifd_offset == 0)
        next_ifd_offset = 0xffff;

    {
        u32 thumb_ifd_offset;

        thumb_ifd_offset = 0xffffffff;

        cur = exif_ifd_offset + 0xc;
        if (cur + 2 >= src_size)
            return 2;

        len = GetWord(src, cur, Endian);
        cur += 2;
        if (cur + len * 12 >= src_size)
            return 2;

        while (len != 0) {
            tag = GetWord(src, cur, Endian);
            cur += 2;
            type = GetWord(src, cur, Endian);
            cur += 2;
            count = GetLong(src, cur, Endian);
            cur += 4;
            ValueOffset = GetLong(src, cur, Endian);
            cur += 4;

            if (tag == 0x927c) {
                if (count > 4)
                    maker_ifd_offset = ValueOffset;
            }
            if (tag == 0xa005)
                inter_ifd_offset = ValueOffset;

            len--;
        }

        while (maker_ifd_offset != 0xffff || inter_ifd_offset != 0xffff || next_ifd_offset != 0xffff) {
            if (maker_ifd_offset < inter_ifd_offset && maker_ifd_offset < next_ifd_offset) {
                cur = maker_ifd_offset + 0xc;
                if (cur + 0xe >= src_size)
                    return 2;

                len = GetWord(src, cur, Endian);
                cur += 2;
                tag = GetWord(src, cur, Endian);
                cur += 2;
                type = GetWord(src, cur, Endian);
                cur += 2;
                count = GetLong(src, cur, Endian);
                cur += 4;
                ValueOffset = GetLong(src, cur, Endian);
                cur += 4;

                if (tag == 0x1000 && type == 7 && count == 0x1c) {
                    len--;
                    if (cur + len * 12 >= src_size)
                        return 2;

                    while (len != 0) {
                        tag = GetWord(src, cur, Endian);
                        cur += 2;
                        type = GetWord(src, cur, Endian);
                        cur += 2;
                        count = GetLong(src, cur, Endian);
                        cur += 4;
                        ValueOffset = GetLong(src, cur, Endian);
                        cur += 4;

                        if (tag == 0x1001) {
                            if (count > 4)
                                SSPiMakerNoteBufferAddr = (u16)ValueOffset;
                            else
                                SSPiMakerNoteBufferAddr = (u16)(cur - count);
                            SSPiMakerNoteBufferSize = (u16)count;
                            if (SSPiMakerNoteBufferAddr + SSPiMakerNoteBufferSize >= src_size) {
                                SSPiMakerNoteBufferAddr = 0;
                                SSPiMakerNoteBufferSize = 0;
                                return 2;
                            }
                        } else if (tag == 0x1002) {
                            if (count > 4)
                                SSPiMakerNoteUserBufferAddr = (u16)ValueOffset;
                            else
                                SSPiMakerNoteUserBufferAddr = (u16)(cur - count);
                            SSPiMakerNoteUserBufferSize = (u16)count;
                            if (SSPiMakerNoteUserBufferAddr + SSPiMakerNoteUserBufferSize >= src_size) {
                                SSPiMakerNoteUserBufferAddr = 0;
                                SSPiMakerNoteUserBufferSize = 0;
                                return 2;
                            }
                        }

                        len--;
                    }
                }
                maker_ifd_offset = 0xffff;
                continue;
            }

            if (inter_ifd_offset < maker_ifd_offset && inter_ifd_offset < next_ifd_offset) {
                cur = inter_ifd_offset + 0xc;
                if (cur + 2 >= src_size)
                    return 2;

                len = GetWord(src, cur, Endian);
                cur += 2;
                if (cur + len * 12 >= src_size)
                    return 2;

                while (len != 0) {
                    tag = GetWord(src, cur, Endian);
                    cur += 2;
                    type = GetWord(src, cur, Endian);
                    cur += 2;
                    count = GetLong(src, cur, Endian);
                    cur += 4;
                    ValueOffset = GetLong(src, cur, Endian);
                    cur += 4;

                    len--;
                }
                inter_ifd_offset = 0xffff;
                continue;
            }

            if (next_ifd_offset < maker_ifd_offset && next_ifd_offset < inter_ifd_offset) {
                cur = next_ifd_offset + 0xc;
                if (cur + 2 >= src_size)
                    return 2;

                len = GetWord(src, cur, Endian);
                cur += 2;
                if (cur + len * 12 >= src_size)
                    return 2;

                while (len != 0) {
                    tag = GetWord(src, cur, Endian);
                    cur += 2;
                    type = GetWord(src, cur, Endian);
                    cur += 2;
                    count = GetLong(src, cur, Endian);
                    cur += 4;
                    ValueOffset = GetLong(src, cur, Endian);
                    cur += 4;

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

        if (option & 1) {
            if (thumb_ifd_offset == 0xffffffff)
                return 2;
            thumb_ifd_offset += 0xc;
            *soi_addr = thumb_ifd_offset;
            return 0;
        } else {
            *soi_addr = AppLen + 4;
            return 1;
        }
    }
}
