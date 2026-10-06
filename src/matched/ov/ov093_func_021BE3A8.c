/*
 * function: func_021BE3A8
 * address:  0x021BE3A8
 * packet:   pkt_ov093_021BE3A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C0450  0x021C0450  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_0201BEB8(u16 id, u32 bit);
extern int func_021EF948(int k);
extern void func_021C0450(u8 *p, u8 *q, u16 c, int k);

int func_021BE3A8(u8 *p, u8 *a, u16 *s)
{
    u16 t = *s;
    int k = 0;
    if (func_021D62C4((struct Unk021D62A8 *)a, 0xF) && func_0201BEB8(t, 0xC)) {
        k = 0xD;
    } else if (func_021EF948(2) && func_0201BEB8(t, 9)) {
        k = 0x14;
    }
    if (k) {
        func_021C0450(p, a, t, k);
        return 1;
    }
    return 0;
}
