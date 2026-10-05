/*
 * function: func_0215B5BC
 * address:  0x0215B5BC
 * packet:   pkt_ov010_0215B5BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern u16 *func_02159AE8(void *, void *);
extern u32 func_02159B10(void *, void *);
extern int func_0215B4AC(void *, u32, void **);
extern u32 func_02017E1C(void *, u32, u32);
#pragma opt_lifetimes off
#pragma opt_propagation off
int func_0215B5BC(void *a0, void *a1)
{
    u16 *out = (u16 *)func_02159AE8(a0, a1);
    int idx = func_02159B10(a0, a1);
    int z = 0;
    u16 sum = 0;
    void *obj;
    if (func_0215B4AC(a1, idx, &obj) == 1) {
        sum = z + (u16)func_02017E1C(obj, 0xD, z);
        sum = sum + (u16)func_02017E1C(obj, 0xE, z);
        sum = sum + (u16)func_02017E1C(obj, 0xF, z);
        sum = sum + (u16)func_02017E1C(obj, 0x10, z);
        sum = sum + (u16)func_02017E1C(obj, 0x11, z);
        sum = sum + (u16)func_02017E1C(obj, 0x12, z);
    }
    *out = sum;
    return 0;
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
