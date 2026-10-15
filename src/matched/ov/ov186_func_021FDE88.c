/*
 * function: BR_UTIL_EffectFlyIn
 * address: 0x021FDE88
 * packet: pkt_ov186_021FDE88
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_InitSpiral 0x021FE3B4 thumb ov186
 *   BR_UTIL_StepSpiral 0x021FE3E4 thumb ov186
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
typedef struct { int x,y; } Pair;
typedef struct { short x,y; } ShortPair;
typedef struct { int x,y;char pad8[4];int heap;char pad10[8];char record[6][32];char padD8[0x120];int handles[12];int timer; } Motion;
struct Obj;
typedef unsigned short u16;
typedef unsigned char  u8;
struct Pair;
extern int BR_UTIL_InitSpiral(u8 *p, const struct Pair *origin, u16 a, u16 b, int duration);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_AddActorSurfacePos(int,ShortPair *,unsigned short);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int BR_UTIL_StepSpiral(char *p, int *out, int step);
void BR_UTIL_EffectFlyIn(int unused,int *state,Motion *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            BR_UTIL_InitSpiral((u8 *)p->record[i],(const struct Pair *)p,15,(i*0xFFFF)/6,90);
            CLACT_SetActorDrawEnable((struct Obj *)p->handles[i],1);
        }
        GFL_USE_PlaySeDefaultVolume(0x705);
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            BR_UTIL_StepSpiral(p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        break;
    }
}
