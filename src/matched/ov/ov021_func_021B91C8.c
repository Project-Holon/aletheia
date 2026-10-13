/*
 * function: FIELD_RAIL_WORK_GetSpotCamera
 * address:  0x021B91C8
 * packet:   pkt_ov021_021B91C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gRailDefaultCamera     0x021D9A0C  data  a4
 *   FIELD_RAIL_SETTING_GetCamera  0x021B8820  thumb  ov021
 */

#include "../include/G_Elem.h"

typedef unsigned short u16;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad2[0x28];
    void *f3C;
} Info;

typedef struct {
    u16 h0;
    Info *f4;
    char pad[0x1C];
    void *f24;
} Obj;

extern struct Elem gRailDefaultCamera;

extern void *FIELD_RAIL_SETTING_GetCamera(void *a, void *b);

void *FIELD_RAIL_WORK_GetSpotCamera(Obj *p)
{
    switch (p->h0) {
    case 0:
        return FIELD_RAIL_SETTING_GetCamera(p->f24, p->f4->f3C);
    case 1:
        return FIELD_RAIL_SETTING_GetCamera(p->f24, p->f4->f10);
    }
    return &(*(int *)&gRailDefaultCamera);
}
