/*
 * function: FIELD_PLAYER_GetGridPosInDir
 * address:  0x021A330C
 * packet:   pkt_ov021_021A330C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELDMAP_GetMoveKind(u8 *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);

void FIELD_PLAYER_GetGridPosInDir(unsigned char **a, u32 b, s16 *c, s16 *d, s16 *e)
{
    void *t = FIELD_PLAYER_GetMmdl((unsigned char *)a);

    if (FIELDMAP_GetMoveKind(a[0]) == 0) {
        *c = FLDMMDL_GetGridNowX(t);
        *d = FLDMMDL_GetGridNowY(t);
        *e = FLDMMDL_GetGridNowZ(t);
        *c = *c + FLDMMDL_MOVE_GetDirAddGridX(b);
        *e = *e + FLDMMDL_MOVE_GetDirAddGridZ(b);
    }
}
