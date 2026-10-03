/*
 * function: func_02187C20
 * address:  0x02187C20
 * packet:   pkt_ov020_02187C20
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02187860  0x02187860  thumb  ov020
 *   func_0202E8A4  0x0202E8A4  thumb
 *   func_0218794C  0x0218794C  thumb  ov020
 *   func_02040588  0x02040588  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0207D658  0x0207D658  arm
 *   func_02187D40  0x02187D40  thumb  ov020
 *   func_02187D74  0x02187D74  thumb  ov020
 *   func_02187D54  0x02187D54  thumb  ov020
 *   func_02187D20  0x02187D20  thumb  ov020
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   func_02187D94  0x02187D94  thumb  ov020
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
void func_02187860(char *p);
u8 func_0202E8A4(s32 x);
void func_0218794C(int a, int b);
void func_02040588(u32 which, u32 enable);
void func_0207D534(int a, int b);
void func_0207D658(u32 addr, int plane, int brightness);
int func_02187D40(char *p);
int func_02187D74(char *p);
int func_02187D54(char *p);
u32 func_02187D20(char *p);
void func_02188DB0(int x);
void func_02187D94(void *o);

void func_02187C20(char *o, int *p, int st)
{
    switch (st) {
    case 0:
        func_02187860(o);
        break;
    case 1:
        *(u8 *)(o + 0x15) = func_0202E8A4(*(u8 *)(o + 0x15));
        func_0218794C(*(u8 *)(o + 0x15), *(u16 *)(o + 8));
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534(0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        *(int *)(o + 0x1c) = func_02187D40(o);
        break;
    case 3:
        *(int *)(o + 0x1c) = func_02187D74(o);
        break;
    case 4:
        *(int *)(o + 0x1c) = func_02187D54(o);
        if (func_02187D20(o) == 0 && *(u8 *)(o + 0x15) == *(u8 *)(o + 0x14)) {
            func_02188DB0(*(int *)(o + 4));
            func_02040588(3, 1);
            func_02187D94(o);
        }
        break;
    case 5:
        break;
    }
    *p = st;
    *(int *)(o + 0x18) = 0;
}
