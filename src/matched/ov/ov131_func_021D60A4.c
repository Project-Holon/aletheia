/*
 * function: P_STATUS_GetPokeParaSource
 * address: 0x021D60A4
 * packet: pkt_ov131_021D60A4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 */
#include "../include/Obj00112.h"
typedef unsigned int u32;

extern void *POKEPARTY_GetMember(void *p, u32 idx);
struct Src { int v; int pad[2]; unsigned char kind; };
int P_STATUS_GetPokeParaSource(char *p)
{
    struct Src *s = *(struct Src * *)&((struct Obj00112 *)p)->f8;
    switch (s->kind) {
    case 0:
        return s->v;
    case 1:
        return (int)POKEPARTY_GetMember((void *)s->v, ((struct Obj00112 *)p)->f18);
    case 2:
        return *(int *)&((struct Obj00112 *)p)->f258;
    default:
        return 0;
    }
}
