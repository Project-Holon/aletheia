/*
 * function: func_021D4214
 * address:  0x021D4214
 * packet:   pkt_ov016_021D4214
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _DWCi_MOV_WaitandDownloadandBoot_Child (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   func_021D2780 0x021D2780 arm ov016
 *   func_021D1E54 0x021D1E54 arm ov016
 *   func_021D2794 0x021D2794 arm ov016
 *   func_021D22AC 0x021D22AC arm ov016
 *   func_021D2314 0x021D2314 arm ov016
 *   func_021D240C 0x021D240C arm ov016
 *   func_021D3250 0x021D3250 arm ov016
 *   func_021D3AC8 0x021D3AC8 arm ov016
 *   g_021DE668 0x021DE668 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0xa90];
    u8 state;
} WkS;

extern WkS *g_021DE668;

extern u16 func_021D2780(void);
extern void func_021D1E54(void *gameInfo, u16 channel);
extern u16 func_021D2794(int bmpType);
extern int func_021D22AC(void);
extern void func_021D2314(void);
extern void func_021D240C(void);
extern int func_021D3250(void);
extern int func_021D3AC8(void);

void func_021D4214(void)
{
    switch (func_021D2780()) {
    case 1:
        func_021D1E54((char *)g_021DE668 + 0x2b4 + 0x800, *(u16 *)((char *)g_021DE668 + 0x600 + 0x4a));
        return;
    case 2:
        if (func_021D2794(2) != 0) {
            g_021DE668->state = 5;
            return;
        }
        if (func_021D2794(3) != 0 || func_021D2794(4) != 0) {
            g_021DE668->state = 6;
            return;
        }
        if (g_021DE668->state != 5)
            return;
        if (func_021D2794(2) == 0)
            g_021DE668->state = 0xd;
        return;
    case 3:
        if (func_021D22AC() != 0) {
            func_021D2314();
            return;
        }
        if (g_021DE668->state == 6 || g_021DE668->state == 7) {
            if (func_021D2794(3) == 0)
                g_021DE668->state = 0x12;
        }
        return;
    case 5:
        g_021DE668->state = 7;
        return;
    case 7:
        func_021D240C();
        g_021DE668->state = 1;
        return;
    case 0:
        switch (func_021D3250()) {
        case 1:
            func_021D3AC8();
            break;
        case 0:
            g_021DE668->state = 0x1f;
            break;
        case 3:
            break;
        default:
            g_021DE668->state = 0x1f;
            break;
        }
        return;
    }
}
