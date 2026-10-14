/*
 * function: MBi_CommParentRecvData
 * address:  0x021F26C0
 * packet:   pkt_ov107_021F26C0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MBi_CommParentRecvData (libmb.TWL.HYB.a(mb_parent.o))
 *
 * symbols:
 *   g_021F6EEC  0x021F6EEC  data
 *   g_021F6FA0  0x021F6FA0  data
 *   func_0208ED70  0x0208ED70  arm
 *   func_021F2200  0x021F2200  arm  ov107
 */

extern int g_021F6EEC;
extern unsigned char *g_021F6FA0;
typedef unsigned short u16;
struct WMMpRecvData;
struct WMMpRecvHeader;
extern struct WMMpRecvData *func_0208ED70(const struct WMMpRecvHeader *header, u16 aid);
extern void func_021F2200(void *arg, unsigned short child);

void MBi_CommParentRecvData(void *arg)
{
    unsigned short i;
    unsigned short *datap;

    for (i = 0; i < 16; i++) {
        if (g_021F6FA0[i * 0x5D4 + 0x1D52] != 0)
            *(unsigned short *)(g_021F6FA0 + i * 0x5D4 + 0x1D4A) = 0;
    }
    g_021F6EEC = 0;
    for (i = 1; i <= 15; i++) {
        datap = (short unsigned int *)func_0208ED70(arg, i);
        if (datap != 0 && datap[0] != 0xFFFF && datap[0] != 0)
            func_021F2200(datap, i);
    }
}
