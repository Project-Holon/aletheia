/*
 * function: FLDMMDL_RAIL_LookAroundMoveBody
 * address:  0x0219EB4C
 * packet:   pkt_ov021_0219EB4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_RAIL_GetRandomTableEntry  0x0219EA10  thumb  ov021
 *   FLDMMDL_RAIL_GetRandomDirOfKind  0x0219EA24  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_RAIL_StoreNowLocation  0x0219EA78  thumb  ov021
 *   d_021D84AC     0x021D84AC  data  ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u8  pad[0xc];
    s16 cnt;
    u16 val;
} E;

extern u8 d_021D84AC[];

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FLDMMDL_RAIL_GetRandomTableEntry(u32 *a, int b);
extern u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32 a, u32 b);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern int FLDMMDL_RAIL_StoreNowLocation();

int FLDMMDL_RAIL_LookAroundMoveBody(u32 o)
{
    E *e;

    e = FLDMMDL_GetMoveProcWork((void *)o);
    e->cnt = e->cnt - 1;
    if (e->cnt <= 0) {
        e->cnt = FLDMMDL_RAIL_GetRandomTableEntry((u32 *)d_021D84AC, -1);
        FLDMMDL_SetDirDispCheckPause((u32)o, (u16)FLDMMDL_RAIL_GetRandomDirOfKind(e->val, 9));
    }
    return FLDMMDL_RAIL_StoreNowLocation(e, o);
}
