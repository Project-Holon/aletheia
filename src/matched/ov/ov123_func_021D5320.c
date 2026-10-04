/*
 * function: func_021D5320
 * address: 0x021D5320
 * packet: pkt_ov123_021D5320
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_02012204 0x02012204 thumb
 *   func_0203CD98 0x0203CD98 arm
 *   func_020310C4 0x020310C4 arm
 *   func_02040618 0x02040618 arm
 *   func_0204A600 0x0204A600 arm
 */
#include "../include/Obj01733.h"
extern void func_02027974(void *);
extern int func_0203CD98(void);
typedef unsigned int   u32;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 func_0201058C(void *key);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A600(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(unsigned int,unsigned int);
int func_021D5320(int a,int b,int c,char *p)
{
    int result=1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result=0;
    }
    if (((struct Obj01733 *)p)->f238) func_02027974(((struct Obj01733 *)p)->f238);
    if (func_0203CD98()) {
        ((struct Obj01733 *)p)->f27C=((struct Obj01733 *)p)->f278;
        ((struct Obj01733 *)p)->f278=func_0201058C(0);
    }
    func_020310C4(((struct Obj01733 *)p)->f230);
    func_0201C4E4(((struct Obj01733 *)p)->f234);
    func_02040618(4,3,((struct Obj01733 *)p)->f268);
    --((struct Obj01733 *)p)->f268;
    func_0204A600();
    if (!((struct Obj01733 *)p)->f28C) func_020121CC(((struct Obj01733 *)p)->f264);
    if (func_020221A4() && func_02012204(((struct Obj01733 *)p)->f264)) {
        ((struct Obj01733 *)p)->f8=0;
        result=1;
        func_0202223C(0,0);
        func_0202223C(1,0);
    }
    return result;
}
