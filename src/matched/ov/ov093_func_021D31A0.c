/*
 * function: BTL_CLIENT_StepClearSidePosition
 * address:  0x021D31A0
 * packet:   pkt_ov093_021D31A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent 172, compiled 170: trailing 2-byte padding)
 *
 * Levers: the 0x26..0x29 selection is a `static inline u16` helper returning nested
 * ternaries; inlined, its result stays in r0 and each arm branches (the inner join of the
 * u == 3 arm is the unthreaded `b` hop). Written in the caller (ternary, if/else, nested
 * ternary, call in each arm) it is if-converted into r1, and a plain `static` helper is
 * not inlined. `u` is `int` (permuter: u32 put c[1] first into r7 in case 0).
 *
 * symbols:
 *   BTL_SIDE_GetSlotOfClient  0x021B9AEC  thumb  ov093
 *   BTL_SLOT_Rotate  0x021B9C50  thumb  ov093
 *   BTLV_CORE_StartClearSidePosition  0x021EAA6C  thumb  ov093
 *   BTLV_CORE_RunProc  0x021EAAD8  thumb  ov093
 *   BTL_MAIN_IsTrainerSlotNpc  0x021B9F70  thumb  ov093
 *   BTLV_CORE_PrintSideMessage  0x021EA678  thumb  ov093
 *   BTLV_CORE_WaitMessage  0x021EA710  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern char *BTL_SIDE_GetSlotOfClient(char *p, int i);
extern void BTL_SLOT_Rotate(u8 **p, int k, u8 **o1, u8 **o2);
extern void BTLV_CORE_StartClearSidePosition(u32 a, int b, int c);
extern int BTLV_CORE_RunProc(u32 a);
extern int BTL_MAIN_IsTrainerSlotNpc(u8 *p, int i);
extern void BTLV_CORE_PrintSideMessage(char *p, u16 k, int *c);
extern int BTLV_CORE_WaitMessage(u32 *p);

static inline u16 sel(u32 u, u32 k)
{
    if (u == 3) {
        return (k != 0) ? 0x26 : 0x27;
    }
    return (k != 0) ? 0x28 : 0x29;
}

int BTL_CLIENT_StepClearSidePosition(u32 *a, int *b, u32 *c)
{
    u32 v;
    int u;
    u8 k;
    char *p;

    switch (*b) {
    case 0:
        u = (u8)c[0];
        v = (u8)c[1];
        p = BTL_SIDE_GetSlotOfClient((char *)a[1], u);
        BTL_SLOT_Rotate((u8 **)p, v, 0, 0);
        BTLV_CORE_StartClearSidePosition(a[0x15], u, v);
        (*b)++;
        break;
    case 1:
        if (BTLV_CORE_RunProc(a[0x15]) != 0) {
            u = (u8)c[1];
            if (u == 1) {
                return 1;
            }
            k = BTL_MAIN_IsTrainerSlotNpc((u8 *)a[0], (u8)c[0]);
            BTLV_CORE_PrintSideMessage((char *)a[0x15], sel(u, k), (int *)c);
            (*b)++;
        }
        break;
    case 2:
        if (BTLV_CORE_WaitMessage((u32 *)a[0x15]) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
