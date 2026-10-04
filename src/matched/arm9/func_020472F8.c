/*
 * function: func_020472F8
 * address:  0x020472F8
 * packet:   pkt_02047260
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8148     0x020A8148  data
 *   func_0206A110  0x0206A110  arm
 *
 * Open one layer: ask func_0206A110 for the layer's handle (a zero handle
 * is the failure path and answers 1), then call the current handler out of
 * the function pointer at 0x020A8148 with the handle, the layer's bit
 * 0x8000 of the halfword at +0x20 and a zero, and store what it returns
 * through the caller's out pointer.
 *
 * `h != 0` is spelled as two statements, not as a comparison: the zero is
 * already live in r4 (it was r2 for the indirect call), so the failure path
 * is a predicated `moveq r0, r4` plus `popeq`, and the success path is the
 * plain `mov r0, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020472F8.c \
 *       --func func_020472F8 --addr 0x020472F8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Layer {
    u8  pad_00[0x1c];
    u16 pad_1c;
    u16 unk_1e;
    u16 unk_20;
};

extern u32 (*g_020A8148)(u32 handle, u32 flags, u32 zero);
extern int func_0206A110(int p);

int func_020472F8(struct Layer *layer, u32 *out)
{
    u32 h;

    h = func_0206A110((int)layer);
    if (h == 0)
        goto ret1;

    h = g_020A8148(h, layer->unk_20 & 0x8000, 0);
    *out = h;
    if (h == 0)
        return 0;
ret1:
    return 1;
}
