/*
 * function: ZUKAN_NICKNAME_Main
 * address: 0x0220B72C
 * packet: pkt_ov207_0220B72C
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 02035C60/0201CCE4 matched void forwarders leave r0 live; this caller tests/stores it.
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F164 0x0201F164 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   ZUKAN_NICKNAME_UpdateInfoWindow 0x0220B9E0 thumb ov207
 */
#include "../include/Obj00181.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Tcbl;
struct WordSet;
struct Descriptor;
struct CharBuf;
struct U16Vec;
extern void TCBL_Main(struct Tcbl *);
extern u32 PRINTSYS_PrintStreamGetState(void *);
extern u32 KEY_GetCont(void);
extern void func_020355D8(u8);
extern int TOUCHPANEL_GetCont(void);
typedef signed int     s32;
struct Rec;
struct Rec3;
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,u8);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *);
extern struct WordSet *GF_FONT_Create_EC64(u32);
extern void func_0201EEF4(struct WordSet *,u32,void *);
extern void func_0201F164(struct WordSet *,u32,u32,u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void ZUKAN_NICKNAME_UpdateInfoWindow(int *);
int ZUKAN_NICKNAME_Main(char *p)
{
    int done=0,flag;
    u32 value;
    struct WordSet *ws;
    switch(((struct Obj00181 *)p)->f3C) {
    case 0: break;
    case 1:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=PRINTSYS_PrintStreamGetState(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=2;((struct Obj00181 *)p)->f4C=1;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(((struct Obj00181 *)p)->f28);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 2:
        if(((struct Obj00181 *)p)->f40==2) break;
        if(((struct Obj00181 *)p)->f40==0) {
            if(*(u32 *)&((struct Obj00181 *)p)->f8==0) {((struct Obj00181 *)p)->f3C=5;break;}
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00181 *)p)->f24),15);
            PRINTSYS_PrintStreamDelete(((struct Obj00181 *)p)->f28);
            STRBUF_Delete(*(struct U16Vec * *)&((struct Obj00181 *)p)->f2C);
            ws=GF_FONT_Create_EC64(((struct Obj00181 *)p)->f0);
            func_0201EEF4(ws,0,((struct Obj00181 *)p)->f4);
            func_0201F164(ws,1,((struct Obj00181 *)p)->fC,((struct Obj00181 *)p)->f10);
            *(struct U16Vec * *)&((struct Obj00181 *)p)->f2C=STRBUF_Create(64,((struct Obj00181 *)p)->f0);
            func_0201F250(ws,((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f8);
            WORDSET_DeleteStrbufED04(ws);
            *(u32 *)&((struct Obj00181 *)p)->f28=PRINTSYS_PrintStream(*(u32 *)&((struct Obj00181 *)p)->f24,0,0,*(u32 *)&((struct Obj00181 *)p)->f2C,((struct Obj00181 *)p)->f18,MSG_SPEED_GetWait(),*(u32 *)&((struct Obj00181 *)p)->f34,2,((struct Obj00181 *)p)->f0,15);
            ((struct Obj00181 *)p)->f3C=3;
        } else ((struct Obj00181 *)p)->f3C=5;
        break;
    case 3:
        TCBL_Main(*(struct Tcbl * *)&((struct Obj00181 *)p)->f34);
        value=PRINTSYS_PrintStreamGetState(((struct Obj00181 *)p)->f28);
        if(value==2) {((struct Obj00181 *)p)->f3C=4;break;}
        switch(value) {
        case 0:
            flag=0;
            if(KEY_GetCont()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetCont()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) PRINTSYS_PrintStreamShortWait(((struct Obj00181 *)p)->f28,0);
            break;
        case 1:
            flag=0;
            if(KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
            else if(TOUCHPANEL_GetTrg()!=0) {func_020355D8(1);flag=1;}
            if(flag!=0) {PRINTSYS_PrintStreamReleasePause(((struct Obj00181 *)p)->f28);GFL_USE_PlaySeDefaultVolume(0x547);}
            break;
        }
        break;
    case 4:
        ++((struct Obj00181 *)p)->f44;
        if(((struct Obj00181 *)p)->f44==60) ((struct Obj00181 *)p)->f3C=5;
        break;
    case 5: done=1; break;
    }
    ZUKAN_NICKNAME_UpdateInfoWindow((int *)p);
    return done;
}
