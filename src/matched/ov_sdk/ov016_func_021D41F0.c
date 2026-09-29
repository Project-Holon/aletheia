/*
 * function: func_021D41F0
 * address:  0x021D41F0
 * packet:   pkt_ov016_021D41F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _DWCi_MOVStartWaitChild (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_Init                0x021D1D40  arm  ov016
 *   g_021DE668                       0x021DE668  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 pad0[0x648];
    u16 moveid_tgid;
    u8 pad1[0xa90 - 0x64a];
    u8 mov_stt;
    u8 mov_stt_old;
    u8 pad2[0xaa0 - 0xa92];
    void *sChildInfo[1];
    u8 pad3[0xac8 - 0xaa4];
    u32 ggid;
} Wk;

extern Wk *g_021DE668;
extern void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid);

void func_021D41F0(void)
{
    DWCi_MOV_MBP_Init(g_021DE668->ggid, g_021DE668->moveid_tgid);
}
