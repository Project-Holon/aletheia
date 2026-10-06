/*
 * function: func_021BAB0C
 * address: 0x021BAB0C
 * packet: pkt_ov110_021BAB0C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCEE4 0x021BCEE4 thumb ov110
 *   func_021BCF38 0x021BCF38 thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BF72C 0x021BF72C thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj04443.h"
#include "../include/Obj10268.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BCEE4(char *p, u32 mode);
extern int func_021BCF38(char *p, u32 mode);
extern void func_021BCF7C(u8 *p, int n, int v);
extern u16 func_021BF724(u8 *);
extern u16 func_021BF72C(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BAB0C(void *unused,u8 *p) {
    u8 *q;
    q=*(u8 * *)&((struct Obj10268 *)p)->f0;
    switch(((struct Obj10268 *)p)->f14) {
    case 0:
        func_021BCEE4((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2);
        ++((struct Obj10268 *)p)->f14;
        break;
    case 1:
        if(func_021BCF38((char *)(*(u8 * *)&((struct Obj04443 *)q)->f64),2)) {
            if(**(u32 * *)&((struct Obj04443 *)q)->f78==0 && func_021BF724(*(u8 * *)&((struct Obj04443 *)q)->f18)==253 && func_021BF72C(*(u8 * *)&((struct Obj04443 *)q)->f18)==253)
                func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,1,1);
            else func_021BCF7C(*(u8 * *)&((struct Obj04443 *)q)->f64,0,0);
            func_021B9CBC(p);
        }
        break;
    }
}
