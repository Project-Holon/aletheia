/*
 * function: CARDi_ReadCardWithHashInternalAsync
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
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_02077008 0x02077008 arm
 *   CARD_NotifyRomHashReadAsync 0x0272EE2C arm twl
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
extern void DWCi_ScreenDC_FlushRange(u32, u32);
extern void func_02077008(struct Request *);
extern void CARD_NotifyRomHashReadAsync(void *);

u32 CARDi_ReadCardWithHashInternalAsync(u32 a, u32 b, u32 c, u32 d)
{
    if (data_02150200.state == -1) {
        d = 0;
    } else {
        DWCi_ScreenDC_FlushRange(b, d);
        data_02732DA8.callback = CARD_NotifyRomHashReadAsync;
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
