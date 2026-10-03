/*
 * function: func_021C0D90
 * address: 0x021C0D90
 * packet: pkt_ov093_021C0D90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C0EC4 0x021C0EC4 thumb ov093
 *   func_021C0ED4 0x021C0ED4 thumb ov093
 *   func_021C0EE4 0x021C0EE4 thumb ov093
 *   func_021C0EF4 0x021C0EF4 thumb ov093
 *   func_021C0A4C 0x021C0A4C thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021C0F04 0x021C0F04 thumb ov093
 *   func_021C11A4 0x021C11A4 thumb ov093
 *   func_021BEC08 0x021BEC08 thumb ov093
 *   func_021BA1B4 0x021BA1B4 thumb ov093
 *   func_021C0F14 0x021C0F14 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Flags { u32 a:1; u32 b:1; } Flags;
extern u32 func_021C0EC4(u8 *);
extern u32 func_021C0ED4(u8 *);
extern void func_021C0EE4(u8 *, u8 *, u8 *);
extern void func_021C0EF4(u8 *, u8 *, u8 *);
extern void func_021C0A4C(u8 *, u8 *, u8 *, u8 *, u32, u32, u8 *);
extern u32 func_021CD4FC(u8 *, u32);
extern u32 func_021C0F04(u8 *);
extern u32 func_021C11A4(u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u32, Flags);
extern int func_021BEC08(u8 *p, u8 *a);
extern void func_021BA1B4(u8 *, int);
extern u32 func_021C0F14(u8 *);
u32 func_021C0D90(u8 *p, u8 *q, u8 *a, u8 *b, u32 c, u32 *out, u32 d)
{
    u32 k;
    u32 result;
    Flags f;
    if (func_021C0EC4(b) == 1) k = 0x1000;
    else k = 0xc00;
    result = 0;
    f.a = func_021C0ED4(b) > 1;
    f.b = d;
    func_021C0EE4(b, a, *(u8 **)(p + 0x858));
    func_021C0EF4(b, a, *(u8 **)(p + 0x85c));
    func_021C0A4C(p, a, *(u8 **)(p + 0x858), q, c, k, *(u8 **)(p + 0x86c));
    func_021C0A4C(p, a, *(u8 **)(p + 0x85c), q, c, k, *(u8 **)(p + 0x870));
    *out = func_021CD4FC(*(u8 **)(p + 0xc), 0x30);
    if (func_021C0F04(*(u8 **)(p + 0x858)) != 0) {
        result += func_021C11A4(p, q, a, *(u8 **)(p + 0x858), *(u8 **)(p + 0x86c), *(u8 **)(p + 0x4b4), k, f);
        if (result != 0 && func_021BEC08(p, a) != 0)
            func_021BA1B4(*(u8 **)(p + 4), 0x4d);
    }
    if (func_021C0F14(*(u8 **)(p + 0x85c)) != 0)
        result += func_021C11A4(p, q, a, *(u8 **)(p + 0x85c), *(u8 **)(p + 0x870), *(u8 **)(p + 0x4b4), k, f);
    return result;
}
