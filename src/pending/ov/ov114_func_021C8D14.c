/*
 * function: func_021C8D14
 * address: 0x021C8D14
 * packet: pkt_ov114_021C8D14
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: DIFF
 * note 2026-10-05 (wave P17 L2): 140 bytes, 6 bytes differ. Callees match twins (func_021CA470 returns int, func_021C9EE4(int,char*)).
 *   Struct copy through a Pair *dst local (EXACT-adjacent) leaves one swap: the original loads the dst pool word (+0x10)
 *   between the two source loads (+0x14); ours loads it after both. Tried: Pair copy to cast array, local dst, Pair t temp,
 *   const src pointer, inline cp(), non-const source, u64 copy (ldm, 95 B), scalar copies (12 B), array-of-Pair dst (12 B),
 *   mode local first, pragmas scheduling/opt_lifetimes/opt_propagation/peephole/opt_common_subs off (all 6 B).
 *   Idioms: two-word-copy-between-different-bases, two-word-region-as-a-struct, pool-word-order-list-scheduler-tie,
 *   load-scheduled-above-unrelated-store-const-pointer, const-source-pointer-hoists-last-load, 12-byte-aggregate-pins-destination.
 * symbols:
 *   d_021D3D38 0x021D3D38 data a4
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021CF674 0x021CF674 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
/*
 * function: func_021C8D14
 * address: 0x021C8D14
 * packet: pkt_ov114_021C8D14
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3D38 0x021D3D38 data a4
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021CF674 0x021CF674 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */
typedef struct { unsigned a, b; } Pair;
extern const Pair d_021D3D38;
extern void *d_021D3D28;
extern unsigned d_021D3D2C[], d_021CF538[], d_021CF674[], d_021D3D40[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C8D14(void)
{
    Pair *dst = (Pair *)d_021D3D40;
    *dst = d_021D3D38;
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF674, d_021D3D2C[2], dst, 8, 0) == 0) {
        d_021D3D2C[0] = 18;
        return;
    }
    d_021D3D2C[0] = 24;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}
