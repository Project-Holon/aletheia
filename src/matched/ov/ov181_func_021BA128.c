/*
 * function: STAFF_ROLL_UpdateLights
 * address: 0x021BA128
 * packet: pkt_ov181_021BA128
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048AE8, 02048AFC, 02048B30, 02048B44 have no witness.
 *   the integrator owns these accessors. Existing unit_02048AD0.c defines them but
 *   its function header lists only G3D_CAMERA_Reset, so no individual shard entries resolve them.
 * blocker: Verified separately with one --arm (no region), fixed compiler/flags:
 *   typedef unsigned char u8; typedef unsigned int u32;
 *   typedef struct { int x, y, z; } Vec;
 *   struct Light { u32 unk00, unk04, unk08; u8 pad0C[8]; u32 unk14, unk18;
 *     u8 pad1C[4]; Vec unk20, unk2C, unk38; };
 *   0x02048AE8 EXACT 20B: void G3D_CAMERA_GetEye(struct Light *l, Vec *out) { *out = l->unk20; }
 *   0x02048AFC EXACT 16B: void G3D_CAMERA_SetEye(struct Light *l, const Vec *in) { l->unk20 = *in; }
 *   0x02048B30 EXACT 20B: void G3D_CAMERA_GetUp(struct Light *l, Vec *out) { *out = l->unk38; }
 *   0x02048B44 EXACT 16B: void G3D_CAMERA_SetUp(struct Light *l, const Vec *in) { l->unk38 = *in; }
 * symbols:
 *   G3D_CAMERA_GetEye 0x02048AE8 arm
 *   G3D_CAMERA_GetUp 0x02048B30 arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetUp 0x02048B44 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   STAFF_ROLL_CalcVelocity 0x021BA028 thumb ov181
 *   STAFF_ROLL_StepPosition 0x021BA0AC thumb ov181
 *   STAFF_ROLL_AdvanceLights 0x021BA000 thumb ov181
 *   STAFF_ROLL_SetLightMode 0x021BA2A8 thumb ov181
 */
typedef unsigned short u16;
typedef struct { int x, y, z; } Vec;
struct Light;
extern void G3D_CAMERA_GetEye(struct Light *, Vec *);
extern void G3D_CAMERA_GetUp(struct Light *, Vec *);
extern void G3D_CAMERA_SetEye(struct Light *, const Vec *);
extern void G3D_CAMERA_SetUp(struct Light *, const Vec *);
extern void G3D_CAMERA_Reset(struct Light *);
extern void STAFF_ROLL_CalcVelocity(Vec *, const Vec *, const Vec *, unsigned);
extern void STAFF_ROLL_StepPosition(Vec *, const Vec *, const Vec *, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void STAFF_ROLL_AdvanceLights(u8 *p);
extern void STAFF_ROLL_SetLightMode(u8 *p, u32 a);
void STAFF_ROLL_UpdateLights(char *p)
{
    Vec a, b, c, d, e;
    char *q;
    q = p + 0x28;
    if (*(int *)(q + 0x7c) == 0) return;
    if (*(u16 *)(q + 0x78) == 0) {
        *(u16 *)(q + 0x7a) = *(u16 *)(q + 0x36);
        G3D_CAMERA_GetEye(*(struct Light **)(p + 0xc), &a);
        STAFF_ROLL_CalcVelocity(&b, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x1c) = b;
        G3D_CAMERA_GetUp(*(struct Light **)(p + 0xc), &a);
        STAFF_ROLL_CalcVelocity(&c, &a, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12), *(u16 *)(q + 0x7a));
        *(Vec *)(q + 0x28) = c;
    }
    if (*(u16 *)(q + 0x78) >= *(u16 *)(q + 0x7a)) {
        *(Vec *)(q + 4) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24);
        *(Vec *)(q + 0x10) = *(Vec *)(*(unsigned *)q + *(u16 *)(q + 0x34) * 24 + 12);
        *(u16 *)(q + 0x76) = *(u16 *)(q + 0x34);
        *(u16 *)(q + 0x78) = 0;
        STAFF_ROLL_AdvanceLights((u8 *)q);
        if (*(u16 *)(q + 0x34) == 0xffff) STAFF_ROLL_SetLightMode((u8 *)q, 0);
    } else {
        STAFF_ROLL_StepPosition(&d, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24), (Vec *)(q + 0x1c), *(u16 *)(q + 0x78));
        *(Vec *)(q + 4) = d;
        STAFF_ROLL_StepPosition(&e, (Vec *)(*(unsigned *)q + *(u16 *)(q + 0x76) * 24 + 12), (Vec *)(q + 0x28), *(u16 *)(q + 0x78));
        *(Vec *)(q + 0x10) = e;
        if (*(unsigned char *)(p + 0x2d2) == 1) *(u16 *)(q + 0x78) += 4;
        else ++*(u16 *)(q + 0x78);
    }
    G3D_CAMERA_SetEye(*(struct Light **)(p + 0xc), (Vec *)(q + 4));
    G3D_CAMERA_SetUp(*(struct Light **)(p + 0xc), (Vec *)(q + 0x10));
    G3D_CAMERA_Reset(*(struct Light **)(p + 0xc));
}
