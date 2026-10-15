/*
 * function: TOUCHBAR_LoadCharToBg
 * address:  0x021B6738
 * packet:   pkt_ov067_021B6738
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads a character-data resource, optionally adds a3 to each of its
 * k2 * k3 u16 cells, then (when BG_SYS_GetBuf(a2) allows) copies it into
 * background a2 and loads its palette, and frees the resource.
 * The u8 stack arguments are re-read with ldrb before each call because the
 * callees take them as u8 (widths from BG_SYS_DrawTileEx.c and
 * BG_SYS_FillTileMap.c); with u32 callee parameters k4..k6 stayed in registers
 * and the frame grew (200 bytes against 192). The loop bound is the
 * expression k2 * k3 and the add is `+=` with the uncast a3: a total local,
 * k3 * k2 and `arr[i] + (u16)a3` each cost a copy or swapped the loads.
 *
 * symbols:
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *ARC_UTIL_LoadHandleMember(void *a0, u32 a1, u32 a2, u32 a3);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern u8 BG_SYS_GetField16(int channel);
extern u32 BG_SYS_GetBuf(int channel);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 a);
extern u32 func_020307B0(void *p);

void TOUCHBAR_LoadCharToBg(u32 a0, u32 a1, u32 a2, u32 a3,
                   u8 k0, u8 k1, u8 k2, u8 k3, u8 k4, u8 k5, u8 k6, u8 k7,
                   u8 k8, u32 k9, u16 k10)
{
    void *h;
    u8 *out;
    int i;
    u16 *arr;

    h = ARC_UTIL_LoadHandleMember((void *)a0, a1, k9, (u16)((k10 & 0x7fff) | 0x8000));
    NNS_G2dGetUnpackedScreenData(h, (void **)(&out));
    if (a3 != 0) {
        if (BG_SYS_GetField16((u8)a2) == 0) {
            arr = (u16 *)(out + 0xc);
            for (i = 0; i < k2 * k3; i++) {
                arr[i] += a3;
            }
        }
    }
    if ((int)BG_SYS_GetBuf((u8)a2)) {
        BG_SYS_DrawTileEx((u8)a2, k4, k5, k6, k7, (u32)(out + 0xc), k0, k1, k2, k3);
        BG_SYS_FillTileMap(a2, k4, k5, k6, k7, k8);
        func_020409B4(a2);
    }
    func_020307B0(h);
}
