/*
 * function: EVENT_FIELD_PROCLINK_HandlerCheckEntryGrid
 * address: 0x02162198
 * packet: pkt_ov010_02162198
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   EVENT_FIELD_PROCLINK_GetEventdataEntry 0x02161DC4 thumb ov010
 */
typedef unsigned short u16;
typedef struct { unsigned x; u16 b; u16 t; } S;
extern char *EVENT_FIELD_PROCLINK_GetEventdataEntry(char *, int, unsigned);
int EVENT_FIELD_PROCLINK_HandlerCheckEntryGrid(int unused, char *p, const S *s, S *out)
{
    out->x = s->x;
    out->b = s->b;
    if (EVENT_FIELD_PROCLINK_GetEventdataEntry(p, s->b, 1) != 0) out->t = 0;
    else out->t = 1;
    return 1;
}
