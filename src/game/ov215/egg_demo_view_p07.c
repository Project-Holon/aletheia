/*
 * file:     egg_demo_view_p07.c
 * unit:     yes
 * function: func_021F7028, func_021F7048
 * address:  0x021F7028
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_021F6718 0x021F6718 thumb ov215
 *   func_02048A18    0x02048A18  arm
 *   func_02047910    0x02047910  arm
 *   func_020478B8    0x020478B8  arm
 */
#include "../../matched/include/Obj04636.h"
#include "../../matched/include/Obj01083.h"

struct Ctx;
typedef unsigned short u16;

extern void func_020480E4(struct Ctx *,unsigned),func_021F6718(void *);
extern void *func_02048A18(void *p, int v);
extern int func_020478B8(void *p, int a, int b);
void func_021F7028(char *p);
void func_021F7048(char *p);

void func_021F7028(char *p){func_020480E4(*(struct Ctx * *)&((struct Obj04636 *)p)->f48,((struct Obj04636 *)p)->f4C);func_021F6718(((struct Obj04636 *)p)->f54);((struct Obj04636 *)p)->f50=0;}


void func_021F7048(char *p)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < ((struct Obj01083 *)p)->f50; i++) {
        func_02047910(func_02048A18(((struct Obj01083 *)p)->f48,
                        *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + i * 0x44)), 0, 0x1000);
    }
    ((struct Obj01083 *)p)->f58 = ((struct Obj01083 *)p)->f58 + 1;
    q = func_02048A18(((struct Obj01083 *)p)->f48,
                      *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + ((struct Obj01083 *)p)->f4E * 0x44));
    if (((struct Obj01083 *)p)->f5C == 1) {
        a = func_020478B8(q, 1, 0x5000);
        b = func_020478B8(q, 2, 0x5000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 2;
    } else if (((struct Obj01083 *)p)->f5C == 3) {
        a = func_020478B8(q, 1, -0x2000);
        b = func_020478B8(q, 2, -0x2000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 0;
    }
}
