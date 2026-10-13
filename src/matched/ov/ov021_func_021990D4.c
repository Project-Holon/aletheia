/*
 * function: FLDMMDL_ACMD_BounceMove
 * address:  0x021990D4
 * packet:   pkt_ov021_021990D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D4C1C     0x021D4C1C  data   a4
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
typedef struct { int w[10]; } T40;
extern T40 d_021D4C1C;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_BounceMove(u32 a)
{
    Vec v = { 0, 0, 0 };
    T40 t;
    int *p;
    int i;

    t = d_021D4C1C;
    p = FLDMMDL_GetMoveCmdWork((void *)a);
    i = p[0];
    if (i >= 10) {
        i = 9;
    }
    v.y = t.w[i];
    FLDMMDL_SetDrawOffset(a, &v);
    p[0] = p[0] + 1;
    if (p[0] >= 20) {
        FLDMMDL_IncAcmdSeq(a);
    }
    return 0;
}
