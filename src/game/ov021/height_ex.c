/*
 * file:     height_ex.c
 * unit:     yes
 * function: func_021C0598, func_021C05D4, func_021C0628, func_021C0674, func_021C0688, func_021C068C, func_021C06A8, func_021C06B4, func_021C06C0
 * address:  0x021C0598
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_player_grid_event.c at 0x021C0598 (lane CL118, __FILE__ anchor 021C05D4 (height_ex.c); 021C0598 is its rect test, 021C06C0 the last slot setter called by field_g3d_mapper.c and ov043).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   sub_02030734  0x02030734  arm
 *   d_021DE3A0  0x021DE3A0  data  ov021  a1
 */
#include "height_ex_types.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern void *sub_02030734(u32 heapId, u32 size, int align, const char *file, unsigned short line);
extern u32 func_020307B0(void *block);

int func_021C0598(int x, int z, const HeightExArea *area, int areaIndex);
HeightExTable *func_021C05D4(u32 count, u32 heapId);
void func_021C0628(int index, int x, int z, int width, int depth, int height, int attr, HeightExTable *table);
void func_021C0674(HeightExTable *table);
int func_021C0688(const HeightExTable *table);
int func_021C068C(int x, int z, const HeightExTable *table, u8 index);
int func_021C06A8(u8 index, const HeightExTable *table);
int func_021C06B4(u8 index, const HeightExTable *table);
void func_021C06C0(u8 index, int height, HeightExTable *table);

extern u8 d_021DE3A0[];

/*
 * Point-in-rectangle test against an active area. The index is not read.
 */
int func_021C0598(int x, int z, const HeightExArea *area, int areaIndex)
{
    int left, top, right, bottom;

    if (area->active == 0)
        return 0;
    left = area->x;
    top = area->z;
    right = left + area->width - 1;
    bottom = top + area->depth - 1;
    if (left <= x && x <= right && top <= z && z <= bottom)
        return 1;
    return 0;
}

HeightExTable *func_021C05D4(u32 count, u32 heapId)
{
    u8 i;
    HeightExTable *table;

    i = 0;
    table = (HeightExTable *)sub_02030734(heapId, 8, 0, (const char *)d_021DE3A0, 0x5a);
    table->areas = (HeightExArea *)sub_02030734(heapId, count * sizeof(HeightExArea), 0, (const char *)d_021DE3A0, 0x5b);
    table->count = count;
    for (i = 0; i < count; i++) {
        table->areas[i].active = 0;
    }
    return table;
}

/*
 * Fills area index when it is in range and not yet active.
 */
void func_021C0628(int index, int x, int z, int width, int depth, int height, int attr, HeightExTable *table)
{
    if (index < table->count && table->areas[index].active == 0) {
        table->areas[index].x = x;
        table->areas[index].z = z;
        table->areas[index].width = width;
        table->areas[index].depth = depth;
        table->areas[index].height = height;
        table->areas[index].attr = attr;
        table->areas[index].active = 1;
    }
}

/*
 * Frees the areas array, then the table.
 */
void func_021C0674(HeightExTable *table)
{
    func_020307B0(table->areas);
    func_020307B0(table);
}

int func_021C0688(const HeightExTable *table)
{
    return table->count;
}

int func_021C068C(int x, int z, const HeightExTable *table, u8 index)
{
    if (func_021C0598(x, z, &table->areas[index], index) != 0) {
        return 1;
    }
    return 0;
}

int func_021C06A8(u8 index, const HeightExTable *table)
{
    return table->areas[index].height;
}

int func_021C06B4(u8 index, const HeightExTable *table)
{
    return table->areas[index].attr;
}

void func_021C06C0(u8 index, int height, HeightExTable *table)
{
    table->areas[index].height = height;
}
