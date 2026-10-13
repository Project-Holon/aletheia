/*
 * file:     field_zonefog.c
 * unit:     yes
 * function: func_021A02C4, func_021A02F4, func_021A030C, func_021A0338, func_021A0354, func_021A0358, func_021A0380, func_021A0390, func_021A03A4, func_021A03B8, func_021A03CC
 * address:  0x021A02C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c (CL110): __FILE__ anchor field_zonefog.c at 0x021A02C4; ends at the field_light.c anchor 0x021A03D0.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DDE28     0x021DDE28  data
 *   func_02049238  0x02049238  arm
 *   func_0204A380  0x0204A380  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

#define ZONEFOG_ID_NONE 0x0FFFFFFF
#define ZONEFOG_ARC_ID  0x51

/* One zone fog record loaded from archive ZONEFOG_ARC_ID. */
typedef struct {
    int fogOffset;
    int fogSlope;
} ZoneFogData;

/* Zone fog and light ids of the current zone (0x10 bytes). */
typedef struct {
    u8 loadRequest;
    s8 loadWait;
    u16 fogId;
    ZoneFogData *data;
    int lightId;
    void *arcHandle;
} FieldZoneFog;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(void *arcHandle);
extern void *func_0204A380(void *arcHandle, u32 dataId, u32 heapLow, u32 heapId);
void func_021A0358(FieldZoneFog *zoneFog);
extern char d_021DDE28[];

FieldZoneFog *func_021A02C4(u16 heapId)
{
    FieldZoneFog *zoneFog = (FieldZoneFog *)func_02030734(heapId, sizeof(FieldZoneFog), 1, d_021DDE28, 0x51);
    zoneFog->lightId = ZONEFOG_ID_NONE;
    zoneFog->arcHandle = func_020490F4(ZONEFOG_ARC_ID, heapId);
    return zoneFog;
}

int func_021A02F4(FieldZoneFog *zoneFog)
{
    func_02049238(zoneFog->arcHandle);
    func_021A0358(zoneFog);
    return func_020307B0(zoneFog);
}

/* Loads the requested fog record once the wait count reaches zero. */
void func_021A030C(FieldZoneFog *zoneFog, u32 heapId)
{
    if (zoneFog->loadRequest == 1) {
        zoneFog->loadWait--;
        if (zoneFog->loadWait <= 0) {
            zoneFog->data = func_0204A380(zoneFog->arcHandle, zoneFog->fogId, 0, heapId);
            zoneFog->loadRequest = 0;
        }
    }
}

void func_021A0338(FieldZoneFog *zoneFog, u32 fogId, u32 lightId, u8 loadWait)
{
    if (fogId != ZONEFOG_ID_NONE) {
        zoneFog->loadRequest = 1;
        zoneFog->fogId = fogId;
        zoneFog->loadWait = loadWait;
    }
    zoneFog->lightId = lightId;
}

u8 func_021A0354(FieldZoneFog *zoneFog)
{
    return zoneFog->loadRequest;
}

void func_021A0358(FieldZoneFog *zoneFog)
{
    if (zoneFog->data != 0) {
        func_020307B0(zoneFog->data);
        zoneFog->data = 0;
    }
    zoneFog->lightId = ZONEFOG_ID_NONE;
    if (zoneFog->loadRequest == 1) {
        zoneFog->loadRequest = 0;
    }
}

int func_021A0380(FieldZoneFog *zoneFog)
{
    return zoneFog->data != 0 ? 1 : 0;
}

int func_021A0390(FieldZoneFog *zoneFog)
{
    return zoneFog->lightId != ZONEFOG_ID_NONE ? 1 : 0;
}

int func_021A03A4(FieldZoneFog *zoneFog)
{
    ZoneFogData *data = zoneFog->data;

    if (data != 0) {
        return data->fogOffset;
    }
    return ZONEFOG_ID_NONE;
}

int func_021A03B8(FieldZoneFog *zoneFog)
{
    ZoneFogData *data = zoneFog->data;

    if (data != 0) {
        return data->fogSlope;
    }
    return ZONEFOG_ID_NONE;
}

int func_021A03CC(FieldZoneFog *zoneFog)
{
    return zoneFog->lightId;
}
