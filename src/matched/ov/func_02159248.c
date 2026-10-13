/*
 * function: SCRIPT_WORK_CmdHalt
 * address:  0x02159248
 * packet:   pkt_02159248
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011290  0x02011290  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct ScriptVm;
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);

int SCRIPT_WORK_CmdHalt(struct ScriptVm *a0)
{

    a0 = (struct ScriptVm *)func_02011290(a0);
loc_0215924E:
a0 = (struct ScriptVm *)1;
    return (int)a0;}
