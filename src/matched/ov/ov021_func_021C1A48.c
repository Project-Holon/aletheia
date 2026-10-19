/*
 * function: FLD_PARTICLE_CreateEffect
 * address:  0x021C1A48
 * packet:   pkt_ov021_021C1A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates the effect instance and sets its two scale parameters.
 *
 * symbols:
 *   G3D_CAMERA_SetNear  0x02048B60  arm  arm9
 *   G3D_CAMERA_SetFar  0x02048B6C  arm  arm9
 *   PARTICLE_CreateSystemDefault  0x02050C04  arm  arm9
 *   PARTICLE_EMITTER_GetBlock  0x02051788  arm  arm9
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u32 fC;
} S;

extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
struct Light;
extern int PARTICLE_EMITTER_GetBlock(char *p);
extern void G3D_CAMERA_SetNear(struct Light *l, const u32 *in);
extern void G3D_CAMERA_SetFar(struct Light *l, const u32 *in);

u32 FLD_PARTICLE_CreateEffect(S *p)
{
    u32 a;
    u32 b;
    u32 o;

    p->fC = PARTICLE_CreateSystemDefault(p->f8, 0x4800, 1, p->f4);
    o = PARTICLE_EMITTER_GetBlock((char *)p->fC);
    a = 1 << 12;
    b = 0x384000;
    G3D_CAMERA_SetNear((struct Light *)o, &a);
    G3D_CAMERA_SetFar((struct Light *)o, &b);
    return p->fC;
}
