/*
 * file:     rail_attr.c
 * unit:     yes
 * function: func_021BB088, func_021BB0A4, func_021BB0B4, func_021BB11C, func_021BB13C, func_021BB188, func_021BB1A0, func_021BB1AC, func_021BB1B8, func_021BB1C4, func_021BB1D0, func_021BB1DC, func_021BB1E8
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
 *   func_020307B0  0x020307B0  arm
 *   func_0204A298  0x0204A298  arm
 *   func_02030734  0x02030734  arm
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *p);
extern void *func_0204A298(int arcId, int dataId, int compressed, int heapId, u32 *outSize);

RailAttr *func_021BB088(int heapId);
void func_021BB0A4(RailAttr *attr);
void func_021BB0B4(RailAttr *attr, u32 dataId, u32 heapId);
void func_021BB11C(RailAttr *attr);
int func_021BB13C(const RailAttr *attr, const RailLocation *location);

extern int d_021DE2C4;

RailAttr *func_021BB088(int heapId)
{
    return func_02030734((u16)heapId, sizeof(RailAttr), 1, (const char *)&d_021DE2C4, 0x5C);
}

void func_021BB0A4(RailAttr *attr)
{
    func_021BB11C(attr);
    func_020307B0(attr);
}

void func_021BB0B4(RailAttr *attr, u32 dataId, u32 heapId)
{
    u32 i = 0;
    u32 offset;

    attr->data = func_0204A298(RAIL_ATTR_ARC_ID, dataId, 0, (u16)heapId, &attr->dataSize);
    attr->lineCount = *(u32 *)attr->data;
    attr->lines = func_02030734((u16)heapId, attr->lineCount * 4, 1, (const char *)&d_021DE2C4, 0x86);
    offset = 4;
    for (i = 0; i < attr->lineCount; i++) {
        RailAttrLine *line;

        attr->lines[i] = (RailAttrLine *)((u32)attr->data + offset);
        line = attr->lines[i];
        offset += line->width * line->length * 4 + 4;
    }
}

void func_021BB11C(RailAttr *attr)
{
    if (attr->data != 0) {
        func_020307B0(attr->lines);
        func_020307B0(attr->data);
        attr->lineCount = 0;
        attr->lines = 0;
        attr->data = 0;
    }
}

int func_021BB13C(const RailAttr *attr, const RailLocation *location)
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

int func_021BB188(u16 value)
{
    if ((u16)(value + 0xFF60) <= 1) {
        return 1;
    }
    return 0;
}

int func_021BB1A0(int value)
{
    if (value == 163)
        return 1;
    return 0;
}

int func_021BB1AC(int value)
{
    if (value == 165)
        return 1;
    return 0;
}

int func_021BB1B8(int value)
{
    if (value == 164)
        return 1;
    return 0;
}

int func_021BB1C4(int value)
{
    if (value == 167)
        return 1;
    return 0;
}

int func_021BB1D0(int value)
{
    if (value == 166)
        return 1;
    return 0;
}

int func_021BB1DC(int value)
{
    if (value == 168)
        return 1;
    return 0;
}

int func_021BB1E8(int value)
{
    if (value == 176)
        return 1;
    return 0;
}
