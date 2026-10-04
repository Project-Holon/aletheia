/*
 * function: func_021D5514
 * address: 0x021D5514
 * packet: pkt_ov122_021D5514
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment at 021D55FA, then next labelled function.
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_021D5110 0x021D5110 thumb ov122
 *   func_021D5310 0x021D5310 thumb ov122
 *   func_0204A600 0x0204A600 arm
 *   func_0203CD98 0x0203CD98 arm
 *   func_0201283C 0x0201283C thumb
 *   func_0201058C 0x0201058C thumb
 *   func_021D533C 0x021D533C thumb ov122
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02040618 0x02040618 arm
 *   func_020221A4 0x020221A4 thumb
 *   func_020121CC 0x020121CC thumb
 *   func_02012204 0x02012204 thumb
 *   func_0202223C 0x0202223C thumb
 */
#include "../include/Obj00208.h"
typedef unsigned int u32;
extern void func_02027974(void *);
extern void func_021D5110(char *);
extern void func_021D5310(char *);
extern void func_0204A600(void);
extern int func_0203CD98(void);
struct BigObj;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *);
extern u32 func_021D533C(char *);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_02040618(u32, u32, u32);
extern u32 func_020221A4(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);
int func_021D5514(void *a, void *b, void *c, char *p)
{
    int result = 1;
    if (*(void (**)(char *))p) {
        (*(void (**)(char *))p)(p);
        result = 0;
    }
    if (((struct Obj00208 *)p)->f324) func_02027974(((struct Obj00208 *)p)->f324);
    if (((struct Obj00208 *)p)->f8 != 1) func_021D5110(p);
    func_021D5310(p);
    func_0204A600();
    if (func_0203CD98()) {
        ((struct Obj00208 *)p)->f368 = ((struct Obj00208 *)p)->f364;
        ((struct Obj00208 *)p)->f364 = func_0201058C((void *)func_0201283C(((struct Obj00208 *)p)->f350));
        ((struct Obj00208 *)p)->f370 = ((struct Obj00208 *)p)->f36C;
        ((struct Obj00208 *)p)->f36C = func_021D533C(p);
    }
    func_020310C4(((struct Obj00208 *)p)->f31C);
    func_0201C4E4(((struct Obj00208 *)p)->f320);
    func_02040618(4, 3, ((struct Obj00208 *)p)->f358);
    ((struct Obj00208 *)p)->f358 = ((struct Obj00208 *)p)->f358 - 1;
    if (func_020221A4() && ((struct Obj00208 *)p)->f38C == 0) func_020121CC(((struct Obj00208 *)p)->f354);
    if (func_020221A4() && func_02012204(((struct Obj00208 *)p)->f354)) {
        ((struct Obj00208 *)p)->f8 = 2;
        result = 1;
        func_0202223C(0, 0);
        func_0202223C(1, 0);
    }
    return result;
}
