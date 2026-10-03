/*
 * function: func_0215CA64
 * address:  0x0215CA64
 * packet:   pkt_ov010_0215CA64
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: reads two words and stores func_02161B90's result
 * (over the system and the script's cell) in the script's slot.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *vm);
extern void *func_0215A5DC(void *vm);
extern u32 func_02159B10(void *c, void *vm);
extern void *func_02158F50(void *p);
extern void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
extern void func_0215897C(void *p, void *v);

int func_0215CA64(void *c, void *vm)
{
    void *slot;
    void *sys;
    u32 a;
    u32 b;

    slot = func_0215A5F4(vm);
    sys = func_0215A5DC(vm);
    a = func_02159B10(c, vm);
    b = func_02159B10(c, vm);
    func_0215897C(slot, func_02161B90(sys, func_02158F50(slot), a, b, 0));
    return 1;
}
