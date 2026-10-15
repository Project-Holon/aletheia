/*
 * function: ZUKAN_GetResumeState
 * address: 0x021C8F98
 * packet: pkt_ov212_021C8F98
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov212/zukan.c and filed here.
 */

typedef unsigned int u32;

/* hidden function: 16 bytes between ZUKAN_SetResumeState and ZUKAN_StartProc211 */
struct Obj021C8F98 {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20;
};

u32 ZUKAN_GetResumeState(struct Obj021C8F98 *p);

u32 ZUKAN_GetResumeState(struct Obj021C8F98 *p)
{
    if (p->f8 != 1)
        return p->f20;
    return 0;
}
