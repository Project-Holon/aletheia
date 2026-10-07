/*
 * file:     unit_021BB954_p07.c
 * unit:     yes
 * function: func_021BC1E8, func_021BC228
 * address:  0x021BC1E8
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
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D378  0x0203D378  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021BA874  0x021BA874  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   func_021BC090  0x021BC090  thumb  ov099
 */
#include "../../matched/include/Obj10203.h"
#include "../../matched/include/Obj06354.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern void func_0201DD68(void);
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern struct Entry *func_020399A8(void);
extern int func_0203D1E8(int a, int b);
extern int func_0203D378(int a);
extern void func_02039C68(struct Link *a, unsigned int b, unsigned int c);
extern void func_021BA874(void *p, int id);
extern void func_021BAAB8(char *p, int a, int b);
extern void func_021BC090(void *p);
int func_021BC1E8(char *p, int r);
int func_021BC228(char *p, int r);


int func_021BC1E8(char *p, int r)
{
    int v;

    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1)
        return r;
    if (v == 0)
        ((struct Obj10203 *)p)->f1353 = 0x44;
    else
        ((struct Obj10203 *)p)->f1353 = 0x4A;
    func_021BA8EC(p);
    ((struct Obj10203 *)p)->f1CC = 0x8A;
    return r;
}


int func_021BC228(char *p, int r)
{
    if (func_0203D378(func_0203D1E8((int)func_020399A8(), 0)) != 0) {
        ((struct Obj06354 *)p)->f135C = 3;
        func_021BA874(p, ((struct Obj06354 *)p)->f242 - 1);
        func_021BAAB8(p, 0x60, 0);
        ((struct Obj06354 *)p)->f1CC = 0x45;
    } else {
        ((struct Obj06354 *)p)->f135C = 4;
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        func_02039C68((struct Link *)func_020399A8(), 0x1B, 0xA);
        ((struct Obj06354 *)p)->f1CC = 0x49;
    }
    return r;
}
