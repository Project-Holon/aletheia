/*
 * function: func_021D6F0C
 * address:  0x021D6F0C
 * packet:   pkt_021D6F0C
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021D6ECC  0x021D6ECC  thumb  ov118
 *
 * MATCH: byte-correct (32 bytes), same shape as func_021D6EAC; the two ARM9
 * storage setters func_02051A2C/func_02051A24 have no witness outside this
 * range.
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02051774(void *);
extern void func_02051A2C(void *, unsigned int);
extern void func_02051A24(void *, void (*)(void));
extern void func_021D6ECC(void);

void func_021D6F0C(void *p)
{
    func_02051A2C(p, func_02051774(p));
    func_02051A24(p, func_021D6ECC);
}
