/*
 * function: WIFIBATTLEMATCH_NET_TaskCreate
 * address: 0x021D4318
 * packet: pkt_ov175_021D4318
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 * symbols:
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   func_02034AC4 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_GRAPHIC_Create 0x021E5440 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_Create 0x021E567C thumb ov177
 *   WIFIBATTLEMATCH_NET_CopyBoxSave 0x021D6698 thumb ov175
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   WIFIBATTLEMATCH_NET_CreateNetContext 0x021D9DC8 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_Create 0x021E8568 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   WIFIBATTLEMATCH_NET_TaskStepA 0x021D458C thumb ov175
 *   WIFIBATTLEMATCH_VIEW_CreateActorArray 0x021E7D20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   WIFIBATTLEMATCH_NET_IncBsubwayStat 0x021D6524 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetupBoxAndWait 0x021D63C8 thumb ov175
 *   WIFIBATTLEMATCH_NET_RestartNet 0x021DD008 thumb ov175
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern const char ov067_id[], ov114_id[];
extern int func_02034AC4(int);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned, int);
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
extern u32 *WIFIBATTLEMATCH_VIEW_Create(int unused, int mode, int heap);
extern void WIFIBATTLEMATCH_NET_CopyBoxSave(u32 *, u32 *);
struct GfFont;
struct MsgBank;
struct WordSet;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, unsigned short heap);
typedef unsigned short u16;
extern char *WIFIBATTLEMATCH_NET_CreateNetContext(u32 a, void *save, u32 b, u16 heap);
extern void *WIFIBATTLEMATCH_UTIL_Create(unsigned, unsigned, unsigned, unsigned, void *, void *, unsigned);
extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int, int, int);
extern void WIFIBATTLEMATCH_NET_TaskStepA(unsigned sys, int *state, int *p);
extern void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *, void *, unsigned);
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **, int);
extern void WIFIBATTLEMATCH_NET_IncBsubwayStat(int, int, u32);
extern void WIFIBATTLEMATCH_NET_SetupBoxAndWait(char *, u32);
extern void WIFIBATTLEMATCH_NET_RestartNet(char *, int);
int WIFIBATTLEMATCH_NET_TaskCreate(void *sys, int *state, u32 *ctx)
{
    u32 *p;
    func_02034AC4((int)ov067_id);
    func_02034AC4((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 87, 0x35000);
    p = PROCSYS_AllocProcWork(sys, 0x100, 87);
    MI_CpuFill8(p, 0, 0x100);
    p[16] = (u32)ctx;
    p[0] = (u32)WIFIBATTLEMATCH_GRAPHIC_Create(1, 87);
    p[1] = (u32)WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)p[0]), 2, 87);
    WIFIBATTLEMATCH_NET_CopyBoxSave((u32 *)ctx[5], p);
    p[2] = (u32)GF_FONT_Create(23, 0, 0, 0, 87);
    p[3] = PRINTSYS_QUE_Create((void *)87);
    p[4] = (u32)func_02045B38(0, 2, 210, 87);
    p[5] = (u32)WORDSET_Create(8, 64, 87);
    p[12] = (u32)WIFIBATTLEMATCH_NET_CreateNetContext(((u32 *)p[16])[15], (void *)(((u32 *)ctx[2])[0]), ctx[7], 87);
    p[9] = (u32)WIFIBATTLEMATCH_UTIL_Create(0, 15, 14, 10, (void *)p[3], (void *)p[2], 87);
    p[13] = (u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)p, (int)WIFIBATTLEMATCH_NET_TaskStepA, 87);
    p[14] = (u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)p, 0, 87);
    p[8] = (u32)WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)p[0]), (void *)p[1], 87);
    WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)p[8], 0);
    if (ctx[3] != 0) {
        if (ctx[0] == 0) {
            WIFIBATTLEMATCH_NET_SetupBoxAndWait((char *)p, 0);
        } else if (ctx[0] == 1) {
            if (ctx[3] == 1)
                WIFIBATTLEMATCH_NET_IncBsubwayStat(ctx[4], ((u32 *)ctx[2])[1], *(u32 *)ctx[11]);
            WIFIBATTLEMATCH_NET_SetupBoxAndWait((char *)p, 1);
        }
    }
    WIFIBATTLEMATCH_NET_RestartNet((char *)p[12], 1);
    return 1;
}
