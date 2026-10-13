/*
 * function: MIi_FIFOCallback
 * address:  0x0272FFC8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F3C 0x02732F3C data twl
 *   data_02732EFC 0x02732EFC data twl
 *   func_02084998 0x02084998 arm
 *   func_020849C8 0x020849C8 arm
 *   MIi_NDMACallback 0x02730090 arm twl
 *   MIi_NDmaAsync_withConfig_Dev 0x0272F9C4 arm twl
 */
typedef unsigned int u32;
struct St { u32 f0; u32 f4; u32 f8; u32 fc; };
struct E { int a, b, c, d; };
extern struct St data_02732F3C;
extern struct E data_02732EFC[];
extern void func_02084998(u32);
extern void func_020849C8(u32);
extern void MIi_NDMACallback(void);
extern void MIi_NDmaAsync_withConfig_Dev(u32, u32, u32, u32, u32, u32, void (*)(), u32, void *, u32, u32);

static void MIi_FIFOCallback(void)
{
    u32 pos;
    u32 n = data_02732F3C.fc;
    void (*cb)();
    u32 rem;
    u32 idx;
    if (n == 0) {
        return;
    }
    if (n >= 0x1d8) {
        n = 0x1d8;
    }
    pos = data_02732F3C.f8;
    data_02732F3C.fc -= n;
    data_02732F3C.f8 = pos + n;
    if (data_02732F3C.fc == 0) {
        func_02084998(0x200000);
    }
    func_020849C8(0x200000);
    rem = data_02732F3C.fc;
    cb = MIi_NDMACallback;
    if (rem != 0) {
        cb = 0;
    }
    idx = data_02732F3C.f4;
    MIi_NDmaAsync_withConfig_Dev(rem == 0 ? 9 : 8, idx, pos, 0x04000400, 0, n, cb, 0,
                  (void *)((char *)data_02732EFC + (idx << 4)), -1, 0x80000000);
}






