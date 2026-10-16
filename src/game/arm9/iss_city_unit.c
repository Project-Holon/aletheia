/*
 * file:     iss_city_unit.c
 * unit:     yes
 * function: ISS_CITY_UNIT_Create, ISS_CITY_UNIT_Delete, ISS_CITY_UNIT_GetZoneId, ISS_CITY_UNIT_CalcVolume, ISS_CITY_UNIT_Copy, ISS_CITY_UNIT_CalcVolumeFromAxes, ISS_CITY_UNIT_CalcVolumeX, ISS_CITY_UNIT_CalcVolumeY, ISS_CITY_UNIT_CalcVolumeZ, ISS_CITY_UNIT_FindStepX, ISS_CITY_UNIT_FindStepY, ISS_CITY_UNIT_FindStepZ, ISS_CITY_UNIT_GetCenterX, ISS_CITY_UNIT_GetCenterY, ISS_CITY_UNIT_GetCenterZ, ISS_CITY_UNIT_Interpolate
 * address:  0x0202AEEC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from iss_city_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   ISS_CITY_UNIT_sSourceFileName     0x020A76F8  data
 *   func_020307B0  0x020307B0  arm
 *   _s32_to_double  0x0209B750  arm
 *   func_0209AC04   0x0209AC04  arm
 *   _d2s            0x0209C508  arm
 *   ARC_TOOL_LoadMemberRange  0x02048F88  arm
 */
#include "iss_city_sys_shared_types.h"

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *sourceFile, u16 sourceLine);

extern void *ARC_TOOL_LoadMemberRange(u32 archiveId, u32 memberIndex, u32 heapId, u32 mode, u32 size);

extern u32 func_020307B0(void *block);

extern double _s32_to_double(s32 v);

extern double func_0209AC04(double lhs, double rhs);

extern s32 _d2s(double d);

struct IssCityUnit *ISS_CITY_UNIT_Create(u32 heapId, u32 memberIndex);

void ISS_CITY_UNIT_Delete(struct IssCityUnit *unit);

u32 ISS_CITY_UNIT_GetZoneId(struct IssCityUnit *unit);

u8 ISS_CITY_UNIT_CalcVolume(const struct IssCityUnit *unit, const s32 *playerPos);

void ISS_CITY_UNIT_Copy(const struct IssCityUnit *src, struct IssCityUnit *dst);

u8 ISS_CITY_UNIT_CalcVolumeFromAxes(const struct IssCityUnit *unit, const s32 *playerPos);

u8 ISS_CITY_UNIT_CalcVolumeX(const struct IssCityUnit *unit, const s32 *playerPos);

u8 ISS_CITY_UNIT_CalcVolumeY(const struct IssCityUnit *unit, const s32 *playerPos);

u8 ISS_CITY_UNIT_CalcVolumeZ(const struct IssCityUnit *unit, const s32 *playerPos);

u32 ISS_CITY_UNIT_FindStepX(const struct IssCityUnit *unit, const s32 *playerPos);

u32 ISS_CITY_UNIT_FindStepY(const struct IssCityUnit *unit, const s32 *playerPos);

u32 ISS_CITY_UNIT_FindStepZ(const struct IssCityUnit *unit, const s32 *playerPos);

s32 ISS_CITY_UNIT_GetCenterX(const struct IssCityUnit *unit);

s32 ISS_CITY_UNIT_GetCenterY(const struct IssCityUnit *unit);

s32 ISS_CITY_UNIT_GetCenterZ(const struct IssCityUnit *unit);

s32 ISS_CITY_UNIT_Interpolate(s32 distA, s32 volumeA, s32 distB, s32 volumeB, s32 dist);

extern const char ISS_CITY_UNIT_sSourceFileName[];

/*
 * Allocates a 0x28-byte node with func_02030734, wraps it with ARC_TOOL_LoadMemberRange,
 * runs ISS_CITY_UNIT_Copy over the pair and releases the wrapper.  The pair is
 * passed as (wrapper, node): r0 is left holding the wrapper from the second
 * allocation when ISS_CITY_UNIT_Copy is reached, with the node moved into r1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_Create.c \
 *       --func ISS_CITY_UNIT_Create --addr 0x0202AEEC --thumb --cc 1.1p1
 */
