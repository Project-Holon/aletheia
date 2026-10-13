/*
 * function: FLDMMDL_MOVE_ProcMoveStartFirst
 * address: 0x02163130
 * packet: pkt_ov010_02163130
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_CheckMoveBit 0x0216D57C thumb ov010
 *   FLDMMDL_MOVE_StopAcmdWalkCodes 0x021641C8 thumb ov010
 *   FLDMMDL_MOVE_AttrProcMoveStartFirst 0x02163230 thumb ov010
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_MOVE_StopAcmdWalkCodes(void *a);
extern void FLDMMDL_MOVE_AttrProcMoveStartFirst(int a0);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
void FLDMMDL_MOVE_ProcMoveStartFirst(char *p)
{
    if (FLDMMDL_CheckMoveBit(p, 0x20)) {
        FLDMMDL_MOVE_StopAcmdWalkCodes(p);
        FLDMMDL_MOVE_AttrProcMoveStartFirst((int)p);
    }
    FLDMMDL_ClearMoveBit(p, 0xa0);
}
