/*
 * function: func_021DE5D0
 * address: 0x021DE5D0
 * packet: pkt_ov137_021DE5D0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: final push 2026-10-05 G9L5. Closed from DIFF216. Causes: (1) the hoisted-constant chains
 *   (base 0x138) need the duplicated tails: the then and else arms of `if (i == f())` each hold the
 *   4B878 call (cross-jump leaves `bne; b`), so no offset enum or local is needed, plain literals;
 *   (2) in case 1 only the 4B878 call is repeated, 3DC, the state store and flag follow the join;
 *   (3) the parameter is a non-const pointer (const reorders the outgoing stack argument load).
 *   Callee func_021DE6EC takes a fifth unused stack argument in the caller (stale prototype).
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   func_021DE6EC 0x021DE6EC thumb ov137
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void func_021DE6EC(u8 *,u8 *,int,int,int);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void GFL_USE_PlaySeDefaultVolume(u32);
void func_021DE5D0(u8 *p)
{
    int i;
    int flag = 0;
    u8 a, b;
    for (i = 0; i < 5; i++) {
        switch(*(u32 *)(p+i*4+0x160)) {
        case 0: break;
        case 1:
            a=func_02008550(*(void **)(p+i*8+0x138));
            b=func_02008554(*(void **)(p+i*8+0x138));
            if (i==GFL_NET_SYSTEM_GetCurrentAid()) {
                CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x9c),4);
            } else {
                func_021DE6EC((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x9c),4);
            }
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x9c),1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==GFL_NET_SYSTEM_GetCurrentAid()) {
                func_02008550(*(void **)(p+i*8+0x138));
                CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x9c),5);
            } else {
                CLACT_SetActorAnimSeq(*(void **)(p+i*4+0x9c),5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) GFL_USE_PlaySeDefaultVolume(0x676);
}
