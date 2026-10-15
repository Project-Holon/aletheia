/*
 * function: ZKND_TBAR_LoadCellArchive
 * address:  0x021BD574
 * packet:   pkt_ov208_021BD574
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern u8 BG_SYS_GetField16(int channel);
extern u32 BG_SYS_GetBuf(int channel);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u8 channel);
extern u32 func_020307B0(void *p);

void ZKND_TBAR_LoadCellArchive(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)ARC_UTIL_LoadHandleMember((void *)a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    NNS_G2dGetUnpackedScreenData((void *)file, (void **)(&scr));
    if (add != 0 && BG_SYS_GetField16((u8)channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if ((int)BG_SYS_GetBuf((u8)channel) != 0) {
        BG_SYS_DrawTileEx((u8)channel, x, y, w, h, (u32)scr->data, a4, a5, a6, a7);
        BG_SYS_FillTileMap(channel, x, y, w, h, pal);
        BG_SYS_PushTile(channel);
    }
    func_020307B0((void *)file);
}
