/*
 * function: SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId
 * address:  0x021B6E68
 * packet:   pkt_ov021_021B6E68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Search the 0x24-byte records for the one whose second halfword is 0x46
 * and return its first.  The return reads through a byte offset rather
 * than t[i].a: the subscript form lets the compiler CSE t + i*0x24 into
 * one register (product in r2, ldrh r0,[r3]); the byte-offset form keeps
 * only the product live and loads ldrh r0,[r4,r3] as the original does.
 *
 * symbols:
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char u8;

struct Ent { u16 a; u16 b; u8 pad[0x20]; };

typedef unsigned int   u32;
struct BigObj;
u32 GAME_DATA_GetEventData(const struct BigObj *p);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(u8 *p);
u16 EVENTDATA_SYSTEM_GetNpcCount(u8 *p);

int SCRCMD_POKEMON_FLD_FindDeliveryNpcObjId(int a)
{
    struct Ent *t;
    int n;
    int m;
    int i;

    m = GAME_DATA_GetEventData((const struct BigObj *)a);
    t = (struct Ent *)EVENTDATA_SYSTEM_GetNpcHeaders((u8 *)m);
    n = EVENTDATA_SYSTEM_GetNpcCount((u8 *)m);
    if (t == 0 || n == 0) {
        return -1;
    }
    for (i = 0; i < n; i++) {
        if (t[i].b == 0x46) {
            return *(u16 *)((u8 *)t + i * 0x24);
        }
    }
    return -1;
}
