/*
 * function: FLDMMDL_SetStatusBitAlias
 * address:  0x0216DB98
 * packet:   pkt_0216DB98
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The first argument picks which of the pair of field setters
 * takes the shifted mask and the value.
 *
 * symbols:
 *   FLDMMDL_SetStatusBit   0x0216D548  thumb  ov010
 *   FLDMMDL_ClearStatusBit   0x0216D550  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);

int FLDMMDL_SetStatusBitAlias(void *a0, int a1)
{
    int a2;
    if (a1 == 1)
        return (int)FLDMMDL_SetStatusBit(a0, 0x800);

    return (int)FLDMMDL_ClearStatusBit(a0, 0x800);
}

