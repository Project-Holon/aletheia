/*
 * file:     field_light.c
 * unit:     yes
 * function: func_021A03D0, func_021A0448, func_021A0458, func_021A0568, func_021A0590, func_021A05D8, func_021A0618, func_021A063C, func_021A065C, func_021A066C, func_021A0734, func_021A0748, func_021A07B0, func_021A07B4, func_021A07F8, func_021A0818, func_021A0860, func_021A08CC, func_021A0918, func_021A0974, func_021A0980, func_021A0A50, func_021A0B14, func_021A0B34, func_021A0B4C, func_021A0C50, func_021A0C60, func_021A0C74, func_021A0CE4
 * address:  0x021A03D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c (CL110): __FILE__ anchor field_light.c at 0x021A03D0; ends at the field_subscreen.c anchor 0x021A0CF4.
 * Helpers 0x021A07B0..0x021A0CE4 are called only by this file.
 * Time-of-day lighting of the field map: keyframes per time of day (loaded from archive 0x3d),
 * blended by FIELD_LIGHT_Main, applied to the 3D light slots, material colors, fog color and clear color.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082D44  0x02082D44  arm
 *   d_021DDE38  0x021DDE38  data  ov021
 *   func_02048CA4  0x02048CA4  arm
 *   func_02048CDC  0x02048CDC  arm
 *   func_0206AA8C  0x0206AA8C  arm
 *   func_0206AAB0  0x0206AAB0  arm
 *   func_0207DD24  0x0207DD24  arm
 *   func_020490A8  0x020490A8  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0207CDB8  0x0207CDB8  arm
 *   func_02011400  0x02011400  thumb
 *   func_0207CB68  0x0207CB68  arm
 *   func_0207CAA4  0x0207CAA4  arm
 *   func_0207D184  0x0207D184  arm
 *   func_0207B65C  0x0207B65C  arm
 *   func_0207BC08  0x0207BC08  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   d_020A1B38  0x020A1B38  data  a2
 *   func_021A01C4  0x021A01C4  thumb  ov021
 */
#define GX_RGB(r, g, b) ((u16)(((r) << 0) | ((g) << 5) | ((b) << 10)))

#define FIELD_LIGHT_SLOT_COUNT      4
#define FIELD_LIGHT_KEYFRAME_MAX    16
#define FIELD_LIGHT_ARC_ID          0x3d
#define FIELD_LIGHT_BLEND_FRAMES    0x3c
#define FIELD_LIGHT_SECONDS_PER_DAY 86400

#define FIELD_LIGHT_MODE_FOLLOW     0
#define FIELD_LIGHT_MODE_FADE       1

#define FIELD_LIGHT_FADE_IDLE       0
#define FIELD_LIGHT_FADE_START      1
#define FIELD_LIGHT_FADE_HOLD       2
#define FIELD_LIGHT_FADE_RETURN     3
#define FIELD_LIGHT_FADE_NO_RETURN  0xFFFF

struct LightSlot;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

/* Light direction, three fx16 components. */
typedef struct {
    u16 x, y, z;
} FieldLightDir;

typedef struct { s32 x, y, z; } FieldLightVec32;

/* One time-of-day entry of the light table (0x34 bytes), as stored in the archive. */
typedef struct {
    u16 hour;
    s16 minute;
    u8 slotUsed[FIELD_LIGHT_SLOT_COUNT];
    u16 slotColor[FIELD_LIGHT_SLOT_COUNT];
    FieldLightDir slotDir[FIELD_LIGHT_SLOT_COUNT];
    u16 materialDiffuse;
    u16 materialAmbient;
    u16 materialSpecular;
    u16 materialEmission;
    u16 fogColor;
    u16 clearColor;
} FieldLightKeyframe;

/* One 5-bit color channel as a start value and a signed distance to the end value. */
typedef struct {
    s16 base;
    s16 delta;
} FieldLightChannelLerp;

typedef struct {
    FieldLightChannelLerp r;
    FieldLightChannelLerp g;
    FieldLightChannelLerp b;
} FieldLightColorLerp;

/* Rotation of a light direction from a start vector about an axis by an angle (0x1c bytes). */
typedef struct {
    FieldLightVec32 start;
    FieldLightVec32 axis;
    u16 angle;
} FieldLightDirLerp;

