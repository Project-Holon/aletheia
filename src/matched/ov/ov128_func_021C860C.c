/*
 * unit: yes
 * function: func_021C860C, func_021C8660, func_021C8664, func_021C8668
 * address: 0x021C860C
 * packet: pkt_ov128_021C860C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA40C 0x021CA40C thumb ov128
 *   func_021C88C0 0x021C88C0 thumb ov128
 *   func_021C8904 0x021C8904 thumb ov128
 *   func_021CA2DC 0x021CA2DC thumb ov128
 */
#include "../include/Obj00179.h"
#include "../include/Obj14039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void func_021CA40C(char *p, int n);
extern void func_021C88C0(s16 *, void *, u8 *);
extern void func_021C8904(char *p, char *q, void *r, void *s, int t, char *table, int page, u16 heap);
extern void func_021CA2DC(char *p);
void func_021C860C(u8 *p, u8 *a, u8 *b, int x, int y, u16 c)
{
    ((struct Obj00179 *)p)->f4 = y;
    ((struct Obj00179 *)p)->f0 = x;
    func_021CA40C((char *)p, x);
    func_021C88C0((s16 *)(p + 12), b, b + 0x16c);
    func_021C8904((char *)(p + 12), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    func_021CA2DC((char *)p);
}
void func_021C8660(void) {}
void func_021C8664(void) {}
void func_021C8668(u8 *p, u8 *a, int n)
{
    a[8] = 3;
    ((struct Obj14039 *)p)->f102 = n;
    ((struct Obj14039 *)p)->f100 = 0;
}
