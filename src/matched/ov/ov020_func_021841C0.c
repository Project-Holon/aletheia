/*
 * function: func_021841C0
 * address:  0x021841C0
 * packet:   pkt_ov020_021841C0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two spellings are load-bearing.  The u8 range check on func_02026454's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * func_0216A358 call.  func_021882A0/02188318/021883CC are ov230's decrypted
 * code (ov230d token); each gets the range func_02183B60 to one of this
 * overlay's end markers.  Leaves filed for this function: ov010 0x02164454,
 * 0x0216445C, 0x02164464 and ov020 0x0218608C.
 *
 * symbols:
 *   ov230_id       0x000000E6  data
 *   func_02012138  0x02012138  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201447C  0x0201447C  thumb
 *   func_02014554  0x02014554  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02013D34  0x02013D34  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02183B60  0x02183B60  thumb  ov020
 *   func_0218604C  0x0218604C  thumb  ov020
 *   func_0218606C  0x0218606C  thumb  ov020
 *   func_0218608C  0x0218608C  thumb  ov020
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188318  0x02188318  arm  ov230d
 *   func_021883CC  0x021883CC  arm  ov230d
 *   func_02185B70  0x02185B70  thumb  ov020
 *   func_0202E8CC  0x0202E8CC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0216AAE4  0x0216AAE4  thumb  ov010
 *   func_0216A358  0x0216A358  thumb  ov010
 *   func_02185A68  0x02185A68  thumb  ov020
 *   func_021857C0  0x021857C0  thumb  ov020
 *   func_0202735C  0x0202735C  thumb
 *   func_02164454  0x02164454  thumb  ov010
 *   func_0216445C  0x0216445C  thumb  ov010
 *   func_02164464  0x02164464  thumb  ov010
 *   func_0215874C  0x0215874C  thumb  ov010
 *   func_020145FC  0x020145FC  thumb
 *   func_02029C64  0x02029C64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 ov230_id[];
extern int func_02012138(int a);
extern int func_02012B38(int a);
extern void func_0201447C(int a, int b);
extern int func_02014554(int a, int b);
extern void func_02012374(int a, int b);
extern void func_02034AC4(u8 *id);
extern void func_02034A5C(u8 *id);
extern int func_02013D34(int a);
extern int func_02026454(int a);
extern void func_02026400(int a);
extern void func_02183B60(void);
extern void func_0218604C(void);
extern void func_0218606C(void);
extern void func_0218608C(void);
extern u32 func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_02188318(void (*a)(void), void (*b)(void), u32 c);
extern u32 func_021883CC(void (*a)(void), void (*b)(void), u32 c);
extern void func_02185B70(int a);
extern void func_0202E8CC(int a, int b);
extern int func_02012EBC(int a);
extern int func_02008B14(int a);
extern int func_02012984(int a);
extern int func_02012934(int a);
extern void func_0216AAE4(int a, int b, int c);
extern void func_0216A358(int a, int b, int c, int d);
extern void func_02185A68(int a, int b);
extern void func_021857C0(int a, u8 *b);
extern void func_0202735C(int a, int b);
extern void func_02164454(int a, int b);
extern void func_0216445C(int a, int b);
extern void func_02164464(int a, int b);
extern void func_0215874C(int a);
extern int func_020145FC(int a);
extern int func_02029C64(int a);

int func_021841C0(int ctx, int *state, u8 **pp)
{
    u8 *p;
    int x;
    int y;
    int z;
    int w;
    int c;
    int b;
    int a;

    p = *pp;
    z = *(int *)(p + 8);
    x = *(int *)(p + 0);
    y = *(int *)(p + 4);
    w = func_02012138(x);

    switch (*state) {
    case 0:
        func_0201447C(func_02012B38(y), 2);
        func_02012374(ctx, func_02014554(x, z));
        (*state)++;
        break;
    case 1:
        func_02034AC4(ov230_id);
        if (func_02013D34(*(u16 *)(p + 0x14)) == 1 && (u8)(func_02026454(w) + 0xff) <= 1) {
            func_02026400(w);
            *state = 2;
        } else {
            *state = 3;
        }
        break;
    case 2:
        if (func_02026454(w) == 0) {
            *state = 3;
        }
        break;
    case 3:
        func_021882A0(func_02183B60, func_0218604C, 0);
        func_02185B70(x);
        if (*(int *)(p + 0x40) != 0 && *(int *)(p + 0x44) != 0) {
            func_0202E8CC(y, *(u16 *)(p + 0x4a));
            a = func_02008B14(func_02012EBC(y));
            b = func_02012984(y);
            c = func_02012934(y);
            func_0216AAE4(y, c, b);
            a += 0x14;
            func_0216A358(y, c, a, b);
        }
        func_02188318(func_02183B60, func_0218606C, 0);
        func_02185A68(x, *(u16 *)(p + 0x14));
        func_021857C0(x, p + 0x10);
        if (*(u8 *)(p + 0x30) != 4) {
            func_0202735C(*(u16 *)(p + 0x14), y);
        }
        func_021883CC(func_02183B60, func_0218608C, 0);
        switch (*(u8 *)(p + 0x30)) {
        case 1:
            func_02164454(y, *(u16 *)(p + 0x14));
            break;
        case 2:
            func_02164464(y, *(u16 *)(p + 0x14));
            break;
        case 3:
            func_0216445C(y, *(u16 *)(p + 0x14));
            break;
        }
        func_02034A5C(ov230_id);
        func_0215874C(w);
        (*state)++;
        break;
    case 4:
        func_02012374(ctx, func_020145FC(x));
        (*state)++;
        break;
    case 5:
        func_02012374(ctx, func_02029C64(x));
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}
