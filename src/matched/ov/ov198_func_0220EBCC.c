/*
 * function: B_PLIST_DRAW_LayoutMode1
 * address: 0x0220EBCC
 * packet: pkt_ov198_0220EBCC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a char cast only on the later resource access prevents CSE of
 * the base-plus-index sum, preserving the byte-offset spill across E7CC.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {u8 bytes[76];} Record;
extern const Pair d_02211D34;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,unsigned);
typedef unsigned int   u32;
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
void B_PLIST_DRAW_LayoutMode1(Record *records)
{
    u8 *p=(u8 *)records;
    int i;
    Pair pair;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    pair=d_02211D34;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(p+i*0x4c+0x1e),*(u8 **)((char *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
}
