/*
 * function: func_021DCE10
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
 * func_02082BCC 0x02082BCC arm
 * func_0203F8F4 0x0203F8F4 arm
 * func_02045B38 0x02045B38 arm
 * TCBL_Create 0x0203101C arm
 * GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * func_0201EC64 0x0201EC64 thumb
 * GF_FONT_Create 0x0201D7EC thumb
 * WIPE_SYS_Start 0x0202208C thumb
 * func_020056A0 0x020056A0 thumb
 * func_0201C440 0x0201C440 thumb
 * func_021DD1D0 0x021DD1D0 thumb ov137
 * func_021DD1E0 0x021DD1E0 thumb ov137
 * func_021DD3D8 0x021DD3D8 thumb ov137
 * func_021DD1A4 0x021DD1A4 thumb ov137
 * func_021DD2E0 0x021DD2E0 thumb ov137
 * func_021DD4A8 0x021DD4A8 thumb ov137
 * func_021DD5AC 0x021DD5AC thumb ov137
 * func_021DD638 0x021DD638 thumb ov137
 * func_021DCB78 0x021DCB78 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *func_020490F4(u32 id, u32 heap);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void func_0203F8F4(u16);
struct GfFont;
struct MsgBank;
struct Tcbl;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_021DD1D0(void),func_021DD1E0(void);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
extern void func_021DD3D8(void *,void *);
extern void func_021DD1A4(void *a0, void *work);
extern void *func_020056A0(u32,u32,u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *);
extern void func_021DD2E0(u8 *,void *),func_021DD4A8(u8 *,void *),func_021DD5AC(u8 *),func_021DD638(u8 *);
extern void func_021DCB78(u32 a);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *);
int func_021DCE10(void *a,u32 *state,u8 *ctx)
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
        func_02082BCC(p,0,0x4874);
        *(u8 **)(ctx+32)=p; *(u8 **)(p+12)=ctx;
        *(void **)(p+16)=*(void **)(ctx+24);
        func_0203F8F4(114);
        *(void **)(p+60)=func_0201EC64(114);
        *(void **)(p+64)=func_02045B38(0,2,42,114);
        *(void **)(p+56)=GF_FONT_Create(23,0,0,0,114);
        func_021DD1D0(); func_021DD1E0();
        WIPE_SYS_Start(0,1,1,0,16,1,114);
        func_021DD3D8(p,arc);
        *(void **)(p+48)=func_020056A0((u32)func_021DD1A4,(u32)p,1);
        *(void **)(p+244)=TCBL_Create(114,114,32,32);
        *(u32 *)(p+236)=func_0201C440((void *)114);
        func_021DD2E0(p,arc); func_021DD4A8(p,arc); func_021DD5AC(p); func_021DD638(p);
        func_021DCB78((u32)(*(void **)(ctx+24)));
        GFL_NET_RestartWithDefaultTimeout(1,114); ARC_TOOL_DeleteHandle(arc);
        (*state)++;
        break;
    case 1:
        *state=0;
        return 1;
    }
    return 0;
}
