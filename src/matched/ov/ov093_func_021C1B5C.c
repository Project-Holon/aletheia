/*
 * function: func_021C1B5C
 * address: 0x021C1B5C
 * packet: pkt_ov093_021C1B5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1C48 0x021C1C48 thumb ov093
 *   func_021C1C58 0x021C1C58 thumb ov093
 *   func_021C1C68 0x021C1C68 thumb ov093
 *   func_021C1C78 0x021C1C78 thumb ov093
 *   func_021D74F8 0x021D74F8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D75EC 0x021D75EC thumb ov093
 *   func_021D7630 0x021D7630 thumb ov093
 *   func_021D70F0 0x021D70F0 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7540 0x021D7540 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021C1C48(u8 *);
extern u8 *func_021C1C58(u8 *, u32);
extern int func_021C1C68(u8 *, u8 *, u32 *);
extern int func_021C1C78(u8 *, u8 *, u32 *);
extern void func_021D74F8(int);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int, u32);
extern void func_021D7630(int, u32);
extern void func_021D70F0(u8 *, int);
extern int func_021D775C(int);
extern void func_021D7540(int);
void func_021C1B5C(u8 *p, u8 *a, u8 *b, u8 *c, u32 d, u8 e, int f)
{
    u32 sum;
    u32 n;
    u32 got;
    u32 i;
    u32 v;
    u8 *x;
    int ok;
    n = func_021C1C48(b);
    sum = 0;
    got = 0;
    func_021D74F8(0x1b2b);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(0x4d, d);
    func_021D75EC(0x12, *(u16 *)c);
    func_021D75EC(0x16, c[6]);
    for (i = 0; i < n; i++) {
        x = func_021C1C58(b, i);
        if (e) ok = func_021C1C68(b, x, &v);
        else ok = func_021C1C78(b, x, &v);
        if (ok) {
            sum += v;
            func_021D75EC(got + 6, func_021D5440(x));
            got++;
        }
    }
    if (got) {
        func_021D75EC(5, got);
        func_021D7630(0x47, 0);
        func_021D7630(0x48, 0);
        func_021D75EC(0x32, sum);
        func_021D70F0(p, 0x82);
        if (!func_021D775C(0x48)) func_021D70F0(p, f);
    }
    func_021D7540(0x1b52);
}
