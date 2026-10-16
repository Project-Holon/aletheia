/*
 * file:     fld_vreq.c
 * unit:     yes
 * function: FLD_VREQ_Create, FLD_VREQ_Delete, FLD_VREQ_VBlank, FLD_VREQ_SetBgVisible, FLD_VREQ_SetSubMasterBrightness, FLD_VREQ_SetMainBlendAlpha, FLD_VREQ_SetMainBlendBrightnessExt, FLD_VREQ_SetMainBlendAlphaEv, FLD_VREQ_SetSubBlendAlpha, FLD_VREQ_ApplyBlendNone, FLD_VREQ_ApplyBlendAlpha, FLD_VREQ_ApplyBlendBrightness, FLD_VREQ_ApplyBlendControl, FLD_VREQ_ApplyChangeBlendBrightness
 * address:  0x021D317C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D317C (__FILE__ anchor fld_vreq.c at 0x021D317C (first anchored function)).
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_021DE6C8     0x021DE6C8  data  ov021  a4
 *   sFldVReqBlendFuncs     0x021DE6AC  data  ov021  a4
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   G2x_SetBlendBrightnessExt_  0x0207D67C  arm
 *   DWCi_WindowG2x_ChangeBlendBrightness_  0x0207D6C0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/*
 * Field V-blank requests: blend and brightness register writes and BG
 * visibility changes stored during the frame and applied by
 * FLD_VREQ_VBlank in V-blank.
 */
typedef struct FldVReq {
    u16 mainBlendKind;          /* 0x00: index into sFldVReqBlendFuncs, 0 = none */
    u16 subBlendKind;           /* 0x02 */
    int mainBlendParams[5];     /* 0x04 */
    int subBlendParams[5];      /* 0x18 */
    u8 bgVisible[8];            /* 0x2C: per BG frame, 0xFF = no request */
    u8 mainBrightReq;           /* 0x34 */
    u8 subBrightReq;            /* 0x35 */
    signed char mainBright;     /* 0x36 */
    signed char subBright;      /* 0x37 */
} FldVReq;

/* Blend request kinds (sFldVReqBlendFuncs slots). */
#define _BLEND_KIND_ALPHA       2
#define _BLEND_KIND_BRIGHT_EXT  4
#define _BLEND_KIND_ALPHA_EV    5

#define _REG_MAIN_BLDCNT        0x04000050
#define _REG_SUB_BLDCNT         0x04001050
#define _REG_MAIN_MASTER_BRIGHT 0x0400006C
#define _REG_SUB_MASTER_BRIGHT  0x0400106C

typedef void (*FldVReqBlendFunc)(void *params, int isMain);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern u32 BG_SYS_SetPlaneVisible(u32 which, u32 enable);
extern void MI_CpuFill8(void *p, int v, int n);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void G2x_SetBlendAlpha_(int, int, int, int, int);
extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);
extern void G2x_SetBlendBrightnessExt_(u32 reg, int a, int b, int c, int d, int e);
extern void DWCi_WindowG2x_ChangeBlendBrightness_(u32 addr, int brightness);
FldVReq *FLD_VREQ_Create(u32 heapId);
void FLD_VREQ_Delete(FldVReq *vreq);
void FLD_VREQ_VBlank(FldVReq *vreq);
void FLD_VREQ_SetBgVisible(FldVReq *vreq, int frame, u8 visible);
void FLD_VREQ_SetSubMasterBrightness(FldVReq *vreq, u8 brightness);
void FLD_VREQ_SetMainBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void FLD_VREQ_SetMainBlendBrightnessExt(FldVReq *vreq, int plane1, int plane2, int ev1, int ev2, int brightness);
void FLD_VREQ_SetMainBlendAlphaEv(FldVReq *vreq, int ev1, int ev2);
void FLD_VREQ_SetSubBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void FLD_VREQ_ApplyBlendNone(void *params, int isMain);
void FLD_VREQ_ApplyBlendAlpha(int *params, int isMain);
void FLD_VREQ_ApplyBlendBrightness(u32 *params, int isMain);
void FLD_VREQ_ApplyBlendControl(const int *params, int isMain);
void FLD_VREQ_ApplyBlendAlphaEv(u32 *params, int isMain);
void FLD_VREQ_ApplyChangeBlendBrightness(u32 *params, int isMain);
extern char d_021DE6C8[];       /* "fld_vreq.c" */

FldVReq *FLD_VREQ_Create(u32 heapId)
{
    FldVReq *vreq = GFL_HEAP_Alloc(heapId, sizeof(FldVReq), 1, d_021DE6C8, 0x80);
    MI_CpuFill8(vreq->bgVisible, 0xff, sizeof(vreq->bgVisible));
    return vreq;
}

/*
 * Tail-call thunk: forwards to GFL_HEAP_Free with no argument change.
 */
void FLD_VREQ_Delete(FldVReq *vreq)
{
    GFL_HEAP_Free(vreq);
}

extern FldVReqBlendFunc sFldVReqBlendFuncs[];

/*
 * The visibility byte is BG_SYS_SetPlaneVisible's second argument (it takes two,
 * like every other caller): passing vreq->bgVisible[frame] is what puts the
 * ldrb in r1.
 */
