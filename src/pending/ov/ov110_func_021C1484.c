/*
 * function: func_021C1484
 * address: 0x021C1484
 * packet: pkt_ov110_021C1484
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * Blocked on ARM9 0x02024910 (no outside witness); two-byte zero padding follows.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *func_02024910(u8 *p,int i) { return p+8+i*8; }
 * symbols:
 *   func_021C0B4C 0x021C0B4C thumb ov110
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02024910 0x02024910 thumb
 */
typedef unsigned char u8;
extern void func_021C0B4C(void *);
extern int func_020279E8(void *);
extern int func_02027A04(void *);
extern unsigned func_02024910(void *, u8);
int func_021C1484(void *arg, u8 *p) {
    func_021C0B4C(*(void **)(p+0x68));
    if (func_020279E8(*(void **)(p+0x68))) {
        switch (func_02027A04(*(void **)(p+0x68))) {
        case 0:
            *(int *)(p+0xa0)=5;
            *(unsigned *)(*(u8 **)p+8)=func_02024910(*(void **)(p+0x20),p[0x95]);
            *(unsigned *)(*(u8 **)p+4)=0;
            break;
        case 1: *(int *)(p+0xa0)=11; break;
        case 2: *(int *)(p+0xa0)=4; break;
        }
        return 1;
    }
    return 0;
}
