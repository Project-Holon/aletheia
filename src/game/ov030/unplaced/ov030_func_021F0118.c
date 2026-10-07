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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021F007C(char *p);
extern u32 func_020307B0(void *p);

#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_021F0118(char *p)
{
    func_021F007C(p);
    REG_DB_BLDCNT_SUB = 0;
    func_020307B0(p);
}
