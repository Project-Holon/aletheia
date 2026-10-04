/*
 * function: func_021E0C44
 * address: 0x021E0C44
 * packet: pkt_ov119_021E0C44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status:   EXACT
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 * symbols:
 *   func_02010904 0x02010904 thumb
 *   func_02010934 0x02010934 thumb
 *   func_021E02E8 0x021E02E8 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 */
#include "../include/Obj10371.h"
typedef unsigned int   u32;
struct Sub0201088CObj;
extern u32 func_02010904(struct Sub0201088CObj *p);
extern void func_02010934(struct Sub0201088CObj *p);
extern void func_021E02E8(char *p);
extern void func_021D8E84(void *p, void (*fn)(void *p));
extern void func_021E0C78(void *p);
void func_021E0C44(char *p)
{
    if (func_02010904(((struct Obj10371 *)p)->fEF8)) {
        func_021E02E8(p);
        func_02010934(((struct Obj10371 *)p)->fEF8);
        *(int *)&((struct Obj10371 *)p)->fEF8 = 0;
        func_021D8E84(p, func_021E0C78);
    }
}
