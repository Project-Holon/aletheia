/*
 * function: func_021587E0
 * address: 0x021587E0
 * packet: pkt_ov010_021587E0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Extent ends in two alignment padding bytes.
 * symbols:
 *   func_021589DC 0x021589DC thumb ov010
 *   func_02158894 0x02158894 thumb ov010
 */
extern void *func_021589DC(int);
extern int func_02158894(void *, int);
int func_021587E0(int a, int b) {
    void *p = func_021589DC(a);
    if (!p) return 0;
    if (func_02158894(p, b)) return 1;
    return 0;
}
