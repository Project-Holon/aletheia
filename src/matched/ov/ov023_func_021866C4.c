/*
 * function: OEKAKI_RegisterMetPlayers
 * address:  0x021866C4
 * packet:   pkt_ov023_021866C4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MET_TRAINERS_GetFromSave  0x0200ED48  thumb
 *   UNION_APP_GetMemberEntry  0x02184180  thumb  ov022
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   func_02008530  0x02008530  thumb
 *   MET_TRAINERS_Insert  0x0200ED54  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Big;
struct L0200ED54;
struct Sub0200852CObj;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *p);
extern char *UNION_APP_GetMemberEntry(unsigned char *p, int i);
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);

void OEKAKI_RegisterMetPlayers(u32 *p)
{
    int i;
    u32 h;
    u32 r;

    h = (u32)MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)(p[1] + 4))));
    for (i = 0; i < 5; i++) {
        r = (u32)UNION_APP_GetMemberEntry((unsigned char *)(*(u32 *)p[1]), (u8)i);
        if (r != 0) {
            if (i != GFL_NET_SYSTEM_GetCurrentAid()) {
                MET_TRAINERS_Insert((struct L0200ED54 *)h, func_02008530((const struct Sub0200852CObj *)r));
            }
        }
    }
}
