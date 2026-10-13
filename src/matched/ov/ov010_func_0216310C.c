/*
 * function: FLDMMDL_MOVE_UpdateAttrIfRequested
 * address: 0x0216310C
 * packet: pkt_ov010_0216310C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x0216312E before FLDMMDL_MOVE_ProcMoveStartFirst.
 * symbols:
 *   FLDMMDL_CheckMoveBit 0x0216D57C thumb ov010
 *   FLDMMDL_MOVE_UpdateMapAttr 0x021640B0 thumb ov010
 *   FLDMMDL_OnMoveBitMoveStart 0x0216DA70 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateMapAttr(int p);
extern void FLDMMDL_OnMoveBitMoveStart(void *a0);
void FLDMMDL_MOVE_UpdateAttrIfRequested(char *p)
{
    if (FLDMMDL_CheckMoveBit(p, 0x800) != 0 && FLDMMDL_MOVE_UpdateMapAttr((int)p) == 1)
        FLDMMDL_OnMoveBitMoveStart(p);
}
