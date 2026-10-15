/*
 * file:     os_application_jump.c
 * function: OSi_InitPrevTitleId
 * address:  0x020883D4
 * packet:   pkt_020883D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_InitPrevTitleId (os_application_jump.o)
 *
 * symbols:
 *   OS_InitDeliverArgInfo         0x02087F60  arm
 *   OS_DecodeDeliverArg           0x0208806C  arm
 *   OS_GetTitleIdFromDeliverArg   0x0208812C  arm
 *   OSi_SearchTitleIdFromList     0x0273131C  arm
 *   OS_EncodeDeliverArg           0x02087FBC  arm
 *   OS_SetDeliverArgStateInvalid  0x02088118  arm
 *   s_prevTitleId                 0x02732F9C  data
 */

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
typedef struct OsArgumentBss {
    u8 *sPtr;
    u32 sBufferState;
    OSDeliverArgInfo *sBufferPtr;
} OsArgumentBss;

extern OsArgumentBss g_02151384;

typedef signed char s8;
typedef long s32;

extern void OS_InitDeliverArgInfo(OSDeliverArgInfo *info, int binSize);
extern s32 OS_DecodeDeliverArg(void);
extern u64 OS_GetTitleIdFromDeliverArg(void);
extern u64 OSi_SearchTitleIdFromList(u64 titleId, u64 mask);
extern s32 OS_EncodeDeliverArg(void);
extern void OS_SetDeliverArgStateInvalid(void);
extern u64 s_prevTitleId;

void OSi_InitPrevTitleId(void)
{
    OSDeliverArgInfo deliverArgInfo;

    OS_InitDeliverArgInfo(&deliverArgInfo, 0);
    if (OS_DecodeDeliverArg() == 0) {
        s_prevTitleId = OS_GetTitleIdFromDeliverArg();
    }

    if ((s_prevTitleId != 0 && OSi_SearchTitleIdFromList(s_prevTitleId, (u64)-1) == 0)
        || (s8)(s_prevTitleId >> 24) == '0' || (s8)(s_prevTitleId >> 24) == '1'
        || (s8)(s_prevTitleId >> 24) == '2' || (s8)(s_prevTitleId >> 24) == '3'
        || (s8)(s_prevTitleId >> 24) == '4') {
        s_prevTitleId = 0;
        OS_InitDeliverArgInfo(&deliverArgInfo, 0);
        (void)OS_EncodeDeliverArg();
    } else {
        OS_SetDeliverArgStateInvalid();
    }
}
