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
 */
typedef unsigned int u32;

struct SysState {
    char pad[0x508];
    int state;
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

void func_0272F740(void *ptr);
int func_0272E9E8(int a0, int a1, int a2, int a3);
u32 func_0272EA04(u32 a, u32 b, u32 c, u32 d);
asm void func_0272EA74(void);



int func_0272E9E8(int a0, int a1, int a2, int a3) {
    func_0272F740((void *)0x02732DC4);
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

asm void func_0272EA74(void)
{
}
