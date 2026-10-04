/*
 * function: func_02213134
 * address: 0x02213134
 * packet: pkt_ov199_02213134
 * region: ov199
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI exception: empty AE14 preserves its input pointer in r0, consumed here.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034714 0x02034714 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B1D4 0x0200B1D4 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_0200BA38 0x0200BA38 thumb
 *   d_02213D04 0x02213D04 data a1 ov199
 *   d_02213D00 0x02213D00 data a1 ov199
 */
#include "../include/Obj02248.h"
#include "../include/Obj25295.h"
typedef unsigned char u8;
extern void *func_02030734(unsigned, unsigned, int, const char *, unsigned short);
extern void func_02082BCC(void *, int, unsigned);
typedef unsigned int   u32;
struct Big;
struct Rec160;
struct Reg;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200B358(void *);
extern struct Rec160 *func_0200B1D4(struct Rec160 *arr, u32 index);
extern void *func_0200AE14(void *);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern unsigned func_0200BA38(unsigned);
extern const char d_02213D04[], d_02213D00[];
unsigned *func_02213134(int unused, unsigned heap, u8 *p)
{
    unsigned *out;
    unsigned index, id, flag;
    unsigned zero = 0;
    void *reg;
    int a;
    unsigned b;
    out = func_02030734(heap, 0x18, 0, d_02213D04, 0x637);
    func_02082BCC(out, 0, 0x18);
    if (((struct Obj02248 *)p)->f1C == 3) {
        id = ((struct Obj02248 *)p)->f8 + 0x17;
    } else if (((struct Obj02248 *)p)->f1C == 2) {
        id = ((struct Obj02248 *)p)->f8 + 0x1c;
    } else {
        if (((struct Obj02248 *)p)->f1C == 0) index = zero;
        else if (((struct Obj02248 *)p)->f1C == 1) index = 1;
        else func_02034714(d_02213D00, zero, d_02213D00);
        reg = func_0200AE14(func_0200B1D4(func_0200B358(func_02012EBC(((struct Obj02248 *)p)->f4)), index));
        a = func_0200AE54(reg, 0xd);
        b = func_0200AE54(reg, 0x15);
        if (a >= 2) a = 1;
        id = a + (b * 2 + 0x21);
    }
    flag = 1;
    out[0] = *(unsigned *)&((struct Obj02248 *)p)->f4;
    out[1] = flag;
    out[2] = 0;
    out[4] = id;
    out[5] = 0;
    if (((struct Obj02248 *)p)->f1C == 1) {
        out[3] = flag;
    } else {
        if (((struct Obj02248 *)p)->f1C4 == 0 && ((struct Obj02248 *)p)->f1C8 == 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        out[3] = flag;
    }
    if (func_0200BA38((u8)((struct Obj25295 *)(*(u8 * *)&((struct Obj02248 *)p)->f2C))->f44) != 0) out[1] = 1;
    else out[1] = 0;
    return out;
}
