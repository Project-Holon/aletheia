/*
 * file:     fld_scenearea_loader.c
 * unit:     yes
 * function: func_021AB7E4, func_021AB81C, func_021AB840, func_021AB868, func_021AB880, func_021AB884, func_021AB888, func_021AB890, func_021AB908, func_021AB9FC, func_021ABA3C, func_021ABABC, func_021ABB54, func_021ABB78, func_021ABBA0, func_021ABBF0, func_021ABC14, func_021ABC38, func_021ABC5C, func_021ABD08
 * address:  0x021AB7E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021AB7E4: __FILE__ fld_scenearea_loader.c on 0x021AB7E4 (create,
 * first function).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   d_021DE000  0x021DE000  data  a4
 *   d_021D8EEC  0x021D8EEC  data  a4
 *   func_0204A39C  0x0204A39C  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0218E124  0x0218E124  thumb  ov021
 *   tbl_020A1B38   0x020A1B38  data  a2
 *   d_021D8EF4  0x021D8EF4  data  a4
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECF4  0x0218ECF4  thumb  ov021
 *   FX_Div         0x0207C768  arm
 *   func_0218ED34  0x0218ED34  thumb
 *   func_0218ED48  0x0218ED48  thumb
 *   func_0218ED58  0x0218ED58  thumb
 *   func_0218F0D4  0x0218F0D4  thumb
 *   func_0218F05C  0x0218F05C  thumb
 *   func_0218ECD4  0x0218ECD4  thumb ov021
 *   func_0207C768  0x0207C768  arm
 *   func_0218ED64  0x0218ED64  thumb
 *   func_021AB760  0x021AB760  thumb  ov021
 *   func_021AB764  0x021AB764  thumb  ov021
 */
#include "fld_scenearea_types.h"

