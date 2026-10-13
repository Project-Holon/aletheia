/*
 * function: EFFECT_ENCOUNT_StartItemEvent
 * address:  0x021AB0AC
 * packet:   pkt_ov021_021AB0AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x5bc];
    u16 h5bc;
} D;

typedef struct {
    u32 f0;
    void *f4;
    int pad[2];
    D *f10;
} S;

typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern int SCRIPT_SYS_CreateScriptEventSimple(void *a0, u32 a1, int a2, u16 a3);

void EFFECT_ENCOUNT_StartItemEvent(S *s, u16 v)
{
    s->f10->h5bc = v;
    SCRIPT_SYS_CreateScriptEventSimple(s->f4, 0x2795, 0, FIELDMAP_GetHeapId((u8 *)s->f0));
}
