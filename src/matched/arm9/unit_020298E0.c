/*
 * unit:     yes
 * address:  0x020298E0
 * packet:   pkt_020295D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020298E0
 *
 * Part of the (task body, task spawner) family that makes up the tail of
 * field_sound_system.c.  A four state body: it issues a command 2, waits for the system to go idle,
 * hands a resource off through func_02028A50 and then reports done.  The
 * resource is resolved from work->unk00 before the switch, even though only
 * the third state uses it.
 *
 * This body has no spawner inside the packet: nothing in
 * 0x020295D8..0x02029D44 holds its address, so it stands as its own file and
 * carries no self-reference to attest.
 *
 * What capped it: the call to func_02028A50 is the only branch to that
 * address in the image, so the `label` class had no witness outside this one
 * function and no cut helped.  Wave 26 closed it the honest way, by giving
 * 0x02028A50 an entry: func_02028D2C, func_02029F54 and func_02029F60 are now
 * EXACT, src/matched/unit_02028A50.c graduated with them, and this call site
 * resolves `matched`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020298E0.c  *       --addr 0x020298E0 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Work {
    void *unk00;
    void *unk04;
    u32   unk08;
    u16   unk0C;
    u16   unk0E;
};

typedef u32 (*TaskFn)(void *task, u32 *state, struct Work *work);

struct Ctx;
struct Sys;
extern void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d);
extern u32 func_020289B8(struct Sys *s);
extern void  func_02028A50(void *sys, void *res);
extern void *func_020120F4(const struct Ctx *p);

u32 func_020298E0(void *task, u32 *state, struct Work *work)
{
    void *res = func_020120F4(work->unk00);
    void *sys = work->unk04;

    switch (*state) {
    case 0:
        func_020289F8(sys, 2, 0, work->unk0E, 0);
        (*state)++;
        break;
    case 1:
        if (func_020289B8(sys) == 0) {
            (*state)++;
        }
        break;
    case 2:
        func_02028A50(sys, res);
        (*state)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
