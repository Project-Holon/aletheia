/*
 * function: WORLDTRADE_ProcInit
 * address:  0x021F4580
 * packet:   pkt_021F4580
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
  *
  *
  *
  *
  *
  *
 * symbols:
 *   WORLDTRADE_ADAPTER_AllocHeapBuf  0x02202608  thumb
 *   WORLDTRADE_ADAPTER_InitPrinter  0x022026D8  thumb
 *   WORLDTRADE_CallStateHandler  0x021F489C  thumb
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb
 *   g_02203F80  0x02203F80  data
 *   str_02203AF8  0x02203AF8  data  a1
 *   ov114_id  0x00000072  data
 *   ov067_id  0x00000043  data
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb  arm9
 *   PROCSYS_Create  0x02031324  arm  arm9
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   WORDSET_Create  0x0201EC74  thumb  arm9
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 pad0[0x20];
    u32 x20;
} Args;

typedef struct {
    u8 pad0[0xB68];
    void *words;
    void *msg[5];
    u8 padB80[0xEA8 - 0xB80];
    void *mon;
    u8 padEAC[0xF94 - 0xEAC];
    void *rec;
    u8 padF98[0xF9C - 0xF98];
    void *recMem;
    u8 ctx[0x12F0 - 0xFA0];
    void *save;
    u8 pad12F4[0x132C - 0x12F4];
} Work;

struct Ctx;
struct MsgBank;
struct WordSet;
extern int func_02034AC4(s32 handle);
extern u8 ov114_id[];
extern u8 ov067_id[];
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern void *WORLDTRADE_ADAPTER_AllocHeapBuf(u32 heap);
extern void *PROCSYS_Create(int a0);
extern u32 func_02030CB0(u32 n);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void WORLDTRADE_ADAPTER_InitPrinter(void *ctx, u32 arg);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void WORLDTRADE_CallStateHandler(Work *p, Args *args);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void WORLDTRADE_ClearAndShowPlanes(Work *p);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);

extern Work *g_02203F80;
extern const char str_02203AF8[];

int WORLDTRADE_ProcInit(void *proc, int *seq, Args *args)
{
    Work *p;

    func_02034AC4((u32)ov114_id);
    func_02034AC4((u32)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x48, 0x30100);
    p = PROCSYS_AllocProcWork(proc, sizeof(Work), 0x48);
    MI_CpuFill8(p, 0, sizeof(Work));
    g_02203F80 = p;
    p->mon = WORLDTRADE_ADAPTER_AllocHeapBuf(0x48);
    p->save = PROCSYS_Create(0x48);
    p->recMem = func_02030734(0x48, func_02030CB0(8), 0, str_02203AF8, 0xA1);
    p->rec = func_02030CBC(8, p->recMem);
    WORLDTRADE_ADAPTER_InitPrinter(p->ctx, args->x20);
    p->words = WORDSET_Create(0xB, 0x40, 0x48);
    p->msg[0] = func_02045B38(0, 2, 0xD0, 0x48);
    p->msg[2] = func_02045B38(0, 2, 0xD1, 0x48);
    p->msg[3] = func_02045B38(0, 2, 0xE8, 0x48);
    p->msg[1] = func_02045B38(0, 2, 0x46, 0x48);
    p->msg[4] = func_02045B38(0, 2, 0xE7, 0x48);
    WORLDTRADE_CallStateHandler(p, args);
    BG_SYS_ClearGraphicsMemory(0);
    WORLDTRADE_ClearAndShowPlanes(p);
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}
