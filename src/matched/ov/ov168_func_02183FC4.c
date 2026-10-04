/*
 * function: func_02183FC4
 * address: 0x02183FC4
 * packet: pkt_ov168_02183FC4
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * abi: ABF0 and B294 results remain live and are stored by this caller; their extern return types reflect that use.
 * symbols:
 *   func_0204B100 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 *   func_0204B604 0x0204B604 arm
 *   d_02184910 0x02184910 data a4
 *   d_021848AC 0x021848AC data a4
 */
#include "../include/Obj01262.h"
#include "../include/Obj10642.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 group,id,config;} Row;
typedef struct {short x,y,id;u8 a,b;} Config;
extern const Row d_02184910[];
extern const Config d_021848AC[];
struct Actor;
struct Bank;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32,u16);
extern u32 func_020275E4(void);
extern u32 func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *,u32,u32,u32,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
void func_02183FC4(char *p,u16 heap)
{
    void *first,*second;
    u16 i;
    const Row *r;
    char *q;
    i=0;
    ((struct Obj01262 *)p)->f1C=func_0204B100(32,0,heap);
    first=func_020490F4(106,heap);
    second=func_020490F4(func_020275E4(),heap);
    ((struct Obj01262 *)p)->f24=func_0204ABF0(first,6,0,0,heap);
    ((struct Obj01262 *)p)->f20=func_0204A6C8(first,7,0,0,heap);
    ((struct Obj01262 *)p)->f28=func_0204AF28(first,8,9,heap);
    ((struct Obj01262 *)p)->f30=func_0204ABF0(first,10,0,32,heap);
    ((struct Obj01262 *)p)->f2C=func_0204A6C8(first,11,0,0,heap);
    ((struct Obj01262 *)p)->f34=func_0204AF28(first,12,13,heap);
    ((struct Obj01262 *)p)->f3C=func_0204ABF0(first,14,0,64,heap);
    ((struct Obj01262 *)p)->f38=func_0204A6C8(first,15,0,0,heap);
    ((struct Obj01262 *)p)->f40=func_0204AF28(first,16,17,heap);
    ((struct Obj01262 *)p)->f48=func_0204ABF0(second,31,1,0,heap);
    ((struct Obj01262 *)p)->f44=func_0204A6C8(second,32,0,1,heap);
    ((struct Obj01262 *)p)->f4C=func_0204AF28(first,18,19,heap);
    func_02049238(second);
    func_02049238(first);
    do{
        r=&d_02184910[i];
        q=p+r->group*4;
        *(void **)(p+i*4)=func_0204B294((void *)*(u32 *)&((struct Obj01262 *)p)->f1C,((struct Obj10642 *)q)->f20,((struct Obj10642 *)q)->f24,((struct Obj10642 *)q)->f28,&d_021848AC[r->config],r->id,heap);
        func_0204B92C(*(void **)(p+i*4),1);
        ++i;
    }while(i<7);
    for(i=0;i<3;i++)func_0204B3DC(*(void **)(p+i*4+0x10),0);
    func_0204B570(((struct Obj01262 *)p)->f0,0);
    func_0204B604(((struct Obj01262 *)p)->f0,1,1);
    ((struct Obj01262 *)p)->fE0=10;
}
