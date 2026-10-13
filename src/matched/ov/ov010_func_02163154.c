/*
 * function: FLDMMDL_MOVE_ProcMoveStartSecond
 * address: 0x02163154
 * packet: pkt_ov010_02163154
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x02163186 before FLDMMDL_MOVE_ProcMoveEnd.
 * symbols:
 *   FLDMMDL_CheckMoveBit 0x0216D57C thumb ov010
 *   FLDMMDL_MOVE_AttrProcJumpStart 0x021632F0 thumb ov010
 *   FLDMMDL_MOVE_AttrProcMoveStartSecond 0x02163288 thumb ov010
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_MOVE_AttrProcJumpStart(int a0);
extern void FLDMMDL_MOVE_AttrProcMoveStartSecond(int a0);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);
void FLDMMDL_MOVE_ProcMoveStartSecond(char *p)
{
    if (FLDMMDL_CheckMoveBit(p, 0x80)) FLDMMDL_MOVE_AttrProcJumpStart((int)p);
    else if (FLDMMDL_CheckMoveBit(p, 0x20)) FLDMMDL_MOVE_AttrProcMoveStartSecond((int)p);
    FLDMMDL_ClearMoveBit(p, 0xa0);
}
