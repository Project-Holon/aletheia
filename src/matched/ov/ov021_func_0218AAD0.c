/*
 * function: func_0218AAD0
 * address:  0x0218AAD0
 * packet:   pkt_ov021_0218AAD0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Adds func_02010FF4(0x100) to the step accumulator in the save block; once
 * it passes 0x10000 it advances the party's egg counters (func_0218AA74) and
 * resets it.
 *
 * symbols:
 *   func_02008970  0x02008970  thumb
 *   func_0200896C  0x0200896C  thumb
 *   func_0218AA74  0x0218AA74  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct Sub02008828Obj;
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern void func_02008970(const struct Sub02008828Obj *obj, u32 *out);
extern void func_0200896C(struct Sub02008828Obj *obj, u32 value);
extern u32 func_02010FF4(u32 v);
extern void func_0218AA74(void *party);

void func_0218AAD0(void *sys, void *party)
{
    void *save = func_02008854(func_02012EBC(sys));
    u32 steps;

    func_02008970(save, &steps);
    steps += func_02010FF4(0x100);
    if (steps > 0x10000) {
        func_0218AA74(party);
        steps = 0;
    }
    func_0200896C(save, steps);
}
