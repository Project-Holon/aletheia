/*
 * function: G3D_SYSTEM_DrawEnd
 * address:  0x02047970
 * packet:   pkt_020477D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   _G3dSystem     0x02146A5C  data
 *   func_0206DB80  0x0206DB80  arm
 *
 * Set the context's +0x94 word to one, after letting func_0206DB80 run
 * first; the context pointer is read from its slot after the call, so it is
 * a fresh `ldr` and not a saved one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/G3D_SYSTEM_DrawEnd.c \
 *       --func G3D_SYSTEM_DrawEnd --addr 0x02047970 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8  pad_00[0x94];
    u32 unk_94;
};

extern struct Ctx *_G3dSystem;
extern void func_0206DB80(void);

void G3D_SYSTEM_DrawEnd(void)
{
    func_0206DB80();
    _G3dSystem->unk_94 = 1;
}
