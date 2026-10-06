/*
 * function: func_021BEEBC
 * address: 0x021BEEBC
 * packet: pkt_ov099_021BEEBC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a named enabled result before kind initialization preserves call/store scheduling.
 * symbols:
 *   func_02155664 0x02155664 thumb ov009
 *   func_021BEE64 0x021BEE64 thumb ov099
 *   func_020490F4 0x020490F4 arm
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021C0290 0x021C0290 thumb ov099
 *   func_02082BCC 0x02082BCC arm
 *   func_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02009A54 0x02009A54 thumb
 *   func_021B95A0 0x021B95A0 thumb ov099
 *   func_021B9900 0x021B9900 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_021C1A44 0x021C1A44 thumb ov099
 *   func_021C1A58 0x021C1A58 thumb ov099
 *   func_021C282C 0x021C282C thumb ov099
 *   func_021C205C 0x021C205C thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_021BEDA0 0x021BEDA0 thumb ov099
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_02049238 0x02049238 arm
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Descriptor;
struct Obj;
struct Sub020097BCObj;
extern void func_02155664(void (*callback)(void));
struct Sub0200852CObj;
extern int func_021BEE64(void *a, char *b);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021C19A8(char *);
extern void func_021C0290(char *);
extern void func_02082BCC(void *,int,int);
extern void func_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0201F868(void *);
extern int func_021B96CC(int *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02009A54(struct Sub020097BCObj *obj);
extern void func_021B95A0(char *p, int heap, u32 x2, u32 x3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u8 *func_021B9900(u8 *p, int v);
extern void func_021BE21C(char *,void *);
extern int func_021C1A44(char *);
extern void func_021C1A58(char *,int,int);
extern int func_021C282C(u8 *p);
extern void func_021C205C(u8 *p, int v);
extern void func_021BA8EC(char *);
extern int func_021BE788(char *);
extern void func_021BEDA0(char *);
extern void func_021BDD0C(void *p, int on);
extern void func_02049238(void *);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void func_021BEEBC(char *p)
{
    void *h;
    int kind, enabled;
    func_02155664((void (*)(void))func_021BEE64);
    h=func_020490F4(33,33);
    func_021C19A8(p);
    func_021C0290(p);
    func_02082BCC(p+0x30,0,32);
    if(((struct Obj00008 *)p)->fB0){
        func_020452E8(((struct Obj00008 *)p)->f1A0);
        func_0202020C(((struct Obj00008 *)p)->fB4,0,0);
        ((struct Obj00008 *)p)->fB4=0;
        func_0201F868(((struct Obj00008 *)p)->fB0);
        ((struct Obj00008 *)p)->fB0=0;
    }
    if(!func_021B96CC((int *)(p+0x274))){
        enabled=func_02008550((const struct Sub0200852CObj *)func_02012944(((struct Obj00008 *)p)->fC4));
        kind=16;
        if(enabled)kind=17;
        ((struct Obj00008 *)p)->f132A=func_02009A54(((struct Obj00008 *)p)->f4);
        func_021B95A0(p+0x274,33,(u32)h,kind,((struct Obj00008 *)p)->f132A,33,(u32)(((struct Obj00008 *)p)->f110),(u32)(((struct Obj00008 *)p)->f114));
        func_021BE21C(p,func_021B9900((u8 *)(p+0x274),kind));
    }
    if(!func_021C1A44(p))func_021C1A58(p,(int)h,33);
    func_021C282C(((struct Obj00008 *)p)->f8);
    ((struct Obj00008 *)p)->f1351=0;
    func_021C205C((u8 *)p,33);
    func_021BA8EC(p);
    func_021BE788(p);
    func_021BEDA0(p);
    func_021BDD0C(p,0);
    ((struct Obj00008 *)p)->f1F0=-1;
    func_02049238(h);
    func_0202208C(0,1,1,0,6,1,33);
}
