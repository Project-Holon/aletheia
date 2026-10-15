/*
 * function: WIFI_BSUBWAY_OpenCodeIn
 * address: 0x021D7278
 * packet: pkt_ov116_021D7278
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFI_BSUBWAY_GetTransferState 0x021D6A4C thumb ov116
 *   WIFI_BSUBWAY_GetDownloadResult 0x021D6A48 thumb ov116
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   gWifiBsubwayCodeInParam 0x021D8560 data ov116 a4
 *   gWifiBsubwayCodeInParamEx 0x021D8568 data ov116 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   ov129_id 0x81 data
 */
#include "../include/Obj13866.h"
#include "../include/Obj22623.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int WIFI_BSUBWAY_GetTransferState(unsigned char *p);
extern u16 WIFI_BSUBWAY_GetDownloadResult(u8 *);
struct IcaAnime;
struct Param;
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 a1, u32 a2, u32 a3, u32 *src);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 gWifiBsubwayCodeInParam[],gWifiBsubwayCodeInParamEx[],d_021DA62C[];
extern u8 ov129_id[];
void WIFI_BSUBWAY_OpenCodeIn(u8 *p,int a) {
    void *obj;
    gWifiBsubwayCodeInParam[2]=(u32)WIFI_BSUBWAY_GetTransferState(p+0xb74);
    obj=CODEIN_PARAM_Create(a,1,WIFI_BSUBWAY_GetDownloadResult(p+0xb74),3,gWifiBsubwayCodeInParamEx);
    ((struct Obj13866 *)p)->f1840=obj;
    GAMESYSTEM_CallProc(((struct Obj22623 *)(*(u8 * *)&((struct Obj13866 *)p)->f0))->f4,(u32)ov129_id,d_021DA62C,obj);
}
