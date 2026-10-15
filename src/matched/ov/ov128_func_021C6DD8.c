/*
 * function: Wf2dmapFriend_SetActorDrawEnable
 * address: 0x021C6DD8
 * packet: pkt_ov128_021C6DD8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void Wf2dmapFriend_SetActorDrawEnable(u8 *p,u32 a) {int i; for(i=0;i<2;i++) CLACT_SetActorDrawEnable(*(void **)((u32)p+i*4+0x15c),a);}
