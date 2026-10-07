/*
 * file:     unit_021BCF9C_p07.c
 * unit:     yes
 * function: func_021BD5FC, func_021BD63C
 * address:  0x021BD5FC
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
 *   func_0201DD68 0x0201DD68 thumb
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
#include "../../matched/include/Obj10205.h"
#include "../../matched/include/Obj07950.h"

struct Entry;
struct Link;
typedef unsigned int   u32;

typedef unsigned char u8;

extern void func_0201DD68(void);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern int func_021BA928(void *);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
int func_021BD5FC(char *p, int ret);
int func_021BD63C(char *p, int v);

int func_021BD5FC(char *p, int ret)
{
    int v;
    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1) return ret;
    if (v == 0) p[0x1353] = 0x44;
    else p[0x1353] = 0x4a;
    func_021BA8EC(p);
    ((struct Obj10205 *)p)->f1CC = 0x8a;
    return ret;
}

int func_021BD63C(char *p, int v)
{
    int state;
    func_021BA928(p);
    if (func_02039CB4((struct Link *)func_020399A8(), 0x1a, 10) != 0) {
        state = ((struct Obj07950 *)p)->f1357;
        if (state != 0) ((struct Obj07950 *)p)->f1CC = state;
        else ((struct Obj07950 *)p)->f1CC = 0x15;
        ((struct Obj07950 *)p)->f1357 = 0;
    }
    return v;
}
