/*
 * function: func_021BA4CC
 * address: 0x021BA4CC
 * packet: pkt_ov110_021BA4CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * abi: F7C4 tail-forwards p[0] to ARM9 24158, whose full body returns a
 *   bit test; A570 consumes the live r0. C728 retains its visible unused r0.
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BB9C0 0x021BB9C0 thumb ov110
 *   func_021BD000 0x021BD000 thumb ov110
 *   func_021BBB0C 0x021BBB0C thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BD028 0x021BD028 thumb ov110
 *   func_021BCB50 0x021BCB50 thumb ov110
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BB7A0 0x021BB7A0 thumb ov110
 *   func_021BBEF4 0x021BBEF4 thumb ov110
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BB7B8 0x021BB7B8 thumb ov110
 *   func_021BBF54 0x021BBF54 thumb ov110
 *   func_021BC728 0x021BC728 thumb ov110
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj01530.h"
#include "../include/Obj03237.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
struct Object;
extern void func_021BCEE4(char *p, u32 mode);
extern void func_021BB9C0(u8 *,int);
extern int func_021BD000(char *p);
extern int func_021BBB0C(u8 *,int);
extern int func_021BCF38(char *p, u32 mode);
extern int func_021BD028(u8 *);
extern void func_021BCB50(struct Object *p);
extern void func_021BB658(u8 *,int);
extern void func_021BB7A0(u8 *);
extern void func_021BBEF4(u8 *,u8);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern void func_021BAD68(u8 *,int);
extern int func_021BB7B8(u8 *);
extern int func_021BBF54(u8 *);
extern void func_021BC728(u8 *);
extern void func_021BC6F8(void *);
extern void func_021B9CBC(u8 *);
void func_021BA4CC(void *unused,u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj03237 *)p)->f0;
    int a,b;
    switch(((struct Obj03237 *)p)->f14) {
    case 0:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            func_021BCEE4((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
            func_021BB9C0(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        } else func_021BD000((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        ++((struct Obj03237 *)p)->f14;
        break;
    case 1:
        if(func_021BF6DC(*(u8 * *)&((struct Obj03237 *)p)->f4)==1) {
            a=func_021BBB0C(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
            b=func_021BCF38((char *)(*(u8 * *)&((struct Obj01530 *)q)->f64),0);
        } else {
            a=func_021BD028(*(u8 * *)&((struct Obj01530 *)q)->f64);
            b=1;
        }
        if(a && b) ++((struct Obj03237 *)p)->f14;
        break;
    case 2:
        func_021BCB50((struct Object *)(*(u8 * *)&((struct Obj01530 *)q)->f64));
        func_021BB658(*(u8 * *)&((struct Obj01530 *)q)->f58,0);
        func_021BB7A0(*(u8 * *)&((struct Obj01530 *)q)->f58);
        func_021BBEF4(*(u8 * *)&((struct Obj01530 *)q)->f54,1);
        if(func_021BF7C4(*(u8 * *)&((struct Obj03237 *)p)->f4) || func_021BF6D8(*(u8 * *)&((struct Obj03237 *)p)->f4)!=2) func_021BAD68(p,1);
        else func_021BAD68(p,0);
        ++((struct Obj03237 *)p)->f14;
        break;
    case 3:
        a=func_021BB7B8(*(u8 * *)&((struct Obj01530 *)q)->f58);
        b=func_021BBF54(*(u8 * *)&((struct Obj01530 *)q)->f54);
        if(a && b) {
            func_021BC728(*(u8 * *)&((struct Obj01530 *)q)->f54);
            func_021BC6F8(*(u8 * *)&((struct Obj01530 *)q)->f54);
            q[0x74]=0;
            func_021B9CBC(p);
        }
        break;
    }
}
