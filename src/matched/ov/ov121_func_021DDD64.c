/*
 * function: func_021DDD64
 * address: 0x021DDD64
 * packet: pkt_ov121_021DDD64
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever (wave 82, lane R10, retry): the palette base is an inline that adds
 *   the byte offset inside each arm (`if (mode==0) return off+0x05000200;
 *   else return off+0x05000600;`); the shared add cross-jumps into the
 *   `adds r1,r0,r1` join. A base-only inline plus `+ offset` at the call site,
 *   or a ternary on the base, if-converts to a default load plus override and
 *   misschedules the q+0xb0/q+0x98 loads (431 B). The heap stays u16 as in
 *   matched ov121 func_021DBF10 and matched caller func_021DE024: the earlier
 *   u32-heap owner gate does not apply.
 * symbols:
 *   func_021DBF10 0x021DBF10 thumb ov121
 *   func_021DBF40 0x021DBF40 thumb ov121
 *   func_021DBF9C 0x021DBF9C thumb ov121
 *   func_021DBF70 0x021DBF70 thumb ov121
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_02082A48 0x02082A48 arm
 *   func_0204B5F4 0x0204B5F4 arm
 *   func_0204AEF4 0x0204AEF4 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {s16 x,y;} Point;
extern void *func_021DBF10(void *,u16);
extern u32 func_021DBF40(void *);
extern int func_021DBF9C(void *);
extern u32 func_021DBF70(void *);
extern int func_021DC024(void *);
extern void *func_02049F78(void *,int,void **,u16);
extern void func_02082D44(const void *,void *,int);
extern void func_020307B0(void *);
extern void *func_02049E74(void *,int,int,void **,u16);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_02049238(void *);
extern void func_0204B6F4(void *,u8,u32);
extern void func_0204B404(void *,const Point *,u16);
struct Actor;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204ADEC(u32,void *,u32);
extern void func_02082A48(u32,void *,u32);
extern void func_0204B5F4(struct Actor *actor, u16 value);
extern void *func_0204AEF4(u32,u32);
extern void func_0207D63C(void *,int,int,int,int);
static inline void *palette(u32 off, int mode)
{
    if (mode==0) return (void *)(off+0x05000200);
    else return (void *)(off+0x05000600);
}
void func_021DDD64(char *p,char *q,u16 heap)
{
    void *arc;
    void *allocation;
    void *allocation2;
    void *res;
    void *res2;
    Point pt;
    u16 *dest;
    u32 offset;
    int i;
    arc=func_021DBF10(p,heap);
    allocation=func_02049F78(arc,func_021DBF40(p),&res,*(u16 *)(p+0x118));
    offset=*(u32 *)(q+0xb0)*32;
    func_02082D44(*(void **)((char *)res+12),palette(offset,*(u32 *)(q+0x98)),96);
    func_020307B0(allocation);
    allocation2=func_02049E74(arc,func_021DBF9C(p),0,&res2,*(u16 *)(p+0x118));
    func_0204AA94(*(int *)(q+8),*(void **)((char *)res2+20),512,0,*(int *)(q+0x98));
    func_020307B0(allocation2);
    func_02049238(arc);
    pt.x=216; pt.y=22;
    if (func_021DC024(p)==2) {pt.x+=4;pt.y+=8;}
    func_0204B6F4(*(void **)(q+28),func_021DBF70(p),0);
    func_0204B404(*(void **)(q+28),&pt,*(u32 *)(q+0x98));
    func_0204B3DC(*(void **)(q+28),1);
    if (func_021DC024(p)==1) {
        func_0204ADEC(*(u32 *)(q+16),*(void **)(*(char **)(p+0x140)+12),1);
        func_02082D44(*(void **)(*(char **)(p+0x140)+12),q+0x64,32);
        func_02082A48(0,q+0x44,32);
        func_0204AA94(*(int *)(q+20),*(void **)(*(char **)(p+0x138)+20),0x1200,0,*(int *)(q+0x98));
        func_0204B5F4(*(void **)(q+32),0);
        func_0204B3DC(*(void **)(q+32),1);
        if (*(u32 *)(q+0xa0)<4) dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000200);
        else dest=(u16 *)((u32)func_0204AEF4(*(u32 *)(q+16),*(u32 *)(q+0x98))+0x05000600);
        for(i=0;i<16;i++) dest[i]=*(u16 *)(q+0x44+i*2);
        if (*(u32 *)(q+0xa0)<4)
            func_0207D63C((void *)0x04000050,0,(1<<(u8)*(u32 *)(q+0xa0))|(1<<(u8)*(u32 *)(q+0xa4)),2,12);
        else
            func_0207D63C((void *)0x04001050,0,(1<<(u8)(*(u32 *)(q+0xa0)-4))|(1<<(u8)(*(u32 *)(q+0xa4)-4)),2,12);
    } else func_0204B3DC(*(void **)(q+32),0);
}
