/*
 * file:     unit_021BCF9C_p02.c
 * unit:     yes
 * function: func_021BD0BC, func_021BD0F0
 * address:  0x021BD0BC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_0203D378  0x0203D378  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   func_02012934  0x02012934  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 */
#include "../../matched/include/Obj13689.h"
#include "../../matched/include/Obj04415.h"

struct BigObj;
struct Rec534;
typedef unsigned char u8;

typedef unsigned int u32_021BD0BC;

typedef unsigned short u16;

typedef unsigned long  u32_021BD0F0;

extern int func_021BA928(void *);
extern u32_021BD0BC func_020362DC(void);
extern u32_021BD0F0 func_0203D378(void);
extern int func_021BCBBC(int a, int b, int *out);
extern void *func_02012934(const struct BigObj *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021BAAB8(char *p, int a, int b);
int func_021BD0BC(char *p, int v);
int func_021BD0F0(char *p, int v);

int func_021BD0BC(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (func_020362DC() == 0) return v;
    ((struct Obj13689 *)p)->f1353 = 0x6e;
    ((struct Obj13689 *)p)->f1CC = 0x8a;
    return v;
}


int func_021BD0F0(char *p, int v)
{
    int t;
    int out;

    t = 0;
    if (func_0203D378() == 0) {
        t = 1;
    }
    if (func_021BCBBC(((struct Obj04415 *)p)->f1348, ((struct Obj04415 *)p)->fCC, &out) != 0
        && ((struct Obj04415 *)p)->fCC == 0) {
        func_0201AC2C(func_02012934(((struct Obj04415 *)p)->fC4),
                      *(void **)(*(char * *)&((struct Obj04415 *)p)->f248 + t * 4 + 0x14));
        ((struct Obj04415 *)p)->f1CC = 0x67;
    } else {
        func_021BAAB8(p, 0x71, 0);
        ((struct Obj04415 *)p)->f1CC = 0x65;
    }
    return v;
}
