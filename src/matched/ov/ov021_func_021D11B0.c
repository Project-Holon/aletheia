/*
 * function: FIELD_SAVEANIME_Start
 * address:  0x021D11B0
 * packet:   pkt_ov021_021D11B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056A0  0x020056A0  thumb
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   FIELD_SAVEANIME_ShowWindow  0x021D1400  thumb  ov021
 *   FIELD_SAVEANIME_AnimTask  0x021D1488  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BG_SYS_FreeSlot(int a);
extern int FIELD_SAVEANIME_ShowWindow(void *a);
extern void *func_020056A0(void *, void *, int);
struct Anim021D1488;
extern void FIELD_SAVEANIME_AnimTask(void *task, struct Anim021D1488 *p);

void FIELD_SAVEANIME_Start(u32 *p)
{
    BG_SYS_FreeSlot(3);
    p[5] = 0;
    FIELD_SAVEANIME_ShowWindow(p);
    p[3] = (u32)func_020056A0(FIELD_SAVEANIME_AnimTask, p, 0x80);
}
