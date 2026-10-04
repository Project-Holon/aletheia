/*
 * function: func_0216A634
 * address:  0x0216A634
 * packet:   pkt_ov010_0216A634
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_021D0BE4  0x021D0BE4  thumb  ov021
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_021D0BE4(int a, u8 *b, u16 *c);
extern void func_0215897C(void *vm, void *task);

int func_0216A634(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r4 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    func_0215897C(r7, func_021D0BE4((int)l0, (u8 *)*r4, func_02159AE8((void *)a0, (void *)a1)));
    return 1;
}
