/*
 * function: BTL_SERVER_FLOW_ProcPlayerSupportHeal
 * address: 0x021C4744
 * packet: pkt_ov093_021C4744
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0202E7E0 and 0x0202E7E4 have no outside witness.
 * Verified with one --thumb without region, dsi/1.1p1 -O4,p:
 * typedef unsigned int u32;
 * typedef struct { u32 a[8]; } Block;
 * typedef struct { u32 mode, old, other; Block current, previous; } State;
 * 0x0202E7E0 EXACT: u32 COMM_PLAYER_SUPPORT_GetMode(State *p) { return p->mode; }
 * 0x0202E7E4 EXACT: void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(State *p) {
 *     p->old = p->mode; p->previous = p->current; p->mode = 3;
 * }
 * lever: a u64 draw and a separate u32 slot preserve the high-product register.
 * symbols:
 *  BTL_MAIN_GetPmsWork 0x021B8630 thumb ov093
 *  BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *  BTL_SERVER_GetClientChecked 0x021BB85C thumb ov093
 *  BTL_SIDE_GetClientPokeParam 0x021B990C thumb ov093
 *  BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *  BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *  BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *  GF_STANDARD_Rand 0x0203F0A8 arm
 *  _ull_mul 0x0209C054 arm
 *  BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *  func_021D59B4 0x021D59B4 thumb ov093
 *  BTL_SERVER_FLOW_TryRecoverHp 0x021C334C thumb ov093
 *  BTL_SERVER_CMD_PushVariable 0x021CD64C thumb ov093
 *  COMM_PLAYER_SUPPORT_GetMode 0x0202E7E0 thumb
 *  COMM_PLAYER_SUPPORT_SavePreviousAndSuspend 0x0202E7E4 thumb
  * note 2026-10-05 (D8 lane16): witnesses COMM_PLAYER_SUPPORT_GetMode and COMM_PLAYER_SUPPORT_SavePreviousAndSuspend filed as src/matched/arm9/COMM_PLAYER_SUPPORT_GetMode.c and COMM_PLAYER_SUPPORT_SavePreviousAndSuspend.c (both EXACT); this file becomes EXACT once the integrator seeds them.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
extern u32 BTL_MAIN_GetPmsWork(u32 **p);
extern u32 COMM_PLAYER_SUPPORT_GetMode(void *);
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
extern void *BTL_SIDE_GetClientPokeParam(char *p, unsigned int i, unsigned int j);
extern int BTL_POKEPARAM_IsFainted(void *p);
extern int BTL_POKEPARAM_IsHpFull(u8 *);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern u32 GF_STANDARD_Rand(void);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *, int);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_SERVER_FLOW_TryRecoverHp(u8 *p, u8 *q, int a, int b);
extern void BTL_SERVER_CMD_PushVariable(void *w, u8 id, ...);
extern void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(void *);
void BTL_SERVER_FLOW_ProcPlayerSupportHeal(u8 *p)
{
    u8 list[4];
    u8 i, n;
    void *work;
    u32 mode, side;
    u8 *desc, *m;
    u32 value, slot;
    u64 draw;
    u8 id;
    int live;
    work = (void *)BTL_MAIN_GetPmsWork(*(void **)(p + 4));
    if (work == 0) return;
    mode = COMM_PLAYER_SUPPORT_GetMode(work);
    if (mode == 0 || mode == 3) return;
    side = BTL_MAIN_GetOwnClientId(*(u8 **)(p + 4));
    desc = BTL_SERVER_GetClientChecked(*(void **)p, (int)side);
    i = 0;
    n = 0;
    for (; i < desc[9]; i++) {
        m = BTL_SIDE_GetClientPokeParam(*(void **)(p + 8), side, (u8)i);
        if (m != 0) {
            if (BTL_POKEPARAM_IsFainted(m) == 0) live = 1;
            else live = 0;
        } else live = 0;
        if (live) {
            if (BTL_POKEPARAM_IsHpFull(m) == 0) list[n++] = BTL_POKEPARAM_GetPokeId(m);
        }
    }
    if (n == 0) return;
    draw = GF_STANDARD_Rand();
    slot = (u32)draw;
    if (n != 0) slot = (u32)((draw * (u32)n) >> 32);
    id = list[slot];
    m = BTL_SIDE_GetPokeByIdThunk(*(char **)(p + 8), id);
    value = (u32)func_021D59B4(m, 14);
    if (mode == 1) value >>= 1;
    if (value == 0) return;
    if (BTL_SERVER_FLOW_TryRecoverHp(p, m, (u16)value, (u32)0)) {
        BTL_SERVER_CMD_PushVariable(*(void **)(p + 12), (u32)0x5a, 0x53, 4, id, 0xffff0000);
        COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(work);
    }
}
