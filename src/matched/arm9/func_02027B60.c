/*
 * unit:     no
 * function: APP_TASKMENU_UpdateCursorColor
 * address:  0x02027B60
 * packet:   pkt_02027B60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask   0x02061CA4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern s16 FX_SinCosTable_[];
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);


void APP_TASKMENU_UpdateCursorColor(u16 *phase, u16 *out, u32 mode, u32 slot)
{
    s32 s;
    u8 b, r, g;

    if (*phase + 0x400 >= 0x10000) {
        *phase = (u16)(*phase - 0xfc00);
    } else {
        *phase = (u16)(*phase + 0x400);
    }

    s = (s16)((FX_SinCosTable_[2 * (*phase >> 4) + 1] + 0x1000) / 2);

    b = (u8)(((s + s * 16) >> 12) + 0xd);
    r = (u8)(((s * 7) >> 12) + 5);
    g = (u8)(((s * 15) >> 12) + 0xa);

    *out = (u16)(r | (g << 5) | (b << 10));

    if (mode <= 3) {
        NNS_GfdRegisterNewVramTransferTask((void *)0xf, slot * 32 + 0xc, (u32)out, 2);
    } else {
        NNS_GfdRegisterNewVramTransferTask((void *)0x1f, slot * 32 + 0xc, (u32)out, 2);
    }
}
