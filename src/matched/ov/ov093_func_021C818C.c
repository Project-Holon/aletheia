/*
 * function: BTL_SERVER_FLOW_IsPokeEvolvable
 * address: 0x021C818C
 * packet: pkt_ov093_021C818C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   SHINKA_CHECK_GetRowParam 0x0201B718 thumb
 */
#include "../include/Obj13341.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
struct QF;
extern u16 BTL_POKEPARAM_GetSpecies(struct QF *p);
extern unsigned int SHINKA_CHECK_GetRowParam(void *, unsigned int, unsigned int, unsigned int);
int BTL_SERVER_FLOW_IsPokeEvolvable(u8 *p, int v) { unsigned int species; u16 i; species=BTL_POKEPARAM_GetSpecies((struct QF *)BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj13341 *)p)->f8,v)); for(i=0;i<7;i++) { if(SHINKA_CHECK_GetRowParam(((struct Obj13341 *)p)->f4A4,species,0,i)) return 1; } return 0; }
