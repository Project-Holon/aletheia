/*
 * file:     gx_vramcnt.c
 * unit:     yes
 * function: func_0207FD34, func_0207FDCC, GX_SetBankForOBJ, GX_SetBankForBGExtPltt, GX_SetBankForOBJExtPltt, GX_SetBankForTex, GX_SetBankForTexPltt, GX_SetBankForClearImage, GX_SetBankForARM7, func_0208068C, GX_SetBankForSubBG, GX_SetBankForSubOBJ, GX_SetBankForSubBGExtPltt, GX_SetBankForSubOBJExtPltt, resetBankForX_, GX_ResetBankForBG, GX_ResetBankForOBJ, func_0208091C, func_02080940, GX_ResetBankForTex, GX_ResetBankForTexPltt, GX_ResetBankForClearImage, GX_ResetBankForSubBG, GX_ResetBankForSubOBJ, func_020809C8, func_020809F0, disableBankForX_, GX_DisableBankForBG, GX_DisableBankForOBJ, GX_DisableBankForBGExtPltt, GX_DisableBankForOBJExtPltt, GX_DisableBankForTex, GX_DisableBankForTexPltt, GX_DisableBankForClearImage, GX_DisableBankForARM7, GX_DisableBankForLCDC, GX_DisableBankForSubBG, GX_DisableBankForSubOBJ, GX_DisableBankForSubBGExtPltt, GX_DisableBankForSubOBJExtPltt, GX_GetBankForOBJ, GX_GetBankForOBJExtPltt, GX_GetBankForTex, GX_GetBankForLCDC, GX_GetBankForSubOBJ, GX_GetBankForSubOBJExtPltt
 * address:  0x0207FD34
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
 *   gGXState             0x02150E4C  data
 *   g_02150E4C 0x02150E4C data
 *   func_0207FD34 0x0207FD34 arm
 *   g_02150E5A 0x02150E5A data
 *   g_02150E5C 0x02150E5C data
 *   g_02150E62 0x02150E62 data
 *   g_02150E64 0x02150E64 data
 *   OSi_UnlockVram    0x02087EDC  arm
 *   GXi_VRamLockId    0x02150E0E  data
 *   disableBankForX_   0x02080A18  arm
 */
#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)
#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)
#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)
#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)
#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)
#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)
#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)
#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)
#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)
#define VRAMCNT_LCDC 0x80
#define VRAMCNT_BG(ofs) (0x80 | 1 | ((ofs) << 3))
#define VRAMCNT_OBJ(ofs) (0x80 | 2 | ((ofs) << 3))
#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)
#define REG_G3X_DISP3DCNT_TME_MASK 0x0001
#define REG_G3X_DISP3DCNT_RO_MASK  0x3000
#define VRAMCNT_TEX(ofs) (0x80 | 3 | ((ofs) << 3))
typedef unsigned char u8;

typedef volatile u8 vu8;

typedef unsigned short u16;

typedef enum {
    GX_VRAM_BG_NONE = 0x00,
    GX_VRAM_BG_16_F = 0x20,
    GX_VRAM_BG_16_G = 0x40,
    GX_VRAM_BG_32_FG = 0x60,
    GX_VRAM_BG_64_E = 0x10,
    GX_VRAM_BG_80_EF = 0x30,
    GX_VRAM_BG_80_EG = 0x50,
    GX_VRAM_BG_96_EFG = 0x70,
    GX_VRAM_BG_128_A = 0x01,
    GX_VRAM_BG_128_B = 0x02,
    GX_VRAM_BG_128_C = 0x04,
    GX_VRAM_BG_128_D = 0x08,
    GX_VRAM_BG_256_AB = 0x03,
    GX_VRAM_BG_256_BC = 0x06,
    GX_VRAM_BG_256_CD = 0x0c,
    GX_VRAM_BG_384_ABC = 0x07,
    GX_VRAM_BG_384_BCD = 0x0e,
    GX_VRAM_BG_512_ABCD = 0x0f,
    GX_VRAM_BG_256_AC = 0x05,
    GX_VRAM_BG_256_AD = 0x09,
    GX_VRAM_BG_256_BD = 0x0a,
    GX_VRAM_BG_384_ABD = 0x0b,
    GX_VRAM_BG_384_ACD = 0x0d
} GXVRamBG;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt;

