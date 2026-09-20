/*
 * unit:     yes
 * function: func_020113F0
 * address:  0x020113F0
 * packet:   pkt_020113F0
 * status:   EXACT
 * symbols:
 *   lbl_0209DF24 0x0209DF24 data
 *   lbl_0209DF10 0x0209DF10 data
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern const u8 lbl_0209DF24[];
extern const u8 lbl_0209DF10[];

u8 func_020113F0(int a, const u8 *b)
{
    int offset = a * 0x18;
    return *(const u8 *)((u32)lbl_0209DF24 + offset + (u32)b);
}

u8 func_02011400(int a, const u8 *b)
{
    int offset = a * 5;
    return *(const u8 *)((u32)lbl_0209DF10 + offset + (u32)b);
}
