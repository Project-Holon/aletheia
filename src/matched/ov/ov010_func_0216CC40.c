/*
 * function: func_0216CC40
 * address: 0x0216CC40
 * packet: pkt_ov010_0216CC40
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 */
extern void *func_020120F4(const void *);
extern void *func_02012EC4(void *);
extern int *func_0200B3A4(void *, int);
void func_0216CC40(void *a) {
    *func_0200B3A4(func_02012EC4(func_020120F4(a)),0x34)=1;
}
