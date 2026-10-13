/*
 * function: SCRCMD_MSGWIN_GetBalloonSide
 * address:  0x021B0A40
 * packet:   pkt_ov021_021B0A40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct T { int a; int b; int c; } T;
typedef struct Q { int f0; int f4; int f8; } Q;

struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *t);

int SCRCMD_MSGWIN_GetBalloonSide(u32 a, Q *q)
{
    T t;
    int r = 2;

    FLDMMDL_GetPos((const struct Actor *)a, (struct VecFx32 *)&t);
    if (q->f8 < t.c)
        r = 1;
    return r;
}
