/*
 * function: func_021CFC4C
 * address:  0x021CFC4C
 * packet:   pkt_ov021_021CFC4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009470  0x02009470  thumb
 *   func_0200E878  0x0200E878  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_021CFC80  0x021CFC80  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
struct Sub02009470Obj;
extern int func_02012F38(int base);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern int func_0200E878(u8 *p);
extern int func_021CFC80(u32 a, u8 *b, int c, void *d);

int func_021CFC4C(void *a, int b, void *c)
{
    void *sys = func_020120F4(a);
    u8 *sv = (u8 *)func_02012F38((int)sys);

    if (b < 0xe9) {
        return func_021CFC80((u32)func_02009470(func_02012EBC(sys)), sv, b, c);
    }
    return func_0200E878(sv);
}
