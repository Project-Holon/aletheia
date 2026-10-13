/*
 * function: INTRUDE_SUBDISP_CreateInfoIconActor
 * address:  0x0217DCFC
 * packet:   pkt_ov018_0217DCFC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_SUBDISP_IsInfoActive  0x0217F1E8  thumb  ov018
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   d_021836C4  0x021836C4  data  a4
 */

typedef unsigned short u16;

typedef struct { u16 a, b, c, d; } Rect;

typedef unsigned char  u8;
extern int INTRUDE_SUBDISP_IsInfoActive(u8 *p);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern const Rect d_021836C4;

void INTRUDE_SUBDISP_CreateInfoIconActor(int *p, void *a1)
{
    Rect r;
    int h;

    r = d_021836C4;
    h = INTRUDE_SUBDISP_IsInfoActive((u8 *)p);
    p[0xac / 4] = (int)CLACT_CreateActor((void *)p[0x54 / 4], p[5], p[2], p[6], &r, 0, 0x70);
    CLACT_SetActorDrawEnable((struct Obj *)p[0xac / 4], h);
}
