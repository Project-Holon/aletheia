/*
 * function: func_021BD8F0
 * address: 0x021BD8F0
 * packet: pkt_ov093_021BD8F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021B9D10 0x021B9D10 thumb ov093
 *   func_021B9C10 0x021B9C10 thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8750 0x021B8750 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021DCF5C 0x021DCF5C thumb ov093
 *   func_021D63EC 0x021D63EC thumb ov093
 *   func_021D6580 0x021D6580 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021BD9C4 0x021BD9C4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char *func_021B9AEC(char *, int);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021B9D10(char *, void *, int);
struct S2;
extern void func_021B9C10(u32 *p, int a, int b);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 func_021D5440(u8 *p);
extern void func_021B8750(char *p, unsigned char k, void *m);
extern void *func_021D8484(void *a);
extern void *func_021DCF5C(void *p);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *);
extern u32 func_021B8588(void **p);
extern u32 func_021B99B8(void *, int);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021BD9C4(void *, int, u8, void *);
void func_021BD8F0(u8 *p, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = func_021B9AEC(*(char * *)&((struct Obj00003 *)p)->f8, i);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 42, i);
    func_021B9D10(*(char * *)&((struct Obj00003 *)p)->f4, arr, i);
    if (a != b) func_021B9C10((u32 *)arr, a, b);
    m = (u8 *)func_021B9BF0((struct S2 *)arr, a);
    id = func_021D5440(m);
    func_021B8750(((struct Obj00003 *)p)->f4, i, m);
    func_021D8484(m);
    func_021DCF5C(m);
    func_021D63EC(m, ((struct Obj00003 *)p)->f10);
    func_021D6580(m);
    flags = p + 0x7c1;
    flags[id] = 1;
    if (func_021B8588(((struct Obj00003 *)p)->f4) == 3) {
        if (func_021B99B8(((struct Obj00003 *)p)->f4, i) <= a) flags[id] = 0;
    }
    func_021CD4B0(((struct Obj00003 *)p)->fC, 18, i, a, b, (u16)((struct Obj00003 *)p)->f10);
    func_021BD9C4(p + 0x1ab8, func_021B8BEC(*(u8 * *)&((struct Obj00003 *)p)->f4, i, a), id, ((struct Obj00003 *)p)->f8);
}
