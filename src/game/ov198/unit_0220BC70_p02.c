/*
 * file:     unit_0220BC70_p02.c
 * unit:     yes
 * function: func_0220BE04, func_0220BE2C
 * address:  0x0220BE04
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0220BDD4 0x0220BDD4 thumb ov198
 *   func_020452E8 0x020452E8 arm
 *   func_0220BD84 0x0220BD84 thumb ov198
 *   func_0220C60C  0x0220C60C  thumb  ov198
 *   func_0220D884  0x0220D884  thumb  ov198
 *   func_0220D9B4  0x0220D9B4  thumb  ov198
 *   func_0220DCA8  0x0220DCA8  thumb  ov198
 *   func_0220DC04  0x0220DC04  thumb  ov198
 *   func_0220DD78  0x0220DD78  thumb  ov198
 *   func_0220DE4C  0x0220DE4C  thumb  ov198
 *   func_0220DF20  0x0220DF20  thumb  ov198
 *   func_0220E088  0x0220E088  thumb  ov198
 */
#include "../../matched/include/Obj00507.h"

struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020452E8(struct Descriptor *);
extern void func_0220BDD4(char *);
extern void func_0220BD84(u8 *);
extern int func_0220C60C(char *, int);
extern void func_0220D884(u8 *p);
extern int func_0220D9B4(char *);
extern int func_0220DCA8(char *);
extern int func_0220DC04(char *);
extern int func_0220DD78(char *);
extern int func_0220DE4C(char *);
extern int func_0220DF20(char *);
extern int func_0220E088(char *);
void func_0220BE04(u8 *p);
int func_0220BE2C(char *a, int idx);

void func_0220BE04(u8 *p){u32 i;func_0220BDD4((char *)p);for(i=0;i<2;i++)func_020452E8(*(struct Descriptor **)(p+i*8+0x1f60));func_0220BD84(p);}


int func_0220BE2C(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        func_0220D884((u8 *)a);
        c = *(unsigned char *)(*(int *)&((struct Obj00507 *)a)->f0 + 0x1f);
        if (c == 3)
            return func_0220C60C(a, 7);
        if (c == 2)
            return func_0220C60C(a, 9);
        return func_0220C60C(a, 6);
    }
    case 8:
        func_0220D884((u8 *)a);
        return func_0220C60C(a, 0xa);
    case 1:
        return func_0220D9B4(a);
    case 2:
        return func_0220DCA8(a);
    case 3:
        return func_0220DC04(a);
    case 4:
        return func_0220DD78(a);
    case 5:
        return func_0220E088(a);
    case 6:
        return func_0220DE4C(a);
    case 7:
        return func_0220DF20(a);
    }
}
