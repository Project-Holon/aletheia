/*
 * file:     irc_internal.c
 * unit:     yes
 * function: IRCi_WaitCommand, IRCi_Init, IRCi_End, IRCi_CommWrite, IRCi_CommRead, IRCi_Read, IRCi_Write
 * address:  0x0217A5B4
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      IRCi_Write (libirc.a irc_internal.o)
 *
 * symbols:
 *   OS_GetTick  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   OS_GetLockID  0x02084EB8  arm
 *   gIrcLockId     0x0217AAB4  data
 *   gIrcCommParamAlias2     0x0217AC90  data
 *   OS_ReleaseLockID  0x02084F10  arm
 *   CARD_LockBackup  0x02075E9C  arm
 *   OS_LockCard  0x02084DF4  arm
 *   OS_UnLockCard  0x02084E2C  arm
 *   CARD_UnlockBackup  0x02075EAC  arm
 *   gIrcReadBuffer     0x0217ACA0  data
 *   g_0217AC90b    0x0217AC90  data
 *   gIrcWriteBuffer     0x0217AD58  data
 *   g_0217AC90_b   0x0217AC90  data
 */

#include "../types.h"

typedef struct IRCParam {
    int reserved00;
    unsigned char *send;
    unsigned char *recv;
} IRCParam;

extern unsigned long long OS_GetTick(void);
extern long OS_GetLockID(void);
extern void OS_ReleaseLockID(unsigned short lockID);
extern void CARD_LockBackup(int owner);
extern long OS_LockCard(u16 id);
extern void OS_UnLockCard();
extern void CARD_UnlockBackup(u16 id);
void IRCi_WaitCommand(void);
void IRCi_Init(void);
void IRCi_End(void);
unsigned char IRCi_CommWrite(struct IRCParam *param);
void IRCi_CommRead(struct IRCParam *param);
int IRCi_Read(u8 *buf);
void IRCi_Write(unsigned char *data, unsigned char size);
extern unsigned short gIrcLockId;
extern struct IRCParam gIrcCommParamAlias2;
extern u8 gIrcReadBuffer[181];
extern struct IRCParam g_0217AC90b;
extern unsigned char gIrcWriteBuffer[181];
extern struct IRCParam g_0217AC90_b;

/*
 * sdk:      IRCi_WaitCommand (libirc.a irc_internal.o)
 */
void IRCi_WaitCommand(void)
{
    unsigned long long time;

    time = OS_GetTick();
    while ((OS_GetTick() - time) * 64000 / 0x82EA < 60)
        ;
}

/*
 * sdk:      IRCi_Init (libirc.a irc_internal.o)
 */
void IRCi_Init(void)
{
    (*(int *)&gIrcCommParamAlias2) = 1;
    if (gIrcLockId != 0xFFFD)
        return;
    gIrcLockId = OS_GetLockID();
}

/*
 * sdk:      IRCi_End (libirc.a irc_internal.o)
 */
void IRCi_End(void)
{
    if (gIrcLockId == -3)
        return;
    OS_ReleaseLockID(gIrcLockId);
    gIrcLockId = -3;
}

/*
 * sdk:      IRCi_CommWrite (libirc.a irc_internal.o)
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
unsigned char IRCi_CommWrite(struct IRCParam *param)
{
    unsigned long long time;
    volatile unsigned short tmp;

    time = OS_GetTick();
    while ((OS_GetTick() - time) * 64000 / 0x82EA < 50)
        ;
    *(volatile unsigned short *)0x040001A2 = *param->send;
    param->send++;
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    tmp = *(volatile unsigned short *)0x040001A2;
    return tmp;
}

/*
 * sdk:      IRCi_CommRead (libirc.a irc_internal.o)
 */
void IRCi_CommRead(struct IRCParam *param)
{
    unsigned long long time;

    time = OS_GetTick();
    while ((OS_GetTick() - time) * 64000 / 0x82EA < 50)
        ;
    *(volatile unsigned short *)0x040001A2 = 0;
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    *param->recv = *(volatile unsigned short *)0x040001A2;
    param->recv++;
}

#pragma opt_lifetimes off

