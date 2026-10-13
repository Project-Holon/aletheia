/*
 * function: FIELD_MENU_CreateItem
 * address:  0x021A9154
 * packet:   pkt_ov021_021A9154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateAffineActor  0x0204B324  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Item {
    int f00;
    int f04;
    int f08;
    u32 f0C;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 pad16[2];
    u32 f18;
} Item;

typedef struct Src {
    int f00;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
} Src;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    u8 pad08[0x104 - 0x08];
    u32 f104;
    u8 pad108[0x11C - 0x108];
    u32 f11C;
    u8 pad120[0x12C - 0x120];
    u32 f12C;
} Obj;

typedef struct Hdr {
    u16 f00;
    u16 f02;
    u16 f04;
    u8 f06;
    u8 f07;
    u16 f08;
    u16 f0A;
    u32 f0C;
    u32 f10;
    u16 f14;
    u16 f16;
} Hdr;

typedef signed int     s32;
struct Actor;
struct Cfg;
struct CharBuf;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateAffineActor(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void CLACT_SetActorAutoAnimSpeed(struct Actor *a, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *, unsigned int);

void FIELD_MENU_CreateItem(Obj *p, Item *it, const Src *s)
{
    Hdr h;
    u32 k;

    k = FIELD_MSGBG_GetFont((u8 *)FIELDMAP_GetMsgBg(p->f04));
    it->f00 = 1;
    it->f08 = s->f00;
    it->f14 = s->f04;
    it->f15 = s->f05;
    it->f04 = BMP_WIN_Create(6, s->f06, s->f07, 8, 2, 0xD, 1);
    BMP_WIN_MakeScreen((struct Cfg *)it->f04);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)it->f04)), 0);
    PRINTSYS_PrintQueColor((void *)p->f12C, (int)func_02045770((struct Descriptor *)it->f04), 2, 1, s->f0C, k, 0x440);
    if (s->f10 != 0) {
        it->f0C = CLACT_RegisterCharacter((void *)s->f10, s->f14, 0, 1, p->f00);
        it->f10 = CLACT_RegisterCellAnim((void *)s->f10, s->f18, s->f1C, p->f00);
        h.f00 = s->f08;
        h.f02 = s->f09;
        h.f04 = 0;
        h.f06 = 0;
        h.f07 = 0;
        h.f08 = 0;
        h.f0A = 0;
        h.f0C = 0x1000;
        h.f10 = 0x1000;
        h.f14 = 0;
        h.f16 = 2;
        it->f18 = (u32)CLACT_CreateAffineActor(p->f11C, it->f0C, p->f104, it->f10, (u32)(&h), 0, p->f00);
        CLACT_SetActorAutoAnimSpeed((struct Actor *)it->f18, 0x1000);
        func_0204B92C((struct Obj *)it->f18, 1);
        CLACT_SetActorAnimSeq((struct Obj *)it->f18, 0);
        if (it->f08 == 7)
            func_0204B3DC((struct Obj *)it->f18, 0);
        else
            func_0204B3DC((struct Obj *)it->f18, 1);
    } else {
        it->f18 = 0;
    }
}
