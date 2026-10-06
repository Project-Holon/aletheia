/*
 * function: func_021C1D60
 * address:  0x021C1D60
 * packet:   pkt_ov093_021C1D60
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021D5FC0  0x021D5FC0  thumb  ov093
 *   func_021C76F4  0x021C76F4  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C7780  0x021C7780  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct UtilWork;
extern int func_021D5BB0(struct UtilWork *p, u32 n);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern int func_021C76F4(u8 *p, u8 *q, u32 n);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C7780(u8 *p, u8 *q);
extern void func_021CC95C(u32 *p, u32 v, int line);

int func_021C1D60(u8 *p, u8 *q, u32 n)
{
    if (func_021D5BB0((struct UtilWork *)q, 5)) {
        func_021D5FC0((struct UtilWork *)q, 6);
        return 1;
    }
    if (func_021C76F4(p, q, n)) {
        func_021D5FC0((struct UtilWork *)q, 4);
        return 1;
    }
    if (n >= 100) {
        u32 s = func_021CC8D8(p + 0x1D74, 7085);
        func_021C7780(p, q);
        func_021CC95C((u32 *)(p + 0x1D74), s, 7087);
    }
    return 0;
}
