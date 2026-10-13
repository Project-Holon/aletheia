/*
 * function: FLDMMDL_ExecMove
 * address:  0x0216D38C
 * packet:   pkt_0216D38C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 28 compiled 26
 *
 * symbols:
 *   FLDMMDL_UpdateMove  0x0216D28C  thumb  ov010
 *   FLDMMDL_CheckStatusBitUse  0x0216DA30  thumb  ov010
 *   FLDMMDL_UpdateDraw  0x0216D3B4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_UpdateMove();
extern int FLDMMDL_CheckStatusBitUse();
extern int FLDMMDL_UpdateDraw(int a0);

void FLDMMDL_ExecMove(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_UpdateMove(a0);
loc_0216D394:
a0 = t4 + 0;
    a0 = FLDMMDL_CheckStatusBitUse(a0);
loc_0216D39A:
    if (a0 != 1) goto loc_0216D3A4;
loc_0216D39E:
a0 = t4 + 0;
    a0 = FLDMMDL_UpdateDraw(a0);
loc_0216D3A4:
    return;}
