/*
 * function: FLDMMDL_ACMD_FlyReadyMove
 * address:  0x02199F94
 * packet:   pkt_ov021_02199F94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_DRAW_GetBlactAnimeTypeB  0x0219FCC0  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern int FLDMMDL_DRAW_GetBlactAnimeTypeB(u32, u16 *, u16 *);
extern u16 FLDMMDL_GetObjCode(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_FlyReadyMove(u32 a)
{
    u16 *p;
    u16 v[2];
    p = FLDMMDL_GetMoveCmdWork((void *)a);
    if (FLDMMDL_DRAW_GetBlactAnimeTypeB(a, &v[1], &v[0]) != 1)
        return 0;
    p[0] = p[0] + 1;
    v[0] = v[0] - 1;
    if (FLDMMDL_GetObjCode((void *)a) == 0xDD && v[1] == 0 && *((u8 *)p + 2) != v[0]) {
        *((u8 *)p + 2) = v[0];
        switch (v[0]) {
        case 0:
            GFL_USE_PlaySeDefaultVolume(0x7E5);
            break;
        case 3:
            GFL_USE_PlaySeDefaultVolume(0x7E6);
            break;
        }
    }
    if (p[0] < 0x5F)
        return 0;
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
