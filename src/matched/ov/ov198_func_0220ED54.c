/*
 * function: B_PLIST_DRAW_LayoutMoveDetailPage
 * address: 0x0220ED54
 * packet: pkt_ov198_0220ED54
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD6 lane16): EXACT. The 0x1ebc call is written in each arm of the idx if/else (tail-merged), so the
 *   0x1ED8 pool word stays CSE-live into it; the 0x1F58/0x1F5C read is a ternary of two loads; rec + k*8 + 0x31 as pointer adds.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SwapActorPair 0x0220E9A0 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   B_PLIST_DRAW_TransferCharacterToggle 0x0220E8B4 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D60 0x02211D60 data a2
 *   d_02211D88 0x02211D88 data a2
 *   d_02211D58 0x02211D58 data a2
 *   d_02211D48 0x02211D48 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {u8 low:6;u8 bit:1;u8 high:1;} Flag;
typedef struct {Pair first,second;short pad[4];Pair third;short pad2[4];Pair fourth;short pad3[8];Pair fifth;} Table1;
extern const Table1 d_02211D34;
extern const Pair d_02211D60;
extern const Pair d_02211D88;
extern const Pair d_02211D58;
extern const Pair d_02211D48;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,u32);
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SwapActorPair(char *,u8 *,const Pair *);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_TransferCharacterToggle(char *,int,int,int);
void B_PLIST_DRAW_LayoutMoveDetailPage(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    int idx;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fifth;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D60));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,&d_02211D88);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if (((Flag *)(p+0x2175))->bit==0) {
        idx=(*(u8 **)p)[0x4b]+0x22;
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D58);
    } else {
        idx=(*(u8 **)p)[0x4b]+0x1d;
        B_PLIST_DRAW_PlaceActor(*(u8 **)(p+idx*4+0x1ebc),(u32)&d_02211D58);
    }
    B_PLIST_DRAW_PlaceActor(((Flag *)(p+0x2175))->high==0?((u8 **)p)[0x7d6]:((u8 **)p)[0x7d7],(u32)&d_02211D48);
    B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,*(rec+(*(u8 **)p)[0x4b]*8+0x31));
}
