/*
 * function: TR_AI_CmdEnd
 * address: 0x021895AC
 * packet: pkt_ov096_021895AC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02011290 0x02011290 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct ScriptVm;
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
int TR_AI_CmdEnd(u8 *a, u8 *b)
{
    b[0x44] |= 1; func_02011290((struct ScriptVm *)a); return 1;
}
