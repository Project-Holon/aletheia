/*
 * function: FLDEFF_BUBBLE_DrawBubble
 * address:  0x021D08D8
 * packet:   pkt_ov021_021D08D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE628     0x021DE628  data  ov021  a4
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   G3D_SYSTEM_DrawObjectCulling  0x02047AC8  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Row {
    u32 f0;
    int f4;
    u32 f8[3];
} Row;

typedef struct Blk021D08D8 {
    u32 w[3];
} Blk021D08D8;

typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
struct Arg;
extern int G3D_SYSTEM_DrawObjectCulling(void *a0, struct Arg *a1);
extern Blk021D08D8 d_021DE628;

void FLDEFF_BUBBLE_DrawBubble(Row *r, int a)
{
    int i;

    if (r->f0 != 0) {
        d_021DE628 = *(Blk021D08D8 *)r->f8;
        for (i = 0; i < 2; i++) {
            G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)a, (u16)i, &r->f4);
        }
        G3D_SYSTEM_DrawObjectCulling((void *)a, (struct Arg *)(&d_021DE628));
    }
}
