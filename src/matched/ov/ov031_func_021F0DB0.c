/*
 * function: func_021F0DB0
 * address:  0x021F0DB0
 * packet:   pkt_ov031_021F0DB0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0DB0  0x021F0DB0  thumb
 *   func_02035D20  0x02035D20  arm
 *   func_021F0F68  0x021F0F68  thumb  ov031
 *   func_021F0ED8  0x021F0ED8  thumb  ov031
 *   func_021BBC2C  0x021BBC2C  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_021F0F40  0x021F0F40  thumb  ov031
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    char pad[0x43C];
    int a;
    int n;
} B;

extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021F0F68(void *, int, int);
extern void func_021F0ED8(void *, B *, int);
extern u8 *func_021BBC2C(B *, int);
extern void func_02082D44(void *dst, void *src, int n);
extern void func_021F0F40(void *, B *, int);
extern void func_020061E4(u32 a);

int func_021F0DB0(char *a0, void *a1, B *a2)
{
    u32 x;
    u32 y;
    int i;
    int t;
    u8 *e;

    if (func_02035D20(&x, &y) == 0)
        return 0;
    if (x <= 0xE8) {
        for (i = 0; i < 3; i++) {
            if (y >= (u32)(i * 0x38) && y <= (u32)(i * 0x38 + 0x38))
                break;
        }
    }
    if (i >= 3 || i > a2->a)
        return 0;
    if (func_021F0F68(a1, i, 1) == 1) {
        t = i;
        i = a2->n;
        if (i >= 3)
            i = i - 2 + t;
        else
            i = t;
        func_021F0ED8(a1, a2, i);
        e = func_021BBC2C(a2, i);
        if (e != 0)
            func_02082D44(e + 0x1A, a0 + 0x28A4, 6);
        func_021F0F40(a1, a2, i);
        func_020061E4(0x54C);
        return 1;
    }
    return 0;
}
