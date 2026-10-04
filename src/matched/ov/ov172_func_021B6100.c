/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov172_021B6100
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034F84 0x02034F84 arm
 *   func_02085D3C 0x02085D3C arm
 *   func_02088234 0x02088234 arm
 *   func_02084968 0x02084968 arm
 *   func_020351F8 0x020351F8 arm
 *   func_021B62A8 0x021B62A8 arm ov172
 *   func_021B62B0 0x021B62B0 arm ov172
 *   func_021B62B8 0x021B62B8 arm ov172
 *   func_021B62C0 0x021B62C0 arm ov172
 *   func_021B62C8 0x021B62C8 arm ov172
 *   func_021B62D0 0x021B62D0 arm ov172
 *   func_021B62D8 0x021B62D8 arm ov172
 *   func_021B62E0 0x021B62E0 arm ov172
 *   func_021B62E8 0x021B62E8 arm ov172
 *   func_021B62F0 0x021B62F0 arm ov172
 *   func_021B62F8 0x021B62F8 arm ov172
 *   func_021B6300 0x021B6300 arm ov172
 *   func_021B6308 0x021B6308 arm ov172
 *   func_021B6310 0x021B6310 arm ov172
 *   func_021B6318 0x021B6318 arm ov172
 *   func_021B6320 0x021B6320 arm ov172
 *   func_021B6328 0x021B6328 arm ov172
 *   func_021B6330 0x021B6330 arm ov172
 *   func_021B68A0 0x021B68A0 thumb ov172
 *   func_021B6338 0x021B6338 thumb ov172
 *   func_021B65D8 0x021B65D8 thumb ov172
 *   func_021B6620 0x021B6620 thumb ov172
 *   func_021B662C 0x021B662C thumb ov172
 *   d_021C71C0 0x021C71C0 data a4
 *   g_021C88E0 0x021C88E0 data a4
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034F84(int);
extern int func_02085D3C(void);
extern void func_02088234(void);
extern void func_02084968(int);
extern void func_020351F8(u32 a, u32 b);
extern int func_021B62A8(void);
extern int func_021B62B0(int);
extern void func_021B62B8(int, int, int);
extern void func_021B62C0(int, int);
extern void func_021B62C8(int, int);
extern int func_021B62D0(int);
extern void func_021B62D8(void *);
extern void func_021B62E0(void *);
extern void func_021B62E8(void *);
extern void func_021B62F0(int);
extern void func_021B62F8(int, int);
extern void func_021B6300(int, int);
extern void func_021B6308(int, int);
extern void func_021B6310(int, int);
extern void func_021B6318(int, int);
extern void func_021B6320(int, int);
extern void func_021B6328(void *);
extern int func_021B6330(void *, int, int);
extern void func_021B68A0(char *);
extern void func_021B6338(char *p);
extern void func_021B65D8(void);
extern void func_021B6620(int x);
extern void func_021B662C(void);
extern const char d_021C71C0[];
extern char *g_021C88E0;

char *func_021B6100(int id)
{
    char *p;
    int r;
    int z;
    char buf[0x48];

    z = 0;
    p = func_02030734(id, 0x50, 0, d_021C71C0, 0x6F);
    g_021C88E0 = p;
    *(unsigned short *)p = id;
    *(int *)(p + 4) = z;
    *(char *)(p + 0x18) = z;
    *(char *)(p + 8) = z;
    *(int *)(p + 0xC) = z;
    *(int *)(p + 0x10) = z;
    *(int *)(p + 0x14) = z;
    *(int *)(p + 0x2C) = 1;
    *(int *)(p + 0x30) = 5;
    *(int *)(p + 0x1C) = z;
    *(int *)(p + 0x20) = z;
    *(int *)(p + 0x24) = z;
    *(int *)(p + 0x3C) = z;
    *(int *)(p + 0x40) = z;
    func_02034F84(0x40);
    if (func_02085D3C() == 1) {
        r = func_021B62A8();
        if (r == 0) r = func_021B62B0(3);
    } else {
        r = 7;
    }
    if (r == 7) func_02088234();
    if (r == 6) return 0;
    r = *(int *)(p + 0x2C);
    if (func_02085D3C() == 1) func_021B62B8(r, 3, 0);
    r = *(int *)(p + 0x2C);
    if (func_02085D3C() == 1) func_021B62C0(r, 1);
    r = *(int *)(p + 0x2C);
    if (func_02085D3C() == 1) func_021B62C8(r, 1);
    r = *(int *)(p + 0x2C);
    if (func_02085D3C() == 1) r = func_021B62D0(r);
    else r = 7;
    if (r == 7) func_02088234();
    if (r == 6) return 0;
    *(int *)(p + 0x28) = 0;
    func_02084968(0x20000000);
    if (func_02085D3C() == 1) func_021B62D8((void *)func_021B662C);
    if (func_02085D3C() == 1) func_021B62E0((void *)func_021B65D8);
    if (func_02085D3C() == 1) func_021B62E8((void *)func_021B6620);
    func_021B68A0(p);
    if (func_02085D3C() == 1) func_021B62F0(1);
    *(int *)(p + 0x48) = 0;
    *(char *)(p + 0x44) = 0;
    func_021B62F8(1, 0);
    func_021B6300(1, 0);
    func_021B6308(1, 1);
    func_021B6310(2, 0);
    func_021B6318(2, 0);
    func_021B6320(2, 1);
    if (func_02085D3C() != 0) func_021B6328(buf);
    if (func_02085D3C() != 0) r = func_021B6330(buf, 0xFF, 0xFF);
    else r = 0;
    if (r == 0) func_02088234();
    func_020351F8((u32)((void *)func_021B6338), (u32)p);
    return p;
}
