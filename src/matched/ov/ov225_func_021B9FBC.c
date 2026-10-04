/*
 * function: func_021B9FBC
 * address: 0x021B9FBC
 * packet: pkt_ov225_021B9FBC
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA240 0x021BA240 thumb ov225
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6470 0x021B6470 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021BA508 0x021BA508 thumb ov225
 *   d_021BBF2C 0x021BBF2C data a4
 */
#include "../include/Obj00367.h"
typedef unsigned char u8;
typedef struct S S;
struct Entry {unsigned word[7];};
extern const struct Entry d_021BBF2C[];
extern void func_021BA240(char *);
extern void func_021B63D0(struct S *p);
extern int func_021B6470(u8 *);
extern int func_021B6448(u8 *);
extern void func_021BA508(char *);
void func_021B9FBC(char *p)
{
    ((struct Obj00367 *)p)->f24=-1;((struct Obj00367 *)p)->f28=-1;func_021BA240(p);
    if(((struct Obj00367 *)p)->f20==1) {((struct Obj00367 *)p)->f20=0;return;}
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==2) {
        func_021B63D0(*(S * *)&((struct Obj00367 *)p)->f4);
        if(((struct Obj00367 *)p)->f20==0) {
            int result=func_021B6470(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=2;((struct Obj00367 *)p)->f24=result;}
        } else {
            int result=func_021B6448(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=1;((struct Obj00367 *)p)->f28=result;}
        }
    }
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==3) {
        func_021BA508(p);
        if(((struct Obj00367 *)p)->f20==0) {
            if(((struct Obj00367 *)p)->f44==1) {((struct Obj00367 *)p)->f20=3;*(unsigned *)&((struct Obj00367 *)p)->f24=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        } else {
            if(((struct Obj00367 *)p)->f44==3) {((struct Obj00367 *)p)->f20=1;*(unsigned *)&((struct Obj00367 *)p)->f28=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        }
    }
}
