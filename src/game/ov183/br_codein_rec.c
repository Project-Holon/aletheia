/*
 * file:     br_codein_rec.c
 * unit:     yes
 * function: func_021E2FA8, func_021E2FE8, func_021E300C, func_021E301C, func_021E31AC, func_021E31E8, func_021E3228
 * address:  0x021E2FA8
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_SetWindowText 0x021FD170 thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   BR_UTIL_DeleteTextWin 0x021FD15C thumb ov186
 *   d_021E3910 0x021E3910 data a4
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   STRBUF_Create 0x020457B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   BR_BTN_CreateObject 0x021FB3BC thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 *   BR_RES_ReleaseSprite 0x021FC0C8 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../../matched/include/Obj03885.h"
#include "../../matched/include/Obj24693.h"
#include "../../matched/include/Obj24694.h"
#include "../../matched/include/Obj06616.h"
#include "../../matched/include/Obj24695.h"
#include "../../matched/include/Obj10763.h"
#include "../../matched/include/Obj10764.h"
#include "../../matched/include/Obj14446.h"
#include "../../matched/include/Obj24696.h"
#include "../../matched/include/Obj24697.h"

struct Pair;
struct PrintSys;
struct U16Vec;
struct RecGet;
struct MsgBank;
struct ObjC4;
struct WordSet;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 a,b; } Pair;

typedef struct { u32 f0,f4; Pair callbacks; } Table;

typedef struct Desc {short x,y,n;unsigned char flag,pad;} Desc;

typedef struct Triple {int a,b,c;} Triple;

extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_SetWindowText(char *p, char *q, void *text);
extern void BR_UTIL_StartEffect(int, int, int *);
extern void BR_UTIL_DeleteTextWin(void *,int);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MI_CpuFill8(void *,int,unsigned),BR_RES_LoadSprite(char *,unsigned,unsigned);
extern int BR_RES_GetSprite(void *,int,Triple *);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *BR_BTN_CreateObject(void *,void *,int,int,int,int,int,void *,u16);
extern void *BR_BTN_CreateFromMessage(void *,int,int,int,int,int,int,int,void *,u16);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag);
extern u32 func_0200D6EC(struct RecGet *p);
extern void BR_UTIL_SetWindowTextBuf(char *p, void *q, void *text);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_BTN_DeleteObject(char *p);
extern void BR_RES_ReleaseSprite(char *,unsigned);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021E2FA8(char *p);
void func_021E2FE8(char *p);
void func_021E300C(Pair *out);
void func_021E301C(char *p,char *q);
void func_021E31AC(char *p,char *q);
int func_021E31E8(char *p, int a, int b);
int func_021E3228(char *p, int a, int b);
extern const Table d_021E3910;



void func_021E2FA8(char *p)
{
    int args[2];
    if (((struct Obj03885 *)p)->f8 == 0)
        ((struct Obj03885 *)p)->f8 = BR_UTIL_CreateTextWin(((struct Obj24693 *)(*(char * *)&((struct Obj03885 *)p)->f3C))->f8, (void *)(((struct Obj03885 *)p)->f4), ((struct Obj03885 *)p)->f38);
    BR_UTIL_SetWindowText(((struct Obj03885 *)p)->f8, (char *)(((struct Obj24694 *)(*(char * *)&((struct Obj03885 *)p)->f3C))->f8), (void *)0x14b);
    args[0] = 0x80;
    args[1] = 0x60;
    BR_UTIL_StartEffect(((struct Obj03885 *)p)->f30, 4, args);
}




void func_021E2FE8(char *p) { int zero=0;BR_UTIL_StartEffect((int)(*(char * *)&((struct Obj06616 *)p)->f30), 0, (int *)0);if(((struct Obj06616 *)p)->f8){BR_UTIL_DeleteTextWin(((struct Obj06616 *)p)->f8,((struct Obj24695 *)(*(char * *)&((struct Obj06616 *)p)->f3C))->f8);*(int *)&((struct Obj06616 *)p)->f8=zero;} }




void func_021E300C(Pair *out) {
    *out=d_021E3910.callbacks;
}



/*
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021E301C(char *p,char *q)
{
    Triple t;
    Desc d;
    int h,c;
    void *a,*b,*s,*owner,*tmp;
    int i;
    unsigned offset;
    h=BR_RES_GetFont(*(char **)(q+8));
    c=BR_RES_GetMsgData(*(char **)(q+8));
    a=(void *)BR_RES_GetWordSet(*(char **)(q+8));
    b=STRBUF_Create(0x80,*(u16 *)(p+0x38));
    s=STRBUF_Create(0x80,*(u16 *)(p+0x38));
    MI_CpuFill8(&d,0,8);
    d.x=0x30;d.y=0x28;d.n=11;d.flag=1;
    BR_RES_LoadSprite(*(char **)(q+8),1,*(u16 *)(p+0x38));
    BR_RES_GetSprite(*(void **)(q+8),1,&t);
    for(i=0;i<3;i++) {
        offset=(i+1)*4;
        if(*(unsigned *)(*(unsigned *)(q+0x18)+offset)) {
            func_02045CAC((struct MsgBank *)c,0x1a,s);
            func_0201EE0C(a,0,(const void *)(*(unsigned *)(*(unsigned *)(q+0x18)+offset+0x10)),*(unsigned *)(*(unsigned *)(q+0x18)+offset+0x20),1,2);
            func_0201F250(a,b,s);
        }else func_02045CAC((struct MsgBank *)c,9,b);
        *(void **)(p+i*4+0x14)=BR_BTN_CreateObject(&d,b,0xa0,1,*(int *)(q+4),*(int *)p,h,&t,*(u16 *)(p+0x38));
        d.y=d.y+0x28;
    }
    d.n=1;
    *(void **)(p+0x20)=BR_BTN_CreateFromMessage(&d,4,0xa0,1,*(int *)(q+4),*(int *)p,h,c,&t,*(u16 *)(p+0x38));
    owner=BATTLE_REC_GetWork();
    tmp=GDS_PROFILE_CreateNameStr(owner,(u16)((*(u16 *)(p+0x38)&0x7fff)|0x8000));
    if(!*(void **)(p+8)) *(void **)(p+8)=BR_UTIL_CreateTextWin(*(int *)(q+8),(void *)(*(int *)(p+4)),*(u16 *)(p+0x38));
    func_02045CAC((struct MsgBank *)c,0x5c,s);
    func_0201EE0C(a,0,(const void *)tmp,func_0200D6EC(owner),1,2);
    func_0201F250(a,b,s);
    BR_UTIL_SetWindowTextBuf(*(void **)(p+8),(void *)(*(int *)(q+8)),b);
    STRBUF_Delete(tmp);STRBUF_Delete(s);STRBUF_Delete(b);
}



void func_021E31AC(char *p,char *q) { int i;char *s;if(((struct Obj10763 *)p)->f8){BR_UTIL_DeleteTextWin(((struct Obj10763 *)p)->f8,*(int *)&((struct Obj14446 *)q)->f8);*(int *)&((struct Obj10763 *)p)->f8=0;}for(i=0;i<4;i++){s=p+i*4;if(((struct Obj10764 *)s)->f14){BR_BTN_DeleteObject(((struct Obj10764 *)s)->f14);((struct Obj10764 *)s)->f14=0;}}BR_RES_ReleaseSprite(*(char * *)&((struct Obj14446 *)q)->f8,1); }




int func_021E31E8(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x20) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        BR_UTIL_StartEffect(((struct Obj24696 *)p)->f34, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}


int func_021E3228(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x90) <= 0x48) &
             ((unsigned int)(b - 0x30) <= 0x10);

    if (ok) {
        int args[2];

        args[0] = a;
        args[1] = b;
        BR_UTIL_StartEffect(((struct Obj24697 *)p)->f34, 1, args);
        GFL_USE_PlaySeDefaultVolume(0x703);
    }
    return ok;
}
