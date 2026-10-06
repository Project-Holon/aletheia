/*
 * function: func_02020234
 * address:  0x02020234
 * packet:   pkt_02020234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020234.c \
 *       --func func_02020234 --addr 0x02020234 --cc 1.1p1 --thumb
 */
#include "../include/Obj08776.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct CharBuf;
struct Obj;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0202055C(struct Obj *obj, u16 row, u16 col, u16 n, u32 flag);
extern void func_020206C0(struct Obj *obj);

void func_02020234(u8 *p)
{
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj08776 *)p)->fC)),
                  ((struct Ctl *)p)->lo4);
    func_0202055C((struct Obj *)p, ((struct Obj08776 *)p)->f40, 0, ((struct Obj08776 *)p)->f12, 1);
    func_020206C0((struct Obj *)p);
}
