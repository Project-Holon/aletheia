/*
 * function: FLDMMDL_EndAcmd
 * address: 0x0216D480
 * packet: pkt_ov010_0216D480
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_CheckMoveBit 0x0216D57C thumb ov010
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 */

typedef unsigned int   u32;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
int FLDMMDL_EndAcmd(char *p)
{
    if (FLDMMDL_CheckMoveBit(p, 0x200) == 0) return 1;
    if (FLDMMDL_CheckMoveBit(p, 0x400) == 0) return 0;
    FLDMMDL_ClearMoveBit(p, 0x600);
    return 1;
}
