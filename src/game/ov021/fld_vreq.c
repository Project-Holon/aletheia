/*
 * file:     fld_vreq.c
 * unit:     yes
 * function: func_021D317C, func_021D31A4, func_021D31AC, func_021D3244, func_021D324C, func_021D325C, func_021D3270, func_021D3288, func_021D3294, func_021D32A8, func_021D32C4, func_021D32F8, func_021D331C, func_021D3384
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
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02040588  0x02040588  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021DE6C8     0x021DE6C8  data  ov021  a4
 *   d_021DE6AC     0x021DE6AC  data  ov021  a4
 *   func_0207D534  0x0207D534  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0207D658  0x0207D658  arm
 *   func_0207D67C  0x0207D67C  arm
 *   func_0207D6C0  0x0207D6C0  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/*
 * Field V-blank requests: blend and brightness register writes and BG
 * visibility changes stored during the frame and applied by
 * func_021D31AC in V-blank.
 */
typedef struct FldVReq {
    u16 mainBlendKind;          /* 0x00: index into d_021DE6AC, 0 = none */
    u16 subBlendKind;           /* 0x02 */
    int mainBlendParams[5];     /* 0x04 */
    int subBlendParams[5];      /* 0x18 */
    u8 bgVisible[8];            /* 0x2C: per BG frame, 0xFF = no request */
    u8 mainBrightReq;           /* 0x34 */
    u8 subBrightReq;            /* 0x35 */
    signed char mainBright;     /* 0x36 */
    signed char subBright;      /* 0x37 */
} FldVReq;

/* Blend request kinds (d_021DE6AC slots). */
#define _BLEND_KIND_ALPHA       2
#define _BLEND_KIND_BRIGHT_EXT  4
#define _BLEND_KIND_ALPHA_EV    5

#define _REG_MAIN_BLDCNT        0x04000050
#define _REG_SUB_BLDCNT         0x04001050
#define _REG_MAIN_MASTER_BRIGHT 0x0400006C
#define _REG_SUB_MASTER_BRIGHT  0x0400106C

