/*
 * function: func_021ECC2C
 * address: 0x021ECC2C
 * packet: pkt_ov093_021ECC2C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_MAIN_GetOwnClientId 0x021B8FF4 thumb ov093
 *   BTLV_SCU_GetBallStates 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021F7EB4 0x021F7EB4 thumb ov094
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   BTL_MAIN_GetSlotFromViewPos 0x021B8ED8 thumb ov093
 *   BTL_SIDE_GetPokeAtPos 0x021B98AC thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_GetDisplayMon 0x021D5864 thumb ov093
 *   func_021F7EE8 0x021F7EE8 thumb ov094
 *   BTL_MSG_FormatArgs 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021EDA04 0x021EDA04 thumb ov093
 */
#include "../include/Obj00027.h"
#include "../include/Obj00378.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_MAIN_GetOwnClientId(u8 *);
extern void BTLV_SCU_GetBallStates(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern int func_021F7EB4(void);
extern void func_021F7998(u32);
extern int func_021F827C(u32);
extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_POKEPARAM_IsFainted(void *);
struct Work;
extern void *BTL_POKEPARAM_GetDisplayMon(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void BTL_MSG_FormatArgs(u32, u16, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
struct E;
struct S;
struct T;
extern int func_021ECF68(struct T *p);
extern void func_021F8260(u32 i);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *s);
extern void func_021EDA04(struct E *e);
int func_021ECC2C(u8 *p, int *state)
{
    u8 *b = p + 0xf0;
    unsigned long i;
    u32 buf[7];
    u16 msg;
    switch (*state) {
    case 0:
        b[22] = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00027 *)p)->f134);
        BTLV_SCU_GetBallStates(p, buf, b[22], 4, 0);
        func_021F823C(buf);
        (*state)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[15] = 2;
            b[16] = 4;
            b[17] = 6;
            b[21] = 0;
            b[22] = BTL_MAIN_GetOwnClientId(*(u8 * *)&((struct Obj00027 *)p)->f134);
            for (i = 0; i < 3U; i++) {
                b[12 + i] = BTL_MAIN_GetSlotFromViewPos(*(u8 * *)&((struct Obj00027 *)p)->f134, b[15 + i]);
                ((u8 **)b)[i] = (u8 *)BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj00027 *)p)->f138, b[12 + i]);
                b[18 + i] = BTL_POKEPARAM_GetPokeId(((u8 **)b)[i]);
                if (!BTL_POKEPARAM_IsFainted(((u8 **)b)[i])) b[21]++;
            }
            func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00378 *)b)->f0), b[15]);
            if (b[21] > 1) func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00378 *)b)->f4), b[16]);
            if (b[21] > 2) func_021F7EE8(BTL_POKEPARAM_GetDisplayMon(((struct Obj00378 *)b)->f8), b[17]);
            func_021F7998(0x234);
            if (b[21] == 3) msg = 13;
            else msg = b[21] == 2 ? 12 : 11;
            BTL_MSG_FormatArgs(((struct Obj00027 *)p)->f34, msg, 3, b[18], b[19], b[20]);
            func_021ECEB8(p, ((struct Obj00027 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[12] * 12));
            if (b[21] > 1) func_021EDA04((struct E *)(p + 0x48 + b[13] * 12));
            if (b[21] > 1) func_021EDA04((struct E *)(p + 0x48 + b[14] * 12));
            (*state)++;
        }
        break;
    case 5:
        return 1;
    }
    return 0;
}
