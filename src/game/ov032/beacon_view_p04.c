/*
 * file:     beacon_view_p04.c
 * unit:     yes
 * function: func_021F0A98, func_021F0AC0, func_021F0B10, func_021F0B64, func_021F0B80
 * address:  0x021F0A98
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_021F201C  0x021F201C  thumb  ov032
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../../matched/include/Obj00007.h"

struct MsgBank;
struct WordSet;
struct CharBuf;
struct Descriptor;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_021F201C(char *p, char *q, void *text, u16 x, u8 y, u8 a5, u16 col, u32 a7);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021F0A98(char *p,unsigned a);
void func_021F0AC0(char *p);
void func_021F0B10(char *p, int a, int b);
void func_021F0B64(char *p);
void func_021F0B80(char *p,void *t,unsigned a);

void func_021F0A98(char *p,unsigned a) { func_02045CAC(((struct Obj00007 *)p)->f114,a,((struct Obj00007 *)p)->f118); func_0201F250(((struct Obj00007 *)p)->f110,((struct Obj00007 *)p)->f11C,((struct Obj00007 *)p)->f118); }


void func_021F0AC0(char *p)
{
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, ((struct Obj00007 *)p)->f7B, 2, 1, 1);
    func_021F0A98(p, 0);
    func_021F201C(p, p + 0x110 + 0x94, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 4, 0, 1, 0x3DC1, 0);
}


void func_021F0B10(char *p, int a, int b)
{
    func_0201EFA4((struct WordSet *)(*(int *)&((struct Obj00007 *)p)->f110), 0, *(int *)&((struct Obj00007 *)p)->f2D4, 5, 0, 1);
    func_021F0A98(p, a);
    func_021F201C(p, p + 0x110 + 0x80, (void *)(*(int *)&((struct Obj00007 *)p)->f11C), 0, 4, 0, 0x3C40, b);
}

void func_021F0B64(char *p) { func_02043B5C(((struct Obj00007 *)p)->f194,0x40); func_02045334(((struct Obj00007 *)p)->f190); }

void func_021F0B80(char *p,void *t,unsigned a) { func_021F201C(p,p+0x17c,t,0,0,9,0x449,a); }
