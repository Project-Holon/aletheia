/*
 * function: func_02183B60
 * address: 0x02183B60
 * packet: pkt_ov219_02183B60
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0204363C resides in src/matched/arm9/unit_0204361C.c but is omitted from function:. Owner must list BG_SYS_ResetSubDisplay,func_0204363C,func_02043658 and regenerate its shard. tu --suggest-split cannot isolate this caller.
 * blocker: 0204363C independently verified EXACT28B ARM, no-region one, dsi/1.1p1 -O4,p c99.
 *   typedef unsigned short u16; typedef unsigned int u32;
 *   void func_0204363C(u32 swap) {
 *     *(volatile u16 *)0x04000304 = (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 * prototype: 3159C's void legacy allocator leaves live r0 used as the context pointer; copy full-width payload. Heap truncations before calls use narrow extern args.
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02009470 0x02009470 thumb
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02009524 0x02009524 thumb
 *   func_021844E4 0x021844E4 thumb ov219
 *   func_02184558 0x02184558 thumb ov219
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0204363C 0x0204363C arm
 *   TCBL_Create 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   func_0201C440 0x0201C440 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_021845B4 0x021845B4 thumb ov219
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Big;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct Tcbl;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,u32,u32);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u8 *func_02012944(void *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern const u8 GAME_LANGUAGE_Code;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02009524(const struct Sub02009470Obj *obj);
extern void func_021844E4(void);
extern void func_02184558(unsigned heap);
struct WordSet;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void func_0204363C(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_02028590(u32,u32,u32,u16);
extern u32 func_0201C440(void *);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void func_021845B4(char *);
int func_02183B60(void *obj,void *unused,void *ctx)
{
    char *p;
    GFL_HEAP_CreateChildHeap((u32)((void *)1),0x7c,0x80000);
    p=PROCSYS_AllocProcWork(obj,0xc3bc,0x7c);
    func_02082BCC(p,0,0xc3bc);
    *(u32 *)p=0x7c;
    *(void **)(p+4)=ctx;
    *(void **)(p+8)=GAME_DATA_GetSaveControl(ctx);
    *(void **)(p+0xc)=func_02012944(*(void **)(p+4));
    *(void **)(p+0x10)=func_02009470(*(void **)(p+8));
    if(GAME_LANGUAGE_Code==1)*(u32 *)(p+0xc318)=1;
    else *(u32 *)(p+0xc318)=0;
    *(u32 *)(p+0xc33c)=func_0200856C(*(void **)(p+0xc));
    *(u32 *)(p+0xc340)=func_02008570(*(void **)(p+0xc));
    *(u32 *)(p+0xc34c)=func_02009524(*(void **)(p+0x10));
    *(u32 *)(p+0xc05c)=0;
    *(u32 *)(p+0xc060)=0;
    func_021844E4();
    func_02184558((u16)(*(u32 *)p));
    *(void **)(p+0xc0a8)=func_0201EC74(8,0x40,*(u32 *)p);
    *(u32 *)(p+0xc310)=0;
    func_0204363C(0);
    *(void **)(p+0xc0a4)=TCBL_Create((u16)(*(u32 *)p),*(u32 *)p,0x20,0x20);
    *(u32 *)(p+0xc088)=func_02028590(0xf,1,0,*(u32 *)p);
    *(u32 *)(p+0xc080)=func_0201C440((void *)(u16)*(u32 *)p);
    GFL_NET_RestartWithDefaultTimeout(1,(u16)(*(u32 *)p));
    BG_SYS_SetSubPlaneVisible(0x10,1);
    func_021845B4(p);
    return 1;
}
