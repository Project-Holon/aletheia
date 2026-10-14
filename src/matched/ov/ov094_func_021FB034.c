/*
 * function: BTLV_EFFVM_CmdStartPokeBlink
 * address:  0x021FB034
 * packet:   pkt_ov094_021FB034
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_MCSS_StartBlinkTask  0x021FF870  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_StartBlinkTask(void *w, int a, int b, int c, int d);

int BTLV_EFFVM_CmdStartPokeBlink(void *a, State *s)
{
    int buf[8];
    int n;
    int x;
    int y;
    int z;
    int i;

    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    x = VM_GetU32(a);
    y = VM_GetU32(a);
    z = VM_GetU32(a);
    if (n != 0) {
        if (z == 0)
            z = 1;
        for (i = 0; i < n; i++)
            BTLV_MCSS_StartBlinkTask((void *)BTLV_EFFECT_GetMcss(), buf[i], x, y, z);
    }
    return s->f23c;
}
