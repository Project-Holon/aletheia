/*
 * function: func_021C962C
 * address:  0x021C962C
 * packet:   pkt_ov093_021C962C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C96B4  0x021C96B4  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021C96C4  0x021C96C4  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D66B0  0x021D66B0  thumb  ov093
 *   func_021E8DA8  0x021E8DA8  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */
#include "../../../matched/include/Obj00003.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C96B4(int a, u8 b);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern int func_021C96C4(int a);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D66B0(u8 *p, int n);
extern int func_021E8DA8(int a);
extern u8 func_021E8CFC(int v);
extern void func_021CD64C(void *w, u8 id, ...);

typedef struct { u32 w; u16 h4; u8 b6; u8 b7; } Ent;

int func_021C962C(int p, const Ent *e)
{
    int a;

    if (func_021C96B4(p + 0x1ab8, e->b6)) {
        a = (int)func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, e->b6);
        if (func_021D5B68((void *)a) == 0 && func_021C96C4(func_021D5444((void *)a)) == 0) {
            func_021CD4B0(((struct Obj00003 *)p)->fC, 0x16, e->b6, e->h4);
            func_021D66B0((void *)a, e->h4);
            if (e->b7 == 0 && func_021E8DA8(e->h4))
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x380, e->b6, func_021E8CFC(e->h4), 0xffff0000);
            return 1;
        }
    }
    return 0;
}
