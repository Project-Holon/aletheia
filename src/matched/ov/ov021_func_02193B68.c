/*
 * function: func_02193B68
 * address:  0x02193B68
 * packet:   pkt_ov021_02193B68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02193EB4  0x02193EB4  thumb  ov021
 *   func_02193F34  0x02193F34  thumb  ov021
 *   func_0200846C  0x0200846C  thumb
 *   func_020084A0  0x020084A0  thumb
 *   func_020084D4  0x020084D4  thumb
 *   func_0200852C  0x0200852C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj19617.h"

typedef unsigned short u16;

typedef unsigned int   u32;
struct V;
extern void func_02193EB4(struct V *v);
struct E50;
extern struct E50 *func_02193F34(struct V *v, u32 key);
struct Sub0200852CObj;
struct WordSet;
extern void *func_0200846C(int a0);
struct Sub0200852CObj;
extern void func_020084A0(struct Sub0200852CObj *);
extern u32 func_020084D4(u32 value, void *dst);
extern void func_0200852C(struct Sub0200852CObj *obj, u32 value);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_020307B0(void *p);

void func_02193B68(void *a, int b, int c, int d, u16 e)
{
    char *q;
    int h;

    func_02193EB4(a);
    q = (char *)func_02193F34(a, c);
    h = (int)func_0200846C((u16)((e & 0x7fff) | 0x8000));
    func_020084A0((struct Sub0200852CObj *)h);
    func_020084D4(h, q + 0x38);
    func_0200852C((struct Sub0200852CObj *)h, ((struct Obj19617 *)q)->f48);
    func_0201F02C((struct WordSet *)b, d, (void *)h);
    func_020307B0((void *)h);
}
