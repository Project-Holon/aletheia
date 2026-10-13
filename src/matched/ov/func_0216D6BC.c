/*
 * function: FLDMMDL_InitMoveCmdWork
 * address:  0x0216D6BC
 * packet:   pkt_0216D6BC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern int func_02082BCC();

void *FLDMMDL_InitMoveCmdWork(int a0, int a1, int a2)
{
    void *t4;
    int t5;

t5 = a1 + 0;
    t4 = FLDMMDL_GetMoveCmdWork((void *)a0);
loc_0216D6C4:
a1 = 0;
a2 = t5 + 0;
    a0 = func_02082BCC(t4, a1, a2);
loc_0216D6CE:
    return t4;}
