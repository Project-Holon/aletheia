/*
 * function: FLDMMDL_RestartMoveTcb
 * address: 0x0216D244
 * packet: pkt_ov010_0216D244
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_InitMoveProcList 0x0216D230 thumb ov010
 *   FLDMMDL_AddMoveTcb 0x0216DF64 thumb ov010
 *   FLDMMDL_SetMoveBit 0x0216D568 thumb ov010
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int FLDMMDL_InitMoveProcList(int a0);
extern void FLDMMDL_AddMoveTcb(u8 *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
void FLDMMDL_RestartMoveTcb(u32 v, u8 *p)
{
    FLDMMDL_InitMoveProcList((int)p);
    FLDMMDL_AddMoveTcb(p, v);
    FLDMMDL_SetMoveBit(p, 0x1820);
}
