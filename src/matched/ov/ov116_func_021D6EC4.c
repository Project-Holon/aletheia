/*
 * function: func_021D6EC4
 * address: 0x021D6EC4
 * packet: pkt_ov116_021D6EC4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D700E follow the epilogue.
 * evidence: ov114 labelled 97F4/99F0/99F4/9A14 bodies read the
 * declared pointer/index inputs; 99F4 reconstructs a full32-bit value.
 * Original keeps field loads and repeated per-call object reloads.
 * symbols:
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021D7250 0x021D7250 thumb ov116
 *   func_021B9774 0x021B9774 thumb ov114
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_021D7260 0x021D7260 thumb ov116
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_021B99F0 0x021B99F0 thumb ov114
 *   func_021B9A14 0x021B9A14 thumb ov114
 *   func_02082D44 0x02082D44 arm
 *   func_021B99F4 0x021B99F4 thumb ov114
 *   func_021D724C 0x021D724C thumb ov116
 *   func_021D7010 0x021D7010 thumb ov116
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern void func_021D7250(u8 *, u32);
extern void func_021B9774(u8 *);
extern void func_021B99B8(u8 *);
extern void func_021B9838(u8 *);
extern void func_02156DC4(int, int);
extern void func_021D7260(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 func_021B99F0(u8 *);
extern u8 *func_021B9A14(u8 *, int);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_021B99F4(u8 *, int);
extern void func_021D724C(u8 *, u32);
extern void func_021D7010(u8 *, int);
int func_021D6EC4(u8 *p, u8 *q, int flag)
{
    int result = 0;
    int code, status, all, i;
    u8 *x;
    code = func_021B99DC(*(u8 **)(p + 0x168));
    status = func_021B9790(*(u8 **)(p + 0x168));
    if (code != 200 && status == 0) {
        func_021D7250(q, code);
        func_021B9774(*(u8 **)(p + 0x168));
        func_021B99B8(*(u8 **)(p + 0x168));
        func_021B9838(*(u8 **)(p + 0x168));
        *(u8 **)(p + 0x168) = 0;
        func_02156DC4(0, 0);
        return 2;
    }
    if (status != 0) {
        func_021D7260(q);
    } else {
        x = func_021B97F4(*(u8 **)(p + 0x168));
        if (func_021B99F0(x) == 0) {
            all = 1;
            func_02082D44(func_021B9A14(x, *(u16 *)(p + 0x16c)), p + 0x16e, 128);
            for (i = 0; i < *(u16 *)(p + 0x16c); i++) {
                if (func_021B99F4(x, i) != 0) {
                    all = 0;
                    if (flag != 0) func_021D724C(q, 1);
                    else func_021D7010(p, i);
                }
            }
            if (all != 0) result = 1;
            else result = 2;
        } else {
            if (flag != 0) func_021D724C(q, 2);
            result = 2;
            for (i = 0; i < *(u16 *)(p + 0x16c); i++) {
                if (func_021B99F4(x, i) != 0) func_021D7010(p, i);
            }
        }
        func_021B99B8(*(u8 **)(p + 0x168));
        func_021B9838(*(u8 **)(p + 0x168));
        *(u8 **)(p + 0x168) = 0;
        func_02156DC4(0, 0);
    }
    return result;
}
