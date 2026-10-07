/*
 * function: func_0208812C
 * address:  0x0208812C
 * packet:   pkt_0208812C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_GetTitleIdFromDeliverArg (os_argument.o)
 *
 * symbols:
 *   g_02151384  0x02151384  data
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

u64 func_0208812C(void)
{
    if (!(g_02151384.sBufferState & 1)) {
        return 0;
    }
    return ((OSDeliverArgInfo *)g_02151384.sBufferPtr)->header.titleId;
}
