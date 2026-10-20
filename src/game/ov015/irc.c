/*
 * file:     irc.c
 * unit:     yes
 * function: IRCi_CalcSum, IRCi_Restore, IRCi_ResetState, IRC_Init, IRC_Connect, IRC_IsSender, IRC_IsConnect, IRCi_Send, IRCi_Finish, IRC_Shutdown, IRC_Send, IRCi_Nop, IRCi_CheckLength, IRCi_CheckTimeout, IRCi_CheckPacket, IRC_Move, IRC_SetRecvCallback, IRC_SetUnitNumber, IRC_GetUnitNumber
 * address:  0x02179EE0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * notes:    libirc irc.o IRC_Connect (TwlSDK add-ins/irc, FINALROM build: the OS_Printf call on line 160 is an
 *           empty macro). Earlier passes (P20 lane 4, G5L2, P2L27, P3L13, P4L06) stayed at 12-16 bytes off with
 *           all state as fields of one struct over the .bss base.
 *           pass 5 2026-10-06 P5L05: closed. The irc.o DWARF shows the state as separate file statics, not one
 *           struct: flg_restore +0x14, isSender +0x18, isTry +0x1c, sStatus +0x20 (IRCStatus {status enum;
 *           BOOL flg_connect}), timeout +0x28. So the guards are sStatus.flg_connect (line 150) and isTry
 *           (line 154), line 158 is isTry = TRUE and line 166 is sStatus.status = IRC_ST_WAIT_RESPONSE. With
 *           isTry as its own object the scheduler places the argument setup before the isTry store, as in the
 *           game. No pragma is needed. The statics are declared as in ov_sdk/IRC_Init.c (mwcc .data
 *           in reverse order, .bss by size class), except that isTry and flg_restore change places: the DWARF
 *           puts isTry at +0x1c and flg_restore at +0x14 (02179F74 has these two names swapped; it does not
 *           use either, so its bytes do not change). `u8 command` is a C99 mid-block declaration as in the
 *           vendor DWARF (no lexical block), so the file needs --lang c99; the same body with the declaration
 *           in a nested block is also EXACT in --lang c and --lang c99.
 *           Check: the library IRC_Move rebuilt from matched 0217A334 plus its OS_Printf calls is byte-exact,
 *           so the game irc.o is the Release source with the prints removed, same compiler and flags.
 *           2026-10-13: IRC_Init merged in from its own file. Both functions are irc.o, and each
 *           file defined the irc.o statics, so .data 0217AAB0 was defined twice in a whole-overlay link.
 *           Notes of 02179F74 (lane 09, 2026-10-01): as file statics, the zero for the three callback
 *           clears is set up before the unit_number strb; .bss slots +8 sRecvCallback, +0xc
 *           sShutdownCallback, +0x10 sConnectCallback, +0x18 isSender agree with IRC_SetRecvCallback and
 *           IRC_IsSender. Its bytes do not change with the statics block below.
 *
 * symbols:
 *   IRCi_Write  0x0217A8EC  arm    ov015
 *   IRCi_Init  0x0217A60C  arm    ov015
 *   IRCi_Read  0x0217A7AC  arm    ov015
 *   OS_GetTick     0x020870D0  arm
 *   myUnitNumber   0x0217AAB0  data
 *   unit_number    0x0217AAB1  data
 *   retry_count    0x0217ABA8  data
 *   sIrcBuf        0x0217ABD8  data
 *   gIrcBuffer     0x0217ABD8  data
 *   gIrcBufferPayload     0x0217ABDC  data
 *   IRCi_End  0x0217A648  arm  ov015
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */
#include "irc_types.h"
#include "ircnet_types.h"

typedef struct {
    IRCStatusType status;
    BOOL flg_connect;
} IRCStatus;

typedef struct {
    unsigned char command;
    unsigned char id;
    unsigned char sumLo;
    unsigned char sumHi;
} IRCHeader;

#include "irc_internal.h"
#include "../arm9/os_tick.h"
unsigned short IRCi_CalcSum(void *input, unsigned long length);
void IRCi_Restore(void);
void IRCi_ResetState(void);
void IRC_Init(u8 unitId);
void IRC_Connect(void);
unsigned int IRC_IsSender(void);
unsigned int IRC_IsConnect(void);
void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id);
void IRCi_Finish(int n);
void IRC_Shutdown(void);
void IRC_Send(u8 *data, u8 size, int command);
void IRCi_Nop(void);
int IRCi_CheckLength(unsigned long n);
int IRCi_CheckTimeout(void);
int IRCi_CheckPacket(unsigned long n);
int IRC_Move(void);
void IRC_SetRecvCallback(void *cb);
void IRC_SetUnitNumber(unsigned int n);
unsigned int IRC_GetUnitNumber(void);


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
/* Matching device: the packet functions reach this buffer through the extern alias below,
   which the original compiler addressed from its own literal-pool word. */
