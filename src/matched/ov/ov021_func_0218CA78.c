/*
 * function: func_0218CA78
 * address:  0x0218CA78
 * packet:   pkt_ov021_0218CA78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218DD70  0x0218DD70  thumb ov021
 *   func_0218D1D0  0x0218D1D0  thumb ov021
 *   func_0218D304  0x0218D304  thumb ov021
 *   func_0218D444  0x0218D444  thumb ov021
 *   func_0218D570  0x0218D570  thumb ov021
 *   func_0218D7A8  0x0218D7A8  thumb ov021
 *   func_0216932C  0x0216932C  thumb ov010
 *   sub_0207C768   0x0207C768  arm
 */
#include "../include/Obj00806.h"

typedef unsigned short u16;

extern int func_0218DD70(unsigned int a);
typedef unsigned int   u32;
struct Elem;
extern void func_0218D1D0(char *p, void *a, struct Elem *e);
struct Cam;
struct Cell;
struct Obj;
extern void func_0218D304(char *p, int *v, struct Elem *e);
extern void func_0218D444(char *p, int *a, struct Elem *e);
extern void func_0218D570(struct Obj *p, struct Cam *cam, struct Cell *cells);
struct Cell;
struct Obj;
extern int func_0218D7A8(struct Obj *p, struct Cell *nc);
extern void func_0216932C(int a);
extern u32 sub_0207C768(u32 a, u32 b);

void func_0218CA78(char *p)
{
    int i;
    int a;
    int b;

    if (((struct Obj00806 *)p)->f1C == 0)
        return;
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0218DD70((unsigned int)(*(char * *)&((struct Obj00806 *)p)->f28 + i * 16));
    switch (((struct Obj00806 *)p)->fC) {
    case 0:
        func_0218D1D0(p, p + 0x34, ((struct Obj00806 *)p)->f28);
        break;
    case 1:
    default:
        func_0218D304(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 2:
        func_0218D444(p, (int *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    case 3:
        func_0218D570((struct Obj *)p, (struct Cam *)(p + 0x34), ((struct Obj00806 *)p)->f28);
        break;
    }
    func_0218D7A8((struct Obj *)p, ((struct Obj00806 *)p)->f28);
    for (i = 0; i < ((struct Obj00806 *)p)->f2E; i++)
        func_0216932C(*(int *)(*(char * *)&((struct Obj00806 *)p)->f24 + i * 0x28));
    a = sub_0207C768(((struct Obj00806 *)p)->f34, ((struct Obj00806 *)p)->f4);
    b = sub_0207C768(((struct Obj00806 *)p)->f3C, ((struct Obj00806 *)p)->f4);
    ((struct Obj00806 *)p)->f30 = (a >> 12) + (b >> 12) * ((struct Obj00806 *)p)->f14;
}
