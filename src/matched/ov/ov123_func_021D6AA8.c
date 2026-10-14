/*
 * function: GSYNC_DISP_SetIconRecordSpecies
 * address:  0x021D6AA8
 * packet:   pkt_021D6AA8
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void GSYNC_DISP_SetIconRecordSpecies(char *p, int i, u16 v)
{
    *(u16 *)(p + i * 0x18 + 0x4104) = v;
}