typedef struct {
    GX_VRAMCnt vramCnt;
} GX_State;

typedef enum {
    GX_VRAM_OBJ_NONE = 0x00,
    GX_VRAM_OBJ_16_F = 0x20,
    GX_VRAM_OBJ_16_G = 0x40,
    GX_VRAM_OBJ_32_FG = 0x60,
    GX_VRAM_OBJ_64_E = 0x10,
    GX_VRAM_OBJ_80_EF = 0x30,
    GX_VRAM_OBJ_80_EG = 0x50,
    GX_VRAM_OBJ_96_EFG = 0x70,
    GX_VRAM_OBJ_128_A = 0x01,
    GX_VRAM_OBJ_128_B = 0x02,
    GX_VRAM_OBJ_256_AB = 0x03
} GXVRamOBJ;

typedef long fx32;

typedef short fx16;

typedef unsigned long u32;

typedef volatile u16 vu16;

typedef volatile u32 vu32;

typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef enum {
    GX_VRAM_NONE = 0x0000,
    GX_VRAM_A = 0x0001,
    GX_VRAM_B = 0x0002,
    GX_VRAM_C = 0x0004,
    GX_VRAM_D = 0x0008,
    GX_VRAM_E = 0x0010,
    GX_VRAM_F = 0x0020,
    GX_VRAM_G = 0x0040,
    GX_VRAM_H = 0x0080,
    GX_VRAM_I = 0x0100
} GXVRam;

typedef enum {
    GX_VRAM_TEX_NONE = 0x00,
    GX_VRAM_TEX_0_A = 0x01,
    GX_VRAM_TEX_0_B = 0x02,
    GX_VRAM_TEX_0_C = 0x04,
    GX_VRAM_TEX_0_D = 0x08,
    GX_VRAM_TEX_01_AB = 0x03,
    GX_VRAM_TEX_012_ABC = 0x07,
    GX_VRAM_TEX_0123_ABCD = 0x0f,
    GX_VRAM_TEX_01_BC = 0x06,
    GX_VRAM_TEX_012_BCD = 0x0e,
    GX_VRAM_TEX_01_CD = 0x0c,
    GX_VRAM_TEX_01_AC = 0x05,
    GX_VRAM_TEX_01_AD = 0x09,
    GX_VRAM_TEX_01_BD = 0x0a,
    GX_VRAM_TEX_012_ABD = 0x0b,
    GX_VRAM_TEX_012_ACD = 0x0d
} GXVRamTex;

extern void g_02150E4C(void);
extern void func_0207FD34(void);
extern void OSi_UnlockVram(u16 bank, u16 lockId);
extern int disableBankForX_(u16 *g3bit);
void GX_SetBankForBG(GXVRamBG bg);
void GX_SetBankForOBJ(GXVRamOBJ obj);
void GX_SetBankForBGExtPltt(int bgExtPltt);
void GX_SetBankForOBJExtPltt(int objExtPltt);
void GX_SetBankForTex(GXVRamTex tex);
void GX_SetBankForTexPltt(int texPltt);
void GX_SetBankForClearImage(int clrImg);
void GX_SetBankForARM7(int arm7);
asm void GX_SetBankForLCDC(void);
void GX_SetBankForSubBG(int sub_bg);
void GX_SetBankForSubOBJ(int sub_obj);
void GX_SetBankForSubBGExtPltt(int sub_bgExtPltt);
void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt);
int resetBankForX_(u16 *g3bit);
int GX_ResetBankForBG(void);
void GX_ResetBankForOBJ(void);
void GX_ResetBankForBGExtPltt(void);
void GX_ResetBankForOBJExtPltt(void);
int GX_ResetBankForTex(void);
void GX_ResetBankForTexPltt(void);
void GX_ResetBankForClearImage(int a0, int a1, int a2, int a3);
int GX_ResetBankForSubBG(void);
void GX_ResetBankForSubOBJ(void);
void GX_ResetBankForSubBGExtPltt(void);
void GX_ResetBankForSubOBJExtPltt(void);
GXVRam GX_DisableBankForBG(void);
GXVRam GX_DisableBankForOBJ(void);
GXVRam GX_DisableBankForBGExtPltt(void);
GXVRam GX_DisableBankForOBJExtPltt(void);
GXVRam GX_DisableBankForTex(void);
GXVRam GX_DisableBankForTexPltt(void);
GXVRam GX_DisableBankForClearImage(void);
GXVRam GX_DisableBankForARM7(void);
void GX_DisableBankForLCDC(void);
void GX_DisableBankForSubBG(int a0, int a1, int a2, int a3);
void GX_DisableBankForSubOBJ(int a0, int a1, int a2, int a3);
GXVRam GX_DisableBankForSubBGExtPltt(void);
GXVRam GX_DisableBankForSubOBJExtPltt(void);
u16 GX_GetBankForOBJ(void);
u16 GX_GetBankForOBJExtPltt(void);
u16 GX_GetBankForTex(void);
u16 GX_GetBankForLCDC(void);
u16 GX_GetBankForSubOBJ(void);
u16 GX_GetBankForSubOBJExtPltt(void);
extern GX_State gGXState;
extern u16 GXi_VRamLockId;







