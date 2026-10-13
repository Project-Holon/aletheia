/*
 * unit:     yes
 * address:  0x02018A00
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_SetAbility, POKE_TOOL_SetBoxAbility
 *
 * The two functions after src/matched/unit_020188B4.c and the three that its
 * header records as a near miss.  POKE_TOOL_SetAbility is the eight byte
 * `ldr r3, [pc, #0]; bx r3` tail call that
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes; its callee is the
 * next function in this same range, so the site is the `local` class.
 *
 * symbols:
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   func_02019C90  0x02019C90  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
struct Personal;
extern void *func_02019C54(u32 a, u32 b);
extern u32  func_02019C7C(void *h);
extern u32  func_02019C90(u16 a, u16 b, u32 i);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);

void POKE_TOOL_SetBoxAbility(void *p, u32 a, u32 b);

void POKE_TOOL_SetAbility(void *p, u32 a, u32 b)
{
    POKE_TOOL_SetBoxAbility(p, a, b);
}

void POKE_TOOL_SetBoxAbility(void *p, u32 a, u32 b)
{
    void *h;
    u32 t;
    u32 k;
    u32 v;

    v = func_02019C90((u16)a, (u16)b, 0x1C);
    if (v != 0) {
        POKE_TOOL_SetBoxValue(p, 0xA, v);
        POKE_TOOL_SetBoxValue(p, 0x71, 1);
        return;
    }
    h = func_02019C54((u16)a, (u16)b);
    t = func_02017E88(p, 0, 0);
    k = 0x1A;
    if (func_02019C7C(h) == 2 && (t & (1 << 16))) {
        k = 0x1B;
    }
    POKE_TOOL_SetBoxValue(p, 0xA, func_0201AE1C(h, k));
}
