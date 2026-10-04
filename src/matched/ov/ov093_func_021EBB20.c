/*
 * function: func_021EBB20
 * address: 0x021EBB20
 * packet: pkt_ov093_021EBB20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * match-note: The loop stores and reads each call result through the same
 * pointer-typed lvalue. Integer-store/pointer-reload gave 628 bytes; a named
 * integer temporary gave 620 and lost the index spill; pointer lvalues gave
 * EXACT 624 bytes. Evidence: B10/BB20-r1.log through BB20-r3.log.
 * symbols:
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021EB670 0x021EB670 thumb ov093
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
#include "../include/Obj00406.h"
#include "../include/Obj01377.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern int func_021EB670(u8 *, int *);
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
extern void func_021EEE24(u32 a, u16 k, u32 n, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(u8 *);
extern void func_021EDA04(u8 *);
extern void *func_021B86B8(void ***);
extern void func_021F7998(u32);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern u8 func_021B8C50(char **p, u32 v, int k);
extern u8 func_021B8E70(u8 *, u32);
extern u8 func_021B8FF4(u8 *);
int func_021EBB20(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 a;
    unsigned i;
    u8 *q;
    if (p[0x150]) return func_021EB670(p, state);
    switch (*state) {
    case 0:
        a = func_021B8BEC(*(u8 * *)&((struct Obj01377 *)p)->f134, p[0x140], 0);
        b[10] = func_021B8C50(((struct Obj01377 *)p)->f134, a, 0);
        *(u8 * *)&((struct Obj00406 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, b[10]);
        b[8] = func_021D5440(*(u8 * *)&((struct Obj00406 *)b)->f0);
        b[11] = func_021B8C50(((struct Obj01377 *)p)->f134, a, 1);
        *(u8 * *)&((struct Obj00406 *)b)->f4 = func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, b[11]);
        b[9] = func_021D5440(*(u8 * *)&((struct Obj00406 *)b)->f4);
        func_021ED798(p + 0x154);
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            a = func_021B8E70(*(u8 * *)&((struct Obj01377 *)p)->f134, b[10]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f0), a);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            a = func_021B8E70(*(u8 * *)&((struct Obj01377 *)p)->f134, b[11]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f4), a);
            func_021F7A28(a, 0x231);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 3:
        if (!func_021F7EB4()) {
            func_021EEE24(((struct Obj01377 *)p)->f34, 2, 2, b[8], b[9]);
            func_021ECEB8(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ECF68(p)) {
            func_021EDA04(p + 0x48 + b[10] * 12);
            func_021EDA04(p + 0x48 + b[11] * 12);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            b[12] = 2;
            b[13] = 4;
            b[15] = func_021B8FF4(*(u8 * *)&((struct Obj01377 *)p)->f134);
            for (i = 0; i < 2; i++) {
                q = b + i;
                q[10] = func_021B8ED8(*(u8 * *)&((struct Obj01377 *)p)->f134, q[12]);
                ((u8 **)b)[i] = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, q[10]);
                if (((u8 **)b)[i]) q[8] = func_021D5440(((u8 **)b)[i]);
            }
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f0), b[12]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f4), b[13]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj01377 *)p)->f34, 12, 2, b[8], b[9]);
            func_021ECEB8(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ECF68(p)) {
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 8:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04(p + 0x48 + b[10] * 12);
            func_021EDA04(p + 0x48 + b[11] * 12);
            (*state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) return 1;
        break;
    }
    return 0;
}
