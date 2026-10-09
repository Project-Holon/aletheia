/*
 * function: func_0272EA04
 * address:  0x0272EA04
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
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
