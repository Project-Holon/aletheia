/*
 * function: FLDMMDL_InitMoveProcWork
 * address:  0x0216D684
 * packet:   pkt_0216D684
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int func_02082BCC();

void *FLDMMDL_InitMoveProcWork(int a0, int a1, u32 a2, u32 a3)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = FLDMMDL_GetMoveProcWork((void *)a0);
loc_0216D68C:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D696:
    return t4;}
