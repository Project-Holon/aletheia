/*
 * function: func_021F0118
 * address:  0x021F0118
 * packet:   pkt_ov030_021F0118
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: 0x021F0124 strh to hardware register 0x04001050 (REG_DB_BLDCNT_SUB, SDK G2S_BlendNone)
 *
 * symbols:
 *   func_021F007C  0x021F007C  thumb  ov030
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct NoGearWork;

extern void func_021F007C(struct NoGearWork *work);
extern u32 func_020307B0(void *block);

#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

/* Frees the BG resources of the panel, clears the sub screen blend, frees the work. */
void func_021F0118(struct NoGearWork *work)
{
    func_021F007C(work);
    REG_DB_BLDCNT_SUB = 0;
    func_020307B0(work);
}
