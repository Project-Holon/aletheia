/*
 * function: BTLV_EFFVM_CmdSetBillboardMode
 * address:  0x021FA09C
 * packet:   pkt_ov094_021FA09C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFVM_ResolveBattlerList  0x021FCA04  thumb  ov094
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 *   BTLV_EFFVM_RefreshMcssOrtho  0x021FDB20  thumb  ov094
 *   BTLV_MCSS_DisableBillboard  0x021FF228  thumb  ov094
 *   BTLV_MCSS_EnableBillboard  0x021FF1F4  thumb  ov094
 */
typedef struct {
    char pad[0x23C];
    int f23c;
    char pad2[4];
    int f244;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFVM_ResolveBattlerList(State *s, int id, int *out);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_EFFVM_RefreshMcssOrtho(State *s);
extern void BTLV_MCSS_DisableBillboard(void *w, int a);
extern void BTLV_MCSS_EnableBillboard(void *w, int a);

int BTLV_EFFVM_CmdSetBillboardMode(void *a, State *s)
{
    int buf[8];
    int x;
    int n;
    int i;

    x = VM_GetU32(a);
    if (VM_GetU32(a) == 0) {
        s->f244 = x;
        BTLV_EFFVM_RefreshMcssOrtho(s);
    } else {
        n = BTLV_EFFVM_ResolveBattlerList(s, 14, buf);
        if (n != 0) {
            for (i = 0; i < n; i++) {
                if (x == 1)
                    BTLV_MCSS_DisableBillboard((void *)BTLV_EFFECT_GetMcss(), buf[i]);
                else
                    BTLV_MCSS_EnableBillboard((void *)BTLV_EFFECT_GetMcss(), buf[i]);
            }
        }
    }
    return s->f23c;
}
