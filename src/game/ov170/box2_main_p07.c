/*
 * file:     box2_main_p07.c
 * unit:     yes
 * function: func_021DE530, func_021DE5C8
 * address:  0x021DE530
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DDEFC 0x021DDEFC thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_021DE120 0x021DE120 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj01418.h"
#include "../../matched/include/Obj23845.h"
#include "../../matched/include/Obj23846.h"

#define WORK(p) (*(char **)((p) + 0x2C))
typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj;

typedef unsigned int   u32;

typedef struct {
    unsigned short id;
    unsigned short val;
    unsigned short f4;
    unsigned short used;
    unsigned char pad[0x10];
} Entry;

extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DDEFC(unsigned char *p, Obj *o);
extern u32 func_0201AA18(void *p);
extern void func_021DE120(char *p, int a, int b);
void func_021DE530(unsigned char *p, int a, int b);
int func_021DE5C8(char *p, unsigned id);


/*
 * Clears the seven move slots, then either starts a slide from a to b or,
 * when b is not a movable box, snaps to it.
 */
void func_021DE530(unsigned char *p, int a, int b)
{
    Obj *o = *(Obj **)(WORK(p) + 0x60);
    unsigned i;
    for (i = 0; i < 7; i++) {
        o[i].idx = 0;
        o[i].slot = 0;
        o[i].f4 = 0;
        o[i].f6 = 0;
    }
    if (b == 0xFF || func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0)) {
        ((struct Obj01418 *)o)->fAC = 0xFF;
        ((struct Obj01418 *)o)->fB0 = 0xFF;
        o[0].idx = 0x24;
        o[0].slot = a;
        o[0].f4 = a;
        o[0].f6 = 1;
        o[1].idx = a;
        o[1].slot = a;
        o[1].f4 = a;
        o[1].f6 = 1;
        func_021DDEFC(p, o);
    } else {
        ((struct Obj01418 *)o)->fAC = a;
        ((struct Obj01418 *)o)->fB0 = b;
        func_021DE120((char *)p, a, func_0201AA18(((struct Obj23845 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f8) + 0x1E);
    }
}


int func_021DE5C8(char *p, unsigned id)
{
    Entry *e = *(Entry * *)&((struct Obj23846 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0 && id == e[i].id)
            return e[i].val;
    }
    return ((unsigned char *)p)[0x16];
}
