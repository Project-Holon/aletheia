/*
 * function: func_021B96E0
 * address: 0x021B96E0
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B96E0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   callbacks 0x021BC84C data a4
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021BAF30 0x021BAF30 thumb ov223
 *   func_021BC4F4 0x021BC4F4 thumb ov223
 *   func_021BC508 0x021BC508 thumb ov223
 *   func_021B97F8 0x021B97F8 thumb ov223
 *   func_021BC514 0x021BC514 thumb ov223
 */
#include "../include/Obj03962.h"
extern int (*callbacks[])(char *,int *);
typedef unsigned int   u32;
struct PrintSys;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021BAF30(int *);
extern void func_021BC4F4(char *);
extern void func_021BC508(unsigned char *p);
extern void func_021B97F8(char *p);
extern void func_021BC514(unsigned char *p);
int func_021B96E0(void *a,int *state,void *b,char *p)
{
    int old=*state;
    *state=callbacks[*state](p,(int *)(p+12));
    if(*state!=13) {
        if(*state!=old) ((struct Obj03962 *)p)->fC=0;
    } else return 1;
    if(*state>=2&&*state<=11) {
        func_0201C4E4(((struct Obj03962 *)p)->f1C);
        func_021BAF30((int *)p);
        func_021BC4F4(*(char * *)&((struct Obj03962 *)p)->f14);
        func_021BC508(((struct Obj03962 *)p)->f14);
        func_021B97F8(p);
        func_021BC514(((struct Obj03962 *)p)->f14);
    }
    return 0;
}
