/*
 * function: CHIHOU_ZUKAN_AWARD_SetupActorPos
 * address: 0x021B9CEC
 * packet: pkt_ov221_021B9CEC
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G1L9: EXACT. The table is read through a block-local short pointer, the same form as the twin ov222 021B9D84 (an integer address local also matched)
 *   and both halfwords are read through it; the plain extern field reads gave base r1 / x r2 (4 B off). Earlier DIFF tries
 *   (struct copy, short[2], const, pragmas, byte-offset casts, etc.) are superseded. Also unchanged 4 B this pass: brace
 *   initialiser, inline setter, int y temp, short x/y locals, d[0] array extern, struct pointer local, u16 local struct.
 *   Idiom: a pool word reloaded before every field access (u32 gb = (u32)&d_X, read through a cast) from the wave brief.
 * symbols:
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021BA140 0x021BA140 data a2
 */

#include "../include/G_Vec2.h"

struct Obj;
extern struct Vec2 d_021BA140;
typedef unsigned int   u32;
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void CHIHOU_ZUKAN_AWARD_SetupActorPos(char *p)
{
    if(*(unsigned *)(*(unsigned char **)(p+4)+4)==0) {
        struct Vec2 v;
        short *t;
        BG_SYS_ChangeScrollImmediate(1,3,0x40);
        BG_SYS_ChangeScrollImmediate(2,3,0x40);
        t=(short *)&d_021BA140;
        v.x=t[0];
        v.y=t[1]-64;
        CLACT_AddActorSurfacePos(*(struct Obj **)(p+0x54),&v,0);
        p[0x44]=0;
    }
}
