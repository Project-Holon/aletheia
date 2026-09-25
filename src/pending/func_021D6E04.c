/*
 * function: func_021D6E04
 * address:  0x021D6E04
 * packet:   pkt_021D6E04
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * MATCH: byte-correct (104 bytes). All five calls target ARM9 library
 * helpers func_02015EB0/func_02015C48/func_02015E04/func_02015C94/
 * func_02015CAC (0x02015EB0..) that have no witness outside this range.
 * Note the codegen lever: caching the base pointer in a local costs a
 * callee-saved register and diverges; the indexed field must be reloaded
 * inline at every use.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef int s32;

extern void func_02015EB0(u32);
extern void func_02015C48(u32, u32 *);
extern void func_02015E04(u32);
extern void func_02015C94(u32, u32 *);
extern void func_02015CAC(u32, u32 *);

void func_021D6E04(void *p, int idx)
{
    u32 vec[3];
    func_02015EB0(((u32 *)((char *)p + 0x844))[idx]);
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    func_02015C48(((u32 *)((char *)p + 0x844))[idx], vec);
    func_02015E04(((u32 *)((char *)p + 0x844))[idx]);
    func_02015C94(((u32 *)((char *)p + 0x844))[idx], vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    func_02015CAC(((u32 *)((char *)p + 0x844))[idx], vec);
}
