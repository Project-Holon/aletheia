/*
 * file:     unit_021E5680_p03.c
 * unit:     yes
 * function: func_021E625C, func_021E6294, func_021E62D4
 * address:  0x021E625C
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_02049B40 0x02049B40 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02049B90 0x02049B90 arm
 *   func_0204A8D4 0x0204A8D4 arm
 */
#include "../../matched/include/Obj13925.h"
#include "../../matched/include/Obj00001.h"

struct Obj;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    char pad[0x1008];
    int h[2][3];
    int w[2][3];
} Work;

extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_020275E4(void);
extern void func_02049B90(u32,u32,u32,u32,u32,u32,u16);
extern void func_0204A8D4(u32 i);
void func_021E625C(void *p);
void func_021E6294(char *p, int n, u32 x);
void func_021E62D4(Work *p, int a, int b);


void func_021E625C(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            func_0204B3B4((struct Obj *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct Obj13925 *)q)->f10) {
        func_021B6284((unsigned int *)q);
        ((struct Obj13925 *)q)->f10 = 0;
    }
}

void func_021E6294(char *p, int n, u32 x) {
    int offset = n * 32;
    func_02049B40(23,5,x,offset,32,((struct Obj00001 *)p)->f5F4);
    func_02049B90(func_020275E4(),31,x,28,offset+28,4,((struct Obj00001 *)p)->f5F4);
}


void func_021E62D4(Work *p, int a, int b)
{
    if (p->h[a][b]) {
        func_0204B3B4((struct Obj *)p->h[a][b]);
        p->h[a][b] = 0;
        func_0204A8D4(p->w[a][b]);
    }
}
