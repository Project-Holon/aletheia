/*
 * function: NNS_G3dPlttLoad
 * address:  0x0206A12C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * NitroSystem g3d palette upload (the NNS_G3dPlttLoad shape): bracket with
 * GX_BeginLoadTexPltt / GX_EndLoadTexPltt when exec is set, upload the
 * palette block at pTex + ofsPlttData to the slot from the VRAM key, set
 * the loaded bit in plttInfo.flag.
 *
 * Lever (wave 16, declaration facts): both bracket calls take NO argument
 * (their bodies never read r0/r1); the old source passed (p, flag) and v,
 * which kept p and flag live in the swapped registers (9 bytes).  With the
 * real TwlSDK prototypes the function is EXACT.
 *
 * symbols:
 *   GX_BeginLoadTexPltt  0x0207FA0C  arm
 *   GX_LoadTexPltt       0x0207FA40  arm
 *   GX_EndLoadTexPltt    0x0207FADC  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            BOOL;

typedef struct {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} NNSG3dResPlttInfo;

typedef struct {
    u8 header[0x2c];
    NNSG3dResPlttInfo plttInfo;
} NNSG3dResTex;

extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(const void *pSrc, u32 destSlotAddr, u32 szByte);
extern void GX_EndLoadTexPltt(void);
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec)
{
    if (exec) {
        GX_BeginLoadTexPltt();
    }
    {
        u32 sz;
        const void *pData;
        u32 from;

        sz    = (u32)pTex->plttInfo.sizePltt << 3;
        pData = (u8 *)pTex + pTex->plttInfo.ofsPlttData;
        from  = (pTex->plttInfo.vramKey & 0xffff) << 3;
        GX_LoadTexPltt(pData, from, sz);
    }
    pTex->plttInfo.flag |= 1;
    if (exec) {
        GX_EndLoadTexPltt();
    }
}