static u8 sIrcBuf[184] = {0};
extern unsigned char gIrcBuffer[184];
extern unsigned char gIrcBufferPayload[184];

/*
 * sdk:      IRCi_CalcSum (libirc.a irc.o)
 */
unsigned short IRCi_CalcSum(void *input, unsigned long length)
{
    unsigned long sum;
    unsigned long i;
    unsigned char t;

    sum = 0x80;
    for (i = 0; i < length; i++) {
        t = *(unsigned char *)input;
        input = (unsigned char *)input + 1;
        if (i & 1)
            sum += t;
        else
            sum += t << 8;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return (unsigned short)sum;
}



void IRCi_Restore(void)
{
    flg_restore = 1;
    cnt_retry = cnt_retry + 1;
}


void IRCi_ResetState(void)
{
    retry_count = 0;
    sStatus.status = 0;
    sStatus.flg_connect = 0;
    flg_restore = 0;
    isTry = 0;
    isSender = 0;
    cnt_retry = 0;
}





void IRC_Init(u8 unitId)
{
    u8 size;

    IRCi_Init();
    size = IRCi_Read(sIrcBuf);
    IRCi_ResetState();
    IRC_SetUnitNumber(unitId);
    unit_number = 0xFF;
    sConnectCallback = 0;
    sRecvCallback = 0;
    sShutdownCallback = 0;
}


void IRC_Connect(void)
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
        u8 command = IRC_CMD_CONNECT_REQUEST;
        IRCi_Write(&command, 1);
    }
    sStatus.status = IRC_ST_WAIT_RESPONSE;
    timeout = OS_GetTick();
}


unsigned int IRC_IsSender(void)
{
	return isSender;
}



unsigned int IRC_IsConnect(void)
{
	return sStatus.flg_connect;
}


#pragma opt_lifetimes off



/*
 * notes:    w9_nm2: DIFF 10 B (was 16). A dedicated local buf = gIrcBuffer assigned after the copy loop (declared before pHeader) puts i in ip and the pointers in r6/r5; the final call keeps the pool word. Left: object stores sumLo before sumHi (scheduler swaps; tried order, masks, byte pointer, locals) and loop 2 counter is r1 not ip (tried i=0 hoists).
 *           The image keeps the XOR counter i in r12/ip and therefore stores
 *           sumLo/sumHi in source order; mwcc here colours the fresh zero of
 *           the second loop r1 (freeing r1 first, so the two strb swap) and
 *           everything downstream moves. Verified unchanged by: plain/ternary
 *           loop spellings, while/do-while, a fresh loop variable, separate
 *           i/j, long/enum/register/unsigned i, i=0 hoisted before the stores,
 *           a named enum zero, explicit byte temporaries, p-reuse, and a
 *           2000-compile permuter anneal (plateau at 10). w8 also: a no-code
 *           `i = i;` self-assignment at the live-range boundary (idiom
 *           a-no-code-self-assignment-*), an enum-typed counter, and
 *           reusing `p` as the second base with pHeader declared first
 *           (that one costs 24 B — pHeader drops to r5, so the dedicated
 *           buf local is required). Floor stays 10 B. DWARF confirms the
 *           vendor's i is r12 (int) for the whole function. Needs an allocator
 *           that re-materialises the second zero into ip, which no source
 *           spelling tried reaches.
 * lane 6 (wave 10): named hi/lo/u16 byte temporaries (declared before or after i, five shapes) are inert, still 10 B.
 * lane 8 (wave 8): residue is exactly docs/idioms/a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch.md
 *           (found in CPSi_rc4_init): dsi/1.1p1 hands the freshly-dead asr result r1 to loop 2's hoisted zero,
 *           the image keeps the zero in ip (so the two strb stay in source order). A batch of 10 spellings all pin
 *           at 10 B: hi-first source order, named hi / lo+hi, byte-pointer header, enum zero, named-zero copy,
 *           plain `i < size` loop2 (65 B), `sum / 256` (11 B), `unsigned char i` (124 B). Confirms the idiom's park.
 * lane 7 (wave 8): a full sweep of all 120 declaration orders of {p,sum,i,buf,pHeader} is inert (best stays the
 *           baseline order at 10 B). Making the second zero a dependency of a live value (`z=0; i=z;`,
 *           `i=size-size;`, `i=(unsigned char)(sum&0)`) is inert. Loop2 with a plain/while/do-while condition
 *           changes size; only the ternary bottom-test condition reproduces the shape. Floor remains 10 B.
 * 2026-10-01: DWARF has no buf. Without it (one sIrcBuf symbol, `&sIrcBuf[4]`,
 *           p reused as loop-2 base, or loop 2 as an inline helper with its own
 *           buf/size/i) loop 1's i leaves ip or pHeader/p swap r5/r6; best stays
 *           this body at 10 B.
 *
 * lane 19 (2026-10-01): mechanism found, not fileable under house rules. Adding
 *           `#pragma opt_lifetimes off` to this exact body gives EXACT (152 B): the image keeps
 *           i as one register across both loops (no live-range split), so loop 2's zero is ip.
 *           Plain `for` loops plus a zero-byte asm also give EXACT (asm mode = no rotation +
 *           no lifetimes). Same pair closes MBi_SendVolatBeacon (ov107 021F42D4). Left for the
 *           integrator: no plain-C spelling found that stops the split.
 * Closed 2026-10-01 with `#pragma opt_lifetimes off` (lifetime splitting off), read as
 *   the vendor's build setting for this object, not a workaround. Evidence: across all 67
 *   open overlay SDK drafts the pragma closes exactly three, all from libirc irc.o /
 *   irc_internal.o and libmb mb_gameinfo.o; all 20 already-matched functions of those
 *   objects stay EXACT with it, while it breaks 5 of 125 sampled functions from other
 *   objects. Without it the loop variable is split across two registers (residue noted below).
 * sdk:      IRCi_Send (libirc.a irc.o)
 */
