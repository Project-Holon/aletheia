/*
 * function: func_021D6EAC
 * address:  0x021D6EAC
 * packet:   pkt_021D6EAC
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021D6E6C  0x021D6E6C  thumb  ov118
 *
 * MATCH: byte-correct (32 bytes). The two ARM9 storage setters
 * func_02051A2C/func_02051A24 (0x02051A2C / 0x02051A24, str r1,[r0,#0x94] /
 * str r1,[r0,#0x90]) are ARM9 game functions with no witness outside this
 * range; they belong to the ARM9 lane.
 *
 * Addresses are Black-image addresses.
 */

extern unsigned int func_02051774(void *);
extern void func_02051A2C(void *, unsigned int);
extern void func_02051A24(void *, void (*)(void));
extern void func_021D6E6C(void);

void func_021D6EAC(void *p)
{
    func_02051A2C(p, func_02051774(p));
    func_02051A24(p, func_021D6E6C);
}
