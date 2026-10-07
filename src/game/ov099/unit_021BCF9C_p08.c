/*
 * file:     unit_021BCF9C_p08.c
 * unit:     yes
 * function: func_021BD678, func_021BD6A0, func_021BD6D0, func_021BD71C
 * address:  0x021BD678
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
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_02039C68 0x02039C68 arm
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203D378 0x0203D378 arm
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../../matched/include/Obj00008.h"
#include "../../matched/include/Obj13691.h"
#include "../../matched/include/Obj22038.h"
#include "../../matched/include/Obj22039.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021BA928(void *);
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *, u32, u32);
extern void func_021C18C8(char *, int, int);
extern void func_02039C68(struct Link *, u32, u32);
extern void func_0203D7B0(u8 a0);
extern int func_0203D7BC(int);
extern int func_0203D378(int);
extern void func_021BAAB8(char *, int, int);
int func_021BD678(char *p, int v);
int func_021BD6A0(char *p, int v);
int func_021BD6D0(char *p, int v);
int func_021BD71C(char *p, int v);

int func_021BD678(char *p, int v)
{
    func_021BA928(p);
    if (func_02039CB4((struct Link *)func_020399A8(), 0x1b, 10) != 0) {
        *(u32 *)&((struct Obj00008 *)p)->f1CC = 0x48;
    }
    return v;
}

int func_021BD6A0(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    func_02039C68((struct Link *)func_020399A8(), 0x19, 10);
    ((struct Obj13691 *)p)->f135C = 0;
    ((struct Obj13691 *)p)->f1CC = 0x9c;
    return v;
}

int func_021BD6D0(char *p, int v)
{
    int zero;
    if (func_02039CB4((struct Link *)func_020399A8(), 0x19, 10) == 0) return v;
    zero = 0;
    func_0203D7B0(0);
    if (func_0203D378(func_0203D7BC(0)) != 0) {
        func_021BAAB8(p, 0x7c, zero);
    } else {
        func_021BAAB8(p, 0x7d, zero);
    }
    ((struct Obj22038 *)p)->f1CC = 0x8e;
    return v;
}

int func_021BD71C(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    func_0203D7B0(0);
    func_0203D7BC(0);
    ((struct Obj22039 *)p)->f1CC = 0xa9;
    return v;
}
