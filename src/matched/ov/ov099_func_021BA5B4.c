/*
 * function: func_021BA5B4
 * address: 0x021BA5B4
 * packet: pkt_ov099_021BA5B4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021BA594 0x021BA594 thumb ov099
 */
typedef unsigned char u8;
extern int func_021C49A4(u8 *, unsigned int);
extern void func_021BA594(char *p, int a, int b, int c);
void func_021BA5B4(void *a, int b, u8 **p) {
    int c = func_021C49A4(*p, 6);
    int d = func_021C49A4(*p, 4);
    func_021BA594(a,b,c,d);
}
