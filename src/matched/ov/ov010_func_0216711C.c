/*
 * function: EVENT_RESEARCH_RADAR_InitReportWork
 * address: 0x0216711C
 * packet: pkt_ov010_0216711C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   FIELDMAP_GetHeapId 0x02188C84 thumb ov021
 *   FIELDMAP_GetMsgBg 0x02188C54 thumb ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb  arm9
 *   ICA_ANIME_GetField20  0x0201210C  thumb  arm9
 */
#include "../include/Obj05899.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *ICA_ANIME_GetField20(const struct Ctx *p);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern void MI_CpuFill8(void *, int, int);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
void EVENT_RESEARCH_RADAR_InitReportWork(u8 *p, void *sys) {
    void *field;
    field = ICA_ANIME_GetField20(sys);
    MI_CpuFill8(p, 0, 32);
    ((struct Obj05899 *)p)->f0 = FIELDMAP_GetHeapId(field);
    ((struct Obj05899 *)p)->f4 = sys;
    ((struct Obj05899 *)p)->f8 = ICA_ANIME_GetField1C(sys);
    ((struct Obj05899 *)p)->fC = field;
    ((struct Obj05899 *)p)->f10 = FIELDMAP_GetMsgBg(field);
}
