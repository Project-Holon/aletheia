/*
 * function: WIFI_BSUBWAY_GRAPHIC_SetupTextParam
 * address: 0x021D72D0
 * packet: pkt_ov116_021D72D0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   d_021D8574 0x021D8574 data a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   ov129_id 0x81 data
 */
#include "../include/Obj13867.h"
#include "../include/Obj22624.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct IcaAnime;
struct Param;
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 d_021D8574[], d_021DA62C[];
extern u8 ov129_id[];
void WIFI_BSUBWAY_GRAPHIC_SetupTextParam(u8 *p, u32 heap)
{
    void *obj;
    obj = CODEIN_PARAM_Create(heap, 2, 10, 2, d_021D8574);
    ((struct Obj13867 *)p)->f1840 = obj;
    GAMESYSTEM_CallProc(((struct Obj22624 *)(*(u8 * *)&((struct Obj13867 *)p)->f0))->f4, (u32)ov129_id, d_021DA62C, obj);
}
