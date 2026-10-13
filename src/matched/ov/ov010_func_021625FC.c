/*
 * function: EVENTDATA_SYSTEM_SetConnectExitLocation
 * address: 0x021625FC
 * packet: pkt_ov010_021625FC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 150-byte function followed by two alignment bytes at 02162692.
 * lever: read-only const source parameter schedules the final signed-id
 * truncation after the argument loads; exact callee widths keep B on r1.
 * interface: callee argument id is s16 as caller's explicit asrs shows;
 * k stays full-width because the original forwards it without truncation.
 * symbols:
 *   EVENTDATA_SYSTEM_GetConnectData 0x021625CC thumb ov010
 *   ZONEDATA_InitLocation 0x020140F8 thumb
 *   ZONEDATA_SetExitLocation 0x02014110 thumb
 *   ZONEDATA_SetExitRailLocation 0x02014134 thumb
 *   EVENTDATA_SYSTEM_GetConnectExitGridPos 0x02162C84 thumb ov010
 *   EVENTDATA_SYSTEM_GetConnectExitRailLocation 0x02162D90 thumb ov010
 */
#include "../include/Obj07293.h"
#include "../include/Obj07294.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { u16 a, b; s16 c; u16 d; } B;
typedef struct { int x, y, z; } A;
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern void ZONEDATA_InitLocation(int p0);
extern void ZONEDATA_SetExitLocation(int *, u16, s16, u16, int, unsigned, unsigned, unsigned);
extern void ZONEDATA_SetExitRailLocation(int *, u16, s16, u16, int, u16, u16, s16);
struct Box;
struct Out;
extern void EVENTDATA_SYSTEM_GetConnectExitGridPos(struct Box *b, int q, int *out);
extern void EVENTDATA_SYSTEM_GetConnectExitRailLocation(const struct Box *b, int q, struct Out *o);
int EVENTDATA_SYSTEM_SetConnectExitLocation(const u8 *q, int *out, int id, int k)
{
    u8 *r;
    A s;
    B t;
    r = EVENTDATA_SYSTEM_GetConnectData((char *)q, id);
    if (r == 0) return 0;
    ZONEDATA_InitLocation((int)out);
    if (((struct Obj07294 *)r)->f2 == 0x100) *out = 3;
    else *out = 2;
    if (((struct Obj07294 *)r)->f6 == 0) {
        EVENTDATA_SYSTEM_GetConnectExitGridPos((struct Box *)r, k, (int *)(&s));
        ZONEDATA_SetExitLocation(out, ((struct Obj07293 *)q)->f10, id, r[4], k, s.x, s.y, s.z);
    } else {
        EVENTDATA_SYSTEM_GetConnectExitRailLocation((const struct Box *)r, k, (struct Out *)(&t));
        ZONEDATA_SetExitRailLocation(out, ((struct Obj07293 *)q)->f10, id, r[4], k, t.a, t.d, t.c);
    }
    return 1;
}
