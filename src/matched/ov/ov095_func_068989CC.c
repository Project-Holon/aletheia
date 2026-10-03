/*
 * function: func_068989CC
 * address: 0x068989CC
 * packet: pkt_ov095_068989CC
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Message pointer y is passed live in r1 to 06898B40, whose fixed veneer
 * targets two-argument func_021C88C8. Omitting y lost its r0-to-r1 copy.
 * symbols:
 *   func_06898A80 0x06898A80 thumb ov095
 *   func_06898A90 0x06898A90 thumb ov095
 *   func_06898AA0 0x06898AA0 thumb ov095
 *   func_06898AB0 0x06898AB0 thumb ov095
 *   func_06898AC0 0x06898AC0 thumb ov095
 *   func_06898AD0 0x06898AD0 thumb ov095
 *   func_06898AE0 0x06898AE0 thumb ov095
 *   func_06898AF0 0x06898AF0 thumb ov095
 *   func_06898B00 0x06898B00 thumb ov095
 *   func_06898B10 0x06898B10 thumb ov095
 *   func_06898B20 0x06898B20 thumb ov095
 *   func_06898B30 0x06898B30 thumb ov095
 *   func_06898B40 0x06898B40 thumb ov095
 *   func_06898B50 0x06898B50 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int w0; u32 w1; u8 pad[0x10]; u32 w6; } D;
extern int func_06898A80(int k);
extern int func_06898A90(int b);
extern int func_06898AA0(int b);
extern int func_06898AB0(int b, int c);
extern int func_06898AC0(int b, int s);
extern int func_06898AD0(int x);
extern u8 *func_06898AE0(int b, int n, int k);
extern void func_06898AF0(void *p, int n, int v);
extern void func_06898B00(void *p, int k);
extern void func_06898B10(void *p, u32 v);
extern void func_06898B20(int b, void *p);
extern u8 *func_06898B30(int b, int n, int k);
extern void func_06898B40(int b, void *p);
extern void func_06898B50(int a);
void func_068989CC(int a, int b, int c, D *d)
{
    if (func_06898A80(2) == 0x1f && func_06898A90(b) == 0) {
        u8 t = func_06898AA0(b);
        if (t >= d->w0) {
            int s = func_06898AB0(b, c);
            u8 k = d->w6;
            if (s != 0x1f && s != k) {
                if (func_06898AD0(func_06898AC0(b, s)) == 0) {
                    u8 *x = func_06898AE0(b, 4, k);
                    u8 *y;
                    func_06898AF0(x + 4, 2, 0x438);
                    func_06898B00(x + 4, s);
                    func_06898B10(x + 4, d->w1);
                    func_06898B20(b, x);
                    y = func_06898B30(b, 0x27, k);
                    y[4] = k;
                    y[5] = s;
                    *(u16 *)(y + 6) = d->w1;
                    func_06898B40(b, y);
                }
            }
            func_06898B50(a);
        }
    }
}