typedef void (*FldVReqBlendFunc)(void *params, int isMain);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern u32 func_02040588(u32 which, u32 enable);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_0207D63C(int, int, int, int, int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_0207D67C(u32 reg, int a, int b, int c, int d, int e);
extern void func_0207D6C0(u32 addr, int brightness);
FldVReq *func_021D317C(u32 heapId);
void func_021D31A4(FldVReq *vreq);
void func_021D31AC(FldVReq *vreq);
void func_021D3244(FldVReq *vreq, int frame, u8 visible);
void func_021D324C(FldVReq *vreq, u8 brightness);
void func_021D325C(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void func_021D3270(FldVReq *vreq, int plane1, int plane2, int ev1, int ev2, int brightness);
void func_021D3288(FldVReq *vreq, int ev1, int ev2);
void func_021D3294(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2);
void func_021D32A8(void *params, int isMain);
void func_021D32C4(int *params, int isMain);
void func_021D32F8(u32 *params, int isMain);
void func_021D331C(const int *params, int isMain);
void func_021D335C(u32 *params, int isMain);
void func_021D3384(u32 *params, int isMain);
extern char d_021DE6C8[];       /* "fld_vreq.c" */

FldVReq *func_021D317C(u32 heapId)
{
    FldVReq *vreq = func_02030734(heapId, sizeof(FldVReq), 1, d_021DE6C8, 0x80);
    func_02082BCC(vreq->bgVisible, 0xff, sizeof(vreq->bgVisible));
    return vreq;
}

/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 */
void func_021D31A4(FldVReq *vreq)
{
    func_020307B0(vreq);
}

extern FldVReqBlendFunc d_021DE6AC[];

/*
 * The visibility byte is func_02040588's second argument (it takes two,
 * like every other caller): passing vreq->bgVisible[frame] is what puts the
 * ldrb in r1.
 */
void func_021D31AC(FldVReq *vreq)
{
    int frame;

    if (d_021DE6AC[vreq->mainBlendKind] != 0) {
        d_021DE6AC[vreq->mainBlendKind](vreq->mainBlendParams, 1);
        vreq->mainBlendKind = 0;
    }
    if (d_021DE6AC[vreq->subBlendKind] != 0) {
        d_021DE6AC[vreq->subBlendKind](vreq->subBlendParams, 0);
        vreq->subBlendKind = 0;
    }
    for (frame = 0; frame < 8; frame++) {
        if (vreq->bgVisible[frame] != 0xff) {
            func_02040588((u8)frame, vreq->bgVisible[frame]);
            vreq->bgVisible[frame] = 0xff;
        }
    }
    if (vreq->mainBrightReq != 0) {
        func_0207D534((volatile u16 *)_REG_MAIN_MASTER_BRIGHT, vreq->mainBright);
        vreq->mainBrightReq = 0;
    }
    if (vreq->subBrightReq != 0) {
        func_0207D534((volatile u16 *)_REG_SUB_MASTER_BRIGHT, vreq->subBright);
        vreq->subBrightReq = 0;
    }
}

void func_021D3244(FldVReq *vreq, int frame, u8 visible)
{
    vreq->bgVisible[frame] = visible;
}

void func_021D324C(FldVReq *vreq, u8 brightness)
{
    vreq->subBrightReq = 1;
    vreq->subBright = brightness;
}

void func_021D325C(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2)
{
    vreq->mainBlendKind = _BLEND_KIND_ALPHA;
    vreq->mainBlendParams[0] = plane1;
    vreq->mainBlendParams[1] = plane2;
    vreq->mainBlendParams[2] = ev1;
    vreq->mainBlendParams[3] = ev2;
}

void func_021D3270(FldVReq *vreq, int plane1, int plane2, int ev1, int ev2, int brightness)
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
 * called from func_021C622C.
 */
void func_021D3288(FldVReq *vreq, int ev1, int ev2)
{
    vreq->mainBlendKind = _BLEND_KIND_ALPHA_EV;
    vreq->mainBlendParams[0] = ev1;
    vreq->mainBlendParams[1] = ev2;
}

/*
 * Unlabelled Thumb leaf (a .word in ov021.s), blocker of ov032 func_021F0208.
 * Storing the u16 kind first is what makes the compiler save r3/r4 and keep
 * the constant in r4.
 */
void func_021D3294(FldVReq *vreq, u32 plane1, u32 plane2, u32 ev1, u32 ev2)
{
    vreq->subBlendKind = _BLEND_KIND_ALPHA;
    vreq->subBlendParams[0] = plane1;
    vreq->subBlendParams[1] = plane2;
    vreq->subBlendParams[2] = ev1;
    vreq->subBlendParams[3] = ev2;
}

void func_021D32A8(void *params, int isMain)
{
    if (isMain != 0) {
        *(volatile unsigned short *)_REG_MAIN_BLDCNT = 0;
    } else {
        *(volatile unsigned short *)_REG_SUB_BLDCNT = 0;
    }
}

void func_021D32C4(int *params, int isMain)
{
    if (isMain) {
        func_0207D63C(_REG_MAIN_BLDCNT, params[0], params[1], params[2], params[3]);
    } else {
        func_0207D63C(_REG_SUB_BLDCNT, params[0], params[1], params[2], params[3]);
    }
}

void func_021D32F8(u32 *params, int isMain)
{
    if (isMain) {
        func_0207D658(_REG_MAIN_BLDCNT, params[0], params[1]);
    } else {
        func_0207D658(_REG_SUB_BLDCNT, params[0], params[1]);
    }
}

/*
 * func_021D335C is an unlabelled leaf after the first function's pool.
 */
void func_021D331C(const int *params, int isMain)
{
    if (isMain) {
        func_0207D67C(_REG_MAIN_BLDCNT, params[0], params[1], params[2], params[3], params[4]);
    } else {
        func_0207D67C(_REG_SUB_BLDCNT, params[0], params[1], params[2], params[3], params[4]);
    }
}

/* BLDALPHA (BLDCNT + 2): ev1 | ev2 << 8. */
void func_021D335C(u32 *params, int isMain)
{
    if (isMain) {
        *(volatile u16 *)(_REG_MAIN_BLDCNT + 2) = params[0] | (params[1] << 8);
    } else {
        *(volatile u16 *)(_REG_SUB_BLDCNT + 2) = params[0] | (params[1] << 8);
    }
}

void func_021D3384(u32 *params, int isMain)
{
    if (isMain) {
        func_0207D6C0(_REG_MAIN_BLDCNT, params[0]);
    } else {
        func_0207D6C0(_REG_SUB_BLDCNT, params[0]);
    }
}
