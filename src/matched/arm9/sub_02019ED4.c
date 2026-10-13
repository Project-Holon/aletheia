/*
 * function: POKE_REGULATION_CheckPartyUsable
 * address:  0x02019ED4
 * packet:   pkt_02019ED4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the inferred extent runs 2 bytes past the 250-byte body because the
 * follower at 0x02019FD0 has no lr-saving prologue and so carries no label.
 * No byte differs.
 *
 * The party "is this team legal for the rule set" check.  It reads each
 * member's species (id 5) and form (id 0x9E) into two parallel u16[6] stack
 * arrays, zeroes the species of any member POKE_REGULATION_CheckPokemon rejects, then runs an
 * O(n^2) duplicate-species scan that zeroes the worse of each colliding pair
 * (worse = the larger form value) and decrements a running count.  If the
 * surviving count is below what func_0200AE54(ctx, 2) requires it answers 4;
 * otherwise the answer is 0 or 1 from POKE_REGULATION_FindValidOrder.
 *
 * Two layout tells pin the frame:
 *   - the 12-byte MI_CpuFill8 buffer is declared LAST, not first: the later
 *     declarator gets the lower stack address, which is what puts `pad` at
 *     sp+0x10 and `species` at sp+0x28
 *     (docs/idioms/local-declaration-order-is-stack-order.md).
 *   - the outer scan loop assigns its counter before its bound (`i = 0;`
 *     then `lim = n - 1;`), or the `movs r0,#0` and the `subs r0,r0,#1`
 *     swap places
 *     (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * VERSION SENSITIVITY: party ids 5 and 0x9E and the rule-set keys 7 and 2 are
 * content numbering; the team size 6 is the array bound and is structural.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/POKE_REGULATION_CheckPartyUsable.c \
 *       --func POKE_REGULATION_CheckPartyUsable --addr 0x02019ED4 --cc 1.1p1 --thumb
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_REGULATION_CheckPokemon  0x02019DA4  thumb
 *   func_0200AE54  0x0200AE54  thumb
 *   POKE_REGULATION_FindValidOrder  0x0201A59C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 POKEPARTY_GetCount(void *p);
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int POKE_REGULATION_CheckPokemon(void *ctx, void *mon);
struct Reg;
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern int POKE_REGULATION_FindValidOrder(void *a0, void *a1, void *a2);

int POKE_REGULATION_CheckPartyUsable(void *ctx, void *q)
{
    u16 species[6];
    u16 form[6];
    u8 pad[12];
    int n;
    int cnt;
    int i;
    int j;
    int lim;
    int r;

    n = POKEPARTY_GetCount(q);
    cnt = n;
    MI_CpuFill8(pad, 0, 12);
    for (i = 0; i < n; i++) {
        void *mon = POKEPARTY_GetMember(q, i);

        species[i] = (u16)func_02017E1C(mon, 5, 0);
        form[i] = (u16)func_02017E1C(mon, 0x9E, 0);
        if (POKE_REGULATION_CheckPokemon(ctx, mon) != 0) {
            species[i] = 0;
            cnt--;
        }
    }

    if ((int)func_0200AE54(ctx, 7) == 0 && n > 1) {
        i = 0;
        lim = n - 1;
        for (; i < lim; i++) {
            for (j = i + 1; j < n; j++) {
                if (species[i] == species[j] && species[i] != 0) {
                    if (form[i] > form[j]) {
                        species[i] = 0;
                    } else {
                        species[j] = 0;
                    }
                    cnt--;
                }
            }
        }
    }

    if (cnt < (int)func_0200AE54(ctx, 2)) {
        return 4;
    }

    r = 0;
    if (POKE_REGULATION_FindValidOrder(ctx, q, 0) != 1) {
        r = 1;
    }
    return r;
}
