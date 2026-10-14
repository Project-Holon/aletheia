/*
 * function: MB_SEQ_StateLeave
 * address: 0x021C6E18
 * packet: pkt_ov136_021C6E18
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov136/mb_seq.c and filed here.
 *
 * symbols:
 *   MB_SEQ_StartFadeOut 0x021C7178 thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
int MB_SEQ_StateLeave(u8 *p);
int MB_SEQ_StartFadeOut(u8 *p, u32 v);

int MB_SEQ_StateLeave(u8 *p)
{
    *(u32 *)(p + 0x28) = 0x1b;
    return MB_SEQ_StartFadeOut(p, 1);
}