static void GX_VRAMCNT_SetLCDC_(int lcdc)
{
    if (lcdc & 0x001) {
        reg_GX_VRAMCNT_A = VRAMCNT_LCDC;
    }
    if (lcdc & 0x002) {
        reg_GX_VRAMCNT_B = VRAMCNT_LCDC;
    }
    if (lcdc & 0x004) {
        reg_GX_VRAMCNT_C = VRAMCNT_LCDC;
    }
    if (lcdc & 0x008) {
        reg_GX_VRAMCNT_D = VRAMCNT_LCDC;
    }
    if (lcdc & 0x010) {
        reg_GX_VRAMCNT_E = VRAMCNT_LCDC;
    }
    if (lcdc & 0x020) {
        reg_GX_VRAMCNT_F = VRAMCNT_LCDC;
    }
    if (lcdc & 0x040) {
        reg_GX_VRAMCNT_G = VRAMCNT_LCDC;
    }
    if (lcdc & 0x080) {
        reg_GX_VRAMCNT_H = VRAMCNT_LCDC;
    }
    if (lcdc & 0x100) {
        reg_GX_VRAMCNT_I = VRAMCNT_LCDC;
    }
}







void GX_SetBankForBG(GXVRamBG bg)
{
    gGXState.vramCnt.lcdc = (u16)(~bg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.bg));
    gGXState.vramCnt.bg = (u16)bg;

    switch (bg) {
    case GX_VRAM_BG_128_D:
        reg_GX_VRAMCNT_D = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_256_CD:
        reg_GX_VRAMCNT_D = VRAMCNT_BG(1);
    case GX_VRAM_BG_128_C:
        reg_GX_VRAMCNT_C = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_384_BCD:
        reg_GX_VRAMCNT_D = VRAMCNT_BG(2);
    case GX_VRAM_BG_256_BC:
        reg_GX_VRAMCNT_C = VRAMCNT_BG(1);
    case GX_VRAM_BG_128_B:
        reg_GX_VRAMCNT_B = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_512_ABCD:
        reg_GX_VRAMCNT_D = VRAMCNT_BG(3);
    case GX_VRAM_BG_384_ABC:
        reg_GX_VRAMCNT_C = VRAMCNT_BG(2);
    case GX_VRAM_BG_256_AB:
        reg_GX_VRAMCNT_B = VRAMCNT_BG(1);
    case GX_VRAM_BG_128_A:
        reg_GX_VRAMCNT_A = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_384_ABD:
        reg_GX_VRAMCNT_A = VRAMCNT_BG(0);
        reg_GX_VRAMCNT_B = VRAMCNT_BG(1);
        reg_GX_VRAMCNT_D = VRAMCNT_BG(2);
        break;
    case GX_VRAM_BG_384_ACD:
        reg_GX_VRAMCNT_D = VRAMCNT_BG(2);
    case GX_VRAM_BG_256_AC:
        reg_GX_VRAMCNT_A = VRAMCNT_BG(0);
        reg_GX_VRAMCNT_C = VRAMCNT_BG(1);
        break;
    case GX_VRAM_BG_256_AD:
        reg_GX_VRAMCNT_A = VRAMCNT_BG(0);
        reg_GX_VRAMCNT_D = VRAMCNT_BG(1);
        break;
    case GX_VRAM_BG_256_BD:
        reg_GX_VRAMCNT_B = VRAMCNT_BG(0);
        reg_GX_VRAMCNT_D = VRAMCNT_BG(1);
        break;
    case GX_VRAM_BG_96_EFG:
        reg_GX_VRAMCNT_G = VRAMCNT_BG(3);
    case GX_VRAM_BG_80_EF:
        reg_GX_VRAMCNT_F = VRAMCNT_BG(2);
    case GX_VRAM_BG_64_E:
        reg_GX_VRAMCNT_E = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_80_EG:
        reg_GX_VRAMCNT_G = VRAMCNT_BG(2);
        reg_GX_VRAMCNT_E = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_32_FG:
        reg_GX_VRAMCNT_G = VRAMCNT_BG(1);
    case GX_VRAM_BG_16_F:
        reg_GX_VRAMCNT_F = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_16_G:
        reg_GX_VRAMCNT_G = VRAMCNT_BG(0);
        break;
    case GX_VRAM_BG_NONE:
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}






