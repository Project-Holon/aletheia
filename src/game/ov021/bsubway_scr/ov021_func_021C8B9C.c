/*
 * function: func_021C8B9C
 * address:  0x021C8B9C
 * packet:   pkt_ov021_021C8B9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: the base/offset register swap of the earlier DIFF closed by
 * declaring the table const (the const element type recolours the hoisted
 * table base into r3).
 *
 * symbols:
 *   d_021DAB54  0x021DAB54  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 a;
    u16 b;
} E;

extern const E d_021DAB54[4];

const E *func_021C8B9C(u16 id)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (d_021DAB54[i].id == id)
            return &d_021DAB54[i];
    }
    return 0;
}
