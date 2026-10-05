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
 *   func_020061E4 0x020061E4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02008554 0x02008554 thumb
 *   func_02039338 0x02039338 arm
 *   func_021DE6EC 0x021DE6EC thumb ov137
 *   func_0204B878 0x0204B878 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u8 func_02008550(const void *);
extern u8 func_02008554(const void *);
extern u16 func_02039338(void);
extern void func_021DE6EC(u8 *,u8 *,int,int,int);
extern void func_0204B878(void *,u16);
extern void func_0204B3DC(void *,u32);
extern void func_020061E4(u32);
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
            if (i==func_02039338()) {
                func_0204B878(*(void **)(p+i*4+0x9c),4);
            } else {
                func_021DE6EC((u8 *)p,*(u8 **)(p+0x114),i,b,a);
                func_0204B878(*(void **)(p+i*4+0x9c),4);
            }
            func_0204B3DC(*(void **)(p+i*4+0x9c),1);
            *(u32 *)(p+i*4+0x160)=2;
            flag=1;
            break;
        case 2: break;
        case 3:
            if(i==func_02039338()) {
                func_02008550(*(void **)(p+i*8+0x138));
                func_0204B878(*(void **)(p+i*4+0x9c),5);
            } else {
                func_0204B878(*(void **)(p+i*4+0x9c),5);
            }
            *(u32 *)(p+i*4+0x160)=0;
            break;
        }
    }
    if(flag) func_020061E4(0x676);
}