void GX_SetBankForOBJ(GXVRamOBJ obj)
{
    gGXState.vramCnt.lcdc = (u16)(~obj & (gGXState.vramCnt.lcdc | gGXState.vramCnt.obj));
    gGXState.vramCnt.obj = (u16)obj;

    switch (obj) {
    case GX_VRAM_OBJ_256_AB:
        reg_GX_VRAMCNT_B = VRAMCNT_OBJ(1);
    case GX_VRAM_OBJ_128_A:
        reg_GX_VRAMCNT_A = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_128_B:
        reg_GX_VRAMCNT_B = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_96_EFG:
        reg_GX_VRAMCNT_G = VRAMCNT_OBJ(3);
    case GX_VRAM_OBJ_80_EF:
        reg_GX_VRAMCNT_F = VRAMCNT_OBJ(2);
    case GX_VRAM_OBJ_64_E:
        reg_GX_VRAMCNT_E = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_80_EG:
        reg_GX_VRAMCNT_G = VRAMCNT_OBJ(2);
        reg_GX_VRAMCNT_E = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_32_FG:
        reg_GX_VRAMCNT_G = VRAMCNT_OBJ(1);
    case GX_VRAM_OBJ_16_F:
        reg_GX_VRAMCNT_F = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_16_G:
        reg_GX_VRAMCNT_G = VRAMCNT_OBJ(0);
        break;
    case GX_VRAM_OBJ_NONE:
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}






/*
 * sdk:      GX_SetBankForBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForBGExtPltt(int bgExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.bgExtPltt));
    gGXState.vramCnt.bgExtPltt = (u16)bgExtPltt;

    switch (bgExtPltt) {
    case 0:
        reg_GX_DISPCNT &= ~0x40000000;
        break;
    case 0x010:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_E = 0x84;
        break;
    case 0x040:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_G = 0x8c;
        break;
    case 0x060:
        reg_GX_VRAMCNT_G = 0x8c;
        /* fall through */
    case 0x020:
        reg_GX_VRAMCNT_F = 0x84;
        reg_GX_DISPCNT |= 0x40000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}






