/*
 * function: func_021DCFC8
 * address: 0x021DCFC8
 * packet: pkt_ov121_021DCFC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF99C 0x021DF99C data a4
 */
#include "../include/Obj00237.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct {u32 w[12];} Desc;
typedef struct {u32 w[30];} Config;
typedef struct {s16 x,y,z;u8 a,b;} Record;
extern char d_021DFBB0[];
extern const Config d_021DF99C;
struct Actor;
struct Obj;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021DA1BC(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,int);
extern struct Obj *func_0204B294(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_0202D7C8(int a0);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern int func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D81C(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
void *func_021DCFC8(const Desc *p,u16 heap)
{
    char *out;
    Config config;
    Record first;
    Record second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    ((struct Obj00237 *)out)->f88=p->w[5];
    ((struct Obj00237 *)out)->f94=p->w[0];
    ((struct Obj00237 *)out)->f96=p->w[1];
    *(Desc *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        ((struct Obj00237 *)out)->f9C=0;
        ((struct Obj00237 *)out)->f98=0;
        ((struct Obj00237 *)out)->f84=1;
    } else {
        ((struct Obj00237 *)out)->f9C=4;
        ((struct Obj00237 *)out)->f98=1;
        ((struct Obj00237 *)out)->f84=0;
    }
    config=d_021DF99C;
    ((struct Obj00237 *)out)->f0=func_021DA1BC((void *)1,(const char *)&config,5,((struct Obj00237 *)out)->fA4,((struct Obj00237 *)out)->fAC,((struct Obj00237 *)out)->fC8,((struct Obj00237 *)out)->fC0,((struct Obj00237 *)out)->fC4,heap);
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj00237 *)out)->f4=func_0204ABF0(arc,3,((struct Obj00237 *)out)->f98,(u16)(p->w[4]<<5),heap);
    *(int *)&((struct Obj00237 *)out)->fC=func_0204AF28(arc,33,36,heap);
    *(int *)&((struct Obj00237 *)out)->f8=func_0204A6C8(arc,12,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc);
    func_02082BCC(&first,0,8);
    first.x=216;first.y=22;
    ((struct Obj00237 *)out)->f1C=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f8,((struct Obj00237 *)out)->f4,((struct Obj00237 *)out)->fC,&first,((struct Obj00237 *)out)->f98,heap);
    func_0204B688(((struct Obj00237 *)out)->f1C,0);
    func_0204B3DC(((struct Obj00237 *)out)->f1C,0);
    arc2=(void *)func_0202D7C8(heap);
    *(int *)&((struct Obj00237 *)out)->f10=func_0202D7D8((int)arc2,1,0,0,0,0,0,((struct Obj00237 *)out)->f98,p->w[5]<<5,heap);
    *(int *)&((struct Obj00237 *)out)->f18=func_0202D898(1,0,0,0,0,0,2,((struct Obj00237 *)out)->f98,heap);
    *(int *)&((struct Obj00237 *)out)->f14=func_0202D81C(arc2,1,0,0,0,0,0,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc2);
    func_02082BCC(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    ((struct Obj00237 *)out)->f8C=second.b;
    ((struct Obj00237 *)out)->f90=p->w[1]&3;
    ((struct Obj00237 *)out)->f20=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f14,((struct Obj00237 *)out)->f10,((struct Obj00237 *)out)->f18,&second,((struct Obj00237 *)out)->f98,heap);
    CLACT_SetActorAffineMode(((struct Obj00237 *)out)->f20,2);
    func_0204B688(((struct Obj00237 *)out)->f20,1);
    func_0204B3DC(((struct Obj00237 *)out)->f20,0);
    return out;
}
