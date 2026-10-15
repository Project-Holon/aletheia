/*
 * function: CTVT_TALK_Init
 * address:  0x021B8CC8
 * packet:   pkt_ov172_021B8CC8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets up the BG layers and five OBJ sprites of the screen, then clears the state words.
 * 2026-10-05 (wD8 lane06): closed by statement order of the zero stores. mwcc keeps one constant
 *   of the join block in r7; with the zero stores in the order 0, 8, 0xA4 (address-temp store last)
 *   and 0x38, 0x34, 0x8C, 0xC the constant 1 wins r7 as in the image. Earlier lanes found the
 *   0x15/0x16 if/else for rc.z (holds &rc in r7 for the first block).
 * symbols:
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020409B4 0x020409B4 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   COMM_TVT_SYS_GetHeapId 0x021BE00C thumb ov172
 *   COMM_TVT_SYS_GetArc 0x021BE010 thumb ov172
 *   COMM_TVT_SYS_GetResId 0x021BE018 thumb ov172
 *   COMM_TVT_SYS_GetClactUnit 0x021BE024 thumb ov172
 *   COMM_TVT_SYS_GetViewSwapped 0x021BE0B4 thumb ov172
 *   COMM_TVT_SYS_GetComm 0x021BDFE4 thumb ov172
 *   CTVT_COMM_GetMarkerSlot 0x021B8B68 thumb ov172
 *   COMM_TVT_SYS_PlaceSlotMarker 0x021BE210 thumb ov172
 *   CTVT_MIC_IsCaptureDone 0x021BA270 thumb ov172
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };
struct Cfg;
struct CharBuf;
struct Descriptor;
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_020409B4(u32 layer);
extern struct Obj *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u16 COMM_TVT_SYS_GetHeapId(u16 *p);
extern u32 COMM_TVT_SYS_GetArc(void *p);
extern u32 COMM_TVT_SYS_GetResId(void *p, int i);
extern u32 COMM_TVT_SYS_GetClactUnit(void *p);
extern u32 COMM_TVT_SYS_GetViewSwapped(void *p);
extern u32 COMM_TVT_SYS_GetComm(void *p);
extern u8 CTVT_COMM_GetMarkerSlot(int unused, char *p);
extern void COMM_TVT_SYS_PlaceSlotMarker(void *a, u32 b);
extern int CTVT_MIC_IsCaptureDone(void *p);

void CTVT_TALK_Init(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = COMM_TVT_SYS_GetHeapId(a);
    g = (void *)COMM_TVT_SYS_GetArc(a);
    func_02049658(g, 0xB, 6, 0, 0, 0, h);
    func_020498F4(g, 0x11, 6, 0, 0, 0, h);
    func_02049658(g, 0xB, 5, 0, 0x5000, 0, h);
    func_020498F4(g, 0xF, 5, 0, 0, 0, h);
    func_0207D63C((void *)0x04001050, 2, 0x14, 5, 0xF);
    func_020409B4(6);
    func_020409B4(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = *(u8 *)(p + 0xD) + 0x19;
    rc.a = 0;
    rc.b = 2;
    *(struct Obj **)(p + 0x90) = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x90), 1);
    if (COMM_TVT_SYS_GetViewSwapped(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    *(struct Obj **)(p + 0x94) = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x94), 1);
    rc.z = 0x14;
    *(struct Obj **)(p + 0x9C) = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x9C), 1);
    rc.z = 0x18;
    *(struct Obj **)(p + 0xA0) = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 5), COMM_TVT_SYS_GetResId(a, 1), COMM_TVT_SYS_GetResId(a, 9), &rc, 1, h);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0xA0), 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    *(struct Obj **)(p + 0x98) = CLACT_CreateActor((void *)COMM_TVT_SYS_GetClactUnit(a), COMM_TVT_SYS_GetResId(a, 6), COMM_TVT_SYS_GetResId(a, 2), COMM_TVT_SYS_GetResId(a, 10), &rc, 1, h);
    CLACT_SetActorDrawEnable(*(struct Obj **)(p + 0x98), 1);
    CLACT_SetActorAutoAnim(*(struct Obj **)(p + 0x98), 1);
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xA4) = 0;
    *(u32 *)(p + 0xA8) = 3;
    *(u32 *)(p + 0x2C) = BMP_WIN_Create(4, 8, 3, 0x10, 8, 0xA, 1);
    *(u32 *)(p + 0x7C) = BMP_WIN_Create(4, 1, 1, 0x1E, 4, 0xA, 1);
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x2C)), 0);
    BMP_WIN_MakeScreen(*(void **)(p + 0x2C));
    BMP_WIN_TransferChars(*(void **)(p + 0x2C));
    *(u32 *)(p + 0x80) = 0;
    *(u32 *)(p + 0x84) = 0;
    *(u32 *)(p + 0x28) = 0;
    func_020409B4(4);
    *(u8 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u8 *)(p + 0xC) = 0;
    {
        u32 r = (u8)CTVT_COMM_GetMarkerSlot((int)a, (char *)COMM_TVT_SYS_GetComm(a));
        if (r != 0xFF) {
            COMM_TVT_SYS_PlaceSlotMarker(a, r);
            *(u32 *)(p + 0xA4) = 2;
        }
    }
    if (CTVT_MIC_IsCaptureDone(*(void **)(p + 0x10)) == 0)
        *(u32 *)(p + 0xA4) = 2;
}
