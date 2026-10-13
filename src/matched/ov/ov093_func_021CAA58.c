/*
 * function: BTL_SERVER_FLOW_DecideMoveTargetsDouble
 * address: 0x021CAA58
 * packet: pkt_ov093_021CAA58
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * blocker: thirteen local Thumb veneers 021CAC24..021CACE4 have no
 * outside witness; their ARM pool target 0x0689CB49 is outside image regions.
 * extent: 458-byte function, two bytes alignment, thirteen 16-byte veneers.
 * body: no concrete differences; 21 of 34 relocations resolve.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_SERVER_FLOW_ResolveCurseTargetPosition 0x021CAA24 thumb ov093
 *   BTL_SIDE_GetPokeAtPosThunk 0x021B98A4 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_GetEnemyPokeAtLane 0x021CB174 thumb ov093
 *   BTL_SERVER_FLOW_GetPartnerPoke 0x021CB1A4 thumb ov093
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_ProcTargetChange 0x021CB1D4 thumb ov093
 *   func_021CAC24 0x021CAC24 thumb ov093
 *   func_021CAC34 0x021CAC34 thumb ov093
 *   func_021CAC44 0x021CAC44 thumb ov093
 *   func_021CAC54 0x021CAC54 thumb ov093
 *   func_021CAC64 0x021CAC64 thumb ov093
 *   func_021CAC74 0x021CAC74 thumb ov093
 *   func_021CAC84 0x021CAC84 thumb ov093
 *   func_021CAC94 0x021CAC94 thumb ov093
 *   func_021CACA4 0x021CACA4 thumb ov093
 *   func_021CACB4 0x021CACB4 thumb ov093
 *   func_021CACC4 0x021CACC4 thumb ov093
 *   func_021CACD4 0x021CACD4 thumb ov093
 *   func_021CACE4 0x021CACE4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern u8 BTL_SERVER_FLOW_ResolveCurseTargetPosition(u8 *, u8 *, u8 *, int, u16);
extern u8 *BTL_SIDE_GetPokeAtPosThunk(char * const *q, u8 b);
extern u32 BTL_CALC_Random(u32);
extern void *BTL_SERVER_FLOW_GetEnemyPokeAtLane(u8 *p, unsigned int n, int k);
extern u8 *BTL_SERVER_FLOW_GetPartnerPoke(u8 *, int);
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern u8 BTL_SERVER_FLOW_ProcTargetChange(u8 *, u8 *, u8 *, u32);
extern void func_021CAC24(void *, void *);
extern void func_021CAC34(void *, void *);
extern void func_021CAC44(void *, void *);
extern void func_021CAC54(void *, void *);
extern void func_021CAC64(void *, void *);
extern void func_021CAC74(void *, void *);
extern void func_021CAC84(void *, void *);
extern void func_021CAC94(void *, void *);
extern void func_021CACA4(void *, void *);
extern void func_021CACB4(void *, void *);
extern void func_021CACC4(void *, void *);
extern void func_021CACD4(void *, void *);
extern void func_021CACE4(void *, void *);
int BTL_SERVER_FLOW_DecideMoveTargetsDouble(u8 *p, u8 *a, u16 move, u8 *q, int id, void *out)
{
    int n = BTL_MAIN_GetTrainerSlotOfPoke(*(void **)(p + 4), *(void **)(p + 8), BTL_POKEPARAM_GetPokeId(a));
    u8 key = BTL_SERVER_FLOW_ResolveCurseTargetPosition(p, q, a, n, move);
    u8 *b;
    u8 selected;
    switch (*(u32 *)(q + 12)) {
    case 0:
        b = BTL_SIDE_GetPokeAtPosThunk(*(void **)(p + 8), key);
        break;
    case 3:
        b = BTL_SIDE_GetPokeAtPosThunk(*(void **)(p + 8), key);
        break;
    case 9:
        b = BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)BTL_CALC_Random(2));
        break;
    case 5:
        func_021CAC24(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)0));
        func_021CAC34(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)1));
        return 2;
    case 4:
        func_021CAC44(out, BTL_SERVER_FLOW_GetPartnerPoke(p, n));
        func_021CAC54(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)0));
        func_021CAC64(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)1));
        return 3;
    case 8:
        func_021CAC74(out, a);
        func_021CAC84(out, BTL_SERVER_FLOW_GetPartnerPoke(p, n));
        func_021CAC94(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)0));
        func_021CACA4(out, BTL_SERVER_FLOW_GetEnemyPokeAtLane(p, (int)n, (u8)1));
        return 3;
    case 7:
        if (id == 31) func_021CACB4(out, a);
        else func_021CACB4(out, (void *)BTL_SIDE_GetPokeByIdThunk(*(char **)(p + 8), id));
        return 1;
    case 1:
        func_021CACC4(out, BTL_SIDE_GetPokeAtPosThunk(*(void **)(p + 8), key));
        return 1;
    case 2:
        func_021CACD4(out, BTL_SERVER_FLOW_GetPartnerPoke(p, n));
        return 1;
    case 13:
        if (id != 31) {
            b = (u8 *)BTL_SIDE_GetPokeByIdThunk(*(char **)(p + 8), id);
            break;
        }
        return 0;
    case 6: case 10: case 11: case 12: default:
        return 0;
    }
    if (b) {
        selected = BTL_SERVER_FLOW_ProcTargetChange(p, a, q, BTL_POKEPARAM_GetPokeId(b));
        if (selected != 31) b = (u8 *)BTL_SIDE_GetPokeByIdThunk(*(char **)(p + 8), selected);
        func_021CACE4(out, b);
        return 1;
    }
    return 0;
}
