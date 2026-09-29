/*
 * function: func_0218AED4
 * address:  0x0218AED4
 * packet:   pkt_ov021_0218AED4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218AE48  0x0218AE48  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_0218AE04  0x0218AE04  thumb  ov021
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626EC  0x021626EC  thumb  ov010
 *   func_021626E8  0x021626E8  thumb  ov010
 *   func_0218ADC8  0x0218ADC8  thumb  ov021
 *   func_0218AD80  0x0218AD80  thumb  ov021
 */

typedef unsigned short u16;

typedef struct Vec { int x, y, z; } Vec;

extern void func_0218AE48(void *p, Vec *out);
extern void *func_02188C98(void *p);
extern int func_021AB0D4(void *a, Vec *b);
extern int func_021AB0F8(int a);
extern int func_0218AE04(void *p, Vec *v);
extern void *func_021625CC(void *a, u16 b);
extern int func_021626EC(void *p);
extern int func_021626E8(void *p);
extern void func_0218ADC8(void *p, int id, Vec *pos);
extern int func_0218AD80(void *p, void *a, int id, Vec *pos);

int func_0218AED4(char *p, int unused, void *a)
{
    Vec v;
    int id;
    void *o;

    func_0218AE48(p, &v);
    if ((func_021AB0F8(func_021AB0D4(func_02188C98(a), &v)) & 1) == 0)
        return 0;
    id = func_0218AE04(p, *(Vec **)(p + 0x34));
    if (id != 0xFFFF) {
        o = func_021625CC(*(void **)(p + 0xc), id);
        if (func_021626EC(o) == 0 && func_021626E8(o) == 1) {
            func_0218ADC8(p, id, *(Vec **)(p + 0x34));
            return func_0218AD80(p, a, id, *(Vec **)(p + 0x34));
        }
    }
    id = func_0218AE04(p, &v);
    if (id != 0xFFFF) {
        if (func_021626EC(func_021625CC(*(void **)(p + 0xc), id)) == 0) {
            func_0218ADC8(p, id, *(Vec **)(p + 0x34));
            return func_0218AD80(p, a, id, &v);
        }
    }
    return 0;
}
