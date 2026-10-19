/*
 * function: VCT_Init
 * address:  0x021B370C
 * packet:   pkt_ov013_021B370C
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   d_02005108     0x02005108  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   gVctState     0x021B60CC  data  ov013
 *   gVctSession     0x021B60D8  data  ov013
 *   VCT_MIXER_Init  0x021B0508  arm  ov013
 *   VCT_SESSION_InitPeerPool  0x021B22B4  arm  ov013
 *   VCT_SESSION_ClearPeerLists  0x021B23C8  arm  ov013
 *   VCT_POOL_InitFrames  0x021B2ED8  arm  ov013
 *   VCT_POOL_Reset  0x021B2F98  arm  ov013
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    u8  fc;
    u8  fd, fe, ff;
    int f10;
    int f14;
    int f18;
    int f1c;
} Param;

extern char d_02005108[];
extern int  gVctState[];
extern u8   gVctSession[];
extern void OSi_ReferSymbol(const void *symbol);
extern void MI_CpuFill8(void *dst, int c, int n);
extern int  VCT_MIXER_Init(void);
struct Config;
extern int VCT_SESSION_InitPeerPool(struct Config *cfg);
extern void VCT_SESSION_ClearPeerLists(void);
typedef unsigned int   u32;
struct E;
extern int VCT_POOL_InitFrames(struct E *a, u32 b);
extern void VCT_POOL_Reset(void);

int VCT_Init(Param *p)
{
    OSi_ReferSymbol(d_02005108);
    if (p == 0)
        return 0;
    if (gVctState[2] != 0)
        return 1;
    if (p->f8 != 1 && p->f8 != 2 && p->f8 != 3)
        return 0;
    if (p->f18 == 0)
        return 0;
    if (p->f10 == 0 || p->f14 == 0)
        return 0;
    if (p->f10 % 32 != 0)
        return 0;
    MI_CpuFill8(gVctSession, 0, 0x18);
    gVctState[4] = p->f18;
    gVctState[5] = p->f1c;
    gVctState[7] = p->f8;
    gVctState[6] = 0;
    if (p->fc >= 0x20)
        return 0;
    ((u8 *)gVctState)[0xc] = p->fc;
    if (VCT_POOL_InitFrames((struct E *)p->f10, p->f14) == 0) {
        VCT_POOL_Reset();
        return 0;
    }
    if (VCT_SESSION_InitPeerPool((struct Config *)p) == 0) {
        VCT_POOL_Reset();
        return 0;
    }
    if (VCT_MIXER_Init() != 0) {
        gVctState[2] = 1;
        return 1;
    }
    VCT_SESSION_ClearPeerLists();
    VCT_POOL_Reset();
    return 0;
}
