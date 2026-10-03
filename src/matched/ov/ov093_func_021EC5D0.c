/*
 * function: func_021EC5D0
 * address: 0x021EC5D0
 * packet: pkt_ov093_021EC5D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5B68 0x021D5B68 thumb ov093
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
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S { int h, x, y, dx, dy; u8 state, cnt; };
extern u8 func_021B8FF4(u8 *);
extern u8 func_021B9064(u8 *, u32, u32);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern u8 func_021D5440(u8 *p);
extern void *func_021D5864(void *);
extern u16 func_021ECE08(u8 *, int);
extern void func_021EEE24(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(u8 *);
extern void func_021ED798(u8 *);
extern int func_021ED814(struct S *);
extern void func_021EDA04(u8 *);
extern void func_021F7EE8(void *, int);
extern void func_021F7A28(int, u32);
extern void func_021F8260(int);
extern int func_021F7EB4(void);
extern int func_021D5B68(void *);
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
        b[22] = func_021B9064(*(u8 **)(p + 0x134), func_021B8FF4(*(u8 **)(p + 0x134)), 0);
        for (i = 0; i < 3; i++) {
            b[12 + i] = func_021B8ED8(*(u8 **)(p + 0x134), b[15 + i]);
            ((u8 **)b)[i] = func_021B98AC(*(char *const **)(p + 0x138), b[12 + i]);
            b[18 + i] = func_021D5440(((u8 **)b)[i]);
            if (!func_021D5B68(((void **)b)[i])) b[21]++;
        }
        func_021EEE24(*(u32 *)(p + 0x34), func_021ECE08(p, b[21]), 4, b[22], b[18], b[19], b[20]);
        func_021ECEB8(p, *(u32 *)(p + 0x34), 0x50, 0);
        (*state)++;
        break;
    case 1:
        if (func_021ECF68(p)) {
            func_021ED798(p + 0x154);
            (*state)++;
        }
        break;
    case 2:
        func_021F7EE8(func_021D5864(*(void **)b), b[15]);
        if (b[21] > 1) func_021F7EE8(func_021D5864(*(void **)(b + 4)), b[16]);
        if (b[21] > 2) func_021F7EE8(func_021D5864(*(void **)(b + 8)), b[17]);
        func_021F7A28(b[15], 0x239);
        func_021F8260(1);
        (*state)++;
        break;
    case 3:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04(p + 0x48 + b[12] * 12);
            if (b[21] > 1) func_021EDA04(p + 0x48 + b[13] * 12);
            if (b[21] > 2) func_021EDA04(p + 0x48 + b[14] * 12);
            (*state)++;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
