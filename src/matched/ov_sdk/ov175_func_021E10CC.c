/*
 * function: func_021E10CC
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
 *   func_021E17D8  0x021E17D8  arm  ov175
 *   func_021E1EAC  0x021E1EAC  arm  ov175
 *   func_02059F54  0x02059F54  arm
 *   func_0217CA40  0x0217CA40  arm  ov009
 *   func_021DD1EC  0x021DD1EC  arm  ov175
 *   func_021E191C  0x021E191C  arm  ov175
 *   func_021E1EC4  0x021E1EC4  arm  ov175
 *   func_021DD25C  0x021DD25C  arm  ov175
 *   func_021DD290  0x021DD290  arm  ov175
 *   func_021E216C  0x021E216C  arm  ov175
 *   func_021BF558  0x021BF558  arm  ov114
 *   g_021E5334  0x021E5334  data
 *   g_021E450C  0x021E450C  data
 *   g_021E452C  0x021E452C  data
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
extern void func_021E17D8(int line, const char *fmt, ...);
extern int func_021E1EAC(int process, int error);
extern void func_02059F54(int error, int errorCode);
extern void func_0217CA40(void);
extern int func_021DD1EC(void **sakePtr);
extern void func_021E191C(void);
extern int func_021E1EC4(int result);
extern void func_021DD25C(void *sake, char *gameName, int gameId, char *secretKey);
extern void func_021DD290(void *sake, int profileId, char *loginTicket);
extern void func_021E216C(int ssl_type);
extern int func_021BF558();
extern DWCiGdbEntity g_021E5334;
extern char g_021E450C[];
extern char g_021E452C[];
extern char g_021AE01C[];
extern char g_021AE11C[];

int func_021E10CC(int game_id, DWCstAccUserData *userdata, int ssl_type)
{
    char loginTicket[25];
    int result;

    if (g_021E5334.state != 0)
        return 18;
    if (!func_0216AAE0(loginTicket)) {
        func_021E17D8(0x11A, g_021E450C);
        func_02059F54(8, func_021E1EAC(1, 4));
        return 4;
    }
    func_0217CA40();
    result = func_021DD1EC(&g_021E5334.sake);
    if (result != 0) {
        func_021E17D8(0x127, g_021E452C, result);
        func_021E191C();
        return func_021E1EC4(result);
    }
    func_021DD25C(g_021E5334.sake, g_021AE01C, game_id, g_021AE11C);
    func_021DD290(g_021E5334.sake, userdata->gs_profile_id, loginTicket);
    func_021E216C(ssl_type);
    func_021BF558(0);
    g_021E5334.state = 1;
    g_021E5334.result = 0;
    g_021E5334.process = 0;
    g_021E5334.current_work = 0;
    return 0;
}
