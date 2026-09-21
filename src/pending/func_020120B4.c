/*
 * function: func_020120B4
 * address:  0x020120B4
 * packet:   pkt_020120B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     status corrected 2026-09-21 from EXACT to DIFF by re-verification (12 concrete bytes out)
 *
 * symbols:
 *   func_02031348  0x02031348  arm
 */

typedef struct Struct_020120B4 {
    char pad[8];
    void *f8;
} Struct_020120B4;

extern void func_02031348(void *p);

void func_020120B4(Struct_020120B4 *obj)
{
    func_02031348(obj->f8);
}
