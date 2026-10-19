/*
 * function: COMM_TVT_SYS_SavePeerRecord
 * address: 0x021BE2F0
 * packet: pkt_ov172_021BE2F0
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 *   MET_TRAINERS_Insert  0x0200ED54  thumb  arm9
 */
typedef unsigned int u32;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MET_TRAINERS_GetFromSave(void *p);
struct L0200ED54;
struct Sub0200852CObj;
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void MET_TRAINERS_Insert(struct L0200ED54 *l, u32 val);
void COMM_TVT_SYS_SavePeerRecord(u32 *p, void *q)
{
    void *l = MET_TRAINERS_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)p[0x7e])));
    MET_TRAINERS_Insert(l, func_02008530(q));
}
