/*
 * function: func_021740D4
 * address: 0x021740D4
 * packet: pkt_ov012_021740D4
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent follower 0217410C is this lane's corrected-entry file, kept separate.
 * func_021840A4 receives both original loaded arguments despite its empty body.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02034714 0x02034714 arm
 *   func_021840A4 0x021840A4 thumb ov022
 *   d_02175624 0x02175624 data a1
 */
typedef unsigned char u8;
extern int func_020399A8(void);
extern int func_0203D1A4(int);
extern void func_02034714(void *, int, void *);
extern void func_021840A4(int, u8);
extern u8 d_02175624[];
void func_021740D4(int a, int x, u8 *b, u8 *p)
{
    if (a != func_0203D1A4(func_020399A8())) {
        if (*(int *)(p + 0x3528) == 0) {
            func_02034714(d_02175624, 0, d_02175624);
            return;
        }
        func_021840A4(*(int *)(p + 0x3528), *b);
    }
}
