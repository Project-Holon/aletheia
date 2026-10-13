/*
 * function: FLDMMDL_CheckEndAcmd
 * address:  0x0216D454
 * packet:   pkt_0216D454
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);

int FLDMMDL_CheckEndAcmd(int a0, u32 a1, u32 a2, u32 a3)
{
    int t4;
    int t5;

t4 = 2;
t4 = t4 << 8;
a1 = t4 + 0;
t5 = a0 + 0;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_0216D462:
    if (a0 != 0) goto loc_0216D46A;
loc_0216D466:
a0 = 1;
    return a0;
loc_0216D46A:
a0 = t5 + 0;
a1 = t4 << 1;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_0216D472:
    if (a0 == 0) goto loc_0216D47A;
loc_0216D476:
a0 = 1;
    return a0;
loc_0216D47A:
a0 = 0;
    return a0;}
