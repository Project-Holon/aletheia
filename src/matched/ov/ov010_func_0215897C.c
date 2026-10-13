/*
 * function: SCRIPT_SYS_CallEvent
 * address:  0x0215897C
 * packet:   pkt_ov010_0215897C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queue a task on the script's event list.
 *
 * symbols:
 *   SCRIPT_WORK_GetEvent  0x02158F50  thumb  ov010
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

extern void *SCRIPT_WORK_GetEvent(void *vm);
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

void SCRIPT_SYS_CallEvent(void *vm, void *task)
{
    GAME_EVENT_CallEvent(SCRIPT_WORK_GetEvent(vm), task);
}
