/*
 * function: FIELD_TASK_CreatePlayerDrawOffsetTween
 * address:  0x021C7858
 * packet:   pkt_021C7858
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_TASK_CreateMmdlDrawOffsetTween  0x021C7878  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u32 FIELD_TASK_CreateMmdlDrawOffsetTween(u32, u32, u32, void *);

int FIELD_TASK_CreatePlayerDrawOffsetTween(u32 a, u32 b, u32 c)
{
return FIELD_TASK_CreateMmdlDrawOffsetTween(a, b, c, FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)a)));
}

