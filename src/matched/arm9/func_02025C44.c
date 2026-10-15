/*
 * function: BMP_OAM_Check5C44
 * address:  0x02025C44
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209FA38 literal
 * blocker:  0209FA3C literal
 *
 * symbols:
 *   g_0209FA38  0x0209FA38  data
 *   g_0209FA3C  0x0209FA3C  data
 *   BMP_OAM_GetRecordIndex  0x02025B3C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32 BMP_OAM_GetRecordIndex(u32 a0);
extern u8  g_0209FA38[];
extern u8  g_0209FA3C[];

int BMP_OAM_Check5C44(u32 a0, u32 *a1, u32 *a2)
{
    u32 i = BMP_OAM_GetRecordIndex(a0);
    u32 off;

    if (i == 0) {
        return 0;
    }
    off = i * 12;
    *a1 = *(u32 *)(g_0209FA38 + off);
    *a2 = g_0209FA3C[off];
    return 1;
}
