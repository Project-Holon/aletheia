/*
 * function: func_021C15B4
 * address: 0x021C15B4
 * packet: pkt_ov110_021C15B4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * Blocked on ARM9 leaves 0x02024120 and 0x02024134; zero padding follows.
 * blocker: 0x02024120 Thumb, EXACT (block24120.log)
 *   typedef unsigned char u8;
 *   u8 func_02024120(u8 *p) { return p[2]; }
 * blocker: 0x02024134 Thumb, EXACT (block24134.log)
 *   symbols: func_02024570 0x02024570 thumb
 *   typedef unsigned char u8;
 *   extern void func_02024570(void *,const void *);
 *   void func_02024134(u8 *p,void *out) { func_02024570(out,p+16); }
 * symbols:
 *   func_02024120 0x02024120 thumb
 *   func_02024134 0x02024134 thumb
 *   func_02024918 0x02024918 thumb
 *   func_020240FC 0x020240FC thumb
 */
typedef unsigned char u8;
extern int func_02024120(void *);
extern void func_02024134(void *, void *);
extern void func_02024918(void *, u8, void *);
extern void func_020240FC(void *);
int func_021C15B4(int *state, u8 *p) {
    unsigned pair[2];
    switch (*state) {
    case 0:
        if (func_02024120(*(void **)(p+0x90))) {
            func_02024134(*(void **)(p+0x90),pair);
            func_02024918(*(void **)(p+0x20),p[0x95],pair);
        }
        func_020240FC(*(void **)(p+0x90));
        ++*state;
        break;
    case 1: return 1;
    }
    return 0;
}
