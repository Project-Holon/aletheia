/*
 * file:     os_entropy.c
 * function: OS_GetLowEntropyData
 * address:  0x02088168
 * packet:   pkt_02088168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_GetLowEntropyData (os_entropy.o)
 *
 * symbols:
 *   OS_GetTickLo     0x02087170  arm
 *   OSi_TickCounter  0x02151338  data
 */

typedef unsigned long long u64;
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef volatile u32 vu32;
typedef volatile u16 vu16;

#include "os_system_work_types.h"

#define reg_GX_VCOUNT   (*(vu16 *)0x04000006)
#define reg_GX_GXSTAT   (*(vu32 *)0x04000600)
#define reg_PAD_KEYINPUT (*(vu16 *)0x04000130)

/* Read as an absolute address, not through the system-work pointer: the
   object forms its own base (0x02FFFC00 + 0x3A8) for this halfword. */
#define BUTTON_XY_BUF    (*(u16 *)0x02FFFFA8)

extern u16 OS_GetTickLo(void);
extern volatile u64 OSi_TickCounter;

void OS_GetLowEntropyData(u32 *buffer)
{
    u8 *macAddress;
    OSSystemWork *w;    /* not a DWARF local; keeps 0x02FFFC00 live across the call */
    {
        u16 vcount = reg_GX_VCOUNT;
        w = (OSSystemWork *)0x02FFFC00;
        macAddress = w->macAddress;
        buffer[0] = OS_GetTickLo() | (vcount << 16);
    }
    buffer[1] = (u32)OSi_TickCounter ^ ((u32)*(u16 *)(macAddress + 4) << 16);
    buffer[2] = w->vblankCount ^ ((u32)(OSi_TickCounter >> 32) ^ *(u32 *)macAddress);
    buffer[2] ^= reg_GX_GXSTAT;
    buffer[3] = w->systemCounterLow;
    buffer[4] = w->systemCounterHigh;
    buffer[5] = ((u32)w->clockCounterHigh << 16) ^ w->clockCounterLow;
    buffer[6] = ((u32)w->entropyCounterHigh << 16) | w->entropyCounterLow;
    buffer[7] = ((u32)w->inputCounterHigh << 16) | (reg_PAD_KEYINPUT | BUTTON_XY_BUF);
}
