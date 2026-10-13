/*
 * file:     unit_0206A110.c
 * unit:     yes
 * function: NNS_G3dPlttGetRequiredSize, NNS_G3dPlttSetPlttKey, NNS_G3dPlttLoad
 * address:  0x0206A110
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
u32 NNS_G3dPlttGetRequiredSize(NNSG3dResTex *pTex);
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, u32 plttKey);
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec);


/* NNS_G3dPlttGetRequiredSize: palette block size in bytes (sizePltt is in 8-byte units). */
u32 NNS_G3dPlttGetRequiredSize(NNSG3dResTex *pTex)
{
    return pTex ? ((u32)pTex->plttInfo.sizePltt << 3) : 0;
}

/* NNS_G3dPlttSetPlttKey: store the VRAM key of the palette block. */
void NNS_G3dPlttSetPlttKey(NNSG3dResTex *pTex, u32 plttKey){ pTex->plttInfo.vramKey = plttKey; }

/*
 * NitroSystem g3d palette upload (the NNS_G3dPlttLoad shape): bracket with
 * GX_BeginLoadTexPltt / GX_EndLoadTexPltt when exec is set, upload the
 * palette block at pTex + ofsPlttData to the slot from the VRAM key, set
 * the loaded bit in plttInfo.flag.
 *
 * Lever (wave 16, declaration facts): both bracket calls take NO argument
 * (their bodies never read r0/r1); the old source passed (p, flag) and v,
 * which kept p and flag live in the swapped registers (9 bytes).  With the
 * real TwlSDK prototypes the function is EXACT.
 */
void NNS_G3dPlttLoad(NNSG3dResTex *pTex, BOOL exec)
{
    if (exec) {
        GX_BeginLoadTexPltt();
    }
    {
        u32 szByte;
        const void *pPlttData;
        u32 destSlotAddr;

        szByte       = (u32)pTex->plttInfo.sizePltt << 3;
        pPlttData    = (u8 *)pTex + pTex->plttInfo.ofsPlttData;
        destSlotAddr = (pTex->plttInfo.vramKey & 0xffff) << 3;
        GX_LoadTexPltt(pPlttData, destSlotAddr, szByte);
    }
    pTex->plttInfo.flag |= 1;
    if (exec) {
        GX_EndLoadTexPltt();
    }
}
