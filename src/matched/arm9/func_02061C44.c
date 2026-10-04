/*
 * function: func_02061C44
 * address:  0x02061C44
 * packet:   pkt_02061C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146B80  0x02146B80  data
 *   func_02061BB0  0x02061BB0  arm
 *   func_02061BD0  0x02061BD0  arm
 *   func_02061B2C  0x02061B2C  arm
 *
 * Drain loop over the 0x02146B80 work record: fetch the head node, pump the
 * record's one-step state machine, and for as long as it reports progress
 * dispose of the node and subtract its size field from the record's running
 * byte total at +0x10, then fetch the next head.
 *
 * Blocked at MATCH on the `matched` class: func_02061B2C (PC24 at +0x0028)
 * and func_02061BD0 (PC24 at +0x0018 and +0x004c) each have their only
 * branch inside 0x02061C44..0x02061CA0, so both sites stay wildcarded.  Both
 * callees are documented dead ends in docs/notes/pkt_02061B2C.c.txt and
 * docs/notes/pkt_02061BD0.c.txt (16 and 6 concrete bytes of instruction
 * selection residue respectively), so neither can ever be filed EXACT and
 * neither can attest this file.  Every concrete byte here reproduces.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct Node {
    char pad_00[0xc];
    u32  f0c;   /* 0x0c, byte size consumed */
} Node;

typedef struct Rec {
    char pad_00[0x10];
    u32  f10;   /* 0x10, running byte total */
} Rec;

extern Rec g_02146B80;
extern u32 func_02061BB0(u8 *p);
extern u32   func_02061BD0(Rec *rec);
extern void  func_02061B2C(Node *n);

void func_02061C44(void)
{
    Node *n = (Node *)func_02061BB0((u8 *)(&g_02146B80));

    while (func_02061BD0(&g_02146B80) != 0) {
        func_02061B2C(n);
        g_02146B80.f10 -= n->f0c;
        n = (Node *)func_02061BB0((u8 *)(&g_02146B80));
    }
}
