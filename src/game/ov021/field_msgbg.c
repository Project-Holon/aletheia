/*
 * file:     field_msgbg.c
 * unit:     yes
 * function: func_021901EC, func_02190270, func_0219027C, func_021902A4, func_021902AC, func_021902BC, func_02190344, func_02190378, func_02190398, func_021903CC, func_021903E0, func_0219047C, func_02190490, func_0219049C, func_021904A8, func_021904AC, func_021904B0, func_021904C8, func_021904D0, func_021904DC, func_021904EC, func_02190538, func_02190550, func_02190590, func_021905C8, func_02190604, func_0219061C, func_02190620, func_0219063C, func_02190678, func_0219067C, func_02190680, func_02190708, func_02190728, func_02190740, func_02190758, func_02190764, func_0219077C, func_02190788, func_02190794, func_021907A8, func_021907C0, func_021907C4, func_0219082C, func_02190844, func_02190854, func_02190860, func_02190938, func_02190960, func_0219097C, func_02190988, func_021909BC, func_021909E4, func_02190A14, func_02190A20, func_02190A28, func_02190A64, func_02190A6C, func_02190A74, func_02190AC4, func_02190ACC, func_02190AEC, func_02190B08, func_02190B1C, func_02190B2C, func_02190BE4, func_02190C78, func_02190C94, func_02190D08, func_02190D2C, func_02190D48, func_02190D5C, func_02190DCC, func_02190E40, func_02190E74, func_02190EB8, func_02190EF0, func_02190F64, func_02190F7C, func_02190F9C, func_02190FA0, func_02191008, func_0219103C, func_02191084, func_021910C0, func_02191134, func_02191164, func_02191184, func_021911B4, func_021911B8, func_0219129C, func_021912D8, func_021912F8, func_0219131C, func_02191348, func_02191388, func_021914CC, func_02191504, func_02191558, func_021915B4, func_021915EC, func_0219160C, func_0219161C, func_02191648, func_02191674, func_021916A8, func_021916E0, func_02191794, func_021917C0, func_021917C4, func_02191830, func_02191870, func_021918DC, func_0219194C, func_0219196C, func_02191978, func_021919AC, func_021919C8, func_02191A04, func_02191A10, func_02191B14, func_02191BE8, func_02191D88, func_02191DC8, func_02191FA0, func_02192138, func_0219214C, func_021921C8, func_02192244, func_02192264, func_021922A4, func_021924F0, func_02192570, func_02192628, func_0219269C, func_021926D8, func_0219270C, func_0219272C, func_02192788, func_021927B0, func_021927C0, func_021927E8, func_021927F8, func_021927FC, func_02192860, func_021928C0, func_021928F8, func_021929E8, func_02192A04, func_02192B20, func_02192B64, func_02192BC0, func_02192BD0, func_02192CF0, func_02192E0C, func_02192EB8, func_02192EE0, func_02192F74, func_02192FA4, func_02192FEC, func_02193044, func_02193060, func_02193068, func_021930C0, func_02193130, func_02193144, func_02193170, func_0219319C, func_021931C4, func_021931F4, func_02193200, func_02193208, func_0219320C, func_02193210, func_02193228, func_02193260, func_021932A0
 * address:  0x021901EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Includes the former unit_02192860.c and unit_02192CF0.c (0x02192860..0x021932BF).
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   d_021DDA50  0x021DDA50  data  ov021  a4
 *   func_020056A0  0x020056A0  thumb
 *   func_02194798  0x02194798  thumb  ov021
 *   func_02031140  0x02031140  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0219470C  0x0219470C  thumb  ov021
 *   func_02194760  0x02194760  thumb  ov021
 *   func_02194764  0x02194764  thumb  ov021
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_0201C724  0x0201C724  thumb  arm9
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02043AF4  0x02043AF4  arm  arm9
 *   func_0201FF30  0x0201FF30  thumb
 *   func_02020CF8  0x02020CF8  thumb
 *   func_02020D10  0x02020D10  thumb  arm9
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_020200CC  0x020200CC  thumb  arm9
 *   func_02020234  0x02020234  thumb
 *   func_0201F81C  0x0201F81C  thumb
 *   func_0201F878  0x0201F878  thumb  arm9
 *   func_0201F898  0x0201F898  thumb
 *   func_0201F8F4  0x0201F8F4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201F91C  0x0201F91C  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021D3F38     0x021D3F38  data   ov021  a4
 *   d_021D3E68     0x021D3E68  data   ov021  a4
 *   func_0201CD10  0x0201CD10  thumb
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02006238  0x02006238  thumb  arm9
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0201CE34  0x0201CE34  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02194848  0x02194848  thumb  ov021
 *   func_02194888  0x02194888  thumb  ov021
 *   func_021948CC  0x021948CC  thumb  ov021
 *   func_02194940  0x02194940  thumb  ov021
 *   func_02194950  0x02194950  thumb  ov021
 *   func_02194960  0x02194960  thumb  ov021
 *   func_0219492C  0x0219492C  thumb  ov021
 *   func_02194990  0x02194990  thumb  ov021
 *   func_0219499C  0x0219499C  thumb  ov021
 *   func_02194974  0x02194974  thumb  ov021
 *   func_02194984  0x02194984  thumb  ov021
 *   func_02040618  0x02040618  arm
 *   func_02194A00  0x02194A00  thumb  ov021
 *   func_02194A48  0x02194A48  thumb  ov021
 *   func_02194A34  0x02194A34  thumb  ov021
 *   func_021947E8  0x021947E8  thumb  ov021
 *   func_0201D42C  0x0201D42C  thumb  arm9
 *   func_020458F8  0x020458F8  arm
 *   func_02045838  0x02045838  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043678  0x02043678  arm
 *   func_02045374  0x02045374  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045738  0x02045738  arm
 *   func_02045740  0x02045740  arm
 *   func_020456F8  0x020456F8  arm
 *   func_02041300  0x02041300  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_02043814  0x02043814  arm
 *   func_02049624  0x02049624  arm
 *   func_02049B90  0x02049B90  arm
 *   func_0201D37C  0x0201D37C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb  arm9
 *   func_020437DC  0x020437DC  arm  arm9
 *   func_020437E4  0x020437E4  arm  arm9
 *   func_020439A0  0x020439A0  arm  arm9
 *   func_020437D4  0x020437D4  arm  arm9
 *   func_0204A1BC  0x0204A1BC  arm  arm9
 *   func_02062A4C  0x02062A4C  arm  arm9
 *   func_02082EA4  0x02082EA4  arm  arm9
 *   func_0201DC80  0x0201DC80  thumb
 *   func_02045874  0x02045874  arm
 *   func_020436FC  0x020436FC  arm  arm9
 *   d_021D3E50     0x021D3E50  data   ov021  a1
 *   d_021D3E60     0x021D3E60  data  a2
 *   d_021D3E58     0x021D3E58  data  a2
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02194670  0x02194670  thumb  ov021
 *   func_02194704  0x02194704  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3E98     0x021D3E98  data  a4
 *   d_021D3E78     0x021D3E78  data  a4
 *   d_021D3ED8     0x021D3ED8  data  a4
 *   d_021D3EF8     0x021D3EF8  data  a4
 *   d_021D3EB8     0x021D3EB8  data  a4
 *   func_02005C8C  0x02005C8C  thumb  arm9
 *   func_02030EAC  0x02030EAC  arm  arm9
 *   func_0204047C  0x0204047C  arm
 *   d_021D3F18     0x021D3F18  data  a4
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_02195588  0x02195588  thumb  ov021
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0201F548  0x0201F548  thumb  arm9
 *   func_02012FFC  0x02012FFC  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 */
#include "field_msgbg_types.h"
#include "talkmsgwin_types.h"

/* Cursor y offsets per animation frame. */
typedef struct FieldMsgCursorOffsets {
    u16 offsetY[3];
} FieldMsgCursorOffsets;

#define REG_BLDCNT_ADDR 0x04000050
#define REG_BG2CNT (*(volatile u16 *)0x0400000C)

#define PAD_BUTTON_AB 0x0003 /* A and B */

/* windowKind values */
#define FIELD_MSGBG_PALETTE_SYSTEM 0xE
#define FIELD_MSGBG_PALETTE_TALK 0xB

/* Image of a BG template (struct BgTemplate, 8 words) as copied from the overlay data. */
typedef struct FieldBgTemplate {
    u32 word[8];
} FieldBgTemplate;

struct BgTemplate;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *bgTemplate, u32 type);
extern void func_02040C14(u32 frame, u32 value, u32 count, u32 index);
extern void func_02040588(u8 frame, u8 enable);
extern void func_0207D63C(u32 reg, u32 mode, u32 planeMask, u32 coeffA, u32 coeffB);
extern int func_02005C8C(void);
extern void func_02194704(struct TalkMsgWinSys *talkSys);
extern TalkMsgWinSys *func_02194670(const TalkMsgWinParam *param);
extern void func_02030EAC(void *task);
extern void func_0204047C(u32 frame, u16 value);
extern void func_02049B40(u32 arcId, u32 fileId, u32 type, u32 offset, u32 size, u32 heapId);
extern void func_0201F5BC(u32 frame, u32 charStart, u32 palette, u32 trans, u32 heapId);
extern void func_02195588(struct TalkMsgWinSys *talkSys);
extern void func_0201F7A8(struct BmpWin *bmpWin, u32 kind);
extern u8 func_0201F548(int windowType);
extern signed char func_02013080(u32 index);
extern signed char func_02012FFC(void);
extern void func_0201CE8C(struct PrintStream *stream, s32 wait);
extern void func_0201CEB8(struct PrintStream *stream);

extern const FieldMsgCursorOffsets d_021D3E60;
extern const FieldMsgCursorOffsets d_021D3E58;
extern const FieldBgTemplate d_021D3E98;
extern const FieldBgTemplate d_021D3E78;
extern const FieldBgTemplate d_021D3ED8;
extern const FieldBgTemplate d_021D3EF8;
extern const FieldBgTemplate d_021D3EB8;
extern const FieldBgTemplate d_021D3F18;

extern u32 func_02082BCC(void *dst, int value, u32 size);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void *func_02030734(u16 heapId, u32 size, u32 clear, const void *file, u32 line);
extern u32 func_020307B0(void *ptr);
extern struct GfFont *func_0201D7EC(int arcId, int fileId, int mode, int fixed, u32 heapId);
extern struct PrintQue *func_0201C440(u32 heapId);
extern struct Tcbl *func_0203101C(u16 heapId, u16 tag, u32 count, u32 workSize);
extern void func_021931F4(FieldMsgKeyWait *keyWait);
extern void *func_0204A1BC(int arcId, int fileId, int compressed, int heapId);
extern s32 func_02062A4C(void *file, NNSG2dCharacterData **out);
extern void func_02192BD0(FieldMsgBg *msgBg, int loadTalkSys);
extern void func_02192CF0(FieldMsgBg *msgBg, int loadTalkSys);
extern void *func_020056A0(void (*fn)(void *, void *), void *arg, u32 pri);
extern void func_02192EB8(void *task, void *msgBg);
extern void func_02192FA4(int bgFrame, int heapId);
extern void func_02192FEC(int bgFrame, int heapId, int step);
extern void func_02194798(struct TalkMsgWinSys *talkSys);
extern void func_02031140(struct Tcbl *tcbl);
extern void func_02040DA8(u32 frame, u32 visible, u32 mode);
extern void func_020403F4(u32 frame);
extern void func_02045808(struct Strbuf *str);
extern void func_0201C4C0(struct PrintQue *printQue);
extern u32 func_0201D83C(struct GfFont *font);
extern void func_02192E0C(FieldMsgBg *msgBg);
extern u32 func_0201C4E4(struct PrintQue *printQue);
extern struct Bmp *func_02045770(struct BmpWin *bmpWin);
extern u32 func_0201C6C4(struct PrintQue *printQue, struct Bmp *bmp);
extern void func_02045334(struct BmpWin *bmpWin);
extern void func_020310C4(struct Tcbl *tcbl);
extern void func_0219470C(struct TalkMsgWinSys *talkSys);
extern void func_02194760(struct TalkMsgWinSys *talkSys);
extern void func_02194764(struct TalkMsgWinSys *talkSys);
extern void func_0201C6EC(struct PrintQue *printQue);
extern u32 func_0201C6B4(const struct PrintQue *printQue);
extern struct MsgData *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct MsgData *msgData);
extern void func_02193208(FieldMsgKeyWait *keyWait, u8 autoMode);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgData *msgData, u32 msgId, struct Strbuf *dest);
extern void func_0201C6FC(struct PrintQue *printQue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, struct GfFont *font);
extern void func_0201C724(struct PrintQue *printQue, struct Bmp *bmp, u32 x, u32 y, struct Strbuf *str, struct GfFont *font, u16 color);
extern u32 func_020409B4(u32 frame);
extern void func_02043B5C(struct Bmp *bmp, u8 color);
extern u8 func_02045730(struct BmpWin *bmpWin);
extern void func_02043AF4(struct Bmp *bmp, u32 x, u32 y, u32 width, u32 height, u32 color);
extern void func_02192F74(FieldMsgBg *msgBg);
extern struct BmpWin *func_021930C0(int frame, int heapId, int x, int y, u16 width, u16 height, u16 palette);
extern void func_02193144(u32 heapId);
extern void func_02193044(u32 enable);
extern void func_02193170(u32 heapId);
extern int func_02193130(struct BmpWin *bmpWin);
extern struct BmpWin *func_02192B20(u8 x, u8 y, u8 width, u8 height, u32 heapId);
extern void func_02192BC0(struct BmpWin *bmpWin);
extern struct BmpMenuList *func_0201FF30(BmpMenuListHeader *header, u16 listPos, u16 cursorPos, u32 heapId);
extern void func_02020CF8(struct BmpMenuList *menuList, int heapId);
extern void func_02020D10(struct BmpMenuList *menuList, u32 cancelMode);
extern u32 func_0201F868(struct BmpMenuWork *items);
extern void func_0202020C(struct BmpMenuList *menuList, u16 *listPos, u16 *cursorPos);
extern s32 func_020200CC(struct BmpMenuList *menuList);
extern void func_02020234(struct BmpMenuList *menuList);
extern struct BmpMenuWork *func_0201F81C(int count, u16 heapId);
extern void func_0201F878(struct BmpMenuWork *items, struct MsgData *msgData, u32 msgId, u32 param, u32 heapId);
extern u32 func_0201F898(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u32 heapId);
extern void func_0201F8F4(struct BmpMenuWork *items);
extern u32 func_0201D304(struct Strbuf *str, struct GfFont *font, u32 margin);
extern u32 func_0201F91C(struct BmpMenuWork *items);
extern u32 func_0201F73C(struct BmpWin *bmpWin, u32 trans, u32 charStart, u32 palette);
extern struct PrintStream *func_0201CD10(struct BmpWin *bmpWin, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, s32 wait,
                                         struct Tcbl *tcbl, u32 tcblPri, u32 heapId, u16 clearColor, int (*callback)(int));
