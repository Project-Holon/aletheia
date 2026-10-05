/*
 * function: func_021B9580
 * address: 0x021B9580
 * packet: pkt_ov172_021B9580
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD4 lane03: EXACT. The 0xa4 store is written in each arm (= 2, = 2, = 0)
 *   instead of a local x stored once; tail merging then keeps the later x=2 copy and the first
 *   arm becomes the b stub, as in the listing.
 * symbols:
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021B7B3C 0x021B7B3C thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *   func_021B8B5C 0x021B8B5C thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021BE0B8 0x021BE0B8 thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021B77B4 0x021B77B4 thumb ov172
 *   func_021BE08C 0x021BE08C thumb ov172
 *   func_021B99F4 0x021B99F4 thumb ov172
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   d_021C6F83 0x021C6F83 data a1
 *   d_021C6F77 0x021C6F77 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u32 func_021BDFE4(void *);
extern u32 func_021BE054(void *);
extern u32 func_021B9DF8(void *, void *);
extern u32 func_021BE0B4(void *);
extern u32 func_021BDFDC(void *);
extern void func_021B7B3C(void *, u32, int);
extern u32 func_021BA270(u32);
extern u32 func_021B8B5C(void *, u32);
extern u8 func_021B8B68(void *, u32);
extern u32 func_021B8740(void *, u32, u8, u32);
extern u32 func_021B9F4C(void *, void *, int);
extern void func_021BE0B8(void *);
extern u32 func_021BE0A4(void *);
extern u32 func_021B77B4(void *, u32);
extern void func_021BE08C(void *);
extern void func_021B99F4(void *, void *);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020355D8(u32);
extern void func_020061E4(u32);
extern void func_0204B878(struct Obj *, u16);
extern void func_0204B92C(struct Obj *, u32);
extern const u8 d_021C6F83[];
extern const u8 d_021C6F77[];

void func_021B9580(u8 *c, u8 *q)
{
    u32 a = func_021BDFE4(c);
    u32 b = func_021BE054(c);
    int r6;

    if (func_021B9DF8(c, q) == 1)
        return;
    if (*(int *)q <= 8 && func_021BE0B4(c) == 0) {
        u32 s = func_021BDFDC(c);
        if (func_020362DC() & 0x40) func_021B7B3C(c, s, 0);
        if (func_020362DC() & 0x10) func_021B7B3C(c, s, 5);
        if (func_020362DC() & 0x80) func_021B7B3C(c, s, 1);
        if (func_020362DC() & 0x20) func_021B7B3C(c, s, 3);
    }
    if (b == 1 || func_021BA270(*(u32 *)(q + 0x10)) == 0) {
        *(int *)(q + 0xa4) = 2;
    } else {
        u32 t = func_021B8B5C(c, a);
        u32 u = func_021B8B68(c, a);
        if (u != 0xff) {
            if (u == t) {
                u32 k = q[0xc];
                if (k) {
                    k--;
                    q[0xc] = k;
                } else if (func_021B8740(c, a, 9, 0) == 1) {
                    q[0xc] = 8;
                }
            }
            *(int *)(q + 0xa4) = 2;
        } else {
            u32 r = func_021B9F4C(c, q, 0);
            if ((func_020362DC() & 0x101) || r == 1) {
                *(int *)q = 6;
                func_020061E4(0x66C);
                *(int *)(q + 0x34) = 1;
                q[0x38] = 0;
            }
            *(int *)(q + 0xa4) = 0;
        }
    }
    if (*(int *)q == 5) {
        if ((func_020362DC() & 0x400) || (func_020362DC() & 0x400) || func_02035C08(d_021C6F83) != -1) {
            *(int *)q = 3;
            *(int *)(q + 4) = 6;
            func_0204B878(*(struct Obj **)(q + 0x9c), 0x14);
            func_0204B92C(*(struct Obj **)(q + 0x9c), 1);
            func_020061E4(0x66C);
        }
    }
    if (*(int *)q == 5) {
        r6 = func_02035C08(d_021C6F77);
        if (r6 == 0 || (func_020362DC() & 2)) {
            if (r6 == 0) func_020355D8(1); else func_020355D8(0);
            *(int *)q = 9;
            func_020061E4(0x551);
            func_0204B878(*(struct Obj **)(q + 0x98), 9);
        } else if (r6 == 1 || (func_020362DC() & 0xc)) {
            func_021BE0B8(c);
            func_020061E4(0x66F);
            if (func_021BE0B4(c) == 1)
                func_0204B878(*(struct Obj **)(q + 0x94), 0x15);
            else
                func_0204B878(*(struct Obj **)(q + 0x94), 0x16);
        }
    }
    if (func_021BE0A4(c) == 0 && (func_020362DC() & 0x200)) {
        if (func_021B77B4(c, func_021BDFDC(c)) == 0) {
            func_021BE08C(c);
            func_020061E4(0x66C);
        }
    }
    func_021B99F4(c, q);
}
