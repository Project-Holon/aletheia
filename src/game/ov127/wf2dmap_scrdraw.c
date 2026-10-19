/*
 * file:     wf2dmap_scrdraw.c
 * unit:     yes
 * function: WF2DMAP_SCRDRAW_SetPoint, WF2DMAP_SCRDRAW_GetPointY, WF2DMAP_SCRDRAW_GetPointX, WF2DMAP_SCRDRAW_CreateBitmapDesc, WF2DMAP_SCRDRAW_DeleteBitmapDesc, WF2DMAP_SCRDRAW_UpdatePosition, WF2DMAP_SCRDRAW_LoadPalette, WF2DMAP_SCRDRAW_SetScroll, WF2DMAP_SCRDRAW_DrawTilesClipped, WF2DMAP_SCRDRAW_DrawTilesWrapped, WF2DMAP_SCRDRAW_GetMode, WF2DMAP_SCRDRAW_GetTileSource
 * address:  0x021C59DC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   sWf2dmapScrdrawFileName 0x021C6144 data a1
 *   GFL_HEAP_Free  0x020307B0  arm
 *   CLACT_SetSurfacePos 0x0204B09C arm
 *   sWf2dmapPaletteDesc 0x021C60C4 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 */

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed char s8;

/* Screen point; this file stores the y coordinate first (see SetPoint). */
typedef struct Wf2dmapPoint {
    s16 y;                  /* 0x00 */
    s16 x;                  /* 0x02 */
} Wf2dmapPoint;

/* Bitmap (2D char) resource descriptor built by CreateBitmapDesc (0x1C bytes). */
typedef struct Wf2dmapBitmapDesc {
    void *src;              /* 0x00: tile data */
    u32 count;              /* 0x04: byte count */
    void *palette;          /* 0x08: palette data loaded from the archive */
    u32 paletteOut;         /* 0x0C: archive loader output */
    u32 type;               /* 0x10: resource byte 0 */
    u32 resourceId;         /* 0x14: resource byte 1 */
    u32 pad_18;             /* 0x18: never read in this file */
} Wf2dmapBitmapDesc;

/* Resource record copied from sWf2dmapPaletteDesc before LoadPalette fills it. */
typedef struct Wf2dmapResourceDesc {
    u32 words[4];           /* 0x00 */
    u8 bytes[12];           /* 0x10 */
    u32 tail;               /* 0x1C */
} Wf2dmapResourceDesc;

/* Pixel size header of a 2D char resource; the tile data follows at +12. */
typedef struct Wf2dmapCharSize {
    u16 widthPx;            /* 0x00 */
    u16 heightPx;           /* 0x02 */
} Wf2dmapCharSize;

/* Screen surface the scroll drawer works on. */
typedef struct Wf2dmapSurface {
    void *owner;            /* 0x00: CLACT owner */
    void *surface;          /* 0x04: passed to the tile drawer */
    u8 pad_8[4];            /* 0x08 */
    void *size;             /* 0x0C: Wf2dmapCharSize of the surface */
    int flag;               /* 0x10: 0 = sub screen, else main screen at y+192 */
    int layer;              /* 0x14: layer passed to the tile drawer */
    u16 tileX;              /* 0x18: last drawn tile column */
    u16 tileY;              /* 0x1A: last drawn tile row */
} Wf2dmapSurface;

extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32 archiveID, u32 memberIdx, u32 heapID, void *unpackedOut, u16 flags);
extern u32 GFL_HEAP_Free(void *p);
extern void CLACT_SetSurfacePos(void *,int,void *);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BG_SYS_InitBgLayer(u8,void *,int);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_MarkTileDirty(u32 bit);
extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);
extern void BG_SYS_SetTileEntry(u8,int,int,int,u8,u8,u8);
extern void BG_SYS_DrawTileEx(u8, u8, u8, u8, u8, void *, u8, u8, u32, u32);
void WF2DMAP_SCRDRAW_SetPoint(Wf2dmapPoint *p, s16 y, s16 x);
int WF2DMAP_SCRDRAW_GetPointY(const Wf2dmapPoint *p);
int WF2DMAP_SCRDRAW_GetPointX(const Wf2dmapPoint *p);
Wf2dmapBitmapDesc *WF2DMAP_SCRDRAW_CreateBitmapDesc(void *src, u32 count, const u8 *res, u32 heap);
void WF2DMAP_SCRDRAW_DeleteBitmapDesc(u8 *desc);
void WF2DMAP_SCRDRAW_UpdatePosition(char *surface,void *point);
void WF2DMAP_SCRDRAW_LoadPalette(void *unused, u32 id, u8 *res);
void WF2DMAP_SCRDRAW_SetScroll(char *surface,int x,int y);
void WF2DMAP_SCRDRAW_DrawTilesClipped(void *surface,int layer,unsigned int charRes,s16 x,s16 y);
void WF2DMAP_SCRDRAW_DrawTilesWrapped(void *surface, u8 layer, u8 x, u8 y, u8 w, u8 h, void *tiles, u8 sx, u8 sy, int width, int height);
int WF2DMAP_SCRDRAW_GetMode(unsigned int width, unsigned int height);
char *WF2DMAP_SCRDRAW_GetTileSource(char *tiles, u8 x, u8 y, unsigned mode, int w, int h, u16 *out);
extern const char sWf2dmapScrdrawFileName[];
extern const Wf2dmapResourceDesc sWf2dmapPaletteDesc;