extern void func_02193200(FieldMsgKeyWait *keyWait);
extern void func_020061E4(u32 se);
extern int func_02006238(void);
extern void func_0201CE48(struct PrintStream *stream);
extern u32 func_0201CE30(struct PrintStream *stream);
extern u32 func_0201CE34(struct PrintStream *stream);
extern void func_0201CE38(struct PrintStream *stream);
extern int func_02193228(FieldMsgKeyWait *keyWait);
extern int func_02193260(FieldMsgKeyWait *keyWait, u32 streamParam);
extern u8 func_0219320C(FieldMsgKeyWait *keyWait);
extern void func_021932A0(struct PrintStream *stream, int fast);
extern u32 func_02193210(FieldMsgKeyWait *keyWait);
extern void func_021928C0(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color);
extern void func_02194848(struct TalkMsgWinSys *talkSys, int index, VecFx32 *pos, struct Strbuf *str, u32 color, u32 winType, u32 tailType, u32 wait);
extern void func_02194888(struct TalkMsgWinSys *talkSys, int index, VecFx32 *pos, struct Strbuf *str, u32 color, u32 winType, u32 tailType, u32 wait);
extern void func_021948CC(struct TalkMsgWinSys *talkSys, int index, VecFx32 *pos, struct Strbuf *str, u8 color, u32 winType, u32 wait);
extern void func_02194940(struct TalkMsgWinSys *talkSys, int index);
extern u32 func_02194950(struct TalkMsgWinSys *talkSys, u32 index);
extern u32 func_02194960(struct TalkMsgWinSys *talkSys, u32 index);
extern void func_0219492C(struct TalkMsgWinSys *talkSys, int index);
extern struct BmpWin *func_02194990(struct TalkMsgWinSys *talkSys, u32 index);
extern void func_0219499C(struct TalkMsgWinSys *talkSys, int index, struct Strbuf *str, u32 wait);
extern int func_02194974(struct TalkMsgWinSys *talkSys, int index);
extern struct PrintStream *func_02194984(struct TalkMsgWinSys *talkSys, u32 index);
extern void func_02040618(u32 frame, u32 op, u32 value);
extern struct BmpWin *func_02194A00(struct TalkMsgWinSys *talkSys, u8 x, u8 y, u8 width, u8 height, u32 winType);
extern u32 func_02194A48(struct TalkMsgWinSys *talkSys, struct BmpWin *bmpWin);
extern int func_02194A34(struct TalkMsgWinSys *talkSys, struct BmpWin *bmpWin);
extern void func_021947E8(struct TalkMsgWinSys *talkSys, int index, struct Strbuf *str, u8 x, u8 y, u8 width, u8 height,
                          u32 color, u32 bgColor, u32 wait, u8 frameType, u8 tailDir);
extern u32 func_0201D42C(struct Strbuf *str, struct GfFont *font);
extern int func_0219319C(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin);
extern u16 func_020458F8(struct Strbuf *str);
extern void func_02045838(struct Strbuf *dst, struct Strbuf *src);
extern FieldSubMsgWin *func_021931C4(FieldMsgBg *msgBg, u32 id);
extern struct BmpWin *func_020450F0(u32 frame, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 dir);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 colorMode, u32 heapId);
extern void func_02045374(struct BmpWin *bmpWin);
extern u8 func_02045758(struct BmpWin *bmpWin);
extern u8 func_02045760(struct BmpWin *bmpWin);
extern u8 func_02045738(struct BmpWin *bmpWin);
extern u8 func_02045740(struct BmpWin *bmpWin);
extern void func_020456F8(struct BmpWin *bmpWin);
extern void func_02041300(u32 frame, u16 tile, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern u32 func_020452E8(struct BmpWin *bmpWin);
extern void func_020437AC(struct Bmp *bmp);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void func_02049624(u32 arcId, u32 fileId, u32 frame, u32 offset, u32 size, u32 compressed, u32 heapId);
extern void func_02049B90(u32 arcId, u32 fileId, u32 type, u32 offset, u32 size, u32 transSize, u32 heapId);
extern u32 func_0201D37C(struct Strbuf *src, struct Strbuf *dst, u32 line);
extern void func_0201C7A4(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font);
extern u16 func_020437DC(const struct Bmp *bmp);
extern u16 func_020437E4(const struct Bmp *bmp);
extern void func_020439A0(struct Bmp *src, struct Bmp *dst, u32 srcX, u32 srcY, int dstX, int dstY, u32 width, u32 height, u16 colorKey);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082EA4(void *src, void *dst, u32 size);
extern u32 func_0201DC80(struct GfFont *font);
extern void func_021928F8(FieldMsgCursor *cursor, struct Bmp *bmp, struct Bmp *backBmp);
extern struct Strbuf *func_02045874(struct Strbuf *src, u32 heapId);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 colorMode, u16 heapId);

