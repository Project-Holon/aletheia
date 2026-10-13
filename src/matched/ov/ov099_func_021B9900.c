/*
 * function: WIFICLUBACTOR_SpawnCursorActor
 * address:  0x021B9900
 * packet:   pkt_ov099_021B9900
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIFICLUBACTOR_FindFreeActor  0x021BA168  thumb
 *   WIFICLUBACTOR_FindCursorStartTile  0x021BA0F8  thumb  ov099
 *   WIFICLUBACTOR_SpawnEntity  0x021BA1C4  thumb
 *   WIFICLUBACTOR_SetPlayerState  0x021BA228  thumb  ov099
 *   WIFICLUBACTOR_AttachSprite  0x021BA190  thumb
 *   func_021C5994  0x021C5994  thumb  ov127
 *   func_021C5A60  0x021C5A60  thumb  ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *WIFICLUBACTOR_FindFreeActor(u8 *p);
extern void WIFICLUBACTOR_FindCursorStartTile(void *p, u16 *xy);
extern void WIFICLUBACTOR_SpawnEntity(u8 *p, void **out, short *xy, int a, u16 d, u8 c, int b);
extern void WIFICLUBACTOR_SetPlayerState(void *w, u8 *s);
extern void WIFICLUBACTOR_AttachSprite(u8 *p, u8 *s, int n);
extern void func_021C5994(void *p, void *q);
extern void func_021C5A60(char *p, void *q);

u8 *WIFICLUBACTOR_SpawnCursorActor(u8 *p, int v)
{
    u8 *s;
    u16 xy[2];

    s = WIFICLUBACTOR_FindFreeActor(p);
    *(u8 **)(p + 0x570) = s;
    WIFICLUBACTOR_FindCursorStartTile(p, xy);
    WIFICLUBACTOR_SpawnEntity(p, (void **)s, (short int *)xy, 0, v, 0, 0);
    WIFICLUBACTOR_SetPlayerState(p, s);
    WIFICLUBACTOR_AttachSprite(p, s, 1);
    func_021C5994(p + 0x594, **(void ***)(p + 0x570));
    func_021C5A60(*(char **)(p + 0x598), p + 0x594);
    return s;
}
