/*
 * function: func_021B7560
 * address: 0x021B7560
 * packet: pkt_ov106_021B7560
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Keep visible unused 3064C r2 and 8D90 r1. 3159C leaves allocation live in r0; empty 80AC preserves p; 80B0 forwards to the first-word 7FF4 getter. Pointer casts preserve whole-word heap/index payloads unchanged.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   fill 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_020124F4 0x020124F4 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021B8B9C 0x021B8B9C thumb ov106
 *   func_021B7FF8 0x021B7FF8 thumb ov106
 *   func_021B80B0 0x021B80B0 thumb ov106
 *   func_02025538 0x02025538 thumb
 *   func_021B7890 0x021B7890 thumb ov106
 *   func_021B78E0 0x021B78E0 thumb ov106
 *   func_021B8D90 0x021B8D90 thumb ov106
 *   func_021B8FB8 0x021B8FB8 thumb ov106
 *   func_021B80AC 0x021B80AC thumb ov106
 *   func_021B80D0 0x021B80D0 thumb ov106
 *   func_021B70DC 0x021B70DC thumb ov101
 *   func_020490F4 0x020490F4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_021B92D4 0x021B92D4 thumb ov106
 *   func_021B93D8 0x021B93D8 thumb ov106
 *   func_021B93DC 0x021B93DC thumb ov106
 *   func_021B9380 0x021B9380 thumb ov106
 *   d_021B94D4 0x021B94D4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x,y; u16 a,b; } Entry;
typedef struct { s16 x,y; u16 flags; u8 a,b; } Pos;
#define SLOT(p,i) (*(u8 **)((u8 *)((u32 *)(p)+(i))+0x62c))
extern const Entry d_021B94D4[];
extern void func_0203064C(u32,u32,u32);
extern u8 *func_0203159C(void *,u32,u32);
extern void fill(void *,int,u32);
extern void *func_020120F4(const void *),*func_020124F4(u16);
extern u32 func_0201C440(void *),func_0201D7EC(int,int,int,int,u32);
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_021B8B9C(void *,u32);
extern void func_021B7FF8(u8 *,void *,u32);
extern void *func_021B80B0(u8 *);
extern u32 func_021B80AC(u8 *);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_021B7890(u8 *,u8 *,u32),func_021B78E0(void);
extern void func_021B8D90(void *,u32),func_021B8FB8(void *);
extern void func_021B80D0(u8 *,u32,u32,u32,u8,u32,void *,void *,u32,u16);
extern void *func_021B70DC(u32,void *,u16,u16,u8,u32,u32,u32,u16);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern void *func_021B92D4(const u8 *,u8,u8,int,u8,int,void *,void *,u16);
extern void func_021B93D8(u8 *,u16),func_021B93DC(u8 *,u32,u32,u32),func_021B9380(u8 *,void *,void *,int);
int func_021B7560(void *sys,u32 unused,void **args) {
    u8 *p;
    u32 e;
    void *arc;
    Pos pos;
    int i;
    func_0203064C(1,67,6<<16);
    p=func_0203159C(sys,0x648,67);
    fill(p,0,0x648);
    if(*args)*(void **)(p+0x628)=func_020120F4(*args);
    else *(void **)(p+0x628)=func_020124F4(1);
    *(u32 *)(p+0x61c)=func_0201C440((void *)67);
    *(u32 *)(p+0x618)=func_0201D7EC(23,0,0,0,67);
    *(void **)(p+0x620)=func_02045B38(0,2,50,67);
    *(u32 *)(p+0x63c)=func_021B8B9C(*(void **)(p+0x628),67);
    func_021B7FF8(p,*(void **)(p+0x628),67);
    *(void **)(p+0x624)=func_02025538(67,func_021B80B0(p));
    func_021B7890(p+0x28,p,(u32)func_021B78E0);
    func_021B8D90(p+0x5d4,67);func_021B8FB8(p+0x600);
    e=func_021B80AC(p);
    func_021B80D0(p+0x38,1,2,5,6,e,func_021B80B0(p),*(void **)(p+0x620),*(u32 *)(p+0x63c),67);
    *(void **)(p+0x614)=func_021B70DC(2,func_021B80B0(p),4,13,0,2,*(u32 *)(p+0x618),*(u32 *)(p+0x61c),67);
    arc=func_020490F4(23,67);
    *(u32 *)(p+0x644)=func_0204ACEC(arc,5,0,448,67);
    func_02049238(arc);
    fill(&pos,0,8);
    pos.x=8;pos.y=41;pos.a=0;pos.b=0;
    for(i=0;i<4;i++) {
        pos.x=d_021B94D4[i].x;pos.y=d_021B94D4[i].y;
        SLOT(p,i)=func_021B92D4((u8 *)&pos,d_021B94D4[i].a,d_021B94D4[i].b,*(int *)(p+0x644),3,0,*(void **)(p+0x624),*(void **)(p+0x61c),67);
        func_021B93D8(SLOT(p,i),1088);
        func_021B93DC(SLOT(p,i),0,0,1);
        func_021B9380(SLOT(p,i),*(void **)(p+0x620),(void *)(i+1),*(int *)(p+0x618));
    }
    return 1;
}
