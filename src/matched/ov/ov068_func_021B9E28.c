/*
 * function: OPTION_MENU_InitSprites
 * address:  0x021B9E28
 * packet:   pkt_ov068_021B9E28
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The `movs r7, #0` at entry that feeds the second memset's value comes
 * from naming CLACT_SetUnitDefaultRenderer's argument (the bank CLACT_CreateUnit returned);
 * with that call left argument-free the zero folds to `movs r1, #0`.
 * Table rows are indexed `i - 2` over a loop from 2 to 12.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   func_020490F4  0x020490F4  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   gOptionMenuChoices     0x021BB704  data  ov068  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
} Ent;

extern char gClActorInitParam[];
extern Ent gOptionMenuChoices[];

extern void func_02082BCC(void *p, int c, u32 n);
struct Bank;
struct Cfg;
struct Obj;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 a, u32 b);
typedef signed int     s32;
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int CLACT_RegisterPalette(void *, int, int, int, int);
extern int CLACT_RegisterCharacter(void *, int, int, int, int);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern int CLACT_CreateActor(int, int, int, int, Local *, int, int);
struct Obj;
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

void OPTION_MENU_InitSprites(int *p, void *res, u32 heap)
{
    Local s;
    void *h;
    int i;

    func_02082BCC(p, 0, 0x54);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (u32)res, heap);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer((struct Bank *)p[0]);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    h = func_020490F4(0x1b, heap);
    p[1] = CLACT_RegisterPalette(h, 6, 0, 0, heap);
    p[2] = CLACT_RegisterCharacter(h, 5, 0, 0, heap);
    p[3] = CLACT_RegisterCellAnim(h, 4, 3, heap);
    p[4] = CLACT_RegisterCharacter(h, 0xc, 0, 0, heap);
    p[5] = CLACT_RegisterCellAnim(h, 0xb, 0xa, heap);
    ARC_TOOL_DeleteHandle(h);
    func_02082BCC(&s, 0, 8);
    s.e = 2;
    s.d = 2;
    for (i = 2; i < 13; i++) {
        s.a = gOptionMenuChoices[i - 2].f8;
        s.b = gOptionMenuChoices[i - 2].fC;
        p[6 + i] = CLACT_CreateActor(p[0], p[2], p[1], p[3], &s, 0, heap);
        func_0204B92C((struct Obj *)p[6 + i], 0);
    }
    func_02082BCC(&s, 0, 8);
    s.a = 0x80;
    s.b = 0x60;
    s.e = 2;
    s.d = 1;
    p[7] = CLACT_CreateActor(p[0], p[4], p[1], p[5], &s, 0, heap);
    func_0204B6F4((struct Obj *)p[7], 6, 1);
    if (GFL_NET_GetRunState())
        GFL_NET_RestartWithDefaultTimeout(1, heap);
}
