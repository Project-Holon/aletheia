/*
 * function: func_021C1484
 * address: 0x021C1484
 * packet: pkt_ov110_021C1484
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Blocked on ARM9 0x02024910 (no outside witness); two-byte zero padding follows.
 * blocker: 0x02024910 Thumb, EXACT (block24910.log)
 *   typedef unsigned char u8;
 *   void *PMS_WORD_GetSaveEntry(u8 *p,int i) { return p+8+i*8; }
 * symbols:
 *   func_021C0B4C 0x021C0B4C thumb ov110
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   PMS_WORD_GetSaveEntry 0x02024910 thumb
 */
typedef unsigned char u8;
extern void func_021C0B4C(void *);
typedef unsigned int   u32;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void *PMS_WORD_GetSaveEntry(char *p, int idx);
int func_021C1484(void *arg, u8 *p) {
    func_021C0B4C(*(void **)(p+0x68));
    if (func_020279E8(*(void **)(p+0x68))) {
        switch (func_02027A04(*(void **)(p+0x68))) {
        case 0:
            *(int *)(p+0xa0)=5;
            *(unsigned *)(*(u8 **)p+8)=(unsigned int)PMS_WORD_GetSaveEntry(*(void **)(p+0x20),p[0x95]);
            *(unsigned *)(*(u8 **)p+4)=0;
            break;
        case 1: *(int *)(p+0xa0)=11; break;
        case 2: *(int *)(p+0xa0)=4; break;
        }
        return 1;
    }
    return 0;
}