/* Blend between two keyframes (0xF4 bytes); step runs from 0 to stepCount. */
typedef struct {
    u16 hour;
    s16 minute;
    u8 slotUsed[FIELD_LIGHT_SLOT_COUNT];
    FieldLightColorLerp slotColor[FIELD_LIGHT_SLOT_COUNT];
    FieldLightDirLerp slotDir[FIELD_LIGHT_SLOT_COUNT];
    FieldLightColorLerp materialDiffuse;
    FieldLightColorLerp materialAmbient;
    FieldLightColorLerp materialSpecular;
    FieldLightColorLerp materialEmission;
    FieldLightColorLerp fogColor;
    FieldLightColorLerp clearColor;
    u16 step;
    u16 stepCount;
} FieldLightBlend;

/* Script-driven fade to a flat color and back (8 bytes). */
typedef struct {
    u16 state;
    u16 frames;
    u16 returnFrames;
    u16 color;
} FieldLightFade;

/* Field map lighting work (0x490 bytes). */
typedef struct {
    u16 mode;
    u16 season;
    struct LightSlot *slots;
    void *fog;
    u32 keyframeCount;
    FieldLightKeyframe keyframes[FIELD_LIGHT_KEYFRAME_MAX];
    u32 keyframeIndex;
    u16 tableId;
    FieldLightKeyframe current;
    u16 active;
    u32 dirty;
    FieldLightBlend blend;
    FieldLightFade fade;
    s32 lastSeconds;
} FieldLight;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082D44(void *src, void *dst, u32 n);
extern void func_02048CA4(struct LightSlot *slots, u8 index, const FieldLightDir *dir);
extern void func_02048CDC(struct LightSlot *slots, u32 index, u16 *color);
extern void func_0206AA8C(u32 diffuse, u32 ambient, u32 flag);
extern void func_0206AAB0(u32 specular, u32 emission, u32 flag);
extern void func_0207DD24(u16 color, int alpha, int depth, int polygonId, int fog);
extern u32 func_020490A8(u32 arcId, u32 memberId);
extern void func_02048F4C(void *dst, u32 arcId, u32 memberId);
extern void func_0207CDB8(void *src, void *dst);
extern u8 func_02011400(int season, int hour);
extern void func_0207CB68(const s16 *a, const s16 *b, s16 *out);
extern s32 func_0207CAA4(const s16 *a, const s16 *b);
extern u16 func_0207D184(s32 cosine);
extern void func_0207B65C(void *mtx, const void *axis, s32 sin, s32 cos);
extern void func_0207BC08(const void *vec, const void *mtx, void *out);
extern void func_0207CCA4(void *src, void *dst);
void func_021A01C4(void *fog, u32 colorRgb);
void func_021A066C(const FieldLight *light, void *fog, struct LightSlot *slots);
void func_021A0734(FieldLight *light, u32 tableId);
void func_021A0748(FieldLight *light, u32 arcId, u32 memberId);
void func_021A07B0(void);
u32 func_021A07B4(FieldLight *light, int seconds);
int func_021A07F8(u32 season, const FieldLightKeyframe *keyframe);
void func_021A0818(FieldLightColorLerp *lerp, s32 from, u32 to);
u16 func_021A0860(FieldLightColorLerp *lerp, int step, int stepCount);
void func_021A08CC(FieldLightDirLerp *lerp, const s16 *from, const s16 *to);
void func_021A0918(FieldLightDirLerp *lerp, s32 step, s32 stepCount, s16 *out);
void func_021A0974(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to);
void func_021A0980(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to, u32 frames);
void func_021A0A50(FieldLightBlend *blend, FieldLightKeyframe *from, u32 color, u32 frames);
void func_021A0B14(FieldLightBlend *blend);
int func_021A0B34(const FieldLightBlend *blend);
void func_021A0B4C(const FieldLightBlend *blend, FieldLightKeyframe *out);
FieldLightFade *func_021A0C50(FieldLightFade *fade, u16 frames, u32 returnFrames, u32 color);
void func_021A0C60(FieldLightFade *fade, u16 frames, u16 color);
s32 func_021A0C74(FieldLightFade *fade, FieldLightBlend *blend, FieldLightKeyframe *current, FieldLightKeyframe *target);
int func_021A0CE4(FieldLightFade *fade);
extern u8 d_021DDE38[];
extern s16 d_020A1B38[];

