/*
 * function: func_02212988
 * address: 0x02212988
 * packet: pkt_ov199_02212988
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI exception: AE14 and 084F4 empty callees preserve live pointer r0;
 * caller consumes it after their BL, despite legacy void(void).
 * symbols:
 *   func_0201A948 0x0201A948 thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201A354 0x0201A354 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0201AC2C 0x0201AC2C thumb
 *   func_0201A2A8 0x0201A2A8 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02034714 0x02034714 arm
 *   d_02213D04 0x02213D04 data a1 ov199
 *   d_02213D00 0x02213D00 data a1 ov199
 */
#include "../include/Obj01078.h"
#include "../include/Obj02537.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct Party;
struct Rec160;
extern void func_0201A948(struct Party *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_0201A354(int, int);
extern void *func_0200AE14(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200B358(void *);
extern void *func_02012EBC(struct Big *p);
struct Rec534;
struct Sub0200852CObj;
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern void func_0201A2A8(void *, void *);
extern void *func_020084F4(void *);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_02213D04[], d_02213D00[];
u8 *func_02212988(int unused, unsigned heap, u8 *p)
{
    u8 *out;
    u8 *row;
    unsigned id;
    func_0201A948(((struct Obj01078 *)p)->f30);
    func_0201A948(((struct Obj01078 *)p)->f34);
    out = func_02030734(heap, 0x24, 0, d_02213D04, 0x32f);
    func_02082BCC(out, 0, 0x24);
    if (((struct Obj01078 *)p)->f1C == 2 || ((struct Obj01078 *)p)->f1C == 3) {
        switch (((struct Obj01078 *)p)->f8) {
        case 0: id = 15; break;
        case 1: id = 16; break;
        case 2: id = 17; break;
        case 3: id = 18; break;
        case 4: id = 19; break;
        default: func_02034714(d_02213D00, 0, d_02213D00); break;
        }
        ((struct Obj02537 *)out)->f0 = func_0201A354(id, heap);
    } else if (((struct Obj01078 *)p)->f1C == 0) {
        ((struct Obj02537 *)out)->f0 = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj01078 *)p)->f4)), 0));
    } else if (((struct Obj01078 *)p)->f1C == 1) {
        ((struct Obj02537 *)out)->f0 = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj01078 *)p)->f4)), 1));
    } else {
        func_02034714(d_02213D00, 0, d_02213D00);
    }
    ((struct Obj02537 *)out)->f1C = ((struct Obj01078 *)p)->f30;
    ((struct Obj02537 *)out)->f14 = ((struct Obj01078 *)p)->f4;
    func_0201AC2C((const struct Rec534 *)(*(u8 * *)&((struct Obj01078 *)p)->f28 + 0xd4), ((struct Obj01078 *)p)->f38);
    func_0201A2A8(((struct Obj02537 *)out)->f0, ((struct Obj01078 *)p)->f38);
    ((struct Obj02537 *)out)->f4 = ((struct Obj01078 *)p)->f38;
    row = *(u8 * *)&((struct Obj01078 *)p)->f2C;
    func_0201AC2C((const struct Rec534 *)(row + 0xd4), ((struct Obj01078 *)p)->f3C);
    func_0201A2A8(((struct Obj02537 *)out)->f0, ((struct Obj01078 *)p)->f3C);
    ((struct Obj02537 *)out)->f8 = func_020084F4(row);
    ((struct Obj02537 *)out)->f10 = ((struct Obj01078 *)p)->f3C;
    out[0xc] = func_02008550((const struct Sub0200852CObj *)row);
    return out;
}
