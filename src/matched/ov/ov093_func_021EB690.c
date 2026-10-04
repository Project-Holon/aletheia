/*
 * function: func_021EB690
 * address: 0x021EB690
 * packet: pkt_ov093_021EB690
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EB660 0x021EB660 thumb ov093
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021EB584 0x021EB584 thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021EB820 0x021EB820 thumb ov093
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021EDA04 0x021EDA04 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 */
#include "../include/Obj00765.h"
#include "../include/Obj02793.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern int func_021EB660(u8 *, int *);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
extern void func_021ED798(u8 *);
extern int func_021ED814(struct S *);
struct Work;
extern void *func_021D5864(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void func_021EB584(int);
extern int func_021F7EB4(void);
extern int func_021EB820(u8 *);
extern void func_021EEE24(u32, u32, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(u8 *);
extern void func_021EDA04(u8 *);
extern void *func_021B86B8(void ***);
extern void func_021F7998(u32);
int func_021EB690(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    if (p[0x150]) return func_021EB660(p, state);
    switch (*state) {
    case 0:
        b[5] = 1;
        b[4] = func_021B8ED8(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
        *(u8 * *)&((struct Obj00765 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
        b[6] = func_021D5440(*(u8 * *)&((struct Obj00765 *)b)->f0);
        func_021ED798(p + 0x154);
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7EE8(func_021D5864(((struct Obj00765 *)b)->f0), b[5]);
            func_021F7A28(b[5], 0x231);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            func_021EEE24(((struct Obj02793 *)p)->f34, func_021EB820(p), 1, b[6]);
            func_021ECEB8(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68(p)) {
            func_021EDA04(p + 0x48 + b[4] * 12);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154))) {
            if ((int)func_021B86B8(*(void *** *)&((struct Obj02793 *)p)->f134) == 4) func_021F7998(0x23c);
            else func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 5:
        if (!func_021F7EB4()) {
            b[5] = 0;
            b[4] = func_021B8ED8(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj00765 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
            b[6] = func_021D5440(*(u8 * *)&((struct Obj00765 *)b)->f0);
            func_021F7EE8(func_021D5864(((struct Obj00765 *)b)->f0), b[5]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj02793 *)p)->f34, 11, 1, b[6]);
            func_021ECEB8(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ECF68(p)) {
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ED814((struct S *)(p + 0x154))) (*state)++;
        break;
    case 8:
        if (!func_021F7EB4()) {
            func_021EDA04(p + 0x48 + b[4] * 12);
            return 1;
        }
        break;
    }
    return 0;
}
