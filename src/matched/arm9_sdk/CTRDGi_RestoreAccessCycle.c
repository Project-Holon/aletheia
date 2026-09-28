/*
 * function: CTRDGi_RestoreAccessCycle
 * address:  0x0209109C
 * packet:   pkt_0209109C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libctrdg ctrdg.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 */

typedef unsigned short u16;
typedef volatile u16 vu16;

typedef enum { MI_CTRDG_ROMCYCLE1_10 = 0, MI_CTRDG_ROMCYCLE1_8 = 1, MI_CTRDG_ROMCYCLE1_6 = 2, MI_CTRDG_ROMCYCLE1_18 = 3 } MICartridgeRomCycle1st;
typedef enum { MI_CTRDG_ROMCYCLE2_6 = 0, MI_CTRDG_ROMCYCLE2_4 = 1 } MICartridgeRomCycle2nd;

typedef struct CTRDGRomCycle {
    MICartridgeRomCycle1st c1;
    MICartridgeRomCycle2nd c2;
} CTRDGRomCycle;

#define reg_MI_EXMEMCNT (*(vu16 *)0x04000204)

static inline void MI_SetCartridgeRomCycle1st(MICartridgeRomCycle1st c1)
{
    reg_MI_EXMEMCNT = (u16)((reg_MI_EXMEMCNT & ~0xC) | (c1 << 2));
}
static inline void MI_SetCartridgeRomCycle2nd(MICartridgeRomCycle2nd c2)
{
    reg_MI_EXMEMCNT = (u16)((reg_MI_EXMEMCNT & ~0x10) | (c2 << 4));
}

void CTRDGi_RestoreAccessCycle(CTRDGRomCycle *r)
{
    MI_SetCartridgeRomCycle1st(r->c1);
    MI_SetCartridgeRomCycle2nd(r->c2);
}