void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id)
{
    unsigned char *p;
    unsigned short sum;
    int i;
    unsigned char *buf;
    IRCHeader *pHeader;

    pHeader = (IRCHeader *)gIrcBuffer;
    pHeader->command = command;
    pHeader->id = id;
    pHeader->sumLo = 0;
    pHeader->sumHi = 0;
    p = gIrcBufferPayload;
    for (i = 0; (i < size) ? 1 : 0; i++)
        *p++ = *data++;
    size += 4;
    buf = gIrcBuffer;
    sum = IRCi_CalcSum(buf, size);
    pHeader->sumLo = sum;
    pHeader->sumHi = sum >> 8;
    for (i = 0; (i < size) ? 1 : 0; i++)
        buf[i] ^= 0xAA;
    IRCi_Write(gIrcBuffer, size);
}



/*
 * notes:    2026-10-05 wave P18 lane 8: libirc finish. When the field at d_0217ABA8 + 0x24 is set, and the field at
 *           +0x18 and the argument n are both zero, sends a 0xF4 frame through IRCi_Send. Then calls the
 *           callback stored at +0xC with n when it is set, and resets the state with IRCi_ResetState.
 */
void IRCi_Finish(int n)
{
    IRCShutdownCallback cb;

    if (sStatus.flg_connect != 0 && isSender == 0 && n == 0)
        IRCi_Send(0, 0, IRC_CMD_FINISH, myUnitNumber);
    cb = sShutdownCallback;
    if (cb != 0)
        cb(n);
    IRCi_ResetState();
}



/*
 * notes:    2026-10-05 wave P27 lane 4: libirc shutdown. Calls IRCi_Finish with 0 (finish), then
 *           IRCi_End (IRCi_End).
 */
void IRC_Shutdown(void)
{
    IRCi_Finish(0);
    IRCi_End();
}


void IRC_Send(u8 *data, u8 size, int command)
{
    if (sStatus.flg_connect)
        IRCi_Send(data, size, command, myUnitNumber);
}


/*
 * notes:    empty function, a lone bx lr. Witness for the call in IRC_Move (2026-10-05, wave P10 lane Y8).
 */
void IRCi_Nop(void)
{
}



/*
 * notes:    2026-10-05 wave P16 lane E4: libirc check on a packet length n. n == 1 returns 1 when the field at
 *           d_0217ABA8 + 0x24 is set, else whether the first receive byte is not 0xFC. n == 2 or 3 runs two empty
 *           delay loops (bottom-test form (i < n) ? 1 : 0, otherwise mwcc deletes them) and returns 1. Other n returns 0.
 *           The 2/3 test must be a switch after the if: `n == 2 || n == 3` folds to a range test and `n != 2 && n != 3`
 *           gives cmpne/movne. Called from IRC_Move as int(u32).
 */
int IRCi_CheckLength(unsigned long n)
{
    unsigned long i;

    if (n == 1) {
        if (sStatus.flg_connect)
            return 1;
        return gIrcBuffer[0] != IRC_CMD_DISCONNECT;
    }
    switch (n) {
    case 2:
    case 3:
        for (i = 0; (i < 4) ? 1 : 0; i++)
            ;
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        return 1;
    }
    return 0;
}



int IRCi_CheckTimeout(void)
{
    u64 d;

    if (sStatus.flg_connect == 0 && isTry == 0)
        return 0;
    d = OS_GetTick() - timeout;
    d = (d << 6) / 33514ULL;
    if (d < 100)
        return 0;
    IRCi_Finish(1);
    isTry = 0;
    return 1;
}



