/*
 * function: func_021B9580
 * address:  0x021B9580
 * packet:   pkt_ov172_021B9580
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Per-frame input handler for the screen: key presses select entries, confirm/cancel switch state.
 *
 * Note: func_021B8B5C is matched as void(void) but returns the result of its last call;
 * the prototype here uses that return.
 *
 * 2026-10-02 (C1-03): logic, callees and pool constants are right; everything from the
 * 0x21B96DE block on matches instruction for instruction. Open: block layout of the
 * `v = 2` store at the start of the 0x21B9610 branch. The original has `bne 961c; b 9654`
 * and shares ONE `movs r1,#2; b 968a` block at the tail of the t != 0xFF arm (the outer else
 * jumps there); ours emits the v = 2 block directly after the BA270 test. Tried: else-arm
 * v = 2 (best, 58 bytes differ), up-front v = 2, flag variable, goto ladders (worse).
 * `func_020355D8(r6 == 0)` only matches as a call in each arm (the select form if-converts).
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_02035C08  0x02035C08  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B77B4  0x021B77B4  thumb  ov172
 *   func_021B7B3C  0x021B7B3C  thumb  ov172
 *   func_021B8740  0x021B8740  thumb  ov172
 *   func_021B8B5C  0x021B8B5C  thumb  ov172
 *   func_021B8B68  0x021B8B68  thumb  ov172
 *   func_021B99F4  0x021B99F4  thumb  ov172
 *   func_021B9DF8  0x021B9DF8  thumb  ov172
 *   func_021B9F4C  0x021B9F4C  thumb  ov172
 *   func_021BA270  0x021BA270  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BE08C  0x021BE08C  thumb  ov172
 *   func_021BE0A4  0x021BE0A4  thumb  ov172
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_021BE0B8  0x021BE0B8  thumb  ov172
 *   d_021C6F77     0x021C6F77  data
 *   d_021C6F83     0x021C6F83  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020362DC(void);
extern int func_02035C08(void *rects);
extern void func_020355D8(int v);
extern void func_020061E4(int se);
extern void func_0204B878(int, int);
extern void func_0204B92C(int, int);
extern u32 func_021B77B4(int unused, void *p);
extern void func_021B7B3C(int x, int y, int z);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern u32 func_021B8B5C(int a, u32 b);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021B99F4(void *unused, u8 *q);
extern int func_021B9DF8(void *p, int *out);
extern int func_021B9F4C(int a, int b, int mode);
extern int func_021BA270(void *p);
extern u32 func_021BDFDC(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021BE054(void *p);
extern void func_021BE08C(void *p);
extern u8 func_021BE0A4(void *p);
extern u32 func_021BE0B4(void *p);
extern void func_021BE0B8(void *p);
extern u8 d_021C6F77[];
extern u8 d_021C6F83[];

void func_021B9580(int self, char *q)
{
    u32 a = func_021BDFE4((void *)self);
    u32 stk = func_021BE054((void *)self);
    u32 r6;
    u32 v;

    if (func_021B9DF8((void *)self, (int *)q) == 1)
        goto done;
    if (*(int *)q <= 8 && func_021BE0B4((void *)self) == 0) {
        r6 = func_021BDFDC((void *)self);
        if (func_020362DC() & 0x40)
            func_021B7B3C(self, r6, 0);
        if (func_020362DC() & 0x10)
            func_021B7B3C(self, r6, 5);
        if (func_020362DC() & 0x80)
            func_021B7B3C(self, r6, 1);
        if (func_020362DC() & 0x20)
            func_021B7B3C(self, r6, 3);
    }
    if (stk == 1 || func_021BA270(*(void **)(q + 0x10)) == 0) {
        v = 2;
    } else {
        u32 s = func_021B8B5C(self, a);
        u32 t = func_021B8B68(self, (char *)a);
        if (t != 0xFF) {
            if (t == s) {
                u32 c = *(u8 *)(q + 0xC);
                if (c != 0) {
                    *(u8 *)(q + 0xC) = c - 1;
                } else if (func_021B8740(self, a, 9, 0) == 1) {
                    *(u8 *)(q + 0xC) = 8;
                }
            }
            v = 2;
        } else {
            r6 = func_021B9F4C(self, (int)q, 0);
            if ((func_020362DC() & 0x101) || r6 == 1) {
                *(int *)q = 6;
                func_020061E4(0x66C);
                *(int *)(q + 0x34) = 1;
                *(u8 *)(q + 0x38) = 0;
            }
            v = 0;
        }
    }
    *(u32 *)(q + 0xA4) = v;
    if (*(int *)q == 5) {
        if ((func_020362DC() & 0x400) || (func_020362DC() & 0x400) || func_02035C08(d_021C6F83) != -1) {
            *(int *)q = 3;
            *(int *)(q + 4) = 6;
            func_0204B878(*(int *)(q + 0x9C), 0x14);
            func_0204B92C(*(int *)(q + 0x9C), 1);
            func_020061E4(0x66C);
        }
    }
    if (*(int *)q == 5) {
        r6 = func_02035C08(d_021C6F77);
        if (r6 == 0 || (func_020362DC() & 2)) {
            if (r6 == 0)
                func_020355D8(1);
            else
                func_020355D8(0);
            *(int *)q = 9;
            func_020061E4(0x551);
            func_0204B878(*(int *)(q + 0x98), 9);
        } else if (r6 == 1 || (func_020362DC() & 0xC)) {
            func_021BE0B8((void *)self);
            func_020061E4(0x66F);
            if (func_021BE0B4((void *)self) == 1)
                func_0204B878(*(int *)(q + 0x94), 0x15);
            else
                func_0204B878(*(int *)(q + 0x94), 0x16);
        }
    }
    if (func_021BE0A4((void *)self) == 0 && (func_020362DC() & 0x200) && func_021B77B4(self, (void *)func_021BDFDC((void *)self)) == 0) {
        func_021BE08C((void *)self);
        func_020061E4(0x66C);
    }
    func_021B99F4((void *)self, (u8 *)q);
done:
    return;
}
