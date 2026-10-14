/*
 * function: HALL_OF_FAME_MoveActorRelative
 * address: 0x021B7438
 * packet: pkt_ov180_021B7438
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Plain halfword assignment preserves the required promotion and late truncation.
 * symbols:
 *   HALL_OF_FAME_GetActorPos 0x021B7408 thumb ov180
 *   HALL_OF_FAME_MoveActorBy 0x021B73E4 thumb ov180
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct { s16 y,x; } Pair;
extern void HALL_OF_FAME_GetActorPos(u8 *,int,s16 *,s16 *);
extern void HALL_OF_FAME_MoveActorBy(char *p, int i, short x, short y);
void HALL_OF_FAME_MoveActorRelative(u8 *p,int n,int x,int y) { Pair s; HALL_OF_FAME_GetActorPos(p,n,&s.x,&s.y); s.x=s.x+x; s.y=s.y+y; HALL_OF_FAME_MoveActorBy((char *)p,n,s.x,s.y); }
