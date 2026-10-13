/*
 * function: FIELD_RAIL_CAMERA_Orbit
 * address:  0x021BA7B0
 * packet:   pkt_ov021_021BA7B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_CAMERA_SetOrbit  0x021BA7E0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

typedef struct {
    int x0;
    int ang;
    int r;
    V pos;
} Cam;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
Cam *FIELD_RAIL_WORK_GetCamera(void);
void FIELD_RAIL_CAMERA_SetOrbit(u8 *p, u16 ang, int r, V *pos);

void FIELD_RAIL_CAMERA_Orbit(u8 *p)
{
    Cam *c;
    u16 ang;
    int r;
    V pos;

    FIELD_RAIL_GetFocusWork(p);
    c = FIELD_RAIL_WORK_GetCamera();
    ang = c->ang;
    r = c->r;
    pos.x = c->pos.x;
    pos.y = c->pos.y;
    pos.z = c->pos.z;
    FIELD_RAIL_CAMERA_SetOrbit(p, ang, r, &pos);
}
