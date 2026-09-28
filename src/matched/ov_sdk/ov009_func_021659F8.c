/*
 * function: WCMi_NotifyEx
 * address:  0x021659F8
 * packet:   pkt_ov009_021659F8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_NotifyEx (system.o)
 *
 * symbols:
 *   g_021AA7D4                      0x021AA7D4 data
 */

typedef struct {
    short notify;
    short result;
    void *para0;
    void *para1;
    long para2;
} WCMNotice;

extern char g_021AA7D4[];

void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2)
{
    char *w = *(char **)(g_021AA7D4 + 4);
    WCMNotice notice;

    if (*(void (**)(WCMNotice *))(w + 0x1000 + 0x2d0) == 0)
        return;
    notice.notify = notify;
    notice.result = result;
    notice.para0 = para0;
    notice.para1 = para1;
    notice.para2 = para2;
    (*(void (**)(WCMNotice *))(w + 0x1000 + 0x2d0))(&notice);
}
