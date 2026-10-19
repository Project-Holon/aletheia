/*
 * file:     os_argument.c
 * unit:     yes
 * function: OS_InitDeliverArgInfo, OS_EncodeDeliverArg, OS_DecodeDeliverArg, OS_SetDeliverArgStateInvalid, OS_GetTitleIdFromDeliverArg, OS_IsValidDeliverArg
 * address:  0x02087F60
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_02151384   0x02151384  data
 *   SVC_GetCRC16   0x02004632  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   s_02151384     0x02151384  data
 *   s_02151390     0x02151390  data
 *   OS_IsValidDeliverArg  0x02088150  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   SVC_GetCRC16  0x02004632  thumb
 *   OS_SetDeliverArgStateInvalid  0x02088118  arm
 */
#include "../types.h"

#include "../sdk_os.h"

/* os_argument.o .bss from 0x02151384, addressed from one pool word: sPtr
   (a cursor into the argument buffer), the buffer state and the buffer. */
typedef struct OsArgumentBss {
    u8 *sPtr;
    u32 sBufferState;
    OSDeliverArgInfo *sBufferPtr;
} OsArgumentBss;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u16 SVC_GetCRC16(u32 start, const void *data, u32 size);

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

void OS_SetDeliverArgStateInvalid(void);
u64 OS_GetTitleIdFromDeliverArg(void);
BOOL OS_IsValidDeliverArg(void);
void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize);
int OS_EncodeDeliverArg(void);
int OS_DecodeDeliverArg(void);
extern OsArgumentBss g_02151384;
extern u64      s_02151390;

/*
 * sdk:      OS_InitDeliverArgInfo (os_argument.o)
 */
void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize)
{
    g_02151384.sBufferPtr = info;
    MI_CpuFill8(info, 0, sizeof(OSDeliverArgInfo));
    g_02151384.sBufferState = 3;

    g_02151384.sBufferPtr->header.argBufferSize = (u16)(748 - binSize);
    g_02151384.sBufferPtr->header.binarySize = 0;

    g_02151384.sPtr = g_02151384.sBufferPtr->buf;
    g_02151384.sBufferPtr->buf[0] = 0;
    g_02151384.sPtr[1] = 0;
}

/*
 * TwlSDK os_argument.o, the member after OS_InitDeliverArgInfo (0x02087F60):
 * the deliver-argument ENCODE step.  If the "initialised" bit of the module
 * state is clear, return -1.  Otherwise stamp the buffer header with the
 * maker code (u16 at 0x02FFE010) and title ID (u64 at 0x02FFE230) out of the
 * TWL ROM header copy, set the header byte at +9 to 3, keep a copy of the
 * title ID at 0x02151390, CRC the 0x300-byte buffer with SVC_GetCRC16 (crc
 * field zeroed first), copy it to HW_PARAM_DELIVER_ARG (0x02000000) with
 * MI_CpuCopy8(src, dest, size), clear it with MI_CpuFill8, reset the state
 * and return 0.
 *
 * What the old note (docs/notes/pkt_02087FBC.c.txt, 188 against 176) was
 * missing: the ROM-header addresses are plain constants, not a relocated
 * object; MI_CpuCopy8 takes (src, dest, size), not the bus-first order that
 * note used; and the title-ID copy and the `= 3` byte store go through ONE
 * local pointer, which is why the image does not reload the buffer pointer
 * between the u64 store and the byte store while it does everywhere else.
 * 0x02151390 resolves as sole-ref (its only pool word is this function's).
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/OS_EncodeDeliverArg.c \
 *       --func OS_EncodeDeliverArg --addr 0x02087FBC --arm --cc 1.1p1
 */
int OS_EncodeDeliverArg(void)
{
    if ((g_02151384.sBufferState & 1) == 0) return -1;
    g_02151384.sBufferPtr->header.makerCode = *(u16 *)0x02FFE010;
    {
        OSDeliverArgHeader *p = (OSDeliverArgHeader *)g_02151384.sBufferPtr;
        p->titleId = *(u64 *)0x02FFE230;
        p->flag = 3;
    }
    s_02151390 = g_02151384.sBufferPtr->header.titleId;
    g_02151384.sBufferPtr->header.crc = 0;
    g_02151384.sBufferPtr->header.crc = SVC_GetCRC16(0xFFFF, g_02151384.sBufferPtr, 0x300);
    MI_CpuCopy8(g_02151384.sBufferPtr, (void *)0x02000000, 0x300);
    MI_CpuFill8(g_02151384.sBufferPtr, 0, 0x300);
    g_02151384.sBufferState = 0;
    return 0;
}

/*
 * 172 bytes, 0x0208806C..0x02088118, every concrete byte reproduced (0
 * differing bytes of 172); the diff is empty apart from the one wildcarded
 * call field at +0x04.
 *
 * Blocked on the `label` class, and it is a one-address wall: OS_IsValidDeliverArg
 * is reached by exactly one branch anywhere in the image, the `bl` at
 * +0x04 of this function, which is inside the compared range, so `label`
 * refuses it and `matched` has no EXACT entry at 0x02088150 yet.  The
 * compared range cannot be shrunk to exclude it (the call is the function's
 * first statement).  It graduates the day 0x02088150 is matched -- nothing
 * in this C changes.  Note 0x02088150 carries a `.global OS_IsValidDeliverArg`
 * label in asm/arm9/src/027_0208475C.s, so only the outside-branch witness
 * is missing.
 *
 * The other four calls resolve through `label` with plenty of outside
 * witnesses.  SVC_GetCRC16 had to be declared at 0x02004632 (thumb), not
 * 0x02004630: the target is a BLX, and match.py rewrites BL against BLX from
 * the declared ISA, so a wrong address leaves the H bit wrong and reports a
 * concrete one-byte DIFF (0xFB vs 0xEB in byte 3 of the branch) rather than
 * an unresolved wildcard.
 */
int OS_DecodeDeliverArg(void)
{
    u32 *state;
    u32 oldCrc;

    if (OS_IsValidDeliverArg() == 0)
        return -1;

    state = (u32 *)0x02151384;
    if (state[2] == 0)
        return -1;

    ((void (*)(u32 src, u32 dest, u32 size))MI_CpuCopy8)(0x02000000, state[2], 0x300);

    oldCrc = *(u16 *)(state[2] + 0x10);
    *(u16 *)(state[2] + 0x10) = 0;
    *(u16 *)(state[2] + 0x10) = ((u32 (*)(u32 start, u32 data, u32 size))SVC_GetCRC16)(0xffff, state[2], 0x300);

    if (oldCrc != *(u16 *)(state[2] + 0x10)) {
        MI_CpuFill8((void *)state[2], 0, 0x300);
        OS_SetDeliverArgStateInvalid();
        return 0;
    }

    *(u8 *)(state[2] + 9) &= 0xfe;
    state[1] = 1;
    return 0;
}

/*
 * note:     ctrdg_proc.o CTRDGi_CallbackForSetPhi.
 */
void OS_SetDeliverArgStateInvalid(void)
{
    g_02151384.sBufferState = 0;
}

/*
 * sdk:      OS_GetTitleIdFromDeliverArg (os_argument.o)
 */
u64 OS_GetTitleIdFromDeliverArg(void)
{
    if (!(g_02151384.sBufferState & 1)) {
        return 0;
    }
    return g_02151384.sBufferPtr->header.titleId;
}

BOOL OS_IsValidDeliverArg(void)
{
    OSDeliverArgInfo *p = (OSDeliverArgInfo *)0x02000000;

    return (p->header.flag & 2) ? 1 : 0;
}
