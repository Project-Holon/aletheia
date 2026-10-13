/*
 * function: func_021BC0C4
 * address:  0x021BC0C4
 * packet:   pkt_ov099_021BC0C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBD80  0x021BBD80  thumb  ov099
 *   func_021BBC0C  0x021BBC0C  thumb  ov099
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   BMP_MENULIST_Delete  0x0202020C  thumb
 *   BMP_MENUWORK_Delete  0x0201F868  thumb
 */
#include "../include/Obj05261.h"

typedef unsigned short u16;
struct Obj;
extern void func_021BBD80(char *s);
extern void func_021BBC0C(void *p);
extern int func_021BA8BC(void *p);
extern void BMP_MENULIST_Delete(struct Obj *o, u16 *a, u16 *b);
typedef unsigned int   u32;
extern u32 BMP_MENUWORK_Delete(void *p);

void func_021BC0C4(char *p)
{
    if (((struct Obj05261 *)p)->f1A4 != 0) {
        func_021BBD80(p);
        func_021BBC0C(p);
        ((struct Obj05261 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj05261 *)p)->f1A4);
        BMP_MENULIST_Delete(((struct Obj05261 *)p)->fBC, 0, 0);
        BMP_MENUWORK_Delete(((struct Obj05261 *)p)->fB8);
        ((struct Obj05261 *)p)->fB8 = 0;
    }
}
