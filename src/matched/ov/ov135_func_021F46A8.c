/*
 * function: func_021F46A8
 * address: 0x021F46A8
 * packet: pkt_ov135_021F46A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_0205D074 0x0205D074 arm
 *   func_021F4EB4 0x021F4EB4 thumb ov135
 *   func_020370F4 0x020370F4 arm
 *   func_021C7C1C 0x021C7C1C arm ov114
 *   func_02031330 0x02031330 arm
 *   func_02030D28 0x02030D28 arm
 *   func_02202770 0x02202770 thumb ov135
 *   func_021F49A8 0x021F49A8 thumb ov135
 *   func_020221A4 0x020221A4 thumb
 *   func_021FF6A4 0x021FF6A4 thumb ov135
 *   func_021FFB20 0x021FFB20 thumb ov135
 *   func_021F4F84 0x021F4F84 thumb ov135
 *   func_0204A600 0x0204A600 arm
 *   d_02203A80 0x02203A80 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int (*init)(u8 *, int); int (*update)(u8 *, int); int (*finish)(u8 *, int); } Handler;
extern const Handler d_02203A80[];
extern int func_0203CD98(void);
extern u32 func_0205D074(void);
extern int func_021F4EB4(void);
extern u32 func_020370F4(u32);
extern void func_021C7C1C(void);
extern u32 func_02031330(void *);
extern void func_02030D28(void *);
extern void func_02202770(void *);
extern void func_021F49A8(void);
extern u32 func_020221A4(void);
extern void func_021FF6A4(u8 *);
extern void func_021FFB20(u8 *, int, int);
extern void func_021F4F84(u8 *);
extern void func_0204A600(void *);
int func_021F46A8(void *unused0, int *state, void *unused2, u8 *p)
{
    if (func_0203CD98() != 0) {
        func_0205D074();
        func_020370F4(func_021F4EB4());
    }
    func_021C7C1C();
    *(u32 *)(p + 0x12f4) = func_02031330(*(void **)(p + 0x12f0));
    func_02030D28(*(void **)(p + 0xf94));
    func_02202770(p + 0xfa0);
    switch (*state) {
    case 0:
        *state = d_02203A80[*(u32 *)(p + 16)].init(p, *state);
        func_021F49A8();
        break;
    case 1:
        if (func_020221A4() != 0) *state = 2;
        break;
    case 2:
        *state = d_02203A80[*(u32 *)(p + 16)].update(p, *state);
        break;
    case 3:
        if (func_020221A4() != 0) {
            *state = d_02203A80[*(u32 *)(p + 16)].finish(p, *state);
            if (*(u32 *)(p + 184) != 0) {
                func_021FF6A4(p);
                func_021FFB20(p, *(int *)(p + 208), 0);
                *(u32 *)(p + 184) = 0;
            }
        }
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        return 1;
    }
    func_021F4F84(p);
    if (*(u32 *)(p + 0xbc0) != 0) func_0204A600(*(void **)(p + 0xbc0));
    if (*(int *)(p + 0x12e8) > 0) *(int *)(p + 0x12e8) -= 1;
    return 0;
}
