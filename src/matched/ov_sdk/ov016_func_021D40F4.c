/*
 * function: DWCi_MOVGetStatus
 * address:  0x021D40F4
 * packet:   pkt_ov016_021D40F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOVGetStatus (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   gDwcMoveidWork                       0x021DE668  data
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

extern Wk *gDwcMoveidWork;
void DWCi_MOVGetStatus(u8 *stt, u8 *change_f)
{
    *stt = gDwcMoveidWork->mov_stt;
    if (gDwcMoveidWork->mov_stt != gDwcMoveidWork->mov_stt_old)
        *change_f = 1;
    else
        *change_f = 0;
    gDwcMoveidWork->mov_stt_old = gDwcMoveidWork->mov_stt;
}
