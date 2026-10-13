/*
 * function: EVENT_FIELD_PROCLINK_RunReturnSlots
 * address:  0x02162120
 * packet:   pkt_ov010_02162120
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_ClearReturnSlot  0x0216230C  thumb
 *   EVENT_FIELD_PROCLINK_GetReturnSlot  0x02162254  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnResultSlot  0x02162278  thumb
 *   d_02172990     0x02172990  data  ov010  a4
 */

typedef unsigned short u16;

typedef int (*Fn)(int, int, u16 *, u16 *);

extern void EVENT_FIELD_PROCLINK_ClearReturnSlot(char *p, unsigned i);
extern int EVENT_FIELD_PROCLINK_GetReturnSlot(char *p, u16 index, u16 *out);
extern void EVENT_FIELD_PROCLINK_SetReturnResultSlot(char *p, int index, u16 a, u16 b);
extern Fn d_02172990[];

void EVENT_FIELD_PROCLINK_RunReturnSlots(int a, int b, int c)
{
    u16 t[4];
    u16 s[4];
    int i;
    int r;

    for (i = 0; i < 3; i++) {
        if ((c & (1 << i)) == 0) {
            EVENT_FIELD_PROCLINK_ClearReturnSlot((char *)a, (u16)i);
        } else if (EVENT_FIELD_PROCLINK_GetReturnSlot((char *)a, i, s) != 0) {
            r = d_02172990[s[3]](a, b, s, t);
            EVENT_FIELD_PROCLINK_ClearReturnSlot((char *)a, (u16)i);
            if (r != 0)
                EVENT_FIELD_PROCLINK_SetReturnResultSlot((char *)a, (u16)i, t[2], t[3]);
        }
    }
}
