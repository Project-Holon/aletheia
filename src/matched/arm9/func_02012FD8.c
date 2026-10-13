/*
 * function: GAME_DATA_GetSaveBlock43
 * address:  0x02012FD8
 * packet:   pkt_02012FD8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020071CC  0x020071CC  thumb
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *GAME_DATA_GetSaveBlock43(void **p)
{
    return func_020071CC(*p, 0x43);
}