/*
 * sdk:      GX_SetBankForOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForOBJExtPltt(int objExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.objExtPltt));
    gGXState.vramCnt.objExtPltt = (u16)objExtPltt;

    switch (objExtPltt) {
    case 0x020:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_F = 0x85;
        break;
    case 0x040:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_G = 0x85;
        break;
    case 0:
        reg_GX_DISPCNT &= ~0x80000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}




void GX_SetBankForTex(GXVRamTex tex)
{
    gGXState.vramCnt.lcdc = (u16)(~tex & (gGXState.vramCnt.lcdc | gGXState.vramCnt.tex));
    gGXState.vramCnt.tex = (u16)tex;

    if (tex == GX_VRAM_TEX_NONE) {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_TME_MASK);
    } else {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~REG_G3X_DISP3DCNT_RO_MASK) | REG_G3X_DISP3DCNT_TME_MASK);

        switch (tex) {
        case GX_VRAM_TEX_01_AC:
            reg_GX_VRAMCNT_A = VRAMCNT_TEX(0);
            reg_GX_VRAMCNT_C = VRAMCNT_TEX(1);
            break;
        case GX_VRAM_TEX_01_AD:
            reg_GX_VRAMCNT_A = VRAMCNT_TEX(0);
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(1);
            break;
        case GX_VRAM_TEX_01_BD:
            reg_GX_VRAMCNT_B = VRAMCNT_TEX(0);
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(1);
            break;
        case GX_VRAM_TEX_012_ABD:
            reg_GX_VRAMCNT_A = VRAMCNT_TEX(0);
            reg_GX_VRAMCNT_B = VRAMCNT_TEX(1);
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(2);
            break;
        case GX_VRAM_TEX_012_ACD:
            reg_GX_VRAMCNT_A = VRAMCNT_TEX(0);
            reg_GX_VRAMCNT_C = VRAMCNT_TEX(1);
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(2);
            break;
        case GX_VRAM_TEX_0_D:
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(0);
            break;
        case GX_VRAM_TEX_01_CD:
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(1);
        case GX_VRAM_TEX_0_C:
            reg_GX_VRAMCNT_C = VRAMCNT_TEX(0);
            break;
        case GX_VRAM_TEX_012_BCD:
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(2);
        case GX_VRAM_TEX_01_BC:
            reg_GX_VRAMCNT_C = VRAMCNT_TEX(1);
        case GX_VRAM_TEX_0_B:
            reg_GX_VRAMCNT_B = VRAMCNT_TEX(0);
            break;
        case GX_VRAM_TEX_0123_ABCD:
            reg_GX_VRAMCNT_D = VRAMCNT_TEX(3);
        case GX_VRAM_TEX_012_ABC:
            reg_GX_VRAMCNT_C = VRAMCNT_TEX(2);
        case GX_VRAM_TEX_01_AB:
            reg_GX_VRAMCNT_B = VRAMCNT_TEX(1);
        case GX_VRAM_TEX_0_A:
            reg_GX_VRAMCNT_A = VRAMCNT_TEX(0);
            break;
        default:
            break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}








/*
 * sdk:      GX_SetBankForTexPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForTexPltt(int texPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~texPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.texPltt));
    gGXState.vramCnt.texPltt = (u16)texPltt;

    switch (texPltt) {
    case 0:
        break;
    case 0x060:
        reg_GX_VRAMCNT_G = 0x8b;
        /* fall through */
    case 0x020:
        reg_GX_VRAMCNT_F = 0x83;
        break;
    case 0x040:
        reg_GX_VRAMCNT_G = 0x83;
        break;
    case 0x070:
        reg_GX_VRAMCNT_G = 0x9b;
        /* fall through */
    case 0x030:
        reg_GX_VRAMCNT_F = 0x93;
        /* fall through */
    case 0x010:
        reg_GX_VRAMCNT_E = 0x83;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}








/*
 * sdk:      GX_SetBankForClearImage (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForClearImage(int clrImg)
{
    gGXState.vramCnt.lcdc = (u16)(~clrImg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.clrImg));
    gGXState.vramCnt.clrImg = (u16)clrImg;

    switch (clrImg) {
    case 0x003:
        reg_GX_VRAMCNT_A = 0x93;
        /* fall through */
    case 0x002:
        reg_GX_VRAMCNT_B = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x00c:
        reg_GX_VRAMCNT_C = 0x93;
        /* fall through */
    case 0x008:
        reg_GX_VRAMCNT_D = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0:
        reg_G3X_DISP3DCNT &= ~0x4000;
        break;
    case 0x001:
        reg_GX_VRAMCNT_A = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x004:
        reg_GX_VRAMCNT_C = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}