FieldLight *func_021A03D0(u32 tableId, u32 seconds, u32 season, void *fog, struct LightSlot *slots, u16 heapId)
{
    FieldLight *light;

    light = func_02030734(heapId, sizeof(FieldLight), 1, (const char *)d_021DDE38, 0x167);
    light->season = season;
    func_021A0734(light, tableId);
    light->active = 1;
    light->keyframeIndex = func_021A07B4(light, seconds);
    func_02082D44(&light->keyframes[light->keyframeIndex], &light->current, sizeof(FieldLightKeyframe));
    light->dirty = 1;
    light->fog = fog;
    light->slots = slots;
    return light;
}

void func_021A0448(FieldLight *light)
{
    func_021A07B0();
    func_020307B0(light);
}

/* Steps the light for the current time of day: advances to the next keyframe when its time is
 * reached (starting a blend), runs a script fade, and steps a running blend. */
void func_021A0458(FieldLight *light, s32 seconds)
{
    s32 prevSeconds;
    s32 curSeconds;
    s32 lastSeconds;
    s32 wrapped;
    s32 prevIndex;
    u32 nextIndex;

    if (light->keyframeCount == 0)
        return;
    switch (light->mode) {
    case FIELD_LIGHT_MODE_FOLLOW:
        curSeconds = func_021A07F8(light->season, &light->keyframes[light->keyframeIndex]);
        wrapped = 0;
        prevIndex = light->keyframeIndex - 1;
        if (prevIndex < 0) {
            prevSeconds = 0;
            lastSeconds = func_021A07F8(light->season, &light->keyframes[(s32)light->keyframeCount - 1]);
            if (lastSeconds <= seconds) {
                prevSeconds = lastSeconds;
                wrapped = 1;
                curSeconds += FIELD_LIGHT_SECONDS_PER_DAY;
            }
        } else {
            prevSeconds = func_021A07F8(light->season, &light->keyframes[prevIndex]);
        }
        if ((prevSeconds > seconds || curSeconds <= seconds) && wrapped == 0) {
            nextIndex = (light->keyframeIndex + 1) % light->keyframeCount;
            light->keyframeIndex = nextIndex;
            func_021A0974(&light->blend, &light->current, &light->keyframes[nextIndex]);
        }
        break;
    case FIELD_LIGHT_MODE_FADE:
        if (func_021A0C74(&light->fade, &light->blend, &light->current, &light->keyframes[light->keyframeIndex]))
            light->mode = FIELD_LIGHT_MODE_FOLLOW;
        break;
    }
    if (func_021A0B34(&light->blend)) {
        func_021A0B14(&light->blend);
        func_021A0B4C(&light->blend, &light->current);
        light->dirty = 1;
    }
    light->lastSeconds = seconds;
}

void func_021A0568(FieldLight *light, int force)
{
    if (light->dirty != 0 || force != 0) {
        func_021A066C(light, light->fog, light->slots);
        light->dirty = 0;
    }
}

/* Loads another light table and blends to the keyframe for the last time of day. */
void func_021A0590(FieldLight *light, u32 arcId, u32 memberId, u32 frames)
{
    u32 index;

    func_021A07B0();
    func_021A0748(light, arcId, memberId);
    index = func_021A07B4(light, light->lastSeconds);
    light->keyframeIndex = index;
    func_021A0980(&light->blend, &light->current, &light->keyframes[index], frames);
}

/* Reloads the zone's own light table and blends to it. */
void func_021A05D8(FieldLight *light)
{
    u32 index;

    func_021A07B0();
    func_021A0734(light, light->tableId);
    index = func_021A07B4(light, light->lastSeconds);
    light->keyframeIndex = index;
    func_021A0974(&light->blend, &light->current, &light->keyframes[index]);
}

/* Fades to a flat color over frames, then back to the keyframe light over returnFrames. */
void func_021A0618(FieldLight *light, u32 color, u32 frames, u32 returnFrames)
{
    func_021A0C50(&light->fade, frames, (u16)returnFrames, color);
    light->mode = FIELD_LIGHT_MODE_FADE;
}

