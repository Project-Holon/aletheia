#ifndef ALETHEIA_OV021_HEIGHT_EX_TYPES_H
#define ALETHEIA_OV021_HEIGHT_EX_TYPES_H

/*
 * Height extension areas of a field map: a table of rectangles on the map
 * plane. Each area carries a height value and an attribute value that the
 * map code reads back by index, and an active flag that is set once the
 * area has been filled in.
 */

/* One area (0x1C bytes). */
typedef struct HeightExArea {
    int x;
    int z;
    int width;
    int depth;
    int height;
    int active;
    int attr;
} HeightExArea;

/* Heap table of areas (8 bytes); the areas array holds count entries. */
typedef struct HeightExTable {
    int count;
    HeightExArea *areas;
} HeightExTable;

#endif
