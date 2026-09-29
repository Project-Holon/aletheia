/*
 * function: func_0217C0A8
 * address:  0x0217C0A8
 * packet:   pkt_ov018_0217C0A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02026478();
extern int func_02012B70();
extern int func_02012B80();
extern int func_02012B58();
extern int func_02026454();
extern u8 *func_02026474();
extern int func_02013D5C();
extern void func_02012950();
extern void func_02012944();
extern void func_02008550();

void func_0217C0A8(int a0)
{
    int h;
    u8 *q;

    h = func_02026478(a0);
    if (func_02012B70(h) == 0) {
        func_02012944(h);
    } else if (func_02012B80(h) == func_02012B58(h)) {
        func_02012944(h);
    } else {
        q = 0;
        if (func_02026454(a0) == 2 && func_02026474(a0) != 0)
            q = func_02026474(a0);
        if (q == 0) {
            func_02012944(h);
        } else if (func_02013D5C(*(u16 *)(q + 0x84)) == 1) {
            func_02012944(h);
        } else {
            func_02012950(h, func_02012B80(h));
        }
    }
    func_02008550();
}