/* Fades to a flat color over frames and stays there. */
void func_021A063C(FieldLight *light, u16 color, u32 frames)
{
    func_021A0C60(&light->fade, frames, color);
    light->mode = FIELD_LIGHT_MODE_FADE;
}

int func_021A065C(FieldLight *light)
{
    return func_021A0CE4(&light->fade);
}

/* Writes the current keyframe to the 3D engine: light slots, material colors, fog and clear color. */
void func_021A066C(const FieldLight *light, void *fog, struct LightSlot *slots)
{
    int i;
    FieldLightDir zeroDir = {0, 0, 0};
    u16 zeroColor = 0;

    if (light->active == 0) {
        return;
    }
    for (i = 0; i < FIELD_LIGHT_SLOT_COUNT; i++) {
        if (light->current.slotUsed[i]) {
            func_02048CA4(slots, i, &light->current.slotDir[i]);
            func_02048CDC(slots, (u8)i, (u16 *)(&light->current.slotColor[i]));
        } else {
            func_02048CA4(slots, i, &zeroDir);
            func_02048CDC(slots, (u8)i, &zeroColor);
        }
    }
    func_0206AA8C(light->current.materialDiffuse, light->current.materialAmbient, 1);
    func_0206AAB0(light->current.materialSpecular, light->current.materialEmission, 0);
    func_021A01C4(fog, light->current.fogColor);
    func_0207DD24(light->current.clearColor, 0x1F, 0x7FFF, 0, 0);
}

void func_021A0734(FieldLight *light, u32 tableId)
{
    light->tableId = tableId;
    func_021A0748(light, FIELD_LIGHT_ARC_ID, tableId);
}

/* Reads a light table into the keyframes and normalizes every slot direction. */
void func_021A0748(FieldLight *light, u32 arcId, u32 memberId)
{
    u32 i;
    s32 j;
    FieldLightDir *dir;

    light->keyframeCount = func_020490A8(arcId, memberId) / sizeof(FieldLightKeyframe);
    func_02048F4C(light->keyframes, arcId, memberId);
    for (i = 0; i < light->keyframeCount; i++) {
        dir = light->keyframes[i].slotDir;
        for (j = 0; j < FIELD_LIGHT_SLOT_COUNT; j++) {
            func_0207CDB8(&dir[j], &dir[j]);
        }
    }
}

void func_021A07B0(void)
{
}

/* Index of the keyframe whose time span contains the given second of the day, 0 if none. */
u32 func_021A07B4(FieldLight *light, int seconds)
{
    int prevSeconds = 0;
    u32 i;
    int keyframeSeconds;
    for (i = 0; i < light->keyframeCount; i++) {
        keyframeSeconds = func_021A07F8(light->season, &light->keyframes[i]);
        if (prevSeconds <= seconds && keyframeSeconds > seconds)
            return i;
        prevSeconds = keyframeSeconds;
    }
    return 0;
}

/* Second of the day of a keyframe; the hour is remapped by the season. */
int func_021A07F8(u32 season, const FieldLightKeyframe *keyframe)
{
    int hour = func_02011400(season, keyframe->hour);
    return hour * 3600 + keyframe->minute * 60;
}

/* Splits two GX_RGB colors into per-channel start and delta. */
void func_021A0818(FieldLightColorLerp *lerp, s32 from, u32 to)
{
    lerp->r.base = from & 0x1f;
    lerp->r.delta = (s16)(to & 0x1f) - (u16)lerp->r.base;
    lerp->g.base = (from & 0x3e0) >> 5;
    lerp->g.delta = (s16)((to & 0x3e0) >> 5) - (u16)lerp->g.base;
    lerp->b.base = (from & 0x7c00) >> 10;
    lerp->b.delta = (s16)((to & 0x7c00) >> 10) - (u16)lerp->b.base;
}

/*
 * Colour interpolation: each channel is base + delta * step / stepCount, packed GX_RGB.
 * Each channel is an s16 local set from the quotient and then `+=` its base; a
 * single-expression initialiser lets the compiler hoist all three divisions and
 * evaluate them right to left.
 */
u16 func_021A0860(FieldLightColorLerp *lerp, int step, int stepCount)
{
    s16 r = (s16)(lerp->r.delta * step / stepCount);
    s16 g, b;

    r += lerp->r.base;
    g = (s16)(lerp->g.delta * step / stepCount);
    g += lerp->g.base;
    b = (s16)(lerp->b.delta * step / stepCount);
    b += lerp->b.base;
    return GX_RGB(r, g, b);
}

