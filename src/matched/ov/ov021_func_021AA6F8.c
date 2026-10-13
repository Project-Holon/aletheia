/*
 * function: FIELD_ENCOUNT_ResetStepWork
 * address:  0x021AA6F8
 * packet:   pkt_ov021_021AA6F8
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
 *   MI_CpuFill8  0x02082BCC  arm
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
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

void FIELD_ENCOUNT_ResetStepWork(struct Pos *p, void *q)
{
    void *o = FIELD_PLAYER_GetMmdl(q);

    MI_CpuFill8(p, 0, sizeof(*p));
    p->x = FLDMMDL_GetGridNowX(o);
    p->y = FLDMMDL_GetGridNowY(o);
    p->z = FLDMMDL_GetGridNowZ(o);
}
