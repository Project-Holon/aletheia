/*
 * function: func_021D9C00
 * address: 0x021D9C00
 * packet: pkt_ov119_021D9C00
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_02039CB4 0x02039CB4 arm
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D9AD8 0x021D9AD8 thumb ov119
 *   func_021D9BC4 0x021D9BC4 thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_020399A8(void);
extern u32 func_0203D1A4(void *);
extern int func_021D8A24(void *p);
extern int func_02039CB4(void *h, int a, int b);
extern void func_021DD24C(void *p);
extern void func_021DD294(void *p, int a, int b);
extern void func_021D8E84(void *p, int next);
extern void func_02045CAC(int a, int b, int c);
extern void func_021E1024(void *p);
extern void func_021E1030(void *p);
extern void func_021D9AD8(void *p);
extern void func_021D9BC4(void *p);
extern void func_021DAEF0(void *p);

void func_021D9C00(char *p)
{
    int cmd;
    u32 other;
    u32 me;
    u32 a;

    me = func_0203D1A4(func_020399A8());
    other = 1 - me;
    if (func_021D8A24(p) == 0) {
        me = 0;
        other = 1;
    }
    if (func_021D8A24(p) != 0 && func_02039CB4(func_020399A8(), 0x1a, 8) == 0) {
        func_021DD24C(p);
        return;
    }
    func_021DD294(p, 1, 1);
    a = ((u8 *)p + me)[0x11e0];
    if (a == 1 && ((u8 *)p + other)[0x11e0] == 1) {
        func_021D8E84(p, (int)func_021D9AD8);
        return;
    }
    if (a == 4 && ((u8 *)p + other)[0x11e0] == 4) {
        *(int *)(*(char **)(p + 8) + 8) = 3;
        func_02045CAC(*(int *)(p + 0x720), 0x8d, *(int *)(p + 0x738));
        func_021E1024(p);
        func_021E1030(p);
        *(int *)(p + 0xf2c) = 0;
        func_021D8E84(p, (int)func_021D9BC4);
        return;
    }
    if (((u8 *)p + other)[0x11e0] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    func_02045CAC(*(int *)(p + 0x720), cmd, *(int *)(p + 0x738));
    func_021E1024(p);
    p[0x11e0] = 0;
    p[0x11e1] = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}