static inline void setVec(FieldLightVec32 *vec, s32 x, s32 y, s32 z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

/*
 * Sets up the rotation from direction `from` to direction `to`: start vector,
 * rotation axis (cross product) and angle (arccos of the dot product).
 * The `const` on `from` is what puts its three loads ahead of the stores in
 * the original's order (from[2], from[1], from[0]; stores axis y, z, then x).
 */
void func_021A08CC(FieldLightDirLerp *lerp, const s16 *from, const s16 *to)
{
    s16 axis[3];

    setVec(&lerp->start, from[0], from[1], from[2]);
    func_0207CB68(from, to, axis);
    setVec(&lerp->axis, axis[0], axis[1], axis[2]);
    lerp->angle = func_0207D184(func_0207CAA4(from, to));
}

/* Rotates the start vector about the axis by angle * step / stepCount and normalizes it. */
void func_021A0918(FieldLightDirLerp *lerp, s32 step, s32 stepCount, s16 *out)
{
    s32 mtx[12];
    s32 vec[3];
    s32 vx, vy, vz;
    u32 sinCosIndex;

    sinCosIndex = (u16)(lerp->angle * step / stepCount) >> 4;
    func_0207B65C(mtx, &lerp->axis, d_020A1B38[sinCosIndex * 2], d_020A1B38[sinCosIndex * 2 + 1]);
    func_0207BC08(lerp, mtx, vec);
    func_0207CCA4(vec, vec);
    vz = vec[2];
    vy = vec[1];
    vx = vec[0];
    out[0] = vx;
    out[1] = vy;
    out[2] = vz;
}

void func_021A0974(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to)
{
    func_021A0980(blend, from, to, FIELD_LIGHT_BLEND_FRAMES);
}

/* Starts a blend from one keyframe to another over the given number of frames. */
void func_021A0980(FieldLightBlend *blend, FieldLightKeyframe *from, FieldLightKeyframe *to, u32 frames)
{
    FieldLightDir *toDir;
    FieldLightDir *fromDir;
    FieldLightDirLerp *dirLerp;
    FieldLightColorLerp *colorLerp;
    int i;

    i = 0;
    blend->step = i;
    blend->stepCount = frames;
    blend->hour = to->hour;
    blend->minute = to->minute;
    colorLerp = blend->slotColor;
    dirLerp = blend->slotDir;
    fromDir = from->slotDir;
    toDir = to->slotDir;
    for (; i < FIELD_LIGHT_SLOT_COUNT; i++) {
        func_021A0818(&colorLerp[i], from->slotColor[i], to->slotColor[i]);
        func_021A08CC(&dirLerp[i], (const s16 *)&fromDir[i], (const s16 *)&toDir[i]);
        blend->slotUsed[i] = to->slotUsed[i];
    }
    func_021A0818(&blend->materialDiffuse, from->materialDiffuse, to->materialDiffuse);
    func_021A0818(&blend->materialAmbient, from->materialAmbient, to->materialAmbient);
    func_021A0818(&blend->materialSpecular, from->materialSpecular, to->materialSpecular);
    func_021A0818(&blend->materialEmission, from->materialEmission, to->materialEmission);
    func_021A0818(&blend->fogColor, from->fogColor, to->fogColor);
    func_021A0818(&blend->clearColor, from->clearColor, to->clearColor);
}

/* Starts a blend from a keyframe to one flat color (slot directions stay). */
void func_021A0A50(FieldLightBlend *blend, FieldLightKeyframe *from, u32 color, u32 frames)
{
    s32 i;

    blend->step = 0;
    blend->stepCount = frames;
    blend->hour = from->hour;
    blend->minute = from->minute;
    for (i = 0; i < FIELD_LIGHT_SLOT_COUNT; i++) {
        func_021A0818(&blend->slotColor[i], from->slotColor[i], color);
        func_021A08CC(&blend->slotDir[i], (const s16 *)&from->slotDir[i], (const s16 *)&from->slotDir[i]);
        blend->slotUsed[i] = from->slotUsed[i];
    }
    func_021A0818(&blend->materialDiffuse, from->materialDiffuse, color);
    func_021A0818(&blend->materialAmbient, from->materialAmbient, color);
    func_021A0818(&blend->materialSpecular, from->materialSpecular, color);
    func_021A0818(&blend->materialEmission, from->materialEmission, color);
    func_021A0818(&blend->fogColor, from->fogColor, color);
    func_021A0818(&blend->clearColor, from->clearColor, color);
}

void func_021A0B14(FieldLightBlend *blend)
{
    if (blend->step < blend->stepCount)
        blend->step++;
}

int func_021A0B34(const FieldLightBlend *blend)
{
    if (blend->step < blend->stepCount) {
        return 1;
    }
    return 0;
}

/*
 * Evaluates the blend at its current step into a keyframe. The source pointer
 * must be const: without it the six trailing strh stores are scheduled ahead of
 * the next call's `adds rN, #0xf0/#0xf2` address setup (24 bytes differ).
 */
void func_021A0B4C(const FieldLightBlend *blend, FieldLightKeyframe *out)
{
    s32 i;
    u16 color;

    out->hour = blend->hour;
    out->minute = blend->minute;
    for (i = 0; i < FIELD_LIGHT_SLOT_COUNT; i++) {
        out->slotColor[i] = func_021A0860((FieldLightColorLerp *)&blend->slotColor[i], blend->step, blend->stepCount);
        func_021A0918((FieldLightDirLerp *)&blend->slotDir[i], blend->step, blend->stepCount, (s16 *)&out->slotDir[i]);
        out->slotUsed[i] = blend->slotUsed[i];
    }
    color = func_021A0860((FieldLightColorLerp *)&blend->materialDiffuse, blend->step, blend->stepCount);
    out->materialDiffuse = color;
    color = func_021A0860((FieldLightColorLerp *)&blend->materialAmbient, blend->step, blend->stepCount);
    out->materialAmbient = color;
    color = func_021A0860((FieldLightColorLerp *)&blend->materialSpecular, blend->step, blend->stepCount);
    out->materialSpecular = color;
    color = func_021A0860((FieldLightColorLerp *)&blend->materialEmission, blend->step, blend->stepCount);
    out->materialEmission = color;
    color = func_021A0860((FieldLightColorLerp *)&blend->fogColor, blend->step, blend->stepCount);
    out->fogColor = color;
    color = func_021A0860((FieldLightColorLerp *)&blend->clearColor, blend->step, blend->stepCount);
    out->clearColor = color;
}

FieldLightFade *func_021A0C50(FieldLightFade *fade, u16 frames, u32 returnFrames, u32 color)
{
    fade->state = FIELD_LIGHT_FADE_START;
    fade->frames = frames;
    fade->returnFrames = returnFrames;
    fade->color = color;
    return fade;
}

void func_021A0C60(FieldLightFade *fade, u16 frames, u16 color)
{
    fade->state = FIELD_LIGHT_FADE_START;
    fade->frames = frames;
    fade->color = color;
    fade->returnFrames = FIELD_LIGHT_FADE_NO_RETURN;
}

/* Runs the fade state machine; returns 1 when no fade is active. */
s32 func_021A0C74(FieldLightFade *fade, FieldLightBlend *blend, FieldLightKeyframe *current, FieldLightKeyframe *target)
{
    switch (fade->state) {
    case FIELD_LIGHT_FADE_START:
        func_021A0A50(blend, current, fade->color, fade->frames);
        fade->state = FIELD_LIGHT_FADE_HOLD;
        break;
    case FIELD_LIGHT_FADE_HOLD:
        if (func_021A0B34(blend) == 0) {
            if (fade->returnFrames != FIELD_LIGHT_FADE_NO_RETURN) {
                func_021A0980(blend, current, target, fade->returnFrames);
            }
            fade->state = FIELD_LIGHT_FADE_RETURN;
        }
        break;
    case FIELD_LIGHT_FADE_RETURN:
        if (func_021A0B34(blend) == 0) {
            fade->state = FIELD_LIGHT_FADE_IDLE;
        }
        break;
    case FIELD_LIGHT_FADE_IDLE:
        return 1;
    }
    return 0;
}

int func_021A0CE4(FieldLightFade *fade)
{
    if (fade->state != 0) {
        return 1;
    }
    return 0;
}
