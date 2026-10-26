/*
 * file:     nsbtx_to_clwk.c
 * unit:     yes
 * function: NAMEIN_GRAPHIC_BlitTexture, NAMEIN_GRAPHIC_CopyRows, NAMEIN_GRAPHIC_LoadIconMember
 * address:  0x021F513C
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from namein_graphic_p03.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   DC_FlushRange 0x020862F0 arm
 *   CLACT_GetActorPaletteProxy 0x0204B764 arm
 *   NNSi_G2dGetVramHandleEx 0x02063800 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   d_021F57A8 0x021F57A8 data ov194 a1
 */
#include "../types.h"

struct ArcFile;

struct Struct20;

typedef struct {int w[5];} Palette;

/* A texture reached from NNS_G3dGetTex. */
typedef struct NameinGraphicTex {
    unsigned char pad_0[0x14];
    unsigned int pixelOffset;        /* 0x14 */
    unsigned char pad_18[0x20];
    unsigned int paletteOffset;      /* 0x38 */
    unsigned char pad_3C[1];
    unsigned char count;             /* 0x3D */
    unsigned char pad_3E[4];
    unsigned short entryOffset;      /* 0x42 */
} NameinGraphicTex;

#include "../arm9/gfl_heap_wrap.h"




#include "../arm9/mi_memory.h"
struct ArcHandle;


#include "../arm9/nns_g3d_res.h"
struct ClactActor;

#include "../arm9/clact.h"


#include "../arm9/os_cache.h"
struct PaletteProxy;


#include "../arm9/nns_g2d_oam_manager.h"

#include "../arm9/gx_load2d.h"


/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define ARC_TOOL_LoadHandleMember ARC_TOOL_LoadHandleMember_header
#endif
#include "../arm9/arc_tool.h"
#ifdef __MWERKS__
#undef ARC_TOOL_LoadHandleMember
extern void * ARC_TOOL_LoadHandleMember(struct ArcHandle *, u32, unsigned short);
#endif
#include "../arm9/arc_tool.h"
void NAMEIN_GRAPHIC_BlitTexture(const char *src, int width, int x, int y, int w, int h, char *dst);

void NAMEIN_GRAPHIC_CopyRows(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step);

void NAMEIN_GRAPHIC_LoadIconMember(struct ClactActor *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap);

extern const char d_021F57A8[];

void NAMEIN_GRAPHIC_BlitTexture(const char *src, int width, int x, int y, int w, int h, char *dst)
{
    unsigned inOffset;
    unsigned outOffset;
    int i, j;
    unsigned step;
    uptr target;
    step = width * 4;
    target = (uptr)dst;
    outOffset = 0;
    for (j = y; j < y + h; j++) {
        for (i = x; i < x + w; i++) {
            inOffset = i * 4 + j * step * 8;
            NAMEIN_GRAPHIC_CopyRows(src, (char *)target, &inOffset, &outOffset, 4, step);
        }
    }
}

/*
 * Padding: two zero bytes at 0x021F51E2, then a function prologue.
 */
void NAMEIN_GRAPHIC_CopyRows(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step)
{
    int i;
    for (i = 0; i < 8; i++) {
        MI_CpuCopy8(src + *a, dst + *b, n);
        *a += step;
        *b += n;
    }
}

static inline u8 *entry(u8 *p,u32 i) {
    if(p) {
        u8 *q=p+0x3c;
        if(q && i<((NameinGraphicTex *)p)->count) {
                u16 off=((NameinGraphicTex *)p)->entryOffset;
                u16 stride=*(u16 *)(q+off);
                return q+off+4+stride*i;
        } else return 0;
    }
    return 0;
}

void NAMEIN_GRAPHIC_LoadIconMember(struct ClactActor *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap)
{
    Palette pal;
    u32 size=width*height*32;
    /* likely original mismatch: the original passes a u16 heap id; the arm9 prototype takes unsigned int */
    void *archive=ARC_TOOL_CreateHandle(arc,heap);
    u8 *raw=ARC_TOOL_LoadHandleMember(archive,member,heap);
    u8 *tex=(u8 *)NNS_G3dGetTex((NNSG3dResFileHeader *)raw);
    u8 *pixels;
    u32 offset;
    offset=(*(u32 *)entry(tex,index)&0xffff)*8;
    pixels=tex+((NameinGraphicTex *)tex)->pixelOffset;
    void *buf=GFL_HEAP_Alloc((u16)((heap&0x7fff)|0x8000),size,0,d_021F57A8,95);
    NAMEIN_GRAPHIC_BlitTexture((const char *)(pixels+offset),width,0,0,width,height,buf);
    CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((struct ClactActor *)dst),buf,size,pos,mode);
    GFL_HEAP_Free(buf);
    u32 poff=((NameinGraphicTex *)tex)->paletteOffset;
    DC_FlushRange(tex+poff,32);
    CLACT_GetActorPaletteProxy((char *)dst,(struct PaletteProxy *)(&pal));
    if(mode==0 || mode==2) GX_LoadOBJPltt(tex+poff,NNSi_G2dGetVramHandleEx((char *)&pal,1),32);
    if(mode==1 || mode==2) GXS_LoadOBJPltt(tex+poff,NNSi_G2dGetVramHandleEx((char *)&pal,2),32);
    GFL_HEAP_Free(raw);
    ARC_TOOL_DeleteHandle(archive);
}
