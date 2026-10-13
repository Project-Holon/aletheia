/*
 * function: OPTION_MENU_InitSettings
 * address:  0x021BAF5C
 * packet:   pkt_ov068_021BAF5C
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Byte-correct; blocked by two unwitnessed arm9 leaves (the integrator's):
 *   CONFIG_GetBattleScene (bitfield read, verified EXACT: typedef struct { unsigned short a:7; unsigned short b:1; } S;
 *                  unsigned CONFIG_GetBattleScene(S *p){ return p->b; })
 *   CONFIG_GetBattleStyle (same with a:6, b:1; disasm ldrh; lsls #0x19; lsrs #0x1f)
 *
 * 2026-10-05: body byte-correct. Leaves 020083AC and 020083C8 are now filed
 * EXACT in src/matched/arm9/. Needs shard seeding by the integrator.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   CONFIG_GetTextSpeed  0x02008374  thumb
 *   CONFIG_GetBattleScene  0x020083AC  thumb
 *   CONFIG_GetBattleStyle  0x020083C8  thumb
 *   CONFIG_GetSoundMode  0x02008390  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern unsigned int CONFIG_GetTextSpeed(int a0);
extern u32 CONFIG_GetBattleScene(u32 a);
extern u32 CONFIG_GetBattleStyle(u32 a);
extern unsigned int CONFIG_GetSoundMode(char *a0);
extern int CONFIG_GetButtonMode(unsigned short *p);

void OPTION_MENU_InitSettings(u8 *p, short unsigned int *a)
{
    MI_CpuFill8(p, 0, 12);
    p[5] = 11;
    *(u32 *)(p + 8) = (u32)a;
    p[0] = CONFIG_GetTextSpeed((int)a);
    p[1] = CONFIG_GetBattleScene((u32)a);
    p[2] = CONFIG_GetBattleStyle((u32)a);
    p[3] = CONFIG_GetSoundMode((char *)a);
    p[4] = CONFIG_GetButtonMode(a);
}
