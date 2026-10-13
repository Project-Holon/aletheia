/*
 * unit:     yes
 * function: sub_0202DE5C
 * address:  0x0202DE5C
 * packet:   pkt_0202DD24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three unlabelled PmsDraw setters between PMS_DRAW_Copy and
 * unit_0202DE6C: +0x31 (u8, reached through `adds #0x31` past the ldrb
 * reach), +0x24 (u16) and +0x2c (u32).  None saves lr, so the integrator
 * should seed 0x0202DE5C, 0x0202DE64 and 0x0202DE68.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PmsDraw {
    u16   heap;
    u8    pad02[2];
    u32   unk04;
    void *unk08;
    void *elems;
    u8    sub10[0x14];
    u16   unk24;
    u8    pad26[2];
    u32   selected;
    u32   unk2c;
    u8    count;
    u8    unk31;
};

void sub_0202DE5C(struct PmsDraw *p, u8 v)
{
    p->unk31 = v;
}

void sub_0202DE64(struct PmsDraw *p, u16 v)
{
    p->unk24 = v;
}

void sub_0202DE68(struct PmsDraw *p, u32 v)
{
    p->unk2c = v;
}
