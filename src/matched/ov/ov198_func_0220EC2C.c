/*
 * function: B_PLIST_DRAW_LayoutMode2
 * address: 0x0220EC2C
 * packet: pkt_ov198_0220EC2C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SwapActorPair 0x0220E9A0 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D68 0x02211D68 data a2
 *   d_02211D98 0x02211D98 data a2
 */
#include "../include/Obj10847.h"
#include "../include/Obj14560.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {Pair first,second;short pad[4];Pair third;} Table1;
typedef struct {Pair first;short pad[4];Pair last;} Table2;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
extern const Table1 d_02211D34;
extern const Table2 d_02211D68;
extern const Pair d_02211D98;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,unsigned);
typedef unsigned int   u32;
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SwapActorPair(char *,u8 *,Pair *);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
void B_PLIST_DRAW_LayoutMode2(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.third;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D68.first));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,(Pair *)&d_02211D98);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(((struct Obj14560 *)rec)->f1A,*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    B_PLIST_DRAW_SetActorAnimByMode(((struct Obj14560 *)rec)->f1A,*(u8 * *)&((struct Obj10847 *)p)->f1ED4,(const struct Vec2 *)((Pair *)&d_02211D34.second));
    B_PLIST_DRAW_PlaceActor(*(u8 * *)&((struct Obj10847 *)p)->f1F08,(unsigned)&d_02211D68.last);
}
