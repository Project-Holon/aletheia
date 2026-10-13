/*
 * function: FLDMMDL_InitDrawProcWork
 * address:  0x0216D6D8
 * packet:   pkt_0216D6D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetDrawProcWork(void *p);
extern int MI_CpuFill8();

void *FLDMMDL_InitDrawProcWork(int a0, int a1)
{
    int a2;
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = FLDMMDL_GetDrawProcWork((void *)a0);
loc_0216D6E0:
a1 = 0;
a2 = t5 + 0;
    a0 = MI_CpuFill8(t4, a1, a2);
loc_0216D6EA:
    return t4;}
