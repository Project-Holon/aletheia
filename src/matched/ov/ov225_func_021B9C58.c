/*
 * function: MANUAL_COMMON_CheckUnlocked
 * address: 0x021B9C58
 * packet: pkt_ov225_021B9C58
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009210 0x02009210 thumb
 *   func_020090E0 0x020090E0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 */
typedef unsigned char u8;
struct Big;
struct Sub02009210Obj;
struct Sub020090B0Obj;
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009210Obj *func_02009210(void *);
extern u8 func_020090E0(const struct Sub020090B0Obj *);
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned ZONEDATA_CheckEventFlag(void *,int);
int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save)
{
    int result=0;
    switch(kind) {
    case 0:result=1;break;
    case 1:
        if(func_020090E0((const struct Sub020090B0Obj *)func_02009210(GAME_DATA_GetSaveControl((struct Big *)save)))!=0)result=1;
        break;
    case 2:
        if(ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save),2400)!=0)result=1;
        break;
    }
    return result;
}
