/*
 * function: FLDEFF_HIDE_Exit
 * address:  0x021D0504
 * packet:   pkt_ov021_021D0504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckCheckInfo  0x0216E1C4  thumb  ov010
 *   FLDMMDL_MOVE_SetHideEffect  0x0219BF3C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Blk021D04D8 {
    u32 w[4];
} Blk021D04D8;

typedef struct St021D04D8 {
    u8 *f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10[2];
    u16 f18;
} St021D04D8;

extern int FLDMMDL_CheckCheckInfo(int a0, int a1);
extern void FLDMMDL_MOVE_SetHideEffect(int a, u32 v);

void FLDEFF_HIDE_Exit(void *a, St021D04D8 *s)
{
    if (FLDMMDL_CheckCheckInfo(s->f8, (int)s->f10) == 1) {
        FLDMMDL_MOVE_SetHideEffect(s->f8, 0);
    }
}
