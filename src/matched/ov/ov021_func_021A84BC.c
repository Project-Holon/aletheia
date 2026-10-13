/*
 * function: FIELD_MENU_Delete
 * address:  0x021A84BC
 * packet:   pkt_ov021_021A84BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_MENU_DeleteItem  0x021A926C  thumb  ov021
 *   FIELD_MENU_NotifyParentOnExit  0x021A84A8  thumb  ov021
 *   func_02030EAC  0x02030EAC  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   func_02040618  0x02040618  arm
 *   func_020403F4  0x020403F4  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Item {
    int f00;
    void *f04;
    int f08;
    void *f0C;
    void *f10;
    int f14;
    void *f18;
} Item;

typedef struct Obj {
    u8 pad00[0x34];
    Item items[7];
    u8 padF8[0x104 - 0xF8];
    void *f104;
    void *f108;
    void *f10C;
    void *f110;
    void *f114;
    void *f118;
    void *f11C;
    void *f120;
    void *f124;
    void *f128;
    void *f12C;
    void *f130;
} Obj;

extern void FIELD_MENU_DeleteItem(Obj *p, Item *it);
extern void FIELD_MENU_NotifyParentOnExit(Obj *p);
typedef unsigned int   u32;
struct Bank;
struct Node;
struct PrintSys;
extern void func_02030EAC(struct Node *n);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_DeleteRenderer(void *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_020403F4(u32 i);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 func_020307B0(void *p);

void FIELD_MENU_Delete(Obj *p)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        FIELD_MENU_DeleteItem(p, &p->items[i]);
    }
    FIELD_MENU_NotifyParentOnExit(p);
    func_02030EAC(p->f130);
    CLACT_DeleteActor(p->f128);
    CLACT_DeleteActor(p->f124);
    CLACT_DeleteRenderer(p->f120);
    CLACT_DeleteUnit(p->f11C);
    CLACT_ReleaseCellAnim((u32)p->f10C);
    CLACT_ReleaseCharacter((u32)p->f108);
    CLACT_ReleasePalette((u32)p->f104);
    CLACT_ReleaseCellAnim((u32)p->f118);
    CLACT_ReleaseCharacter((u32)p->f114);
    CLACT_ReleasePalette((u32)p->f110);
    func_02040618(6, 3, 0);
    func_020403F4(7);
    func_020403F4(5);
    func_020403F4(6);
    PRINTSYS_QUE_Clear(p->f12C);
    PRINTSYS_QUE_Delete(p->f12C);
    func_020307B0(p);
}
