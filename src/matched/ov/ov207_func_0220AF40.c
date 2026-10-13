/*
 * function: func_0220AF40
 * address: 0x0220AF40
 * packet: pkt_ov207_0220AF40
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 0203159C leaves the allocated pointer in r0; the struct pointer is declared as its return type.
 * note: final push 2026-10-05 G3L2: the zero field store goes into both branches of the enabled test, flag zero set after; closed.
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   overlay67 0x00000043 data
 *   overlay206 0x000000CE data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0220B318 0x0220B318 thumb ov207
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_0220B428 0x0220B428 thumb ov207
 *   func_021B9DE0 0x021B9DE0 thumb ov206
 *   func_0220B55C 0x0220B55C thumb ov207
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0220B260 0x0220B260 thumb ov207
 *   func_0220B2F8 0x0220B2F8 thumb ov207
 *   func_020056A0 0x020056A0 thumb
 *   FADE_Start 0x0204E720 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Main { u16 heap,pad; void *display,*font; u32 gfx; int enabled,zero; u32 unused[2]; void *mon,*other,*task; int flag,last; };
extern char overlay67[],overlay206[];
extern int func_02034AC4(int);
struct GfFont;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,int);
extern void *func_0220B318(int,int);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern u32 func_0220B428(u8 *p);
extern void *func_021B9DE0(u16,void *,u32,u32,u32,u32,u8,u32,u32,u32,u32,u32,u32);
extern char *func_0220B55C(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void func_0220B260(u32 *);
extern void func_0220B2F8(int,char *);
extern void *func_020056A0(u32,u32,u32);
extern void FADE_Start(u32,int,int,int);
int func_0220AF40(void *owner,int unused,u32 *args)
{
    struct Main *p;
    int flag;
    func_02034AC4((int)overlay67);
    func_02034AC4((int)overlay206);
    GFL_HEAP_CreateChildHeap((u32)((void *)1),0x6a,0x80000);
    p=PROCSYS_AllocProcWork(owner,0x34,0x6a);
    MI_CpuFill8(p,0,0x34);
    p->heap=0x6a;
    p->display=func_0220B318(1,p->heap);
    p->font=GF_FONT_Create(0x17,0,0,0,p->heap);
    p->gfx=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    if(args[0]==0) { p->enabled=0; p->zero=0; } else { p->enabled=1; p->zero=0; }
    flag=0;
    if(args[0]!=0) flag=1;
    p->mon=func_021B9DE0(p->heap,(void *)args[1],args[2],1,flag,0,0,func_0220B428(p->display),(u32)p->font,p->gfx,0,0,0);
    p->other=func_0220B55C(p->heap,args[1],args[3],args[4],args[5],func_0220B428(p->display),(u32)p->font,p->gfx,args[6]);
    GFL_NET_RestartWithDefaultTimeout(0,p->heap);
    if(p->enabled==1) func_0220B260((u32 *)p);
    p->task=func_020056A0((u32)func_0220B2F8,(u32)p,1);
    FADE_Start(3,16,0,2);
    return 1;
}
