/*
 * file:     unit_021EBF20.c
 * unit:     yes
 * function: func_021EBF20, func_021EBF80, func_021EBFA0, func_021EBFDC, func_021EC0DC, func_021EC200, func_021EC2EC, func_021EC328, func_021EC478, func_021EC5D0, func_021EC768, func_021EC88C, func_021EC8C4, func_021ECA60, func_021ECC2C, func_021ECE08
 * address:  0x021EBF20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EB680  0x021EB680  thumb  ov093
 *   d_021F3918  0x021F3918  data  a4
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021EB584 0x021EB584 thumb ov093
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021EE104 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021B9064 0x021B9064 thumb ov093
 *   func_021B8ED8 0x021B8ED8 thumb ov093
 *   func_021B98AC 0x021B98AC thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5864 0x021D5864 thumb ov093
 *   func_021EDA04 0x021EDA04 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   func_021B9000  0x021B9000  thumb  ov093
 *   func_021B8FE4 0x021B8FE4 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 */
#include "../../matched/include/Obj00027.h"
#include "../../matched/include/Obj01696.h"
#include "../../matched/include/Obj00666.h"
#include "../../matched/include/Obj00766.h"
#include "../../matched/include/Obj00407.h"
#include "../../matched/include/Obj01697.h"
#include "../../matched/include/Obj00622.h"
#include "../../matched/include/Obj01523.h"
#include "../../matched/include/Obj00378.h"
#include "../../matched/include/Obj21588.h"

struct T;
struct Work;
struct E;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { int h, x, y, dx, dy; u8 state, cnt; };

