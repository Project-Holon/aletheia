/*
 * function: MBi_CommCallParentError
 * address:  0x021F2F04
 * packet:   pkt_ov107_021F2F04
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlSDK/libmb.TWL.HYB.a(mb_parent.o).  decl_line 1261.
 */
typedef unsigned short u16;

extern void MBi_CommChangeParentStateCallbackOnly(u16 aid, int state, void *e_stat);

void MBi_CommCallParentError(u16 aid, u16 errcode)
{
    u16 e_stat;

    e_stat = errcode;
    MBi_CommChangeParentStateCallbackOnly(aid, 0xD, &e_stat);
}
