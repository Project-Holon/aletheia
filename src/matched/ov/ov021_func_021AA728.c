/*
 * function: FIELD_ENCOUNT_UpdateStepWork
 * address:  0x021AA728
 * packet:   pkt_ov021_021AA728
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Pos { u16 x, y, z; u16 f06; u32 f08; };

extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

void FIELD_ENCOUNT_UpdateStepWork(struct Pos *p, void *q)
{
    void *o = FIELD_PLAYER_GetMmdl(q);

    if (p->f06 != 0) {
        if (p->f08 < 0xA000)
            p->f08++;
        return;
    }
    if (p->x != FLDMMDL_GetGridNowX(o) || p->y != FLDMMDL_GetGridNowY(o) || p->z != FLDMMDL_GetGridNowZ(o)) {
        p->f06 = 1;
        p->f08++;
    }
}
