/*
 * function: UNION_SUBDISP_CheckTouch
 * address:  0x021F0584
 * packet:   pkt_ov031_021F0584
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   UNION_SUBDISP_SelectAppeal  0x021F0628  thumb  ov031
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { s16 x, y; } Pt;

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
struct Actor;
struct PtS;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void UNION_SUBDISP_SelectAppeal(char *p, int sel);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

int UNION_SUBDISP_CheckTouch(int *p, u8 *flag)
{
    u32 w;
    u32 h;
    Pt t;
    int i;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    if (TOUCHPANEL_GetPointTrg(&w, &h) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)p[6 + i], (struct PtS *)&t, 1);
        y0 = t.y - 10;
        y1 = t.y + 10;
        x1 = t.x + 10;
        x0 = t.x - 10;
        if (x0 < w && x1 > w && y0 < h && y1 > h) {
            if (i == 0 && flag != 0) {
                flag[0x282E] = 1;
                return 0;
            }
            UNION_SUBDISP_SelectAppeal((char *)p, i);
            GFL_USE_PlaySeDefaultVolume(0x54B);
            return 1;
        }
    }
    return 0;
}
