/*
 * function: func_021D6F0C
 * address:  0x021D6F0C
 * packet:   pkt_021D6F0C
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6ECC  0x021D6ECC  thumb  ov118
 *
 * Addresses are Black-image addresses.
 *
 * Promoted from MATCH by the recursive-unblocker lane: the ARM9 storage
 * setters func_02051A2C/func_02051A24 now have EXACT arm9 shard entries
 * (pkt_02051A2C / pkt_02051A24), so both calls resolve via `matched`.
 * Verified EXACT, 32 bytes.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void func_02051A2C(void *p, int v);
extern void func_02051A24(void *p, int v);
extern void func_021D6ECC(void *obj, int on);

void func_021D6F0C(void *p)
{
    func_02051A2C(p, func_02051774());
    func_02051A24(p, (int)func_021D6ECC);
}
