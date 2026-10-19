/*
 * unit:     yes
 * function: G3D_CAMERA_Reset
 * address:  0x02048AD0
 * packet:   pkt_02048AD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_SetProjection  0x02046858  arm
 *   G3D_SYSTEM_SetLookAt  0x02046B40  arm
 *
 * g3d_light.c's accessor run, 0x02048AD0-0x02048BC4.  Seventeen functions,
 * fifteen of them `bx lr` leaves that save no lr and therefore carry no
 * disasm.py label of their own (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); the whole run
 * is one translation unit.
 *
 *   0x02048AD0  two-stage reset: the sibling at 0x02046858 over the object,
 *               then 0x02046B40 over the vector block at +0x20
 *   0x02048AE8  read the vector at +0x20 out to the caller's VecFx32
 *   0x02048AFC  write it
 *   0x02048B0C  read the vector at +0x2C, 0x02048B20 writes it
 *   0x02048B30  read the vector at +0x38, 0x02048B44 writes it
 *   0x02048B54  read +0x14 out through a pointer, 0x02048B60 writes it
 *   0x02048B6C  write +0x18 through a pointer
 *   0x02048B78  return +0x00 by value
 *   0x02048B80  store +0x04 by value
 *   0x02048B88  read +0x08 out through a pointer, 0x02048B94 stores it by
 *               value
 *   0x02048B9C  read +0x04 out through a pointer, 0x02048BA8 stores it
 *   0x02048BB0  read +0x08 out through a pointer, 0x02048BBC stores it
 *
 * The last six are byte-for-byte duplicates of the pair at 0x02048B80 and
 * 0x02048B88: the same three offsets accessed twice over, which is what a
 * second object type sharing the first three words looks like in source.
 * They are written out here as separate functions over a second struct tag
 * rather than folded, because the image has six separate entry points.
 *
 * The twelve-byte vector moves are plain aggregate assignments; the paired
 * `ldm`/`stm` is the inlined struct copy, not a loop
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02048AD0.c \
 *       --addr 0x02048AD0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    int x;
    int y;
    int z;
} VecFx32;

struct Light {
    u32     unk00;
    u32     unk04;
    u32     unk08;
    u8      pad0C[8];
    u32     unk14;
    u32     unk18;
    u8      pad1C[4];
    VecFx32 unk20;
    VecFx32 unk2C;
    VecFx32 unk38;
};

extern void G3D_SYSTEM_SetProjection(const u32 *src);
extern void G3D_SYSTEM_SetLookAt(u8 *a0);

void G3D_CAMERA_Reset(struct Light *l)
{
    G3D_SYSTEM_SetProjection((const u32 *)l);
    G3D_SYSTEM_SetLookAt((u8 *)(&l->unk20));
}

void G3D_CAMERA_GetEye(struct Light *l, VecFx32 *out)
{
    *out = l->unk20;
}

void G3D_CAMERA_SetEye(struct Light *l, const VecFx32 *in)
{
    l->unk20 = *in;
}

void G3D_CAMERA_GetCamUp(struct Light *l, VecFx32 *out)
{
    *out = l->unk2C;
}

void G3D_CAMERA_SetCamUp(struct Light *l, const VecFx32 *in)
{
    l->unk2C = *in;
}

void G3D_CAMERA_GetCamTarget(struct Light *l, VecFx32 *out)
{
    *out = l->unk38;
}

void G3D_CAMERA_SetCamTarget(struct Light *l, const VecFx32 *in)
{
    l->unk38 = *in;
}

void G3D_CAMERA_GetNear(struct Light *l, u32 *out)
{
    *out = l->unk14;
}

void G3D_CAMERA_SetNear(struct Light *l, const u32 *in)
{
    l->unk14 = *in;
}

void G3D_CAMERA_SetFar(struct Light *l, const u32 *in)
{
    l->unk18 = *in;
}

int G3D_CAMERA_GetMode(struct Light *l)
{
    return l->unk00;
}

void G3D_CAMERA_SetFovySin(struct Light *l, u32 v)
{
    l->unk04 = v;
}

void G3D_CAMERA_GetFovyCos(struct Light *l, u32 *out)
{
    *out = l->unk08;
}

void G3D_CAMERA_SetFovyCos(struct Light *l, u32 v)
{
    l->unk08 = v;
}

void G3D_CAMERA_GetNearClipAlt(struct Light *l, u32 *out)
{
    *out = l->unk04;
}

void G3D_CAMERA_SetNearClipAlt(struct Light *l, u32 v)
{
    l->unk04 = v;
}

void G3D_CAMERA_GetFarClipAlt(struct Light *l, u32 *out)
{
    *out = l->unk08;
}

void G3D_CAMERA_SetFarClipAlt(struct Light *l, u32 v)
{
    l->unk08 = v;
}
