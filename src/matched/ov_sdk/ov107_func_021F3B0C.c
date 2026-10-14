/*
 * function: MBi_IsAbleToRecv
 * address:  0x021F3B0C
 * packet:   pkt_ov107_021F3B0C
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_IsAbleToRecv (libmb.TWL.HYB.a mb_fileinfo.o)
 *
 * symbols:
 *   g_021F6D04     0x021F6D04  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef enum {
    SEG_A = 0,
    SEG_B = 1,
    SEG_C = 2
} SegType;

extern SegType g_021F6D04[3];

int MBi_IsAbleToRecv(u8 segment_no, u32 address, u32 size)
{
    SegType seg_type = g_021F6D04[segment_no];

    switch (seg_type) {
    case SEG_C:
        if (address >= 0x027FFE00 && address + size <= 0x027FFE00 + 0x160)
            return 1;
        break;
    case SEG_A:
        if (address >= 0x02000000 && address + size <= 0x022C0000)
            return 1;
        break;
    case SEG_B:
        if (address >= 0x022C0000 && address + size <= 0x02300000)
            return 1;
        if (address >= 0x02000000 && address + size <= 0x02300000)
            return 1;
        break;
    default:
        return 0;
    }
    return 0;
}
