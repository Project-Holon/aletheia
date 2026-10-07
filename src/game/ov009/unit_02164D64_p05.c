/*
 * file:     unit_02164D64_p05.c
 * unit:     yes
 * function: func_021659B4, func_021659F8
 * address:  0x021659B4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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

void WCMi_Notify(short result, void *para0, void *para1, long para2);
void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
extern char g_021AA7D4[];


void WCMi_Notify(short result, void *para0, void *para1, long para2)
{
    short notifyId = *(short *)(*(char **)(g_021AA7D4 + 4) + 0x1000 + 0x2da);

    *(short *)(*(char **)(g_021AA7D4 + 4) + 0x1000 + 0x2da) = 0;
    WCMi_NotifyEx(notifyId, result, para0, para1, para2);
}


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
