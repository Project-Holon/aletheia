/*
 * function: FLDMMDL_LoadMmdlObjCodeParam
 * address:  0x0216E39C
 * packet:   pkt_0216E39C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_LoadObjCodeParam  0x0216E2E8  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_ClearStatusBit();
extern int FLDMMDL_LoadObjCodeParam();
extern int FLDMMDL_SetStatusBit();

void FLDMMDL_LoadMmdlObjCodeParam(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;

t6 = a2 + 0;
t5 = a0 + 0;
t4 = a1 + 0;
a0 = t6 + 0;
a1 = 1;
    a0 = FLDMMDL_ClearStatusBit(a0, a1);
loc_0216E3AC:
a2 = t6 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
a2 = a2 + 0xe4;
    a0 = FLDMMDL_LoadObjCodeParam(a0, a1, a2);
loc_0216E3B8:
a0 = t6 + 0;
a1 = 1;
    a0 = FLDMMDL_SetStatusBit(a0, a1);
loc_0216E3C0:
    return;}
