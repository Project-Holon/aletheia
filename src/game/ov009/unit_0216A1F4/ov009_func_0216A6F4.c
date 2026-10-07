/*
 * function: func_0216A6F4
 * address:  0x0216A6F4
 * packet:   pkt_ov009_0216A6F4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RemoteLogin (libdwcmatch.TWL.HYB.a(dwc_login.o))
 *
 * symbols:
 *   func_020596C8  0x020596C8  arm
 *   func_02059474  0x02059474  arm
 *   func_02059084  0x02059084  arm
 *   func_020596B0  0x020596B0  arm
 *   func_02059644  0x02059644  arm
 *   func_02059588  0x02059588  arm
 *   OS_GetTick     0x020870D0  arm
 *   func_020590F0  0x020590F0  arm
 *   func_02178D14  0x02178D14  arm  ov009
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   g_021AA874     0x021AA874  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
} LoginId;

typedef struct {
    char pad0[4];
    LoginId consoleId;
    char loginId[0x14];
    u32 gamecode;
} UserData;

typedef struct {
    char pad0[0xc];
    u32 gamecode;
    u16 *ingamesn;
    char pad14[8];
    UserData *userdata;
    char pad20[0x1c];
    LoginId loginId;
    char pad48[0x200];
    char username[9];
    char gsbrcd[9];
} LoginControl;

extern LoginControl *g_021AA874;

extern int func_020596C8(UserData *userdata);
struct DWCstAccLoginId;
extern void func_02059474(struct DWCstAccLoginId *loginid, unsigned long gamecode, char *username);
extern u64 func_02059084(void *loginId);
extern int func_020596B0(void *loginid);
extern int func_02059644(struct DWCstAccLoginId *loginid);
extern void func_02059588(struct DWCstAccLoginId *loginid);
extern u64 OS_GetTick(void);
extern void func_020590F0(int *p, int v);
extern int func_02178D14(unsigned short *ingamesn, char *gsbrcd, unsigned long long userid, void *(*allocator)(unsigned long, long), void (*deallocator)(unsigned long, void *, long));
extern void *func_0205A16C(u32, long);
extern void func_0205A1B0(u32, void *, long);

int func_0216A6F4(void)
{
    u64 userid;

    if (func_020596C8(g_021AA874->userdata)) {
        func_02059474((struct DWCstAccLoginId *)g_021AA874->userdata->loginId, g_021AA874->userdata->gamecode, g_021AA874->username);
        userid = func_02059084(g_021AA874->userdata->loginId);
    } else {
        if (!func_020596B0(&g_021AA874->loginId)) {
            if (func_02059644((struct DWCstAccLoginId *)(&g_021AA874->userdata->consoleId)))
                g_021AA874->loginId = g_021AA874->userdata->consoleId;
            else
                func_02059588((struct DWCstAccLoginId *)(&g_021AA874->loginId));
        } else {
            func_020590F0((int *)(&g_021AA874->loginId), (u32)((OS_GetTick() * 0x5D588B656C078965ULL + 0x269EC3) >> 32));
        }
        func_02059474((struct DWCstAccLoginId *)(&g_021AA874->loginId), g_021AA874->gamecode, g_021AA874->username);
        userid = 0;
    }
    return func_02178D14(g_021AA874->ingamesn, g_021AA874->gsbrcd, userid, func_0205A16C, func_0205A1B0);
}
