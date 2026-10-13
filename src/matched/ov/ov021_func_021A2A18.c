/*
 * function: WEATHER_TASK_InitBillboard
 * address:  0x021A2A18
 * packet:   pkt_ov021_021A2A18
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   FIELD_3DBG_LoadBillboardTexture  0x021A1698  thumb  ov021
 *   FIELD_3DBG_SetBillboardVisible  0x021A16D4  thumb  ov021
 *   FIELD_3DBG_SetBillboardPolygonId  0x021A16D8  thumb  ov021
 *   gWeatherBillboardTextureDesc     0x021EE710  data  a4
 *   d_021EE710b    0x021EE710  data  a4
 *
 * Note: the original loads the pool word for 0x021EE710 twice (once for the
 * memcpy dst and the 3rd argument, once for the byte-8 test); the second
 * name is an alias at the same address that stops the compiler CSEing them.
 */

typedef struct {
    char pad0[8];
    unsigned char b8;
    char pad9[3];
} Buf;

typedef struct {
    char pad0[4];
    int f4;
    int f8[2];
    int f10;
} Obj;

extern unsigned char gWeatherBillboardTextureDesc[12];
extern unsigned char d_021EE710b[12];

void MI_CpuCopy8(void *src, void *dst, int n);
int FIELD_3DBG_LoadBillboardTexture(unsigned int a, int b, void *c, int d);
typedef unsigned int   u32;
typedef unsigned char  u8;
void FIELD_3DBG_SetBillboardVisible(u8 *p, u32 v);
void FIELD_3DBG_SetBillboardPolygonId(u8 *p, u8 v);

void WEATHER_TASK_InitBillboard(Obj *o, int idx, void *p, void *src, unsigned short x)
{
    MI_CpuCopy8(src, gWeatherBillboardTextureDesc, 12);
    if (d_021EE710b[8] != 0x1f) {
        d_021EE710b[8] = 0x1f;
    }
    FIELD_3DBG_LoadBillboardTexture((unsigned int)p, o->f10, gWeatherBillboardTextureDesc, x);
    FIELD_3DBG_SetBillboardVisible(p, 0);
    FIELD_3DBG_SetBillboardPolygonId(p, 0x20);
    o->f8[idx] = 1;
}