void FLD_VREQ_VBlank(FldVReq *vreq)
{
    int frame;

    if (sFldVReqBlendFuncs[vreq->mainBlendKind] != 0) {
        sFldVReqBlendFuncs[vreq->mainBlendKind](vreq->mainBlendParams, 1);
        vreq->mainBlendKind = 0;
    }
    if (sFldVReqBlendFuncs[vreq->subBlendKind] != 0) {
        sFldVReqBlendFuncs[vreq->subBlendKind](vreq->subBlendParams, 0);
        vreq->subBlendKind = 0;
    }
    for (frame = 0; frame < 8; frame++) {
        if (vreq->bgVisible[frame] != 0xff) {
            BG_SYS_SetPlaneVisible((u8)frame, vreq->bgVisible[frame]);
            vreq->bgVisible[frame] = 0xff;
        }
    }
    if (vreq->mainBrightReq != 0) {
        GXx_SetMasterBrightness_((volatile u16 *)_REG_MAIN_MASTER_BRIGHT, vreq->mainBright);
        vreq->mainBrightReq = 0;
    }
    if (vreq->subBrightReq != 0) {
        GXx_SetMasterBrightness_((volatile u16 *)_REG_SUB_MASTER_BRIGHT, vreq->subBright);
        vreq->subBrightReq = 0;
    }
}

void FLD_VREQ_SetBgVisible(FldVReq *vreq, int frame, u8 visible)
{
    vreq->bgVisible[frame] = visible;
}

void FLD_VREQ_SetSubMasterBrightness(FldVReq *vreq, u8 brightness)
{
    vreq->subBrightReq = 1;
    vreq->subBright = brightness;
}

void FLD_VREQ_SetMainBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2)
{
    vreq->mainBlendKind = _BLEND_KIND_ALPHA;
    vreq->mainBlendParams[0] = plane1;
    vreq->mainBlendParams[1] = plane2;
    vreq->mainBlendParams[2] = ev1;
    vreq->mainBlendParams[3] = ev2;
}

void FLD_VREQ_SetMainBlendBrightnessExt(FldVReq *vreq, int plane1, int plane2, int ev1, int ev2, int brightness)
{
    vreq->mainBlendKind = _BLEND_KIND_BRIGHT_EXT;
    vreq->mainBlendParams[0] = plane1;
    vreq->mainBlendParams[1] = plane2;
    vreq->mainBlendParams[2] = ev1;
    vreq->mainBlendParams[3] = ev2;
    vreq->mainBlendParams[4] = brightness;
}

/*
 * Unlabelled 10-byte leaf (movs/strh/str/str/bx lr) between labelled code;
 * called from SWEET_SCENT_FadeMain.
 */
void FLD_VREQ_SetMainBlendAlphaEv(FldVReq *vreq, int ev1, int ev2)
{
    vreq->mainBlendKind = _BLEND_KIND_ALPHA_EV;
    vreq->mainBlendParams[0] = ev1;
    vreq->mainBlendParams[1] = ev2;
}

/*
 * Unlabelled Thumb leaf (a .word in ov021.s), blocker of ov032 BEACON_VIEW_SetFadeState.
 * Storing the u16 kind first is what makes the compiler save r3/r4 and keep
 * the constant in r4.
 */
void FLD_VREQ_SetSubBlendAlpha(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2)
{
    vreq->subBlendKind = _BLEND_KIND_ALPHA;
    vreq->subBlendParams[0] = plane1;
    vreq->subBlendParams[1] = plane2;
    vreq->subBlendParams[2] = ev1;
    vreq->subBlendParams[3] = ev2;
}

void FLD_VREQ_ApplyBlendNone(void *params, int isMain)
{
    if (isMain != 0) {
        *(volatile unsigned short *)_REG_MAIN_BLDCNT = 0;
    } else {
        *(volatile unsigned short *)_REG_SUB_BLDCNT = 0;
    }
}

void FLD_VREQ_ApplyBlendAlpha(int *params, int isMain)
{
    if (isMain) {
        G2x_SetBlendAlpha_(_REG_MAIN_BLDCNT, params[0], params[1], params[2], params[3]);
    } else {
        G2x_SetBlendAlpha_(_REG_SUB_BLDCNT, params[0], params[1], params[2], params[3]);
    }
}

void FLD_VREQ_ApplyBlendBrightness(u32 *params, int isMain)
{
    if (isMain) {
        G2x_SetBlendBrightness_(_REG_MAIN_BLDCNT, params[0], params[1]);
    } else {
        G2x_SetBlendBrightness_(_REG_SUB_BLDCNT, params[0], params[1]);
    }
}

/*
 * FLD_VREQ_ApplyBlendAlphaEv is an unlabelled leaf after the first function's pool.
 */
void FLD_VREQ_ApplyBlendControl(const int *params, int isMain)
{
    if (isMain) {
        G2x_SetBlendBrightnessExt_(_REG_MAIN_BLDCNT, params[0], params[1], params[2], params[3], params[4]);
    } else {
        G2x_SetBlendBrightnessExt_(_REG_SUB_BLDCNT, params[0], params[1], params[2], params[3], params[4]);
    }
}

/* BLDALPHA (BLDCNT + 2): ev1 | ev2 << 8. */
void FLD_VREQ_ApplyBlendAlphaEv(u32 *params, int isMain)
{
    if (isMain) {
        *(volatile u16 *)(_REG_MAIN_BLDCNT + 2) = params[0] | (params[1] << 8);
    } else {
        *(volatile u16 *)(_REG_SUB_BLDCNT + 2) = params[0] | (params[1] << 8);
    }
}

void FLD_VREQ_ApplyChangeBlendBrightness(u32 *params, int isMain)
{
    if (isMain) {
        DWCi_WindowG2x_ChangeBlendBrightness_(_REG_MAIN_BLDCNT, params[0]);
    } else {
        DWCi_WindowG2x_ChangeBlendBrightness_(_REG_SUB_BLDCNT, params[0]);
    }
}
