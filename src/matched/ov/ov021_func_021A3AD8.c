/*
 * function: FIELD_PLAYER_CORE_ChangeModel
 * address:  0x021A3AD8
 * packet:   pkt_ov021_021A3AD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_CORE_GetMmdl  0x021A3960  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_BLACT_ChangeObjCode  0x0219D208  thumb  ov021
 *   FLDMMDL_SysWaitBlActResLoad  0x0216CD88  thumb  ov010
 *   FIELD_PLAYER_CORE_GetSex  0x021A398C  thumb  ov021
 *   FIELD_PLAYER_GetObjCodeOfFormCode  0x021A31A4  thumb  ov021
 *   FLDMMDL_ChangeObjCode  0x0216E204  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned int  u32;

void *FIELD_PLAYER_CORE_GetMmdl(u8 *p);
void *FLDMMDL_GetMmdlSys(void *a0);
typedef unsigned short u16;
u16 FLDMMDL_GetObjCode(void *p);
void FLDMMDL_BLACT_ChangeObjCode(int a, unsigned int id);
int FLDMMDL_SysWaitBlActResLoad(int a0);
u32 FIELD_PLAYER_CORE_GetSex(u8 *p);
int FIELD_PLAYER_GetObjCodeOfFormCode(int i, int v);
void FLDMMDL_ChangeObjCode(char *a, u32 v);

void FIELD_PLAYER_CORE_ChangeModel(u8 *p, int a)
{
    void *h = FIELD_PLAYER_CORE_GetMmdl(p);
    u32 g = (u32)FLDMMDL_GetMmdlSys(h);
    int r = FLDMMDL_GetObjCode(h);

    if (a == 1 || a == 4 || r == 1 || r == 4) {
        FLDMMDL_BLACT_ChangeObjCode((int)h, a);
        FLDMMDL_SysWaitBlActResLoad(g);
        return;
    }
    FLDMMDL_ChangeObjCode(h, FIELD_PLAYER_GetObjCodeOfFormCode(FIELD_PLAYER_CORE_GetSex(p), 0));
    FLDMMDL_SysWaitBlActResLoad(g);
    FLDMMDL_BLACT_ChangeObjCode((int)h, a);
    FLDMMDL_SysWaitBlActResLoad(g);
}
