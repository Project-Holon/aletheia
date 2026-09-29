/*
 * function: func_021B8280
 * address:  0x021B8280
 * packet:   pkt_ov070_021B8280
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B61B8  0x021B61B8  thumb  ov070
 *   func_021B616C  0x021B616C  thumb  ov070
 *   func_02020F34  0x02020F34  thumb
 *   func_021B822C  0x021B822C  thumb  ov070
 *   func_021B8F68  0x021B8F68  thumb  ov070
 *   func_02021014  0x02021014  thumb
 *   func_020213E0  0x020213E0  thumb
 *   func_021B83A0  0x021B83A0  thumb  ov070
 *   func_020307B0  0x020307B0  arm
 */

extern int func_021B61B8();
extern unsigned short *func_021B616C();
extern int func_02020F34();
extern void func_021B822C();
extern int func_021B8F68();
extern int func_02021014();
extern int func_020213E0();
extern int func_021B83A0();
extern void func_020307B0();

void func_021B8280(int p, unsigned char *q)
{
    unsigned short *e = func_021B616C(p, func_021B61B8(p));
    if (e != 0 && *e != 0) {
        int h = func_02020F34(*e, 0, *(unsigned short *)((char *)p + 0x544));
        unsigned char v = *(int *)((char *)p + 0x80C);
        func_021B822C(p, h, e, q);
        if (func_021B8F68(p, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (func_020213E0(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (func_021B83A0(p, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}
