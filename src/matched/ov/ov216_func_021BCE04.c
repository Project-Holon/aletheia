/*
 * function: func_021BCE04
 * address: 0x021BCE04
 * packet: pkt_ov216_021BCE04
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetDetailsType 0x02165DAC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsMonsNo 0x02165DF0 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsTrainerNo 0x02165DBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetZoneId 0x02165D28 thumb ov010
 */
struct Bits;
extern unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetZoneId(const struct Bits *);
typedef unsigned short u16;
typedef unsigned int   u32;
struct WordSet;
extern u32 func_02013E4C(u32 id);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F104(struct WordSet *p, u32 i, u32 a);
extern void func_0201F134(struct WordSet *p, u32 i, u32 v);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
void func_021BCE04(void *p,void *q)
{
    switch(GAME_BEACON_ACCESSOR_GetDetailsType(p)) {
    case 0: case 1:
        func_0201EE60(q,0,GAME_BEACON_ACCESSOR_GetDetailsMonsNo(p)); break;
    case 2: {
        unsigned a=GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(p);
        func_0201F104(q,0,a); func_0201F134(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=GAME_BEACON_ACCESSOR_GetZoneId(p);
        if(a>=427) a=317;
        func_0201F158(q,0,func_02013E4C(a)); break;
    }
    }
}
