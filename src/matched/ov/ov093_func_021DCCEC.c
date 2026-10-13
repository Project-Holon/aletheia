/*
 * unit: yes
 * function: HAND_TOKUSEI_UnnerveSkipBerry, HAND_TOKUSEI_AddUnnerve
 * address: 0x021DCCEC
 * packet: pkt_ov093_021DCCEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the by-value record begins in the fifth argument slot; the body
 * reads its halfword at +0 and byte at +4 using a common stack base.
 * symbols:
 *   BTL_EVENT_GetFactorPokeId 0x021D70AC thumb ov093
 *   BTL_MAIN_IsPokeSamePair 0x021B9A24 thumb ov093
 *   ITEM_IsBerry 0x020213C0 thumb
 *   gUnnerveHandlers 0x021F0AE8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 h0; u16 pad2; u8 b4; u8 pad5[3]; } Args;
extern u8 BTL_EVENT_GetFactorPokeId(u8 *);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern int ITEM_IsBerry(u32 a);
extern int gUnnerveHandlers;
int HAND_TOKUSEI_UnnerveSkipBerry(u8 *a,int b,int c,int d,Args e)
{
    if(c==5) {
        if(!BTL_MAIN_IsPokeSamePair(BTL_EVENT_GetFactorPokeId(a),e.b4)) {
            if(ITEM_IsBerry(e.h0)) return 1;
        }
    }
    return 0;
}
int *HAND_TOKUSEI_AddUnnerve(int *p) { *p=3; return &gUnnerveHandlers; }
