/*
 * function: GURU2_RECEIPT_ProcInit
 * address: 0x021DCE10
 * packet: pkt_ov137_021DCE10
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC, unit_0204349C.c omits function: entries for its
 * nested functions. Verified wrapper is MATCH (16 bytes; 020434B4 unresolved).
 * extern void BG_SYS_ClearMainBgPlanes(void),BG_SYS_ClearMainObjPlane(void);
 * void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * Blocker symbols: BG_SYS_ClearMainBgPlanes 0x0204349C arm; BG_SYS_ClearMainObjPlane 0x020434B4 arm.
 * blocker: ARM9 02043588, unit_02043570.c omits function: entry.
 * Verified wrapper is EXACT (16 bytes), fixed compiler/flags ARM.
 * extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 * void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * Blocker symbols: BG_SYS_ClearSubBgPlanes 0x02043558 arm; BG_SYS_ClearSubObjPlane 0x02043570 arm.
 * volatile: hardware DISPCNT reads at 021DCE34 and 021DCE3E.
 * lever: PROCSYS_AllocProcWork leaves its allocator result in r0, used by the caller.
 * symbols:
 * BG_SYS_ClearMainPlanes 0x020434CC arm
 * BG_SYS_ClearSubPlanes 0x02043588 arm
 * GFL_HEAP_CreateChildHeap 0x0203064C arm
 * func_020490F4 0x020490F4 arm
 * PROCSYS_AllocProcWork 0x0203159C arm
 * MI_CpuFill8 0x02082BCC arm
 * BG_SYS_Create 0x0203F8F4 arm
 * func_02045B38 0x02045B38 arm
 * TCBL_Create 0x0203101C arm
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * WORDSET_CreateDefault 0x0201EC64 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * WIPE_SYS_Start 0x0202208C thumb
 * func_020056A0 0x020056A0 thumb
 * PRINTSYS_QUE_Create 0x0201C440 thumb
 * GURU2_RECEIPT_SetVramBanks 0x021DD1D0 thumb ov137
 * GURU2_RECEIPT_InitBg 0x021DD1E0 thumb ov137
 * GURU2_RECEIPT_LoadGraphics 0x021DD3D8 thumb ov137
 * GURU2_RECEIPT_VBlank 0x021DD1A4 thumb ov137
 * GURU2_RECEIPT_InitStrings 0x021DD2E0 thumb ov137
 * GURU2_RECEIPT_InitActors 0x021DD4A8 thumb ov137
 * GURU2_RECEIPT_CreatePlayerActors 0x021DD5AC thumb ov137
 * GURU2_RECEIPT_CreateWindows 0x021DD638 thumb ov137
 * GURU2_COMM_RegisterCommands 0x021DCB78 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *func_020490F4(u32 id, u32 heap);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern void BG_SYS_Create(u16);
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void GURU2_RECEIPT_SetVramBanks(void),GURU2_RECEIPT_InitBg(void);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void GURU2_RECEIPT_LoadGraphics(void *,void *);
extern void GURU2_RECEIPT_VBlank(void *a0, void *work);
extern void *func_020056A0(u32,u32,u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
extern void GURU2_RECEIPT_InitStrings(u8 *,void *),GURU2_RECEIPT_InitActors(u8 *,void *),GURU2_RECEIPT_CreatePlayerActors(u8 *),GURU2_RECEIPT_CreateWindows(u8 *);
extern void GURU2_COMM_RegisterCommands(u32 a);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *);
int GURU2_RECEIPT_ProcInit(void *a,u32 *state,u8 *ctx)
{
    u8 *p;
    void *arc;
    switch(*state) {
    case 0:
        BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
        *(volatile u32 *)0x04000000&=0xffffe0ff;
        *(volatile u32 *)0x04001000&=0xffffe0ff;
        GFL_HEAP_CreateChildHeap((u32)((void *)1),114,0x80000);
        arc=func_020490F4(184,114);
        p=PROCSYS_AllocProcWork(a,0x4874,114);
        MI_CpuFill8(p,0,0x4874);
        *(u8 **)(ctx+32)=p; *(u8 **)(p+12)=ctx;
        *(void **)(p+16)=*(void **)(ctx+24);
        BG_SYS_Create(114);
        *(void **)(p+60)=WORDSET_CreateDefault(114);
        *(void **)(p+64)=func_02045B38(0,2,42,114);
        *(void **)(p+56)=GF_FONT_Create(23,0,0,0,114);
        GURU2_RECEIPT_SetVramBanks(); GURU2_RECEIPT_InitBg();
        WIPE_SYS_Start(0,1,1,0,16,1,114);
        GURU2_RECEIPT_LoadGraphics(p,arc);
        *(void **)(p+48)=func_020056A0((u32)GURU2_RECEIPT_VBlank,(u32)p,1);
        *(void **)(p+244)=TCBL_Create(114,114,32,32);
        *(u32 *)(p+236)=PRINTSYS_QUE_Create((void *)114);
        GURU2_RECEIPT_InitStrings(p,arc); GURU2_RECEIPT_InitActors(p,arc); GURU2_RECEIPT_CreatePlayerActors(p); GURU2_RECEIPT_CreateWindows(p);
        GURU2_COMM_RegisterCommands((u32)(*(void **)(ctx+24)));
        GFL_NET_RestartWithDefaultTimeout(1,114); ARC_TOOL_DeleteHandle(arc);
        (*state)++;
        break;
    case 1:
        *state=0;
        return 1;
    }
    return 0;
}
