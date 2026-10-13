/*
 * function: WEATHER_STORM_InitFallingStreak
 * address:  0x021EF454
 * packet:   pkt_ov026_021EF454
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   WEATHER_TASK_SetParticlePos  0x021A26C4  thumb  ov021
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern int WEATHER_TASK_SetParticlePos(u32 a, u32 b);
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

void WEATHER_STORM_InitFallingStreak(int a, s16 *b, s16 *c, int d)
{
    u32 r;
    s16 v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 43 + 0x56;
    c[3] = (r % 43) * 2 + 0x102;
    v[0] = r % 336 - 0x50;
    v[1] = r % 40 - 0x50;
    WEATHER_TASK_SetParticlePos(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    CLACT_SetActorAnimSeq((struct Obj *)d, 1);
    one = 1;
    CLACT_SetActorAutoAnim((struct Obj *)d, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)d, one << 13);
}
