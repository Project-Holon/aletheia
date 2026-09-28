/*
 * function: func_0205F8A0
 * address:  0x0205F8A0
 * packet:   pkt_0205F8A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      getSlotInfo (libncfg.TWL.HYB.a backup.o)
 *
 * symbols:
 *   NCFG_GetFormatVersion 0x0205F700 arm
 *   BaseAddress           0x020A813C data a4
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef signed long   s32;

extern u8  NCFG_GetFormatVersion(void);
extern u32 BaseAddress;

int func_0205F8A0(s32 index, u32 *address, u32 *size)
{
    switch (index) {
    case 0:
    case 1:
    case 2:
    case 3:
        *address = BaseAddress + index * 0x100;
        *size = 0x100;
        return 1;
    case 0x11:
    case 0x12:
    case 0x13:
        if (NCFG_GetFormatVersion() < 0x20) {
            *address = (u32)-1;
            *size = 0;
            return 0;
        }
        *address = BaseAddress - 0x600 + (index - 0x11) * 0x200;
        *size = 0x200;
        return 1;
    default:
        *address = (u32)-1;
        *size = 0;
        return 0;
    }
}
