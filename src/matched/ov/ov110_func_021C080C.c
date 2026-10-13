/*
 * function: PMS_SELECT_GRAPHIC_ColorRowBg
 * address: 0x021C080C
 * packet: pkt_ov110_021C080C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u32);
void PMS_SELECT_GRAPHIC_ColorRowBg(char *p, u8 idx, u32 pal, int flag)
{
    int i;
    int n;
    u16 *hdr = *(u16 **)(p + 8);
    u16 *data;
    u32 w;
    u32 h;
    w = (u32)hdr[0] >> 3;
    h = (u32)hdr[1] >> 3;
    data = hdr + 6;
    if (flag)
        pal = 5;
    n = w * h;
    for (i = 0; i < n; i++)
    {
        u32 v = data[i] & 0xFFF;
        data[i] = v + ((pal + 2) << 12);
    }
    func_020410D0(2, 0, (u8)(idx * 6 + 1), (u8)w, 6, (u32)(*(u8 **)(p + 8) + 12), 0, 0, (u8)w, (u8)h);
    func_02041B6C(2);
}
