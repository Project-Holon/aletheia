/*
 * function: func_021DEA30
 * address: 0x021DEA30
 * packet: pkt_ov183_021DEA30
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF388 0x021DF388 thumb ov183
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 */
#include "../include/Obj00923.h"
#include "../include/Obj24582.h"
#include "../include/Obj24583.h"
#include "../include/Obj24584.h"
typedef unsigned char  u8;
struct PrintSys;
struct S020315D4;
extern void func_021DF388(char *p);
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD714(void *);
extern void func_021FD15C(void *, int);
extern void func_021FD820(char *r5);
extern void BMP_OAM_DeleteSys(void *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
int func_021DEA30(void *a, int b, char *q, char *p)
{
    int i;
    if (((struct Obj00923 *)p)->f100 != 0) {
        func_021DF388(p + 0x28);
        ((struct Obj00923 *)p)->f100 = 0;
    }
    if (((struct Obj00923 *)p)->fC != 0) {
        func_021FC734(((struct Obj00923 *)p)->fC);
        ((struct Obj00923 *)p)->fC = 0;
    }
    if (((struct Obj00923 *)p)->f8 != 0) {
        func_021FC734(((struct Obj00923 *)p)->f8);
        ((struct Obj00923 *)p)->f8 = 0;
    }
    if (((struct Obj00923 *)p)->f4 != 0) {
        func_021FB494(((struct Obj00923 *)p)->f4);
        ((struct Obj00923 *)p)->f4 = 0;
    }
    if (((struct Obj00923 *)p)->f104 != 0) {
        func_021FC0C8(((struct Obj24583 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10, 6);
        func_021FBDA4((int)(((struct Obj24584 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10), 24);
        ((struct Obj00923 *)p)->f104 = 0;
    }
    func_021FD714(((struct Obj00923 *)p)->f10);
    if (((struct Obj00923 *)p)->f24 != 0) {
        func_021FD15C(((struct Obj00923 *)p)->f24, ((struct Obj24582 *)q)->f10);
        ((struct Obj00923 *)p)->f24 = 0;
    }
    for (i = 0; i < 2; i++) func_021FD820(*(void **)(p + 0x1C + i * 4));
    BMP_OAM_DeleteSys(((struct Obj00923 *)p)->f0);
    func_0201C4C0(((struct Obj00923 *)p)->f14);
    func_020315D4(a);
    return 1;
}
