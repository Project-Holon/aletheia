/*
 * function: OS_EncodeDeliverArg
 * address:  0x02087FBC
 * packet:   pkt_02087AE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SVC_GetCRC16   0x02004632  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   s_02151384     0x02151384  data
 *   s_02151390     0x02151390  data
 *
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

#include "../include/G_OsArgumentBss.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {
    u64 titleId;        /* 0x00 */
    u8  f08;
    u8  f09;
    u16 makerCode;      /* 0x0a */
    u8  pad0c[4];
    u16 crc;            /* 0x10 */
} ArgHeader;
extern struct OsArgumentBss s_02151384;
extern u64      s_02151390;
extern u16 SVC_GetCRC16(u32 start, const void *data, u32 size);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
int OS_EncodeDeliverArg(void)
{
    if ((s_02151384.sBufferState & 1) == 0) return -1;
    ((ArgHeader *)s_02151384.sBufferPtr)->makerCode = *(u16 *)0x02FFE010;
    {
        ArgHeader *p = s_02151384.sBufferPtr;
        p->titleId = *(u64 *)0x02FFE230;
        p->f09 = 3;
    }
    s_02151390 = ((ArgHeader *)s_02151384.sBufferPtr)->titleId;
    ((ArgHeader *)s_02151384.sBufferPtr)->crc = 0;
    ((ArgHeader *)s_02151384.sBufferPtr)->crc = SVC_GetCRC16(0xFFFF, s_02151384.sBufferPtr, 0x300);
    MI_CpuCopy8(s_02151384.sBufferPtr, (void *)0x02000000, 0x300);
    MI_CpuFill8(s_02151384.sBufferPtr, 0, 0x300);
    s_02151384.sBufferState = 0;
    return 0;
}
