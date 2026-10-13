/*
 * unit:     yes
 * function: GFL_NET_STATE_ChangeState
 * address:  0x0203AD74
 * packet:   pkt_0203A81C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Setter and its tail-call export in net_state.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AD74.c \
 *       --addr 0x0203AD74 --arm --cc 1.1p1
 */

typedef unsigned short u16;

struct NetState {
    void *unk0;
    void *unk4;
    void *unk8;
    unsigned char pad[0x46 - 0xC];
    u16 unk46;
};

void GFL_NET_STATE_ChangeState(struct NetState *s, void *p, u16 v)
{
    s->unk8 = p;
    s->unk46 = v;
}

void GFL_NET_STATE_ChangeStateDebug(struct NetState *s, void *p, u16 v, int line)
{
    GFL_NET_STATE_ChangeState(s, p, v);
}
