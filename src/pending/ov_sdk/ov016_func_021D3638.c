/*
 * function: func_021D3638
 * address:  0x021D3638
 * packet:   pkt_ov016_021D3638
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      DWCi_MOV_WH_Initialize (libdwcutil.TWL.HYB.a(dwc_mov_wh.o))
 *
 * symbols:
 *   DWCi_MOV_WH_StateInInitialize    0x021D36D0  arm  ov016
 *   g_021DE660                       0x021DE660  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u32 f0;
    u16 f4;
    u8 pad0[0x48 - 6];
    u32 f48;
    u32 f4c;
    u16 f50;
    u16 f52;
    u32 f54;
    u8 pad1[0x12a0 - 0x58];
    u32 f12a0;
    u32 f12a4;
} Wh;

typedef struct {
    void *trace;
    Wh *wh;
} WhGlobals;

extern WhGlobals g_021DE660;
extern int DWCi_MOV_WH_StateInInitialize(void);

int func_021D3638(void)
{
    g_021DE660.wh->f12a4 = 0;
    g_021DE660.wh->f12a0 = 0;
    g_021DE660.wh->f48 = 0;
    g_021DE660.wh->f50 = 0;
    g_021DE660.wh->f52 = 1;
    g_021DE660.wh->f54 = 0;
    g_021DE660.wh->f0 = 0;
    g_021DE660.wh->f4 = 0;
    g_021DE660.wh->f4c = 0;
    return DWCi_MOV_WH_StateInInitialize() ? 1 : 0;
}
