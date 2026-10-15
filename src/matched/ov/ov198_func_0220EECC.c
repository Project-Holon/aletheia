/*
 * function: B_PLIST_DRAW_LayoutMode7
 * address: 0x0220EECC
 * packet: pkt_ov198_0220EECC
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: each bit-test if/else writes its 0220E7CC call per arm (tail merge keeps 0x1ed8 live); rec byte read as (rec+n*8)[0x31]
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   B_PLIST_DRAW_SetActorAnim 0x0220E974 thumb ov198
 *   B_PLIST_DRAW_SwapActorPair 0x0220E9A0 thumb ov198
 *   B_PLIST_DRAW_SetActorAnimByMode 0x0220EA30 thumb ov198
 *   B_PLIST_DRAW_TransferCharacterToggle 0x0220E8B4 thumb ov198
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D3C 0x02211D3C data a2
 *   d_02211D40 0x02211D40 data a2
 *   d_02211D5C 0x02211D5C data a2
 *   d_02211D90 0x02211D90 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {short x,y;} Pair;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
typedef struct {u8 low:6;u8 a:1;u8 b:1;} Fl;
typedef struct {char pad[0x1F58];u8 *a;u8 *b;} Q;
typedef struct {Pair first,second;short pad[4];Pair third;short pad2[6];Pair fourth;} Table1;
extern const Table1 d_02211D34;
extern const Pair d_02211D3C;
extern const Pair d_02211D40;
extern const Pair d_02211D5C;
extern const Pair d_02211D90;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern void B_PLIST_DRAW_PlaceActor(u8 *,u32);
struct Vec2;
extern void B_PLIST_DRAW_SetActorAnim(int mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_SwapActorPair(char *,u8 *,Pair *);
extern void B_PLIST_DRAW_SetActorAnimByMode(u32 mode, u8 *p, const struct Vec2 *q);
extern void B_PLIST_DRAW_TransferCharacterToggle(char *,int,int,int);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
void B_PLIST_DRAW_LayoutMode7(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    unsigned n;
    i=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.fourth;
    B_PLIST_DRAW_PlaceActor(*(u8 **)(p+i*4+0x1ed8),(u32)&pair);
    B_PLIST_DRAW_SetActorAnim(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D3C));
    B_PLIST_DRAW_SwapActorPair((char *)p,rec,(Pair *)&d_02211D90);
    pair.x+=8;
    pair.y+=8;
    B_PLIST_DRAW_SetActorAnimByMode(*(u16 *)(rec+0x1a),*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    if(((Fl *)(p+0x2175))->a==0) B_PLIST_DRAW_PlaceActor(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x22)*4+0x1ebc),(u32)&d_02211D40);
    else B_PLIST_DRAW_PlaceActor(*(u8 **)(p+((*(u8 **)p)[0x4b]+0x1d)*4+0x1ebc),(u32)&d_02211D40);
    if(((Fl *)(p+0x2175))->b==0) B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1F58),(u32)&d_02211D5C);
    else B_PLIST_DRAW_PlaceActor(*(u8 **)(p+0x1F5C),(u32)&d_02211D5C);
    n=(*(u8 **)p)[0x4b];
    if(n<4) B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,(rec+n*8)[0x31]);
    else B_PLIST_DRAW_TransferCharacterToggle((char *)p,0x27,0x16,WAZA_TOOL_GetParam(*(u16 *)(*(u8 **)p+0x26),2));
}
