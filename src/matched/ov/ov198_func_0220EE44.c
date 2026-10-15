/*
 * function: B_PLIST_DRAW_LayoutMode6
 * address: 0x0220EE44
 * packet: pkt_ov198_0220EE44
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the copied Pair is a field of a struct-typed table (twin 0220EC2C's
 * Table1 shape, extended to offset 0x1c), not an indexed Pair array; the
 * array form hoists the 0x1ed8 resource load above the second strh.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SwapActorPair 0x0220E9A0 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   B_PLIST_MAIN_SyncMoveActors 0x0220F060 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D4C 0x02211D4C data a2
 *   d_02211D80 0x02211D80 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {Pair first,second;short pad[4];Pair third;short pad2[4];Pair fourth;} Table1;
extern const Table1 d_02211D34;
extern const Pair d_02211D4C;
extern const Pair d_02211D80;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,u32);
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SwapActorPair(char *,u8 *,Pair *);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_MAIN_SyncMoveActors(u8 *);
void B_PLIST_DRAW_LayoutMode6(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fourth;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D4C));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,(Pair *)&d_02211D80);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    B_PLIST_MAIN_SyncMoveActors(p);
}
