/*
 * function: INTRUDE_CMD_RecvResultRecord
 * address:  0x0217410C
 * packet:   pkt_ov011_0217410C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * pass 2 2026-10-06 P2L50: EXACT (c99 and c). The s[0x907] = 1 before the
 * call is written in each arm of the b[0x37] if/else; the compiler tail-merges
 * it into the join. Written once after the if/else, the 0x907 offset is a
 * common subexpression with the store in the call-result block, and that
 * shared offset takes r0, so the flag spill and the byte store need two
 * movs #1 (224 B). Per-arm stores leave the later offset a fresh temp
 * (ldr r1, pool; movs r0, #1; str r0, [sp]; strb r0, [r4, r1]).
 * Idioms: a-constant-shifted-in-a-merged-tail-is-a-statement-repeated-in-each-arm,
 * a-field-offset-derived-from-a-live-base-after-an-if-is-the-stores-repeated-in-each-arm.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_PickEntryForKind  0x021763D8  thumb  ov011
 *   INTRUDE_COMM_RecordResultOutcome  0x02175E30  thumb  ov011
 *   INTRUDE_COMM_CountOutcomes  0x02176424  thumb  ov011
 *   INTRUDE_COMM_SetResultRecord  0x02175D7C  thumb  ov011
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Rec {
    u32 pad0;
    u32 lo : 4;
};

struct Entry;
struct Link;
extern u32 func_02026478(void *obj);
extern void *GAME_DATA_GetLastBattleRecSlot(void *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int INTRUDE_COMM_HasResult(u8 *);
extern void INTRUDE_COMM_PickEntryForKind(u8 *, u32);
extern void INTRUDE_COMM_RecordResultOutcome(void *, u8 *, struct Rec *);
extern int INTRUDE_COMM_CountOutcomes(u8 *, u8 *, u8 *);
extern void INTRUDE_COMM_SetResultRecord(void *, u8 *, void *);

void INTRUDE_CMD_RecvResultRecord(int a0, int a1, u8 *b, u8 *s)
{
    u8 *y;
    int flag;
    void *x;
    u8 buf[2];
    int r7;
    int r6;

    x = (void *)func_02026478(*(void **)(s + 4));
    y = GAME_DATA_GetLastBattleRecSlot(x);
    buf[1] = 0;
    flag = 0;
    buf[0] = 0;
    r7 = 0;
    r6 = 0;
    if (b[0x2c] == 4) {
        return;
    }
    if (INTRUDE_COMM_HasResult(s + 0x1ac) == 1) {
        return;
    }
    if (b[0x28] == GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
        if (b[0x37] == 1) {
            INTRUDE_COMM_PickEntryForKind(y, ((struct Rec *)b)->lo);
            s[0x907] = 1;
        } else {
            INTRUDE_COMM_RecordResultOutcome(x, s, (struct Rec *)b);
            s[0x907] = 1;
        }
        if (INTRUDE_COMM_CountOutcomes(y, &buf[1], &buf[0]) == 1) {
            flag = 1;
            s[0x907] = 1;
        }
        if (b[0x2e] == 1) {
            r6 = 1;
        } else {
            r7 = 1;
        }
        if (flag == 1) {
            r6 += buf[0];
            r7 += buf[1];
        }
        s[0x354] = r7;
        s[0x355] = r6;
        s[0x356] = 1;
        s[0x93e] = 1;
    }
    INTRUDE_COMM_SetResultRecord(s, s + 0x1ac, b);
}
