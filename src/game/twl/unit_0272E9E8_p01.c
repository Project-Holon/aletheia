/*
 * file:     unit_0272E9E8_p01.c
 * unit:     yes
 * function: func_0272E9E8, func_0272EA04, func_0272EA74
 * address:  0x0272E9E8
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_02732DC4 0x02732DC4 data twl
 *   func_0272F740 0x0272F740 arm twl
 *   func_020862F0 0x020862F0 arm
 *   func_02077008 0x02077008 arm
 *   func_0272EE2C 0x0272EE2C arm twl
 *   data_02150200 0x02150200 data
 *   data_02732DA8 0x02732DA8 data twl
 *   func_02086580 0x02086580 arm
 *   func_0208656C 0x0208656C arm
 *   func_02086774 0x02086774 arm
 *   func_02075E04 0x02075E04 arm
 *   func_0272EBDC 0x0272EBDC arm twl
 *   func_02088234 0x02088234 arm
 *   func_02087B04 0x02087B04 arm
 *   func_02084EB8 0x02084EB8 arm
 *   func_02075E10 0x02075E10 arm
 *   func_02075E80 0x02075E80 arm
 *   func_02084F10 0x02084F10 arm
 *   func_02076E4C 0x02076E4C arm
 *   func_0272F0BC 0x0272F0BC arm twl
 *   data_02732DA0 0x02732DA0 data twl
 *   data_02732DA4 0x02732DA4 data twl
 *   data_02150840 0x02150840 data
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct SysState {
    char pad[0x508];
    int state;
};
struct Hook {
    int f0;
    void *callback;
};

struct Request {
    int f0;
    void (*callback)(void *);
    u32 a;
    u32 c;
    u32 b;
    u32 d;
    int f18;
};

extern struct SysState data_02150200;
extern struct Request data_02732DA8;
extern void func_020862F0(u32, u32);
extern void func_02077008(struct Request *);
extern void func_0272EE2C(void *);
extern struct Hook data_02150840;
extern u32 data_02732DA0, data_02732DA4;
extern u8 data_02732DC4[];
extern u32 func_02086580(int arena);
extern u32 func_0208656C(int arena);
extern void func_02086774(int arena, u32 addr);
extern void *func_02075E04(void);
extern u32 func_0272EBDC(void *hdr);
extern void func_02088234(void);
extern int func_02087B04(void);
extern int func_02084EB8(void);
extern void func_02075E10(u16 id);
extern void func_02075E80(u16 id);
extern void func_02084F10(u16 id);
extern int func_02076E4C(void *, void *, u32, u32);
extern void func_0272F0BC(void *, void *, u32, u32, void *, void *, void *);

void func_0272F740(void *obj, u8 *buf, u32 off, u32 len);
int func_0272E9E8(int a0, int a1, int a2, int a3);
u32 func_0272EA04(u32 a, u32 b, u32 c, u32 d);
void func_0272EA74(void);



int func_0272E9E8(int a0, int a1, int a2, int a3) {
    func_0272F740(data_02732DC4, (u8 *)a1, a2, a3);
    return a3;
}


u32 func_0272EA04(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02150200.state == -1) {
        d = 0;
    } else {
        func_020862F0(b, d);
        data_02732DA8.callback = func_0272EE2C;
        data_02732DA8.a = a;
        data_02732DA8.c = c;
        data_02732DA8.b = b;
        data_02732DA8.d = d;
        data_02732DA8.f0 = 0;
        data_02732DA8.f18 = 0;
        func_02077008(&data_02732DA8);
    }
    return d;
}

void func_0272EA74(void)
{
    u32 lo = (func_02086580(0) + 0x1f) & ~0x1f;
    u32 hi = func_0208656C(0);
    u32 size;
    u16 lock;

    size = func_0272EBDC(func_02075E04());
    if (lo + size > (hi & ~0x1f)) {
        func_02088234();
        return;
    }
    func_02086774(0, lo + size);
    data_02732DA0 = lo;
    data_02732DA4 = size;
    if (func_02087B04() != 1) {
        return;
    }
    if (!(*(u8 *)0x02FFE01C & 1)) {
        return;
    }
    data_02150200.state = -1;
    data_02150840.callback = func_0272E9E8;
    lock = func_02084EB8();
    func_02075E10(lock);
    func_0272F0BC(data_02732DC4, func_02075E04(), data_02732DA0, data_02732DA4, func_02076E4C, func_0272EA04, data_02732DC4);
    data_02732DA0 = 0;
    data_02732DA4 = 0;
    func_02075E80(lock);
    func_02084F10(lock);
}
