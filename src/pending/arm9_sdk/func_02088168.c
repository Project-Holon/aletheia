/*
 * function: func_02088168
 * address:  0x02088168
 * packet:   pkt_02088168
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      OS_GetLowEntropyData (os_entropy.o)
 *
 * notes:    draft (DIFF, 77 bytes).  VCOUNT is now read into a callee-saved
 *           register before OS_GetTickLo as in the original.  Remaining
 *           residue: the original loads the 0x02FFFC00 system-work base into
 *           r4 before the call and keeps it across it (buffer in r5, VCOUNT
 *           in r6); this spelling loads the base after the call, which shifts
 *           every register.  Direct field access (no macAddress pointer)
 *           reproduces the +0x300 rebasing but not the separate +0x3A8 base.
 *           OSi_TickCounter (0x02151338) now resolves (sole-ref), so an exact
 *           spelling would verify EXACT, not MATCH.  Permuter seed 13203,
 *           400 rounds: 73 bytes at best, no structural gain.
 *
 * symbols:
 *   OS_GetTickLo     0x02087170  arm
 *   OSi_TickCounter  0x02151338  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

typedef unsigned long long u64;

extern u16 OS_GetTickLo(void);
extern volatile u64 OSi_TickCounter;

typedef struct OSiSysWork {
    u8 rsv0[0x3C];
    u32 w3C;
    u8 rsv1[0xF4 - 0x40];
    u32 wF4;
    u16 hF8;
    u8 rsv2[0x1E8 - 0xFA];
    u32 w1E8;
    u32 w1EC;
    u8 rsv3[0x390 - 0x1F0];
    u32 w390;
    u8 macAddress[0x3AE - 0x394];
} OSiSysWork;

void func_02088168(u32 *buffer)
{
    OSiSysWork *sw = (OSiSysWork *)0x02FFFC00;
    u8 *macAddress;

    {
        u16 vc = *(volatile u16 *)0x04000006;
        buffer[0] = (u32)((vc << 16) | OS_GetTickLo());
    }
    buffer[1] = (u32)(sw->hF8 << 16) ^ (u32)OSi_TickCounter;
    buffer[2] = sw->w3C ^ ((u32)(OSi_TickCounter >> 32) ^ sw->wF4);
    buffer[2] ^= *(volatile u32 *)0x04000600;
    buffer[3] = sw->w1E8;
    buffer[4] = sw->w1EC;
    macAddress = sw->macAddress;
    buffer[5] = sw->w390 ^ (u32)(*(u16 *)macAddress << 16);
    buffer[6] = (u32)((*(u16 *)(macAddress + 0x16) << 16) | *(u16 *)(macAddress + 0x18));
    buffer[7] = (u32)((*(u16 *)(macAddress + 4) << 16) | (*(volatile u16 *)0x04000130 | *(u16 *)(macAddress + 0x14)));
}
