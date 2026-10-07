/*
 * file:     unit_021BF050_p13.c
 * unit:     yes
 * function: func_021C1288, func_021C12D0
 * address:  0x021C1288
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
 *   func_020399A8 0x020399A8 arm
 *   func_0200ED48 0x0200ED48 thumb
 *   sub_020399A8  0x020399A8  arm
 */
#include "../../matched/include/Obj13701.h"

struct Entry;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
typedef unsigned int   u32_021C1288;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021C12D0;

typedef int BOOL;

extern struct Entry *func_020399A8(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32_021C1288 i);
extern void func_02008494(void *, void *);
extern void *func_0200ED48(void *);
extern u32_021C1288 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32_021C1288 val);
extern struct Entry *sub_020399A8(void);
void func_021C1288(int index, int unused, void *src, char *p, int handle);
void func_021C12CC(void);
void func_021C12D0(int a, int b, int c, u8 *d, int e);

/*
 * size: 72
 * follower: empty return at 0x021C12CC.
 */
void func_021C1288(int index, int unused, void *src, char *p, int handle)
{
    void *q;
    void *list;
    if (handle == (int)func_020399A8()) {
        q = func_02012950(((struct Obj13701 *)p)->fC4, index);
        func_02008494(src, q);
        list = func_0200ED48(((struct Obj13701 *)p)->fC0);
        func_0200ED54(list, func_02008530(q));
    }
}

void func_021C12CC(void) {}


void func_021C12D0(int a, int b, int c, u8 *d, int e)
{
    if ((int)sub_020399A8() == e) {
        d[0x1355] = 1;
    }
}
