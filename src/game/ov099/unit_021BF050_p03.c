/*
 * file:     unit_021BF050_p03.c
 * unit:     yes
 * function: func_021BFCEC, func_021BFD68
 * address:  0x021BFCEC
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
 *   func_021BFBBC 0x021BFBBC thumb ov099
 *   func_021BA858 0x021BA858 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_0201FEF4 0x0201FEF4 thumb
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../../matched/include/Obj04416.h"
#include "../../matched/include/Obj00008.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_021BFBBC(char *);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *);
extern void func_0201FEF4(u8 *o);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BAADC(char *, int, int);
extern int func_021BA928(char *, int);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
int func_021BFCEC(char *p, int ret);
int func_021BFD68(char *p, int ret);

int func_021BFCEC(char *p, int ret)
{
    int v;
    func_021BFBBC(p);
    v = func_021BA858(p);
    if (v == -1) {
        if (((struct Obj04416 *)p)->f1355) {
            func_021BA8EC(p);
            func_0201FEF4(((struct Obj04416 *)p)->f108);
            ((struct Obj04416 *)p)->f108 = 0;
            func_021BA874(p, func_02156A3C());
            func_021BAAB8(p, 0x10, 0);
            ((struct Obj04416 *)p)->f1E0 = 0x3c;
            ((struct Obj04416 *)p)->f1CC = 0x94;
        }
    } else if (v == 0) {
        ((struct Obj04416 *)p)->f1CC = 0x92;
    } else {
        func_021BAADC(p, 0x7b, 0);
        ((struct Obj04416 *)p)->f1CC = 0x10;
    }
    return ret;
}

int func_021BFD68(char *p, int ret)
{
    if (!func_021BA928(p, ret)) return ret;
    if (func_0203D3A8(func_020399A8(), 0xa08, 0, 0)) {
        func_02039C68((struct Link *)func_020399A8(), 0x12, 0xa);
        ((struct Obj00008 *)p)->f1CC = 0x93;
    }
    return ret;
}