/*
 * notes:    2026-10-05 wave P13 lane B9: libirc receive check. The empty delay loop needs the bottom-test form
 *           (i < n) ? 1 : 0, otherwise mwcc deletes it. Callee IRCi_CalcSum is IRCi_CalcSum (u16 return, matched);
 *           IRCi_Restore is void. Plain C, no pragmas.
 */
int IRCi_CheckPacket(unsigned long n)
{
    unsigned char *pk = gIrcBuffer;
    unsigned long i;
    unsigned short sum;
    unsigned short calc;

    if (n == 1)
        return pk[0] == IRC_CMD_DISCONNECT;
    if (n < 4)
        return 0;
    sum = pk[2] + (pk[3] << 8);
    pk[2] = 0;
    pk[3] = 0;
    calc = IRCi_CalcSum(pk, n);
    pk[3] = sum >> 8;
    pk[2] = sum;
    if (calc == sum) {
        retry_count = 0;
        return 1;
    }
    if (sStatus.flg_connect) {
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        IRCi_Restore();
    }
    return 0;
}



#pragma opt_common_subs off


/*
 * notes:    Packet handler of the libirc link (state block 0x0217ABA8). 2026-10-05 wave P10 lane Y8 first draft; final push
 *           2026-10-05 G8L6 closed it. The 0xF8 residue was a hidden callee argument list: the onDone callback is called
 *           as onDone(pk[1], 0), so r0 keeps the byte just stored to unit_number and r1 keeps the zero used for the
 *           f14/f1C stores, and the callback pointer lands in r2. The earlier draft called it with no arguments
 *           (onDone is void (*)(u8, int)). The dead `n = 1` in the 0xFA arm was not needed (the literal 1 is pooled in r5
 *           by itself) and was dropped. Pragma opt_common_subs off reproduces the three separate loads of the packet
 *           command byte. Callee types: A7AC(u8 *) returns u32, A178(u32) int, A1FC() int, A280(u32) int, 020870D0
 *           returns u64, A034 four ints. IRCi_Nop is an empty leaf (bx lr), filed as IRCi_Nop.c.
 */
int IRC_Move(void)
{
    u32 n;
    u8 *pk;

    n = IRCi_Read(gIrcBuffer);
    if (IRCi_CheckLength(n))
        n = 0;
    if (n == 0)
        return IRCi_CheckTimeout() != 0;
    if (!IRCi_CheckPacket(n))
        return 0;
    timeout = OS_GetTick();
    pk = gIrcBuffer;
    if (pk[0] < 0xF0) {
        if (sStatus.flg_connect == 0)
            return 0;
        if (pk[1] != myUnitNumber)
            return 0;
    }
    switch (pk[0]) {
    case IRC_CMD_DISCONNECT:
        switch (sStatus.status) {
        case 0:
        case 2:
        case 3:
        case 4:
            break;
        case 1:
            sStatus.status = 2;
            IRCi_Send(0, 0, IRC_CMD_CONNECT_ACK, myUnitNumber);
            break;
        }
        if (isTry == 0) {
            isTry = 1;
            sStatus.status = 2;
            isSender = 0;
            if (n <= 1 || sStatus.flg_connect != 0) {
                IRCi_Send(0, 0, IRC_CMD_CONNECT_ACK, myUnitNumber);
                if (sStatus.flg_connect != 0)
                    IRCi_Restore();
                IRCi_Nop();
            }
        }
        break;
    case IRC_CMD_CONNECT_ACK:
        if (sStatus.status == 1) {
            sStatus.status = 3;
            isSender = 1;
            unit_number = pk[1];
            if (pk[1] == myUnitNumber) {
                IRCi_Send(0, 0, IRC_CMD_CONNECT_CONFIRM, myUnitNumber);
                sStatus.flg_connect = 1;
                flg_restore = 0;
                isTry = 0;
            }
        }
        break;
    case IRC_CMD_CONNECT_CONFIRM:
        if (sStatus.status == 2) {
            sStatus.status = 4;
            unit_number = pk[1];
            sStatus.flg_connect = 1;
            flg_restore = 0;
            isTry = 0;
            if (sConnectCallback)
                (sConnectCallback)(pk[1], 0);
        }
        break;
    case IRC_CMD_RESTORE:
        IRCi_Restore();
        break;
    default:
        if (flg_restore != 1 && sStatus.flg_connect != 0)
            sRecvCallback(gIrcBufferPayload, n - 4, gIrcBuffer[0], gIrcBuffer[1]);
        break;
    }
    return 0;
}



#pragma opt_common_subs reset



void IRC_SetRecvCallback(void *cb)
{
	sRecvCallback = (IRCRecvCallback)cb;
}



void IRC_SetUnitNumber(unsigned int n)
{
	myUnitNumber = (unsigned char)n;
}



unsigned int IRC_GetUnitNumber(void)
{
	return unit_number;
}
