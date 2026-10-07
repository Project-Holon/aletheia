/*
 * file:     beacon_view_p15.c
 * unit:     yes
 * function: func_021F2234, func_021F22FC
 * address:  0x021F2234
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
 *   func_02030734 0x02030734 arm
 *   d_021F36A0 0x021F36A0 data ov032 a1
 *   func_020120F4 0x020120F4 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188E30 0x02188E30 thumb ov021
 *   func_020490F4 0x020490F4 arm
 *   func_021F27D4 0x021F27D4 thumb ov032
 *   func_021F2908 0x021F2908 thumb ov032
 *   func_021F2A8C 0x021F2A8C thumb ov032
 *   func_021F2C1C 0x021F2C1C thumb ov032
 *   func_021F2D20 0x021F2D20 thumb ov032
 *   func_021F2F44 0x021F2F44 thumb ov032
 *   func_021F3058 0x021F3058 thumb ov032
 *   func_021EFEC0 0x021EFEC0 thumb ov032
 *   func_021F0208 0x021F0208 thumb ov032
 *   func_021F30B4 0x021F30B4 thumb
 *   func_021F2FCC 0x021F2FCC thumb
 *   func_021F2EDC 0x021F2EDC thumb
 *   func_021F2CC4 0x021F2CC4 thumb
 *   func_021F2BD4 0x021F2BD4 thumb
 *   func_021F2A04 0x021F2A04 thumb
 *   func_021F28DC 0x021F28DC thumb
 *   func_0203115C 0x0203115C arm
 *   func_02049238 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00812.h"

struct Ctx;
struct Tcbl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188E30(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021F27D4(u8 *p);
extern void func_021F2908(char *p);
extern void func_021F2A8C(u8 *p, void *h);
extern void func_021F2C1C(char *p);
extern void func_021F2D20(char *p, void *a);
extern void func_021F2F44(char *p, void *a);
extern void func_021F3058(char *p);
extern void func_021EFEC0(u8 *o);
extern void func_021F0208(u8 *p, int flag);
extern void func_021F30B4(char *p);
extern void func_021F2FCC(char *p);
extern void func_021F2EDC(char *p);
extern void func_021F2CC4(char *p);
extern void func_021F2BD4(char *p);
extern void func_021F2A04(char *p);
extern void func_021F28DC(char *p);
extern void func_0203115C(struct Tcbl *p);
extern void func_02049238(u32 a);
extern u32 func_020307B0(void *p);
char *func_021F2234(u32 a0, u32 a1);
void func_021F22FC(char *p);
extern char d_021F36A0[];


char *func_021F2234(u32 a0, u32 a1)
{
    char *p;
    void *v;

    p = func_02030734(0x70, 0x3d0, 1, d_021F36A0, 0x8d);
    ((struct Obj00007 *)p)->f0 = a0;
    ((struct Obj00007 *)p)->f4 = (u32)func_020120F4((const struct Ctx *)a0);
    ((struct Obj00007 *)p)->f8 = v = func_0201210C((void *)a0);
    ((struct Obj00007 *)p)->f10 = func_02188E30(v);
    ((struct Obj00007 *)p)->fC = a1;
    ((struct Obj00007 *)p)->f98 = 0x70;
    ((struct Obj00007 *)p)->f94 = 0x15;
    ((struct Obj00007 *)p)->f96 = 0x8070;
    ((struct Obj00007 *)p)->f9C = func_020490F4(0xad, ((struct Obj00007 *)p)->f98);
    func_021F27D4((u8 *)p);
    func_021F2908(p);
    func_021F2A8C((u8 *)p, ((struct Obj00007 *)p)->f9C);
    func_021F2C1C(p);
    func_021F2D20(p, ((struct Obj00007 *)p)->f9C);
    func_021F2F44(p, ((struct Obj00007 *)p)->f9C);
    func_021F3058(p);
    ((struct Obj00007 *)p)->f7A = 1;
    func_021EFEC0((u8 *)p);
    ((struct Obj00007 *)p)->f7A = 0;
    *(u32 *)&((struct Obj00007 *)p)->f60 = 0;
    func_021F0208((u8 *)p, 1);
    return p;
}


void func_021F22FC(char *p)
{
    func_0203115C((struct Tcbl *)(((struct Obj00812 *)p)->fA0));
    func_021F30B4(p);
    func_021F2FCC(p);
    func_021F2EDC(p);
    func_021F2CC4(p);
    func_021F2BD4(p);
    func_021F2A04(p);
    func_021F28DC(p);
    func_02049238(((struct Obj00812 *)p)->f9C);
    func_020307B0(p);
}
