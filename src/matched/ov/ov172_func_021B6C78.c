/*
 * function: DRAW_SYSTEM_DrawStroke
 * address: 0x021B6C78
 * packet: pkt_ov172_021B6C78
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 the record pointer is const: that lets the scheduler hoist the r2/r3 loads
 *   above the outgoing stack stores (a plain pointer may alias the stack, which pins the order).
 * symbols:
 *   DRAW_SYSTEM_GetPlane 0x021B6EBC thumb ov172
 *   DRAW_SYSTEM_DrawLine 0x021B6CA4 thumb ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
    u16 c;
    u8 idx;
} Stroke;

extern void *DRAW_SYSTEM_GetPlane(void);
extern void DRAW_SYSTEM_DrawLine(u16 *o, char *t, int x0, int x1, u16 y0, u16 y1, int idx, u16 c);

void DRAW_SYSTEM_DrawStroke(u16 *o, const Stroke *e)
{
    DRAW_SYSTEM_DrawLine(o, DRAW_SYSTEM_GetPlane(), e->x0, e->x1, e->y0, e->y1, e->idx, e->c);
}
