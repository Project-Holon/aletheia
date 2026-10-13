/*
 * function: func_021D185C
 * address:  0x021D185C
 * packet:   pkt_ov093_021D185C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: PMSI_PARAM_IsEnabled (arm9 leaf, the integrator's; unlabelled Thumb) has no witness.
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int PMSI_PARAM_IsEnabled(u16 *p) { return *p != 0xffff; }
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   PMSI_PARAM_IsEnabled  0x02024450  thumb
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   STRBUF_Delete   0x02045808  arm
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

struct U16Vec;
extern u8 func_021B904C(u8 *p, int k);
extern void *func_021BA02C(char *p, int i, int mode);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
struct H;
struct L;
extern void *PMSI_PARAM_ToString(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u16 func_021BA004(char *p, int i);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA5F0(char *p, struct H *h);

void func_021D185C(BattleSeq *s, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(s->battle, b);
    p = func_021BA02C(s->battle, idx, a);
    if (p != 0 && PMSI_PARAM_IsEnabled(p) != 0) {
        r = PMSI_PARAM_ToString(p, (u16)((*(u16 *)((u8 *)s + 0x19a) & 0x7fff) | 0x8000));
        func_021EA5E4(s->msgWin, r);
        STRBUF_Delete(r);
        return;
    }
    v = func_021BA004(s->battle, idx);
    if (v != 0) {
        func_021EAF18((struct L *)s->msg, 7, (int)0);
        func_021EAF50((struct L *)s->msg, (int)v);
        func_021EAF50((struct L *)s->msg, (int)a);
        func_021EA5F0(s->msgWin, (struct H *)s->msg);
    }
}
