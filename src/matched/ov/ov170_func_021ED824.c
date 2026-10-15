/*
 * function: BOX2_UI_CreatePartyActors
 * address: 0x021ED824
 * packet: pkt_ov170_021ED824
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFD1C 0x021EFD1C data a4
 *   BOX2_SEQ_CreateActorFromDesc 0x021EBEE0 thumb ov170
 */
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;
extern const Desc d_021EFD1C;
extern void *BOX2_SEQ_CreateActorFromDesc(char *, const Desc *);
void BOX2_UI_CreatePartyActors(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    unsigned i;
    for (i = 0; i < 6; i++) {
        t = base;
        t.y += (short)(i * 0x22);
        t.c = i + 0x39;
        *(void **)(p + i * 4 + 0x9f28) = BOX2_SEQ_CreateActorFromDesc(p, &t);
    }
}
