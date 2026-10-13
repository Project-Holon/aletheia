/*
 * file:     unit_0689C0A8.c
 * function: func_0689C0A8
 * address: 0x0689C0A8
 * packet: pkt_ov095_0689C0A8
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0689C0D2.
 * Calls fixed bx-pc veneers 0689C0D4 -> 021D5440,
 * 0689C0E4 -> 021C88A4, 0689C0F4 -> 021C88C8.
 * symbols:
 *   func_021C88A4  0x021C88A4  thumb
 *   func_021C88C8  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   func_0689C104 0x0689C104 thumb ov095
 */
#include "../../matched/include/Obj21902.h"
typedef unsigned char u8;
extern void func_0689C104(void *, void *, u8);
extern int BTL_POKEPARAM_GetPokeId(void *);
extern void *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
void func_0689C0A8(void *a, void *b)
{
    int key;
    void *record;
    func_0689C104(a, b, 0);
    key = BTL_POKEPARAM_GetPokeId(b);
    record = func_021C88A4(a, 0x13, key);
    ((struct Obj21902 *)((unsigned int)record))->f4 = key;
    func_021C88C8(a, record);
}
