/*
 * function: FIELD_COMM_ACTOR_SetMoveWork
 * address:  0x02194588
 * packet:   pkt_ov021_02194588
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void *FLDMMDL_GetMoveProcWork(void *p);

void FIELD_COMM_ACTOR_SetMoveWork(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 *p;

    p = FLDMMDL_GetMoveProcWork((void *)a);
    p[0] = b;
    p[1] = c;
    p[2] = d;
    p[3] = e;
}
