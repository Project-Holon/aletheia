/*
 * function: WIFICLUBACTOR_SpawnSlotActor
 * address:  0x021B9968
 * packet:   pkt_ov099_021B9968
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WF2DMAP_OBJ_GetPos  0x021C4AC4  thumb  ov127
 *   WIFICLUBACTOR_FindFreeActor  0x021BA168  thumb
 *   WIFICLUBACTOR_FindSlotTile  0x021BA04C  thumb
 *   WIFICLUBACTOR_SpawnEntity  0x021BA1C4  thumb
 *   WIFICLUBACTOR_SetWaitState  0x021BA248  thumb
 *   WIFICLUBACTOR_AttachSprite  0x021BA190  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    short x, y;
} Pos;

typedef struct {
    char pad[0x570];
    void **f570;
} Work;

extern Pos WF2DMAP_OBJ_GetPos(void *v);
typedef unsigned int   u32;
extern u8 *WIFICLUBACTOR_FindFreeActor(u8 *p);
extern void WIFICLUBACTOR_FindSlotTile(char *p, u16 *out, u32 c);
extern void WIFICLUBACTOR_SpawnEntity(u8 *p, void **out, short *xy, int a, u16 d, u8 c, int b);
extern void WIFICLUBACTOR_SetWaitState(void *o, void *e);
extern void WIFICLUBACTOR_AttachSprite(u8 *p, u8 *s, int n);

void *WIFICLUBACTOR_SpawnSlotActor(Work *o, int a, int b)
{
    void *e;
    Pos t;
    Pos d;

    e = WIFICLUBACTOR_FindFreeActor((u8 *)o);
    WIFICLUBACTOR_FindSlotTile((char *)o, (u16 *)(&t), b - 1);
    if (o->f570 != 0) {
        d = WF2DMAP_OBJ_GetPos(*o->f570);
        if (d.x == t.x && d.y == t.y)
            return 0;
    }
    WIFICLUBACTOR_SpawnEntity((u8 *)o, e, (short int *)(&t), b, a, 1, 4);
    WIFICLUBACTOR_SetWaitState(o, e);
    WIFICLUBACTOR_AttachSprite((u8 *)o, e, 0);
    return e;
}