struct IssCityUnit *ISS_CITY_UNIT_Create(u32 heapId, u32 memberIndex)
{
    struct IssCityUnit *unit = func_02030734(heapId, sizeof(struct IssCityUnit), 0, ISS_CITY_UNIT_sSourceFileName, 0x6c);
    struct IssCityUnit *rawMember = ARC_TOOL_LoadMemberRange(0x84, memberIndex, heapId, 0, sizeof(struct IssCityUnit));
    ISS_CITY_UNIT_Copy(rawMember, unit);
    func_020307B0(rawMember);
    return unit;
}

void ISS_CITY_UNIT_Delete(struct IssCityUnit *unit)
{
    func_020307B0(unit);
}

u32 ISS_CITY_UNIT_GetZoneId(struct IssCityUnit *unit)
{
    return unit->zoneId;
}

/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * A bare tail-call thunk to ISS_CITY_UNIT_CalcVolumeFromAxes (ldr r3, pool; bx r3; .word
 * 0x0202AF75).  Blocked at MATCH on `literal`: the pointer word 0x0202AF75
 * appears in exactly one literal pool image-wide, this thunk's own at
 * 0x0202AF38, so the ABS32 site has no outside witness.  There is no branch
 * to 0x0202AF74 anywhere else in the image either, so the `label` class is
 * empty too.  Closes when ISS_CITY_UNIT_CalcVolumeFromAxes acquires a manifest entry that is
 * not this file's own (a second reader of the thunk, or a matched
 * ISS_CITY_UNIT_CalcVolumeFromAxes elsewhere).
 *
 * THE BODY BELOW IS NEW (third unit pass).  The file carried the note alone
 * because the shape had been reported as a linker veneer with no C spelling:
 * it is not.  A plain tail call reproduces all 8 bytes - 4 of code plus the
 * pool word - byte for byte, and the IRQ-window `ldr r3, [pc, #0]` + `bx r3`
 * is exactly what this front end emits for it.  The one relocation therefore
 * stays a wildcard (its own pool word is inside the compared range), which is
 * the MATCH cap and the only thing that keeps this entry out of the manifest.
 *
 * It is the last link of this lane's 0x0202AE68 chain: src/pending/
 * ISS_CITY_SYS_CalcUnitVolume.c is capped on this address's `label`, which is empty while
 * this file cannot be an EXACT entry.  The whole chain needs ISS_CITY_UNIT_CalcVolumeFromAxes
 * (50 bytes, in another packet) filed.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_CITY_UNIT_CalcVolume.c \
 *       --func ISS_CITY_UNIT_CalcVolume --addr 0x0202AF34 --cc 1.1p1 --thumb
 */
u8 ISS_CITY_UNIT_CalcVolume(const struct IssCityUnit *unit, const s32 *playerPos)
{
    return ISS_CITY_UNIT_CalcVolumeFromAxes(unit, playerPos);
}

void ISS_CITY_UNIT_Copy(const struct IssCityUnit *src, struct IssCityUnit *dst)
{
    int i;
    dst->zoneId = src->zoneId;
    dst->centerGridX = src->centerGridX;
    dst->centerGridY = src->centerGridY;
    dst->centerGridZ = src->centerGridZ;
    for (i = 0; i < 6; i++) {
        dst->volumeSteps[i] = src->volumeSteps[i];
        dst->radiusX[i] = src->radiusX[i];
        dst->radiusY[i] = src->radiusY[i];
        dst->radiusZ[i] = src->radiusZ[i];
    }
}

/* Product of the three axis levels (0..127 each), renormalised by 127 * 127. */
/*
 * The head of the three-axis attenuation family: multiplies the X, Y and
 * Z unit responses (ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY / ISS_CITY_UNIT_CalcVolumeZ, each a
 * 0..127 fadeLevel) and renormalises by 127*127 == 0x3f01, so the product of
 * three 7-bit levels comes back as one 7-bit fadeLevel.  The result is
 * truncated to u8 by the caller-visible return type.
 *
 * Blocked at MATCH: every concrete byte is right.  The three THM_CALL
 * sites at +0x06, +0x10 and +0x1a have no witness outside
 * 0x0202AF74..0x0202AFAC -- this is the only caller of any of the three
 * axis routines in the whole image, so `label` refuses them and `matched`
 * has nothing to point at while ISS_CITY_UNIT_CalcVolumeX / ISS_CITY_UNIT_CalcVolumeY /
 * ISS_CITY_UNIT_CalcVolumeZ stay unfiled (each is a 6-to-13 byte scheduling near
 * miss, see docs/notes/ISS_CITY_UNIT_CalcVolumeX.c.txt and its two twins).
 * --suggest-split cannot help: the compared range is one function.
 * Blocking evidence class: none available (needs an EXACT manifest entry
 * at 0x0202AFAC / 0x0202AFFC / 0x0202B04C, or a second caller).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeFromAxes.c \
 *       --func ISS_CITY_UNIT_CalcVolumeFromAxes --addr 0x0202AF74 --cc 1.1p1 --thumb
 */
