/*
 * function: func_02025C44
 * address:  0x02025C44
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02025B3C  0x02025B3C  thumb
 *   data_0209FA38  0x0209FA38  data
 *   data_0209FA3C  0x0209FA3C  data
 *
 * Blocked: data addresses 0x0209FA38 and 0x0209FA3C have no witness outside
 * the range 0x02025C44..0x02025C74.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_02025B3C(u32 key);
extern const u8 data_0209FA38[];
extern const u8 data_0209FA3C[];

u32 func_02025C44(u32 key, u32 *out1, u32 *out2)
{
    u32 index = func_02025B3C(key);
    if (index == 0) {
        return 0;
    }
    *out1 = *(const u32 *)(data_0209FA38 + index * 12);
    *out2 = *(const u8 *)(data_0209FA3C + index * 12);
    return 1;
}
