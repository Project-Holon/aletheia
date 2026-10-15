/*
 * function: func_021D85C0
 * address: 0x021D85C0
 * packet: pkt_ov129_021D85C0
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 020434CC is in unit_0204349C.c but omitted from function:;
 *   one MATCH (020434B4 unwitnessed), enclosing 0204349C TU EXACT:
 *   extern unsigned d_02146A48[];
 *   void BG_SYS_ClearMainBgPlanes(void) { d_02146A48[1]&=16; }
 *   void BG_SYS_ClearMainObjPlane(void) { d_02146A48[1]&=15; }
 *   void BG_SYS_ClearMainPlanes(void) { BG_SYS_ClearMainBgPlanes(); BG_SYS_ClearMainObjPlane(); }
 * blocker: ARM9 02043588 is in unit_02043570.c but omitted from function:;
 *   one EXACT, fixed compiler/flags ARM:
 *   extern void BG_SYS_ClearSubBgPlanes(void),BG_SYS_ClearSubObjPlane(void);
 *   void BG_SYS_ClearSubPlanes(void) { BG_SYS_ClearSubBgPlanes(); BG_SYS_ClearSubObjPlane(); }
 * note: local allocated pointer, separate from entry object, fixes r4/r5 coloring.
 * note: 0203159C own void prototype widened because caller consumes returned r0.
 * volatile: GX registers read at 021D8642/021D864C and written at 021D864A/021D8650.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_020490F4 0x020490F4 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   PALANM_Create 0x02021518 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   func_021D8804 0x021D8804 thumb ov129
 *   func_021D9838 0x021D9838 thumb ov129
 *   func_021D89C4 0x021D89C4 thumb ov129
 *   func_021D9490 0x021D9490 thumb ov129
 *   func_0207D63C 0x0207D63C arm
 *   func_021D893C 0x021D893C thumb ov129
 *   func_020056A0 0x020056A0 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   d_021DA800 0x021DA800 data a4
 */
typedef unsigned u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u32 words[9]; } Param;
struct GfFont;
struct Obj02021EE4;
struct PalAnmSlot;
struct Param;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,u32);
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern u32 func_020307B0(void *p);
extern void BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void * PALANM_Create(u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_021D8804(void);
extern void func_021D9838(char *p, unsigned a);
extern void func_021D89C4(char *p);
extern void func_021D9490(char *p);
extern void func_0207D63C(void *,int,int,int,int);
extern void func_021D893C(int,char *);
extern void *func_020056A0(u32,u32,u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern const u32 d_021DA800[];
static inline void GX_SetVisiblePlane(int plane) { *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & ~0x1F00u)|((u32)plane<<8); }
static inline void GXS_SetVisiblePlane(int plane) { *(volatile u32 *)0x04001000=(*(volatile u32 *)0x04001000 & ~0x1F00u)|((u32)plane<<8); }
int func_021D85C0(void *obj,void *unused,const Param *cfg)
{
    u8 *p;
    u32 sizes[3];
    Param *q;
    GFL_HEAP_CreateChildHeap((u32)((void *)1),50,0x40000);
    p=PROCSYS_AllocProcWork(obj,0x34C,50);
    MI_CpuFill8(p,0,0x34C);
    if(cfg==0) {
        sizes[0]=4; sizes[1]=4; sizes[2]=4;
        q=(Param *)CODEIN_PARAM_Create(50,0,0,12,sizes);
        *(Param *)(p+0x328)=*q;
        func_020307B0(q);
    } else *(Param *)(p+0x328)=*cfg;
    BG_SYS_ClearMainPlanes(); BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0); GXS_SetVisiblePlane(0);
    *(void **)(p+0x258)=func_020490F4(59,50);
    BG_SYS_Create(50); BMP_WIN_Init(50);
    *(void **)(p+0x290)=PALANM_Create(50);
    *(void **)(p+0x314)=GF_FONT_Create(23,0,0,0,50);
    PALANM_SetAutoTransfer(*(void **)(p+0x290),1);
    PALANM_AllocSlotBuffers(*(void **)(p+0x290),0,512,50);
    func_021D8804();
    func_021D9838((char *)p,(unsigned int)d_021DA800); func_021D89C4((char *)p); func_021D9490((char *)p);
    func_0207D63C((void *)0x04000050,0,6,15,7);
    func_0207D63C((void *)0x04001050,0,14,7,8);
    *(void **)(p+0x318)=func_020056A0((u32)func_021D893C,(u32)p,16);
    GFL_NET_RestartWithDefaultTimeout(1,50);
    return 1;
}
