/*
 * function: FLDMMDL_MOVE_UpdateHeightIfRequested
 * address:  0x021630F4
 * packet:   pkt_021630F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateHeight(int a);

int FLDMMDL_MOVE_UpdateHeightIfRequested(int a0, int a1)
{
    int t4;

a1 = 1;
a1 = a1 << 0xc;
t4 = a0 + 0;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_02163100:
    if (a0 == 0) goto loc_0216310A;
loc_02163104:
a0 = t4 + 0;
    a0 = FLDMMDL_MOVE_UpdateHeight(a0);
loc_0216310A:
    return a0;}
