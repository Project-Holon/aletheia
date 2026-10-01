/*
 * function: func_021EB870
 * address: 0x021EB870
 * packet: pkt_ov093_021EB870
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021EE104 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern int func_021EB660(u8 *, int *);
extern u8 func_021B8ED8(u8 *, u32);
extern int func_021B98AC(char *const *, u8);
extern u8 func_021D5440(u8 *);
extern void func_021ED798(u8 *);
extern int func_021ED814(struct S *);
extern int func_021D5864(void *);
extern void func_021F7EE8(u32, u32);
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
extern u8 func_021B8DE4(u8 *, int);
extern u16 func_021BA020(char *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021EE104(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern u8 func_021B8FF4(u8 *);
extern void func_021F8260(u32);
extern int func_021F827C(u32);
int func_021EB870(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 buf1[7];
    u32 buf2[7];
    u32 a, i;
    if (p[0x150]) return func_021EB660(p, state);
    switch (*state) {
    case 0:
        a = func_021B8ED8(*(u8 **)(p + 0x134), 1);
        i = func_021B8DE4(*(u8 **)(p + 0x134), a);
        func_021F7F58(func_021BA020(*(char **)(p + 0x134), i), 9, 0, 0, 0);
        b[5] = 1;
        b[7] = i;
        b[4] = a;
        *(int *)b = func_021B98AC(*(char *const **)(p + 0x138), b[4]);
        b[6] = func_021D5440(*(u8 **)b);
        func_021ED798(p + 0x154);
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7A28(b[5], 0x237);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            func_021EE104(p, buf1, b[7], 4, 1);
            func_021F823C(buf1);
            func_021EEE24(*(u32 *)(p + 0x34), 7, 1, b[7]);
            func_021ECEB8(p, *(u32 *)(p + 0x34), 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68(p)) {
            func_021F7A28(b[5], 0x238);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EEE24(*(u32 *)(p + 0x34), 14, 2, 1, b[6]);
            func_021ECEB8(p, *(u32 *)(p + 0x34), 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68(p)) {
            func_021F7EE8(func_021D5864(*(void **)b), b[5]);
            func_021F7A28(b[5], 0x239);
            func_021F8260(1);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EE104(p, buf2, func_021B8FF4(*(u8 **)(p + 0x134)), 4, 0);
            func_021F823C(buf2);
            (*state)++;
        }
        break;
    case 7:
        func_021EDA04(p + 0x48 + b[4] * 12);
        func_021F7998(0x232);
        (*state)++;
        break;
    case 8:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[5] = 0;
            b[4] = func_021B8ED8(*(u8 **)(p + 0x134), b[5]);
            *(int *)b = func_021B98AC(*(char *const **)(p + 0x138), b[4]);
            b[6] = func_021D5440(*(u8 **)b);
            func_021F7EE8(func_021D5864(*(void **)b), b[5]);
            func_021F7998(0x234);
            func_021EEE24(*(u32 *)(p + 0x34), 11, 1, b[6]);
            func_021ECEB8(p, *(u32 *)(p + 0x34), 0x50, 0);
            (*state)++;
        }
        break;
    case 9:
        if (func_021ECF68(p)) {
            func_021F8260(0);
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 10:
        if (func_021ED814((struct S *)(p + 0x154))) (*state)++;
        break;
    case 11:
        if (!func_021F7EB4()) {
            func_021EDA04(p + 0x48 + b[4] * 12);
            return 1;
        }
        break;
    }
    return 0;
}
