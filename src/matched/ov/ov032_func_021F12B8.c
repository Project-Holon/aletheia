/*
 * function: func_021F12B8
 * address:  0x021F12B8
 * packet:   pkt_ov032_021F12B8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the only wildcard is the bl to BEACON_STATUS_SetViewTop (blocker: no
 * witness outside the range for an unlabelled arm9 leaf, the integrator's). Verified
 * leaf C (EXACT, arm9 0x020275B8, thumb, 12 bytes incl. pool word 0x0B0E):
 *   typedef unsigned char u8;
 *   void BEACON_STATUS_SetViewTop(char *p, u8 v) { p[0xb0e] = v; }
 * The this+0x7c/0x7d reads are volatile: the original re-reads them.
 *
 * note (2026-10-04): wave D2 filed the arm9 leaf witnesses (src/matched/arm9/BEACON_STATUS_GetLog,
 *   AC, B8, D0 EXACT); the tool still reports them unresolved, so the label seeding for
 *   0x020275A8/AC/B8/D0 (asm/layout, not this lane) is the only blocker.
 *
 * symbols:
 *   func_021F12B8 0x021F12B8 thumb
 *   func_021F0DD8 0x021F0DD8 thumb
 *   BEACON_STATUS_SetViewTop 0x020275B8 thumb
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex 0x021659F0 thumb ov010
 *   func_021F13A0 0x021F13A0 thumb
 */

typedef unsigned char u8;

typedef unsigned short u16;
struct Queue;
struct Rec;
extern void func_021F0DD8(unsigned int a);
extern void BEACON_STATUS_SetViewTop(char *p, int v);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *q, struct Rec *out, u16 *tag, int delta);
extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern void func_021F13A0(char *this, int a, int b, int c, int s);

void func_021F12B8(u8 *this, int dir)
{
    u8 t;
    int n;
    u8 idx;

    func_021F0DD8(0x54b);
    if (dir == 0) {
        t = *(volatile u8 *)(this + 0x7c) + *(volatile u8 *)(this + 0x7d);
        n = *(volatile u8 *)(this + 0x7c) + 1;
    } else {
        t = *(volatile u8 *)(this + 0x7c) - 1;
        n = *(volatile u8 *)(this + 0x7c) - 1;
    }
    *(volatile u8 *)(this + 0x7c) = n;
    BEACON_STATUS_SetViewTop(*(void **)(this + 0x34), *(volatile u8 *)(this + 0x7c));
    GAME_BEACON_ACCESSOR_TableRingGet(*(void **)(this + 0x3c), *(void **)(this + 0x40), (u16 *)(this + 0x48), t);
    idx = GAME_BEACON_ACCESSOR_TableGetRingIndex(*(void **)(this + 0x3c), t);
    func_021F13A0((char *)this, (int)(*(void **)(this + 0x40)), idx, (u8)dir, 2);
}