extern void *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(void *arcHandle);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_02188CFC(void *fieldMap);
extern void *func_0204A39C(void *arcHandle, int fileId, int decompress, u32 heapId, u32 *outSize);
extern void func_0207CA00(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern int func_0207CBD0(const VecFx32 *v);
extern void func_0207CCA4(const VecFx32 *v, VecFx32 *out);
extern u32 func_0207CFB8(int x, int z);
extern void func_0218E124(void *camera, u32 mode);
extern void func_0218EC90(void *camera, VecFx32 *target);
extern void func_0218ECF4(void *camera, VecFx32 *eye);
extern int FX_Div(int a, int b);
extern void func_0218ED34(void *camera, u16 pitch);
extern void func_0218ED48(void *camera, u32 yaw);
extern void func_0218ED58(void *camera, u32 distance);
extern void func_0218F0D4(void *camera, int delay);
extern void func_0218F05C(void *camera);
extern void func_0218ECD4(void *camera, VecFx32 *shift);
extern void func_0218ED64(void *camera, u16 fov);
extern void *func_021AB760(FldSceneArea *sceneArea);
extern void *func_021AB764(FldSceneArea *sceneArea);

FldSceneAreaLoader *func_021AB7E4(int heapId);
void func_021AB81C(FldSceneAreaLoader *loader);
void func_021AB840(FldSceneAreaLoader *loader, int arcIndex, int fileId, int heapId);
void func_021AB868(FldSceneAreaLoader *loader);
FldSceneAreaRec *func_021AB880(FldSceneAreaLoader *loader);
u32 func_021AB884(FldSceneAreaLoader *loader);
const FldSceneAreaCallbacks *func_021AB888(void);
int func_021AB890(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021AB908(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, const VecFx32 *pos);
void func_021AB9FC(FldSceneArea *sceneArea, const FldSceneAreaRec *rec);
int func_021ABA3C(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABABC(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABB54(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABB78(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABBA0(const FldSceneAreaRec *rec, VecFx32 *pos, int *length, int *progress);
void func_021ABBF0(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABC14(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABC38(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABC5C(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);
void func_021ABD08(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos);

extern char d_021DE000[];
extern const int d_021D8EEC[];
extern const FldSceneAreaCallbacks d_021D8EF4;
extern s16 tbl_020A1B38[];

/* 0x021DE000 is the "fld_scenearea_loader.c" file-name string; 0x81 is its line. */
FldSceneAreaLoader *func_021AB7E4(int heapId)
{
    FldSceneAreaLoader *loader = func_02030734(heapId, sizeof(FldSceneAreaLoader), 1, d_021DE000, 0x81);
    int i;

    for (i = 0; i < 2; i++) {
        loader->arcHandle[i] = func_020490F4(d_021D8EEC[i], heapId);
    }
    return loader;
}

void func_021AB81C(FldSceneAreaLoader *loader)
{
    int i;

    func_021AB868(loader);
    for (i = 0; i < 2; i++) {
        func_02049238(loader->arcHandle[i]);
    }
    func_020307B0(loader);
}

/* Loads a scene area file from one of the two archives. */
void func_021AB840(FldSceneAreaLoader *loader, int arcIndex, int fileId, int heapId)
{
    u32 size;

    loader->recs = func_0204A39C(loader->arcHandle[arcIndex], fileId, 0, heapId, &size);
    loader->count = size / sizeof(FldSceneAreaRec);
}

/* Frees the loaded records. */
void func_021AB868(FldSceneAreaLoader *loader)
{
    if (loader->recs != 0) {
        func_020307B0(loader->recs);
        loader->recs = 0;
        loader->count = 0;
    }
}

FldSceneAreaRec *func_021AB880(FldSceneAreaLoader *loader)
{
    return loader->recs;
}

u32 func_021AB884(FldSceneAreaLoader *loader)
{
    return loader->count;
}

/* The check and action tables (d_021D8EF4). */
const FldSceneAreaCallbacks *func_021AB888(void)
{
    return &d_021D8EF4;
}

static inline void VecSet(VecFx32 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

/*
 * Check FLD_SCENEAREA_CHECK_SECTOR: 1 when the position lies in the ring
 * sector around the record's center (distance between min and max, angle
 * between lo and hi, wrapping through 0 when hi < lo).
 *
 * Lever: `const FldSceneAreaRec *` together with the inline VecSet helper
 * gives the y, x, z load order of the 12-byte vector fill; either alone does
 * not.
 */
int func_021AB890(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    VecFx32 offset;
    VecFx32 center;
    int distance;
    u32 angle;

    VecSet(&center, rec->shape.sector.center.x, rec->shape.sector.center.y, rec->shape.sector.center.z);
    func_0207CA00(pos, &center, &offset);
    offset.y = 0;
    distance = func_0207CBD0(&offset);
    func_0207CCA4(&offset, &offset);
    angle = func_0207CFB8(offset.x, offset.z);
    if (rec->shape.sector.minDistance <= distance && rec->shape.sector.maxDistance > distance) {
        if (rec->shape.sector.angleHi < rec->shape.sector.angleLo) {
            if (rec->shape.sector.angleHi >= angle || (angle < 0x10000 && angle >= rec->shape.sector.angleLo))
                return 1;
        } else {
            if (rec->shape.sector.angleLo <= angle && rec->shape.sector.angleHi > angle)
                return 1;
        }
    }
    return 0;
}

static inline s32 FX_Mul(s32 a, s32 b)
{
    return (s32)(((long long)a * b + 0x800LL) >> 12);
}

/*
 * Action FLD_SCENEAREA_ACTION_SECTOR_CAMERA: aims the camera at the center
 * from the player's side, at the record's elevation and distance.
 *
 * Lever (wave A3): the center is copied field by field with its y kept in
 * the vector (`center.y = rec->...y`), y is saved by reading it back
 * (`centerY = center.y`), and center.y is zeroed before the copy of *pos. The
 * read keeps the first center.y store alive and puts the zero ahead of the
 * pos copy, which gives the colouring (y r7, zero r6, table r4) and lets the
 * final center.y reload become `mov r1, r7`.
 */
void func_021AB908(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, const VecFx32 *pos)
{
    VecFx32 playerOffset;
    VecFx32 center;
    VecFx32 dir;
    VecFx32 eye;
    void *camera;
    s32 centerY;
    s32 horizontal;
    s16 sinValue;
    s16 cosValue;

    camera = func_021AB760(sceneArea);
    func_0218E124(camera, 2);
    center.x = rec->shape.sector.center.x;
    center.y = rec->shape.sector.center.y;
    center.z = rec->shape.sector.center.z;
    centerY = center.y;
    center.y = 0;
    playerOffset = *pos;
    playerOffset.y = 0;
    func_0207CA00(&playerOffset, &center, &playerOffset);
    func_0207CCA4(&playerOffset, &dir);
    sinValue = tbl_020A1B38[(rec->shape.sector.angleIndex >> 4) * 2];
    center.y = centerY;
    eye.y = FX_Mul(sinValue, rec->shape.sector.distance);
    cosValue = tbl_020A1B38[(rec->shape.sector.angleIndex >> 4) * 2 + 1];
    horizontal = FX_Mul(cosValue, rec->shape.sector.distance);
    eye.x = FX_Mul(dir.x, horizontal);
    eye.z = FX_Mul(dir.z, horizontal);
    eye.x += center.x;
    eye.y += center.y;
    eye.z += center.z;
    func_0218EC90(camera, &center);
    func_0218ECF4(camera, &eye);
}

/*
 * Action FLD_SCENEAREA_ACTION_FIXED_CAMERA: puts the camera at the record's
 * target and eye.
 *
 * Lever: `const FldSceneAreaRec *` together with the inline VecSet helper
 * gives the y, x, z load order of the two 12-byte vector fills (as in
 * func_021AB890).
 */
void func_021AB9FC(FldSceneArea *sceneArea, const FldSceneAreaRec *rec)
{
    void *camera = func_021AB760(sceneArea);
    VecFx32 target;
    VecFx32 eye;

    func_0218E124(camera, 2);
    VecSet(&target, rec->shape.fixed.target.x, rec->shape.fixed.target.y, rec->shape.fixed.target.z);
    VecSet(&eye, rec->shape.fixed.eye.x, rec->shape.fixed.eye.y, rec->shape.fixed.eye.z);
    func_0218EC90(camera, &target);
    func_0218ECF4(camera, &eye);
}

/*
 * Check FLD_SCENEAREA_CHECK_STRIP: 1 when the player's tile lies in the
 * strip. Never matches while the map is in move kind 1.
 *
 * Lever: `const FldSceneAreaRec *rec` sinks the shifted.z spill store below
 * the first shift pair (const on the vector source alone does not).
 */
int func_021ABA3C(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    VecFx32 shifted;
    u16 playerTileX;
    u16 playerTileZ;
    int width;
    int height;

    if (func_02188CFC(func_021AB764(sceneArea)) == 1)
        return 0;
    shifted = *pos;
    shifted.x -= 0x8000;
    shifted.z -= 0x8000;
    playerTileX = (shifted.x >> 12) / 16;
    playerTileZ = (shifted.z >> 12) / 16;
    width = rec->shape.strip.extentX;
    if (width == 1) {
        width = rec->shape.strip.length;
        height = rec->shape.strip.extentZ;
    } else {
        height = rec->shape.strip.length;
    }
    if (playerTileX >= rec->shape.strip.tileX && playerTileX < rec->shape.strip.tileX + width && playerTileZ >= rec->shape.strip.tileZ && playerTileZ < rec->shape.strip.tileZ + height)
        return 1;
    return 0;
}

/*
 * Action FLD_SCENEAREA_ACTION_STRIP_CAMERA: moves pitch, yaw and distance
 * from the strip's start key to its end key as the player walks along it.
 *
 * const on rec lets the three loads from rec schedule above the store of
 * progress to the address-taken local (docs/idioms/a-const-parameter-hoists-
 * field-loads-above-a-call-result-store-into-an-address-taken-local.md). One
 * reused temporary delta keeps the quotient on the left of each add and stops
 * pitch and yaw being forward-substituted into their calls; distance, the
 * last, is.
 */
void func_021ABABC(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    void *camera = func_021AB760(sceneArea);
    int length;
    int progress;
    int ratio;
    int pitch;
    int yaw;
    int distance;
    int delta;

    func_0218E124(camera, 0);
    func_021ABBA0(rec, pos, &length, &progress);
    progress = ratio = FX_Div(progress, length);
    delta = rec->shape.strip.to.pitch - rec->shape.strip.from.pitch;
    delta = delta * ratio / 4096;
    pitch = delta + rec->shape.strip.from.pitch;
    delta = rec->shape.strip.to.yaw - rec->shape.strip.from.yaw;
    delta = delta * ratio / 4096;
    yaw = delta + rec->shape.strip.from.yaw;
    delta = rec->shape.strip.to.distance - rec->shape.strip.from.distance;
    delta = (int)(((s64)delta * ratio + 0x800) >> 12);
    distance = delta + rec->shape.strip.from.distance;
    func_0218ED34(camera, pitch);
    func_0218ED48(camera, (u16)yaw);
    func_0218ED58(camera, distance);
}

/* Strip camera that first stops the camera delay when the record sets delayFlag. */
void func_021ABB54(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    void *camera = func_021AB760(sceneArea);

    if (rec->shape.strip.delayFlag != 0) {
        func_0218F0D4(camera, rec->shape.strip.delayFlag);
    }
    func_021ABABC(sceneArea, rec, pos);
}

/* Strip camera that restarts the camera delay afterwards when the record sets delayFlag. */
void func_021ABB78(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    void *camera = func_021AB760(sceneArea);

    func_021ABABC(sceneArea, rec, pos);
    if (rec->shape.strip.delayFlag != 0) {
        func_0218F05C(camera);
    }
}

/*
 * Where the player stands along a strip: *length is the strip length and
 * *progress the distance already covered, both in 16.16 tile units.
 */
void func_021ABBA0(const FldSceneAreaRec *rec, VecFx32 *pos, int *length, int *progress)
{
    VecFx32 shifted = *pos;

    shifted.x -= 0x8000;
    shifted.z -= 0x8000;
    *length = rec->shape.strip.length << 16;
    if (rec->shape.strip.extentX == 1)
        *progress = shifted.x - (rec->shape.strip.tileX << 16);
    else
        *progress = shifted.z - (rec->shape.strip.tileZ << 16);
}

/* Full strip action: camera angles, target shift and field of view. */
void func_021ABBF0(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    func_021ABABC(sceneArea, rec, pos);
    func_021ABC5C(sceneArea, rec, pos);
    func_021ABD08(sceneArea, rec, pos);
}

/* Full strip action that stops the camera delay first. */
void func_021ABC14(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    func_021ABB54(sceneArea, rec, pos);
    func_021ABC5C(sceneArea, rec, pos);
    func_021ABD08(sceneArea, rec, pos);
}

/* Full strip action that restarts the camera delay afterwards. */
void func_021ABC38(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    func_021ABB78(sceneArea, rec, pos);
    func_021ABC5C(sceneArea, rec, pos);
    func_021ABD08(sceneArea, rec, pos);
}

/* Moves the camera target shift from the strip's start to its end target. */
void func_021ABC5C(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    void *camera;
    int length;
    int progress;
    VecFx32 shift;
    int deltaY;
    int deltaZ;
    int deltaX;

    camera = func_021AB760(sceneArea);
    func_021ABBA0(rec, pos, &length, &progress);
    deltaY = rec->shape.strip.targetTo.y - rec->shape.strip.targetFrom.y;
    deltaZ = rec->shape.strip.targetTo.z - rec->shape.strip.targetFrom.z;
    deltaX = rec->shape.strip.targetTo.x - rec->shape.strip.targetFrom.x;
    shift.x = rec->shape.strip.targetFrom.x +
              FX_Div((int)(((long long)deltaX * progress + 0x800) >> 12), length);
    shift.y = rec->shape.strip.targetFrom.y + FX_Div((int)(((long long)deltaY * progress + 0x800) >> 12), length);
    shift.z = rec->shape.strip.targetFrom.z + FX_Div((int)(((long long)deltaZ * progress + 0x800) >> 12), length);
    func_0218ECD4(camera, &shift);
}

/*
 * Moves the camera field of view from the strip's start to its end value.
 *
 * const on rec lets mwcc hoist the two field loads above the store to the
 * address-taken progress (see docs/idioms/a-const-source-pointer-hoists-the-
 * last-load-of-a-struct-copy-into-an-address-taken-local.md); the assignment
 * must stay inside the multiply for the result to land in r3.
 */
void func_021ABD08(FldSceneArea *sceneArea, const FldSceneAreaRec *rec, VecFx32 *pos)
{
    void *camera = func_021AB760(sceneArea);
    int length;
    int progress;

    func_021ABBA0(rec, pos, &length, &progress);
    func_0218ED64(camera, rec->shape.strip.fovFrom + (rec->shape.strip.fovTo - rec->shape.strip.fovFrom) * (progress = FX_Div(progress, length)) / 0x1000);
}
