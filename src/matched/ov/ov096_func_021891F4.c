/*
 * function: func_021891F4
 * address: 0x021891F4
 * packet: pkt_ov096_021891F4
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: u16 value/result locals plus result binding give the original cmp operand order.
 * Caller-visible return/second arguments override tail-forwarder declarations.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_0218A0F4 0x0218A0F4 thumb ov096
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x4c]; u16 values[8]; u8 pad2[0xb0-0x5c]; int fb0, fb4, fb8, fbc, fc0, fc4; } Obj;
extern unsigned int func_0201134C(int);
extern int func_0218A160(Obj *, int);
extern int func_0218A2FC(Obj *, int);
extern int func_0218A0F4(int, int, int, int, int);
extern int func_021D5B68(int);
extern int func_021D5448(int);
extern u16 func_021D54C0(int, u8);
int func_021891F4(int a, Obj *b, int c)
{
    u16 value, t;
    int k, z, r, i, s, y;
    k = func_0201134C(a);
    value = func_0201134C(a);
    z = func_0201134C(a);
    y = func_0218A160(b, k);
    r = 0;
    switch (k) {
    case 1:
        for (i = 0; i < func_021D5448(b->fbc); i++) {
            t = func_021D54C0(b->fbc, i);
            if (t == value) {
                r = 1;
                break;
            }
        }
        break;
    case 3:
        s = func_0218A2FC(b, func_0218A160(b, 3));
        if (func_021D5B68(s) == 0) {
            for (i = 0; i < func_021D5448(s); i++) {
                t = func_021D54C0(s, i);
                if (t == value) {
                    r = 1;
                    break;
                }
            }
        }
        break;
    case 0:
        for (i = 0; i < 4; i++) {
            if (b->values[y * 4 + i] == value) {
                r = 1;
                break;
            }
        }
        break;
    }
    return func_0218A0F4(a, c, r, 1, z);
}
