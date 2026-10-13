/*
 * function: func_021A7B10
 * address:  0x021A7B10
 * packet:   pkt_021A7B10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_FreeAcmd(char *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);

int func_021A7B10(void *a)
{
return (int)FLDMMDL_FreeAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((struct Obj00020 *)a)));
}

