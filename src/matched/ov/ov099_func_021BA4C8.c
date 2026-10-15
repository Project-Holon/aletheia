/*
 * unit:     yes
 * function: WIFICLUBACTOR_UpdateWait, WIFICLUBACTOR_UpdateDespawn
 * address:  0x021BA4C8
 * packet:   pkt_ov099_021BA4C8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lever: the second get-call result is a named local (b == a) so cmp keeps
 * the call result in the left slot.
 *
 * WIFICLUBACTOR_UpdateDespawn is the unlabelled 22-byte leaf after the lead function
 * (seed function_starts 0x021BA520).
 *
 * symbols:
 *   WF2DMAP_OBJDRAW_RestoreFrame  0x021C57F4  thumb  ov127
 *   WF2DMAP_OBJDRAW_SetActive  0x021C57D8  thumb  ov127
 *   WF2DMAP_OBJ_GetSlot  0x021C49A4  thumb  ov127
 *   WIFICLUBACTOR_SetPlayerState  0x021BA228  thumb  ov099
 *   WIFICLUBACTOR_ApplyActorMode  0x021BA5F0  thumb  ov099
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;

typedef struct {
    char pad00[0x570];
    void **f570;
} W;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    u8 fa;
    u8 fb;
} S;

extern void WF2DMAP_OBJDRAW_RestoreFrame(u8 *p);
extern void WF2DMAP_OBJDRAW_SetActive(u8 *p, int v);
extern int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);
extern void WIFICLUBACTOR_SetPlayerState(void *w, u8 *s);
extern void WIFICLUBACTOR_ApplyActorMode(void *a, char *b, u8 c);

int WIFICLUBACTOR_UpdateWait(W *w, S *s)
{
    int a;
    int b;

    s->f8 = s->f8 - 1;
    if (s->f8 <= 0) {
        WF2DMAP_OBJDRAW_RestoreFrame(s->f4);
        WF2DMAP_OBJDRAW_SetActive(s->f4, 1);
        a = WF2DMAP_OBJ_GetSlot(*w->f570, 4);
        b = WF2DMAP_OBJ_GetSlot(s->f0, 4);
        if (b == a) {
            WIFICLUBACTOR_SetPlayerState(w, (u8 *)s);
        } else {
            WIFICLUBACTOR_ApplyActorMode(w, (char *)s, s->fb);
        }
    }
    return 0;
}

int WIFICLUBACTOR_UpdateDespawn(W *w, S *s)
{
    s->f8 = s->f8 + 1;
    if (s->f8 > 0x2d) {
        return 1;
    }
    return 0;
}
