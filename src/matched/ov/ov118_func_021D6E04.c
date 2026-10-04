/*
 * function: func_021D6E04
 * address:  0x021D6E04
 * packet:   pkt_ov118_021D6E04
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015EB0  0x02015EB0  thumb
 *   func_02015C48  0x02015C48  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015C94  0x02015C94  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *
 * The five ARM9 helpers it marshals through are unlabelled Thumb leaves;
 * they were promoted to src/matched (pkt_02015Exx) and now witness this
 * file's calls. Codegen lever: caching the base pointer in a local costs a
 * callee-saved register and diverges; the indexed field must be reloaded
 * inline at every use.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef int s32;

extern void func_02015EB0(void *p);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015E04(void *p);
extern void func_02015C94(void *p, u32 *out);
extern void func_02015CAC(void *p, u32 *src);

void func_021D6E04(void *p, int idx)
{
    u32 vec[3];
    func_02015EB0((void *)(((u32 *)((char *)p + 0x844))[idx]));
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    func_02015C48((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    func_02015E04((void *)(((u32 *)((char *)p + 0x844))[idx]));
    func_02015C94((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    func_02015CAC((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
}
