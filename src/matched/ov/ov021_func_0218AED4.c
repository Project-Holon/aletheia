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
#include "../include/Obj00705.h"

typedef unsigned short u16;

typedef struct Vec { int x, y, z; } Vec;

struct Obj;
extern void func_0218AE48(struct Obj *p, struct Vec *out);
extern unsigned int func_02188C98(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F8(u32 attr);
extern u32 func_0218AE04(u8 *p, void *arg);
extern void *func_021625CC(char *p, unsigned i);
extern int func_021626EC(u16 *p);
extern u8 func_021626E8(u8 *p);
extern void func_0218ADC8(u8 *p, int id, u32 *pos);
extern int func_0218AD80(void *p, void *a, int id, Vec *pos);

int func_0218AED4(char *p, int unused, void *a)
{
    Vec v;
    int id;
    void *o;

    func_0218AE48((struct Obj *)p, &v);
    if ((func_021AB0F8(func_021AB0D4((void *)func_02188C98(a), &v)) & 1) == 0)
        return 0;
    id = (int)func_0218AE04((u8 *)p, *(Vec * *)&((struct Obj00705 *)p)->f34);
    if (id != 0xFFFF) {
        o = func_021625CC(((struct Obj00705 *)p)->fC, (u16)id);
        if (func_021626EC(o) == 0 && func_021626E8(o) == 1) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80(p, a, id, *(Vec * *)&((struct Obj00705 *)p)->f34);
        }
    }
    id = (int)func_0218AE04((u8 *)p, &v);
    if (id != 0xFFFF) {
        if (func_021626EC(func_021625CC(((struct Obj00705 *)p)->fC, (u16)id)) == 0) {
            func_0218ADC8((u8 *)p, id, (u32 *)(*(Vec * *)&((struct Obj00705 *)p)->f34));
            return func_0218AD80(p, a, id, &v);
        }
    }
    return 0;
}
