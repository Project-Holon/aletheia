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
 * w6_nm tried: goto-spelled exits with a shared return label (both senses),
 * a result local via goto, unsigned char return/callee types: register roles unchanged.
 *
 * w8_nm: `int r = 0; ... if (call) r = 1; return r;` puts 0 in r5 and 1 in r4 as
 * in the object (15 B -> 5 B). Left: the object returns with `moveq r0,r5;
 * movne r0,r4`, this compile with `movne r5,r4; mov r0,r5`. The result local is
 * not in the DWARF. Tried: `? 1 : 0`, `!!`, `!= 0`, if/else returns in both
 * senses, r = 1 then clear, if/else assignment, the call result in a local,
 * cc 1.1, 1.2, 1.2p1, 1.3.
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
    int r = 0;

    g_021DE660.wh->f12a4 = 0;
    g_021DE660.wh->f12a0 = 0;
    g_021DE660.wh->f48 = 0;
    g_021DE660.wh->f50 = 0;
    g_021DE660.wh->f52 = 1;
    g_021DE660.wh->f54 = 0;
    g_021DE660.wh->f0 = 0;
    g_021DE660.wh->f4 = 0;
    g_021DE660.wh->f4c = 0;
    if (DWCi_MOV_WH_StateInInitialize())
        r = 1;
    return r;
}
