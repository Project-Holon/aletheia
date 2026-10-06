/*
 * function: func_021F8480
 * address: 0x021F8480
 * packet: pkt_ov185_021F8480
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201C440 0x0201C440 thumb
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_02025538 0x02025538 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_02040588 0x02040588 arm
 *   func_021F8EFC 0x021F8EFC thumb ov185
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021F8604 0x021F8604 thumb ov185
 */
#include "../include/Obj00278.h"
#include "../include/Obj02526.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char ov112_id[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
struct Obj24810;
extern unsigned func_021F9B9C(struct Obj24810 *p);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,unsigned);
extern u32 func_0201C440(void *);
typedef unsigned char  u8;
extern u32 func_021FC4DC(u8 *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_021F8EFC(char *p, int *source);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern void func_021F8604(int,int *,char *);
int func_021F8480(void *obj,int b,char *q)
{
    char *p;
    void *v;
    int i;
    func_02034AC4((int)ov112_id);
    p=func_0203159C(obj,88,func_021F9B9C(((struct Obj02526 *)q)->f10));
    func_02082BCC(p,0,88);
    *(char * *)&((struct Obj00278 *)p)->f34=q;
    ((struct Obj00278 *)p)->f30=func_021F9B9C(((struct Obj02526 *)q)->f10);
    ((struct Obj00278 *)p)->f2C=func_0201C440((void *)(unsigned int)((struct Obj00278 *)p)->f30);
    v=(void *)func_021FC4DC(((struct Obj02526 *)q)->f8);
    ((struct Obj00278 *)p)->f28=func_02025538(((struct Obj00278 *)p)->f30,v);
    for (i=0;i<2;i++) *(void **)(p+i*4+56)=func_021FD760((unsigned int)v,(char *)(((struct Obj02526 *)q)->fC),i,((struct Obj00278 *)p)->f30);
    func_021FBE54((char *)(((struct Obj02526 *)q)->fC),6,((struct Obj00278 *)p)->f30);
    func_02040588(0,1);
    func_021F8EFC(p,(int *)q);
    ((struct Obj00278 *)p)->f24=func_021FD6D8((int)p,(int)func_021F8604,((struct Obj00278 *)p)->f30);
    return 1;
}
