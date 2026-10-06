/*
 * function: func_021B8EE8
 * address:  0x021B8EE8
 * packet:   pkt_ov071_021B8EE8
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_02045B38  0x02045B38  arm
 *   func_021B9560  0x021B9560  thumb  ov071
 *   func_021B95FC  0x021B95FC  thumb  ov071
 *   func_021B96A4  0x021B96A4  thumb  ov071
 *   func_021BA11C  0x021BA11C  thumb  ov071
 *   func_021B9BB8  0x021B9BB8  thumb  ov071
 *   func_021B9AE4  0x021B9AE4  thumb  ov071
 *   func_021B9B64  0x021B9B64  thumb  ov071
 *   func_021B9BE8  0x021B9BE8  thumb  ov071
 *   func_021B9750  0x021B9750  thumb  ov071
 *   func_021B7174  0x021B7174  thumb  ov071
 *   func_020056A0  0x020056A0  thumb
 *   func_021BA1B0  0x021BA1B0  thumb  ov071
 *   func_021B9970  0x021B9970  thumb  ov071
 *   func_021B992C  0x021B992C  thumb  ov071
 *   func_021B9A40  0x021B9A40  thumb  ov071
 *   func_021BA140  0x021BA140  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B9F2C  0x021B9F2C  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 */
#include "../include/Obj01884.h"
#include "../include/Obj02123.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

extern void *func_0203159C(int a, int b, int c);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B6C54(char *p);
struct MsgBank;
struct PrintSys;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_021B9560(void);
extern void func_021B95FC(void *a, void *b);
extern void func_021B96A4(char *a, void **b);
extern void func_021BA11C(char *p);
extern void func_021B9BB8(char *p, char *q);
extern void func_021B9AE4(void *a, void *b);
extern void func_021B9B64(char *p, char *q);
extern void func_021B9BE8(char *p, char *q);
extern void func_021B9750(char *a, char *b);
typedef unsigned short u16;
struct R;
extern struct R *func_021B7174(u32 *p, int a, u16 heap);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_021BA1B0(void *unused, char *p);
extern void func_021B9970(void *a, void *b, void *c);
extern void func_021B992C(char *a);
extern int func_021B9A40(char *a, char *b);
extern void func_021BA140(u8 *p);
extern u8 func_020355C4(void);
extern int func_021B9F2C(u8 *p, int i, int v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern void func_02040588(u32 which, u32 enable);
extern void func_02043598(u32 mask, u32 enable);

int func_021B8EE8(int a, int *b, u8 *c, u8 *o)
{
    int busy;
    u32 t;
    Bool f;

    switch (*b) {
    case 0:
        o = func_0203159C(a, 0x314, 0x61);
        func_02082BCC(o, 0, 0x314);
        ((struct Obj01884 *)o)->f2D8 = 0x800;
        ((struct Obj01884 *)o)->f300 = 0xffff;
        ((struct Obj01884 *)o)->f2F8 = 0xffff;
        ((struct Obj01884 *)o)->f2FC = 0xffff;
        func_021B6C54((char *)c);
        ((struct Obj01884 *)o)->f20 = (int)func_02045B38(0, 2, 0xa0, 0x61);
        func_021B9560();
        func_021B95FC(o, ((struct Obj02123 *)c)->f4);
        func_021B96A4((char *)o, ((struct Obj02123 *)c)->f4);
        func_021BA11C((char *)o);
        func_021B9BB8((char *)c, (char *)o);
        func_021B9AE4(o, ((struct Obj02123 *)c)->f4);
        func_021B9B64((char *)c, (char *)o);
        func_021B9BE8((char *)c, (char *)o);
        func_021B9750((char *)c, (char *)o);
        ((struct Obj01884 *)o)->f30C = (int)func_021B7174(((struct Obj02123 *)c)->f4, 4, 0x61);
        (*(u8 **)(c + 8))[1] = 0x30;
        ((struct Obj01884 *)o)->f0 = func_020056A0((void (*)(void))func_021BA1B0, o, 3);
        func_021B9970(c, o, ((struct Obj02123 *)c)->f4);
        func_021B992C((char *)o);
        *b = *b + 1;
        break;
    case 1:
        if (func_021B9A40((char *)o, ((struct Obj02123 *)c)->f4) == 1) {
            func_021BA140(o);
            ((struct Obj01884 *)o)->f2F0 = 1;
            if (func_020355C4() == 0) {
                func_021B9F2C(o, 1, 0);
            } else {
                func_021B9F2C(o, 0xffff, 0);
            }
            *b = *b + 1;
        }
        break;
    case 2:
        busy = 0;
        t = (*(u32 **)(c + 4))[2];
        if (o[0x28c] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj01884 *)o)->f288))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj01884 *)o)->f288);
                o[0x28c] = 0;
            }
        }
        f = o[0x28c] == 0 ? B_TRUE : B_FALSE;
        if (f == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
