/*
 * function: EVENT_FIELD_PROCLINK_SetReturnSlotDefault
 * address: 0x0216220C
 * packet: pkt_ov010_0216220C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned short u16;
typedef struct { unsigned x; u16 b; u16 t; } S;
extern void func_02082D44(void *, void *, unsigned);
void EVENT_FIELD_PROCLINK_SetReturnSlotDefault(u16 *p, S *s)
{
    if (s->x == *p) {
        func_02082D44(s, (char *)p + 0x20, 8);
        p[1] |= 8;
    }
}
