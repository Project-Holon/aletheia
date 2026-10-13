/*
 * function: PLIST_PLATE_CreateActors
 * address: 0x021BA954
 * packet: pkt_ov091_021BA954
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
#include "../include/Obj07731.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u16 a,b,c;u8 d,e;} R;
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned int);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
#define P(k) (*(int *)(p+(k)))
#define S(k) (*(int *)(s+(k)))
void PLIST_PLATE_CreateActors(u8 *p,u8 *s)
{
    R a;
    R b;
    R c;
    R d;
    int x;
    a.a=16;a.b=16;a.c=0;a.d=1;a.e=2;
    x=(int)CLACT_CreateActor((void *)S(0x28),P(0x19c),P(0x178),P(0x1b8),&a,0,((struct Obj07731 *)p)->f0);
    S(0x34)=x;
    CLACT_SetActorAutoAnim((struct Obj *)x,1);
    b.a=0x54;b.b=0x1c;b.c=0;b.d=0;b.e=2;
    S(0x38)=(int)CLACT_CreateActor((void *)S(0x28),P(0x1b0),P(0x18c),P(0x1cc),&b,0,((struct Obj07731 *)p)->f0);
    c.a=32;c.b=24;c.c=0;c.d=0;c.e=2;
    x=(int)CLACT_CreateActor((void *)S(0x28),P(0x1a4),P(0x180),P(0x1c0),&c,0,((struct Obj07731 *)p)->f0);
    S(0x3c)=x;
    CLACT_SetActorDrawEnable((struct Obj *)x,0);
    d.a=32;d.b=42;d.c=0;d.d=0;d.e=2;
    x=(int)CLACT_CreateActor((void *)S(0x28),P(0x1ac),P(0x188),P(0x1c8),&d,0,((struct Obj07731 *)p)->f0);
    S(0x40)=x;
    CLACT_SetActorDrawEnable((struct Obj *)x,0);
}