/*
 * lane01 (2026-10-01): DWARF types `size` as unsigned char and the return as unsigned char
 *   (int here is a stand-in). With u8 size/return every clamp position (after the load, before
 *   or after `i = 0`, between send/recv, after `buf[0] = 0`, ternary at the load) and both
 *   declaration orders measure 324 B: either the clamp zero CSEs with i (extra `mov r0,#0`)
 *   or the send/recv stmib splits and buf moves to r5. Int body kept (6 B).
 *
 * Lane 08 (2026-09-30): 320/320 bytes, 6 concrete bytes.  One further source
 *   fix over lane 04: moving the `if ((unsigned int)size > 0xB5) size = 0;`
 *   clamp ABOVE the `i = 0;` / `g.send = 0;` block makes the clamp's zero
 *   rematerialise as `movhi r4, #0` instead of reusing the `i`/`send` zero in
 *   r5, closing the `movhi r4, r5` byte (8 -> 6).  Clause order matters: with
 *   the clamp after the zero-init the compiler CSEs the two zeroes.
 *   byte-xor loop's counter in r5; dsi/1.1p1 keeps it in r1.  A fresh loop
 *   variable, a while/do-while form, plain relational vs ternary, and moving
 *   `recv` before `send` were all measured inert (stayed 6).
 *   Wave-8 follow-up: this is the documented freshly-dead-register boundary
 *   (docs/idioms/a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register-from-the-scratch.md).
 *   At the loop merge the then-path leaves r5 freshly dead (last use `cmp r5,r4`) and
 *   the else-path leaves r1 freshly dead (`strh r2,[r1]`); dsi colours the second
 *   loop's new zero r1, the image colours it r5.  `return i;` instead of
 *   `return size;` DOES force the counter to r5, but the counter then stays live
 *   across the trailing calls so the +0x0108 IO-pointer load moves r5->r4 and the
 *   return becomes `mov r0,r5`: 4 bytes, still wrong (worse overall).  Also measured
 *   inert (stayed 6): const-zero copy, a named zero reused as both the `send`/`buf[0]`
 *   zero and the second loop initialiser (`i = z;`), `register int i`, `i &= 0`, `i = i;` (at the
 *   merge, in the else arm, after the for-init), `size = size;`/`buf = buf;` at the
 *   merge, `buf[i] = buf[i] ^ 0xAA;`, a `c = buf[i]` temp, and splitting the first
 *   loop's counter into a second variable.
 *
 * Lane 04 (2026-09-30): 320/320 bytes, 18 concrete bytes.  Four source fixes
 *   read off the image and verified by compile:
 *   - the two loops are `for (; (i < size) ? 1 : 0; i++)`; the plain relational
 *     form rotates the loop (a dead pre-test plus a fall-through body) whereas
 *     the ternary keeps the image's `b <bottom-test>` entry.  This alone took
 *     the file from 177 concrete bytes to 29.
 *   - `size` is `int` (the image compares signed: `blt`) but the clamp is
 *     unsigned: `if ((unsigned int)size > 0xB5)` gives the image's `movhi`.
 *   - the address 0x0217AC90 is named through TWO externs (gIrcCommParamAlias2 and
 *     g_0217AC90b at the same address); the image's pool carries the word
 *     twice.  One name CSE'd both uses into a callee-saved register and left
 *     the function 4 bytes short.
 *   Residue (register allocation only): the image keeps the early `&g` in r4
 *   (so the +0x70 reload lands in r0) and the second loop's counter in r5;
 *   dsi/1.1p1 keeps `&g` in r7 across the calls and colours the second loop's
 *   counter r1.  Declaration order, the loop spelling, moving `i = 0`, and a
 *   literal cast for the call argument were all measured inert.
 *
 * Closed 2026-10-01 with `#pragma opt_lifetimes off` (lifetime splitting off), read as
 *   the vendor's build setting for this object, not a workaround. Evidence: across all 67
 *   open overlay SDK drafts the pragma closes exactly three, all from libirc irc.o /
 *   irc_internal.o and libmb mb_gameinfo.o; all 20 already-matched functions of those
 *   objects stay EXACT with it, while it breaks 5 of 125 sampled functions from other
 *   objects. Without it the loop variable is split across two registers (residue noted below).
 * sdk:      IRCi_Read (libirc.a irc_internal.o)
 */
int IRCi_Read(u8 *buf)
{
    int size;
    int i;

    gIrcCommParamAlias2.send = gIrcReadBuffer;
    gIrcCommParamAlias2.recv = buf;
    gIrcReadBuffer[0] = 1;
    buf[0] = 0;
    CARD_LockBackup(gIrcLockId);
    OS_LockCard(gIrcLockId);
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
    *(volatile u16 *)0x040001A0 = 0xA042;
    IRCi_CommWrite(((struct IRCParam *)&g_0217AC90b));
    IRCi_WaitCommand();
    IRCi_CommRead(((struct IRCParam *)&g_0217AC90b));
    IRCi_WaitCommand();
    size = buf[0];
    if ((unsigned int)size > 0xB5)
        size = 0;
    i = 0;
    gIrcCommParamAlias2.send = 0;
    gIrcCommParamAlias2.recv = buf;
    buf[0] = 0;
    if (size != 0) {
        for (; (i < size) ? 1 : 0; i++) {
            if (i == size - 1)
                *(volatile u16 *)0x040001A0 = 0xA002;
            IRCi_CommRead(((struct IRCParam *)&g_0217AC90b));
        }
    } else {
        *(volatile u16 *)0x040001A0 = 0xA002;
        IRCi_CommRead(((struct IRCParam *)&g_0217AC90b));
    }
    for (i = 0; (i < size) ? 1 : 0; i++) {
        buf[i] ^= 0xAA;
    }
    while (*(volatile u16 *)0x040001A0 & 0x80)
        ;
    OS_UnLockCard(gIrcLockId);
    CARD_UnlockBackup(gIrcLockId);
    return size;
}

void IRCi_Write(unsigned char *data, unsigned char size)
{
    int i;
    int n;

    gIrcCommParamAlias2.send = gIrcWriteBuffer;
    gIrcCommParamAlias2.recv = 0;
    gIrcWriteBuffer[0] = 2;
    CARD_LockBackup(gIrcLockId);
    OS_LockCard(gIrcLockId);
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    *(volatile unsigned short *)0x040001A0 = 0xA042;
    IRCi_CommWrite(((IRCParam *)&g_0217AC90_b));
    IRCi_WaitCommand();
    gIrcCommParamAlias2.send = data;
    n = size;
    for (i = 0; (i < size) ? 1 : 0; i++) {
        if (i == n - 1)
            *(volatile unsigned short *)0x040001A0 = 0xA002;
        IRCi_CommWrite(((IRCParam *)&g_0217AC90_b));
    }
    while (*(volatile unsigned short *)0x040001A0 & 0x80)
        ;
    OS_UnLockCard(gIrcLockId);
    CARD_UnlockBackup(gIrcLockId);
}
