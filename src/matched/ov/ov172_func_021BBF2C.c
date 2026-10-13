/*
 * function: func_021BBF2C
 * address:  0x021BBF2C
 * packet:   pkt_ov172_021BBF2C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-04 (D3-06): byte-identical (1724 bytes); 4 of 106 relocations wait on
 *   unlabelled ov172 Thumb leaves filed EXACT this wave as src/matched/ov/
 *   ov172_func_021B8B7C.c, ov172_func_021B8C14.c, ov172_func_021B8C20.c,
 *   ov172_func_021BE0F0.c. After the integrator manifest gives them shard
 *   witnesses, this file should verify EXACT and move to src/matched/ov.
 *   Keys: cnt is block-local in the fC==1 block (sets its stack slot);
 *   case 6 jumps into case 10 by tail merge (code written twice).
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE004  0x021BE004  thumb  ov172
 *   func_021BE010  0x021BE010  thumb  ov172
 *   func_021BE02C  0x021BE02C  thumb  ov172
 *   func_021BE030  0x021BE030  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021BE054  0x021BE054  thumb  ov172
 *   func_021BE0D0  0x021BE0D0  thumb  ov172
 *   func_021BE0EC  0x021BE0EC  thumb  ov172
 *   func_021BE0F0  0x021BE0F0  thumb  ov172
 *   func_021BE318  0x021BE318  thumb  ov172
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_021BDFDC  0x021BDFDC  thumb  ov172
 *   func_021BDFE4  0x021BDFE4  thumb  ov172
 *   func_021B7578  0x021B7578  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021B7B64  0x021B7B64  thumb  ov172
 *   func_021B80DC  0x021B80DC  thumb  ov172
 *   func_021B80EC  0x021B80EC  thumb  ov172
 *   func_021B8B7C  0x021B8B7C  thumb  ov172
 *   func_021B8C14  0x021B8C14  thumb  ov172
 *   func_021B8C20  0x021B8C20  thumb  ov172
 *   func_021BC5E8  0x021BC5E8  thumb  ov172
 *   func_021BC7FC  0x021BC7FC  thumb  ov172
 *   func_021BCE2C  0x021BCE2C  thumb  ov172
 *   func_021BD038  0x021BD038  thumb  ov172
 *   func_021BD0C4  0x021BD0C4  thumb  ov172
 *   func_021BD134  0x021BD134  thumb  ov172
 *   GFL_USE_StopAllSe  0x02006210  thumb  arm9
 *   APP_TASKMENU_WIN_IsFinish  0x02028230  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 *   TOUCHPANEL_GetTrg  0x02035C60  arm  arm9
 *   BMP_WIN_Create  0x020450F0  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_ClearScreen  0x020456F8  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
struct Cfg;
struct PrintSys;
struct Obj;
struct Actor;

extern u16 func_021BE00C(u16 *p);
extern u32 func_021BE004(void *p);
extern u32 func_021BE010(void *c);
extern u32 func_021BE02C(void *c);
extern void func_021BE030(void *c, u32 v);
extern u32 func_021BE044(void *c);
extern u8 func_021BE054(void *c);
extern u32 func_021BE0D0(void *c);
extern u32 func_021BE0EC(void *c);
extern void func_021BE0F0(u8 *c);
extern void func_021BE318(char *a0, void *a1);
extern void func_021BE34C(void *c);
extern u32 func_021BDFDC(void *c);
extern u32 func_021BDFE4(void *c);
extern void func_021B7578(int x, char *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7B64(int x, char *p);
extern void func_021B80DC(int unused, char *p, u32 v);
extern void func_021B80EC(int unused, char *p, const u8 *src);
extern u8 *func_021B8B7C(void *c, u8 *x);
extern void func_021B8C14(void *c, u8 *x);
extern u32 func_021B8C20(void *c, u8 *x);
extern void func_021BC5E8(void *ctx, u8 *list);
extern void func_021BC7FC(void *ctx, u8 *list);
extern void func_021BCE2C(void *c, char *p, char *r, u8 i);
extern void func_021BD038(void *c, char *p);
extern void func_021BD0C4(void *c, char *p, int msg);
extern void func_021BD134(void *c, char *p, u32 msg);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void GFL_USE_StopAllSe(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void *BMP_WIN_GetBmp(struct Descriptor *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 a);
extern void func_02041EE4(u32 index, u32 a, u32 b);

#define W(o) (*(u32 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define OBJ (*(struct Obj **)(p + 0x400))

int func_021BBF2C(void *a0, char *p)
{
    u32 t;
    u16 v;
    u32 *st;
    u32 t2;
    u8 i, j;
    char *r;
    char *q;
    u8 *ip;
    u32 w;
    struct Descriptor *d;

    v = func_021BE00C(a0);
    st = (u32 *)func_021BE004(a0);
    switch (W(8)) {
    case 0:
        if (func_021BE02C(a0) == 1)
            WIPE_SYS_Start((void *)0, 1, 1, 0, 6, 1, v);
        else
            WIPE_SYS_Start((void *)4, 1, 1, 0, 6, 1, v);
        W(8) = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1) {
            u32 *s = (u32 *)func_021BE004(a0);
            if (func_021BE0EC(a0) == 1)
                W(8) = 11;
            else if (s[1] == 2 || s[1] == 3)
                W(8) = 8;
            else
                W(8) = 5;
        }
        break;
    case 2:
        WIPE_SYS_Start((void *)4, 0, 0, 0, 6, 1, v);
        func_021BE030(a0, 0);
        W(8) = 4;
        break;
    case 3:
        if (func_021B7590((int)a0, (char *)func_021BDFDC(a0)) == 1) {
            WIPE_SYS_Start((void *)0, 0, 0, 0, 6, 1, v);
            func_021BE030(a0, 0);
            W(8) = 4;
        }
        break;
    case 4:
        if (WIPE_SYS_EndCheck() == 1) {
            if (W(0x18) == 0 || W(0x18) == 5)
                return 4;
            return 1;
        }
        break;
    case 5:
        func_021BC5E8(a0, (u8 *)p);
        func_021BD038(a0, p);
        break;
    case 6:
        if (W(0x18) == 0 || W(0x18) == 5) {
            if (CLACT_IsActorAnimActive((struct Actor *)OBJ) == 0) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            }
            break;
        }
        if (APP_TASKMENU_WIN_IsFinish((void *)W(0x1c)) != 1)
            break;
        if (W(0x18) == 2) {
            t = func_021BDFE4(a0);
            func_021B80DC((int)a0, (char *)t, 4);
            func_021B80EC((int)a0, (char *)t, (const u8 *)(p + 0x1fd + B(3) * 0x24));
            func_021BD134(a0, p, 0x18);
            W(0x38) = 1;
            W(8) = 7;
            H(0x34) = 0;
            H(0x36) = 0;
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
        } else {
            t2 = func_021BDFE4(a0);
            W(8) = 9;
            func_021BD134(a0, p, 0x14);
            W(0x38) = 1;
            H(0x36) = 0;
            func_021B80DC((int)a0, (char *)t2, 3);
            APP_TASKMENU_WIN_Delete((void *)W(0x1c));
            W(0x1c) = 0;
            ip = func_021B8B7C(a0, (u8 *)t2);
            for (i = 0; i < 3; i++) {
                if (B(i) == 0xff) {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = 0xff;
                } else {
                    for (j = 0; j < 6; j++)
                        ip[i * 6 + j + 0x22] = *(u8 *)(p + B(i) * 0x24 + j + 0x1fd);
                }
            }
            ip[0x21] |= 2;
            func_021B8C14(a0, (u8 *)t2);
        }
        CLACT_SetActorAnimSeq(OBJ, 0xf);
        break;
    case 7:
    case 8:
    case 9:
        func_021BDFE4(a0);
        if (func_021BE054(a0) >= 2) {
            if (W(0x28) == 0) {
                t = func_021BDFDC(a0);
                GFL_USE_StopAllSe();
                GFL_USE_PlaySeDefaultVolume(0x73e);
                func_021B7B64((int)a0, (char *)t);
            }
            W(8) = 2;
        }
        if (W(8) == 9) {
            H(0x36)++;
            if (H(0x36) >= 0x78) {
                H(0x36) = 0;
                GFL_USE_PlaySeInSlot((void *)0x73d, 2);
            }
        }
        if (W(8) == 9) {
            if (func_021B8C20(a0, (u8 *)func_021BDFE4(a0)) == 1) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x27);
                W(8) = 10;
            }
        } else if (W(8) == 7 || W(8) == 8) {
            H(0x34)++;
            if (H(0x34) >= 0x4b0) {
                func_021B80DC((int)a0, (char *)func_021BDFE4(a0), 2);
                func_021BD134(a0, p, 0x28);
                W(8) = 10;
            }
        }
        break;
    case 10:
        if (TOUCHPANEL_GetTrg() == 1) {
            if (((u32 *)func_021BE004(a0))[1] == 2) {
                func_021B7578((int)a0, (char *)func_021BDFDC(a0));
                W(0x18) = 0;
                W(8) = 3;
            } else {
                for (i = 0; i < 3; i++)
                    B(i) = 0xff;
                W(8) = 5;
                B(3) = 0xff;
                func_0201F7A8((void *)W(0x30), 1);
                d = (struct Descriptor *)W(0x30);
                BMP_WIN_ClearScreen(d);
                func_020409B4(BMP_WIN_GetBgLayer(d));
                func_021BE34C(a0);
                CLACT_SetActorAnimSeq(OBJ, 1);
                W(0x18) = 4;
            }
        }
        break;
    case 11:
        BMP_WIN_Delete((struct Descriptor *)W(0x2c));
        W(0x2c) = BMP_WIN_Create(4, 2, 5, 0x1c, 0xe, 0xa, 1);
        func_021BD0C4(a0, p, 0x29);
        W(8) = 12;
        break;
    case 12:
        if (func_021BE054(a0) >= 2 && W(0x28) == 0) {
            GFL_USE_StopAllSe();
            W(0x28) = 1;
            GFL_USE_PlaySeDefaultVolume(0x73e);
        }
        if (TOUCHPANEL_GetTrg() == 1 || func_021BE0D0(a0) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            func_0201F7A8((void *)W(0x2c), 1);
            d = (struct Descriptor *)W(0x2c);
            BMP_WIN_ClearScreen(d);
            func_020409B4(BMP_WIN_GetBgLayer(d));
            BMP_WIN_Delete((struct Descriptor *)W(0x2c));
            W(0x2c) = BMP_WIN_Create(4, 1, 0x15, 0x15, 2, 0xa, 1);
            func_021BE0F0(a0);
            if (st[1] == 2 || st[1] == 3) {
                CLACT_SetActorAnimSeq(OBJ, 0xf);
                if (func_021BE054(a0) < 2)
                    func_021BD134(a0, p, 0x18);
                W(0x38) = 1;
                W(0x18) = 3;
                W(8) = 8;
            } else {
                W(8) = 5;
                W(0x18) = 4;
                CLACT_SetActorAnimSeq(OBJ, 1);
                v = func_021BE00C(a0);
                w = func_021BE010(a0);
                func_02049658((void *)w, 0xb, 4, 0, 0x2800, 0, v);
                func_020498F4((void *)w, 0x12, 4, 0, 0, 0, v);
                func_020409B4(4);
            }
        }
        break;
    }
    if (st[1] != 3 && func_021BE0EC(a0) == 0) {
        func_021BC7FC(a0, (u8 *)p);
        for (i = 0; i < 15; i++) {
            r = p + i * 0x1c;
            if (*(u32 *)(r + 0x44) == 1) {
                struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
                if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp(*(struct Descriptor **)(r + 0x54))) == 0) {
                    d = *(struct Descriptor **)(r + 0x54);
                    BMP_WIN_TransferChars(d);
                    BMP_WIN_MakeScreen((struct Cfg *)d);
                    func_02041B6C(BMP_WIN_GetBgLayer(d));
                    *(u32 *)(r + 0x44) = 0;
                }
            }
        }
        if (W(0xc) == 1) {
            u8 cnt = 0;
            for (i = 0; i < 15; i++)
                func_021BCE2C(a0, p, p + 0x40 + i * 0x1c, i);
            func_02041EE4(6, 3, H(4));
            for (i = 0; i < 3; i++) {
                if (B(i) != 0xff)
                    cnt++;
            }
            for (j = 0; j < 15; j++) {
                r = p + j * 0x24;
                if (*(u32 *)(r + 0x1e4) == 1) {
                    q = p + 0x40 + *(u8 *)(r + 0x204) * 0x1c;
                    if (*(u32 *)(r + 0x1ec) == 1 && *(u8 *)(r + 0x203) < 4 && (B(3) == 0xff || B(3) == j))
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xa);
                    else if (cnt == 3 || B(3) != 0xff || *(u8 *)(r + 0x203) == 4)
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 0xb);
                    else
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 0xc), 9);
                    if (*(u32 *)(r + 0x1f4) == 1) {
                        *(u32 *)(r + 0x1f4) = 0;
                        CLACT_SetActorAnimSeq(*(struct Obj **)(q + 8), 0x22);
                    }
                }
            }
            W(0xc) = 0;
        }
    }
    if (W(0x20) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x2c))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x2c));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x2c));
            func_020409B4(4);
            W(0x20) = 0;
        }
    }
    if (W(0x24) == 1) {
        struct PrintSys *ps = (struct PrintSys *)func_021BE044(a0);
        if (PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp((struct Descriptor *)W(0x30))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)W(0x30));
            BMP_WIN_MakeScreen((struct Cfg *)W(0x30));
            func_020409B4(4);
            W(0x24) = 0;
            if (W(0x38) == 1) {
                W(0x38) = 0;
                func_021BE318(a0, (void *)W(0x30));
            }
        }
    }
    if (W(0x1c) != 0)
        APP_TASKMENU_WIN_Update((void *)W(0x1c));
    return 2;
}