u8 ISS_CITY_UNIT_CalcVolumeFromAxes(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 x;
    s32 y;
    s32 z;
    x = ISS_CITY_UNIT_CalcVolumeX(unit, playerPos);
    y = ISS_CITY_UNIT_CalcVolumeY(unit, playerPos);
    z = ISS_CITY_UNIT_CalcVolumeZ(unit, playerPos);
    return (u8)(z * (x * y) / 0x3f01);
}

/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the first axis: playerPos[0], radius table at +0x16.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeX.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeX.c  *       --func ISS_CITY_UNIT_CalcVolumeX --addr 0x0202AFAC --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeX(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepX(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[0] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterX(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusX[step] << 4, unit->volumeSteps[step],
                             unit->radiusX[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}

/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the second axis: playerPos[1], radius table at +0x1c.
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeY.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeY.c  *       --func ISS_CITY_UNIT_CalcVolumeY --addr 0x0202AFFC --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeY(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepY(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[1] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterY(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusY[step] << 4, unit->volumeSteps[step],
                             unit->radiusY[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}

/*
 * iss_city_unit.c (docs/families/iss_city_unit.h): the third axis: playerPos[2], radius table at +0x22
 * (past the ldrb reach, hence one `adds` per load).
 * EXACT* (the listing extent includes the 2-byte pad).
 *
 * The residue every earlier pass left (docs/notes/ISS_CITY_UNIT_CalcVolumeZ.c.txt: the
 * stacked fifth argument stored to [sp] before the step address
 * computations instead of after them) was the const-qualification of the
 * pointers: `const struct IssCityUnit *unit`, `const s32 *playerPos` and
 * const-pointee callees.  The three axis twins close with the same change.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_CITY_UNIT_CalcVolumeZ.c  *       --func ISS_CITY_UNIT_CalcVolumeZ --addr 0x0202B04C --thumb --cc 1.1p1
 */
u8 ISS_CITY_UNIT_CalcVolumeZ(const struct IssCityUnit *unit, const s32 *playerPos)
{
    u32 step;
    u32 prevStep;
    s32 gridPos;
    s32 dist;
    step = ISS_CITY_UNIT_FindStepZ(unit, playerPos);
    if (step == 0)
        prevStep = 0;
    else
        prevStep = (u8)(step - 1);
    if (step == prevStep)
        return unit->volumeSteps[step];
    gridPos = playerPos[2] >> 12;
    dist = gridPos - ISS_CITY_UNIT_GetCenterZ(unit);
    if (dist < 0)
        dist = -dist;
    return (u8)ISS_CITY_UNIT_Interpolate(unit->radiusZ[step] << 4, unit->volumeSteps[step],
                             unit->radiusZ[prevStep] << 4, unit->volumeSteps[prevStep], dist);
}

u32 ISS_CITY_UNIT_FindStepX(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[0] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterX(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusX[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}

u32 ISS_CITY_UNIT_FindStepY(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[1] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterY(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusY[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}

u32 ISS_CITY_UNIT_FindStepZ(const struct IssCityUnit *unit, const s32 *playerPos)
{
    s32 step;
    s32 gridPos = playerPos[2] >> 12;
    s32 dist = gridPos - ISS_CITY_UNIT_GetCenterZ(unit);
    if (dist < 0) dist = -dist;
    for (step = 0; step < 6; step++) {
        if ((unit->radiusZ[step] << 4) <= dist) return (u8)step;
    }
    return 0;
}

s32 ISS_CITY_UNIT_GetCenterX(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridX << 4))));
}

s32 ISS_CITY_UNIT_GetCenterY(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridY << 4))));
}

s32 ISS_CITY_UNIT_GetCenterZ(const struct IssCityUnit *unit)
{
    return _d2s(func_0209AC04(8.0, _s32_to_double((s32)(unit->centerGridZ << 4))));
}

s32 ISS_CITY_UNIT_Interpolate(s32 distA, s32 volumeA, s32 distB, s32 volumeB, s32 dist)
{
    return volumeA + (volumeB - volumeA) * (dist - distA) / (distB - distA);
}
