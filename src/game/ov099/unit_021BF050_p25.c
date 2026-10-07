/*
 * file:     unit_021BF050_p25.c
 * unit:     yes
 * function: func_021C2274, func_021C22E8
 * address:  0x021C2274
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
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_021C2370 0x021C2370 thumb ov099
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_021BE4BC 0x021BE4BC thumb ov099
 *   func_021C285C 0x021C285C thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj02157.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
typedef short s16;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_021C2370(char *, int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045334(struct Descriptor *d);
extern int func_021C23B8(int i);
extern u8 func_021BDD48(char *, void *);
extern int func_021BDD54(char *, void *);
extern void func_021BE4BC(char *p, int a, int b, int c, int d, unsigned int e, int f);
extern int func_021C285C(void *);
extern void func_021BE3CC(char *p, int a, u8 b, u8 c, unsigned int d, int e);
extern void func_02041B6C(u32 bit);
void func_021C2274(char *p, void *window, int id, int slot, int i);
void func_021C22E8(char *p, void *unused, int id, int flag, int x, int y);

void func_021C2274(char *p, void *window, int id, int slot, int i)
{
    func_02043B5C(func_02045770(window), 0);
    func_0201DD78(15, 2, 0);
    func_021C2370(p, id - 1);
    func_02045CAC(((struct Obj02157 *)p)->fE0, 33, ((struct Obj02157 *)p)->fF0);
    func_0201F250(((struct Obj02157 *)p)->f8B0, ((struct Obj02157 *)p)->fF8, ((struct Obj02157 *)p)->fF0);
    func_0201C7A4(func_02045770(window), 2, 8, ((struct Obj02157 *)p)->fF8, ((struct Obj02157 *)p)->fE8);
    func_02045334(window);
}

void func_021C22E8(char *p, void *unused, int id, int flag, int x, int y)
{
    int offset;
    void *s;
    int kind;
    int value;
    int icon;
    offset = 0;
    if (flag != 0) offset = 16;
    s = (void *)func_021C23B8(id - 1);
    kind = func_021BDD48(p, s);
    value = func_021BDD54(p, s);
    func_021BE4BC(p + 0x898, 6, (u8)(x + 2), (u8)(y + 2), kind, (int)value, offset);
    if (func_021C285C(s)) icon = 15;
    else icon = 11;
    func_021BE3CC(p + 0x898, 6, x + 12, y + 2, (int)(icon + offset), 0);
    func_02041B6C(7);
}
