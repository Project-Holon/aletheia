/*
 * function: func_021D185C
 * address:  0x021D185C
 * packet:   pkt_ov093_021D185C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_02024450 (arm9 leaf, Ilias's; unlabelled Thumb) has no witness.
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int func_02024450(u16 *p) { return *p != 0xffff; }
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   func_02024450  0x02024450  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   sub_02045808   0x02045808  arm
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

extern int func_021B904C(void *battle, int idx);
extern void *func_021BA02C(void *battle, int a, int b);
extern int func_02024450(void *p);
extern void *func_0202435C(void *p, u16 v);
extern void func_021EA5E4(void *win, void *p);
extern void sub_02045808(void *p);
extern int func_021BA004(void *battle, int v);
extern void func_021EAF18(void *msg, int a, int id);
extern void func_021EAF50(void *msg, int v);
extern void func_021EA5F0(void *win, void *msg);

void func_021D185C(BattleSeq *s, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(s->battle, b);
    p = func_021BA02C(s->battle, idx, a);
    if (p != 0 && func_02024450(p) != 0) {
        r = func_0202435C(p, (*(u16 *)((u8 *)s + 0x19a) & 0x7fff) | 0x8000);
        func_021EA5E4(s->msgWin, r);
        sub_02045808(r);
        return;
    }
    v = func_021BA004(s->battle, idx);
    if (v != 0) {
        func_021EAF18(s->msg, 7, 0);
        func_021EAF50(s->msg, v);
        func_021EAF50(s->msg, a);
        func_021EA5F0(s->msgWin, s->msg);
    }
}
