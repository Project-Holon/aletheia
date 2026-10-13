/*
 * function: func_021E6FD4
 * address: 0x021E6FD4
 * packet: pkt_ov119_021E6FD4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021E6FC8 0x021E6FC8 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { short x,y,z; u8 a,b; } Create;
typedef struct { short v; void *p; void (*fn)(void *); } Callback;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
struct Cmd;
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void func_021E7058(void *);
extern void func_021E6FC8(char *p);
void func_021E6FD4(char *p, int x, int y) {
    Callback cb;
    Create c;
    c.x=x+12;c.y=y+12;c.z=24;c.a=0;c.b=0;
    func_021E7058(p);
    ((struct Obj00001 *)p)->fF24=(int)CLACT_CreateActor((void *)((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f894,((struct Obj00001 *)p)->f880,((struct Obj00001 *)p)->f8B0,&c,1,((struct Obj00001 *)p)->f5F4);
    func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fF24,1);
    func_0204B92C((struct Obj *)((struct Obj00001 *)p)->fF24,1);
    p[0x11f5]=0;
    cb.v=0;cb.p=p;cb.fn=(void (*)(void *))func_021E6FC8;
    CLACT_ApplyActorAnimCommand((struct Actor *)(((struct Obj00001 *)p)->fF24),(const struct Cmd *)(&cb));
}
