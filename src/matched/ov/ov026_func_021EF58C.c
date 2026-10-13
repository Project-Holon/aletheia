/*
 * function: WEATHER_STORM_InitFastSideStreak
 * address:  0x021EF58C
 * packet:   pkt_ov026_021EF58C
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
 *   func_0204B92C  0x0204B92C  arm
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
extern void func_0204B92C(struct Obj *, u32);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);

void WEATHER_STORM_InitFastSideStreak(int a, s16 *b, s16 *c, int d)
{
    u32 r;
    s16 v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 24 + 0x50;
    c[3] = r % 24 + 0xE;
    c[4] = c[2] + b[11];
    c[5] = c[3] + b[12];
    v[0] = (r & 7) - 8;
    v[1] = r % 160 - 16;
    WEATHER_TASK_SetParticlePos(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    CLACT_SetActorAnimSeq((struct Obj *)d, 2);
    one = 1;
    func_0204B92C((struct Obj *)d, 1);
    CLACT_SetActorAutoAnimSpeed((struct Actor *)d, one << 13);
}
