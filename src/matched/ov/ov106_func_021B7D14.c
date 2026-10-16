/*
 * function: IRC_RANKING_GfxInit
 * address: 0x021B7D14
 * packet: pkt_ov106_021B7D14
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * closed 2026-10-05 (recoup integrator): func_02049658 returns u32 (its matched definition tail-returns ARC_UTIL_UploadBgChar); with the void declaration the later register zeros were copied from the pooled zero; with the real return type the
 *   bytes are EXACT in c99 and c.
 * 2026-10-05 (lane S9, pengy share): twin shape is ov104 func_021B7994 (no exact twin
 * found). Loop, call order and all arguments are right. 508 B vs 492 B, residue:
 * the original pools the stack-argument zero in r4 (movs r4,#0 right after the
 * p[0] store, str r4 for every stack zero) and keeps k=7 in r5 (movs r5,#7 beside
 * the arg setup of the first 02049658(...,3,7,...) call, used for lsls r4,r5,#6
 * = 0x1c0), with the later 7 arguments as literal movs. Mine rematerialises each
 * zero and CSEs the later 7s from k. Tried: bg local for the table read (fixed the
 * loop), i=0 reuse, named int z, no k at all, six per-function pragmas
 * (lifetimes, propagation, common_subs, dead_assignments, scheduling, peephole):
 * none pools the zero. gIrcRankingDispConfig also has no witness (ov106 token did not help).
 * Idioms checked: a-named-zero-argument-pins-the-callers-truncation (z folded, no
 * change), a-repeated-small-constant-takes-a-callee-saved-register (wall note),
 * a-hoisted-loop-invariant-zero-takes-the-freshly-dead-register (n/a),
 * a-constant-loaded-at-entry-into-a-callee-saved-register (n/a).
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049B40 0x02049B40 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   IRC_RANKING_PrintCentered 0x021B91A8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   gIrcRankingDispConfig 0x021B94A8 data
 *   gIrcRankingBgEntries 0x021B9524 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct DispConfig;
struct BgTemplate { u8 bytes[32]; };
typedef struct { u32 bg; struct BgTemplate t; u32 type; } BgEntry;
struct Descriptor;
struct MsgBank;
struct GfFont;
struct StrObj;
extern struct DispConfig gIrcRankingDispConfig;
extern BgEntry gIrcRankingBgEntries[];
extern void MI_CpuFill8(void *, int, u32);
extern void BG_SYS_Create(u32);
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
struct Cfg;
struct CharBuf;
struct Rec;
struct U16Vec;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(unsigned int id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern unsigned int func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 flags);
extern void func_02049B40(u32, u32, u32, u32, u32, u32);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *, u32);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void IRC_RANKING_PrintCentered(struct Descriptor *, struct StrObj *, void *, u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32);
void IRC_RANKING_GfxInit(u32 *p, void *arg, u32 heap) {
 int i; int k; u32 bg; struct MsgBank *msg; struct GfFont *font; struct StrObj *str;
 MI_CpuFill8(p, 0, 0x10);
 BG_SYS_Create(heap);
 BMP_WIN_Init(heap);
 BG_SYS_SetGraphicsMode(&gIrcRankingDispConfig);
 for (i = 0; i < 8; i++) {
  bg = gIrcRankingBgEntries[i].bg;
  BG_SYS_InitBgLayer((u8)bg, &gIrcRankingBgEntries[i].t, (u8)gIrcRankingBgEntries[i].type);
  BG_SYS_FreeSlot(bg);
  func_02040588(bg, 1);
 }
 p[0] = (u32)func_020490F4(0x4d, heap);
 func_02049B68((void *)p[0], 0, 0, 0, 0, heap);
 func_02049658((void *)p[0], 1, 3, 0, 0, 0, heap);
 func_02049658((void *)p[0], 3, 0, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 4, 3, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 6, 0, 0, 0, 0, heap);
 func_02049B68((void *)p[0], 0, 4, 0, 0, heap);
 k = 7;
 func_02049658((void *)p[0], 3, 7, 0, 0, 0, heap);
 func_020498F4((void *)p[0], 7, 7, 0, 0, 0, heap);
 BG_SYS_Init(1, 0, 1, 0);
 BG_SYS_Init(5, 0, 1, 0);
 p[1] = func_02049740((void *)p[0], 2, 1, 0, 0, heap);
 p[2] = func_02049740((void *)p[0], 2, 5, 0, 0, heap);
 func_02049B40(0x17, 5, 0, k << 6, 0x20, heap);
 func_02049B40(0x17, 5, 4, k << 6, 0x20, heap);
 ARC_TOOL_DeleteHandle((void *)p[0]);
 msg = func_02045B38(0, 2, 0x32, heap);
 font = GF_FONT_Create(0x17, 0, 0, 0, heap);
 p[3] = BMP_WIN_Create(0, 3, 1, 0x1a, (u32)2, (u32)0xe, (u32)1);
 BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p[3]), 0xf);
 str = (struct StrObj *)func_02045EC0(msg, 0);
 IRC_RANKING_PrintCentered((struct Descriptor *)p[3], str, GAME_DATA_GetMyStatus(arg), (u32)font);
 STRBUF_Delete((struct U16Vec *)str);
 GF_FONT_Delete(font);
 MSGDATA_Delete((struct Rec *)msg);
 BMP_WIN_TransferChars((struct Descriptor *)p[3]);
 BMP_WIN_MakeScreen((struct Cfg *)p[3]);
 BG_SYS_PushTile(0);
}
