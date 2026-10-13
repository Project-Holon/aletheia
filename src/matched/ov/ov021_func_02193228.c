/*
 * function: FIELD_MSGBG_KeyWaitCheckSkip
 * address:  0x02193228
 * packet:   pkt_ov021_02193228
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);

int FIELD_MSGBG_KeyWaitCheckSkip(u8 *p)
{
    u32 held = func_020362DC();
    u32 trg = func_0203630C();

    if (p[0] != 0)
        return 0;
    if (held & 3)
        p[2] = 1;
    if (p[2] != 0 && (trg & 3))
        return 1;
    return 0;
}
