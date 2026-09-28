/*
 * function: func_0200A848
 * address:  0x0200A848
 * packet:   pkt_0200A848
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  02161EEC is the unlabelled ov010 leaf now
 *           matched in src/matched/func_02161EEC.c (shard ov010/pkt_02161EEC),
 *           which attests the call as `matched, overlay` under the ov010
 *           hint below; 02161F00 resolves as sole-ref/code (overlay).
 * symbols:
 *   func_02161D98    0x02161D98  thumb  ov010
 *   func_02161EEC    0x02161EEC  thumb  ov010
 *   func_02161F00    0x02161F00  thumb  ov010
 */

typedef unsigned int u32;

extern void func_02161D98(void *p);
extern void func_02161EEC(void *p);
extern void func_02161F00(void *p);

void func_0200A848(void **a0)
{
    func_02161D98(a0);
    func_02161EEC(&a0[0x7a]);
    func_02161F00(&a0[0x7f]);
}
