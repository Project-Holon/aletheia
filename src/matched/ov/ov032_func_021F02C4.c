/*
 * function: func_021F02C4
 * address:  0x021F02C4
 * packet:   pkt_ov032_021F02C4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F180C  0x021F180C  thumb  ov032
 *   func_021F05E8  0x021F05E8  thumb  ov032
 *   func_021F0DD8  0x021F0DD8  thumb  ov032
 *   func_021F1144  0x021F1144  thumb  ov032
 *   func_021F0EA4  0x021F0EA4  thumb  ov032
 *   func_021F0AC0  0x021F0AC0  thumb  ov032
 *   func_021F0B10  0x021F0B10  thumb  ov032
 *   func_021F06E0  0x021F06E0  thumb  ov032
 *   func_02165AC4  0x02165AC4  thumb  ov010
 *   func_021659F0  0x021659F0  thumb  ov010
 *   func_021F13A0  0x021F13A0  thumb  ov032
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021F180C(u8 *p, int x, int flag);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F0DD8(unsigned int a);
extern void func_021F1144(u8 *p, u8 *q, int r, int mode, int skip, int t);
extern void func_021F0EA4(u8 *e, int a);
extern void func_021F0AC0(u8 *p);
extern void func_021F0B10(u8 *p, int a, void *b);
extern void func_021F06E0(u8 *p, u32 x, int y);
extern void func_02165AC4(int, int, void *, int);
extern int func_021659F0(int, int);
extern void func_021F13A0(u8 *p, int a, int b, u8 c, int s);

int func_021F02C4(u8 *p)
{
    int r;

    switch (*(int *)(p + 0x6C)) {
    case 0:
        if (*(int *)(*(u8 **)(p + 0x50) + 0x2C) != 0)
            break;
        (*(int *)(p + 0x6C))++;
        break;
    case 1:
        r = func_021F180C(p, *(int *)(p + 0x4C), *(int *)(p + 0x5C));
        if (*(int *)(p + 0x5C) == 0) {
            if (r != 0) {
                func_021F05E8(p, 4, 2);
                func_021F0DD8(0x549);
            }
            if (*(u8 **)(p + 0x50) != 0) {
                func_021F1144(p, *(u8 **)(p + 0x50), *(int *)(p + 0x4C), 0, r == 0, 0);
                func_021F0EA4(*(u8 **)(p + 0x50), 1);
            }
            return 1;
        }
        func_021F05E8(p, 4, 2);
        (*(int *)(p + 0x6C))++;
        break;
    case 2:
        func_021F0AC0(p);
        func_021F0B10(p, 1, p + 0xA8);
        func_021F06E0(p, *(int *)(p + 0x4C), p[0x57]);
        (*(int *)(p + 0x6C))++;
        break;
    case 3:
        if (p[0x7C] != 0) {
            p[0x54] = p[0x7C];
            func_02165AC4(*(int *)(p + 0x3C), *(int *)(p + 0x4C), p + 0x4A, p[0x54]);
            p[0x55] = func_021659F0(*(int *)(p + 0x3C), p[0x54]);
        }
        func_021F13A0(p, *(int *)(p + 0x4C), p[0x55], 1, (p[0x7C] != 0 ? 1 : 0) + 1);
        p[0x7C] = p[0x54];
        func_021F0DD8(0x64A);
        return 1;
    }
    return 0;
}
