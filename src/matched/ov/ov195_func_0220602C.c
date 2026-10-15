/*
 * function: SHINKA_DEMO_VIEW_Draw
 * address:  0x0220602C
 * packet:   pkt_0220602C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MCSS_Draw 0x02014D2C thumb
 *   SHINKA_DEMO_VIEW_Draw3d 0x02206664 thumb ov195
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    u16 heap;
    u8 pad02[0x4a];
    void *mcss;
    u8 pad50[0x5c - 0x50];
    u32 f5c;
} Owner;

struct McssSys;
extern void MCSS_Draw(struct McssSys *sys);
extern void SHINKA_DEMO_VIEW_Draw3d(Owner *o);

void SHINKA_DEMO_VIEW_Draw(Owner *o)
{
    if (o->f5c != 0)
        MCSS_Draw(o->mcss);
    else
        SHINKA_DEMO_VIEW_Draw3d(o);
}
