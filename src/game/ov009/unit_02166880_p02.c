/*
 * file:     unit_02166880_p02.c
 * unit:     yes
 * function: func_02166DE4, func_02166E5C, func_02166EB0
 * address:  0x02166DE4
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
 *   WM_GetAllowedChannel            0x0208ee60 arm
 *   WCMi_GetSystemWork               0x021657c8 arm
 *   WM_Reset                         0x0208f400 arm
 *   WCMi_SetPhase                    0x02165a4c arm
 *   WCMi_Notify                      0x021659b4 arm
 *   WcmWmcbReset                     0x021679c0 arm
 */
struct WCMWork;
struct WCMWork {
    unsigned char pad[0x12dd];
    unsigned char flag;
};

extern unsigned short WM_GetAllowedChannel(void);
extern struct WCMWork *WCMi_GetSystemWork(void);
extern int WM_Reset(void (*callback)(void *));
extern void WCMi_SetPhase(unsigned char phase);
extern void WCMi_Notify(short result, void *para0, void *para1, long para2);
extern void WcmWmcbReset(void *arg);
unsigned short WCMi_WmifGetAllowedChannel(void);


unsigned short WCMi_WmifGetAllowedChannel(void)
{
    unsigned short val = WM_GetAllowedChannel();
    unsigned short low, high, tmp;

    high = 0x8000;
    low = 1;
    if (val == 0)
        return 0;
    if ((val & 0x8000) == 0) {
        do {
            high = (high >> 1) | 0x8000;
        } while ((high & val) == 0);
    }
    if ((val & 1) == 0) {
        do {
            low = (low << 1) | 1;
        } while ((low & val) == 0);
    }
    tmp = (unsigned short)~((unsigned short)((unsigned int)high << 1) | ((unsigned int)low >> 1));
    return tmp;
}


static void WcmWmReset(void)
{
    struct WCMWork *wcmw;
    int wmResult;

    wcmw = WCMi_GetSystemWork();
    if (wcmw->flag != 0)
        return;
    wcmw->flag = 1;
    wmResult = WM_Reset(WcmWmcbReset);
    if (wmResult == 2)
        return;
    WCMi_SetPhase(0xb);
    WCMi_Notify(7, 0, 0, 0x24f);
}


static void WcmWmcbIndication(void *arg)
{
    struct WCMWork *wcmw = WCMi_GetSystemWork();

    if (*(unsigned short *)((char *)arg + 2) != 8 ||
        *(unsigned short *)((char *)arg + 4) != 0x16 ||
        *(unsigned short *)((char *)arg + 6) != 0x25)
        return;
    switch (*(unsigned char *)((char *)wcmw + 0x12de) - 8) {
    case 0:
        WCMi_SetPhase(0xc);
        break;
    case 1:
    case 4:
        WcmWmReset();
        break;
    case 2:
        WCMi_SetPhase(0xc);
        break;
    case 3:
        break;
    }
}
