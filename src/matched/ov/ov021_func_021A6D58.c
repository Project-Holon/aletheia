/*
 * function: FIELDMAP_CTRL_NOGRID_WORK_CreateWork
 * address:  0x021A6D58
 * packet:   pkt_ov021_021A6D58
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CreateNogrid  0x021A3664  thumb  ov021
 *   FIELD_PLAYER_GetNogridState  0x021A36A4  thumb  ov021
 *   FIELD_NOGRID_MAPPER_BindCameraWork  0x021BB3AC  thumb  ov021
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   data_021DDF1C  0x021DDF1C  data  a1
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19810.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELDMAP_GetNogridMapper(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_CreateNogrid(u32 *p, u32 heap);
extern u32 FIELD_PLAYER_GetNogridState(u8 *p);
extern void FIELD_NOGRID_MAPPER_BindCameraWork(u8 *p, u32 b);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char data_021DDF1C[];

u32 *FIELDMAP_CTRL_NOGRID_WORK_CreateWork(void *a, u32 heap)
{
    u32 r7 = FIELDMAP_GetNogridMapper(a);
    u32 *p = GFL_HEAP_Alloc(heap, 8, 1, data_021DDF1C, 0x3e);
    void *r6 = FIELDMAP_GetFieldPlayer(a);

    ((struct Obj19810 *)p)->f0 = r6;
    FIELD_PLAYER_CreateNogrid(r6, heap);
    FIELD_NOGRID_MAPPER_BindCameraWork((u8 *)r7, FIELD_PLAYER_GetNogridState(r6));
    return p;
}
