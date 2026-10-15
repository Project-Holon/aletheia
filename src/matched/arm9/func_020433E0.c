/*
 * function: BG_SYS_SetVramBanks
 * address:  0x020433E0
 * packet:   pkt_020433E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_020808F4  0x020808F4  arm
 *   func_0208091C  0x0208091C  arm
 *   func_020809A0  0x020809A0  arm
 *   func_020809C8  0x020809C8  arm
 *   func_02080908  0x02080908  arm
 *   func_02080940  0x02080940  arm
 *   func_020809B4  0x020809B4  arm
 *   func_020809F0  0x020809F0  arm
 *   func_02080964  0x02080964  arm
 *   func_02080978  0x02080978  arm
 *   func_0207FDCC  0x0207FDCC  arm
 *   GX_SetBankForBGExtPltt  0x02080100  arm
 *   GX_SetBankForSubBG  0x020806B0  arm
 *   GX_SetBankForSubBGExtPltt  0x020807BC  arm
 *   func_0207FFD0  0x0207FFD0  arm
 *   GX_SetBankForOBJExtPltt  0x020801F8  arm
 *   GX_SetBankForSubOBJ  0x0208074C  arm
 *   GX_SetBankForSubOBJExtPltt  0x0208083C  arm
 *   func_02080294  0x02080294  arm
 *   GX_SetBankForTexPltt  0x0208040C  arm
 *
 * bg_sys.c: apply a VRAM bank descriptor.  Disable every bank, set the ten
 * bank assignments (TwlSDK GX_SetBankFor*, 0x0207FDCC..0x0208040C), then the
 * main and sub OBJ-VRAM character mapping through the SDK inlines
 * GX_SetOBJVRamModeChar / GXS_SetOBJVRamModeChar (nitro/gx/gx.h).
 *
 * Closed in wave 16 by the SDK-inline lever: the two mapping words are
 * GXOBJVRamModeChar enum fields passed straight into the inlines, and the
 * descriptor is `const`.  With u32 fields and parameters the same body is
 * 33 bytes out; with a non-const or volatile descriptor 29; every earlier
 * spelling (locals a/b, volatile struct) capped at 6 (r3/ip pair in the
 * DISPCNT tail, docs/notes/BG_SYS_SetVramBanks.c.txt).
 */
typedef unsigned int u32;

typedef enum {
    GX_OBJVRAMMODE_CHAR_2D      = 0x00000000,
    GX_OBJVRAMMODE_CHAR_1D_32K  = 0x00000010,
    GX_OBJVRAMMODE_CHAR_1D_64K  = 0x00100010,
    GX_OBJVRAMMODE_CHAR_1D_128K = 0x00200010,
    GX_OBJVRAMMODE_CHAR_1D_256K = 0x00300010
} GXOBJVRamModeChar;

typedef enum { GX_VRAM_NONE = 0 } GXVRam;

struct DispVram {
    GXVRam main_bg;             /* +0x00 */
    GXVRam main_bg_expltt;      /* +0x04 */
    GXVRam sub_bg;              /* +0x08 */
    GXVRam sub_bg_expltt;       /* +0x0C */
    GXVRam main_obj;            /* +0x10 */
    GXVRam main_obj_expltt;     /* +0x14 */
    GXVRam sub_obj;             /* +0x18 */
    GXVRam sub_obj_expltt;      /* +0x1C */
    GXVRam teximage;            /* +0x20 */
    GXVRam texpltt;             /* +0x24 */
    GXOBJVRamModeChar main_mapping;     /* +0x28 */
    GXOBJVRamModeChar sub_mapping;      /* +0x2C */
};

extern int func_020808F4(void);
extern void func_0208091C(void);   /* GX_ResetBankForBGExtPltt */
extern int func_020809A0(void);
extern void func_020809C8(void);   /* GX_ResetBankForSubBGExtPltt */
extern void func_02080908(void);
extern void func_02080940(void);   /* GX_ResetBankForOBJExtPltt */
extern void func_020809B4(void);
extern void func_020809F0(void);   /* GX_ResetBankForSubOBJExtPltt */
extern int func_02080964(void);
extern void func_02080978(void);
extern void func_0207FDCC(GXVRam v);   /* GX_SetBankForBG */
extern void GX_SetBankForBGExtPltt(GXVRam v);   /* GX_SetBankForBGExtPltt */
extern void GX_SetBankForSubBG(GXVRam v);   /* GX_SetBankForSubBG */
extern void GX_SetBankForSubBGExtPltt(GXVRam v);   /* GX_SetBankForSubBGExtPltt */
extern void func_0207FFD0(GXVRam v);   /* GX_SetBankForOBJ */
extern void GX_SetBankForOBJExtPltt(GXVRam v);   /* GX_SetBankForOBJExtPltt */
extern void GX_SetBankForSubOBJ(GXVRam v);   /* GX_SetBankForSubOBJ */
extern void GX_SetBankForSubOBJExtPltt(GXVRam v);   /* GX_SetBankForSubOBJExtPltt */
extern void func_02080294(GXVRam v);   /* GX_SetBankForTex */
extern void GX_SetBankForTexPltt(GXVRam v);   /* GX_SetBankForTexPltt */

#define reg_GX_DISPCNT      (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT  (*(volatile u32 *)0x04001000)

static inline void GX_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GX_DISPCNT = (u32)(reg_GX_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

static inline void GXS_SetOBJVRamModeChar(GXOBJVRamModeChar mode)
{
    reg_GXS_DB_DISPCNT = (u32)(reg_GXS_DB_DISPCNT & ~(0x00300000 | 0x00000010) | mode);
}

void BG_SYS_SetVramBanks(const struct DispVram *c)
{
    func_020808F4();
    func_0208091C();
    func_020809A0();
    func_020809C8();
    func_02080908();
    func_02080940();
    func_020809B4();
    func_020809F0();
    func_02080964();
    func_02080978();
    func_0207FDCC(c->main_bg);
    GX_SetBankForBGExtPltt(c->main_bg_expltt);
    GX_SetBankForSubBG(c->sub_bg);
    GX_SetBankForSubBGExtPltt(c->sub_bg_expltt);
    func_0207FFD0(c->main_obj);
    GX_SetBankForOBJExtPltt(c->main_obj_expltt);
    GX_SetBankForSubOBJ(c->sub_obj);
    GX_SetBankForSubOBJExtPltt(c->sub_obj_expltt);
    func_02080294(c->teximage);
    GX_SetBankForTexPltt(c->texpltt);
    GX_SetOBJVRamModeChar(c->main_mapping);
    GXS_SetOBJVRamModeChar(c->sub_mapping);
}
