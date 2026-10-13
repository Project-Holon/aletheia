/*
 * function: G3D_SYSTEM_SwapBuffersMain
 * address:  0x02047990
 * packet:   pkt_02047990
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The 3D buffer-swap flush, called once per frame from NitroMain (blx at
 * 0x02005176).  When the swap requested by func_02047970 is pending (+0x94
 * set to 1), it writes G3_SWAP_BUFFERS with the sort mode (+0x80) and the
 * buffer mode (+0x84) and clears the request.  The listing carried it as raw
 * words until NitroMain was seeded in layout/function_starts.txt.
 *
 * symbols:
 *   _G3dSystem  0x02146A5C  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

#define reg_G3_SWAP_BUFFERS (*(volatile u32 *)0x04000540)

struct Ctx {
    u8  pad_00[0x80];
    u32 sortMode;      /* G3_SwapBuffers am */
    u32 bufferMode;    /* G3_SwapBuffers zw */
    u8  pad_88[0x94 - 0x88];
    u32 unk_94;
};

extern struct Ctx *_G3dSystem;

void G3D_SYSTEM_SwapBuffersMain(void)
{
    struct Ctx *c = _G3dSystem;

    if (c == 0)
        return;
    if (c->unk_94 != 1)
        return;
    reg_G3_SWAP_BUFFERS = (c->bufferMode << 1) | c->sortMode;
    _G3dSystem->unk_94 = 0;
}
