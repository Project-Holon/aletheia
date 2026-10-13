/*
 * function: FLDMMDL_SetLocalAcmd
 * address:  0x0216D438
 * packet:   pkt_0216D438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetAcmdCode  0x0216D7C0  thumb  ov010
 *   FLDMMDL_SetAcmdSeq  0x0216D7C8  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_SetAcmdCode();
extern void *FLDMMDL_SetAcmdSeq(void *p, u16 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_SetLocalAcmd(char *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)FLDMMDL_SetAcmdCode(a0, a1);
loc_0216D440:
a0 = (char *)(t4 + 0);
a1 = 0;
    a0 = (char *)FLDMMDL_SetAcmdSeq(a0, a1);
loc_0216D448:
a1 = 1;
a0 = (char *)(t4 + 0);
a1 = a1 << 0xa;
    a0 = (char *)FLDMMDL_ClearMoveBit(a0, a1);
loc_0216D452:
    return;}
