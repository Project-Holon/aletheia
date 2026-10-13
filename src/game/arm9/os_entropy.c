/*
 * file:     os_entropy.c
 * function: func_02088168
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

typedef struct OSSystemWork {
    u8 pad000[0x3C];
    u32 vblankCount;            /* +0x03C */
    u8 pad040[0xF4 - 0x40];
    u8 macAddress[6];           /* +0x0F4 */
    u8 pad0FA[0x1E8 - 0xFA];
    u32 w1E8;                   /* +0x1E8 */
    u32 w1EC;                   /* +0x1EC */
    u8 pad1F0[0x390 - 0x1F0];
    u32 w390;                   /* +0x390 */
    u16 h394;                   /* +0x394 */
    u16 pad396;
    u16 h398;                   /* +0x398 */
    u8 pad39A[0x3AA - 0x39A];
    u16 h3AA;                   /* +0x3AA */
    u16 h3AC;                   /* +0x3AC */
} OSSystemWork;

#define reg_GX_VCOUNT   (*(vu16 *)0x04000006)
#define reg_GX_GXSTAT   (*(vu32 *)0x04000600)
#define reg_PAD_KEYINPUT (*(vu16 *)0x04000130)

/* Read as an absolute address, not through the system-work pointer: the
   object forms its own base (0x02FFFC00 + 0x3A8) for this halfword. */
#define BUTTON_XY_BUF    (*(u16 *)0x02FFFFA8)

extern u16 OS_GetTickLo(void);
extern volatile u64 OSi_TickCounter;

void func_02088168(u32 *buffer)
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
    buffer[3] = w->w1E8;
    buffer[4] = w->w1EC;
    buffer[5] = ((u32)w->h394 << 16) ^ w->w390;
    buffer[6] = ((u32)w->h3AA << 16) | w->h3AC;
    buffer[7] = ((u32)w->h398 << 16) | (reg_PAD_KEYINPUT | BUTTON_XY_BUF);
}
