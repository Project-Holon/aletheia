/*
 * function: func_0272EA74
 * address:  0x0272EA74
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02732DA0 0x02732DA0 data twl
 *   data_02732DA4 0x02732DA4 data twl
 *   data_02732DC4 0x02732DC4 data twl
 *   data_02150200 0x02150200 data
 *   data_02150840 0x02150840 data
 *   func_02086580 0x02086580 arm
 *   func_0208656C 0x0208656C arm
 *   func_02075E04 0x02075E04 arm
 *   func_0272EBDC 0x0272EBDC arm twl
 *   func_02088234 0x02088234 arm
 *   func_02086774 0x02086774 arm
 *   func_02087B04 0x02087B04 arm
 *   func_02084EB8 0x02084EB8 arm
 *   func_02075E10 0x02075E10 arm
 *   func_02075E80 0x02075E80 arm
 *   func_02084F10 0x02084F10 arm
 *   func_0272F0BC 0x0272F0BC arm twl
 *   func_02076E4C 0x02076E4C arm
 *   func_0272EA04 0x0272EA04 arm twl
 *   func_0272E9E8 0x0272E9E8 arm twl
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

extern struct SysState data_02150200;
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
extern u32 func_0272EA04(u32, u32, u32, u32);
extern int func_0272E9E8(int, int, int, int);
extern void func_0272F0BC(void *, void *, u32, u32, void *, void *, void *);

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
