/*
 * function: BTL_MAIN_GetPosTable
 * address:  0x021B99E0
 * packet:   pkt_ov093_021B99E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021EFD70  0x021EFD70  data  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021EFD70 { u8 b[10]; };
extern struct Unk021EFD70 data_021EFD70[];

struct Unk021EFD70 *BTL_MAIN_GetPosTable(int i)
{
    return &data_021EFD70[i];
}
