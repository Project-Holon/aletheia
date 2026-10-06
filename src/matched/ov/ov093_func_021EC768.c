/*
 * function: func_021EC768
 * address: 0x021EC768
 * packet: pkt_ov093_021EC768
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE104 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
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
#include "../include/Obj01697.h"
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
extern void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag);
extern void func_021F823C(u32 *);
extern void func_021F7998(u32);
extern int func_021F827C(u32 i);
int func_021EC768(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    u32 buf[7];
    switch (*state) {
    case 0:
        b[7] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
        func_021EE104(p, buf, b[7], 4, 0);
        func_021F823C(buf);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[5] = 0;
            b[7] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
            b[4] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj01697 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[4]);
            b[6] = func_021D5440(*(u8 * *)&((struct Obj01697 *)b)->f0);
            func_021F7EE8(func_021D5864(((struct Obj01697 *)b)->f0), b[5]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj00027 *)p)->f34, 11, 1, b[6]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}
