/*
 * function: func_021F42A0
 * address: 0x021F42A0
 * packet: pkt_ov194_021F42A0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02045808 0x02045808 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_0204ADA4(int);
extern void func_02045808(void *);
extern void func_0202570C(void *);
extern void func_020437AC(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(int);
extern void func_0204B3B4(void *);
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
void func_021F42A0(unsigned char *p) {
    if (*(void **)(p+0x2c)) {
        func_0204ADA4(*(int *)(p+0x24));
        func_02045808(*(void **)(p+0x28));
        func_0202570C(*(void **)(p+0x2c));
        func_020437AC(*(void **)(p+0x30));
    }
    func_0204ADA4(*(int *)(p+8));
    func_0204A8D4(*(void **)(p+12));
    func_0204AFD8(*(int *)(p+16));
    func_0204B3B4(*(void **)p);
    func_02082BCC(p,0,0x3c);
}
