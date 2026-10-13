/*
 * function: func_021E4FF4
 * address:  0x021E4FF4
 * packet:   pkt_ov093_021E4FF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13523.h"
#include "../include/Obj13524.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct Rec {
    u8 pad[0xe];
    u8 id;
    u8 f0 : 1;
    u8 f1 : 1;
} Rec;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D58A8(u8 *p, int k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E4FF4(int a, void *b, int c)
{
    void *q;
    u8 *w;
    Rec *r;

    if (c == BTL_EVENT_GetVar(3)) {
        q = func_021C7CF4(b, c);
        r = func_021C88A4(b, 0x11, c);
        r->id = c;
        ((struct Obj13523 *)r)->f4 = func_021D58A8(q, 9);
        ((struct Obj13523 *)r)->f6 = func_021D58A8(q, 8);
        r->f0 = 1;
        r->f1 = 1;
        func_021C8838((u8 *)r + 0x10, 2, 0x305);
        func_021C8860((struct S *)((u8 *)r + 0x10), c);
        func_021C88C8(b, r);
        w = func_021C88A4(b, 0x17, c);
        w[8] = c;
        ((struct Obj13524 *)w)->f4 = 0xa;
        func_021C88C8(b, w);
    }
}
