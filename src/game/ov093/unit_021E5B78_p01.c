/*
 * file:     unit_021E5B78_p01.c
 * unit:     yes
 * function: func_021E5B78, func_021E5C18
 * address:  0x021E5B78
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2CD8     0x021F2CD8  data   ov093  a4
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 */
#include "../../matched/include/Obj02791.h"

struct Flag;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021C8168(void *p);
extern int func_021C815C(int *p);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
void func_021E5B78(int a, void *b, int c);
int *func_021E5C0C(int *p);
void func_021E5C18(u8 *p, void *a, int b);
extern int d_021F2CD8[];


void func_021E5B78(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3) && func_021C7F24(b, c) != 0 && func_021C7F4C(b) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj02791 *)m)->f4 = 4;
        m[8] = func_021C8010(b, c);
        ((struct Obj02791 *)m)->fC = c;
        m[0x1c] = 1;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj02791 *)m)->f4 = 0xe;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x29, c);
        m[0x4c] = c;
        m[0x4d] = 1;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
    }
}


int *func_021E5C0C(int *p)
{
    *p = 3;
    return d_021F2CD8;
}


void func_021E5C18(u8 *p, void *a, int b)
{
    void *r;
    if (func_021C8168(a) != 0 || func_021C815C(a) != 0)
        func_021D76BC(0x22, 0x1a);
    r = func_021C7CF4(a, b);
    if (func_021D62C4(r, 8) != 0 && func_021D62C4(r, 0x16) != 0)
        func_021D76BC(0x22, 0x1a);
}