void WF2DMAP_SCRDRAW_SetPoint(Wf2dmapPoint *p, s16 y, s16 x) { p->y=y; p->x=x; }

int WF2DMAP_SCRDRAW_GetPointY(const Wf2dmapPoint *p) { return p->y; }

int WF2DMAP_SCRDRAW_GetPointX(const Wf2dmapPoint *p) { return p->x; }

Wf2dmapBitmapDesc *WF2DMAP_SCRDRAW_CreateBitmapDesc(void *src, u32 count, const u8 *res, u32 heap)
{
    Wf2dmapBitmapDesc *desc = GFL_HEAP_Alloc((u16)heap, 28, 1, sWf2dmapScrdrawFileName, 104);
    desc->src = src;
    desc->count = count;
    desc->type = res[0];
    desc->resourceId = res[1];
    WF2DMAP_SCRDRAW_LoadPalette((void *)count, res[1], (u8 *)res);
    desc->palette = ARC_UTIL_LoadPaletteDataFromArchive(res[8], res[9], res[10], (&desc->paletteOut), heap);
    return desc;
}


void WF2DMAP_SCRDRAW_DeleteBitmapDesc(u8 *desc)
{
    GFL_HEAP_Free(((Wf2dmapBitmapDesc *)desc)->palette);
    GFL_HEAP_Free(desc);
}

/*
 *   typedef unsigned char u8; typedef unsigned int u32; typedef signed short s16;
 *   struct Item { int x; int y; u8 pad_08[0x40]; };
 *   struct Owner { u8 pad_00[0x98]; struct Item *items; };
 *   struct Pt { s16 x; s16 y; };
 *   void CLACT_SetSurfacePos(struct Owner *owner,u32 index,struct Pt *in) {
 *       int x=in->x; int y=in->y; struct Item *it=owner->items; struct Item *p;
 *       it[index].x=x<<12; p=&it[index]; p->y=y<<12;
 *   }
 */
void WF2DMAP_SCRDRAW_UpdatePosition(char *surface,void *point)
{
    int y,x;
    struct { s16 x,y; } pos;
    y=WF2DMAP_SCRDRAW_GetPointY(point);
    x=WF2DMAP_SCRDRAW_GetPointX(point);
    pos.x=x;
    pos.y=y;
    if(((Wf2dmapSurface *)surface)->flag==0) CLACT_SetSurfacePos(((Wf2dmapSurface *)surface)->owner,0,&pos);
    else { pos.y+=192; CLACT_SetSurfacePos(((Wf2dmapSurface *)surface)->owner,1,&pos); }
    WF2DMAP_SCRDRAW_SetScroll(surface,x,y);
}

void WF2DMAP_SCRDRAW_LoadPalette(void *unused, u32 id, u8 *res)
{
    Wf2dmapResourceDesc desc;
    desc=sWf2dmapPaletteDesc;
    desc.bytes[1]=res[2]; desc.bytes[2]=res[3]; desc.bytes[3]=res[4];
    desc.bytes[8]=res[5]; desc.bytes[9]=res[6]; desc.bytes[10]=0; desc.tail=res[7];
    BG_SYS_FreeLayerBuf((u8)id);
    BG_SYS_InitBgLayer(id,&desc,0);
    BG_SYS_SetPlaneVisible(id,1);
}

void WF2DMAP_SCRDRAW_SetScroll(char *surface,int x,int y)
{
    s16 tx,ty,rx,ry;
    tx=x/8; ty=y/8; rx=x%8; ry=y%8;
    if(tx!=((Wf2dmapSurface *)surface)->tileX||ty!=((Wf2dmapSurface *)surface)->tileY) {
        ((Wf2dmapSurface *)surface)->tileY=ty; ((Wf2dmapSurface *)surface)->tileX=tx;
        WF2DMAP_SCRDRAW_DrawTilesClipped(((Wf2dmapSurface *)surface)->surface,((Wf2dmapSurface *)surface)->layer,(unsigned int)(((Wf2dmapSurface *)surface)->size),-tx,-ty);
        BG_SYS_MarkTileDirty((u8)(((Wf2dmapSurface *)surface)->layer));
    }
    BG_SYS_ChangeScroll((u8)(((Wf2dmapSurface *)surface)->layer),(int)0,(int)rx);
    BG_SYS_ChangeScroll((u8)(((Wf2dmapSurface *)surface)->layer),(int)3,(int)ry);
}

