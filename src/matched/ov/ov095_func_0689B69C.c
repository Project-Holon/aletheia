/*
 * function: func_0689B69C
 * address: 0x0689B69C
 * packet: pkt_ov095_0689B69C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: five unlabelled 16-byte bx-pc/ARM veneers 0689B730..0689B770 lack outside witnesses; full ROM pool targets 022033CC,0220270C,021F81EC,021F8A78,022033CC respectively. No ARM9 blocker.
 * trailing: five fixed veneers plus 16-byte tail stub 0689B780..0689B790; non-C veneers interrupt the lead/stub C unit. Parent cleared B780 conditionally; no follower filed.
 * checks: 1 call arguments and veneer target words audited, 760 argless; 2 B670 union/bitfields and B790 tail twin read; 3 bitfield += (u8)1 gives byte-correct 148B; 4 bitfield/compound-update idioms fit; 5 live ov095 neighbors reread; caller-only TU/split diagnoses wildcard sites.
 * symbols:
 *   func_0689B730 0x0689B730 thumb ov095
 *   func_0689B740 0x0689B740 thumb ov095
 *   func_0689B750 0x0689B750 thumb ov095
 *   func_0689B760 0x0689B760 thumb ov095
 *   func_0689B770 0x0689B770 thumb ov095
 */
typedef unsigned char u8;
typedef struct {
    u8 pad[0x92];
    struct { u8 state:7, active:1; } f;
    u8 pad2[0x1d];
    void *ctx;
} S;
extern int func_0689B730(void *);
extern void func_0689B740(void *, int, int);
extern void func_0689B750(int);
extern void func_0689B760(void);
extern int func_0689B770(void *);
int func_0689B69C(S *s)
{
    switch (s->f.state) {
    case 0:
        if (func_0689B730(s->ctx) == 0)
            s->f.state += (u8)1;
        break;
    case 1:
        func_0689B740(s->ctx, 0, 0);
        func_0689B750(8);
        func_0689B760();
        s->f.state += (u8)1;
        break;
    case 2:
        if (func_0689B770(s->ctx) == 0)
            s->f.state += (u8)1;
        break;
    case 3:
        s->f.active = 0;
        return 1;
    }
    return 0;
}
