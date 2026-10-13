/*
 * function: UNION_SUBDISP_SetLinePalette
 * address:  0x021F0F68
 * packet:   pkt_ov031_021F0F68
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   UNION_SUBDISP_SetLinePalette  0x021F0F68  thumb
 *   func_0204162C  0x0204162C  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0204162C(int channel);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);

int UNION_SUBDISP_SetLinePalette(void *unused, int idx, int flag)
{
    u16 *map;
    int pal;

    map = (u16 *)func_0204162C(6);
    switch ((u16)(map[idx * 0xE0] >> 12)) {
    case 0:
    case 1:
        if (flag == 0)
            pal = 0;
        else
            pal = 1;
        break;
    case 2:
    case 3:
        if (flag == 0)
            pal = 2;
        else
            pal = 3;
        break;
    default:
        return 0;
    }
    func_020413B0(6, 0, idx * 7, 0x20, 7, pal);
    func_02041B6C(6);
    return 1;
}
