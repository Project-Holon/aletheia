/*
 * function: func_02037200
 * address:  0x02037200
 * packet:   pkt_02037200
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469C8     0x021469C8  data
 *   func_02036D64  0x02036D64  arm
 */

typedef unsigned int u32;

struct Notifier {
    u32   unk00;
    void *handler;
};

extern struct Notifier g_021469C8;
typedef unsigned char  u8;
extern u32 func_02036D64(u8 *p);

u32 func_02037200(void)
{
    if (g_021469C8.handler == 0) {
        return 1;
    }
    return func_02036D64(g_021469C8.handler);
}
