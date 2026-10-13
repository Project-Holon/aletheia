/*
 * function: EVENT_BATTLE_REC_SAVE_ProcMain
 * address:  0x02154CF8
 * packet:   pkt_ov008_02154CF8
 * region:   ov008
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 wave P16 lane E10: stage 15 truth value is built after the call
 * (c = f(b91); k = 1; if (c == 0) k = 0; zero arm for w94 == 0 shares the
 * same zero). Closes the 121-byte DIFF; the mid-function pool island follows.
 * BA38 returns u32.
 *
 * 18-stage task on *mode.  PROCSYS_Push's second/third arguments are an
 * overlay id and an address in that overlay (0xD5/ov213, 0x61/ov097,
 * 0xD6/ov214; the -1 one points into ov093, which stage 6 loads by id 0x5D
 * and stage 12 unloads).
 *
 * symbols:
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   BATTLE_REC_FreeWork  0x0200B424  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   BATTLE_REC_LoadToolOverlay  0x0200BA58  thumb
 *   BATTLE_REC_UnloadToolOverlay  0x0200BA68  thumb
 *   BATTLE_REC_IsVersionSupported  0x0200BA38  thumb
 *   func_021EEE78  0x021EEE78  thumb  ov188
 *   ov093_id       0x0000005D  data   a1
 *   ov097_id       0x00000061  data   a1
 *   ov213_id       0x000000D5  data   a1
 *   ov214_id       0x000000D6  data   a1
 *   d_021BB0B0     0x021BB0B0  data   ov213  a4
 *   d_021F75EC     0x021F75EC  data   ov097  a4
 *   d_021F03C4     0x021F03C4  data   ov093  a4
 *   d_021EFDAC     0x021EFDAC  data   ov093  a4
 *   d_021BB474     0x021BB474  data   ov214  a4
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    int w0;
    char pad4[0xA - 4];
    u8 name[6];
} Rec;

typedef struct {
    Rec rec[4];
    int w40;
    int w44;
} B;

typedef struct {
    char pad0[0x21];
    u8 b21;
    u8 b22;
    char pad23[0x8C - 0x23];
    int w8C;
    char pad90[0x91 - 0x90];
    u8 b91;
    char pad92[0x94 - 0x92];
    int w94;
    char pad98[0xC8 - 0x98];
    u8 names[4][6];
} A;

typedef struct {
    int w00;
    A *p4;
    B *p8;
    int w0C;
    int w10;
    int w14;
    int w18;
    int w1C;
    int w20;
    int w24;
    int w28;
    int w2C;
} Obj;

typedef struct {
    int w00;
    int w04;
    int w08;
    int w0C;
    int w10;
    int w14;
    int w18;
} Ctx;

typedef signed int     s32;
struct Entry;
extern unsigned int PROCSYS_Main(void *p);
extern void PROCSYS_Push(int h, u32 id, void *a, void *b);
extern u32 func_0200FB24(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void func_02034A5C(s32 handle);
extern int func_02034AC4(s32 handle);
extern void BATTLE_REC_FreeWork(void);
extern void BATTLE_REC_AllocWork(u32 heap);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_StartTimingSync(int a, int b);
extern int  GFL_NET_CheckTimingSync(int a, int b);
extern void BATTLE_REC_LoadToolOverlay(void);
extern void BATTLE_REC_UnloadToolOverlay(void);
extern u32 BATTLE_REC_IsVersionSupported(u32 v);
extern void func_021EEE78(void *p);

extern char ov093_id[];
extern char ov097_id[];
extern char ov213_id[];
extern char ov214_id[];
extern char d_021BB0B0[];
extern char d_021F75EC[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_021BB474[];

u32 EVENT_BATTLE_REC_SAVE_ProcMain(void *task, int *mode, Obj *obj, Ctx *ctx)
{
    int r = PROCSYS_Main((void *)ctx->w00);
    int n, lo, hi, i, j, odd, k;
    u32 c;

    if (r != 1 && func_0200FB24() != 0 && *mode >= 0 && *mode < 13) {
        if (ctx->w14 == 1)
            GFL_NET_COMMAND_DeleteCommandTable(0x100);
        if (ctx->w10 == 1)
            func_02034A5C((u32)ov093_id);
        if (ctx->w18 == 1)
            BATTLE_REC_FreeWork();
        return 1;
    }

    switch (*mode) {
    case 0:
        if (obj->p4->b22 == 0)
            obj->p8->w44 = 1;
        else
            obj->p8->w44 = 3;
        PROCSYS_Push(ctx->w00, (u32)ov213_id, d_021BB0B0, obj->p8);
        *mode = 1;
        break;
    case 1:
        if (r == 1)
            break;
        if (obj->p4->b22 == 0)
            *mode = 6;
        else
            *mode = 2;
        break;
    case 2:
        GFL_NET_StartTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xC9);
        *mode = 3;
        break;
    case 3:
        if (GFL_NET_CheckTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xC9) == 0)
            break;
        *mode = 4;
        break;
    case 4:
        if (obj->p4->b21 <= 1) {
            ctx->w0C = 0;
            ctx->w04 = obj->p8->rec[0].w0;
            ctx->w08 = obj->p8->rec[1].w0;
        } else {
            ctx->w0C = 1;
            ctx->w04 = obj->p8->rec[1].w0;
            ctx->w08 = obj->p8->rec[0].w0;
        }
        PROCSYS_Push(ctx->w00, (u32)ov097_id, d_021F75EC, &ctx->w04);
        *mode = 5;
        break;
    case 5:
        if (r == 1)
            break;
        *mode = 6;
        break;
    case 6:
        ctx->w10 = 1;
        func_02034AC4((u32)ov093_id);
        ctx->w14 = 1;
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xC8);
        *mode = 7;
        break;
    case 7:
        if (GFL_NET_CheckTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xC8) == 0)
            break;
        *mode = 8;
        break;
    case 8:
        ctx->w18 = 1;
        BATTLE_REC_AllocWork(0x76);
        PROCSYS_Push(ctx->w00, -1, d_021EFDAC, obj->p4);
        *mode = 9;
        break;
    case 9:
        if (r == 1)
            break;
        *mode = 10;
        break;
    case 10:
        *mode = 11;
        break;
    case 11:
        GFL_NET_StartTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xCA);
        *mode = 12;
        break;
    case 12:
        if (GFL_NET_CheckTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xCA) == 0)
            break;
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        ctx->w14 = 0;
        func_02034A5C((u32)ov093_id);
        ctx->w10 = 0;
        BATTLE_REC_LoadToolOverlay();
        func_021EEE78(obj->p4);
        BATTLE_REC_UnloadToolOverlay();
        *mode = 13;
        break;
    case 13:
        if (obj->p4->b22 == 0)
            obj->p8->w44 = 2;
        else
            obj->p8->w44 = 4;
        switch (obj->p4->w8C) {
        case 1:
        case 4:
            obj->p8->w40 = 0;
            break;
        case 0:
        case 3:
            obj->p8->w40 = 1;
            break;
        case 2:
            obj->p8->w40 = 2;
            break;
        case 6:
            break;
        default:
            obj->p8->w40 = 2;
            break;
        }
        if (obj->p4->b22 == 0) {
            n = 1;
            lo = 0;
            hi = 1;
        } else {
            n = 3;
            lo = 0;
            hi = 2;
        }
        odd = obj->p4->b21;
        for (i = 0; i <= n; i++) {
            if ((i & 1) == (odd & 1)) {
                if (odd & 1)
                    k = (i & 2) + 1;
                else
                    k = i & 2;
                for (j = 0; j < 6; j++)
                    obj->p8->rec[lo + (i >> 1)].name[j] = obj->p4->names[k][j];
            } else {
                if (odd & 1)
                    k = i & 2;
                else
                    k = (i & 2) + 1;
                for (j = 0; j < 6; j++)
                    obj->p8->rec[hi + (i >> 1)].name[j] = obj->p4->names[k][j];
            }
        }
        if (obj->p4->w8C == 6) {
            *mode = 16;
            break;
        }
        PROCSYS_Push(ctx->w00, (u32)ov213_id, d_021BB0B0, obj->p8);
        *mode = 14;
        break;
    case 14:
        if (r == 1)
            break;
        *mode = 15;
        break;
    case 15:
        if (obj->p4->w94 == 0) k = 0; else { c = BATTLE_REC_IsVersionSupported(obj->p4->b91); k = 1; if (c == 0) k = 0; }
        obj->w1C = k;
        obj->w18 = obj->w00;
        obj->w20 = 1;
        obj->w24 = 1;
        obj->w28 = obj->w0C;
        obj->w2C = obj->w10;
        PROCSYS_Push(ctx->w00, (u32)ov214_id, d_021BB474, &obj->w18);
        *mode = 16;
        break;
    case 16:
        if (r == 1)
            break;
        BATTLE_REC_FreeWork();
        ctx->w18 = 0;
        *mode = 17;
        break;
    case 17:
        return 1;
    }
    return 0;
}
