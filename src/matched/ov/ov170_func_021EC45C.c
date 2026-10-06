/*
 * function: func_021EC45C
 * address:  0x021EC45C
 * packet:   pkt_ov170_021EC45C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EC338 0x021EC338 thumb
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_021EC428 0x021EC428 thumb
 *   func_020307B0 0x020307B0 arm
 *
 * Loads an icon resource for a, uploads it and frees the file.
 */
#include "../include/Obj24003.h"

extern void *func_021EC338(char *p, void *b, void *c);
extern int func_0201BBE8(void *a);
extern void func_021EC428(char *w, int a, int i, int b);
extern void func_020307B0(void *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EC45C(unsigned char *p, void *a, int i)
{
    void *d;
    void *res = func_021EC338(WORK(p), a, &d);
    func_021EC428(WORK(p), ((struct Obj24003 *)d)->f14, i, func_0201BBE8(a));
    func_020307B0(res);
}
