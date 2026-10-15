/*
 * function: func_021BD1AC
 * address: 0x021BD1AC
 * packet: pkt_ov172_021BD1AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 wD5 lane12: the loop argument and the two byte stores are the literal 0 (the
 *   original copies r5=0 into r6 before the loop label; it is not the last index).
 * symbols:
 *   func_021BD5D8 0x021BD5D8 thumb ov172
 *   func_021BD844 0x021BD844 thumb ov172
 *   func_021BDBC4 0x021BDBC4 thumb ov172
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   CTVT_CAMVIEW_Create 0x021B6EE0 thumb ov172
 *   func_021B7BA8 0x021B7BA8 thumb ov172
 *   CTVT_TALK_Create 0x021B8C3C thumb ov172
 *   CTVT_DRAW_Create 0x021BA280 thumb ov172
 *   func_021BBA6C 0x021BBA6C thumb ov172
 *   DRAW_SYSTEM_CreateCanvas 0x021B6BE0 thumb ov172
 *   func_021BD5AC 0x021BD5AC thumb ov172
 *   func_020056A0 0x020056A0 thumb
 *   func_0202EB14 0x0202EB14 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021B80DC 0x021B80DC thumb ov172
 *   func_021B80EC 0x021B80EC thumb ov172
 *   GAME_DATA_GetBgmInfo 0x02012A30 thumb
 *   FIELD_SOUND_SYSTEM_StopRingtone 0x02028A70 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;
struct BigObj;
struct CharBuf;
struct Descriptor;
struct R;
struct SoundSys;
extern void func_021BD5D8(u8 *p);
extern void func_021BD844(u8 *p);
extern void func_021BDBC4(u8 *p);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern char *CTVT_CAMVIEW_Create(void *a, u16 b);
extern char *func_021B7BA8(void *p, u16 heap);
extern char *CTVT_TALK_Create(char *unused, u16 heap);
extern u32 CTVT_DRAW_Create(char *, u16);
extern void *func_021BBA6C(int unused, void *p);
extern u32 DRAW_SYSTEM_CreateCanvas(Params *);
extern void func_021BD5AC(int, char *);
extern u32 func_020056A0(void (*)(int, char *), char *, int);
extern int func_0202EB14(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021B80DC(int unused, char *p, u32 v);
extern void func_021B80EC(int unused, char *p, const u8 *src);
extern u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_StopRingtone(struct SoundSys *sys);
extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);
#define W(o) (*(u32 *)(self + (o)))
#define B(o) (*(u8 *)(self + (o)))
#define H(o) (*(u16 *)(self + (o)))
void func_021BD1AC(char *self)
{
    int z = 0;
    int one = 1;
    u8 i;
    u32 h2;
    Params st;
    B(0x18) = one;
    B(0x19) = z;
    W(0x1c) = z;
    func_021BD5D8((u8 *)self);
    func_021BD844((u8 *)self);
    func_021BDBC4((u8 *)self);
    W(0x1d4) = (u32)APP_TASKMENU_RES_Create(4, 7, W(0x1c8), W(0x1d0), H(0));
    W(0x1e0) = (u32)CTVT_CAMVIEW_Create(self, H(0));
    W(0x1e4) = (u32)func_021B7BA8(self, H(0));
    W(0x1e8) = (u32)CTVT_TALK_Create(self, H(0));
    W(0x1ec) = CTVT_DRAW_Create(self, H(0));
    W(0x1f0) = (u32)func_021BBA6C((int)self, (void *)H(0));
    st.heap = H(0);
    st.kind = 2;
    st.count = 0x64;
    st.a = z;
    st.b = 0x100;
    st.c = z;
    st.d = 0xc0;
    W(0x1f4) = DRAW_SYSTEM_CreateCanvas(&st);
    W(4) = func_020056A0(func_021BD5AC, self, 8);
    W(8) = z;
    H(0x38) = z;
    H(0x3a) = z;
    W(0x10) = one;
    W(0x20) = z;
    W(0x24) = z;
    W(0x28) = z;
    W(0x2c) = z;
    W(0x30) = z;
    W(0x34) = z;
    if (func_0202EB14() == 1) W(0x30) = one;
    GFL_NET_RestartWithDefaultTimeout(0, H(0));
    switch (*(u32 *)(W(0x1f8) + 4)) {
    case 0:
        func_021B80DC((int)self, (char *)W(0x1e4), 3);
        W(0xc) = 1;
        break;
    case 1:
        func_021B80DC((int)self, (char *)W(0x1e4), 2);
        W(0xc) = 2;
        break;
    case 2:
        func_021B80DC((int)self, (char *)W(0x1e4), 4);
        func_021B80EC((int)self, (char *)W(0x1e4), (const u8 *)(W(0x1f8) + 8));
        W(0xc) = 2;
        FIELD_SOUND_SYSTEM_StopRingtone((struct SoundSys *)GAME_DATA_GetBgmInfo((const struct BigObj *)(*(u32 *)W(0x1f8))));
        break;
    case 3:
        func_021B80DC((int)self, (char *)W(0x1e4), 5);
        W(0xc) = 2;
        break;
    }
    W(0x1b8) = BMP_WIN_Create(0, 2, 10, 12, 2, 10, 1);
    W(0x1bc) = BMP_WIN_Create(0, 0x12, 10, 12, 2, 10, 1);
    W(0x1c0) = BMP_WIN_Create(0, 2, 0x16, 12, 2, 10, 1);
    W(0x1c4) = BMP_WIN_Create(0, 0x12, 0x16, 12, 2, 10, 1);
    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)(*(u32 *)(self + i * 4 + 0x1b8))), 0);
    }
    B(0x1b4) = 0;
    B(0x1b5) = 0;
    GFL_USE_CancelChangeAndPlayBgm(0x3e9, 0xffff);
}
