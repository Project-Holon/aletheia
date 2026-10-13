/*
 * function: func_021A8198
 * address:  0x021A8198
 * packet:   pkt_ov021_021A8198
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb  ov021
 *   FIELD_PLAYER_GetNogridLocationByDir  0x021A36C8  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 */

typedef struct V {
    int x;
    int y;
    int z;
} V;

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void *FIELD_NOGRID_MAPPER_GetRailMan(void *p);
extern int FIELD_PLAYER_GetNogridLocationByDir(u8 *p, u32 k, void *buf);
extern void FIELD_RAIL_GetLocationPos(void *p, int *in, V *out);

void func_021A8198(void *a, V *out)
{
    void *ctx;
    int k;
    void *h;
    V res;
    int in[2];

    ctx = FIELDMAP_GetFieldPlayer(a);
    k = FIELD_PLAYER_GetDirDisp(ctx);
    h = FIELD_NOGRID_MAPPER_GetRailMan((void *)FIELDMAP_GetNogridMapper(a));
    FIELD_PLAYER_GetNogridLocationByDir(ctx, k, in);
    FIELD_RAIL_GetLocationPos(h, in, &res);
    *out = res;
}
