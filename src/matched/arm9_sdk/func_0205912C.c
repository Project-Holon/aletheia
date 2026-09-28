/*
 * function: func_0205912C
 * address:  0x0205912C
 * packet:   pkt_0205912C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CTRDG_IsBitID (libctrdg.TWL.HYB.a ctrdg.o)
 *
 * symbols:
 *   CTRDG_IsExisting  0x0205915C  arm
 *   CTRDGi_IsBitIDAtInit  0x02059194  arm
 */

typedef unsigned char u8;
typedef int BOOL;

extern BOOL CTRDG_IsExisting(void);
extern BOOL CTRDGi_IsBitIDAtInit(u8 bitID);

BOOL func_0205912C(u8 bitID)
{
    return (CTRDG_IsExisting() && CTRDGi_IsBitIDAtInit(bitID)) ? 1 : 0;
}
