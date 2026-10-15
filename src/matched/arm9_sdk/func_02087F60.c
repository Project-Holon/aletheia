/*
 * function: OS_InitDeliverArgInfo
 * address:  0x02087F60
 * packet:   pkt_02087F60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_InitDeliverArgInfo (os_argument.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   g_02151384   0x02151384  data
 */

#include "../include/G_OsArgumentBss.h"

typedef unsigned long long u64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;

typedef struct OSDeliverArgHeader {
    u64 titleId;
    u8 reserved1;
    u8 flag;
    u16 makerCode;
    u16 argBufferSize;
    u16 binarySize;
    u16 crc;
    u16 sysParam;
} OSDeliverArgHeader;

typedef struct OSDeliverArgInfo {
    OSDeliverArgHeader header;
    u8 buf[748];
} OSDeliverArgInfo;

/* os_argument.o .bss from 0x02151384, addressed from one pool word: sPtr
   (a cursor into the argument buffer), the buffer state and the buffer. */
typedef struct OsArgumentBss OsArgumentBss;

extern struct OsArgumentBss g_02151384;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize)
{
    g_02151384.sBufferPtr = info;
    MI_CpuFill8(info, 0, sizeof(OSDeliverArgInfo));
    g_02151384.sBufferState = 3;

    ((OSDeliverArgInfo *)g_02151384.sBufferPtr)->header.argBufferSize = (u16)(748 - binSize);
    ((OSDeliverArgInfo *)g_02151384.sBufferPtr)->header.binarySize = 0;

    g_02151384.sPtr = ((OSDeliverArgInfo *)g_02151384.sBufferPtr)->buf;
    ((OSDeliverArgInfo *)g_02151384.sBufferPtr)->buf[0] = 0;
    ((u8 *)g_02151384.sPtr)[1] = 0;
}
