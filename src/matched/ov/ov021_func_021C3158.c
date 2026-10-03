/*
 * function: func_021C3158
 * address:  0x021C3158
 * packet:   pkt_ov021_021C3158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Plays the next sound effect of the current cue table when its frame is
 * reached.
 *
 * symbols:
 *   d_021DA720     0x021DA720  data  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int se;
    u32 frame;
} Ent;

extern Ent *d_021DA720[];
extern void func_020061E4(u32 a);

void func_021C3158(u8 *p)
{
    Ent *t = d_021DA720[*(u16 *)(p + 0x66)];

    if (t[*(u16 *)(p + 0x136)].se != -1 && *(u16 *)(p + 0x134) == t[*(u16 *)(p + 0x136)].frame) {
        func_020061E4(t[*(u16 *)(p + 0x136)].se);
        (*(u16 *)(p + 0x136))++;
    }
}
