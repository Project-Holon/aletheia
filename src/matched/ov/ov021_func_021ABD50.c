/*
 * function: FIELD_EFFECT_Create
 * address:  0x021ABD50
 * packet:   pkt_ov021_021ABD50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   COMM_PLAYER_SUPPORT_GetInfoCode  0x0202E83C  thumb
 *   FIELDMAP_GetAreaData  0x02188D58  thumb  ov021
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   FIELD_EFFECT_InitResourceTable  0x021ABEAC  thumb  ov021
 *   FIELDMAP_GetEffectBbdAct  0x02188C88  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 */
#include "../include/Obj04240.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x; int y; int z; } V;

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
struct Sub020140BCObj;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 ZONEDATA_GetAreaId(u32 id);
extern void *FIELDMAP_GetGameSystem(void *p);
extern int COMM_PLAYER_SUPPORT_GetInfoCode(void *a0);
extern u32 FIELDMAP_GetAreaData(u8 *p);
extern u8 ZONEDATA_GetAreaInnerOuter(struct Sub020140BCObj *p);
extern void FIELD_EFFECT_InitResourceTable(char *p);
extern u32 FIELDMAP_GetEffectBbdAct(u8 *p);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern void func_0204EDBC(u8 *dst, u8 val);
struct Blk3;
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_0204EDB0(u8 *dst, u8 *src);
extern char d_021DE018[];
extern V d_021D8F04;

char *FIELD_EFFECT_Create(int a, int b, u16 c)
{
    char *p;
    int h;
    V v;
    u8 z;

    p = (char *)func_02030734(c, 0x28, 1, d_021DE018, 0x7e);
    ((struct Obj04240 *)p)->f0 = b;
    ((struct Obj04240 *)p)->f4 = c;
    ((struct Obj04240 *)p)->f8 = a;
    ((struct Obj04240 *)p)->fC = (int)func_020490F4(0x4b, c);
    ZONEDATA_GetAreaId(FIELDMAP_GetZoneId((u8 *)a));
    ((struct Obj04240 *)p)->f16 = COMM_PLAYER_SUPPORT_GetInfoCode(FIELDMAP_GetGameSystem((void *)a));
    ((struct Obj04240 *)p)->f17 = ZONEDATA_GetAreaInnerOuter((struct Sub020140BCObj *)FIELDMAP_GetAreaData((u8 *)a));
    FIELD_EFFECT_InitResourceTable(p);
    h = BILLBOARD_ACT_GetBoard((u32 *)FIELDMAP_GetEffectBbdAct((u8 *)(((struct Obj04240 *)p)->f8)));
    func_0204EDBC((u8 *)h, 0);
    v = d_021D8F04;
    func_0204ED70((u8 *)h, (struct Blk3 *)(&v));
    z = 0;
    func_0204EDB0((u8 *)h, &z);
    return p;
}
