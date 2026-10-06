/*
 * function: func_021BFE60
 * address:  0x021BFE60
 * packet:   pkt_ov093_021BFE60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C5620  0x021C5620  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021D5C08  0x021D5C08  thumb  ov093
 *   func_021C6110  0x021C6110  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
struct UtilWork;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
struct Slot;
extern void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern u32 func_021D5C08(struct UtilWork *p);
extern void func_021C6110(u8 *p, u8 *a, unsigned int n);

void func_021BFE60(u8 *p, u8 *a)
{
    int k = 0x1a;
    u32 r;
    if (func_021D62C4((struct Unk021D62A8 *)a, k) != 0) {
        func_021C5620(p, a, k, 0);
        func_021D5FC0((struct UtilWork *)a, 0xb);
    }
    r = func_021D5C08((struct UtilWork *)a);
    while (r != 0x10) {
        func_021C6110(p, a, r);
        r = func_021D5C08((struct UtilWork *)a);
    }
}
