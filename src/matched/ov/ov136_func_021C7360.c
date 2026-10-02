/*
 * function: func_021C7360
 * address: 0x021C7360
 * packet: pkt_ov136_021C7360
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02024450 has no witness outside this caller.
 *   2026-10-02: src/matched/arm9/func_02024450.c exists (EXACT) but has no shard yet.
 *   After the integrator runs manifest on it, re-run: expect EXACT.
 *   Verified Thumb C is preserved here; ARM9 filing belongs to Ilias.
 *   typedef unsigned short u16;
 *   int func_02024450(const u16 *p)
 *   {
 *       if (*p != 0xFFFF) return 1;
 *       return 0;
 *   }
 * symbols:
 *   func_02008FC8 0x02008FC8 thumb
 *   func_02024450 0x02024450 thumb
 *   func_020414EC 0x020414EC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02008FC8(void *, u8);
extern int func_02024450(void *);
extern void func_0202DC9C(void *, u8, int);
extern void func_020414EC(u32);
void func_021C7360(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (func_02024450(func_02008FC8(*(void **)(*(u8 **)(p + 8) + p[0x1F]*4 + 0x298), i)) != 0) {
            func_0202DC9C(*(void **)(*(u8 **)(p + 8) + 0x35C), i, 0);
        }
    }
    if (*(u16 *)(*(u8 **)(p + 8) + 0x364) != 0) {
        func_0202DC9C(*(void **)(*(u8 **)(p + 8) + 0x35C), i, 0);
    }
    func_020414EC(4);
    func_020414EC(5);
}
