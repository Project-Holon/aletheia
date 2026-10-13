/*
 * function: func_021C3E9C
 * address: 0x021C3E9C
 * packet: pkt_ov136_021C3E9C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wD7 lane15): closed. func_021C414C takes a second argument (u8 *p, its matched
 *   definition reads r1), so case 2 keeps the ctx+0x10 pointer in r1 for that call.
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   PROCSYS_Push 0x02031348 arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   PMSI_PARAM_CheckCanceled 0x0202411C thumb
 *   PMSI_PARAM_GetSentence 0x02024134 thumb
 *   PMSI_PARAM_GetWord 0x02024124 thumb
 *   PMSI_PARAM_Delete 0x020240FC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_021C414C 0x021C414C thumb ov136
 *   func_021C3FC8 0x021C3FC8 thumb ov136
 *   ov110_id 0x0000006E data
 *   D_021C7750 0x021C7750 data
 *   D_021C775C 0x021C775C data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PROCSYS_Main(void *p);
extern void PROCSYS_Push(void *h, u32 id, void *a, void *b);
extern int func_02034AC4(int handle);
extern void func_02034A5C(int handle);
extern int PMSI_PARAM_CheckCanceled(unsigned char *p);
struct Sub02008C20Obj;
extern void PMSI_PARAM_GetSentence(char *a, void *b);
extern unsigned int PMSI_PARAM_GetWord(unsigned short *p);
extern void PMSI_PARAM_Delete(void *a);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_021C414C(void *a, u8 *p);
extern void func_021C3FC8(u8 *ctx, u8 *arg);
extern u8 ov110_id[];
extern u8 D_021C7750[];
extern u8 D_021C775C[];
int func_021C3E9C(int unused, u32 *state, u16 *msg, u8 *ctx)
{
    u32 ret = PROCSYS_Main(*(void **)(ctx + 0x1C));
    switch (*state) {
    case 0:
        **(u16 **)(ctx + 0x10) = *msg;
        PROCSYS_Push(*(void **)(ctx + 0x1C), (u32)-1, D_021C7750, *(void **)(ctx + 0x10));
        *state = 1;
        break;
    case 1: {
        u16 v;
        if (ret == 1)
            break;
        v = **(u16 **)(ctx + 0x10);
        if (v != 4) {
            if (v == 0xFFFF)
                *state = 2;
            else
                goto s3;
        } else
            *state = 2;
        break;
    s3:
        *state = 3;

        break;
    }
    case 2:
        if (*msg == 1) {
            u32 r;
            u8 *p = *(u8 **)(ctx + 0x10);
            if (*(u16 *)p == 4) {
                func_021C414C(*(void **)(msg + 10), p);
                func_02008DF0(func_02008C58(*(void **)(msg + 8)), 0x1D);
                r = 1;
            } else {
                r = 0;
            }
            *(u32 *)(msg + 2) = r;
        }
        return 1;
    case 3:
        func_02034AC4((int)ov110_id);
        func_021C3FC8(ctx, (u8 *)msg);
        PROCSYS_Push(*(void **)(ctx + 0x1C), (u32)-1, D_021C775C, *(void **)(ctx + 8));
        *state = 4;
        break;
    case 4:
        if (ret == 1)
            break;
        if (PMSI_PARAM_CheckCanceled(*(void **)(ctx + 8)) == 0) {
            u8 *q = *(u8 **)(ctx + 0x10);
            void *h = *(void **)(ctx + 8);
            if (q[2] < 3)
                PMSI_PARAM_GetSentence(h, q + 0x16 + q[2] * 8);
            else
                *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32) = PMSI_PARAM_GetWord(*(u16 **)(ctx + 8));
        }
        PMSI_PARAM_Delete(*(void **)(ctx + 8));
        func_02034A5C((int)ov110_id);
        *state = 0;
        break;
    }
    return 0;
}
