/*
 * function: func_021D4624
 * address:  0x021D4624
 * packet:   pkt_ov016_021D4624
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Parent_StepDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_021D3250 0x021D3250 arm ov016
 *   func_021D3904 0x021D3904 arm ov016
 *   func_021D323C 0x021D323C arm ov016
 *   func_021D38DC 0x021D38DC arm ov016
 *   g_021DE668 0x021DE668 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0x100];
    u8 shared[2][0x44];
    char pad188[0x204 - 0x188];
    int counter;
    int valid[2];
    char pad210[0xa90 - 0x210];
    u8 state;
    char padA91;
    u8 sendKind;
    u8 mode;
    char padA94[0xab0 - 0xa94];
    u16 *buf;
} Wk;

extern Wk *g_021DE668;

extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_021D3250(void);
extern int func_021D3904(void *data);
extern u16 func_021D323C(void);
extern u16 *func_021D38DC(u16 aid);

void func_021D4624(u16 kind, u16 counter, u8 *data)
{
    u16 i;
    u16 *adr;

    if (g_021DE668->mode == 1) {
        g_021DE668->buf[0] = kind;
        g_021DE668->buf[1] = counter;
        func_02082D44(data, g_021DE668->buf + 2, 0x40);
    } else {
        g_021DE668->counter++;
        g_021DE668->buf[0] = 0xbc;
        ((u8 *)g_021DE668->buf)[4] = g_021DE668->sendKind;
    }
    if (func_021D3250() != 5)
        return;
    if (func_021D3904(g_021DE668) == 0) {
        g_021DE668->counter += 4;
        return;
    }
    if (g_021DE668->mode == 0) {
        g_021DE668->counter++;
    } else {
        g_021DE668->counter = 0;
        if (func_021D323C() != 3) {
            g_021DE668->state = 0x1b;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        adr = func_021D38DC(i);
        if (adr != 0) {
            func_02082D44(adr, g_021DE668->shared[i], 0x44);
            g_021DE668->valid[i] = 1;
        } else {
            g_021DE668->valid[i] = 0;
        }
    }
}
