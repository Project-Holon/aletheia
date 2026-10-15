/*
 * function: COMM_BTL_DEMO_MAIN_Tick
 * address: 0x021B98EC
 * packet: pkt_ov213_021B98EC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   getState 0x021B61FC thumb ov067
 *   advance 0x021B6200 thumb ov067
 *   tick 0x021BA444 thumb ov213
 *   code 0x021BA81C thumb ov213
 *   test 0x021B9E50 thumb ov213
 *   select 0x021BA95C thumb ov213
 *   first 0x021B9864 thumb ov213
 *   second 0x021B98A0 thumb ov213
 *   reset 0x021BA480 thumb ov213
 *   busy 0x021BA9D0 thumb ov213
 *   soundFor 0x021B98DC thumb ov213
 *   sound 0x020061E4 thumb
 *   animate 0x021BA8E8 thumb ov213
 *   fade 0x0204E720 arm
 *   records 0x021BB0A4 data a4
 */
#include "../include/Obj02549.h"
#include "../include/Obj25687.h"
#include "../include/Obj25688.h"
#include "../include/Obj25689.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Record { int a,b,c; };
struct Table { struct Record a; u32 callback[3]; struct Record b,c; u8 gap[24]; struct Record d; };
extern const struct Table records;
extern u32 getState(const u8 *);
extern void advance(u8 *);
extern void tick(char *);
extern void code(u8 *,u32);
extern int test(u32);
extern void select(u8 *,int);
extern void first(u8 *);
extern void second(char *);
extern void reset(char *);
extern int busy(u8 *);
extern int soundFor(int,int);
extern void sound(int);
extern int animate(char *,int,const struct Record *);
extern void fade(u32,int,int,int);
int COMM_BTL_DEMO_MAIN_Tick(u8 *task,char *p)
{
    u32 state;
    struct Record a,b,c,d;
    state=getState(task);
    tick(p);
    switch(state) {
    case 0:
        code((u8 *)p+0x24,13);
        if(test(((struct Obj02549 *)p)->f49C8)) {
            select((u8 *)p+0x24,0);
            first((u8 *)p);
        } else {
            select((u8 *)p+0x24,2);
            second(p);
        }
        reset(p);
        advance(task);
        break;
    case 1:
        if(busy((u8 *)p+0x24)==0) {
            select((u8 *)p+0x24,4);
            if(((struct Obj25687 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50) code((u8 *)p+0x24,11);
            else code((u8 *)p+0x24,10);
            ((struct Obj02549 *)p)->f49D0=0;
            advance(task);
        }
        break;
    case 2:
        busy((u8 *)p+0x24);
        if(((struct Obj02549 *)p)->f49D0==15) {
            sound(soundFor(1,((struct Obj25688 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50));
            a=records.a; animate(p+0x24,0,&a);
            b=records.d; animate(p+0x24,1,&b);
            c=records.b; animate(p+0x24,2,&c);
        } else if(((struct Obj02549 *)p)->f49D0==25) {
            d=records.c; animate(p+0x24,3,&d);
        } else if(((struct Obj02549 *)p)->f49D0==160) { fade(12,0,16,-3);
        } else if(((struct Obj02549 *)p)->f49D0==150) { sound(soundFor(3,((struct Obj25689 *)(*(char * *)&((struct Obj02549 *)p)->f4))->f50));
        } else if(((struct Obj02549 *)p)->f49D0==168) {return 1;
        }
        (((struct Obj02549 *)p)->f49D0)++;
        break;
    }
    return 0;
}
