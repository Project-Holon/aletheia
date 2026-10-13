/*
 * function: func_06898B6C
 * address: 0x06898B6C
 * packet: pkt_ov095_06898B6C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * The returned message pointer stays live in r1 for 06898BDC, whose veneer
 * reaches the two-argument BTL_SERVER_FLOW_CommitCmdRecord. A one-argument declaration loses
 * the pointer copy and leaves 18 differing bytes (62/64).
 * symbols:
 *   func_06898BAC 0x06898BAC thumb ov095
 *   func_06898BBC 0x06898BBC thumb ov095
 *   func_06898BCC 0x06898BCC thumb ov095
 *   func_06898BDC 0x06898BDC thumb ov095
 *   func_06898BEC 0x06898BEC thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_06898BAC(int k);
extern int func_06898BBC(int b, int c);
extern u8 *func_06898BCC(int b, int k, int n);
extern void func_06898BDC(int b, void *p);
extern void func_06898BEC(int a);
void func_06898B6C(int a, int b, int c, u32 *d)
{
    u8 t = func_06898BAC(2);
    u8 *p;
    if (t == func_06898BBC(b, c)) {
        p = func_06898BCC(b, 0x2a, 0x1f);
        p[4] = *d;
        p[5] = t;
        func_06898BDC(b, p);
        func_06898BEC(a);
    }
}
