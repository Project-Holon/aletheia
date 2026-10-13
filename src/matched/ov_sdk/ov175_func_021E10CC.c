/*
 * function: DWC_GdbInitialize
 * address:  0x021E10CC
 * packet:   pkt_ov175_021E10CC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GdbInitialize (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 *
 * symbols:
 *   func_0216AAE0  0x0216AAE0  arm  ov009
 *   DWCi_GdbPrintf  0x021E17D8  arm  ov175
 *   DWCi_GdbGetStartRequestErrorCode  0x021E1EAC  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   func_0217CA40  0x0217CA40  arm  ov009
 *   sakeStartup  0x021DD1EC  arm  ov175
 *   DWCi_GdbShutdownGsCore  0x021E191C  arm  ov175
 *   DWCi_GdbHandleStartupResult  0x021E1EC4  arm  ov175
 *   sakeSetGame  0x021DD25C  arm  ov175
 *   sakeSetProfile  0x021DD290  arm  ov175
 *   DWCi_GdbSetUseSSL  0x021E216C  arm  ov175
 *   DWC_InitGHTTP  0x021BF558  arm  ov114
 *   gDwcGdbEntity  0x021E5334  data
 *   sDwcGdbLoginTicketFailed  0x021E450C  data
 *   sDwcGdbSakeStartupFailed  0x021E452C  data
 *   g_021AE01C  0x021AE01C  data
 *   g_021AE11C  0x021AE11C  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    int size;
    u32 pseudo[3];
    u32 authentic[3];
    int gs_profile_id;
    int flag;
    u32 gamecode;
    int reserved[5];
    u32 crc32;
} DWCstAccUserData;

typedef struct {
    void *request;
    void *sake;
    int   state;
    int   process;
    int   result;
    u32   current_work;
    u8    work[2][56];
} DWCiGdbEntity;

extern int func_0216AAE0(char *loginTicket);
struct SAKEInternal;
extern void DWCi_GdbPrintf(int line, char *fmt, ...);
extern int DWCi_GdbGetStartRequestErrorCode(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern void func_0217CA40(void);
extern int sakeStartup(struct SAKEInternal **sakePtr);
extern void DWCi_GdbShutdownGsCore(void);
extern int DWCi_GdbHandleStartupResult(int result);
extern void sakeSetGame(char *p, int b, int c, int d);
extern void sakeSetProfile(struct SAKEInternal *sake, int profileId, const char *loginTicket);
extern void DWCi_GdbSetUseSSL(int ssl_type);
extern int DWC_InitGHTTP();
extern DWCiGdbEntity gDwcGdbEntity;
extern char sDwcGdbLoginTicketFailed[];
extern char sDwcGdbSakeStartupFailed[];
extern char g_021AE01C[];
extern char g_021AE11C[];

int DWC_GdbInitialize(int game_id, DWCstAccUserData *userdata, int ssl_type)
{
    char loginTicket[25];
    int result;

    if (gDwcGdbEntity.state != 0)
        return 18;
    if (!func_0216AAE0(loginTicket)) {
        DWCi_GdbPrintf(0x11A, sDwcGdbLoginTicketFailed);
        func_02059F54(8, DWCi_GdbGetStartRequestErrorCode(1, 4));
        return 4;
    }
    func_0217CA40();
    result = sakeStartup((struct SAKEInternal **)(&gDwcGdbEntity.sake));
    if (result != 0) {
        DWCi_GdbPrintf(0x127, sDwcGdbSakeStartupFailed, result);
        DWCi_GdbShutdownGsCore();
        return DWCi_GdbHandleStartupResult(result);
    }
    sakeSetGame(gDwcGdbEntity.sake, (int)g_021AE01C, game_id, (int)g_021AE11C);
    sakeSetProfile(gDwcGdbEntity.sake, userdata->gs_profile_id, loginTicket);
    DWCi_GdbSetUseSSL(ssl_type);
    DWC_InitGHTTP(0);
    gDwcGdbEntity.state = 1;
    gDwcGdbEntity.result = 0;
    gDwcGdbEntity.process = 0;
    gDwcGdbEntity.current_work = 0;
    return 0;
}
