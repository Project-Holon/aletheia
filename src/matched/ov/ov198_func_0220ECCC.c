/*
 * function: B_PLIST_DRAW_LayoutMoveListPage
 * address: 0x0220ECCC
 * packet: pkt_ov198_0220ECCC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: the start pair is a struct field of a const table extern
 *   (`d_02211D34.item`, +0x3C), as the twin 0220EC2C reads `.third`; the
 *   element form `d_02211D34[15]` schedules the lsls/ldr-pool pair before the
 *   halfword copy (12 bytes). 0x02211D6C is d_02211D68's second pair (EC2C's
 *   pool names 0x02211D68); a separate d_02211D6C extern has no witness.
 *   The (char *) and (const u8 *) casts on p keep p + i*4 from being CSE'd
 *   into one register, as in EC2C.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SwapActorPair 0x0220E9A0 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   B_PLIST_MAIN_SyncMoveActors 0x0220F060 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D68 0x02211D68 data a2
 *   d_02211D78 0x02211D78 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
struct Vec2;
typedef struct {u8 pad[0x3C];Pair item;} Table1;
extern const Table1 d_02211D34;
typedef struct {Pair first,second,third,last;} Table2;
extern const Table2 d_02211D68;
extern const Pair d_02211D78;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i);
extern void B_PLIST_DRAW_PlaceActor(u8 *p, u32 b);
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SwapActorPair(char *p, u8 *q, Pair *pos);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_MAIN_SyncMoveActors(u8 *p);
void B_PLIST_DRAW_LayoutMoveListPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i = B_PLIST_MAIN_GetOrderIndex(p, (*(u8 **)p)[0x20]);
    rec = p + 4 + i * 0x4c;
    pair = d_02211D34.item;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p + i * 4 + 0x1ed8), (u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec + 0x17))->kind, *(u8 **)((char *)p + i * 4 + 0x1ef0), (const struct Vec2 *)&d_02211D68.second);
    B_PLIST_DRAW_SwapActorPair((char *)p, rec, (Pair *)&d_02211D78);
    pair.x += 8;
    pair.y += 8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec + 0x1a), *(u8 **)((const u8 *)p + i * 4 + 0x1ebc), (const struct Vec2 *)&pair);
    B_PLIST_MAIN_SyncMoveActors(p);
}
