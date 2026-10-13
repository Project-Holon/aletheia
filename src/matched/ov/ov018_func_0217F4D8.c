/*
 * function: EVENT_COMM_COMMON_StartChoice
 * address: 0x0217F4D8
 * packet: pkt_ov018_0217F4D8
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   func_02034714 0x02034714 arm
 *   FIELD_MSGBG_CreateYesNoMenu 0x02190BE4 thumb ov021
 *   d_02183B2C 0x02183B2C data a4
 */
extern unsigned char d_02183B2C[];
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *);
extern void func_02034714(const char *expr, unsigned int line, const char *file);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
void EVENT_COMM_COMMON_StartChoice(void **p, int a)
{
    GAMESYSTEM_GetFieldMap((const struct Ctx *)a);
    if (p[11] != 0 || p[3] == 0) func_02034714((const char *)d_02183B2C, 0, (const char *)d_02183B2C);
    p[11] = FIELD_MSGBG_CreateYesNoMenu(p[9], 0);
}
