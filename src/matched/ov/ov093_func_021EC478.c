/*
 * function: func_021EC478
 * address: 0x021EC478
 * packet: pkt_ov093_021EC478
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 id and other retain the entry spill and the later argument reload order.
 * symbols:
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_021ECE08 0x021ECE08 thumb ov093
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021EDA04 0x021EDA04 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 */
#include "../include/Obj00027.h"
#include "../include/Obj00766.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern u8 func_021B8FF4(u8 *);
struct Work;
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
extern void *func_021D5864(struct Work *p);
extern u16 func_021ECE08(u8 *, int);
extern void func_021EEE24(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
struct E;
struct T;
extern int func_021ECF68(struct T *p);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *);
extern void func_021EDA04(struct E *e);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void func_021F8260(u32 i);
extern int func_021F7EB4(void);
int func_021EC478(u8 *p, int *state, u16 id, u16 other)
{
    u8 *b = p + 0xf0;
    switch (*state) {
    case 0:
        b[10] = 3;
        b[8] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[10]);
        *(u8 * *)&((struct Obj00766 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[8]);
        b[12] = func_021D5440(*(u8 * *)&((struct Obj00766 *)b)->f0);
        b[11] = 5;
        b[9] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[11]);
        *(u8 * *)&((struct Obj00766 *)b)->f4 = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[9]);
        b[13] = func_021D5440(*(u8 * *)&((struct Obj00766 *)b)->f4);
        func_021EEE24(((struct Obj00027 *)p)->f34, func_021ECE08(p, 1), 2, id, b[12]);
        func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (func_021ECF68((struct T *)p)) {
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 2:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021EEE24(((struct Obj00027 *)p)->f34, func_021ECE08(p, 1), 2, other, b[13]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F7EE8(func_021D5864(((struct Obj00766 *)b)->f0), b[10]);
            func_021F7EE8(func_021D5864(((struct Obj00766 *)b)->f4), b[11]);
            func_021F7A28(b[10], 0x239);
            func_021F8260(1);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[8] * 12));
            func_021EDA04((struct E *)(p + 0x48 + b[9] * 12));
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}
