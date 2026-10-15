/*
 * function: VIEWER_TEXT_Create
 * address:  0x021C6FC4
 * packet:   pkt_ov111_021C6FC4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   VIEWER_TEXT_LoadResources  0x021C7130  thumb
 *   VIEWER_TEXT_InitVram  0x021C7208  thumb
 *   VIEWER_TEXT_InitBg  0x021C7228  thumb
 *   VIEWER_TEXT_LoadBgResources  0x021C72FC  thumb
 *   VIEWER_TEXT_InitClact  0x021C7504  thumb
 *   VIEWER_ACTOR_CreateObjects  0x021C75E4  thumb
 *   VIEWER_ACTOR_Init3D  0x021C76A4  thumb
 *   VIEWER_ACTOR_CreateModel  0x021C7744  thumb
 *   VIEWER_ACTOR_InitBgWindow  0x021C78C4  thumb
 *   VIEWER_ACTOR_CreateFont  0x021C7934  thumb
 *   VIEWER_ACTOR_SetSelection  0x021C81A4  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 heap, u32 size);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(int v, void *p, int size);
extern void VIEWER_TEXT_LoadResources(Work *p, void *parent);
extern void VIEWER_TEXT_InitVram(void);
extern void VIEWER_TEXT_InitBg(Work *p);
extern void VIEWER_TEXT_LoadBgResources(Work *p);
extern void VIEWER_TEXT_InitClact(Work *p);
extern void VIEWER_ACTOR_CreateObjects(Work *p);
extern void VIEWER_ACTOR_Init3D(Work *p);
extern void VIEWER_ACTOR_CreateModel(Work *p);
extern void VIEWER_ACTOR_InitBgWindow(Work *p);
extern void VIEWER_ACTOR_CreateFont(Work *p);
extern void VIEWER_ACTOR_SetSelection(Work *p, u16 v);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int VIEWER_TEXT_Create(void *proc, int *seq, void *parent)
{
    Work *p;

    GFL_HEAP_CreateChildHeap(1, 0x27, 0x20000);
    p = PROCSYS_AllocProcWork(proc, 0x1C8, 0x27);
    MIi_CpuClearFast(0, p, 0x1C8);
    VIEWER_TEXT_LoadResources(p, parent);
    VIEWER_TEXT_InitVram();
    VIEWER_TEXT_InitBg(p);
    VIEWER_TEXT_LoadBgResources(p);
    VIEWER_TEXT_InitClact(p);
    VIEWER_ACTOR_CreateObjects(p);
    VIEWER_ACTOR_Init3D(p);
    VIEWER_ACTOR_CreateModel(p);
    VIEWER_ACTOR_InitBgWindow(p);
    VIEWER_ACTOR_CreateFont(p);
    VIEWER_ACTOR_SetSelection(p, p->f114);
    GFL_NET_RestartWithDefaultTimeout(1, 0x27);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}
