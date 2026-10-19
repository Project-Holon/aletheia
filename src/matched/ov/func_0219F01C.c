/*
 * function: FLDMMDL_CreateTalkScriptEvent
 * address:  0x0219F01C
 * packet:   pkt_0219F01C
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
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int FLDMMDL_CreateTalkScriptEvent(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id)
{
return (int)SCRIPT_SYS_CreateScriptEventSimple(a, ((c << 16) >> 16), e1, *(u16 *)((u8 *)((u8 *)&e1) + 4));
}

