/*
 * function: func_021CFFAC
 * address: 0x021CFFAC
 * packet: pkt_ov093_021CFFAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D00FE before func_021D0100.
 * lever: hold the one-word aggregate accessor result before passing by value.
 * symbols:
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021D799C 0x021D799C thumb ov093
 *   func_021D055C 0x021D055C thumb ov093
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct G { u8 pad[0xf4]; u64 seed; u64 mul; u64 add; };
typedef union { u32 v; } Word;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern u32 func_0201C314(void *p);
extern u8 func_0201C1C8(void *p);
extern u16 func_021D57FC(void *);
extern int func_021D799C(int, int);
extern int func_021D055C(void *, void *, int);
int func_021CFFAC(struct G *g, void *mon, void *target)
{
    u32 id;
    int valid;
    u32 kind;
    Word slot;
    if (func_021D62C4(mon, 0x1b)) {
        slot = func_021D6314(mon, 0x1b);
        id = func_021E8B80(slot);
        if (id) {
            valid = func_0201C314((void *)id);
            kind = func_0201C1C8((void *)id);
            if (func_021D799C(kind, func_021D57FC(target)) == 0 && valid) {
                if (func_021D055C(g, target, 4)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 3) >> 32) < 2;
                }
                if (func_021D055C(g, target, 3)) {
                    g->seed = g->mul * g->seed + g->add;
                    return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
                }
            }
            if (!valid) {
                g->seed = g->mul * g->seed + g->add;
                return (u32)(((g->seed >> 32) * 2) >> 32) < 1;
            }
        }
    }
    return 0;
}
