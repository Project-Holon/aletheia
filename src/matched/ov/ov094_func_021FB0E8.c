/*
 * function: BTLV_EFFVM_CmdSetPokePaletteFade
 * address:  0x021FB0E8
 * packet:   pkt_ov094_021FB0E8
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
 *   BTLV_MCSS_SetPaletteFade  0x021FFDB4  thumb  ov094
 */
typedef unsigned char u8;

typedef struct {
    char pad[0x23C];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_SetPaletteFade(void *w, int a, u8 b, u8 c, u8 d, int e);

int BTLV_EFFVM_CmdSetPokePaletteFade(void *a, State *s)
{
    int buf[8];
    int n;
    int p;
    int q;
    int r;
    int t;
    int i;

    n = BTLV_EFFVM_ResolveBattlerList(s, VM_GetU32(a), buf);
    p = VM_GetU32(a);
    q = VM_GetU32(a);
    r = VM_GetU32(a);
    t = VM_GetU32(a);
    if (n != 0) {
        for (i = 0; i < n; i++)
            BTLV_MCSS_SetPaletteFade((void *)BTLV_EFFECT_GetMcss(), buf[i], p, q, r, t);
    }
    return s->f23c;
}
