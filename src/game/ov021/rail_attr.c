/*
 * file:     rail_attr.c
 * unit:     yes
 * function: RAIL_ATTR_Create, RAIL_ATTR_Delete, RAIL_ATTR_Load, RAIL_ATTR_Release, RAIL_ATTR_GetAttribute, RAIL_ATTR_IsSignBoard, RAIL_ATTR_IsJumpStart, RAIL_ATTR_IsForceMoveUp, RAIL_ATTR_IsForceMoveDown, RAIL_ATTR_IsForceMoveLeft, RAIL_ATTR_IsForceMoveRight, RAIL_ATTR_IsForceMoveStop, RAIL_ATTR_IsSlipDown
 * address:  0x021BB088
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Split by lane CL115 from field_nogrid_mapper.c at the __FILE__ anchor cuts.
 *
 * symbols:
 *   d_021DE2C4     0x021DE2C4  data  a4
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 */
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;

#define RAIL_ATTR_ARC_ID 0x4f       /* archive that holds the rail and rail attribute data */
#define RAIL_LOCATION_TYPE_LINE 1   /* RailLocation.type of a place on a rail line */
#define RAIL_ATTR_NONE (-1)

/* Attribute grid of one rail line: width columns by length rows. */
typedef struct RailAttrLine {
    u16 width;      /* 0x00 */
    u16 length;     /* 0x02 */
    u32 attr[1];    /* 0x04: width * length entries, row by row */
} RailAttrLine;

/* Rail attribute data of the current map (0x10 bytes, rail_attr.c line 0x5C
 * allocation). */
typedef struct RailAttr {
    void *data;              /* 0x00: the loaded archive file */
    u32 dataSize;            /* 0x04 */
    u32 lineCount;           /* 0x08: first word of the file */
    RailAttrLine **lines;    /* 0x0C: one pointer per line into data */
} RailAttr;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern unsigned int GFL_HEAP_Free(void *p);
extern int ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, unsigned short heapID, unsigned int *out);

RailAttr *RAIL_ATTR_Create(int heapId);
void RAIL_ATTR_Delete(RailAttr *attr);
void RAIL_ATTR_Load(RailAttr *attr, u32 dataId, u32 heapId);
void RAIL_ATTR_Release(RailAttr *attr);
int RAIL_ATTR_GetAttribute(const RailAttr *attr, const RailLocation *location);

extern int d_021DE2C4;

RailAttr *RAIL_ATTR_Create(int heapId)
{
    return GFL_HEAP_Alloc((u16)heapId, sizeof(RailAttr), 1, (const char *)&d_021DE2C4, 0x5C);
}

void RAIL_ATTR_Delete(RailAttr *attr)
{
    RAIL_ATTR_Release(attr);
    GFL_HEAP_Free(attr);
}

void RAIL_ATTR_Load(RailAttr *attr, u32 dataId, u32 heapId)
{
    u32 i = 0;
    u32 offset;

    attr->data = (void *)ARC_UTIL_LoadMemberWithSize(RAIL_ATTR_ARC_ID, dataId, 0, (u16)heapId, &attr->dataSize);
    attr->lineCount = *(u32 *)attr->data;
    attr->lines = GFL_HEAP_Alloc((u16)heapId, attr->lineCount * 4, 1, (const char *)&d_021DE2C4, 0x86);
    offset = 4;
    for (i = 0; i < attr->lineCount; i++) {
        RailAttrLine *line;

        attr->lines[i] = (RailAttrLine *)((u32)attr->data + offset);
        line = attr->lines[i];
        offset += line->width * line->length * 4 + 4;
    }
}

void RAIL_ATTR_Release(RailAttr *attr)
{
    if (attr->data != 0) {
        GFL_HEAP_Free(attr->lines);
        GFL_HEAP_Free(attr->data);
        attr->lineCount = 0;
        attr->lines = 0;
        attr->data = 0;
    }
}

int RAIL_ATTR_GetAttribute(const RailAttr *attr, const RailLocation *location)
{
    int result = RAIL_ATTR_NONE;
    if (location->type == RAIL_LOCATION_TYPE_LINE) {
        unsigned lineIndex = location->railIndex;
        if (attr->lineCount > lineIndex) {
            RailAttrLine *line = attr->lines[lineIndex];
            unsigned width = line->width;
            int x = location->widthGrid + (width >> 1);
            int y = location->lineGrid;
            if ((int)width > x && line->length > y && x >= 0 && y >= 0)
                result = line->attr[x + width * y];
        }
    }
    return result;
}

/* Attribute value checks (values of the attribute words above). */

int RAIL_ATTR_IsSignBoard(u16 value)
{
    if ((u16)(value + 0xFF60) <= 1) {
        return 1;
    }
    return 0;
}

int RAIL_ATTR_IsJumpStart(int value)
{
    if (value == 163)
        return 1;
    return 0;
}

int RAIL_ATTR_IsForceMoveUp(int value)
{
    if (value == 165)
        return 1;
    return 0;
}

int RAIL_ATTR_IsForceMoveDown(int value)
{
    if (value == 164)
        return 1;
    return 0;
}

int RAIL_ATTR_IsForceMoveLeft(int value)
{
    if (value == 167)
        return 1;
    return 0;
}

int RAIL_ATTR_IsForceMoveRight(int value)
{
    if (value == 166)
        return 1;
    return 0;
}

int RAIL_ATTR_IsForceMoveStop(int value)
{
    if (value == 168)
        return 1;
    return 0;
}

int RAIL_ATTR_IsSlipDown(int value)
{
    if (value == 176)
        return 1;
    return 0;
}