/*
 * sdk:      GX_SetBankForARM7 (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForARM7(int arm7)
{
    gGXState.vramCnt.lcdc = (u16)(~arm7 & (gGXState.vramCnt.lcdc | gGXState.vramCnt.arm7));
    gGXState.vramCnt.arm7 = (u16)arm7;

    switch (arm7) {
    case 0:
        break;
    case 0x004:
        reg_GX_VRAMCNT_C = 0x82;
        break;
    case 0x00c:
        reg_GX_VRAMCNT_D = 0x8a;
        reg_GX_VRAMCNT_C = 0x82;
        break;
    case 0x008:
        reg_GX_VRAMCNT_D = 0x82;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}







asm void GX_SetBankForLCDC(void)
{
    ldr r2, =g_02150E4C
    mov r1, r0, lsl #16
    ldrh r3, [r2]
    ldr ip, =func_0207FD34
    orr r1, r3, r1, lsr #16
    strh r1, [r2]
    bx ip
}








/*
 * sdk:      GX_SetBankForSubBG (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForSubBG(int sub_bg)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_bg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bg));
    gGXState.vramCnt.sub_bg = (u16)sub_bg;

    switch (sub_bg) {
    case 0x004:
        reg_GX_VRAMCNT_C = 0x84;
        break;
    case 0x180:
        reg_GX_VRAMCNT_I = 0x81;
        /* fall through */
    case 0x080:
        reg_GX_VRAMCNT_H = 0x81;
        break;
    case 0:
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}







