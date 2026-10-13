/*
 * function: FIELD_PLAYER_GRID_EVENT_DeleteHopTask
 * address:  0x021C10A0
 * packet:   pkt_021C10A0
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
 *   TCBL_GetTaskUserData  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(void *p);
extern u32 func_02030EAC(u32);
struct S02030EE8;
extern u32 TCBL_GetTaskUserData(struct S02030EE8 *p);

int FIELD_PLAYER_GRID_EVENT_DeleteHopTask(u32 a)
{
func_020307B0((void *)TCBL_GetTaskUserData((struct S02030EE8 *)a));
return func_02030EAC(a);
}

