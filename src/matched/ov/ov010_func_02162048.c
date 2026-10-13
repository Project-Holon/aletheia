/*
 * function: EVENT_FIELD_PROCLINK_RequestReturn
 * address:  0x02162048
 * packet:   pkt_ov010_02162048
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_IsNetConnected  0x0216210C  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnPendingSlot  0x02162298  thumb
 *   EVENT_FIELD_PROCLINK_SetReturnSlotDefault  0x0216220C  thumb
 *   d_0217144C     0x0217144C  data  ov010  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 x;
    u16 b;
    u16 t;
} S;

extern int EVENT_FIELD_PROCLINK_IsNetConnected(int a0);
extern int EVENT_FIELD_PROCLINK_SetReturnPendingSlot(int a0, int a1, int a2);
extern void EVENT_FIELD_PROCLINK_SetReturnSlotDefault(u16 *, S *);
extern int d_0217144C[];

void EVENT_FIELD_PROCLINK_RequestReturn(u16 *a, int b, int c)
{
    S s;
    int t;

    if (EVENT_FIELD_PROCLINK_IsNetConnected((int)a) == 0) {
        EVENT_FIELD_PROCLINK_SetReturnPendingSlot((int)a, b, c);
        return;
    }
    t = d_0217144C[c];
    if (t != 4) {
        s.x = *a;
        s.b = b;
        s.t = t;
        EVENT_FIELD_PROCLINK_SetReturnSlotDefault(a, &s);
    }
}
