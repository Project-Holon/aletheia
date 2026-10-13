/*
 * function: FLDMMDL_ACMD_FallMove
 * address:  0x02198A8C
 * packet:   pkt_ov021_02198A8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_FallMove(u32 a)
{
    int *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    p[0] = p[0] + p[1];
    if (p[0] < 0) {
        p[0] = 0;
    }
    {
        Vec v = { 0, 0, 0 };
        v.y = p[0];
        FLDMMDL_SetDrawOffset(a, &v);
    }
    if (p[0] > 0) {
        return 0;
    }
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
