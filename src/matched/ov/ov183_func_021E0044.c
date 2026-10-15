/*
 * function: BR_CODEIN_CodeOpenPokeSearch
 * address: 0x021E0044
 * packet: pkt_ov183_021E0044
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   BR_POKESEARCH_Create 0x021FFBD4 thumb ov186
 *   BR_POKESEARCH_Open 0x021FFE5C thumb ov186
 *   BR_POKESEARCH_UpdatePrint 0x021FFE34 thumb ov186
 */
#include "../include/Obj04573.h"
#include "../include/Obj08315.h"
typedef unsigned short u16;
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern char *BR_POKESEARCH_Create(void *, void *, int, int, int, int, int, u16);
extern void BR_POKESEARCH_Open(char *);
extern unsigned BR_POKESEARCH_UpdatePrint(char *p);
void BR_CODEIN_CodeOpenPokeSearch(char *p, char *q)
{
    *(char * *)&((struct Obj04573 *)p)->f1C = BR_POKESEARCH_Create(ZUKAN_SAVE_GetFromGameData(((struct Obj08315 *)q)->f10), ((struct Obj08315 *)q)->f8, ((struct Obj08315 *)q)->f4, ((struct Obj04573 *)p)->f44, ((struct Obj08315 *)q)->f0, ((struct Obj04573 *)p)->f3C, ((struct Obj04573 *)p)->f40, ((struct Obj04573 *)p)->f54);
    BR_POKESEARCH_Open(*(char * *)&((struct Obj04573 *)p)->f1C);
    BR_POKESEARCH_UpdatePrint(*(char * *)&((struct Obj04573 *)p)->f1C);
}
