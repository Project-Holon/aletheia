/*
 * file:     unit_021BCF9C_p04.c
 * unit:     yes
 * function: func_021BD318, func_021BD380
 * address:  0x021BD318
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
 *   func_0203D378  0x0203D378  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0201A918  0x0201A918  thumb
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_02039C68 0x02039C68 arm
 */
#include "../../matched/include/Obj13690.h"
#include "../../matched/include/Obj00008.h"

struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BD318;

typedef unsigned int u32_021BD380;

extern u32_021BD318 func_0203D378(void);
extern struct Entry *func_020399A8(void);
extern int func_0201A918(void);
extern u32_021BD318 func_0203D3F8(u32_021BD318 entry, u32_021BD318 sendID, u32_021BD318 c, u32_021BD318 d, u32_021BD318 e, u32_021BD318 f, u32_021BD318 g, u32_021BD318 h);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(char *p);
extern int func_021BA928(void *);
extern void func_02039C68(struct Link *p, u32_021BD380 lo, u32_021BD380 hi);
int func_021BD318(char *p, int v);
int func_021BD380(char *p, int v);


int func_021BD318(char *p, int v)
{
    int t;
    u32_021BD318 h;

    t = 0;
    if (func_0203D378() == 0) {
        t = 1;
    }
    h = (u32_021BD318)func_020399A8();
    if (func_0203D3F8(h, 0xFF, 0xA07, func_0201A918(),
                      *(u32_021BD318 *)(*(char * *)&((struct Obj13690 *)p)->f248 + t * 4 + 0x14), 0, 0, 1) != 0) {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        ((struct Obj13690 *)p)->f1CC = 0x98;
    }
    return v;
}

int func_021BD380(char *p, int v)
{
    if (func_021BA928(p) != 0) {
        func_02039C68((struct Link *)func_020399A8(), 0x11, 10);
        *(u32_021BD380 *)&((struct Obj00008 *)p)->f1CC = 0x68;
    }
    return v;
}
