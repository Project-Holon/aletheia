/*
 * function: SCRCMD_PROC_OnBagClosed
 * address: 0x0215C700
 * packet: pkt_ov010_0215C700
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;
typedef struct Outputs { u16 *first; u16 *second; } Outputs;
typedef struct Context { char pad[0x34]; u32 first; u32 second; } Context;
typedef struct Pair { Context *context; Outputs *outputs; } Pair;
extern u32 func_020307B0(void *p);
void SCRCMD_PROC_OnBagClosed(Pair *p)
{
    Context *c = p->context;
    Outputs *o = p->outputs;
    if (c->first == 0)
        *o->first = B_FALSE;
    else
        *o->first = B_TRUE;
    *o->second = c->second;
    func_020307B0(p->outputs);
    func_020307B0(p->context);
}
