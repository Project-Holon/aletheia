/*
 * function: func_0217B5DC
 * address: 0x0217B5DC
 * packet: pkt_ov018_0217B5DC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0217B600 0x0217B600 thumb ov018
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_020122C0(void *, u32, void (*)(), u32);
extern u8 *func_020124E8(void *);
extern void func_0217B600();
extern void func_02082BCC(void *, int, int);
extern int func_021A3074(int);
void *func_0217B5DC(void *a) {
    void *t;
    u8 *p;
    t = func_020122C0(a, 0, func_0217B600, 0x2c);
    p = func_020124E8(t);
    func_02082BCC(p, 0, 0x2c);
    return t;
}