extern int func_021EB680(u8 *, int *);
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B904C(u8 *p, int k);
extern u16 func_021BA020(char *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *);
extern void func_021F7A28(int, u32);
extern void func_021EB584(int);
extern int func_021F7EB4(void);
extern void *func_021B86B8(void ***);
extern void func_021EE104(u8 *p, u32 *out, u32 a, u32 b, u32 flag);
extern void func_021F823C(u32 *);
extern void func_021EEE24(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(struct T *p);
extern u32 func_021B9064(u8 *p, int k, int x);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
extern void *func_021D5864(struct Work *p);
extern void func_021EDA04(struct E *e);
extern void func_021F7EE8(void *, int);
extern void func_021F8260(u32 i);
extern int func_021D5B68(void *);
extern void func_021F7998(u32);
extern int func_021F827C(u32 i);
extern u8 func_021B9000(u8 *);
extern u8 func_021B8FE4(u8 *);
extern int func_021B9F70(u8 *p, int i);
int func_021EBF20(int *a, u8 *b);
int func_021EBF80(u8 *p, int *state);
int func_021EBFA0(u8 *p, int *state);
int func_021EBFDC(u8 *p, int *state, u16 i);
int func_021EC0DC(u8 *p, int *state, u16 i, u16 j);
int func_021EC200(u8 *p, int *state);
int func_021EC2EC(u8 *p, int *state);
int func_021EC328(u8 *p, int *state, u8 id);
int func_021EC478(u8 *p, int *state, u16 id, u16 other);
int func_021EC5D0(u8 *p, int *state);
int func_021EC768(u8 *p, int *state);
int func_021EC88C(u8 *p, int *state);
int func_021EC8C4(u8 *p, int *state, u8 id);
int func_021ECA60(u8 *p, int *state, u32 a, u8 c);
int func_021ECC2C(u8 *p, int *state);
u16 func_021ECE08(u8 *a, int b);

extern int (*const d_021F3918[][2])(u8 *, int *);



int func_021EBF20(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB680(b, a);
    if (b[0x14f] < 3) {
        if (d_021F3918[b[0x14f]][func_021B8FF4(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}

int func_021EBF80(u8 *p, int *state)
{
    return func_021EBFDC(p, state, func_021B904C(((struct Obj00027 *)p)->f134, 0));
}

int func_021EBFA0(u8 *p, int *state)
{
    u8 a = func_021B904C(((struct Obj00027 *)p)->f134, 0);
    u8 b = func_021B904C(((struct Obj00027 *)p)->f134, 1);
    if (a != b)
        return func_021EC0DC(p, state, a, b);
    return func_021EBFDC(p, state, a);
}

int func_021EBFDC(u8 *p, int *state, u16 i)
{
    u8 *b = p + 0xf0;
    int msg;
    u32 buf[7];
    switch (*state) {
    case 0:
        b[1] = 9;
        func_021F7F58(func_021BA020(*(char * *)&((struct Obj00027 *)p)->f134, i), b[1], 0, 0, 0);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7A28(b[1], 0x237);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            if ((int)func_021B86B8(*(void *** *)&((struct Obj00027 *)p)->f134) != 3) msg = 7;
            else msg = 8;
            func_021EE104(p, buf, i, 4, 1);
            func_021F823C(buf);
            func_021EEE24(((struct Obj00027 *)p)->f34, msg, 1, i);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F7A28(b[1], 0x238);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) return 1;
        break;
    }
    return 0;
}

int func_021EC0DC(u8 *p, int *state, u16 i, u16 j)
{
    u8 *b = p + 0xf0;
    int msg;
    u32 buf[7];
    switch (*state) {
    case 0:
        b[0] = 11;
        b[1] = 13;
        func_021F7F58(func_021BA020(*(char * *)&((struct Obj00027 *)p)->f134, i), b[0], 0, 0, 0);
        func_021F7F58(func_021BA020(*(char * *)&((struct Obj00027 *)p)->f134, j), b[1], 0, 0, 0);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7A28(b[0], 0x237);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            if ((int)func_021B86B8(*(void *** *)&((struct Obj00027 *)p)->f134) != 3) msg = 9;
            else msg = 10;
            func_021EE104(p, buf, i, j, 1);
            func_021F823C(buf);
            func_021EEE24(((struct Obj00027 *)p)->f34, msg, 2, i, j);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F7A28(b[0], 0x238);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) return 1;
        break;
    }
    return 0;
}

int func_021EC200(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    switch (*state) {
    case 0:
        b[5] = 1;
        b[8] = func_021B9064(*(u8 * *)&((struct Obj00027 *)p)->f134, func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134), 0);
        b[4] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[5]);
        *(u8 * *)&((struct Obj01696 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[4]);
        b[6] = func_021D5440(*(u8 * *)&((struct Obj01696 *)b)->f0);
        func_021EEE24(((struct Obj00027 *)p)->f34, func_021ECE08(p, 1), 2, b[8], b[6]);
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
        func_021F7EE8(func_021D5864(((struct Obj01696 *)b)->f0), b[5]);
        func_021F7A28(b[5], 0x239);
        func_021F8260(1);
        (*state)++;
        break;
    case 3:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

int func_021EC2EC(u8 *p, int *state)
{
    u8 a = func_021B904C(((struct Obj00027 *)p)->f134, 0);
    u8 b = func_021B904C(((struct Obj00027 *)p)->f134, 1);
    if (a != b)
        return func_021EC478(p, state, a, b);
    return func_021EC328(p, state, a);
}

int func_021EC328(u8 *p, int *state, u8 id)
{
    u8 *b = p + 0xf0;
    unsigned i;
    switch (*state) {
    case 0:
        b[10] = 3;
        b[11] = 5;
        b[15] = id;
        b[14] = 0;
        for (i = 0; i < 2; i++) {
            b[8 + i] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[10 + i]);
            ((u8 **)b)[i] = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[8 + i]);
            b[12 + i] = func_021D5440(((u8 **)b)[i]);
            if (!func_021D5B68(((void **)b)[i])) b[14]++;
        }
        func_021EEE24(((struct Obj00027 *)p)->f34, func_021ECE08(p, b[14]), 3, b[15], b[12], b[13]);
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
        func_021F7EE8(func_021D5864(((struct Obj00666 *)b)->f0), b[10]);
        if (b[14] == 2) func_021F7EE8(func_021D5864(((struct Obj00666 *)b)->f4), b[11]);
        func_021F7A28(b[10], 0x239);
        func_021F8260(1);
        (*state)++;
        break;
    case 3:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[8] * 12));
            if (b[14] == 2) func_021EDA04((struct E *)(p + 0x48 + b[9] * 12));
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * lever: u16 id and other retain the entry spill and the later argument reload order.
 */
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

int func_021EC5D0(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    unsigned i;
    switch (*state) {
    case 0:
        b[15] = 3;
        b[16] = 5;
        b[17] = 7;
        b[21] = 0;
        b[22] = func_021B9064(*(u8 * *)&((struct Obj00027 *)p)->f134, func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134), 0);
        for (i = 0; i < 3; i++) {
            b[12 + i] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[15 + i]);
            ((u8 **)b)[i] = func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[12 + i]);
            b[18 + i] = func_021D5440(((u8 **)b)[i]);
            if (!func_021D5B68(((void **)b)[i])) b[21]++;
        }
        func_021EEE24(((struct Obj00027 *)p)->f34, func_021ECE08(p, b[21]), 4, b[22], b[18], b[19], b[20]);
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
        func_021F7EE8(func_021D5864(((struct Obj00407 *)b)->f0), b[15]);
        if (b[21] > 1) func_021F7EE8(func_021D5864(((struct Obj00407 *)b)->f4), b[16]);
        if (b[21] > 2) func_021F7EE8(func_021D5864(((struct Obj00407 *)b)->f8), b[17]);
        func_021F7A28(b[15], 0x239);
        func_021F8260(1);
        (*state)++;
        break;
    case 3:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[12] * 12));
            if (b[21] > 1) func_021EDA04((struct E *)(p + 0x48 + b[13] * 12));
            if (b[21] > 2) func_021EDA04((struct E *)(p + 0x48 + b[14] * 12));
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}

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

