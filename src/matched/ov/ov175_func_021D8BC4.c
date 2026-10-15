/*
 * function: WIFIBATTLEMATCH_NET_CompStepH
 * address: 0x021D8BC4
 * packet: pkt_ov175_021D8BC4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_GetSetCompStat 0x021D9D50 thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   WIFIBATTLEMATCH_NET_SetCompWaitCallback 0x021D9A1C thumb ov175
 *   WIFIBATTLEMATCH_NET_GetCompWaitResult 0x021D9A30 thumb ov175
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   WIFIBATTLEMATCH_NET_CompStepK 0x021D8EC8 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepI 0x021D8CF0 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompCleanup 0x021D9064 thumb ov175
 *   WIFIBATTLEMATCH_NET_CompStepM 0x021D9090 thumb ov175
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern void func_021E8AA0(int *, int);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
extern int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *, void *, void *);
extern void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *, void *);
extern u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern void WIFIBATTLEMATCH_NET_CompStepK(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompStepI(u32 sys, int *state, char *p);
extern void WIFIBATTLEMATCH_NET_CompCleanup(void *obj, int unused, u8 *p);
extern void WIFIBATTLEMATCH_NET_CompStepM(u32 sys, int *state, char *p);
void WIFIBATTLEMATCH_NET_CompStepH(int *a, int *state, char *ctx)
{
    int r;
    u32 q;
    char *sub = *(char **)(ctx + 0x104);
    switch (*state) {
    case 0:
        func_021E8738(*(int **)(ctx + 0x2C), *(int *)(ctx + 0x14), 0x28, 2);
        *state = 5;
        func_021E8AB4((unsigned)a, 1);
        return;
    case 1:
        WIFIBATTLEMATCH_NET_GetSetCompStat(ctx, *(void **)(sub + 0x34));
        GAME_DATA_SaveStart(**(int **)(sub + 8));
        *state = 2;
        return;
    case 2:
        r = GAME_DATA_SaveMain(**(u8 ***)(sub + 8));
        if (r == 2) {
            *state = 3;
            return;
        }
        if (r == 3)
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompStepK);
        return;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompStepI);
            return;
        case 2:
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(ctx, (void *)WIFIBATTLEMATCH_NET_CompStepM);
            *state = 4;
            return;
        }
        return;
    case 4:
        q = WIFIBATTLEMATCH_NET_GetCompWaitResult(ctx);
        if (q == 0)
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompStepI);
        else if (q - 1 <= 1)
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompStepK);
        else if (q == 3)
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(*(char **)(ctx + 0x34), 0, 0)) {
        case 1:
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompStepI);
            return;
        case 2:
            func_021E8AA0(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        }
        return;
    case 5:
        if (func_021E8844(*(int **)(ctx + 0x2C)))
            func_021E8AB8((unsigned)a);
        return;
    }
}
