/*
 * function: FLDMMDL_FreeAcmd
 * address: 0x0216D4B4
 * packet: pkt_ov010_0216D4B4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 *   FLDMMDL_SetAcmdCode 0x0216D7C0 thumb ov010
 *   FLDMMDL_SetAcmdSeq 0x0216D7C8 thumb ov010
 */

typedef unsigned int   u32;
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
typedef unsigned short u16;
extern void FLDMMDL_SetAcmdCode(void *p, u16 v);
extern void *FLDMMDL_SetAcmdSeq(void *p, u16 v);
void *FLDMMDL_FreeAcmd(char *p)
{
    FLDMMDL_ClearMoveBit(p, 0x600);
    FLDMMDL_SetAcmdCode(p, 0xff);
    return FLDMMDL_SetAcmdSeq(p, 0);
}
