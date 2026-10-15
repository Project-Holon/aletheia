/*
 * function: OEKAKI_Init
 * address:  0x0218456C
 * packet:   pkt_ov023_0218456C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   OEKAKI_SetVramBanks  0x021848D0  thumb  ov023
 *   OEKAKI_SetupBgs  0x021848E0  thumb  ov023
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_020490F4  0x020490F4  arm
 *   OEKAKI_LoadBgGraphics  0x02184B78  thumb  ov023
 *   func_020056A0  0x020056A0  thumb
 *   OEKAKI_VBlankTask  0x0218489C  thumb  ov023
 *   OEKAKI_InitWork  0x021849F8  thumb  ov023
 *   OEKAKI_LoadSpriteResources  0x02184C48  thumb  ov023
 *   OEKAKI_CreateActors  0x02184D30  thumb  ov023
 *   OEKAKI_CreateWindows  0x02184ECC  thumb  ov023
 *   OEKAKI_EnableDisplays  0x02186564  thumb  ov023
 *   OEKAKI_RegisterNetCommands  0x021841E0  thumb  ov023
 *   OEKAKI_RegisterMetPlayers  0x021866C4  thumb  ov023
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct W {
    u32 f0;
    u32 f4;
    void *f8;
    void *fc;
    u32 f10;
    void *f14;
} W;

extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
struct GfFont;
struct MsgBank;
extern void BG_SYS_Create(u16 heapId);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void OEKAKI_SetVramBanks(void);
extern void OEKAKI_SetupBgs(void);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_020490F4(u32 id, u32 heap);
struct Work;
extern void OEKAKI_LoadBgGraphics(u8 *p, void *h);
extern void *func_020056A0(void (*cb)(void), void *ctx, int z);
extern void OEKAKI_VBlankTask(void);
extern void OEKAKI_InitWork(u8 *p);
extern void OEKAKI_LoadSpriteResources(u8 *p, void *q);
extern void OEKAKI_CreateActors(struct Work *p);
extern void OEKAKI_CreateWindows(W *p, void *task);
extern void OEKAKI_EnableDisplays(void);
extern void OEKAKI_RegisterNetCommands(u32 a);
extern void OEKAKI_RegisterMetPlayers(u32 *p);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *h);

int OEKAKI_Init(void *task, int *state, u32 arg)
{
    W *w;
    void *h;

    switch (*state) {
    case 0:
        BG_SYS_ClearMainPlanes();
        BG_SYS_ClearSubPlanes();
        GFL_HEAP_CreateChildHeap(1, 0x28, 0x50000);
        w = PROCSYS_AllocProcWork(task, 0x9e84, 0x28);
        MI_CpuFill8(w, 0, 0x9e84);
        BG_SYS_Create(0x28);
        w->f10 = (u32)WORDSET_CreateDefault(0x28);
        w->f14 = func_02045B38(0, 2, 0x53, 0x28);
        w->fc = GF_FONT_Create(0x17, 0, 0, 0, 0x28);
        OEKAKI_SetVramBanks();
        OEKAKI_SetupBgs();
        WIPE_SYS_Start(0, 9, 9, 0, 0x10, 1, 0x28);
        w->f4 = arg;
        h = func_020490F4(0xbf, 0x28);
        OEKAKI_LoadBgGraphics((u8 *)w, h);
        w->f8 = func_020056A0(OEKAKI_VBlankTask, w, 0);
        OEKAKI_InitWork((u8 *)w);
        OEKAKI_LoadSpriteResources((u8 *)w, h);
        OEKAKI_CreateActors((struct Work *)w);
        OEKAKI_CreateWindows(w, task);
        OEKAKI_EnableDisplays();
        OEKAKI_RegisterNetCommands((u32)w);
        OEKAKI_RegisterMetPlayers((u32 *)w);
        GFL_NET_RestartWithDefaultTimeout(1, 0x28);
        ARC_TOOL_DeleteHandle(h);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return 1;
    }
    return 0;
}
