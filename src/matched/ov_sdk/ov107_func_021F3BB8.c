/*
 * function: func_021F3BB8
 * address:  0x021F3BB8
 * packet:   pkt_ov107_021F3BB8
 * region:   ov107
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      IsAbleToLoad (libmb.TWL.HYB.a mb_fileinfo.o)
 *
 * symbols:
 *   func_021F3B0C  0x021F3B0C  arm  ov107
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
extern int func_021F3B0C(u8 segment_no, u32 address, u32 size);

int func_021F3BB8(u8 segment_no, u32 address, u32 size)
{
    SegType seg_type = g_021F6D04[segment_no];
    u32 end_adr;

    switch (seg_type) {
    case SEG_A:
    case SEG_C:
        return func_021F3B0C(segment_no, address, size);
    case SEG_B:
        if (address >= 0x02000000 && address < 0x023FE800) {
            end_adr = address + size;
            if (address < 0x02300000) {
                if (end_adr > 0x02300000)
                    return 0;
            }
            if (end_adr <= 0x02300000)
                return 1;
            if (end_adr < 0x023FE800 && size <= 0x40000)
                return 1;
            return 0;
        }
        if (address >= 0x03040000 && address < 0x03057000) {
            end_adr = address + size;
            if (end_adr <= 0x03057000)
                return 1;
            return 0;
        }
        break;
    default:
        return 0;
    }
    return 0;
}
