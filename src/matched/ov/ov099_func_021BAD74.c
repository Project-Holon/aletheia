/*
 * function: func_021BAD74
 * address: 0x021BAD74
 * packet: pkt_ov099_021BAD74
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C37A0 0x021C37A0 data a4
 *   d_021C3730 0x021C3730 data a4
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C27E0 0x021C27E0 thumb ov099
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 * prototype-evidence: C23B8 forwards the visibly supplied index to ov009
 *   56860, whose full body returns the address consumed here; BDD48's
 *   result is explicitly narrowed to u16 here, so its extern is wide.
 *   F878/20CF8 retain visibly supplied unused trailing heap arguments.
 * layout-evidence: the template copy is 13 words; count/rows occupy +10/+12.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b; } Pair;
typedef struct {
    u32 w0, w4, w8, wc;
    u16 count, rows;
    u32 w14, w18, w1c, w20, w24, w28, w2c, w30;
} Desc;
struct W;
struct S;
struct Slot;
struct PrintSys;
struct Obj;
struct Cfg;
extern Desc d_021C37A0;
extern const Pair d_021C3730[];
extern u8 func_021B97F4(struct W *);
extern struct S *func_021C23B8(int);
extern u32 func_021BDD48(int, struct S *);
extern int func_021C27E0(struct S *);
extern struct Slot *func_0201F81C(u32, u32);
extern void func_0201F878(struct Slot *, u32, u32, u32, u32);
extern u32 func_020450F0(u32, u32, u8, u32, u8, u8, u8);
extern void func_0201F73C(void *, int, u16, int);
extern struct Obj *func_0201FF30(Desc *, u16, u16, u32);
extern u32 func_0201C6B4(const struct PrintSys *);
extern u32 func_0201C4E4(struct PrintSys *);
extern void func_02020CF8(struct Obj *, u32);
extern void func_02045374(struct Cfg *);
extern void func_02041B6C(u32);
void func_021BAD74(char *p)
{
    int n;
    Desc desc;
    struct S *state;
    u16 kind;
    u32 i;
    n = 2;
    desc = d_021C37A0;
    state = func_021C23B8(func_021B97F4((struct W *)(p + 0x274)) - 1);
    kind = (u16)func_021BDD48((int)p, state);
    func_021C27E0(state);
    func_021C27E0(*(struct S **)(p + 8));
    *(struct Slot **)(p + 0xb8) = func_0201F81C(2, 33);
    for (i = 0; i < 2; i++) {
        if (i == 0 && kind != 2 && kind != 5 && kind != 1) {
            desc.rows--;
            desc.count--;
            n--;
        } else {
            func_0201F878(*(struct Slot **)(p + 0xb8), *(u32 *)(p + 0xe0), d_021C3730[i].a, d_021C3730[i].b, 33);
        }
    }
    *(u32 *)(p + 0x1a4) = func_020450F0(2, 16, (3 - n) * 2 + 11, 15, n * 2, 15, 1);
    func_0201F73C(*(void **)(p + 0x1a4), 2, *(u32 *)(p + 0x1334), 14);
    desc.w0 = *(u32 *)(p + 0xb8);
    desc.wc = *(u32 *)(p + 0x1a4);
    desc.w2c = *(u32 *)(p + 0x1b4);
    desc.w28 = (u32)(p + 0x1ac);
    desc.w30 = *(u32 *)(p + 0xe8);
    *(struct Obj **)(p + 0xbc) = func_0201FF30(&desc, 0, 0, 33);
    if (func_0201C6B4(*(struct PrintSys **)(p + 0x1b4)) == 0) {
        do {
            func_0201C4E4(*(struct PrintSys **)(p + 0x1b4));
        } while (func_0201C6B4(*(struct PrintSys **)(p + 0x1b4)) == 0);
    }
    func_02020CF8(*(struct Obj **)(p + 0xbc), 33);
    func_02045374(*(struct Cfg **)(p + 0x1a4));
    func_02041B6C(2);
}
