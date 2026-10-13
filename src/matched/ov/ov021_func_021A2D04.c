/*
 * function: WEATHER_TASK_ApplyFogChange
 * address:  0x021A2D04
 * packet:   pkt_ov021_021A2D04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_FOG_FADE_InitEx  0x021A0224  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u32 pad0;
    u32 handle;
    u8 pad8[0x774];
    u8 active;
    u8 mode;
    u8 half;
    u8 pad77F;
    u32 value;
} Obj021A2D04;

typedef unsigned short u16;
void FIELD_FOG_FADE_InitEx(u8 *p, u32 a, u32 b, u32 c, u32 d, u16 e);

void WEATHER_TASK_ApplyFogChange(Obj021A2D04 *p)
{
    FIELD_FOG_FADE_InitEx((u8 *)p->handle, 0x7FDF, p->value, p->mode, p->mode, p->half);
}
