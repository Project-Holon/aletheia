/*
 * function: SCRIPT_WORK_GetWorkPtr
 * address: 0x02158FE0
 * packet: pkt_ov010_02158FE0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   func_020143CC 0x020143CC thumb
 *   SCRIPT_WORK_GetLocalWork 0x02158FD0 thumb ov010
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned int func_020143CC(unsigned int, unsigned int);
extern u16 *SCRIPT_WORK_GetLocalWork(void *, unsigned int);
u16 *SCRIPT_WORK_GetWorkPtr(void *a, void *b, unsigned int id)
{
    void *p = (void *)GAME_DATA_GetEventWork(b);
    if (id < 0x4000) return 0;
    if (id < 0x8000) return (u16 *)func_020143CC((unsigned int)p, id);
    if (id < 0xc000) return SCRIPT_WORK_GetLocalWork(a, id);
    return 0;
}
