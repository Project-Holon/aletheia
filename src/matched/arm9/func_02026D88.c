/*
 * function: GAME_BEACON_BuildMyInfo
 * address:  0x02026D88
 * packet:   pkt_02026D88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The own-beacon builder: fills a BeaconRec from the player profile, the
 * save blocks and the DS owner info.  Layout it proves beyond the family
 * header: word +0 is four BYTES (+0 = 0xff, +1/+2 from 0x0200856C and
 * 0x02008570, +3 split 7:1 as u8 bitfields -- strb/ldrb, not word RMW);
 * word +0xC is 6:3:3:4:10:6 (bits 0..5 = 0x15, 6..8 from 0x02008554,
 * 9..11 from 0x0200C224, 12..15 the owner's favoriteColor, then the
 * trainer and top fields); +0x12 is seven halfwords filled like +0x20;
 * +0x50 takes ten bytes via MI_CpuCopy8; the scratch at sp+0x14 is the
 * 0x54-byte OSOwnerInfo.  Levers that mattered: stack order (save, tbl,
 * bag declared in that order) and func_02008550 answering a word that is
 * narrowed with an explicit (u8) before the 1-bit store.
 *
 * symbols:
 *   func_02012944    0x02012944  thumb
 *   func_02012EBC    0x02012EBC  thumb
 *   func_0200C0F0    0x0200C0F0  thumb
 *   func_0200E6E8    0x0200E6E8  thumb
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   func_020127A4    0x020127A4  thumb
 *   func_02012AC8    0x02012AC8  thumb
 *   func_02013CC8    0x02013CC8  thumb
 *   func_02013CE0    0x02013CE0  thumb
 *   func_02012894    0x02012894  thumb
 *   func_02166C7C    0x02166C7C  thumb
 *   func_02008534    0x02008534  thumb
 *   func_02008550    0x02008550  thumb
 *   func_02008554    0x02008554  thumb
 *   func_0200856C    0x0200856C  thumb
 *   func_02008570    0x02008570  thumb
 *   func_0200C224    0x0200C224  thumb
 *   func_0200C1C4    0x0200C1C4  thumb
 *   func_0200C1DC    0x0200C1DC  thumb
 *   func_02012FCC    0x02012FCC  thumb
 *   func_0200864C    0x0200864C  thumb
 *   func_02008650    0x02008650  thumb
 *   func_0200E394    0x0200E394  thumb
 *   func_0200E3A0    0x0200E3A0  thumb
 *   MI_CpuCopy8      0x02082D44  arm
 *   func_0200E6FC    0x0200E6FC  thumb
 *   GAME_BEACON_SetMyPms    0x020274B4  thumb
 *   func_02045A98    0x02045A98  arm
 *   func_020084F4    0x020084F4  thumb
 *   func_0200C1F4    0x0200C1F4  thumb
 *   GAME_BEACON_ResetDetails    0x0202744C  thumb
 */
#include "../include/Obj15760.h"
typedef signed short   s16;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  language;
    u8  favoriteColor;
    u8  month;
    u8  day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

struct Src { u16 a; u16 b; u16 c; u16 d; };

struct Rec {
    u8  b00;
    u8  b01;
    u8  b02;
    u8  b03lo : 7;
    u8  b03hi : 1;

    u32 id    : 17;
    u32 mode  : 10;
    u32 f04hi : 5;

    u32 peer  : 17;
    u32 seq   : 5;
    u32 f08hi : 10;

    u32 c0    : 6;
    u32 c6    : 3;
    u32 c9    : 3;
    u32 c12   : 4;
    u32 trainer : 10;
    u32 f0chi : 6;

    u16 f10;
    u16 f12[7];
    u16 vec[8];
    u16 f30;
    u8  pad32[0x50 - 0x32];
    u8  f50[10];
};

struct Big;
struct BigObj;
struct Blk34;
struct PlayTime;
struct Rec1C;
struct Rec44;
struct SaveBlock;
struct Sub0200852CObj;
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern void *func_0200E6E8(u32 a);
extern void  OS_GetOwnerInfo(OSOwnerInfo *info);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
struct Rec0200E6FC;
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern struct Rec1C *func_02012894(const struct BigObj *p);
extern u32   func_02166C7C(void *sys, u16 m);
extern u16 func_02008534(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_0200C224(struct Blk34 *p);
extern u32 func_0200C1C4(struct Blk34 *p);
extern u32 func_0200C1DC(struct Blk34 *p);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_0200E394(void *p);
extern void *func_0200E3A0(void *p);
extern void  MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern void GAME_BEACON_SetMyPms(u32 a0);
extern u16   func_02045A98(void);
extern u16  *func_020084F4(void *p);
extern u16 *func_0200C1F4(struct Blk34 *p);
extern void GAME_BEACON_ResetDetails(void *dst);

void GAME_BEACON_BuildMyInfo(struct Rec *o, void *sys)
{
    void *save;
    void *tbl;
    void *bag;
    void *prof;
    void *st;
    struct Src src;
    OSOwnerInfo info;
    u16 *q;
    u16 v;
    int i;

    prof = func_02012944(sys);
    save = func_02012EBC(sys);
    tbl = func_0200C0F0(save);
    bag = func_0200E6E8((u32)save);
    OS_GetOwnerInfo(&info);

    o->b00 = 0xff;
    o->mode = func_02012AC8(func_020127A4(sys));
    if ((int)func_02013CC8((u16)o->mode) == 1 || (int)func_02013CE0((u16)o->mode) == 1) {
        o->mode = ((struct Obj15760 *)((u8 *)func_02012894(sys)))->f4;
    }
    o->f08hi = func_02166C7C(sys, o->mode);
    o->b03lo = 0x30;
    o->f10 = func_02008534(prof);
    o->c12 = info.favoriteColor;
    o->b03hi = (u8)(u32)func_02008550(prof);
    if (o->b03hi == 0) {
        o->c6 = func_02008554(prof);
    } else {
        o->c6 = func_02008554(prof) - 8;
    }
    o->c0 = 0x15;
    o->f04hi = 2;
    o->b01 = func_0200856C(prof);
    o->b02 = func_02008570(prof);
    o->c9 = func_0200C224(tbl);
    o->peer = func_0200C1C4(tbl);
    o->id = func_0200C1DC(tbl);
    st = (void *)func_02012FCC((int)sys);
    o->trainer = func_0200864C(st);
    o->f0chi = func_02008650(st);
    MI_CpuCopy8(func_0200E3A0(func_0200E394(save)), o->f50, 10);
    func_0200E6FC(bag, 0, (struct Rec0200E6FC *)(&src));
    GAME_BEACON_SetMyPms((u32)(&src));
    v = func_02045A98();
    q = func_020084F4(prof);
    for (i = 0; i < 7; i++) {
        o->f12[i] = q[i];
        if (v == q[i])
            break;
    }
    q = func_0200C1F4(tbl);
    for (i = 0; i < 8; i++) {
        o->vec[i] = q[i];
        if (v == q[i])
            break;
    }
    GAME_BEACON_ResetDetails(o);
    o->f30 = 0;
}
