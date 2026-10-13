/*
 * function: drawInfo
 * address:  0x021C2610
 * packet:   pkt_ov016_021C2610
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      drawInfo (libdwcutil.TWL.HYB.a sceneoptinfo.o)
 *
 * note:     EXACT (2026-10-01). The image's second STRlConvert call is a
 *           cross-jumped tail: the else path feeds it the first block's
 *           r8/sl/sb, the if path rematerialises. Writing the convert call in
 *           both arms keeps &buf/&tmpbuf/20 live into the else arm, which also
 *           fixes the first block's sl/sb/r8 allocation and the 528 B size.
 *
 * symbols:
 *   DWCi_FNTlFormBgEx                    0x021D5A58  arm
 *   OS_GetMacAddress                     0x02087C6C  arm
 *   OS_SNPrintf                          0x02084F80  arm
 *   DWCi_STRlConvertStringAsciiToUnicode 0x021D722C  arm
 *   DWCi_FNTlDrawRect                    0x021D5E5C  arm
 *   DWCi_BM_GetWiFiInfo                  0x02058518  arm
 *   _ll_udiv                             0x0209C00C  arm
 *   _ull_mod                             0x0209C018  arm
 *   DWCi_FNTlRenewBg                     0x021D5FC4  arm
 *   sSceneOptInfoTable1                           0x021DB2F0  data  a1
 *   sSceneOptInfoTable2                           0x021DB310  data  a1
 *   sSceneOptInfoTable3                           0x021DB324  data  a1
 */

struct tagDWCWiFiInfo {
    unsigned long long id;
    unsigned char pad[12];
};

void *DWCi_FNTlFormBgEx(int lcd, int font);
void OS_GetMacAddress(unsigned char *macAddress);
int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
int DWCi_STRlConvertStringAsciiToUnicode(unsigned short *dst, char *src, int len);
void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, unsigned long flag, unsigned short *txt);
void DWCi_BM_GetWiFiInfo(struct tagDWCWiFiInfo *buf);
void DWCi_FNTlRenewBg(void *canvas);
extern char sSceneOptInfoTable1[];
extern char sSceneOptInfoTable2[];
extern char sSceneOptInfoTable3[];

void drawInfo(void)
{
    struct tagDWCWiFiInfo info;
    unsigned long long id;
    int tmp[4];
    int i;
    unsigned short buf[20];
    char tmpbuf[20];
    unsigned char mac[6];
    void *canvas;

    canvas = DWCi_FNTlFormBgEx(0, 0);
    OS_GetMacAddress(mac);
    OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable1, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
    DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 20);
    DWCi_FNTlDrawRect(canvas, 8, 0x40, 0xf0, 0x1c, 2, 0x480, buf);
    DWCi_BM_GetWiFiInfo(&info);
    id = info.id;
    if (id != 0) {
        tmp[3] = (int)((id % 10) * 1000);
        id /= 10;
        for (i = 0; i < 3; i++) {
            tmp[2 - i] = (int)(id % 10000);
            id /= 10000;
        }
        OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable2, tmp[0], tmp[1], tmp[2], tmp[3]);
        DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 20);
    } else {
        OS_SNPrintf(tmpbuf, 20, sSceneOptInfoTable3);
        DWCi_STRlConvertStringAsciiToUnicode(buf, tmpbuf, 20);
    }
    DWCi_FNTlDrawRect(canvas, 8, 0x78, 0xf0, 0x1c, 2, 0x480, buf);
    DWCi_FNTlRenewBg(canvas);
}