int func_021EC88C(u8 *p, int *state)
{
    u8 a = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
    u8 b = func_021B9000(*(u8 * *)&((struct Obj00027 *)p)->f134);
    if (b == 4)
        return func_021EC8C4(p, state, a);
    return func_021ECA60(p, state, a, b);
}

/*
 * lever: unsigned long loop counter fixes the base/counter register swap;
 * use one pointer element type for the store, null guard and subsequent calls.
 */
int func_021EC8C4(u8 *p, int *state, u8 id)
{
    u8 *b = p + 0xf0;
    unsigned long i;
    u32 buf[7];
    switch (*state) {
    case 0:
        b[15] = id;
        func_021EE104(p, buf, b[15], 4, 0);
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
            b[10] = 2;
            b[11] = 4;
            b[14] = 0;
            b[15] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
            for (i = 0; i < 2U; i++) {
                b[8 + i] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[10 + i]);
                ((u8 **)b)[i] = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[8 + i]);
                if (((u8 **)b)[i]) {
                    b[12 + i] = func_021D5440(((u8 **)b)[i]);
                    if (!func_021D5B68(((u8 **)b)[i])) b[14]++;
                }
            }
            func_021F7EE8(func_021D5864(((struct Obj00622 *)b)->f0), b[10]);
            if (b[14] > 1) func_021F7EE8(func_021D5864(((struct Obj00622 *)b)->f4), b[11]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj00027 *)p)->f34, b[14] == 2 ? 12 : 11, 2, b[12], b[13]);
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
            func_021EDA04((struct E *)(p + 0x48 + b[8] * 12));
            if (b[14] > 1) func_021EDA04((struct E *)(p + 0x48 + b[9] * 12));
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}

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
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154))) {
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
        if (func_021ECF68((struct T *)p)) {
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[8] * 12));
            func_021EDA04((struct E *)(p + 0x48 + b[9] * 12));
            return 1;
        }
        break;
    }
    return 0;
}

int func_021ECC2C(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    unsigned long i;
    u32 buf[7];
    u16 msg;
    switch (*state) {
    case 0:
        b[22] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
        func_021EE104(p, buf, b[22], 4, 0);
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
            b[15] = 2;
            b[16] = 4;
            b[17] = 6;
            b[21] = 0;
            b[22] = func_021B8FF4(*(u8 * *)&((struct Obj00027 *)p)->f134);
            for (i = 0; i < 3U; i++) {
                b[12 + i] = func_021B8ED8(*(u8 * *)&((struct Obj00027 *)p)->f134, b[15 + i]);
                ((u8 **)b)[i] = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj00027 *)p)->f138, b[12 + i]);
                b[18 + i] = func_021D5440(((u8 **)b)[i]);
                if (!func_021D5B68(((u8 **)b)[i])) b[21]++;
            }
            func_021F7EE8(func_021D5864(((struct Obj00378 *)b)->f0), b[15]);
            if (b[21] > 1) func_021F7EE8(func_021D5864(((struct Obj00378 *)b)->f4), b[16]);
            if (b[21] > 2) func_021F7EE8(func_021D5864(((struct Obj00378 *)b)->f8), b[17]);
            func_021F7998(0x234);
            if (b[21] == 3) msg = 13;
            else msg = b[21] == 2 ? 12 : 11;
            func_021EEE24(((struct Obj00027 *)p)->f34, msg, 3, b[18], b[19], b[20]);
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
            func_021EDA04((struct E *)(p + 0x48 + b[12] * 12));
            if (b[21] > 1) func_021EDA04((struct E *)(p + 0x48 + b[13] * 12));
            if (b[21] > 1) func_021EDA04((struct E *)(p + 0x48 + b[14] * 12));
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}


u16 func_021ECE08(u8 *a, int b)
{
    int r;

    switch ((int)func_021B86B8(*(void *** *)&((struct Obj21588 *)a)->f134)) {
    case 0:
    default:
        r = 1;
        if (b != 1)
            r = 2;
        return r;
    case 1:
    case 2:
        if (b == 1)
            return 0xe;
        if (b == 2)
            return 0xf;
        return 0x10;
    case 3:
        if (b == 1)
            return 0x11;
        if (b == 2)
            return 0x12;
        return 0x13;
    }
}
