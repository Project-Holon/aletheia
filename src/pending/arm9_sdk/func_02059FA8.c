/*
 * function: func_02059FA8
 * address:  0x02059FA8
 * packet:   pkt_02059FA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    15 bytes: the two inlined host-name block copies load dst/src into r4/r3 swapped (and their literal-pool order follows); strcpy, memcpy, struct and loop spellings all tried; StatsServerHostname (0x021A5850) also has no outside witness. sdk9w2_dwc also tried: string-literal struct casts, local struct initialisers, compound literals, inline copy helpers with either parameter order, switch forms, strcpy with restrict prototypes, __builtin_strcpy/__builtin_memcpy, and dsi/1.1 to 1.6sp2: all keep src-first (12 to 15 bytes); permuter seed 13302 no gain
 *
 * sdk:      DWCi_Init (libdwccommon.TWL.HYB.a dwc_init.o)
 *
 * symbols:
 *   DWCi_SetMemFunc                0x0205A158 arm
 *   OS_InitTick                    0x02086FE8 arm
 *   OS_InitAlarm                   0x02087208 arm
 *   RTC_Init                       0x02088788 arm
 *   DWC_Alloc                      0x0205A16C arm
 *   DWC_BM_Init                    0x020589D0 arm
 *   DWC_Auth_CheckWiFiIDNeedCreate 0x02059008 arm
 *   DWCi_AUTH_MakeWiFiID           0x02058D88 arm
 *   DWC_Free                       0x0205A1B0 arm
 *   DWCi_Auth_InitInterface        0x02178C88 arm ov009
 *   gsiMemoryCallbacksSet          0x0217EA9C arm ov009
 *   strcpy                         0x02094798 arm
 *   DWCi_Np_SetInitFlag            0x0205A11C arm
 *   dwci_gamecode                  0x02146AAC data a4
 *   DWCi_GsMalloc                  0x0205A26C arm
 *   DWCi_GsFree                    0x0205A29C arm
 *   DWCi_GsRealloc                 0x0205A280 arm
 *   DWCi_GsMemalign                0x0205A2B4 arm
 *   gcd_gamename                   0x021AE01C data a1
 *   StatsServerHostname            0x021A5850 data a1
 *   str_sdkdev                     0x020A8070 data a1
 *   str_gamestats                  0x020A8084 data a1
 */

typedef unsigned long u32;

typedef void *(*DWCAllocEx)(int name, u32 size, int align);
typedef void (*DWCFreeEx)(int name, void *ptr, u32 size);

#define DWC_ALLOCTYPE_BASE 2
#define DWC_INIT_WORK_SIZE 0x1000

extern void  DWCi_SetMemFunc(DWCAllocEx alloc, DWCFreeEx free);
extern void  OS_InitTick(void);
extern void  OS_InitAlarm(void);
extern void  RTC_Init(void);
extern void *DWC_Alloc(int name, u32 size);
extern int   DWC_BM_Init(void *work);
extern int   DWC_Auth_CheckWiFiIDNeedCreate(void);
extern int   DWCi_AUTH_MakeWiFiID(void *work);
extern void  DWC_Free(int name, void *ptr, u32 size);
extern int   DWCi_Auth_InitInterface(int auth_server);
extern void  gsiMemoryCallbacksSet(void *(*p_malloc)(u32), void (*p_free)(void *),
                                   void *(*p_realloc)(void *, u32), void *(*p_memalign)(u32, u32));
extern char *strcpy(char *dst, const char *src);
extern void  DWCi_Np_SetInitFlag(int initialized);
extern void *DWCi_GsMalloc(u32 size);
extern void  DWCi_GsFree(void *ptr);
extern void *DWCi_GsRealloc(void *ptr, u32 size);
extern void *DWCi_GsMemalign(u32 boundary, u32 size);

extern u32  dwci_gamecode;
extern char gcd_gamename[];
extern char StatsServerHostname[];

/* the object copies its two host-name literals (@16103, @16104) into
 * StatsServerHostname as fixed-size blocks, NUL included */
typedef struct { char s[19]; } DWCHostName19;
typedef struct { char s[30]; } DWCHostName30;
extern const DWCHostName19 str_sdkdev;      /* "sdkdev.gamespy.com" */
extern const DWCHostName30 str_gamestats;   /* "gamestats.gs.nintendowifi.net" */

int func_02059FA8(int authserver, const char *gameName, u32 gameCode, DWCAllocEx alloc, DWCFreeEx free)
{
    int ret;
    int result;
    int created = 0;
    void *work;

    DWCi_SetMemFunc(alloc, free);
    OS_InitTick();
    OS_InitAlarm();
    RTC_Init();
    work = DWC_Alloc(DWC_ALLOCTYPE_BASE, DWC_INIT_WORK_SIZE);
    if (work == 0)
        return 4;
    ret = DWC_BM_Init(work);
    if (DWC_Auth_CheckWiFiIDNeedCreate()) {
        DWCi_AUTH_MakeWiFiID(work);
        created = 1;
    }
    DWC_Free(DWC_ALLOCTYPE_BASE, work, 0);
    if (ret < 0) {
        if (created)
            result = 2;
        else
            result = 3;
    } else {
        if (created)
            result = 1;
        else
            result = 0;
    }

    DWCi_Auth_InitInterface(authserver);
    dwci_gamecode = gameCode;
    gsiMemoryCallbacksSet(DWCi_GsMalloc, DWCi_GsFree, DWCi_GsRealloc, DWCi_GsMemalign);
    if (gameName != 0)
        strcpy(gcd_gamename, gameName);
    if (authserver == 0)
        *(DWCHostName19 *)StatsServerHostname = str_sdkdev;
    else
        *(DWCHostName30 *)StatsServerHostname = str_gamestats;
    DWCi_Np_SetInitFlag(1);
    return result;
}
