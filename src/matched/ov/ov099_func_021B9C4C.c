/*
 * function: WIFICLUBACTOR_ProcessSpawnCommands
 * address:  0x021B9C4C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WF2DMAP_OBJ_DispatchById  0x021C48D4  thumb  ov127
 *   WF2DMAP_OBJCMD_Dispatch  0x021C5370  thumb  ov127
 *   WF2DMAP_CMDQ_Pop  0x021C5F80  thumb  ov127
 */
typedef struct {
    char pad[0x588];
    void *f588;             /* 0x588 */
    void *f58c;             /* 0x58c */
    char pad590[0xc];
    void *f59c;             /* 0x59c */
} Work;

extern int WF2DMAP_CMDQ_Pop(void *q, int *out);
typedef unsigned char  u8;
extern int WF2DMAP_OBJCMD_Dispatch(void *a, void *b, const u8 *desc, int *out);
extern void WF2DMAP_OBJ_DispatchById(void *a, u8 *q);

void WIFICLUBACTOR_ProcessSpawnCommands(Work *w)
{
    int a;
    int b[2];

    while (WF2DMAP_CMDQ_Pop(w->f59c, &a) == 1) {
        if (WF2DMAP_OBJCMD_Dispatch(w->f588, w->f58c, (const u8 *)(&a), b) == 1)
            WF2DMAP_OBJ_DispatchById(w->f58c, (u8 *)b);
    }
}
