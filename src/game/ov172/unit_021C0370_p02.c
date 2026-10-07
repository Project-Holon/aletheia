/*
 * file:     unit_021C0370_p02.c
 * unit:     yes
 * function: func_021C0440, func_021C0BB4
 * address:  0x021C0440
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C0370  0x021C0370  arm   ov172
 *   func_021C03C0  0x021C03C0  arm   ov172
 *   MI_CpuCopy     0x02082EA4  arm
 *   SSPiMakerNoteBufferSize      0x021CAD9C  data
 *   SSPiMakerNoteUserBufferSize  0x021CAD9E  data
 *   SSPiSoftwareBufferSize       0x021CADA0  data
 *   SSPiDecodeSignCheckMode      0x021CADA4  data
 *   SSPiMakerNoteUserBufferAddr  0x021CADA8  data
 *   SSPiMakerNoteBufferAddr      0x021CADAC  data
 *   SSPiDateTime                 0x021CADB0  data
 *   SSPiSoftwareBuffer           0x021CADC4  data
 *   func_021C0440  0x021C0440  arm  ov172
 *   g_021CAD9C     0x021CAD9C  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef signed short s16;

struct ExifState {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    char pad[0xc - 6];
    unsigned long f0c;
    unsigned long f10;
};

extern u16 func_021C0370(u8 *src, u32 cur, s16 Endian);
extern u32 func_021C03C0(u8 *src, u32 cur, s16 Endian);
extern void MI_CpuCopy(void *src, void *dst, u32 size);
extern short func_021C0440(unsigned char *src, unsigned long src_size, unsigned long cur, long *soi_addr, int option);
s16 GetAPP1(u8 *src, u32 src_size, u32 cur, long *soi_addr, int option);
long func_021C0BB4(unsigned char *src, unsigned long src_size, int *cur, int option);
extern struct ExifState g_021CAD9C;

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

    AppLen = func_021C0370(src, cur, 1);
    cur += 2;

    if (src[cur++] != 'E') return 2;
    if (src[cur++] != 'x') return 2;
    if (src[cur++] != 'i') return 2;
    if (src[cur++] != 'f') return 2;
    if (src[cur++] != 0) return 2;
    if (src[cur++] != 0) return 2;

    tag = func_021C0370(src, cur, 1);
    cur += 2;
    if (tag == 0x4949)
        Endian = 0;
    else if (tag == 0x4d4d)
        Endian = 1;
    else
        return 2;

    cur += 6;

    len = func_021C0370(src, cur, Endian);
    cur += 2;
    if (cur + len * 12 + 4 >= src_size)
        return 2;

    while (len != 0) {
        tag = func_021C0370(src, cur, Endian);
        cur += 2;
        type = func_021C0370(src, cur, Endian);
        cur += 2;
        count = func_021C03C0(src, cur, Endian);
        cur += 4;
        ValueOffset = func_021C03C0(src, cur, Endian);
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

    next_ifd_offset = func_021C03C0(src, cur, Endian);
    cur += 4;

    if (next_ifd_offset == 0)
        next_ifd_offset = 0xffff;

    {
        u32 thumb_ifd_offset;

        thumb_ifd_offset = 0xffffffff;

        cur = exif_ifd_offset + 0xc;
        if (cur + 2 >= src_size)
            return 2;

        len = func_021C0370(src, cur, Endian);
        cur += 2;
        if (cur + len * 12 >= src_size)
            return 2;

        while (len != 0) {
            tag = func_021C0370(src, cur, Endian);
            cur += 2;
            type = func_021C0370(src, cur, Endian);
            cur += 2;
            count = func_021C03C0(src, cur, Endian);
            cur += 4;
            ValueOffset = func_021C03C0(src, cur, Endian);
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

                len = func_021C0370(src, cur, Endian);
                cur += 2;
                tag = func_021C0370(src, cur, Endian);
                cur += 2;
                type = func_021C0370(src, cur, Endian);
                cur += 2;
                count = func_021C03C0(src, cur, Endian);
                cur += 4;
                ValueOffset = func_021C03C0(src, cur, Endian);
                cur += 4;

                if (tag == 0x1000 && type == 7 && count == 0x1c) {
                    len--;
                    if (cur + len * 12 >= src_size)
                        return 2;

                    while (len != 0) {
                        tag = func_021C0370(src, cur, Endian);
                        cur += 2;
                        type = func_021C0370(src, cur, Endian);
                        cur += 2;
                        count = func_021C03C0(src, cur, Endian);
                        cur += 4;
                        ValueOffset = func_021C03C0(src, cur, Endian);
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

                len = func_021C0370(src, cur, Endian);
                cur += 2;
                if (cur + len * 12 >= src_size)
                    return 2;

                while (len != 0) {
                    tag = func_021C0370(src, cur, Endian);
                    cur += 2;
                    type = func_021C0370(src, cur, Endian);
                    cur += 2;
                    count = func_021C03C0(src, cur, Endian);
                    cur += 4;
                    ValueOffset = func_021C03C0(src, cur, Endian);
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

                len = func_021C0370(src, cur, Endian);
                cur += 2;
                if (cur + len * 12 >= src_size)
                    return 2;

                while (len != 0) {
                    tag = func_021C0370(src, cur, Endian);
                    cur += 2;
                    type = func_021C0370(src, cur, Endian);
                    cur += 2;
                    count = func_021C03C0(src, cur, Endian);
                    cur += 4;
                    ValueOffset = func_021C03C0(src, cur, Endian);
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


long func_021C0BB4(unsigned char *src, unsigned long src_size, int *cur, int option)
{
    short result;
    unsigned long c = *cur;

    g_021CAD9C.f10 = 0;
    g_021CAD9C.h0 = 0;
    g_021CAD9C.f0c = 0;
    g_021CAD9C.h2 = 0;
    g_021CAD9C.h4 = 0;

    result = func_021C0440(src, src_size, c, (long *)cur, option);

    if (g_021CAD9C.f10 != 0)
        g_021CAD9C.f10 = g_021CAD9C.f10 + (unsigned long)(src + 12);
    if (g_021CAD9C.f0c != 0)
        g_021CAD9C.f0c = g_021CAD9C.f0c + (unsigned long)(src + 12);
    return result;
}
