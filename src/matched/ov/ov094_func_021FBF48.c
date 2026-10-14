/*
 * function: BTLV_EFFVM_CmdSetPokeCellFlag
 * address:  0x021FBF48
 * packet:   pkt_ov094_021FBF48
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_MCSS_SetSubstituteSprite  0x021FFFD8  thumb  ov094
 */
typedef struct {
    char pad[0x23c];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetMcss(void);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int i, int *out);
extern void BTLV_MCSS_SetSubstituteSprite(char *w, int key, int flag, int clear);

int BTLV_EFFVM_CmdSetPokeCellFlag(struct Cursor *a, State *s)
{
    int buf[8];
    int x = VM_GetU32(a);
    int n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    int y = VM_GetU32(a);
    int i;

    if (n != 0) {
        for (i = 0; i < n; i++)
            BTLV_MCSS_SetSubstituteSprite((char *)BTLV_EFFECT_GetMcss(), buf[i], x, y);
    }
    return s->f23c;
}
