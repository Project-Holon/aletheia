/*
 * function: ZENKOKU_ZUKAN_AWARD_SetupActorPos
 * address: 0x021B9D84
 * packet: pkt_ov222_021B9D84
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (final push G1L10): closed by a block-local table pointer `s16 *t` assigned after
 *   the two calls and read as t[0], t[1]. Earlier forms (pointer local at function top, late local
 *   with other types, byte-offset reads, int locals, pragmas) left the base and the first halfword
 *   in swapped registers (4 B).
 * symbols:
 *   func_02040618 0x02040618 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_021BA1D8 0x021BA1D8 data a2
 */
typedef unsigned char u8;
typedef signed short s16;
typedef struct {s16 x,y;} Pt;
extern char d_021BA1D8[];
extern void func_02040618(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void ZENKOKU_ZUKAN_AWARD_SetupActorPos(char*p)
{
    Pt pos;
    if(*(int*)(*(char**)(p+4)+4)==0){
        s16 *t;
        func_02040618(1,3,0x40);
        func_02040618(2,3,0x40);
        t=(s16*)d_021BA1D8;
        pos.x=t[0];
        pos.y=t[1]-0x40;
        CLACT_AddActorSurfacePos(*(void**)(p+0x54),(const struct Vec2 *)(&pos),0);
        *(u8*)(p+0x44)=0;
    }
}
