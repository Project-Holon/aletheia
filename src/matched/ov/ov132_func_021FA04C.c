/*
 * function: STA_ACT_AUDIENCE_Delete
 * address:  0x021FA04C
 * packet:   pkt_021FA04C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACT_AUDIENCE_Noop3  0x021FA278  thumb
 *   STA_ACT_AUDIENCE_Noop2  0x021FA0D4  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void STA_ACT_AUDIENCE_Noop3(void *);
extern void STA_ACT_AUDIENCE_Noop2(void *);
extern u32 func_020307B0(void *p);

void STA_ACT_AUDIENCE_Delete(u8 *p)
{
    STA_ACT_AUDIENCE_Noop3(p);
    STA_ACT_AUDIENCE_Noop2(p);
    func_020307B0(p);
}
