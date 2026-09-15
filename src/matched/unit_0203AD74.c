/*
 * unit:     yes
 * function: func_0203AD74
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

void func_0203AD74(struct NetState *s, void *p, u16 v)
{
    s->unk8 = p;
    s->unk46 = v;
}

void func_0203AD80(struct NetState *s, void *p, u16 v)
{
    func_0203AD74(s, p, v);
}
