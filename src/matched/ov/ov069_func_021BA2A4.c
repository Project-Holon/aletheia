/*
 * function: func_021BA2A4
 * address: 0x021BA2A4
 * packet: pkt_ov069_021BA2A4
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021BA2D8 0x021BA2D8 thumb ov069
 *   d_021BA5FC 0x021BA5FC data a4
 */
extern int func_02035C08(const void *key);
extern unsigned func_020362DC(void);
extern void func_020061E4(int v);
extern void func_021BA2D8(char *o, int k);
extern const char d_021BA5FC[];
int func_021BA2A4(char *p)
{
    int k;
    k = func_02035C08(d_021BA5FC);
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        k = 2;
    }
    func_021BA2D8(p, k);
    return k;
}