/*
 * sdk:      GX_SetBankForSubOBJ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForSubOBJ(int sub_obj)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_obj & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_obj));
    gGXState.vramCnt.sub_obj = (u16)sub_obj;

    switch (sub_obj) {
    case 0x008:
        reg_GX_VRAMCNT_D = 0x84;
        break;
    case 0x100:
        reg_GX_VRAMCNT_I = 0x82;
        break;
    case 0:
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}







/*
 * sdk:      GX_SetBankForSubBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForSubBGExtPltt(int sub_bgExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_bgExtPltt));
    gGXState.vramCnt.sub_bgExtPltt = (u16)sub_bgExtPltt;

    switch (sub_bgExtPltt) {
    case 0x080:
        reg_GXS_DB_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_H = 0x82;
        break;
    case 0:
        reg_GXS_DB_DISPCNT &= ~0x40000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}







/*
 * sdk:      GX_SetBankForSubOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~sub_objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.sub_objExtPltt));
    gGXState.vramCnt.sub_objExtPltt = (u16)sub_objExtPltt;

    switch (sub_objExtPltt) {
    case 0x100:
        reg_GXS_DB_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_I = 0x83;
        break;
    case 0:
        reg_GXS_DB_DISPCNT &= ~0x80000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}







/*
 * sdk:      resetBankForX_ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
int resetBankForX_(u16 *g3bit)
{
    int rval = *g3bit;

    *g3bit = 0;
    gGXState.vramCnt.lcdc |= rval;
    GX_VRAMCNT_SetLCDC_(rval);
    return rval;
}






int GX_ResetBankForBG(void){ return resetBankForX_((u16 *)((int)0x2150E4E)); }






void GX_ResetBankForOBJ(void){ resetBankForX_((u16 *)((int)0x2150E50)); }







void GX_ResetBankForBGExtPltt(void)
{
    reg_GX_DISPCNT &= ~0x40000000;
    resetBankForX_((u16 *)((int)0x2150E5A));
}







void GX_ResetBankForOBJExtPltt(void)
{
    reg_GX_DISPCNT &= ~0x80000000;
    resetBankForX_((u16 *)((int)0x2150E5C));
}






int GX_ResetBankForTex(void){ return resetBankForX_((void *)0x02150E54); }






void GX_ResetBankForTexPltt(void){ resetBankForX_((u16 *)((int)0x2150E56)); }






void GX_ResetBankForClearImage(int a0, int a1, int a2, int a3){ resetBankForX_((u16 *)((int)0x2150E58)); }






int GX_ResetBankForSubBG(void){ return resetBankForX_((u16 *)((int)0x2150E5E)); }





void GX_ResetBankForSubOBJ(void){ resetBankForX_((u16 *)((int)0x2150E60)); }






void GX_ResetBankForSubBGExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    resetBankForX_((u16 *)((int)0x2150E62));
}






void GX_ResetBankForSubOBJExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    resetBankForX_((u16 *)((int)0x2150E64));
}






/*
 * sdk:      disableBankForX_ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
int disableBankForX_(u16 *g3bit)
{
    int rval = *g3bit;

    *g3bit = 0;
    if (rval & GX_VRAM_A) {
        reg_GX_VRAMCNT_A = 0;
    }
    if (rval & GX_VRAM_B) {
        reg_GX_VRAMCNT_B = 0;
    }
    if (rval & GX_VRAM_C) {
        reg_GX_VRAMCNT_C = 0;
    }
    if (rval & GX_VRAM_D) {
        reg_GX_VRAMCNT_D = 0;
    }
    if (rval & GX_VRAM_E) {
        reg_GX_VRAMCNT_E = 0;
    }
    if (rval & GX_VRAM_F) {
        reg_GX_VRAMCNT_F = 0;
    }
    if (rval & GX_VRAM_G) {
        reg_GX_VRAMCNT_G = 0;
    }
    if (rval & GX_VRAM_H) {
        reg_GX_VRAMCNT_H = 0;
    }
    if (rval & GX_VRAM_I) {
        reg_GX_VRAMCNT_I = 0;
    }
    OSi_UnlockVram((u16)rval, GXi_VRamLockId);
    return rval;
}






/*
 * sdk:      GX_DisableBankForBG (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForBG(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.bg);
}






/*
 * sdk:      GX_DisableBankForOBJ (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForOBJ(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.obj);
}






/*
 * sdk:      GX_ResetBankForBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForBGExtPltt(void)
{
    reg_GX_DISPCNT &= ~0x40000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.bgExtPltt);
}






/*
 * sdk:      GX_ResetBankForOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForOBJExtPltt(void)
{
    reg_GX_DISPCNT &= ~0x80000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.objExtPltt);
}






/*
 * sdk:      GX_DisableBankForTex (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForTex(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.tex);
}






/*
 * sdk:      GX_DisableBankForTexPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForTexPltt(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.texPltt);
}






/*
 * sdk:      GX_DisableBankForClearImage (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForClearImage(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.clrImg);
}





/*
 * sdk:      GX_DisableBankForARM7 (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForARM7(void)
{
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.arm7);
}




void GX_DisableBankForLCDC(void){ disableBankForX_((void *)0x02150E4C); }




void GX_DisableBankForSubBG(int a0, int a1, int a2, int a3){ disableBankForX_((u16 *)((int)0x2150E5E)); }




void GX_DisableBankForSubOBJ(int a0, int a1, int a2, int a3){ disableBankForX_((u16 *)((int)0x2150E60)); }





/*
 * sdk:      GX_ResetBankForSubBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForSubBGExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.sub_bgExtPltt);
}





/*
 * sdk:      GX_ResetBankForSubOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
GXVRam GX_DisableBankForSubOBJExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return (GXVRam)disableBankForX_(&gGXState.vramCnt.sub_objExtPltt);
}



/*
 * note:     gx_vramcnt.o GX_GetBankForOBJ; gGXState.vramCnt at 0x02150E4C.
 */
u16 GX_GetBankForOBJ(void)
{
    return gGXState.vramCnt.obj;
}



/*
 * note:     gx_vramcnt.o GX_GetBankForOBJExtPltt.
 */
u16 GX_GetBankForOBJExtPltt(void)
{
    return gGXState.vramCnt.objExtPltt;
}



/*
 * note:     gx_vramcnt.o GX_GetBankForTex.
 */
u16 GX_GetBankForTex(void)
{
    return gGXState.vramCnt.tex;
}



/*
 * note:     gx_vramcnt.o GX_GetBankForLCDC.
 */
u16 GX_GetBankForLCDC(void)
{
    return gGXState.vramCnt.lcdc;
}



/*
 * note:     gx_vramcnt.o GX_GetBankForSubOBJ.
 */
u16 GX_GetBankForSubOBJ(void)
{
    return gGXState.vramCnt.sub_obj;
}



/*
 * note:     gx_vramcnt.o GX_GetBankForSubOBJExtPltt.
 */
u16 GX_GetBankForSubOBJExtPltt(void)
{
    return gGXState.vramCnt.sub_objExtPltt;
}
