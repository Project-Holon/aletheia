/*
 * function: SCRIPT_SYS_CreateScriptEventSimple
 * address:  0x02158768
 * packet:   pkt_02158768
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_SYS_CreateScriptEvent  0x02158920  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEvent(int a, int b, int c, int d, int e);

struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int o4;
    struct Desc *r;
t5 = a1 + 0;
t4 = a2 + 0;
a1 = 0;
    o4 = a1;
a1 = a3 + 0;
a2 = t5 + 0;
a3 = t4 + 0;
    r = SCRIPT_SYS_CreateScriptEvent(a0, a1, a2, a3, o4);
loc_0215877C:
    return r;
}
