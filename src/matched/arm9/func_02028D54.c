/*
 * function: func_02028D54
 * address:  0x02028D54
 * packet:   pkt_02028D54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_02028D54.c is now a manifest entry (matched class)
 * blocker:  02028E80; 02028EAC
 */

typedef unsigned int   u32;
struct Cmd;
struct SoundParam;
struct SoundParam2;
struct Sys;
extern void *func_02028D7C(void *obj);
extern u32 func_02028FD0(struct SoundParam *obj, u32 kind);
extern void func_02028EAC(struct SoundParam2 *obj, struct Cmd *cmd);
extern void func_02028E80(struct Sys *s);
void func_02028D54(int a0)
{
    int *p = func_02028D7C((void *)a0);
    if (func_02028FD0((struct SoundParam *)a0, *p)) {
        func_02028EAC((struct SoundParam2 *)a0, (struct Cmd *)((int)p));
        func_02028E80((struct Sys *)a0);
    }
}
