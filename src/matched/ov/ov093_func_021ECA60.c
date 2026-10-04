/*
 * function: func_021ECA60
 * address: 0x021ECA60
 * packet: pkt_ov093_021ECA60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EE104 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B8FE4 0x021B8FE4 thumb ov093
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021EDA04 0x021EDA04 thumb ov093
 */
#include "../include/Obj00027.h"
#include "../include/Obj01523.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021EE104(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern int func_021F7EB4(void);
extern void func_021F7998(u32);
extern int func_021F827C(u32);
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B8FE4(u8 *);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
struct Work;
extern int func_021B9F70(u8 *p, int i);
extern void func_021EEE24(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(u8 *);
extern void func_021F8260(u32 i);
extern void func_021ED798(u8 *);
extern int func_021ED814(void *);
extern void *func_021D5864(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021EDA04(u8 *);
int func_021ECA60(u8 *p, int *state, u32 a, u8 c)
{
    u8 *b = p + 0xf0;
    unsigned long i;
    u32 buf[7];
    u8 side;
    u8 winner;
    u16 msg;
    switch (*state) {
    case 0:
        if (a < c) func_021EE104(p, buf, a, c, 0);
        else func_021EE104(p, buf, c, a, 0);
        func_021F823C(buf);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021F7998(0x233);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[10] = 2;
            b[11] = 4;
            b[15] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
            side = func_021B8FE4(*(u8 * *)&((struct Obj00027 *)p)->f134) ^ 1;
            for (i = 0; i < 2U; i++) {
                b[8 + i] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[10 + i]);
                ((u8 **)b)[i] = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[8 + i]);
                b[12 + i] = func_021D5440(((u8 **)b)[i]);
            }
            msg = func_021B9F70(((struct Obj00027 *)p)->f134, c) ? 14 : 17;
            func_021EEE24(((struct Obj00027 *)p)->f34, msg, 2, c, (b + side)[12]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68(p)) {
            func_021F8260(0);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814(p + 0x154)) {
            winner = func_021B8FE4(*(u8 * *)&((struct Obj00027 *)p)->f134);
            func_021F7EE8(func_021D5864(*(void **)b), b[10]);
            func_021F7EE8(func_021D5864(((struct Obj01523 *)b)->f4), b[11]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj00027 *)p)->f34, 11, 1, (b + winner)[12]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68(p)) {
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814(p + 0x154) && !func_021F7EB4()) {
            func_021EDA04(p + 0x48 + b[8] * 12);
            func_021EDA04(p + 0x48 + b[9] * 12);
            return 1;
        }
        break;
    }
    return 0;
}
