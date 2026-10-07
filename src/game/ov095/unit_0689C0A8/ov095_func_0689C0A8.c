/*
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
 *   func_0689C104 0x0689C104 thumb ov095
 *   func_0689C0D4 0x0689C0D4 thumb ov095
 *   func_0689C0E4 0x0689C0E4 thumb ov095
 *   func_0689C0F4 0x0689C0F4 thumb ov095
 */
#include "../../../matched/include/Obj21902.h"
typedef unsigned char u8;
extern void func_0689C104(void *, void *, u8);
extern int func_0689C0D4(void *);
extern void *func_0689C0E4(void *, int, int);
extern void func_0689C0F4(void *, void *);
void func_0689C0A8(void *a, void *b)
{
    int key;
    void *record;
    func_0689C104(a, b, 0);
    key = func_0689C0D4(b);
    record = func_0689C0E4(a, 0x13, key);
    ((struct Obj21902 *)((unsigned int)record))->f4 = key;
    func_0689C0F4(a, record);
}
