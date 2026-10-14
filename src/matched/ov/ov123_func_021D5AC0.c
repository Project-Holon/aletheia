/*
 * function: GSYNC_DOWNLOAD_SetRequestMode
 * address: 0x021D5AC0
 * packet: pkt_ov123_021D5AC0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD9r lane99): EXACT. The switch is a static inline helper that returns the mode; case 3
 *   returns from inside the switch, the other cases break to the final `return mode;`. The inline return
 *   copy into the result keeps case 3's own `b end` block until after jump-table threading (the stub at
 *   +0x26). No redundant statement and no cast: only the return-versus-break shape of case 3.
 *   Earlier lanes (D2 to D9r) tried every in-function form of case 3; all merged it with the end label.
 * symbols:
 *   func_0200F7DC 0x0200F7DC thumb
 *   d_021DAC20 0x021DAC20 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *d_021DAC20;
extern void func_0200F7DC(void);

static inline u32 func_021D5AC0_next(u32 mode)
{
    switch (mode) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
        break;
    case 3:
        return mode;
    case 6:
        *(u32 *)(d_021DAC20 + 0xC8) = 1;
        break;
    case 8:
        func_0200F7DC();
        break;
    }
    return mode;
}

void GSYNC_DOWNLOAD_SetRequestMode(void *unused, u32 mode)
{
    u32 next = func_021D5AC0_next(mode);
    *(u32 *)(d_021DAC20 + 0xB0) = 1;
    *(u32 *)(d_021DAC20 + 0xB4) = next;
}
