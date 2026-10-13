/*
 * function: BTL_CLIENT_StepSwapAbilitiesWithPopup
 * address:  0x021D32E0
 * packet:   pkt_ov093_021D32E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * pass 6 2026-10-06 P6L08: EXACT (364 B), also EXACT under -lang c99. The closing change is u16 x, y
 * with BTL_POKEPARAM_SetAbility declared (void *, u16), non-const a, and source order u, v, x, y. The callee
 * (BTL_POKEPARAM_SetAbility.c, strh to a u16 field) also matches EXACT with a u16 parameter, so the prototype is
 * consistent. Why it closes (scheduler trace, scratchpad wD9r/p6_P6L08): the word spill of the narrow
 * variable x uses the unknown-memory alias set (AO1), not a fresh spill alias object. With non-const a,
 * the pointee of a is in that set, so `str x, [sp]` gets a memory edge to the a[1] load and the load
 * waits after it, as in the original. With const a, the pointee of a is not in the set (22 B).
 * Earlier passes (wave75 to pass 6 P6L04) stayed at 13 B with u32 locals.
 * symbols:
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_MAIN_IsPokeSamePair 0x021B9A24 thumb ov093
 *   BTL_CLIENT_IsMainStepActive 0x021CD9E0 thumb ov093
 *   BTL_POKEPARAM_SetAbility 0x021D66D0 thumb ov093
 *   func_021EA768 0x021EA768 thumb ov093
 *   func_021EA778 0x021EA778 thumb ov093
 *   func_021EA7A8 0x021EA7A8 thumb ov093
 *   func_021EA7B8 0x021EA7B8 thumb ov093
 *   gExpGainWork 0x021F3B64 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *, int);
extern int BTL_MAIN_IsPokeSamePair(u32, u32);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *);
struct QJ;
extern void BTL_POKEPARAM_SetAbility(struct QJ *p, u32 v);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA7A8(u32 *p, u32 a2);
extern int func_021EA7B8(u32 *p, u32 a2);
extern u32 gExpGainWork[];
int BTL_CLIENT_StepSwapAbilitiesWithPopup(u32 *a, int *b, u32 *c)
{
    u32 u, v;
    u16 x, y;
    int s, t;
    u8 *p, *q;
    u = (u8)c[0];
    v = (u8)c[1];
    x = (u16)c[2];
    y = (u16)c[3];
    s = BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], u);
    t = BTL_MAIN_GetTrainerSlotOfPoke((void *)a[0], (void *)a[1], v);
    p = BTL_SIDE_GetPokeByIdThunk((char *)a[1], u);
    q = BTL_SIDE_GetPokeByIdThunk((char *)a[1], v);
    switch (*b) {
    case 0:
        if (BTL_CLIENT_IsMainStepActive((u8 *)a)) {
            BTL_POKEPARAM_SetAbility((struct QJ *)p, x);
            BTL_POKEPARAM_SetAbility((struct QJ *)q, y);
            return 1;
        }
        if (BTL_MAIN_IsPokeSamePair(u, v)) {
            BTL_POKEPARAM_SetAbility((struct QJ *)p, x);
            BTL_POKEPARAM_SetAbility((struct QJ *)q, y);
            return 1;
        }
        func_021EA768((u32 *)((int)a[21]), s, 0);
        gExpGainWork[1] = 8;
        (*b)++;
        break;
    case 1:
        func_021EA778((u32 *)a[21], s);
        if (gExpGainWork[1]) gExpGainWork[1]--;
        else {
            func_021EA768((u32 *)a[21], t, 0);
            (*b)++;
        }
        break;
    case 2: {
        u8 r, z;
        r = func_021EA778((u32 *)a[21], s);
        z = func_021EA778((u32 *)a[21], t);
        if (r && z) (*b)++;
        break;
    }
    case 3:
        BTL_POKEPARAM_SetAbility((struct QJ *)p, x);
        BTL_POKEPARAM_SetAbility((struct QJ *)q, y);
        gExpGainWork[1] = 0;
        (*b)++;
        break;
    case 4:
        gExpGainWork[1]++;
        if (gExpGainWork[1] > 8) {
            func_021EA7A8((u32 *)a[21], s);
            (*b)++;
        }
        break;
    case 5:
        if (func_021EA7B8((u32 *)a[21], s)) {
            func_021EA7A8((u32 *)a[21], t);
            (*b)++;
        }
        break;
    case 6:
        if (func_021EA7B8((u32 *)a[21], t)) (*b)++;
        break;
    default:
        return 1;
    }
    return 0;
}
