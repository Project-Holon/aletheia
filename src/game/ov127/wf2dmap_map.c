/*
 * file:     wf2dmap_map.c
 * unit:     yes
 * function: WF2DMAP_MAP_IsEmpty, WF2DMAP_MAP_CreateGrid, WF2DMAP_MAP_DeleteGrid, WF2DMAP_MAP_GetWidth, WF2DMAP_MAP_GetHeight, WF2DMAP_MAP_CopyEntries, WF2DMAP_MAP_GetCell, WF2DMAP_MAP_IsCellBlocked, WF2DMAP_MAP_GetCellValue
 * address:  0x021C4790
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wf2dmap_map.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   sWf2dmapMapFileName 0x021C6110 data a1
 *   func_020307B0 0x020307B0 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   sWf2dmapEmptyCell 0x021C600C data a4
 */
#include "wf2dmap_map_shared_types.h"

/* Tile grid of the 2D map (wf2dmap_map.c). */
typedef struct Wf2dmapMapGrid {
    u16 width;
    u16 height;
    void *entries;
} Wf2dmapMapGrid;

/* One grid cell: bit 0 is the blocked flag, the rest a value. */
typedef union Wf2dmapCell {
    u32 raw;
    struct { u32 flag:1; u32 value:31; } bits;
} Wf2dmapCell;

extern void *func_02030734(u16,u32,int,const char *,u16);

extern u32 func_020307B0(void *p);

extern void MI_CpuCopy8(void *,const void *,u32);

int WF2DMAP_MAP_IsEmpty(char *p);

Wf2dmapMapGrid *WF2DMAP_MAP_CreateGrid(u32 w,u32 h,u32 heap);

void WF2DMAP_MAP_DeleteGrid(u8 *p);

u16 WF2DMAP_MAP_GetWidth(u16 *p);

u16 WF2DMAP_MAP_GetHeight(u16 *p);

void WF2DMAP_MAP_CopyEntries(u8 *p,void *out);

Wf2dmapCell WF2DMAP_MAP_GetCell(u8 *p, u32 x, u32 y);

int WF2DMAP_MAP_IsCellBlocked(u8 *p, u16 x, u16 y);

u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y);

extern const char sWf2dmapMapFileName[];

extern Wf2dmapCell sWf2dmapEmptyCell;

int WF2DMAP_MAP_IsEmpty(char *p)
{
    return ((Wf2dmapMapGrid *)p)->entries == 0;
}

Wf2dmapMapGrid *WF2DMAP_MAP_CreateGrid(u32 w,u32 h,u32 heap) { Wf2dmapMapGrid *p;p=func_02030734(heap,8,1,sWf2dmapMapFileName,76);p->width=w;p->height=h;p->entries=func_02030734(heap,p->width*p->height*4,1,sWf2dmapMapFileName,83);return p; }

/*
 * Extent remainder: 2-byte zero padding, filed getters 021C47F8/47FC,
 * and separately filed follower ov127_func_021C4800.c.
 */
void WF2DMAP_MAP_DeleteGrid(u8 *p) { func_020307B0(((Wf2dmapMapGrid *)p)->entries);func_020307B0(p); }

/*
 * Leaf: ldrh r0,[r0]; bx lr.  Blocker of ov099 func_021BA0F8.
 */
u16 WF2DMAP_MAP_GetWidth(u16 *p)
{
    return p[0];
}

u16 WF2DMAP_MAP_GetHeight(u16 *p)
{
    return p[1];
}

/*
 * Follower of 021C47E4, separate because 021C47F8/47FC already have shards.
 */
void WF2DMAP_MAP_CopyEntries(u8 *p,void *out) { MI_CpuCopy8(out,((Wf2dmapMapGrid *)p)->entries,((Wf2dmapMapGrid *)p)->width * ((Wf2dmapMapGrid *)p)->height * 4); }

Wf2dmapCell WF2DMAP_MAP_GetCell(u8 *p, u32 x, u32 y)
{
 Wf2dmapCell r = sWf2dmapEmptyCell;
 if (((Wf2dmapMapGrid *)p)->width > x && ((Wf2dmapMapGrid *)p)->height > y) r=*(Wf2dmapCell *)((u8 *)((Wf2dmapMapGrid *)p)->entries + (x + ((Wf2dmapMapGrid *)p)->width*y)*4);
 return r;
}

/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int WF2DMAP_MAP_IsCellBlocked(u8 *p, u16 x, u16 y) { Wf2dmapCell r=WF2DMAP_MAP_GetCell(p,x,y); if(r.raw==(u32)-1) return 1; return r.bits.flag; }

u32 WF2DMAP_MAP_GetCellValue(u8 *p, u16 x, u16 y) { Wf2dmapCell r=WF2DMAP_MAP_GetCell(p,x,y); if(r.raw==(u32)-1) return 0; return r.bits.value; }
