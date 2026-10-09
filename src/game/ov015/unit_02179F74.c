/*
 * file:     unit_02179F74.c
 * function: func_02179F74
 * address:  0x02179F74
 * packet:   pkt_ov015_02179F74
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * closed (lane 09, 2026-10-01): irc.o's statics (sdkobj lists them as local data) are
 *   defined here as TU `static ... = init;`. As file statics the zero for the three
 *   callback clears is set up before the unit_number strb (0xFF in r3, 0 in r2), which
 *   no extern spelling reached (residue was 8 B). mwcc lays .data out in reverse
 *   declaration order (unit_number declared first lands at +1) and sorts .bss by size
 *   with its own order inside a size class; the 4-byte statics are declared in the order
 *   that puts sRecvCallback at +8 (IRC_SetRecvCallback), sShutdownCallback +0xc,
 *   sConnectCallback +0x10, isSender +0x18 (IRC_IsSender); cnt_retry/flg_restore/isTry (names per the irc.o DWARF, 2026-10-06)
 *   fill +4/+0x14/+0x1c by elimination (names from irc.o, slots not attested). Values
 *   are the image's (.data 0217AAB0 = ff ff).
 *
 * symbols:
 *   func_0217A60C  0x0217A60C  arm  ov015
 *   func_0217A7AC  0x0217A7AC  arm  ov015
 *   func_02179F48  0x02179F48  arm  ov015
 *   func_0217A594  0x0217A594  arm  ov015
 *   myUnitNumber   0x0217AAB0  data
 *   unit_number    0x0217AAB1  data
 *   retry_count    0x0217ABA8  data
 *   sIrcBuf        0x0217ABD8  data
 */

typedef unsigned char u8;
typedef unsigned long long u64;

typedef void (*IRCConnectCallback)(u8 unitId, int isSender);
typedef void (*IRCRecvCallback)(u8 *data, u8 size, u8 command, u8 id);
typedef void (*IRCShutdownCallback)(int isError);

extern void func_0217A60C(void);
extern int func_0217A7AC(u8 *buf);
extern void func_02179F48(void);
extern void func_0217A594(u8 id);

static u8 unit_number = 0xFF;
static u8 myUnitNumber = 0xFF;
static u8 retry_count = 0;
static int isSender = 0;
static IRCConnectCallback sConnectCallback = 0;
static int flg_restore = 0;
static IRCShutdownCallback sShutdownCallback = 0;
static int cnt_retry = 0;
static IRCRecvCallback sRecvCallback = 0;
static int isTry = 0;
static u64 sStatus = 0;
static u64 timeout = 0;
static u8 sIrcBuf[184] = {0};

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
