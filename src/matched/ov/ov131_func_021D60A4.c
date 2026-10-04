/*
 * function: func_021D60A4
 * address: 0x021D60A4
 * packet: pkt_ov131_021D60A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201AB28 0x0201AB28 thumb
 */
#include "../include/Obj00112.h"
typedef unsigned int u32;

extern void *func_0201AB28(void *p, u32 idx);
struct Src { int v; int pad[2]; unsigned char kind; };
int func_021D60A4(char *p)
{
    struct Src *s = *(struct Src * *)&((struct Obj00112 *)p)->f8;
    switch (s->kind) {
    case 0:
        return s->v;
    case 1:
        return (int)func_0201AB28((void *)s->v, ((struct Obj00112 *)p)->f18);
    case 2:
        return *(int *)&((struct Obj00112 *)p)->f258;
    default:
        return 0;
    }
}
