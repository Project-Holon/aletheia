/*
 * function: func_021F1440
 * address:  0x021F1440
 * packet:   pkt_ov194_021F1440
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200C104  0x0200C104  thumb
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021F4AE4  0x021F4AE4  thumb  ov194
 *   func_021F4BEC  0x021F4BEC  thumb  ov194
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   func_021F1780  0x021F1780  thumb  ov194
 *   func_021F1888  0x021F1888  thumb  ov194
 *   func_021F4408  0x021F4408  thumb  ov194
 *   func_021F3FBC  0x021F3FBC  thumb  ov194
 *   func_021F4D3C  0x021F4D3C  thumb  ov194
 *   STRBUF_Clone  0x02045874  arm
 *   STRBUF_GetLength  0x020458F8  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_021F5004  0x021F5004  thumb  ov194
 *   STRBUF_Clear  0x0204581C  arm
 *   func_021F45EC  0x021F45EC  thumb  ov194
 *   func_021F463C  0x021F463C  thumb  ov194
 *   func_021F1E28  0x021F1E28  thumb  ov194
 *   func_021F3008  0x021F3008  thumb  ov194
 *   func_021F3CD0  0x021F3CD0  thumb  ov194
 *   func_021F3EB0  0x021F3EB0  thumb  ov194
 *   func_021F5304  0x021F5304  thumb  ov194
 *   func_021F3DE0  0x021F3DE0  thumb  ov194
 *   func_021F3E18  0x021F3E18  thumb  ov194
 *   func_021F3D70  0x021F3D70  thumb  ov194
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   SAVE_CONTROL_INTR_Resume  0x021BD374  thumb  ov088
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct U16Vec;

struct Blk34;
struct GfFont;
struct MsgBank;
struct WordSet;
extern u8 func_0200C104(struct Blk34 *p, u32 i);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, u32, u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern unsigned char *func_021F4AE4(unsigned swap, unsigned short heap);
extern unsigned func_021F4BEC(unsigned char *p);
extern void *BMP_OAM_CreateSys(u32 a0, void *a1);
extern void func_021F1780(int unused, u16 heap);
extern void func_021F1888(char *p, unsigned owner, u16 heap);
extern int func_021F4408(int x, int y);
extern void func_021F3FBC(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);
extern u32 *func_021F4D3C(u32 heap);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u32 func_021F5004(u16 *s, u32 x);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void func_021F45EC(u8 *a, u32 b, u32 c);
extern void func_021F463C(unsigned char *p, int *unused, unsigned char *q);
extern void func_021F1E28(u8 *p, u32 a, u32 b, u32 c, u32 d, u8 *e, u32 f);
extern void func_021F3008(u8 *p, int mode, void *font, void *window, void *data, void *palette, u32 heap);
extern void func_021F3CD0(u8 *p, int a, int b, int c, int d, u16 e);
extern void func_021F3EB0(char *p, int v);
extern u32 func_021F5304(u16 heap);
extern void func_021F3DE0(char *, int, u32, u32, u16);
extern void func_021F3E18(char *, int, void *);
extern void func_021F3D70(char *, int);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern void SAVE_CONTROL_INTR_Resume(unsigned char *p);

u32 func_021F1440(struct Obj0203159C *a, u32 b, u8 *args)
{
    u8 *w;
    int mode;
    u32 s;
    u16 h;

    mode = 0;
    if (*(u32 *)(args + 0x28) != 0) {
        mode = func_0200C104((struct Blk34 *)(*(u32 *)(args + 0x28)), *(u32 *)args);
        if (mode >= 5) {
            mode = 0;
        }
    }
    GFL_HEAP_CreateChildHeap(1, 0x1e, 0x70000);
    w = PROCSYS_AllocProcWork(a, 0x2d4, 0x1e);
    MI_CpuFill8(w, 0, 0x2d4);
    *(u8 **)(w + 0x2c4) = args;
    *(u32 *)(w + 0x2b0) = (u32)GF_FONT_Create(0x17, 0, 1, 0, 0x1e);
    *(u32 *)(w + 0x2b4) = (u32)PRINTSYS_QUE_CreateEx(0x1000, 0x1e);
    *(u32 *)(w + 0x2b8) = (u32)func_02045B38(1, 2, 0x51, 0x1e);
    *(u32 *)(w + 0x2bc) = (u32)func_0201EC64(0x1e);
    *(u32 *)w = (u32)func_021F4AE4(0, 0x1e);
    *(u32 *)(w + 0x2c0) = (u32)BMP_OAM_CreateSys(0x1e, (void *)func_021F4BEC((unsigned char *)(*(u32 *)w)));
    func_021F1780((int)(w + 0x64), 0x1e);
    s = func_021F4BEC((unsigned char *)(*(u32 *)w));
    func_021F1888((char *)(w + 4), s, 0x1e);
    h = *(u16 *)(args + 4);
    func_021F3FBC(w + 0x264, func_021F4408(*(u32 *)args, h), h, *(u16 *)(args + 6), s,
                  *(u32 *)(w + 0x2b0), *(u32 *)(w + 0x2b4), (void *)(*(u32 *)(w + 0x2b8)), *(u32 *)(w + 0x2c0), 0x1e);
    *(u32 *)(w + 0x22c) = (u32)func_021F4D3C(0x1e);
    *(u32 *)(w + 0x2d0) = (u32)STRBUF_Clone(*(struct U16Vec **)(args + 0x20), 0x1e);
    if (STRBUF_GetLength(*(struct U16Vec **)(w + 0x2d0)) != 0) {
        if (STRBUF_GetLength(*(struct U16Vec **)(w + 0x2d0)) > *(u32 *)(args + 0x18)
            || func_021F5004(STRBUF_GetChars(*(struct U16Vec **)(w + 0x2d0)), 0x1e) == 0) {
            STRBUF_Clear(*(struct U16Vec **)(w + 0x2d0));
        }
    }
    func_021F45EC(w + 0x2a0, (u32)w, (u32)func_021F463C);
    func_021F1E28(w + 0x68, *(u32 *)(w + 0x2d0), (u8)*(u32 *)(args + 0x18), *(u32 *)(w + 0x2b0),
                  *(u32 *)(w + 0x2b4), (u8 *)((u32)(w + 4)), 0x1e);
    func_021F3008(w + 0xfc, mode, *(void **)(w + 0x2b0), *(void **)(w + 0x2b4), *(void **)(w + 0x22c), w + 4, 0x1e);
    func_021F3CD0(w + 0x230, *(u32 *)(w + 0x2b0), *(u32 *)(w + 0x2b8), *(u32 *)(w + 0x2b4), *(u32 *)(w + 0x2bc), 0x1e);
    func_021F3EB0((char *)(w + 0x254), 0x1e);
    *(u32 *)(w + 0x2cc) = func_021F5304(0x1e);
    if (*(u32 *)args == 1) {
        if (*(u32 *)(args + 8) == 0) {
            func_021F3DE0((char *)(w + 0x230), *(u32 *)args, *(u16 *)(args + 4), *(u16 *)(args + 6), 0x1e);
        } else {
            func_021F3E18((char *)(w + 0x230), *(u32 *)args, *(void **)(args + 8));
        }
    } else {
        func_021F3D70((char *)(w + 0x230), *(u32 *)args);
    }
    if (GFL_NET_GetRunState()) {
        GFL_NET_RestartWithDefaultTimeout(1, 0x1e);
    }
    if (*(u32 *)(*(u8 **)(w + 0x2c4) + 0x24) != 0) {
        SAVE_CONTROL_INTR_Resume((unsigned char *)(*(u32 *)(*(u8 **)(w + 0x2c4) + 0x24)));
    }
    return 1;
}
