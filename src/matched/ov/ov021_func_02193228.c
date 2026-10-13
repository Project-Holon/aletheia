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
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   KEY_GetCont  0x0203630C  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);

int FIELD_MSGBG_KeyWaitCheckSkip(u8 *p)
{
    u32 held = KEY_GetTrg();
    u32 trg = KEY_GetCont();

    if (p[0] != 0)
        return 0;
    if (held & 3)
        p[2] = 1;
    if (p[2] != 0 && (trg & 3))
        return 1;
    return 0;
}
