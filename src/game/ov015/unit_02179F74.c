/*
 * file:     unit_02179F74.c
 * function: func_02179F74, func_02179FC4
 * address:  0x02179F74
 * packet:   pkt_ov015_02179F74, pkt_ov015_02179FC4
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    libirc irc.o IRC_Connect (TwlSDK add-ins/irc, FINALROM build: the OS_Printf call on line 160 is an
 *           empty macro). Earlier passes (P20 lane 4, G5L2, P2L27, P3L13, P4L06) stayed at 12-16 bytes off with
 *           all state as fields of one struct over the .bss base.
 *           pass 5 2026-10-06 P5L05: closed. The irc.o DWARF shows the state as separate file statics, not one
 *           struct: flg_restore +0x14, isSender +0x18, isTry +0x1c, sStatus +0x20 (IRCStatus {status enum;
 *           BOOL flg_connect}), timeout +0x28. So the guards are sStatus.flg_connect (line 150) and isTry
 *           (line 154), line 158 is isTry = TRUE and line 166 is sStatus.status = IRC_ST_WAIT_RESPONSE. With
 *           isTry as its own object the scheduler places the argument setup before the isTry store, as in the
 *           game. No pragma is needed. The statics are declared as in ov_sdk/ov015_func_02179F74.c (mwcc .data
 *           in reverse order, .bss by size class), except that isTry and flg_restore change places: the DWARF
 *           puts isTry at +0x1c and flg_restore at +0x14 (02179F74 has these two names swapped; it does not
 *           use either, so its bytes do not change). `u8 command` is a C99 mid-block declaration as in the
 *           vendor DWARF (no lexical block), so the file needs --lang c99; the same body with the declaration
 *           in a nested block is also EXACT in --lang c and --lang c99.
 *           Check: the library IRC_Move rebuilt from matched 0217A334 plus its OS_Printf calls is byte-exact,
 *           so the game irc.o is the Release source with the prints removed, same compiler and flags.
 *           2026-10-13: func_02179F74 merged in from its own file. Both functions are irc.o, and each
 *           file defined the irc.o statics, so .data 0217AAB0 was defined twice in a whole-overlay link.
 *           Notes of 02179F74 (lane 09, 2026-10-01): as file statics, the zero for the three callback
 *           clears is set up before the unit_number strb; .bss slots +8 sRecvCallback, +0xc
 *           sShutdownCallback, +0x10 sConnectCallback, +0x18 isSender agree with IRC_SetRecvCallback and
 *           IRC_IsSender. Its bytes do not change with the statics block below.
 *
 * symbols:
 *   func_0217A8EC  0x0217A8EC  arm    ov015
 *   func_0217A60C  0x0217A60C  arm    ov015
 *   func_0217A7AC  0x0217A7AC  arm    ov015
 *   func_02179F48  0x02179F48  arm    ov015
 *   func_0217A594  0x0217A594  arm    ov015
 *   OS_GetTick     0x020870D0  arm
 *   myUnitNumber   0x0217AAB0  data
 *   unit_number    0x0217AAB1  data
 *   retry_count    0x0217ABA8  data
 *   sIrcBuf        0x0217ABD8  data
 */

typedef unsigned char u8;
typedef int BOOL;
typedef unsigned long long u64;
typedef u64 OSTick;
#define TRUE 1

typedef void (*IRCConnectCallback)(u8 unitId, BOOL isSender);
typedef void (*IRCRecvCallback)(u8 *data, u8 size, u8 command, u8 id);
typedef void (*IRCShutdownCallback)(BOOL isError);

typedef enum {
    IRC_ST_DISCONNECT,
    IRC_ST_WAIT_RESPONSE,
    IRC_ST_WAIT_ACK,
    IRC_ST_SENDER,
    IRC_ST_RECEIVER,
    IRC_ST_NUM
} IRCStatusType;

typedef struct {
    IRCStatusType status;
    BOOL flg_connect;
} IRCStatus;

extern void func_0217A8EC(u8 *data, u8 size);
extern OSTick OS_GetTick(void);

static u8 unit_number = 0xFF;
static u8 myUnitNumber = 0xFF;
static u8 retry_count = 0;
static BOOL isSender = 0;
static IRCConnectCallback sConnectCallback = 0;
static BOOL flg_restore = 0;
static IRCShutdownCallback sShutdownCallback = 0;
static int cnt_retry = 0;
static IRCRecvCallback sRecvCallback = 0;
static BOOL isTry = 0;
static IRCStatus sStatus = {0};
static OSTick timeout = 0;
static u8 sIrcBuf[184] = {0};

extern void func_0217A60C(void);
extern int func_0217A7AC(u8 *buf);
extern void func_02179F48(void);
extern void func_0217A594(u8 id);

void func_02179F74(u8 unitId)
{
    u8 size;

    func_0217A60C();
    size = func_0217A7AC(sIrcBuf);
    func_02179F48();
    func_0217A594(unitId);
    unit_number = 0xFF;
    sConnectCallback = 0;
    sRecvCallback = 0;
    sShutdownCallback = 0;
}

void func_02179FC4(void)
{
    if (sStatus.flg_connect)
    {
        return;
    }
    if (isTry)
    {
        return;
    }
    isTry = TRUE;
    {
        u8 command = 0x56;
        func_0217A8EC(&command, 1);
    }
    sStatus.status = IRC_ST_WAIT_RESPONSE;
    timeout = OS_GetTick();
}
