/*
 * file:     unit_021C0370.c
 * unit:     yes
 * function: func_021C0370, func_021C03C0, func_021C0440, func_021C0BB4
 * address:  0x021C0370
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
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
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef signed short s16;

extern void MI_CpuCopy(void *src, void *dst, u32 size);
extern short func_021C0440(unsigned char *src, unsigned long src_size, unsigned long cur, long *soi_addr, int option);
unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian);
unsigned long func_021C03C0(unsigned char *src, unsigned long cur, short Endian);
s16 GetAPP1(u8 *src, u32 src_size, u32 cur, long *soi_addr, int option);
long func_021C0BB4(unsigned char *src, unsigned long src_size, int *cur, int option);

static u16 SSPiSoftwareBufferSize = 0;


static u16 SSPiMakerNoteUserBufferSize = 0;


static u16 SSPiMakerNoteBufferSize = 0;


static u32 SSPiMakerNoteUserBufferAddr = 0;


static u32 SSPiMakerNoteBufferAddr = 0;


static u32 SSPiDecodeSignCheckMode = 0;


static u8 SSPiDateTime[20] = {0};


static char SSPiSoftwareBuffer[30] = {0};


unsigned short func_021C0370(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned short word;

    if (Endian == 0) {
        word = src[cur] & 0x00ff;
        word |= (src[cur + 1] << 8) & 0xff00;
    } else {
        word = (src[cur] << 8) & 0xff00;
        word |= src[cur + 1];
    }
    return word;
}


/*
 * sdk:      GetLong (exifdec.o)
 */
unsigned long func_021C03C0(unsigned char *src, unsigned long cur, short Endian)
{
    unsigned long word;

    if (Endian == 0) {
        word = src[cur];
        word |= (src[cur + 1] << 8) & 0xff00;
        word |= (src[cur + 2] << 16) & 0xff0000;
        word |= (src[cur + 3] << 24) & 0xff000000;
    } else {
        word = (src[cur] << 24) & 0xff000000;
        word |= (src[cur + 1] << 16) & 0xff0000;
        word |= (src[cur + 2] << 8) & 0xff00;
        word |= src[cur + 3];
    }
    return word;
}



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

    SSPiMakerNoteBufferAddr = 0;
    SSPiMakerNoteBufferSize = 0;
    SSPiMakerNoteUserBufferAddr = 0;
    SSPiMakerNoteUserBufferSize = 0;
    SSPiSoftwareBufferSize = 0;

    result = func_021C0440(src, src_size, c, (long *)cur, option);

    if (SSPiMakerNoteBufferAddr != 0)
        SSPiMakerNoteBufferAddr = SSPiMakerNoteBufferAddr + (unsigned long)(src + 12);
    if (SSPiMakerNoteUserBufferAddr != 0)
        SSPiMakerNoteUserBufferAddr = SSPiMakerNoteUserBufferAddr + (unsigned long)(src + 12);
    return result;
}
