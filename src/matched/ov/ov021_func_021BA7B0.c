/*
 * function: func_021BA7B0
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
 *   func_021B8220  0x021B8220  thumb  ov021
 *   func_021B830C  0x021B830C  thumb  ov021
 *   func_021BA7E0  0x021BA7E0  thumb  ov021
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

u32 func_021B8220(u8 *p);
Cam *func_021B830C(void);
void func_021BA7E0(u8 *p, u16 ang, int r, V *pos);

void func_021BA7B0(u8 *p)
{
    Cam *c;
    u16 ang;
    int r;
    V pos;

    func_021B8220(p);
    c = func_021B830C();
    ang = c->ang;
    r = c->r;
    pos.x = c->pos.x;
    pos.y = c->pos.y;
    pos.z = c->pos.z;
    func_021BA7E0(p, ang, r, &pos);
}