/*
 * extent: Two bytes of zero alignment padding precede WF2DMAP_SCRDRAW_DrawTilesWrapped.
 * lever: Integer address q spills; a pointer q consumes the clipping register.
 */
void WF2DMAP_SCRDRAW_DrawTilesClipped(void *surface,int layer,unsigned int charRes,s16 x,s16 y)
{
    s16 width=((Wf2dmapCharSize *)charRes)->widthPx/8;
    s16 height=((Wf2dmapCharSize *)charRes)->heightPx/8;
    s16 sx,sy,w,h;
    if(x<0) sx=-x; else sx=0;
    if(y<0) sy=-y; else sy=0;
    if(x<=0) x=0;
    if(y<=0) y=0;
    w=33-x;
    h=25-y;
    if(width<sx+w) w-= (s16)(sx+w-width);
    if(height<sy+h) h-= (s16)(sy+h-height);
    BG_SYS_SetTileEntry(layer,0,0,0,33,25,17);
    charRes+=12;
    WF2DMAP_SCRDRAW_DrawTilesWrapped(surface,layer,x,y,w,h,(void *)charRes,sx,sy,(u8)width,(u8)height);
}

/*
 * note 2026-10-05 wD4 lane03: EXACT. Keys: width/height are int params (word prologue copy, raw in call 1);
 *   BG_SYS_DrawTileEx declared (u8 x5, void *, u8, u8, u32, u32) in this unit, so out[] (s16) is cast (u8) in call 2;
 *   mode is unsigned (int mode coalesced with the call temp and took the lowest slot); ox/oy are int;
 *   sy/y advance by (u8)n (the listing truncates n before both adds); u8 params for tx/ty in GetTileSource.
 */
void WF2DMAP_SCRDRAW_DrawTilesWrapped(void *surface, u8 layer, u8 x, u8 y, u8 w, u8 h, void *tiles, u8 sx, u8 sy, int width, int height)
{
    s16 out[2];
    int ox, oy;
    s8 hh, n;
    unsigned mode;
    s8 ccx, ww, cs, cx, m, tx, ty, cw, ccs;
    mode = WF2DMAP_SCRDRAW_GetMode(width, height);
    if (mode == 0) {
        BG_SYS_DrawTileEx(layer, x, y, w, h, tiles, sx, sy, width, height);
        return;
    }
    hh = h;
    if (hh <= 0) return;
    ww = w;
    cs = sx;
    cx = x;
    do {
        oy = sy % 32;
        if (oy + hh <= 32) {
            n = hh;
            hh = 0;
        } else {
            n = 32 - oy;
            hh = hh - n;
        }
        ty = sy / 32;
        cw = ww;
        ccs = cs;
        ccx = cx;
        while (cw > 0) {
            ox = ccs % 32;
            if (ox + cw <= 32) {
                m = cw;
                cw = 0;
            } else {
                m = 32 - ox;
                cw = cw - m;
            }
            tx = ccs / 32;
            BG_SYS_DrawTileEx(layer, ccx, y, m, n,
                WF2DMAP_SCRDRAW_GetTileSource(tiles, tx, ty, mode, width, height, (u16 *)out),
                ox, oy, (u8)out[0], (u8)out[1]);
            ccs = ccs + m;
            ccx = ccx + m;
        }
        sy = sy + (u8)n;
        y = y + (u8)n;
    } while (hh > 0);
}


int WF2DMAP_SCRDRAW_GetMode(unsigned int width, unsigned int height)
{
    int r;

    if (width <= 0x20) {
        r = 0;
        if (height > 0x20)
            r = 2;
    } else {
        r = 1;
        if (height > 0x20)
            r = 3;
    }
    return r;
}

char *WF2DMAP_SCRDRAW_GetTileSource(char *tiles, u8 x, u8 y, unsigned mode, int w, int h, u16 *out)
{
    u16 offset;
    switch(mode) {
    case 0: out[0]=w; out[1]=h; return tiles;
    case 1:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=h;
        return tiles+(s16)(h*64)*x;
    case 2:
        out[0]=w;
        out[1]=(y+1)*32<=h?32:h-y*32;
        return tiles+(s16)(w*64)*y;
    case 3:
        out[0]=(x+1)*32<=w?32:w-x*32;
        out[1]=(y+1)*32<=h?32:h-y*32;
        if(y==0) { offset=0; if(x!=0) offset+=2048; }
        else { offset=(u16)(w*64); if(x!=0) offset+=(u16)(h*64); }
        return tiles+offset;
    }
    return 0;
}
