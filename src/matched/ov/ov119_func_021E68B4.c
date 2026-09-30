/*
 * function: func_021E68B4
 * address: 0x021E68B4
 * packet: pkt_ov119_021E68B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: unsigned cast on the store index prevents address CSE with the signed read index; without it 56 bytes, 37 byte DIFF.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
extern void func_0204B3B4(int);
static inline void clear(int p, int i) {
    if (*(int *)(p+i*4+0x10ac)) {
        func_0204B3B4(*(int *)(p+i*4+0x10ac));
        *(int *)(p+(unsigned int)i*4+0x10ac)=0;
    }
}
void func_021E68B4(int p, int n) {
    int i=n*2;
    clear(p,i+1);
    clear(p,i);
}
