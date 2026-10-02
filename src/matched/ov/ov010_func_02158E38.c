/*
 * function: func_02158E38
 * address: 0x02158E38
 * packet: pkt_ov010_02158E38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * ARM9 interface evidence: 02011324 reads +0x20; 02011328 stores r1/r2 at +0x24/+0x28.
 * symbols:
 *   func_02011324 0x02011324 thumb
 *   func_02011328 0x02011328 thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02158DE8 0x02158DE8 thumb ov010
 */
extern void *func_02011324(void *);
extern void *func_0215A5DC(void *);
extern int func_02158DE8(int, void *, void *, int);
extern void func_02011328(void *, int (*)(int, void *, void *, int), void *);
void func_02158E38(void *a) {
    void *b = func_0215A5DC(func_02011324(a));
    func_02011328(a, func_02158DE8, b);
}
