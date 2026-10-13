/*
 * function: BUTTON_MAN_MakeLookAtMtx
 * address:  0x020521BC
 * packet:   pkt_020520A4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   FX_SinCosTable_   0x020A1B38  data
 *   VEC_Mag        0x0207CBD0  arm
 *   FX_Atan2Idx    0x0207CFB8  arm
 *   MTX_RotX33_    0x0207AF00  thumb
 *   MTX_RotY33_    0x0207AF1C  thumb
 *   MTX_Concat33   0x0207B388  arm
 *
 * Turn a direction vector into a look-at rotation matrix: pitch about X, yaw
 * about Y, composed into the caller's 3x3.
 *
 * The horizontal run is measured by flattening a copy of the vector: the whole
 * 12-byte vector is copied to a stack scratch with one ldm/stm pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), its y component is zeroed,
 * and VEC_Mag of that gives the run.  Pitch is then FX_Atan2Idx(-v->y, run)
 * and yaw is FX_Atan2Idx(v->x, v->z) - note the argument order is (y, x), the
 * SDK's own, and the pitch numerator carries the `rsb r0, r2, #0` negation.
 *
 * Both angle indices feed the shared interleaved sin/cos halfword table at
 * 0x020A1B38 (see src/matched/func_0203F684.c) at i = angle >> 4, sin at
 * tbl[2*i] and cos at tbl[2*i+1], exactly as in BUTTON_MAN_MakeRotMtxXYZ next door.
 *
 * Declaration order is the whole difference between 184 correct bytes and four
 * wrong ones: the frame lays `flat` at sp+0x48, `mx` at sp+0x24 and `my` at
 * sp+0x00, so the locals must be declared flat, mx, my - the later declaration
 * takes the LOWER stack address
 * (docs/idioms/local-declaration-order-is-stack-order.md).  Declaring my, mx,
 * flat reproduces every instruction and misses only the three `add rN, sp, #k`
 * immediates and the `str r1, [sp, #0x4c]` offset.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_MakeLookAtMtx.c \
 *       --func BUTTON_MAN_MakeLookAtMtx --addr 0x020521BC --cc 1.1p1 --arm
 *
 * Addresses are Black-image addresses.
 */

typedef short s16;

struct Vec3 {
    int x;  /* 0x00 */
    int y;  /* 0x04 */
    int z;  /* 0x08 */
};

struct Mtx33 {
    int m[9];
};

extern s16 FX_SinCosTable_[];

extern int  VEC_Mag(const struct Vec3 *v);
extern int  FX_Atan2Idx(int y, int x);
extern void MTX_RotX33_(struct Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_RotY33_(struct Mtx33 *m, s16 sinv, s16 cosv);
extern void MTX_Concat33(const struct Mtx33 *a, const struct Mtx33 *b,
                         struct Mtx33 *dst);

void BUTTON_MAN_MakeLookAtMtx(const struct Vec3 *v, struct Mtx33 *dst)
{
    struct Vec3  flat;
    struct Mtx33 mx;
    struct Mtx33 my;
    int          i;
    int          run;

    flat = *v;
    flat.y = 0;
    run = VEC_Mag(&flat);

    i = FX_Atan2Idx(-v->y, run) >> 4;
    MTX_RotX33_(&mx, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    i = FX_Atan2Idx(v->x, v->z) >> 4;
    MTX_RotY33_(&my, FX_SinCosTable_[2 * i], FX_SinCosTable_[2 * i + 1]);

    MTX_Concat33(&mx, &my, dst);
}
