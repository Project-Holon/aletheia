/*
 * function: STARTMENU_LogoScreenMain
 * address:  0x021BC9E8
 * packet:   pkt_ov088_021BC9E8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed ARC_UTIL_UploadBgCharFromArchive parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   ARC_UTIL_UploadBgCharFromArchive  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetLcdSwap  0x0204363C  arm
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}

typedef enum { Z0 } Zero;

typedef struct {
    u16 state;
    u16 pad;
    int count;
} St;

typedef signed int     s32;
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
struct BgTemplate;
struct DispConfig;
struct DispVram;
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern u32 ARC_UTIL_UploadBgCharFromArchive(void *a0, void *a1, void *a2, void *a3, u32 a4, u32 a5, u16 a6);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern u32 KEY_GetTrg(void);
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_Delete(void);

extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];

int STARTMENU_LogoScreenMain(int a0, int a1, int *mode, St *st)
{
    Zero z;

    switch (st->state) {
    case 0:
        BG_SYS_SetMainVisiblePlanes(0);
        BG_SYS_SetSubVisiblePlanes(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        BG_SYS_SetVramBanks((const struct DispVram *)d_021BD944);
        BG_SYS_Create(0x16);
        BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BD8F4);
        BG_SYS_InitBgLayer(1, (const struct BgTemplate *)d_021BD904, 0);
        BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BD924, 0);
        if (*mode == 1) {
            GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
            st->state = 7;
        } else {
            GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 16);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 16);
            st->state = 1;
        }
        break;
    case 1:
        z = Z0;
        ARC_UTIL_UploadBgCharFromArchive((void *)0x1a, (void *)0xc, (void *)1, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 0, 0, 0, 0x16);
        ARC_UTIL_UploadBgCharFromArchive((void *)0x1a, (void *)0xc, (void *)5, 0, 0, 1, 0x16);
        func_0204989C(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        func_02049B40(0x1a, 0xb, 4, 0, 0, 0x16);
        func_02040588(1, 1);
        func_02040588(5, 1);
        BG_SYS_SetLcdSwap(1);
        BG_SYS_ResetSubDisplay();
        FADE_Start(0xc, 0x10, z, 2);
        st->state = 2;
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            st->state = 3;
            st->count = 0;
        }
        break;
    case 3:
        if (++st->count > 0x5a)
            st->state = 4;
        if (KEY_GetTrg() & 0xb)
            st->state = 4;
        break;
    case 4:
        FADE_Start(3, 0, 0x10, 2);
        st->state = 5;
        break;
    case 5:
        if (FADE_IsActive() == 0) {
            st->state = 6;
            st->count = 0;
        }
        break;
    case 6:
        if (++st->count > 0x1e) {
            st->state = 7;
            st->count = 0;
        }
        break;
    case 7:
        ARC_UTIL_UploadBgCharFromArchive((void *)0xa4, (void *)1, (void *)1, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 2, 1, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 0, 0, 0, 0x16);
        ARC_UTIL_UploadBgCharFromArchive((void *)0xa4, (void *)3, (void *)5, 0, 0x8000, 0, 0x16);
        func_0204989C(0xa4, 4, 5, 0, 0, 0, 0x16);
        func_02049B40(0xa4, 0, 4, 0, 0, 0x16);
        BG_SYS_PushTile(1);
        BG_SYS_PushTile(5);
        func_02040588(1, 1);
        func_02040588(5, 1);
        BG_SYS_SetLcdSwap(1);
        BG_SYS_ResetSubDisplay();
        FADE_Start(3, 0x10, 0, 2);
        st->state = 8;
        break;
    case 8:
        if (FADE_IsActive() == 0)
            st->state = 9;
        break;
    case 9:
        if (++st->count > 0x5a) {
            st->state = 10;
            st->count = 0;
        }
        break;
    case 10:
        FADE_Start(3, 0, 0x10, 2);
        st->state = 0xb;
        break;
    case 11:
        if (FADE_IsActive() == 0)
            st->state = 0xc;
        break;
    case 12:
        if (++st->count > 0x1e)
            st->state = 0xd;
        break;
    case 13:
        BG_SYS_Delete();
        return 1;
    }
    return 0;
}
