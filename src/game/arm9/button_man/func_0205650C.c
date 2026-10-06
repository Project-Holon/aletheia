/*
 * function: func_0205650C
 * address:  0x0205650C
 * packet:   pkt_02052F58
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One of the two textured-quad emitters in the table at 0x020A7FDC
 * (Rig_Hooks2 = { func_020565C8, func_0205650C }, docs/families/
 * cluster_02052F58.h).  Emits one GX_BEGIN_QUADS quad of side 0x2000 centred
 * on the two passed coordinates, texcoords (0,0) (s,0) (s,t) (0,t).
 * Plane: the second coordinate goes to the VTX_10 z field (bits 20..29).
 *
 * THE SHAPE THAT CLOSED IT (wave 8): the NitroSDK immediate-mode inlines,
 * written as static inline functions with their own parameter types --
 * G3_Begin / G3_TexCoord(fx32 s, fx32 t) / G3_Vtx10(fx16 x, fx16 y, fx16 z)
 * / G3_End -- and a VOID return.  The earlier notes (docs/notes/
 * pkt_02056460.c.txt, residues 2..10) wrote the packing inline with named
 * u16 texcoord locals and needed a u32 return to stay size-exact; that body
 * was stuck at 40/50 concrete bytes of pure register naming.  Passing each
 * coordinate through an fx16 PARAMETER (the SDK's own narrowing, then
 * (x >> 6) & 0x3ff) and each texcoord pair through G3_TexCoord's
 * (u16)(s >> 8) | (u16)(t >> 8) << 16 gives the allocator the image's value
 * order directly, and void is then size-exact too.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205650C.c \
 *       --func func_0205650C --addr 0x0205650C --arm --cc ../1.2/sp2
 */

typedef signed int s32;
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
typedef s32 fx32;
typedef s16 fx16;
#define reg_G3_BEGIN_VTXS (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS   (*(volatile u32 *)0x04000504)
#define reg_G3_TEXCOORD   (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_10     (*(volatile u32 *)0x04000490)
#define GX_FX16ToVtx10(x) ((u32)((x) >> 6) & 0x3ff)
#define GX_VECVTX10(x, y, z) ((u32)((GX_FX16ToVtx10(x) << 0) | (GX_FX16ToVtx10(y) << 10) | (GX_FX16ToVtx10(z) << 20)))
static inline void G3_Begin(u32 p) { reg_G3_BEGIN_VTXS = p; }
static inline void G3_End(void) { reg_G3_END_VTXS = 0; }
static inline void G3_TexCoord(fx32 s, fx32 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(s >> 8) | ((u32)(u16)(t >> 8) << 16);
}
static inline void G3_Vtx10(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_10 = GX_VECVTX10(x, y, z);
}

void func_0205650C(s32 s, s32 t, s32 x, s32 z)
{
    G3_Begin(1);
    G3_TexCoord(0, 0);
    G3_Vtx10((fx16)(x - 0x1000), 0, (fx16)(z + 0x1000));
    G3_TexCoord(s, 0);
    G3_Vtx10((fx16)(x + 0x1000), 0, (fx16)(z + 0x1000));
    G3_TexCoord(s, t);
    G3_Vtx10((fx16)(x + 0x1000), 0, (fx16)(z - 0x1000));
    G3_TexCoord(0, t);
    G3_Vtx10((fx16)(x - 0x1000), 0, (fx16)(z - 0x1000));
    G3_End();
}
