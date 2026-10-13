/*
 * file:     wcm_util.c
 * unit:     yes
 * function: func_02166680, func_021666B8, func_021666C8, func_02166710, func_02166784, func_02166804
 * address:  0x02166680
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
 *   OS_DisableInterrupts  0x02087988  arm
 *   WCMi_GetSystemWork  0x021657C8  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   g_021AA814  0x021AA814  data ov009
 *   g_021AA815  0x021AA815  data ov009
 */
typedef enum WMLinkLevel {
    WM_LINK_LEVEL_0 = 0,
    WM_LINK_LEVEL_1 = 1,
    WM_LINK_LEVEL_2 = 2,
    WM_LINK_LEVEL_3 = 3
} WMLinkLevel;

typedef struct WCMWork_021666C8 {
    unsigned char pad0[0x12DE];
    unsigned char phase;
} WCMWork_021666C8;

typedef struct WCMWork_02166710 {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork_02166710;

typedef struct WCMWork_02166804 {
    unsigned char pad0[0x12DF];
    unsigned char deviceId;
} WCMWork_02166804;

extern unsigned long OS_DisableInterrupts(void);
extern int WCMi_GetSystemWork(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void _s32_div_f();
int func_02166680(unsigned char *a, unsigned char *b, unsigned int n);
void func_021666B8(int a, int b);
WMLinkLevel func_021666C8(void);
WMLinkLevel func_02166710(unsigned char rssi);
unsigned char func_02166784(void);
void func_02166804(unsigned char rssi);
extern unsigned char g_021AA814;
extern unsigned char g_021AA815[16];

/*
 * Byte compare over n units: 0 at the first difference, 1 when all agree.
 */
int func_02166680(unsigned char *a, unsigned char *b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}


void func_021666B8(int a, int b)
{
    func_02166680((unsigned char *)a, (unsigned char *)b, 6);
}


/*
 * sdk:      WCM_GetLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * Returns the current link level from the averaged RSSI while connected, else level 0.
 */
WMLinkLevel func_021666C8(void)
{
    unsigned long e;
    WCMWork_021666C8 *w;
    WMLinkLevel ret;

    e = OS_DisableInterrupts();
    w = (WCMWork_021666C8 *)WCMi_GetSystemWork();
    ret = WM_LINK_LEVEL_0;
    if (w != 0 && w->phase == 9) {
        ret = func_02166710(func_02166784());
    }
    OS_RestoreInterrupts(e);
    return ret;
}


/*
 * sdk:      WCM_CalcLinkLevel (libwcm.TWL.HYB.a util.o)
 *
 * Maps an RSSI value to a link level, with per-device thresholds.
 */
WMLinkLevel func_02166710(unsigned char rssi)
{
    WCMWork_02166710 *w;

    w = (WCMWork_02166710 *)WCMi_GetSystemWork();
    switch (w->deviceId) {
    case 1:
    default:
        if (rssi >= 0x1C) {
            return WM_LINK_LEVEL_3;
        }
        if (rssi >= 0x16) {
            return WM_LINK_LEVEL_2;
        }
        if (rssi >= 0x10) {
            return WM_LINK_LEVEL_1;
        }
        return WM_LINK_LEVEL_0;
    case 2:
        if (rssi >= 0x16) {
            return WM_LINK_LEVEL_3;
        }
        if (rssi >= 0x11) {
            return WM_LINK_LEVEL_2;
        }
        if (rssi >= 0xC) {
            return WM_LINK_LEVEL_1;
        }
        return WM_LINK_LEVEL_0;
    }
}


/*
 * sdk:      WCMi_GetRssiAverage (libwcm.TWL.HYB.a util.o)
 *
 * Averages the sheltered RSSI ring buffer: 16 samples once the ring is full, otherwise the samples stored so far.
 */
unsigned char func_02166784(void)
{
    long sum;
    long i;

    sum = 0;
    if (g_021AA814 > 16) {
        for (i = 0; i < 16; i++) {
            sum += g_021AA815[i];
        }
        sum = sum / 16;
    } else if (g_021AA814 != 0) {
        for (i = 0; i < g_021AA814; i++) {
            sum += g_021AA815[i];
        }
        sum = sum / g_021AA814;
    }
    return (unsigned char)sum;
}


/*
 * sdk:      WCMi_ShelterRssi (libwcm.TWL.HYB.a util.o)
 *
 * Stores an RSSI sample into the ring buffer, converting the raw value first for device 1.
 */
void func_02166804(unsigned char rssi)
{
    WCMWork_02166804 *w;
    int raw;

    w = (WCMWork_02166804 *)WCMi_GetSystemWork();
    switch (w->deviceId) {
    case 1:
    default:
        raw = rssi >> 2;
        if ((rssi & 2) != 0) {
            rssi = (unsigned char)raw;
        } else {
            rssi = (unsigned char)(raw + 0x19);
        }
        break;
    case 2:
        break;
    }
    g_021AA815[g_021AA814 % 16] = rssi;
    if (g_021AA814 < 16) {
        g_021AA814 = (unsigned char)(g_021AA814 + 1);
    } else {
        g_021AA814 = (unsigned char)((g_021AA814 + 1) % 16 + 16);
    }
}
