/*
 * function: func_021D9670
 * address: 0x021D9670
 * packet: pkt_ov119_021D9670
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D94D4 0x021D94D4 thumb ov119
 *   func_021D95D0 0x021D95D0 thumb ov119
 *   func_021D95F0 0x021D95F0 thumb ov119
 *   func_021D9610 0x021D9610 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021DA798 0x021DA798 thumb ov119
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern int func_021D94D4(void *p);
extern int func_021D95D0(void *p);
extern int func_021D95F0(void *p);
extern int func_021D9610(void *p);
extern int func_021E12AC(void *p);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_02039C68(void *h, u32 a, u32 b);
extern void func_021DA798(void *p);

void func_021D9670(char *p)
{
    u8 b[5];
    int r;
    int kind = func_021D8A24(p);

    if (func_021E12AC(p) == 0)
        return;
    if (kind != 0) {
        if (func_021D94D4(p)) {
            b[4] = 5;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, &b[4]);
        } else if (func_021D95D0(p)) {
            b[3] = 7;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, &b[3]);
        } else if (func_021D95F0(p)) {
            b[2] = 8;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, &b[2]);
        } else if (func_021D9610(p)) {
            b[1] = 6;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, &b[1]);
        } else {
            b[0] = 2;
            r = func_0203D3A8(func_020399A8(), 0xc00, 1, &b[0]);
        }
        if (r == 0)
            return;
        func_02039C68(func_020399A8(), 0x1b, 8);
        func_021D8E84(p, (int)func_021DA798);
        return;
    }
    p[0x11e0] = 2;
    p[0x11e1] = 2;
    func_021D8E84(p, (int)func_021DA798);
}
