/*
 * function: func_021B78E0
 * address: 0x021B78E0
 * packet: pkt_ov180_021B78E0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: 021B77DC receives full-word fifth/sixth arguments; its body truncates
 *   them internally. A narrow extern added a caller-side shift pair absent here.
 * arity: 020185F0 is a bare bx lr declared void(void) in its unit;
 *   this caller supplies a pointer in r0 and consumes that untouched r0.
 * symbols:
 *   func_020185F0 0x020185F0 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EF14 0x0201EF14 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021B77DC 0x021B77DC thumb ov180
 */
#include "../include/Obj01273.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
struct Sav; struct WordSet; struct CharBuf; struct MsgBank; struct StrObj;
extern struct Sav *func_020185F0(struct Sav *);
extern u32 func_02017DBC(struct Sav *),func_02017DE4(struct Sav *,u32);
extern u32 func_02017E88(void *,u32,u32);
extern void func_02043B5C(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EF14(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_02045808(struct StrObj *);
extern u32 func_0201D304(struct StrObj *,u32,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_021B77DC(char *,int,void *,struct StrObj *,int,int);
void func_021B78E0(char *p) {
    struct Sav *mon;
    u32 lock,width;
    struct StrObj *str;
    mon=func_020185F0(*(struct Sav **)((u32)p+((struct Obj01273 *)p)->f915D*4+0x9140));
    lock=func_02017DBC(mon);
    func_02043B5C(*(struct CharBuf * *)&((struct Obj01273 *)p)->f912C,0);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,1);
    func_0201EF14(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,0,mon);
    func_0201F250(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,((struct Obj01273 *)p)->f9040,str);
    func_021B77DC(p,1,((struct Obj01273 *)p)->f9030,*(struct StrObj * *)&((struct Obj01273 *)p)->f9040,8,0);
    func_02045808(str);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,2);
    width=func_0201D304(str,*(u32 *)&((struct Obj01273 *)p)->f9030,0);
    func_021B77DC(p,1,((struct Obj01273 *)p)->f9030,str,112,0);
    func_02045808(str);
    str=func_02045EC0(*(struct MsgBank * *)&((struct Obj01273 *)p)->f9038,3);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,0,func_02017E88(mon,158,0),3,0,1);
    func_0201F250(*(struct WordSet * *)&((struct Obj01273 *)p)->f903C,((struct Obj01273 *)p)->f9040,str);
    func_021B77DC(p,1,((struct Obj01273 *)p)->f9030,*(struct StrObj * *)&((struct Obj01273 *)p)->f9040,width+112,0);
    func_02045808(str);
    func_02017DE4(mon,lock);
}
