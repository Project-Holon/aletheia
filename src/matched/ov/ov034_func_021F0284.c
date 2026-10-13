/*
 * function: REPORT_InitWindows
 * address: 0x021F0284
 * packet: pkt_ov034_021F0284
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: inline print_record binds owner before the bitmap getter; named one
 * remains live across the repeated blocks and pins their distinct spill slots.
 * symbols:
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   GAMESYSTEM_GetMyPlayerWork 0x020120F8 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   func_0201F158 0x0201F158 thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_CountSeen 0x0200D0AC thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_020071EC 0x020071EC thumb
 *   func_02008748 0x02008748 thumb
 *   func_020086C8 0x020086C8 thumb
 *   func_020086D0 0x020086D0 thumb
 *   func_020086D8 0x020086D8 thumb
 *   func_020086E0 0x020086E0 thumb
 *   func_020086E8 0x020086E8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02088864 0x02088864 arm
 *   func_0208890C 0x0208890C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   sReportWindowLayouts 0x021F0A70 data a1
 */
#include "../include/Obj00166.h"
#include "../include/Obj09806.h"
#include "../include/Obj13076.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PRINTSYS_QUE_Create(void *p);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Big;
struct BigObj;
struct Blk34;
struct CharBuf;
struct Ctx;
struct GfFont;
struct MsgBank;
struct PlayTime;
struct RTCDate;
struct RTCTime;
struct Rec;
struct Rec44;
struct Sub020071E4Ctrl;
struct U16Vec;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int func_02088864(struct RTCDate *date);
extern int func_0208890C(struct RTCTime *time);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_GetPlaceNameId(u32);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 func_0200C258(struct Blk34 *p);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *,int);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
struct Blk37;
extern u32 ZUKAN_SAVE_CountSeen(struct Blk37 *p, u32 heap);
extern int GAME_DATA_GetPlayTime(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
struct Sub020071E4Ctrl;
extern u8 func_020071EC(const struct Sub020071E4Ctrl *);
extern struct PlayTime *func_02008748(void *sys);
extern u32 func_020086C8(const struct PlayTime *p);
extern u32 func_020086D0(const struct PlayTime *p);
extern u32 func_020086D8(const struct PlayTime *p);
extern u32 func_020086E0(const struct PlayTime *p);
extern u32 func_020086E8(const struct PlayTime *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern const u8 sReportWindowLayouts[];
static inline void print_record(u8 *p,u32 index,void *dst,void *s,u32 y,u16 color,u32 one)
{
    u32 owner=((struct Obj09806 *)p)->f8;
    PRINTSYS_PrintQueColor((void *)owner,(u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p+12+index*8)),0,y,(u32)dst,(u32)(((struct Obj09806 *)p)->f4C),color);
    p[16+index*8]=one;
    STRBUF_Delete(s);
}
void REPORT_InitWindows(u8 *p)
{
    u32 i,one=1;
    void *bank,*ws,*dst,*ctx,*ctrl,*s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7,*time,*t;
    u32 date[4],clock[3];
    ((struct Obj00166 *)p)->f8=PRINTSYS_QUE_Create((void *)(((struct Obj00166 *)p)->f12C));
    for(i=0;i<8;i++) {
        const u8 *r=sReportWindowLayouts+i*6;
        u8 *entry=p+i*8;
        ((struct Obj13076 *)entry)->fC=BMP_WIN_Create(r[0],r[1],r[2],r[3],r[4],r[5],one);
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((struct Obj13076 *)entry)->fC),0);
    }
    ((struct Obj00166 *)p)->f4C=GF_FONT_Create(23,0,0,0,((struct Obj00166 *)p)->f12C);
    bank=func_02045B38(0,2,168,((struct Obj00166 *)p)->f12C);
    ws=func_0201EC64(((struct Obj00166 *)p)->f12C);
    dst=STRBUF_Create(256,((struct Obj00166 *)p)->f12C);
    ctx=GAMESYSTEM_GetGameData(((struct Obj00166 *)p)->f0);
    ctrl=GAME_DATA_GetSaveControl(ctx);
    s0=func_02045EC0(bank,0);
    func_0201F02C(ws,0,GAME_DATA_GetMyStatus(ctx));
    func_0201F250(ws,dst,s0);
    print_record(p,0,dst,s0,4,0x3580,one);
    s1=func_02045EC0(bank,1);
    func_02088864((struct RTCDate *)date);
    func_0201EFA4(ws,0,date[0],2,2,one);
    func_0201EFA4(ws,one,date[1],2,0,one);
    func_0201EFA4(ws,2,date[2],2,0,one);
    func_0201F250(ws,dst,s1);
    print_record(p,1,dst,s1,0,0x3DC0,one);
    s2=func_02045EC0(bank,2);
    func_0208890C((struct RTCTime *)clock);
    func_0201EFA4(ws,0,clock[0],2,0,one);
    func_0201EFA4(ws,one,clock[1],2,2,one);
    func_0201F250(ws,dst,s2);
    print_record(p,2,dst,s2,0,0x3DC0,one);
    s3=func_02045EC0(bank,3);
    func_0201F158(ws,0,ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(((struct Obj00166 *)p)->f0))));
    func_0201F250(ws,dst,s3);
    print_record(p,3,dst,s3,0,0x3DC0,one);
    s4=func_02045EC0(bank,4);
    func_0201EFA4(ws,0,func_0200C258(GAME_DATA_GetMiscSave(ctx)),2,0,1);
    func_0201F250(ws,dst,s4);
    print_record(p,4,dst,s4,0,0x3DC0,one);
    if(ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(((struct Obj00166 *)p)->f0)),0x962)==1) {
        s5=func_02045EC0(bank,5);
        func_0201EFA4(ws,0,ZUKAN_SAVE_CountSeen(ZUKAN_SAVE_GetFromGameData(ctx),((struct Obj00166 *)p)->f12C),3,0,1);
        func_0201F250(ws,dst,s5);
        print_record(p,5,dst,s5,0,0x3DC0,one);
    }
    s6=func_02045EC0(bank,6);
    time=(void *)GAME_DATA_GetPlayTime((u32)ctx);
    func_0201EFA4(ws,0,func_0200864C(time),3,0,1);
    func_0201EFA4(ws,1,func_02008650(time),2,2,1);
    func_0201F250(ws,dst,s6);
    print_record(p,6,dst,s6,0,0x3DC0,one);
    if(func_020071F0(ctrl)==0 && func_020071EC(ctrl)==1) {
        t=func_02008748(ctrl);
        s7=func_02045EC0(bank,7);
        func_0201EFA4(ws,0,func_020086C8(t),2,2,1);
        func_0201EFA4(ws,1,func_020086D0(t),2,0,1);
        func_0201EFA4(ws,2,func_020086D8(t),2,0,1);
        func_0201EFA4(ws,3,func_020086E0(t),2,0,1);
        func_0201EFA4(ws,4,func_020086E8(t),2,2,1);
        func_0201F250(ws,dst,s7);
        print_record(p,7,dst,s7,4,0x3580,one);
    } else BMP_WIN_TransferChars((struct Descriptor *)((struct Obj00166 *)p)->f44);
    STRBUF_Delete(dst);
    func_0201ED04(ws);
    MSGDATA_Delete(bank);
}