FieldMsgBg *func_021901EC(u16 heapId, struct G3dCamera *g3dCamera);
void func_02190270(FieldMsgBg *msgBg);
void func_0219027C(FieldMsgBg *msgBg);
void func_021902A4(u32 bgFrame, u32 heapId);
void func_021902AC(FieldMsgBg *msgBg, int step);
void func_021902BC(FieldMsgBg *msgBg);
void func_02190344(FieldMsgBg *msgBg);
int func_02190378(FieldMsgBg *msgBg);
void func_02190398(FieldMsgBg *msgBg);
int func_021903CC(FieldMsgBg *msgBg);
void func_021903E0(FieldMsgBg *msgBg);
void func_0219047C(FieldMsgBg *msgBg);
void func_02190490(FieldMsgBg *msgBg);
int func_0219049C(FieldMsgBg *msgBg);
struct PrintQue *func_021904A8(FieldMsgBg *msgBg);
struct GfFont *func_021904AC(FieldMsgBg *msgBg);
struct MsgData *func_021904B0(FieldMsgBg *msgBg, u32 fileId);
u32 func_021904C8(struct MsgData *msgData);
void func_021904D0(FieldMsgBg *msgBg);
void func_021904DC(FieldMsgBg *msgBg, u8 autoMode);
FieldMsgPrint *func_021904EC(FieldMsgBg *msgBg, struct MsgData *msgData, struct BmpWin *bmpWin);
void func_02190538(FieldMsgPrint *msgPrint);
void func_02190550(FieldMsgPrint *msgPrint, int x, int y, u32 msgId);
void func_02190590(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str);
void func_021905C8(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font);
void func_02190604(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color);
u32 func_0219061C(FieldMsgPrint *msgPrint);
int func_02190620(FieldMsgPrint *msgPrint);
void func_0219063C(FieldMsgPrint *msgPrint, int x, int y, int width, int height);
struct PrintQue *func_02190678(FieldMsgPrint *msgPrint);
PrintUtil *func_0219067C(FieldMsgPrint *msgPrint);
FieldMsgWin *func_02190680(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height, u16 palette);
FieldMsgWin *func_02190708(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
int func_02190728(FieldMsgWin *msgWin);
int func_02190740(FieldMsgWin *msgWin, int x, int y, u32 msgId);
void func_02190758(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
void func_02190764(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font);
int func_0219077C(FieldMsgWin *msgWin);
void func_02190788(FieldMsgWin *msgWin);
void func_02190794(FieldMsgWin *msgWin, int x, int y, int width, int height);
void func_021907A8(FieldMsgBg *msgBg, struct MsgData *msgData);
struct BmpWin *func_021907C0(FieldMsgWin *msgWin);
FieldMsgWin *func_021907C4(FieldMsgBg *msgBg, struct MsgData *msgData, u32 x, u32 y, u16 width, u16 height);
int func_0219082C(FieldMsgWin *msgWin);
void func_02190844(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
void func_02190854(FieldMsgWin *msgWin);
FieldMenuFunc *func_02190860(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u16 palette, u32 moveCallback, u32 lineCallback, u32 work);
FieldMenuFunc *func_02190938(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u32 moveCallback, u32 lineCallback, u32 work);
FieldMenuFunc *func_02190960(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos);
u32 func_0219097C(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items);
FieldMenuFunc *func_02190988(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u32 moveCallback, u32 work,
                             u16 listPos, u16 cursorPos, u32 cancelable);
int func_021909BC(FieldMenuFunc *menu);
int func_021909E4(FieldMenuFunc *menu);
void func_02190A14(FieldMenuFunc *menu);
struct BmpMenuWork *func_02190A20(int count, u16 heapId);
struct BmpMenuWork *func_02190A28(const FieldMenuItemData *itemData, int count, struct MsgData *msgData, u16 heapId);
int func_02190A64(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u32 heapId);
void func_02190A6C(struct BmpMenuWork *items);
u32 func_02190A74(FieldMsgBg *msgBg, BmpMenuWork *items, u32 *outIndex, u32 margin);
unsigned func_02190AC4(struct BmpMenuWork *items);
u32 func_02190ACC(FieldMsgBg *msgBg, BmpMenuWork *items, u32 fontId, u32 margin);
unsigned func_02190AEC(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls);
FieldMenuHeader *func_02190B08(FieldMenuHeader *header, u16 itemCount, u16 x, u16 y, u16 width, u16 height);
int func_02190B1C(FieldMenuFunc *menu);
void func_02190B2C(BmpMenuListHeader *listHeader, const FieldMenuHeader *header);
FieldMenuFunc *func_02190BE4(FieldMsgBg *msgBg, u32 cursorPos);
int func_02190C78(FieldMenuFunc *menu);
FieldMsgStream *func_02190C94(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait, u16 clearColor);
int func_02190D08(int code);
FieldMsgStream *func_02190D2C(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait);
int func_02190D48(FieldMsgStream *stream);
int func_02190D5C(FieldMsgStream *stream);
FieldSysWin *func_02190DCC(FieldMsgBg *msgBg, struct MsgData *msgData, u32 x, u16 y, u16 width, u16 height);
int func_02190E40(FieldSysWin *sysWin);
void func_02190E74(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
void func_02190EB8(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
u32 func_02190EF0(FieldSysWin *sysWin);
FieldSysWin *func_02190F64(FieldMsgBg *msgBg, struct MsgData *msgData);
void func_02190F7C(FieldSysWin *sysWin);
struct BmpWin *func_02190F9C(FieldSysWin *sysWin);
FieldSysWin *func_02190FA0(FieldMsgBg *msgBg, struct MsgData *msgData, u32 y);
int func_02191008(FieldSysWin *sysWin);
void func_0219103C(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
void func_02191084(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
u32 func_021910C0(FieldSysWin *sysWin);
void func_02191134(FieldSysWin *sysWin);
void func_02191164(FieldSysWin *sysWin);
void func_02191184(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str);
struct BmpWin *func_021911B4(FieldSysWin *sysWin);
void func_021911B8(FieldMsgBg *msgBg, FieldTalkWin *talkWin, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
FieldTalkWin *func_0219129C(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType);
int func_021912D8(FieldTalkWin *talkWin);
int func_021912F8(FieldTalkWin *talkWin);
int func_0219131C(FieldTalkWin *talkWin);
u32 func_02191348(FieldTalkWin *talkWin, struct Strbuf *str);
u32 func_02191388(FieldTalkWin *talkWin);
void func_021914CC(FieldTalkWin *talkWin);
void func_02191504(FieldMsgBg *msgBg, FieldPlainWin *plainWin, u32 x, u32 y, u16 width, u16 height, u32 winType);
FieldPlainWin *func_02191558(FieldMsgBg *msgBg, struct MsgData *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height);
int func_021915B4(FieldPlainWin *plainWin);
void func_021915EC(FieldPlainWin *plainWin);
void func_0219160C(FieldPlainWin *plainWin);
void func_0219161C(FieldPlainWin *plainWin, int x, int y, u32 msgId);
void func_02191648(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str);
void func_02191674(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str, u16 color);
void func_021916A8(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str);
u32 func_021916E0(FieldPlainWin *plainWin);
void func_02191794(FieldPlainWin *plainWin);
int func_021917C0(FieldPlainWin *plainWin);
void func_021917C4(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin, struct Strbuf *str, u32 talkIndex, u8 x, u8 y, u8 width, u8 height, u32 id);
void func_02191830(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height);
void func_02191870(FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgId, u32 id, u8 x, u8 y, u8 width, u8 height);
void func_021918DC(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height);
int func_0219194C(FieldSubMsgWin *subMsgWin);
void func_0219196C(FieldMsgBg *msgBg, u32 id);
void func_02191978(FieldMsgBg *msgBg);
int func_021919AC(FieldMsgBg *msgBg);
int func_021919C8(FieldSubMsgWin *subMsgWin);
void func_02191A04(FieldMsgBg *msgBg, int winType);
FieldBgWin *func_02191A10(FieldMsgBg *msgBg, u32 winType, struct GfFont *font);
void func_02191B14(FieldBgWin *bgWin);
u32 func_02191BE8(FieldBgWin *bgWin, struct Strbuf *str);
void func_02191D88(u32 frame, u32 palSlot, u32 winType, u32 heapId);
void func_02191DC8(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette);
void func_02191FA0(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette);
int func_02192138(struct Strbuf *str, struct Strbuf *lineStr, u32 line);
int func_0219214C(struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, struct Strbuf *lineStr, u32 *line, u8 color);
int func_021921C8(struct Bmp *dst, struct Bmp *prevBmp, struct Bmp *nextBmp, int offset, u16 color);
void func_02192244(u32 bgFrame, u32 palSlot, u32 heapId);
void func_02192264(struct Bmp *bmp, u32 frameType, u32 heapId, u32 tileIndex);
void func_021922A4(struct Bmp *bmp, u32 frameType, u32 heapId);
void func_021924F0(u16 x, u16 y, struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, u16 heapId);
FieldSpWin *func_02192570(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height);
void func_02192628(FieldSpWin *spWin);
void func_0219269C(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str);
int func_021926D8(FieldSpWin *spWin);
u32 func_0219270C(FieldMsgBg *msgBg, struct Strbuf *str, int margin);
u32 func_0219272C(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin);
FieldMsgCursor *func_02192788(FieldMsgBg *msgBg);
void func_021927B0(FieldMsgCursor *cursor);
void func_021927C0(FieldMsgCursor *cursor, FieldMsgBg *msgBg);
void func_021927E8(FieldMsgCursor *cursor);
u8 func_021927F8(FieldMsgCursor *cursor);
void func_021927FC(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color);

extern const char d_021DDA50[];
extern FieldMenuHeader d_021D3F38;
extern FieldYesNoItems d_021D3E68;
extern const FieldMsgCursorOffsets d_021D3E50;

FieldMsgBg *func_021901EC(u16 heapId, struct G3dCamera *g3dCamera)
{
    FieldMsgBg *msgBg = func_02030734(heapId, 0x17c, 1, d_021DDA50, 0x1a4);

    msgBg->heapId = heapId;
    msgBg->bgFrame = 0xff;
    msgBg->bgFrameSys = 0xff;
    msgBg->g3dCamera = g3dCamera;
    msgBg->font = func_0201D7EC(0x17, 0, 0, 0, msgBg->heapId);
    msgBg->printQue = func_0201C440(msgBg->heapId);
    msgBg->tcbl = func_0203101C(msgBg->heapId, msgBg->heapId, 1, 4);
    func_021931F4(&msgBg->keyWait);
    msgBg->cursorCharFile = func_0204A1BC(5, 0xc, 0, heapId);
    func_02062A4C(msgBg->cursorCharFile, &msgBg->cursorCharData);
    return msgBg;
}

void func_02190270(FieldMsgBg *msgBg)
{
    func_02192BD0(msgBg, 1);
}

void func_0219027C(FieldMsgBg *msgBg)
{
    func_02192CF0(msgBg, 0);
    if (msgBg->vblankTask == 0)
        msgBg->vblankTask = func_020056A0(func_02192EB8, msgBg, 0);
}

void func_021902A4(u32 bgFrame, u32 heapId)
{
    func_02192FA4(bgFrame, heapId);
}

/* Called from func_021BEF8C. */
void func_021902AC(FieldMsgBg *msgBg, int step)
{
    func_02192FEC(msgBg->bgFrame, msgBg->heapId, step);
}

void func_021902BC(FieldMsgBg *msgBg)
{
    int i;
    FieldMsgPrint *msgPrint;

    i = 0;
    msgPrint = msgBg->msgPrint;
    if (msgBg->cursorCharFile != 0) {
        func_020307B0(msgBg->cursorCharFile);
    }
    if (msgBg->talkSys != 0) {
        func_02194798(msgBg->talkSys);
    }
    if (msgBg->tcbl != 0) {
        func_02031140(msgBg->tcbl);
    }
    if (msgBg->bgFrame != 0xff) {
        func_02040DA8(msgBg->bgFrame, 1, 0);
        func_020403F4((u8)msgBg->bgFrame);
    }
    if (msgBg->bgFrameSys != 0xff) {
        func_020403F4((u8)msgBg->bgFrameSys);
    }
    do {
        if (msgPrint->strBuf != 0) {
            func_02045808(msgPrint->strBuf);
        }
        i++;
        msgPrint++;
    } while (i < 4);
    if (msgBg->printQue != 0) {
        func_0201C4C0(msgBg->printQue);
    }
    if (msgBg->font != 0) {
        func_0201D83C(msgBg->font);
    }
    func_020307B0(msgBg);
}

void func_02190344(FieldMsgBg *msgBg)
{
    if (msgBg->talkSys != 0) {
        func_02194798(msgBg->talkSys);
        msgBg->talkSys = 0;
    }
    if (msgBg->bgFrame != 0xff) {
        func_02040DA8(msgBg->bgFrame, 1, 0);
        func_020403F4((u8)msgBg->bgFrame);
        msgBg->bgFrame = 0xff;
    }
}

int func_02190378(FieldMsgBg *msgBg)
{
    if (msgBg->bgFrameSys != 0xff) {
        func_020403F4((u8)msgBg->bgFrameSys);
        msgBg->bgFrameSys = 0xff;
        return 1;
    }
    return 0;
}

void func_02190398(FieldMsgBg *msgBg)
{
    if (msgBg->talkSys != 0) {
        func_02194798(msgBg->talkSys);
    }
    func_02192E0C(msgBg);
    if (msgBg->vblankTask == 0) {
        msgBg->vblankTask = func_020056A0(func_02192EB8, msgBg, 0);
    }
}

/* Called from func_021BEF8C. */
int func_021903CC(FieldMsgBg *msgBg)
{
    if (msgBg->vblankTask == 0)
        return 1;
    return 0;
}

void func_021903E0(FieldMsgBg *msgBg)
{
    int i;
    FieldSubMsgWin **subMsgWin;
    FieldMsgPrint *msgPrint;
    int j;
    struct PrintQue *printQue;

    func_0201C4E4(msgBg->printQue);
    i = 0;
    subMsgWin = msgBg->subMsgWin;
    for (; i < 8; i++, subMsgWin++) {
        if (*subMsgWin != 0) {
            func_021919C8(*subMsgWin);
        }
    }
    msgPrint = msgBg->msgPrint;
    for (j = 0; j < 4; j++, msgPrint++) {
        printQue = msgPrint->printQue;
        if (printQue != 0) {
            if (msgPrint->printUtil.transReq != 0) {
                if (func_0201C6C4(printQue, func_02045770(msgPrint->printUtil.bmpWin)) == 0) {
                    func_02045334(msgPrint->printUtil.bmpWin);
                    msgPrint->printUtil.transReq = 0;
                }
            }
            msgPrint->transDone = (msgPrint->printUtil.transReq == 0) ? 1 : 0;
        }
    }
    func_020310C4(msgBg->tcbl);
    if (msgBg->talkSys != 0) {
        func_0219470C(msgBg->talkSys);
        func_02194760(msgBg->talkSys);
    }
}

void func_0219047C(FieldMsgBg *msgBg)
{
    struct TalkMsgWinSys *talkSys = msgBg->talkSys;
    if (talkSys != 0)
        func_02194764(talkSys);
}

void func_02190490(FieldMsgBg *msgBg)
{
    func_0201C6EC(msgBg->printQue);
}

int func_0219049C(FieldMsgBg *msgBg)
{
    return func_0201C6B4(msgBg->printQue);
}

struct PrintQue *func_021904A8(FieldMsgBg *msgBg)
{
    return msgBg->printQue;
}

struct GfFont *func_021904AC(FieldMsgBg *msgBg)
{
    return msgBg->font;
}

struct MsgData *func_021904B0(FieldMsgBg *msgBg, u32 fileId)
{
    return func_02045B38(0, 2, (u16)fileId, msgBg->heapId);
}

u32 func_021904C8(struct MsgData *msgData)
{
    return func_02045C04(msgData);
}

void func_021904D0(FieldMsgBg *msgBg)
{
    msgBg->sysFrameReq = 1;
}

/*
 * The second parameter is what puts the offset temp in r2 instead of r1.
 */
void func_021904DC(FieldMsgBg *msgBg, u8 autoMode)
{
    func_02193208(&msgBg->keyWait, autoMode);
}

FieldMsgPrint *func_021904EC(FieldMsgBg *msgBg, struct MsgData *msgData, struct BmpWin *bmpWin)
{
    FieldMsgPrint *msgPrint;
    int i;

    i = 0;
    msgPrint = msgBg->msgPrint;
    for (; i < 4; i++, msgPrint++) {
        if (msgPrint->printQue == 0) {
            msgPrint->msgBg = msgBg;
            msgPrint->bmpWin = bmpWin;
            msgPrint->transDone = 1;
            msgPrint->font = msgBg->font;
            msgPrint->printQue = msgBg->printQue;
            msgPrint->strBuf = func_020457B0(0xa0, msgBg->heapId);
            msgPrint->msgData = msgData;
            msgPrint->printUtil.bmpWin = bmpWin;
            msgPrint->printUtil.transReq = 0;
            return msgPrint;
        }
    }
    return 0;
}

void func_02190538(FieldMsgPrint *msgPrint)
{
    msgPrint->font = 0;
    msgPrint->printQue = 0;
    func_02045808(msgPrint->strBuf);
    msgPrint->strBuf = 0;
    msgPrint->msgData = 0;
}

void func_02190550(FieldMsgPrint *msgPrint, int x, int y, u32 msgId)
{
    struct PrintQue *printQue;

    func_02045CAC(msgPrint->msgData, msgId, msgPrint->strBuf);
    printQue = msgPrint->printQue;
    func_0201C6FC(printQue, func_02045770(msgPrint->printUtil.bmpWin), (s16)x, (s16)y, msgPrint->strBuf, msgPrint->font);
    msgPrint->printUtil.transReq = 1;
}

void func_02190590(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str)
{
    struct PrintQue *printQue;

    printQue = msgPrint->printQue;
    func_0201C6FC(printQue, func_02045770(msgPrint->printUtil.bmpWin), (s16)x, (s16)y, str, msgPrint->font);
    msgPrint->printUtil.transReq = 1;
}

void func_021905C8(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font)
{
    struct PrintQue *printQue;

    printQue = msgPrint->printQue;
    func_0201C724(printQue, func_02045770(msgPrint->printUtil.bmpWin), (s16)x, (s16)y, str, font, color);
    msgPrint->printUtil.transReq = 1;
}

void func_02190604(FieldMsgPrint *msgPrint, int x, int y, struct Strbuf *str, u16 color)
{
    func_021905C8(msgPrint, x, y, str, color, msgPrint->font);
}

/* Read through func_0219077C. */
u32 func_0219061C(FieldMsgPrint *msgPrint)
{
    return msgPrint->transDone;
}

int func_02190620(FieldMsgPrint *msgPrint)
{
    func_02043B5C(func_02045770(msgPrint->bmpWin), 255);
    return func_020409B4(func_02045730(msgPrint->bmpWin));
}

void func_0219063C(FieldMsgPrint *msgPrint, int x, int y, int width, int height)
{
    func_02043AF4(func_02045770(msgPrint->bmpWin), (s16)x, (s16)y, (u16)width, (u16)height, 0xFF);
    func_020409B4(func_02045730(msgPrint->bmpWin));
}

struct PrintQue *func_02190678(FieldMsgPrint *msgPrint)
{
    return msgPrint->printQue;
}

PrintUtil *func_0219067C(FieldMsgPrint *msgPrint)
{
    return &msgPrint->printUtil;
}

FieldMsgWin *func_02190680(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height, u16 palette)
{
    u8 frame;
    FieldMsgWin *msgWin;

    frame = msgBg->bgFrame;
    func_02192F74(msgBg);
    if (palette == 0xe) {
        frame = msgBg->bgFrameSys;
    }
    msgWin = func_02030734(msgBg->heapId, 0xC, 1, d_021DDA50, 0x483);
    msgWin->msgBg = msgBg;
    msgWin->bmpWin = func_021930C0(frame, msgBg->heapId, x, y, width, height, palette);
    msgWin->msgPrint = func_021904EC(msgBg, msgData, msgWin->bmpWin);
    if (palette == 0xe) {
        func_02193144(msgBg->heapId);
        func_02193044(1);
    } else {
        func_02193170(msgBg->heapId);
    }
    return msgWin;
}

FieldMsgWin *func_02190708(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height)
{
    msgBg->windowKind = 0xE;
    return func_02190680(msgBg, msgData, x, y, width, height, msgBg->windowKind);
}

int func_02190728(FieldMsgWin *msgWin)
{
    func_02193130(msgWin->bmpWin);
    func_02190538(msgWin->msgPrint);
    return func_020307B0(msgWin);
}

int func_02190740(FieldMsgWin *msgWin, int x, int y, u32 msgId)
{
    func_02190550(msgWin->msgPrint, x, y, msgId);
    return func_020409B4(func_02045730(msgWin->bmpWin));
}

void func_02190758(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str)
{
    func_02190590(msgWin->msgPrint, x, y, str);
}

void func_02190764(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str, u16 color, struct GfFont *font)
{
    func_021905C8(msgWin->msgPrint, x, y, str, color, font);
}

int func_0219077C(FieldMsgWin *msgWin)
{
    return func_0219061C(msgWin->msgPrint);
}

void func_02190788(FieldMsgWin *msgWin)
{
    func_02190620(msgWin->msgPrint);
}

void func_02190794(FieldMsgWin *msgWin, int x, int y, int width, int height)
{
    func_0219063C(msgWin->msgPrint, x, y, width, height);
}

void func_021907A8(FieldMsgBg *msgBg, struct MsgData *msgData)
{
    func_02190708(msgBg, msgData, 1, 0x13, 0x1E, 4);
}

struct BmpWin *func_021907C0(FieldMsgWin *msgWin)
{
    return msgWin->bmpWin;
}

FieldMsgWin *func_021907C4(FieldMsgBg *msgBg, struct MsgData *msgData, u32 x, u32 y, u16 width, u16 height)
{
    FieldMsgWin *msgWin;

    msgBg->windowKind = 0xe;
    func_02192F74(msgBg);
    msgWin = func_02030734(msgBg->heapId, 0xC, 1, d_021DDA50, 0x560);
    msgWin->msgBg = msgBg;
    msgWin->bmpWin = func_02192B20(x, y, width, height, msgBg->heapId);
    msgWin->msgPrint = func_021904EC(msgBg, msgData, msgWin->bmpWin);
    func_02193044(1);
    return msgWin;
}

int func_0219082C(FieldMsgWin *msgWin)
{
    func_02192BC0(msgWin->bmpWin);
    func_02190538(msgWin->msgPrint);
    return func_020307B0(msgWin);
}

void func_02190844(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str)
{
    func_02190590(msgWin->msgPrint, (u16)(x + 8), y, str);
}

void func_02190854(FieldMsgWin *msgWin)
{
    func_02190620(msgWin->msgPrint);
}

/*
 * Builds the arm9 list header from the field header (func_02190B2C plus the
 * caller's words) and creates the list with func_0201FF30.
 * `const` on header is what interleaves its field loads with the
 * menu->items store.
 */
FieldMenuFunc *func_02190860(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u16 palette, u32 moveCallback, u32 lineCallback, u32 work)
{
    BmpMenuListHeader listHeader;
    u8 frame;
    FieldMenuFunc *menu;

    frame = msgBg->bgFrame;
    func_02192F74(msgBg);
    if (palette == 0xe) {
        frame = msgBg->bgFrameSys;
    }
    menu = func_02030734(msgBg->heapId, 0x14, 1, d_021DDA50, 0x606);
    func_02190B2C(&listHeader, header);
    menu->msgBg = msgBg;
    menu->items = items;
    menu->bmpWin = func_021930C0(frame, msgBg->heapId, header->posX, header->posY, header->width, header->height, palette);
    menu->msgPrint = func_021904EC(msgBg, 0, menu->bmpWin);
    listHeader.reserved24 = 0;
    listHeader.printUtil = func_0219067C(menu->msgPrint);
    listHeader.printQue = func_02190678(menu->msgPrint);
    listHeader.font = msgBg->font;
    listHeader.bmpWin = menu->bmpWin;
    listHeader.items = items;
    listHeader.lineCallback = lineCallback;
    listHeader.moveCallback = moveCallback;
    listHeader.work = work;
    menu->menuList = func_0201FF30(&listHeader, listPos, cursorPos, msgBg->heapId);
    func_02020CF8(menu->menuList, msgBg->heapId);
    if (palette == 0xe) {
        func_02193144(msgBg->heapId);
        func_02193044(1);
    } else {
        func_02193170(msgBg->heapId);
    }
    return menu;
}

FieldMenuFunc *func_02190938(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos,
                             u32 moveCallback, u32 lineCallback, u32 work)
{
    msgBg->windowKind = 0xe;
    return func_02190860(msgBg, header, items, listPos, cursorPos, msgBg->windowKind, moveCallback, lineCallback, work);
}

FieldMenuFunc *func_02190960(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u16 listPos, u16 cursorPos)
{
    return func_02190938(msgBg, header, items, listPos, cursorPos, 0, header->lineCallback, 0);
}

u32 func_0219097C(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items)
{
    return (int)func_02190960(msgBg, header, items, 0, 0);
}

FieldMenuFunc *func_02190988(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items, u32 moveCallback, u32 work,
                             u16 listPos, u16 cursorPos, u32 cancelable)
{
    FieldMenuFunc *menu = func_02190860(msgBg, header, items, listPos, cursorPos, msgBg->windowKind, moveCallback, 0, work);
    if (cancelable == 0)
        func_02020D10(menu->menuList, 1);
    return menu;
}

int func_021909BC(FieldMenuFunc *menu)
{
    func_0202020C(menu->menuList, 0, 0);
    func_0201F868(menu->items);
    func_02193130(menu->bmpWin);
    func_02190538(menu->msgPrint);
    return func_020307B0(menu);
}

int func_021909E4(FieldMenuFunc *menu)
{
    int result;

    if (func_0219049C(menu->msgBg) == 0)
        return -1;
    result = func_020200CC(menu->menuList);
    if (result == -1)
        return -1;
    if (result == -2)
        return -2;
    return result;
}

void func_02190A14(FieldMenuFunc *menu)
{
    func_02020234(menu->menuList);
}

struct BmpMenuWork *func_02190A20(int count, u16 heapId)
{
    return func_0201F81C(count, heapId);
}

struct BmpMenuWork *func_02190A28(const FieldMenuItemData *itemData, int count, struct MsgData *msgData, u16 heapId)
{
    struct BmpMenuWork *items;
    int i;

    items = func_02190A20(count, heapId);
    for (i = 0; i < count; i++)
        func_0201F878(items, msgData, itemData[i].msgId, itemData[i].param, heapId);
    return items;
}

int func_02190A64(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u32 heapId)
{
    return func_0201F898(items, str, param, heapId);
}

void func_02190A6C(struct BmpMenuWork *items)
{
    func_0201F8F4(items);
}

u32 func_02190A74(FieldMsgBg *msgBg, BmpMenuWork *items, u32 *outIndex, u32 margin)
{
    u32 marginU16;
    u32 bestIndex;
    u32 bestWidth;
    u32 i;

    bestWidth = 0;
    bestIndex = 0;
    i = 0;
    if ((u32)items->str != -1) {
        marginU16 = (u16)margin;
        do {
            u32 width;
            if (items->str == 0) {
                break;
            }
            width = func_0201D304(items->str, msgBg->font, marginU16);
            if (width > bestWidth) {
                bestWidth = width;
                bestIndex = i;
            }
            items++;
            i++;
        } while ((u32)items->str != -1);
    }
    *outIndex = bestIndex;
    return bestWidth;
}

/* Sole blocker of ov010 func_0215A864's MATCH (tail call through a pool word). */
unsigned func_02190AC4(struct BmpMenuWork *items)
{
    return func_0201F91C(items);
}

u32 func_02190ACC(FieldMsgBg *msgBg, BmpMenuWork *items, u32 fontId, u32 margin)
{
    u32 bestIndex;
    u32 width;
    u32 chars;

    width = func_02190A74(msgBg, items, &bestIndex, margin);
    width += margin + 0x10;
    chars = width >> 3;
    if (width & 7)
        chars++;
    return chars;
}

/* Sole blocker of ov010 func_0215A864's MATCH. */
unsigned func_02190AEC(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls)
{
    unsigned pixels = lines * (fontHeight + lineSpacing);
    unsigned chars = (pixels + 7) >> 3;
    if (scrolls && chars * 8 - pixels < 6) {
        chars++;
    }
    return chars;
}

FieldMenuHeader *func_02190B08(FieldMenuHeader *header, u16 itemCount, u16 x, u16 y, u16 width, u16 height)
{
    header->itemCount = itemCount;
    header->posY = y;
    header->posX = x;
    header->width = width;
    header->height = height;
    return header;
}

int func_02190B1C(FieldMenuFunc *menu)
{
    return func_0201F73C(menu->bmpWin, 0, 1, 13);
}

void func_02190B2C(BmpMenuListHeader *listHeader, const FieldMenuHeader *header)
{
    func_02082BCC(listHeader, 0, 0x34);
    listHeader->itemCount = header->itemCount;
    listHeader->maxLines = header->maxLines;
    listHeader->labelX = header->labelX;
    listHeader->dataX = header->dataX;
    listHeader->cursorX = header->cursorX;
    listHeader->lineY = header->lineY;
    listHeader->textColor = header->textColor;
    listHeader->bgColor = header->bgColor;
    listHeader->shadowColor = header->shadowColor;
    listHeader->cursorMargin = header->cursorMargin;
    listHeader->lineSpacing = header->lineSpacing;
    listHeader->pageSkip = header->pageSkip;
    listHeader->fontId = header->fontId;
    listHeader->fontHeight = header->fontHeight;
    listHeader->lineCallback = header->lineCallback;
}

FieldMenuFunc *func_02190BE4(FieldMsgBg *msgBg, u32 cursorPos)
{
    FieldMenuHeader header = d_021D3F38;
    FieldYesNoItems itemData = d_021D3E68;
    struct MsgData *msgData;
    struct BmpMenuWork *items;
    FieldMenuFunc *menu;

    msgData = func_021904B0(msgBg, 0xe9);
    items = func_02190A28(itemData.item, 2, msgData, msgBg->heapId);
    func_02045C04(msgData);
    func_02190B08(&header, 2, 0x18, 0xa, 7, 4);
    menu = func_02190860(msgBg, &header, items, 0, (u16)cursorPos, msgBg->windowKind, 0, 0, 0);
    func_02020D10(menu->menuList, 0);
    return menu;
}

int func_02190C78(FieldMenuFunc *menu)
{
    int result = func_021909E4(menu);
    if (result == -1)
        return 2;
    if (result == -2)
        return 1;
    return result;
}

FieldMsgStream *func_02190C94(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait, u16 clearColor)
{
    FieldMsgStream *stream;

    stream = func_02030734(msgBg->heapId, 0xc, 1, d_021DDA50, 0x85e);
    stream->msgBg = msgBg;
    stream->wait = wait;
    stream->stream = func_0201CD10(bmpWin, x, y, str, msgBg->font, wait, msgBg->tcbl, 0, msgBg->heapId, clearColor, func_02190D08);
    func_02193200(&stream->msgBg->keyWait);
    return stream;
}

int func_02190D08(int code)
{
    switch (code) {
    case 3:
        func_020061E4(0x56B);
        break;
    case 6:
        return func_02006238();
    }
    return 0;
}

FieldMsgStream *func_02190D2C(FieldMsgBg *msgBg, struct Strbuf *str, struct BmpWin *bmpWin, u32 x, u16 y, u32 wait)
{
    return func_02190C94(msgBg, str, bmpWin, x, y, wait, 0xF);
}

int func_02190D48(FieldMsgStream *stream)
{
    func_0201CE48(stream->stream);
    return func_020307B0(stream);
}

int func_02190D5C(FieldMsgStream *stream)
{
    int state = func_0201CE30(stream->stream);
    switch (state) {
    case 0:
        if (func_02193228(&stream->msgBg->keyWait) != 0) {
            func_021932A0(stream->stream, 1);
        } else {
            func_021932A0(stream->stream, 0);
        }
        break;
    case 1:
        if (func_02193260(&stream->msgBg->keyWait, func_0201CE34(stream->stream)) != 0) {
            if (func_0219320C(&stream->msgBg->keyWait) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38(stream->stream);
            state = 0;
            func_021932A0(stream->stream, 0);
        }
        break;
    case 2:
        break;
    }
    return state;
}

FieldSysWin *func_02190DCC(FieldMsgBg *msgBg, struct MsgData *msgData, u32 x, u16 y, u16 width, u16 height)
{
    FieldSysWin *sysWin;

    msgBg->windowKind = 0xe;
    func_02192F74(msgBg);
    sysWin = func_02030734(msgBg->heapId, 0x20, 1, d_021DDA50, 0x8FF);
    sysWin->msgBg = msgBg;
    sysWin->msgData = msgData;
    sysWin->bmpWin = func_021930C0(msgBg->bgFrameSys, msgBg->heapId, x, y, width, height, msgBg->windowKind);
    sysWin->strBuf = func_020457B0(0xA0, msgBg->heapId);
    func_021927C0(&sysWin->cursor, msgBg);
    func_02193144(msgBg->heapId);
    func_02193044(1);
    return sysWin;
}

int func_02190E40(FieldSysWin *sysWin)
{
    func_02193130(sysWin->bmpWin);
    if (sysWin->stream != 0) {
        func_02190D48(sysWin->stream);
    }
    if (sysWin->msgPrint != 0) {
        func_02190538(sysWin->msgPrint);
    }
    func_02045808(sysWin->strBuf);
    func_021927E8(&sysWin->cursor);
    return func_020307B0(sysWin);
}

void func_02190E74(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId)
{
    if (sysWin->stream != 0) {
        func_02190D48(sysWin->stream);
    }
    func_02045CAC(sysWin->msgData, msgId, sysWin->strBuf);
    sysWin->stream = func_02190D2C(sysWin->msgBg, sysWin->strBuf, sysWin->bmpWin, x, y, func_02193210(&sysWin->msgBg->keyWait));
}

void func_02190EB8(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str)
{
    if (sysWin->stream != 0)
        func_02190D48(sysWin->stream);
    sysWin->stream = func_02190D2C(sysWin->msgBg, str, sysWin->bmpWin, x, y, func_02193210(&sysWin->msgBg->keyWait));
}

u32 func_02190EF0(FieldSysWin *sysWin)
{
    u32 state = func_02190D5C(sysWin->stream);
    func_020362DC();
    func_0203630C();
    switch (state) {
    case 0:
        if (func_021927F8(&sysWin->cursor) == 1) {
            func_021927FC(&sysWin->cursor, func_02045770(sysWin->bmpWin), 15);
            func_02045334(sysWin->bmpWin);
        }
        break;
    case 1:
        if (func_0219320C(&sysWin->msgBg->keyWait) == 0) {
            func_021928C0(&sysWin->cursor, func_02045770(sysWin->bmpWin), 15);
            func_02045334(sysWin->bmpWin);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

FieldSysWin *func_02190F64(FieldMsgBg *msgBg, struct MsgData *msgData)
{
    return func_02190DCC(msgBg, msgData, 1, 0x13, 0x1E, 4);
}

void func_02190F7C(FieldSysWin *sysWin)
{
    func_02043B5C(func_02045770(sysWin->bmpWin), 0xFF);
    func_020409B4((u8)sysWin->msgBg->bgFrame);
}

/* Reached from func_021D1C8C. */
struct BmpWin *func_02190F9C(FieldSysWin *sysWin)
{
    return sysWin->bmpWin;
}

FieldSysWin *func_02190FA0(FieldMsgBg *msgBg, struct MsgData *msgData, u32 y)
{
    FieldSysWin *sysWin;

    msgBg->windowKind = 0xe;
    func_02192F74(msgBg);
    sysWin = func_02030734(msgBg->heapId, 0x20, 1, d_021DDA50, 0x9F4);
    sysWin->msgBg = msgBg;
    sysWin->msgData = msgData;
    sysWin->bmpWin = func_02192B20(1, y, 0x1E, 4, msgBg->heapId);
    sysWin->strBuf = func_020457B0(0xA0, msgBg->heapId);
    func_021927C0(&sysWin->cursor, msgBg);
    func_02193144(msgBg->heapId);
    func_02193044(1);
    return sysWin;
}

int func_02191008(FieldSysWin *sysWin)
{
    func_02192BC0(sysWin->bmpWin);
    if (sysWin->stream != 0) {
        func_02190D48(sysWin->stream);
    }
    if (sysWin->msgPrint != 0) {
        func_02190538(sysWin->msgPrint);
    }
    func_02045808(sysWin->strBuf);
    func_021927E8(&sysWin->cursor);
    return func_020307B0(sysWin);
}

void func_0219103C(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId)
{
    if (sysWin->stream != 0) {
        func_02190D48(sysWin->stream);
    }
    func_02045CAC(sysWin->msgData, msgId, sysWin->strBuf);
    sysWin->stream = func_02190D2C(sysWin->msgBg, sysWin->strBuf, sysWin->bmpWin, (u16)(x + 8), y, func_02193210(&sysWin->msgBg->keyWait));
}

void func_02191084(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str)
{
    if (sysWin->stream != 0)
        func_02190D48(sysWin->stream);
    sysWin->stream = func_02190D2C(sysWin->msgBg, str, sysWin->bmpWin, (u16)(x + 8), y, func_02193210(&sysWin->msgBg->keyWait));
}

u32 func_021910C0(FieldSysWin *sysWin)
{
    u32 state = func_02190D5C(sysWin->stream);
    func_020362DC();
    func_0203630C();
    switch (state) {
    case 0:
        if (func_021927F8(&sysWin->cursor) == 1) {
            func_021927FC(&sysWin->cursor, func_02045770(sysWin->bmpWin), 15);
            func_02045334(sysWin->bmpWin);
        }
        break;
    case 1:
        if (func_0219320C(&sysWin->msgBg->keyWait) == 0) {
            func_021928C0(&sysWin->cursor, func_02045770(sysWin->bmpWin), 15);
            func_02045334(sysWin->bmpWin);
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

void func_02191134(FieldSysWin *sysWin)
{
    if (func_0219320C(&sysWin->msgBg->keyWait) == 0) {
        func_021928C0(&sysWin->cursor, func_02045770(sysWin->bmpWin), 0xF);
        func_02045334(sysWin->bmpWin);
    }
}

void func_02191164(FieldSysWin *sysWin)
{
    func_02043B5C(func_02045770(sysWin->bmpWin), 0xFF);
    func_020409B4((u8)sysWin->msgBg->bgFrame);
}

void func_02191184(FieldSysWin *sysWin, u32 x, int y, struct Strbuf *str)
{
    if (sysWin->msgPrint != 0)
        func_02190538(sysWin->msgPrint);
    sysWin->msgPrint = func_021904EC(sysWin->msgBg, 0, sysWin->bmpWin);
    func_02190590(sysWin->msgPrint, (u16)(x + 8), y, str);
}

struct BmpWin *func_021911B4(FieldSysWin *sysWin)
{
    return sysWin->bmpWin;
}

void func_021911B8(FieldMsgBg *msgBg, FieldTalkWin *talkWin, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    talkWin->targetPos = pos;
    talkWin->pos = *pos;
    msgBg->windowKind = 11;
    talkWin->msgBg = msgBg;
    talkWin->talkSys = msgBg->talkSys;
    talkWin->index = index;
    func_02193170(msgBg->heapId);
    func_02193044(0);
    switch (index) {
    case 0:
        func_02194848(talkWin->talkSys, 0, pos, str, 15, winType, tailType, func_02193210(&msgBg->keyWait));
        break;
    case 1:
        func_02194888(talkWin->talkSys, 1, pos, str, 15, winType, tailType, func_02193210(&msgBg->keyWait));
        break;
    default:
        func_021948CC(talkWin->talkSys, 2, pos, str, 15, winType, func_02193210(&msgBg->keyWait));
        break;
    }
    func_02193200(&msgBg->keyWait);
    func_02194940(talkWin->talkSys, talkWin->index);
    func_021927C0(&talkWin->cursor, msgBg);
    if (winType == 1) {
        talkWin->shakeOffset = 8;
        func_020061E4(0x72C);
    }
}

FieldTalkWin *func_0219129C(FieldMsgBg *msgBg, int index, VecFx32 *pos, struct Strbuf *str, u32 winType, u32 tailType)
{
    FieldTalkWin *talkWin;

    if (index < 3) {
        talkWin = &msgBg->talkWin[index];
        if (talkWin->talkSys == 0) {
            func_021911B8(msgBg, talkWin, index, pos, str, winType, tailType);
            return talkWin;
        }
    }
    return 0;
}

int func_021912D8(FieldTalkWin *talkWin)
{
    if (talkWin->strBuf != 0) {
        func_02045808(talkWin->strBuf);
    }
    func_021927E8(&talkWin->cursor);
    return func_02194950(talkWin->talkSys, talkWin->index);
}

int func_021912F8(FieldTalkWin *talkWin)
{
    if (func_02194960(talkWin->talkSys, talkWin->index) != 0) {
        func_02082BCC(talkWin, 0, 52);
        return 1;
    }
    return 0;
}

int func_0219131C(FieldTalkWin *talkWin)
{
    if (talkWin->strBuf != 0) {
        func_02045808(talkWin->strBuf);
    }
    func_0219492C(talkWin->talkSys, talkWin->index);
    func_021927E8(&talkWin->cursor);
    return func_02082BCC(talkWin, 0, 52);
}

u32 func_02191348(FieldTalkWin *talkWin, struct Strbuf *str)
{
    struct BmpWin *bmpWin = func_02194990(talkWin->talkSys, talkWin->index);
    func_02043B5C(func_02045770(bmpWin), 255);
    func_0219499C(talkWin->talkSys, talkWin->index, str, func_02193210(&talkWin->msgBg->keyWait));
    return func_020409B4(func_02045730(bmpWin));
}

u32 func_02191388(FieldTalkWin *talkWin)
{
    struct PrintStream *stream;
    u32 state;
    struct BmpWin *bmpWin;
    struct Bmp *bmp;

    if (func_02194974(talkWin->talkSys, talkWin->index) == 0) {
        return 0;
    }
    stream = func_02194984(talkWin->talkSys, talkWin->index);
    state = func_0201CE30(stream);
    func_02040618(1, 3, talkWin->shakeOffset);
    if (talkWin->shakeOffset < 0) {
        talkWin->shakeOffset += 2;
        if (talkWin->shakeOffset > 0) {
            talkWin->shakeOffset = 0;
        }
    }
    talkWin->shakeOffset = -talkWin->shakeOffset;
    switch (state) {
    case 0:
        if (func_021927F8(&talkWin->cursor) == 1) {
            bmpWin = func_02194990(talkWin->talkSys, talkWin->index);
            func_021927FC(&talkWin->cursor, func_02045770(bmpWin), 15);
            func_02045334(bmpWin);
        }
        if (func_02193228(&talkWin->msgBg->keyWait) != 0) {
            func_021932A0(stream, 1);
        } else {
            func_021932A0(stream, 0);
        }
        break;
    case 1:
        bmpWin = func_02194990(talkWin->talkSys, talkWin->index);
        bmp = func_02045770(bmpWin);
        if (func_0219320C(&talkWin->msgBg->keyWait) == 0) {
            func_021928C0(&talkWin->cursor, bmp, 15);
        }
        if (func_02193260(&talkWin->msgBg->keyWait, func_0201CE34(stream)) != 0) {
            if (func_0219320C(&talkWin->msgBg->keyWait) == 0) {
                func_020061E4(0x547);
            }
            func_0201CE38(stream);
            func_021927FC(&talkWin->cursor, bmp, 15);
            func_021932A0(stream, 0);
        }
        func_02045334(bmpWin);
        break;
    case 2:
        if (talkWin->shakeOffset != 0) {
            talkWin->shakeOffset = 0;
            func_02040618(1, 3, talkWin->shakeOffset);
        }
        return 1;
    }
    return 0;
}

void func_021914CC(FieldTalkWin *talkWin)
{
    struct BmpWin *bmpWin;

    if (func_0219320C(&talkWin->msgBg->keyWait) == 0) {
        bmpWin = func_02194990(talkWin->talkSys, talkWin->index);
        func_021928C0(&talkWin->cursor, func_02045770(bmpWin), 0xF);
        func_02045334(bmpWin);
    }
}

void func_02191504(FieldMsgBg *msgBg, FieldPlainWin *plainWin, u32 x, u32 y, u16 width, u16 height, u32 winType)
{
    msgBg->windowKind = 11;
    plainWin->talkSys = msgBg->talkSys;
    func_02193170(msgBg->heapId);
    func_02193044(0);
    plainWin->bmpWin = func_02194A00(plainWin->talkSys, x, y, width, height, winType);
    func_021927C0(&plainWin->cursor, msgBg);
}

FieldPlainWin *func_02191558(FieldMsgBg *msgBg, struct MsgData *msgData, u32 winType, u16 x, u16 y, u16 width, u16 height)
{
    FieldPlainWin *plainWin;

    plainWin = func_02030734(msgBg->heapId, 0x2C, 1, d_021DDA50, 0xCA7);
    plainWin->msgBg = msgBg;
    plainWin->msgData = msgData;
    plainWin->strBuf = func_020457B0(0xA0, msgBg->heapId);
    func_02191504(msgBg, plainWin, x, y, width, height, winType);
    if (winType == 1)
        plainWin->shakeOffset = 8;
    return plainWin;
}

int func_021915B4(FieldPlainWin *plainWin)
{
    if (plainWin->stream != 0) {
        func_02190D48(plainWin->stream);
    }
    if (plainWin->msgPrint != 0) {
        func_02190538(plainWin->msgPrint);
    }
    if (plainWin->strBuf != 0) {
        func_02045808(plainWin->strBuf);
    }
    func_02194A48(plainWin->talkSys, plainWin->bmpWin);
    func_021927E8(&plainWin->cursor);
    return func_020307B0(plainWin);
}

void func_021915EC(FieldPlainWin *plainWin)
{
    func_02043B5C(func_02045770(plainWin->bmpWin), 0xFF);
    func_020409B4((u8)plainWin->msgBg->bgFrame);
}

void func_0219160C(FieldPlainWin *plainWin)
{
    func_02194A34(plainWin->talkSys, plainWin->bmpWin);
}

void func_0219161C(FieldPlainWin *plainWin, int x, int y, u32 msgId)
{
    if (plainWin->msgPrint != 0)
        func_02190538(plainWin->msgPrint);
    plainWin->msgPrint = func_021904EC(plainWin->msgBg, plainWin->msgData, plainWin->bmpWin);
    func_02190550(plainWin->msgPrint, x, y, msgId);
}

void func_02191648(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str)
{
    if (plainWin->msgPrint != 0)
        func_02190538(plainWin->msgPrint);
    plainWin->msgPrint = func_021904EC(plainWin->msgBg, 0, plainWin->bmpWin);
    func_02190590(plainWin->msgPrint, x, y, str);
}

void func_02191674(FieldPlainWin *plainWin, int x, int y, struct Strbuf *str, u16 color)
{
    if (plainWin->msgPrint != 0)
        func_02190538(plainWin->msgPrint);
    plainWin->msgPrint = func_021904EC(plainWin->msgBg, 0, plainWin->bmpWin);
    func_02190604(plainWin->msgPrint, x, y, str, color);
}

void func_021916A8(FieldPlainWin *plainWin, u32 x, u16 y, struct Strbuf *str)
{
    if (plainWin->stream != 0)
        func_02190D48(plainWin->stream);
    plainWin->stream = func_02190D2C(plainWin->msgBg, str, plainWin->bmpWin, x, y, func_02193210(&plainWin->msgBg->keyWait));
}

u32 func_021916E0(FieldPlainWin *plainWin)
{
    u32 state;

    func_020362DC();
    func_0203630C();
    state = func_02190D5C(plainWin->stream);
    plainWin->streamState = func_0201CE30(plainWin->stream->stream);
    func_02040618(1, 3, plainWin->shakeOffset);
    if (plainWin->shakeOffset < 0) {
        plainWin->shakeOffset += 2;
        if (plainWin->shakeOffset > 0) {
            plainWin->shakeOffset = 0;
        }
    }
    plainWin->shakeOffset = -plainWin->shakeOffset;
    switch (state) {
    case 0:
        if (func_021927F8(&plainWin->cursor) == 1) {
            func_021927FC(&plainWin->cursor, func_02045770(plainWin->bmpWin), 15);
            func_02045334(plainWin->bmpWin);
        }
        break;
    case 1:
        if (func_0219320C(&plainWin->msgBg->keyWait) == 0) {
            func_021928C0(&plainWin->cursor, func_02045770(plainWin->bmpWin), 15);
            func_02045334(plainWin->bmpWin);
        }
        break;
    case 2:
        if (plainWin->shakeOffset != 0) {
            plainWin->shakeOffset = 0;
            func_02040618(1, 3, plainWin->shakeOffset);
        }
        return 1;
    }
    return 0;
}

void func_02191794(FieldPlainWin *plainWin)
{
    if (func_0219320C(&plainWin->msgBg->keyWait) == 0) {
        func_021928C0(&plainWin->cursor, func_02045770(plainWin->bmpWin), 0xF);
        func_02045334(plainWin->bmpWin);
    }
}

int func_021917C0(FieldPlainWin *plainWin)
{
    return plainWin->streamState;
}

void func_021917C4(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin, struct Strbuf *str, u32 talkIndex, u8 x, u8 y, u8 width, u8 height, u32 id)
{
    msgBg->windowKind = 11;
    subMsgWin->talkSys = msgBg->talkSys;
    subMsgWin->talkIndex = talkIndex;
    subMsgWin->id = id;
    func_02193170(msgBg->heapId);
    func_02193044(0);
    func_021947E8(subMsgWin->talkSys, subMsgWin->talkIndex, str, x, y, width, height, 0xFF, 0, func_02193210(&msgBg->keyWait), 2, 0);
    func_02194940(subMsgWin->talkSys, subMsgWin->talkIndex);
}

/*
 * The margins are locals (marginX = 2, marginY = 0): the `+ marginY` add is
 * folded to a move after coalescing, which is the original's
 * `adds r0, r0, #0` at +0x22. A literal `+ 0` folds early and loses it.
 */
void func_02191830(FieldMsgBg *msgBg, struct Strbuf *str, u8 *width, u8 *height)
{
    u32 marginX = 2, marginY = 0;
    u32 widthChars = func_0201D304(str, msgBg->font, 0) + marginX;
    u32 heightChars = func_0201D42C(str, msgBg->font) + marginY;
    u32 pixels = widthChars;
    widthChars >>= 3;
    if (pixels & 7) widthChars++;
    pixels = heightChars;
    heightChars >>= 3;
    *width = widthChars;
    if (pixels & 7) heightChars++;
    *height = heightChars;
}

void func_02191870(FieldMsgBg *msgBg, struct MsgData *msgData, u32 msgId, u32 id, u8 x, u8 y, u8 width, u8 height)
{
    FieldSubMsgWin *subMsgWin;
    int slot;

    subMsgWin = func_02030734(msgBg->heapId, 0x18, 1, d_021DDA50, 0xE2A);
    slot = func_0219319C(msgBg, subMsgWin);
    subMsgWin->strBuf = func_020457B0(0x40, msgBg->heapId);
    func_02045CAC(msgData, msgId, subMsgWin->strBuf);
    func_021917C4(msgBg, subMsgWin, subMsgWin->strBuf, (u16)(slot + 3), x, y, width, height, id);
}

/* x is u8: its caller (0x021B11B6) truncates r3, and the narrow type is what
 * pins its home store to the front of the prologue. */
void func_021918DC(FieldMsgBg *msgBg, struct Strbuf *str, u32 id, u8 x, u8 y, u8 width, u8 height)
{
    FieldSubMsgWin *subMsgWin;
    u32 slot;

    subMsgWin = func_02030734(msgBg->heapId, 0x18, 1, d_021DDA50, 0xE48);
    slot = func_0219319C(msgBg, subMsgWin);
    subMsgWin->strBuf = func_020457B0(func_020458F8(str) + 1, msgBg->heapId);
    func_02045838(subMsgWin->strBuf, str);
    func_021917C4(msgBg, subMsgWin, subMsgWin->strBuf, (u16)(slot + 3), x, y, width, height, id);
}

int func_0219194C(FieldSubMsgWin *subMsgWin)
{
    if (subMsgWin->strBuf != 0) {
        func_02045808(subMsgWin->strBuf);
    }
    func_0219492C(subMsgWin->talkSys, subMsgWin->talkIndex);
    return func_020307B0(subMsgWin);
}

void func_0219196C(FieldMsgBg *msgBg, u32 id)
{
    func_0219194C(func_021931C4(msgBg, id));
}

/*
 * The slot is cleared before it is read back, so the delete gets the cleared
 * value; the code is kept as the original has it (store, load, store).
 */
void func_02191978(FieldMsgBg *msgBg)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0) {
            msgBg->subMsgWin[i] = 0;
            {
                FieldSubMsgWin *entry = msgBg->subMsgWin[i];
                msgBg->subMsgWin[i] = 0;
                func_0219194C(entry);
            }
        }
    }
}

int func_021919AC(FieldMsgBg *msgBg)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0)
            return 1;
    }
    return 0;
}

int func_021919C8(FieldSubMsgWin *subMsgWin)
{
    if (func_02194974(subMsgWin->talkSys, (int)subMsgWin->talkIndex) == 0)
        return 0;
    func_020362DC();
    func_0203630C();
    switch (func_0201CE30(func_02194984(subMsgWin->talkSys, subMsgWin->talkIndex))) {
    case 0:
    case 1:
        break;
    case 2:
        return 1;
    }
    return 0;
}

void func_02191A04(FieldMsgBg *msgBg, int winType)
{
    func_02191A10(msgBg, winType, msgBg->font);
}

FieldBgWin *func_02191A10(FieldMsgBg *msgBg, u32 winType, struct GfFont *font)
{
    FieldBgWin *bgWin;
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    bgWin = func_02030734(msgBg->heapId, 0x34, 1, d_021DDA50, 0xee0);
    bgWin->msgBg = msgBg;
    bgWin->font = font;
    bgWin->scrollY = -48;
    func_02040618((u8)msgBg->bgFrame, 0, 0);
    func_02040618((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
    bgWin->bmpWin = func_020450F0((u8)msgBg->bgFrame, 2, 0x13, 0x1c, 4, 9, 1);
    bgWin->nextBmp = func_02043678(0x1c, 4, 0x20, msgBg->heapId);
    bgWin->prevBmp = func_02043678(0x1c, 4, 0x20, msgBg->heapId);
    func_02043B5C(func_02045770(bgWin->bmpWin), 15);
    func_02045374(bgWin->bmpWin);
    func_02045334(bgWin->bmpWin);
    func_02191D88(msgBg->bgFrame, 9, winType, msgBg->heapId);
    x = func_02045758(bgWin->bmpWin);
    y = func_02045760(bgWin->bmpWin);
    width = func_02045738(bgWin->bmpWin);
    height = func_02045740(bgWin->bmpWin);
    func_02191DC8((u8)msgBg->bgFrame, x, y, width, height, 0x33, 9);
    func_020409B4((u8)msgBg->bgFrame);
    func_021927C0(&bgWin->cursor, bgWin->msgBg);
    msgBg->windowKind = 11;
    func_02193044(0);
    return bgWin;
}

void func_02191B14(FieldBgWin *bgWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    func_02045770(bgWin->bmpWin);
    x = func_02045758(bgWin->bmpWin);
    y = func_02045760(bgWin->bmpWin);
    width = func_02045738(bgWin->bmpWin);
    height = func_02045740(bgWin->bmpWin);
    func_02191FA0((u8)bgWin->msgBg->bgFrame, x, y, width, height, 0, 15);
    func_020456F8(bgWin->bmpWin);
    x = func_02045758(bgWin->bmpWin);
    y = func_02045760(bgWin->bmpWin);
    width = func_02045738(bgWin->bmpWin);
    height = func_02045740(bgWin->bmpWin);
    func_02041300((u8)bgWin->msgBg->bgFrame, 0, x, y, width, height, 0x11);
    func_02045334(bgWin->bmpWin);
    func_020452E8(bgWin->bmpWin);
    func_020409B4((u8)bgWin->msgBg->bgFrame);
    func_02040618((u8)bgWin->msgBg->bgFrame, 3, 0);
    func_020437AC(bgWin->prevBmp);
    func_020437AC(bgWin->nextBmp);
    if (bgWin->lineStr != 0) {
        func_02045808(bgWin->lineStr);
    }
    func_021927E8(&bgWin->cursor);
    func_020307B0(bgWin);
}

u32 func_02191BE8(FieldBgWin *bgWin, struct Strbuf *str)
{
    switch (bgWin->seq) {
    case 0:
        bgWin->str = str;
        bgWin->lineStr = func_020457B0(func_020458F8(str) + 2, bgWin->msgBg->heapId);
        func_0219214C(func_02045770(bgWin->bmpWin), bgWin->font, bgWin->str, bgWin->lineStr, &bgWin->lineIndex, 15);
        func_02045334(bgWin->bmpWin);
        func_020409B4((u8)bgWin->msgBg->bgFrame);
        bgWin->seq++;
        break;
    case 1:
        bgWin->scrollY += 12;
        if (bgWin->scrollY >= 0) {
            bgWin->scrollY = 0;
            bgWin->seq++;
        }
        func_02040618((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
        break;
    case 2:
        if (func_02192138(bgWin->str, bgWin->lineStr, bgWin->lineIndex) == 1) {
            bgWin->seq = 5;
            break;
        }
        bgWin->seq++;
    case 3:
        if ((func_020362DC() & 3) == 0) {
            func_021928C0(&bgWin->cursor, func_02045770(bgWin->bmpWin), 15);
            func_02045334(bgWin->bmpWin);
            break;
        }
        func_021927FC(&bgWin->cursor, func_02045770(bgWin->bmpWin), 15);
        func_02043814(func_02045770(bgWin->bmpWin), bgWin->prevBmp);
        func_0219214C(bgWin->nextBmp, bgWin->font, bgWin->str, bgWin->lineStr, &bgWin->lineIndex, 15);
        bgWin->rollOffset = 0;
        func_020061E4(0x547);
        bgWin->seq++;
    case 4:
        if (func_021921C8(func_02045770(bgWin->bmpWin), bgWin->prevBmp, bgWin->nextBmp, bgWin->rollOffset, 15) == 1) {
            bgWin->seq = 2;
        } else {
            bgWin->rollOffset += 4;
        }
        func_02045334(bgWin->bmpWin);
        func_020409B4((u8)bgWin->msgBg->bgFrame);
        break;
    case 5:
        if ((func_020362DC() & 0xf3) == 0) {
            break;
        }
        bgWin->seq++;
    case 6:
        bgWin->scrollY -= 12;
        if (bgWin->scrollY <= -48) {
            bgWin->scrollY = -48;
        }
        func_02040618((u8)bgWin->msgBg->bgFrame, 3, bgWin->scrollY);
        if (bgWin->scrollY == -48) {
            bgWin->seq++;
            return 1;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}

void func_02191D88(u32 frame, u32 palSlot, u32 winType, u32 heapId)
{
    if (winType >= 4)
        winType = 0;
    func_02049624(5, 6, frame, 0x33, 0, 0, heapId);
    func_02049B90(5, 1, 0, winType << 5, palSlot << 5, 0x20, heapId);
}

void func_02191DC8(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette)
{
    func_02041300(frame, tile, x - 2, y - 1, 1, 1, palette);
    func_02041300(frame, tile + 1, x - 1, y - 1, 1, 1, palette);
    func_02041300(frame, tile + 2, x, y - 1, width, 1, palette);
    func_02041300(frame, tile + 4, x + width, y - 1, 1, 1, palette);
    func_02041300(frame, tile + 5, x + width + 1, y - 1, 1, 1, palette);
    func_02041300(frame, tile + 6, x - 2, y, 1, height, palette);
    func_02041300(frame, tile + 7, x - 1, y, 1, height, palette);
    func_02041300(frame, tile + 10, x + width, y, 1, height, palette);
    func_02041300(frame, tile + 11, x + width + 1, y, 1, height, palette);
    func_02041300(frame, tile + 12, x - 2, y + height, 1, 1, palette);
    func_02041300(frame, tile + 13, x - 1, y + height, 1, 1, palette);
    func_02041300(frame, tile + 14, x, y + height, width, 1, palette);
    func_02041300(frame, tile + 16, x + width, y + height, 1, 1, palette);
    func_02041300(frame, tile + 17, x + width + 1, y + height, 1, 1, palette);
}

void func_02191FA0(u8 frame, u8 x, u8 y, u8 width, u8 height, u16 tile, u8 palette)
{
    func_02041300(frame, tile, x - 2, y - 1, 1, 1, palette);
    func_02041300(frame, tile, x - 1, y - 1, 1, 1, palette);
    func_02041300(frame, tile, x, y - 1, width, 1, palette);
    func_02041300(frame, tile, x + width, y - 1, 1, 1, palette);
    func_02041300(frame, tile, x + width + 1, y - 1, 1, 1, palette);
    func_02041300(frame, tile, x - 2, y, 1, height, palette);
    func_02041300(frame, tile, x - 1, y, 1, height, palette);
    func_02041300(frame, tile, x + width, y, 1, height, palette);
    func_02041300(frame, tile, x + width + 1, y, 1, height, palette);
    func_02041300(frame, tile, x - 2, y + height, 1, 1, palette);
    func_02041300(frame, tile, x - 1, y + height, 1, 1, palette);
    func_02041300(frame, tile, x, y + height, width, 1, palette);
    func_02041300(frame, tile, x + width, y + height, 1, 1, palette);
    func_02041300(frame, tile, x + width + 1, y + height, 1, 1, palette);
}

int func_02192138(struct Strbuf *str, struct Strbuf *lineStr, u32 line)
{
    if (func_0201D37C(str, lineStr, line) == 0) {
        return 1;
    }
    return 0;
}

int func_0219214C(struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, struct Strbuf *lineStr, u32 *line, u8 color)
{
    int y;

    func_02043B5C(bmp, color);
    if (func_0201D37C(str, lineStr, *line) == 0)
        return 1;
    func_0201C7A4(bmp, 1, 1, lineStr, font);
    y = 1;
    y += func_0201D42C(lineStr, font) + 1;
    if (func_0201D37C(str, lineStr, ++*line) == 0)
        return 1;
    func_0201C7A4(bmp, 1, y, lineStr, font);
    ++*line;
    return 0;
}

int func_021921C8(struct Bmp *dst, struct Bmp *prevBmp, struct Bmp *nextBmp, int offset, u16 color)
{
    int width;
    int height;

    width = func_020437DC(dst);
    height = func_020437E4(dst);
    func_02043B5C(dst, color);
    if (offset > height)
        offset = height;
    func_020439A0(prevBmp, dst, 0, offset, 0, 0, width, height - offset, color);
    func_020439A0(nextBmp, dst, 0, 0, 0, height - offset, width, offset, color);
    if (offset >= height) return 1;
    return 0;
}

void func_02192244(u32 bgFrame, u32 palSlot, u32 heapId)
{
    func_02049B90(5, 2, 0, 0, palSlot * 32, 0x20, heapId);
}

void func_02192264(struct Bmp *bmp, u32 frameType, u32 heapId, u32 tileIndex)
{
    enum { FRAME_SET_FIRST } frameSet = FRAME_SET_FIRST;
    u8 *pixels;
    void *file;
    NNSG2dCharacterData *charData;

    pixels = func_020437D4(bmp);
    file = func_0204A1BC(5, 8, 0, heapId);
    func_02062A4C(file, &charData);
    func_02082EA4((u8 *)charData->pRawData + frameSet * 32 + tileIndex * 32, pixels, 0x20);
    func_020307B0(file);
}

static inline void blit(struct Bmp *tile, struct Bmp *bmp, u16 x, u16 y)
{
    func_020439A0(tile, bmp, 0, 0, x * 8, y * 8, 8, 8, 0xFFFF);
}

/*
 * Nine-slice frame: loads each frame tile into an 8x8 scratch bitmap with
 * func_02192264 and blits it over the centre, the four edges and the four
 * corners of the target bitmap.
 *
 * The edge loops use u16 locals truncated at their definition from the
 * CSE'd int width-1 / height-1 (spilled); the corners reuse the loop
 * counters i and j as the x/y tile positions, assigned before each tile
 * load, so the u16 truncation is scheduled ahead of the func_02192264 call.
 */
void func_021922A4(struct Bmp *bmp, u32 frameType, u32 heapId)
{
    u16 width;
    u16 j;
    u16 height;
    u16 i;
    struct Bmp *tile;
    u16 lastRow;
    u16 lastCol;

    width = func_020437DC(bmp) >> 3;
    height = func_020437E4(bmp) >> 3;
    tile = func_02043678(1, 1, 0x20, heapId);
    func_02192264(tile, frameType, heapId, 9);
    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
            blit(tile, bmp, i, j);
    func_02192264(tile, frameType, heapId, 1);
    for (i = 0; i < width; i++)
        blit(tile, bmp, i, 0);
    func_02192264(tile, frameType, heapId, 0x11);
    lastRow = height - 1;
    for (i = 0; i < width; i++)
        blit(tile, bmp, i, lastRow);
    func_02192264(tile, frameType, heapId, 8);
    for (i = 0; i < height; i++)
        blit(tile, bmp, 0, i);
    func_02192264(tile, frameType, heapId, 0xA);
    lastCol = width - 1;
    for (i = 0; i < height; i++)
        blit(tile, bmp, lastCol, i);
    func_02192264(tile, frameType, heapId, 0);
    blit(tile, bmp, 0, 0);
    i = width - 1;
    func_02192264(tile, frameType, heapId, 2);
    blit(tile, bmp, i, 0);
    i = height - 1;
    func_02192264(tile, frameType, heapId, 0x10);
    blit(tile, bmp, 0, i);
    i = width - 1;
    j = height - 1;
    func_02192264(tile, frameType, heapId, 0x12);
    blit(tile, bmp, i, j);
    func_020437AC(tile);
}

void func_021924F0(u16 x, u16 y, struct Bmp *bmp, struct GfFont *font, struct Strbuf *str, u16 heapId)
{
    int line;
    struct Strbuf *lineStr;
    int lineHeight;

    lineHeight = func_0201DC80(font) + 2;
    lineStr = func_020457B0(func_020458F8(str) + 1, heapId);
    for (line = 0; func_0201D37C(str, lineStr, line) == 1; line++) {
        func_0201C7A4(bmp, (s16)x, (s16)y, lineStr, font);
        y += (u16)lineHeight;
    }
    func_02045808(lineStr);
}

FieldSpWin *func_02192570(FieldMsgBg *msgBg, u32 frameType, u32 x, u16 y, u16 width, u16 height)
{
    FieldSpWin *spWin;

    spWin = func_02030734(msgBg->heapId, 0x18, 1, d_021DDA50, 0x115D);
    spWin->msgBg = msgBg;
    spWin->bmpWin = func_020450F0((u8)msgBg->bgFrame, (u8)x, (u8)y, (u8)width, (u8)height, 9, 1);
    spWin->frameBmp = func_02043678(1, 1, 0x20, msgBg->heapId);
    func_02192264(spWin->frameBmp, frameType, msgBg->heapId, 9);
    func_021922A4(func_02045770(spWin->bmpWin), frameType, msgBg->heapId);
    func_02192244(msgBg->bgFrame, 9, msgBg->heapId);
    func_02045374(spWin->bmpWin);
    func_02045334(spWin->bmpWin);
    func_020409B4((u8)msgBg->bgFrame);
    func_021927C0(&spWin->cursor, msgBg);
    msgBg->windowKind = 0xB;
    func_02193044(0);
    return spWin;
}

void func_02192628(FieldSpWin *spWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;

    func_020456F8(spWin->bmpWin);
    x = func_02045758(spWin->bmpWin);
    y = func_02045760(spWin->bmpWin);
    width = func_02045738(spWin->bmpWin);
    height = func_02045740(spWin->bmpWin);
    func_02041300((u8)spWin->msgBg->bgFrame, 0, x, y, width, height, 0x11);
    func_02045334(spWin->bmpWin);
    func_020409B4((u8)spWin->msgBg->bgFrame);
    func_021927E8(&spWin->cursor);
    func_020437AC(spWin->frameBmp);
    func_020452E8(spWin->bmpWin);
    func_020307B0(spWin);
}

void func_0219269C(FieldSpWin *spWin, u16 x, u16 y, struct Strbuf *str)
{
    FieldMsgBg *msgBg = spWin->msgBg;
    func_021924F0(x, y, func_02045770(spWin->bmpWin), msgBg->font, str, msgBg->heapId);
    func_02045334(spWin->bmpWin);
    func_020409B4((u8)spWin->msgBg->bgFrame);
}

int func_021926D8(FieldSpWin *spWin)
{
    u32 cont = func_020362DC();
    func_0203630C();
    if (cont & 3)
        return 1;
    func_021928F8(&spWin->cursor, func_02045770(spWin->bmpWin), spWin->frameBmp);
    func_02045334(spWin->bmpWin);
    return 0;
}

u32 func_0219270C(FieldMsgBg *msgBg, struct Strbuf *str, int margin)
{
    u32 width;
    u32 chars;

    width = margin * 2 + func_0201D304(str, msgBg->font, 0);
    chars = width >> 3;
    if (width & 7)
        chars++;
    return chars;
}

u32 func_0219272C(FieldMsgBg *msgBg, struct Strbuf *str, u32 margin)
{
    u32 height;
    struct Strbuf *lineStr;
    u32 lines;

    height = margin * 2 + func_0201D42C(str, msgBg->font);
    lineStr = func_02045874(str, msgBg->heapId);
    lines = 0;
    if (func_0201D37C(str, lineStr, 0) == 1) {
        while (++lines < 0x18 && func_0201D37C(str, lineStr, lines) == 1)
            ;
    }
    func_02045808(lineStr);
    height += (lines - 1) * 2;
    if (height & 7)
        height += 8;
    return height >> 3;
}

FieldMsgCursor *func_02192788(FieldMsgBg *msgBg)
{
    FieldMsgCursor *cursor = func_02030734(msgBg->heapId, 8, 1, d_021DDA50, 0x1202);
    func_021927C0(cursor, msgBg);
    return cursor;
}

void func_021927B0(FieldMsgCursor *cursor)
{
    func_021927E8(cursor);
    func_020307B0(cursor);
}

void func_021927C0(FieldMsgCursor *cursor, FieldMsgBg *msgBg)
{
    func_02082BCC(cursor, 0, 8);
    cursor->bmp = func_020436FC(msgBg->cursorCharData->pRawData, 1, 1, 0x20, msgBg->heapId);
}

void func_021927E8(FieldMsgCursor *cursor)
{
    cursor->isDrawn = 0;
    func_020437AC(cursor->bmp);
}

u8 func_021927F8(FieldMsgCursor *cursor)
{
    return cursor->isDrawn;
}

void func_021927FC(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color)
{
    FieldMsgCursorOffsets offsets = d_021D3E50;
    u16 x;
    u16 y;

    x = func_020437DC(bmp) - 8;
    y = func_020437E4(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    func_02043AF4(bmp, (s16)x, (s16)y, (u16)8, (u16)8, (u8)color);
    cursor->isDrawn = 0;
}

void func_02192860(FieldMsgCursor *cursor, struct Bmp *bmp, u32 unusedColor)
{
    FieldMsgCursorOffsets offsets = d_021D3E60;
    u16 x;
    u16 y;

    x = func_020437DC(bmp) - 8;
    y = func_020437E4(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    func_020439A0(cursor->bmp, bmp, 0, 0, x, y, 8, 8, 0);
    cursor->isDrawn = 1;
}

void func_021928C0(FieldMsgCursor *cursor, struct Bmp *bmp, u32 color)
{
    func_021927FC(cursor, bmp, color);
    cursor->animWait++;
    if (cursor->animWait >= 4) {
        cursor->animWait = 0;
        cursor->animFrame++;
        cursor->animFrame %= 3;
    }
    func_02192860(cursor, bmp, color);
}

void func_021928F8(FieldMsgCursor *cursor, struct Bmp *bmp, struct Bmp *frameBmp)
{
    FieldMsgCursorOffsets offsets = d_021D3E58;
    s16 x;
    s16 y;
    s16 shift;

    x = func_020437DC(bmp) - 8;
    y = func_020437E4(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    shift = y & 7;
    if (shift != 0)
        func_020439A0(frameBmp, bmp, 0, 8 - shift, x, y, 8, shift, 0xFFFF);
    func_020439A0(frameBmp, bmp, 0, 0, x, y + shift, 8, 8 - shift, 0xFFFF);
    cursor->animWait++;
    if (cursor->animWait >= 4) {
        cursor->animWait = 0;
        cursor->animFrame++;
        cursor->animFrame = cursor->animFrame % 3;
    }
    x = func_020437DC(bmp) - 8;
    y = func_020437E4(bmp) - 8 - offsets.offsetY[cursor->animFrame];
    func_020439A0(cursor->bmp, bmp, 0, 0, x, y, 8, 8, 0);
    cursor->isDrawn = 1;
}

void func_021929E8(u32 heapId)
{
    func_02049624(5, 10, 1, 0x1F, 0, 0, heapId);
}

/* Draws a one-tile frame around a window (tiles 0x1F..0x30, palette 13). */
void func_02192A04(struct BmpWin *bmpWin)
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u32 bgFrame;

    x = func_02045758(bmpWin);
    y = func_02045760(bmpWin);
    width = func_02045738(bmpWin);
    height = func_02045740(bmpWin);
    bgFrame = func_02045730(bmpWin);
    func_02041300(bgFrame, 0x1f, x - 1, y - 1, 1, 1, 13);
    func_02041300(bgFrame, 0x20, x, y - 1, width, 1, 13);
    func_02041300(bgFrame, 0x24, x + width, y - 1, 1, 1, 13);
    func_02041300(bgFrame, 0x25, x - 1, y, 1, height, 13);
    func_02041300(bgFrame, 0x2a, x + width, y, 1, height, 13);
    func_02041300(bgFrame, 0x2b, x - 1, y + height, 1, 1, 13);
    func_02041300(bgFrame, 0x2d, x, y + height, width, 1, 13);
    func_02041300(bgFrame, 0x30, x + width, y + height, 1, 1, 13);
    func_020409B4(bgFrame);
}

struct BmpWin *func_02192B20(u8 x, u8 y, u8 width, u8 height, u32 heapId)
{
    struct BmpWin *bmpWin;

    bmpWin = func_020450F0(2, x, y, width, height, 0xE, 1);
    func_02043B5C(func_02045770(bmpWin), 0xFF);
    func_02045374(bmpWin);
    func_02045334(bmpWin);
    func_02192A04(bmpWin);
    return bmpWin;
}

void func_02192B64(struct BmpWin *bmpWin)
{
    u32 bgFrame;
    u32 x;
    u32 y;
    u32 width;
    u32 height;

    bgFrame = func_02045730(bmpWin);
    x = func_02045758(bmpWin);
    y = func_02045760(bmpWin);
    width = func_02045738(bmpWin);
    height = func_02045740(bmpWin);
    func_02041300(bgFrame, 0, (u8)(x - 1), (u8)(y - 1), (u8)(width + 2), (u8)(height + 2), 0);
    func_020409B4(bgFrame);
}

void func_02192BC0(struct BmpWin *bmpWin)
{
    func_02192B64(bmpWin);
    func_020452E8(bmpWin);
}

/* Two-layer setup: message frame 1 and system frame 2, plus the talk balloon system. */
void func_02192BD0(FieldMsgBg *msgBg, int loadTalkSys)
{
    FieldBgTemplate msgTemplate;
    FieldBgTemplate sysTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3E98;
    func_0203FCA0((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    msgBg->bgFrameSys = 2;
    sysTemplate = d_021D3E78;
    func_0203FCA0((u8)msgBg->bgFrameSys, (const struct BgTemplate *)&sysTemplate, 0);
    func_02040C14(msgBg->bgFrame, 0, 1, 0);
    func_02041300((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300((u8)msgBg->bgFrameSys, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4((u8)msgBg->bgFrame);
    func_020409B4((u8)msgBg->bgFrameSys);
    if (loadTalkSys)
        func_02192FA4(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = func_02194670(&talkParam);
        func_02194704(msgBg->talkSys);
    }
    func_0207D63C(REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    func_02040588(msgBg->bgFrame, 1);
    func_02040588(msgBg->bgFrameSys, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* Same as func_02192BD0 with another template pair, and without func_02194704. */
void func_02192CF0(FieldMsgBg *msgBg, int loadTalkSys)
{
    FieldBgTemplate msgTemplate;
    FieldBgTemplate sysTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3ED8;
    func_0203FCA0((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    msgBg->bgFrameSys = 2;
    sysTemplate = d_021D3EF8;
    func_0203FCA0((u8)msgBg->bgFrameSys, (const struct BgTemplate *)&sysTemplate, 0);
    func_02040C14(msgBg->bgFrame, 0, 1, 0);
    func_02041300((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300((u8)msgBg->bgFrameSys, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4((u8)msgBg->bgFrame);
    func_020409B4((u8)msgBg->bgFrameSys);
    if (loadTalkSys)
        func_02192FA4(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = func_02194670(&talkParam);
    }
    func_0207D63C(REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    func_02040588(msgBg->bgFrame, 1);
    func_02040588(msgBg->bgFrameSys, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* One-layer setup: message frame 1 only, always loads the window graphics. */
void func_02192E0C(FieldMsgBg *msgBg)
{
    FieldBgTemplate msgTemplate;
    TalkMsgWinParam talkParam;

    msgBg->bgFrame = 1;
    msgTemplate = d_021D3EB8;
    func_0203FCA0((u8)msgBg->bgFrame, (const struct BgTemplate *)&msgTemplate, 0);
    func_02040C14(msgBg->bgFrame, 0, 1, 0);
    func_02041300((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4((u8)msgBg->bgFrame);
    func_02192FA4(msgBg->bgFrame, msgBg->heapId);
    if (msgBg->g3dCamera != 0) {
        talkParam.heapId = msgBg->heapId;
        talkParam.camera = msgBg->g3dCamera;
        talkParam.font = msgBg->font;
        talkParam.frameBaseTile = 0xb;
        talkParam.bgLayer = 1;
        talkParam.framePalette = 0xc;
        talkParam.bmpWinPalette = FIELD_MSGBG_PALETTE_TALK;
        msgBg->talkSys = func_02194670(&talkParam);
    }
    func_02040588(msgBg->bgFrame, 1);
    msgBg->windowKind = FIELD_MSGBG_PALETTE_SYSTEM;
}

/* Task callback: once the transition is over, uploads the balloon graphics and ends itself. */
void func_02192EB8(void *task, void *arg)
{
    FieldMsgBg *msgBg = arg;

    if (func_02005C8C() == 0) {
        func_02194704(msgBg->talkSys);
        msgBg->vblankTask = 0;
        func_02030EAC(task);
    }
}

/* Sets up the system window frame on BG 2. */
void func_02192EE0(int useTemplate)
{
    FieldBgTemplate sysTemplate;

    func_02040588(2, 0);
    if (useTemplate == 1) {
        sysTemplate = d_021D3F18;
        func_0203FCA0(2, (const struct BgTemplate *)&sysTemplate, 0);
    } else {
        /* Keep priority and mosaic, screen base 0x1F, character base 4. */
        REG_BG2CNT = (REG_BG2CNT & 0x43) | 0x1F10;
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);
    func_0207D63C(REG_BLDCNT_ADDR, 4, 0x1b, 0x10, 4);
    func_0204047C(2, 2);
    func_02040588(2, 1);
}

void func_02192F74(FieldMsgBg *msgBg)
{
    if (msgBg->sysFrameReq != 0) {
        msgBg->sysFrameReq = 0;
        if (msgBg->bgFrameSys == 0xFF) {
            func_020403F4(2);
            func_02192EE0(1);
            msgBg->bgFrameSys = 2;
        } else {
            func_02192EE0(0);
        }
    }
}

void func_02192FA4(int bgFrame, int heapId)
{
    func_02049B40(0x17, 5, 0, 0x160, 0x20, heapId);
    func_02049B40(0x17, 7, 0, 0x1c0, 0x20, heapId);
    func_0201F5BC(bgFrame & 0xff, 1, 0xd, 0, heapId);
    func_021929E8(heapId);
}

/* func_02192FA4 in three steps, one per call. */
void func_02192FEC(int bgFrame, int heapId, int step)
{
    if (step == 0) {
        func_02049B40(0x17, 5, 0, 0x160, 0x20, heapId);
        func_02049B40(0x17, 7, 0, 0x1c0, 0x20, heapId);
    } else if (step == 1) {
        func_0201F5BC(bgFrame & 0xff, 1, 0xd, 0, heapId);
    } else if (step == 2) {
        func_021929E8(heapId);
    }
}

void func_02193044(u32 enable)
{
    if (enable == 1)
        func_0207D63C(REG_BLDCNT_ADDR, 4, 0x1B, 0x10, 4);
}

/* Tail-call thunk: forwards to func_02193044 with no argument change. */
void func_02193060(u32 enable)
{
    func_02193044(enable);
}

void func_02193068(FieldMsgBg *msgBg)
{
    func_02040DA8(msgBg->bgFrame, 1, 0);
    func_02040C14(msgBg->bgFrame, 0, 1, 0);
    func_02041300((u8)msgBg->bgFrame, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4((u8)msgBg->bgFrame);
    func_02192FA4(msgBg->bgFrame, msgBg->heapId);
    func_02195588(msgBg->talkSys);
}

struct BmpWin *func_021930C0(int frame, int unusedHeapId, int x, int y, u16 width, u16 height, u16 palette)
{
    struct BmpWin *bmpWin;
    int framePalette;

    bmpWin = func_020450F0(frame & 0xff, x & 0xff, y & 0xff, width & 0xff, height & 0xff, palette & 0xff, 1);
    func_02043B5C(func_02045770(bmpWin), 0xff);
    func_02045374(bmpWin);
    func_02045334(bmpWin);
    func_020409B4((u8)frame);
    framePalette = 0xd;
    if (palette != FIELD_MSGBG_PALETTE_SYSTEM) {
        framePalette = 0xa;
    }
    func_0201F73C(bmpWin, 0, 1, framePalette & 0xff);
    return bmpWin;
}

int func_02193130(struct BmpWin *bmpWin)
{
    func_0201F7A8(bmpWin, 0);
    return func_020452E8(bmpWin);
}

void func_02193144(u32 heapId)
{
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1A0, 0x20, (u16)heapId);
}

void func_02193170(u32 heapId)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0x140, 0x20, (u16)heapId);
}

/* Stores the sub window in the first free slot and returns the slot (8 when full). */
int func_0219319C(FieldMsgBg *msgBg, FieldSubMsgWin *subMsgWin)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] == 0) {
            msgBg->subMsgWin[i] = subMsgWin;
            return i;
        }
    }
    return i;
}

/* Takes the sub window with this id out of its slot and returns it (0 when absent). */
FieldSubMsgWin *func_021931C4(FieldMsgBg *msgBg, u32 id)
{
    int i;
    FieldSubMsgWin *subMsgWin;

    for (i = 0; i < 8; i++) {
        if (msgBg->subMsgWin[i] != 0 && msgBg->subMsgWin[i]->id == id) {
            subMsgWin = msgBg->subMsgWin[i];
            msgBg->subMsgWin[i] = 0;
            return subMsgWin;
        }
    }
    return 0;
}

void func_021931F4(FieldMsgKeyWait *keyWait)
{
    func_02082BCC(keyWait, 0, sizeof(FieldMsgKeyWait));
}

void func_02193200(FieldMsgKeyWait *keyWait)
{
    keyWait->waitState = 0;
    keyWait->skipHeld = 0;
}

void func_02193208(FieldMsgKeyWait *keyWait, u8 autoMode)
{
    keyWait->autoMode = autoMode;
}

u8 func_0219320C(FieldMsgKeyWait *keyWait)
{
    return keyWait->autoMode;
}

/* Frames per character of a streamed message. */
u32 func_02193210(FieldMsgKeyWait *keyWait)
{
    if (keyWait->autoMode != 0)
        return func_02013080(1);
    return func_02012FFC();
}

/* Returns 1 when A or B is pressed after one of them was held since the stream started. */
int func_02193228(FieldMsgKeyWait *keyWait)
{
    u32 held = func_020362DC();
    u32 trg = func_0203630C();

    if (keyWait->autoMode != 0)
        return 0;
    if (held & PAD_BUTTON_AB)
        keyWait->skipHeld = 1;
    if (keyWait->skipHeld != 0 && (trg & PAD_BUTTON_AB))
        return 1;
    return 0;
}

/* Returns 1 when the message may advance: after a delay in auto mode, on A or B held otherwise. */
int func_02193260(FieldMsgKeyWait *keyWait, u32 streamState)
{
    int held = func_020362DC();
    int delay;

    if (streamState == 0) {
        delay = 8;
    } else {
        delay = 0x32;
    }
    if (keyWait->autoMode != 0) {
        keyWait->waitState = keyWait->waitState + 1;
        if (keyWait->waitState >= delay) {
            keyWait->waitState = 0;
            return 1;
        }
        return 0;
    }
    if ((held & PAD_BUTTON_AB) != 0) {
        return 1;
    }
    return 0;
}

void func_021932A0(struct PrintStream *stream, int fast)
{
    if (fast == 1)
        func_0201CE8C(stream, func_02013080(2));
    else
        func_0201CEB8(stream);
}
