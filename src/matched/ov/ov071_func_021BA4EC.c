/*
 * function: func_021BA4EC
 * address: 0x021BA4EC
 * packet: pkt_ov071_021BA4EC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 */
extern unsigned func_02045EC0(unsigned,unsigned);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_0201C6FC(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_02045808(unsigned);
void func_021BA4EC(char *p, char *q) {
    unsigned s, h;
    s = func_02045EC0(*(unsigned *)(p + 40),38);
    h = *(unsigned *)(p + 8);
    func_0201C6FC(h,(unsigned)func_02045770((struct Descriptor *)*(unsigned *)(q + 12)),0,4,s,*(unsigned *)(p + 12));
    q[16] = 1;
    func_02045808(s);
}
