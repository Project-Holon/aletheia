/*
 * file:     br_codein_p06.c
 * unit:     yes
 * function: func_021DC638, func_021DC8EC, func_021DCBD8, func_021DCDD8, func_021DCE28
 * address:  0x021DC638
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
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021DCE48 0x021DCE48 thumb ov183
 *   func_021DD054 0x021DD054 thumb ov183
 *   func_021DD128 0x021DD128 thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021DD2FC 0x021DD2FC thumb ov183
 *   func_021DD33C 0x021DD33C thumb ov183
 *   func_021DD1D4 0x021DD1D4 thumb ov183
 *   func_021DD0AC 0x021DD0AC thumb ov183
 *   func_021DD0F4 0x021DD0F4 thumb ov183
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02006254 0x02006254 thumb
 *   func_021F9C50 0x021F9C50 thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DBC68 0x021DBC68 thumb ov183
 *   func_021DD228 0x021DD228 thumb ov183
 *   func_021DD25C 0x021DD25C thumb ov183
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0200D6D0 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D774 0x0200D774 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0200B98C 0x0200B98C thumb
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   d_021E32C8 0x021E32C8 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02049238 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 *   func_021FD1C4 0x021FD1C4 thumb ov186
 *   func_021FD640 0x021FD640 thumb ov186
 */
#include "../../matched/include/Obj00050.h"
#include "../../matched/include/Obj24555.h"
#include "../../matched/include/Obj24556.h"
#include "../../matched/include/Obj24557.h"
#include "../../matched/include/Obj24558.h"
#include "../../matched/include/Obj24559.h"
#include "../../matched/include/Obj24560.h"
#include "../../matched/include/Obj24561.h"
#include "../../matched/include/Obj24562.h"
#include "../../matched/include/Obj24563.h"
#include "../../matched/include/Obj24564.h"
#include "../../matched/include/Obj24565.h"
#include "../../matched/include/Obj24566.h"
#include "../../matched/include/Obj24567.h"
#include "../../matched/include/Obj24568.h"
#include "../../matched/include/Obj24569.h"
#include "../../matched/include/Obj24571.h"

struct Actor;
struct Obj;
typedef unsigned int u32;

typedef unsigned char u8;

typedef struct S S;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef struct {u8 x,y,w,h;u32 message;} Descriptor;

typedef struct U16Vec U16Vec;

typedef struct MsgBank MsgBank;

typedef struct WordSet WordSet;

typedef struct GdsProfile GdsProfile;

typedef struct GdsRecord GdsRecord;

typedef struct RecGet RecGet;

typedef signed short s16;

typedef struct {s16 x,y,z;u8 a,b;} Position;

typedef struct {s16 x,y;} Pair;

typedef signed int     s32;

extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021DCE28(char *,char *),func_021DCE48(char *,char *),func_021DD054(char *,char *),func_021DD128(char *,char *),func_021DD1D4(char *,char *);
extern void func_021DD0AC(char *,char *),func_021DD0F4(char *,char *);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021DD2FC(char *,int,int),func_021DD33C(char *,int,int);
extern void func_021FD170(char *p, char *q, void *text);
extern int func_02012DAC(int),func_02012DD0(u8 *);
extern void func_021FD860(int,int,int *);
extern int func_02006254(u32 a);
extern void func_021F9C50(S *);
extern int func_021FD744(int *a);
extern int *func_021FD73C(int *p, int v);
extern void func_021DBC68(int a, int b, char *p);
extern int func_021DD228(void *),func_021DD25C(void *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC7C4(char *,void *,void *,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0200D6D0(const void *,u32);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern u32 func_0200D6EC(struct RecGet *p);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void),func_0201BC40(void),func_0201BCB4(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_021DD228(void *);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void func_02082BCC(void *,int,unsigned);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02049238(void *);
extern char *func_021FD1C4(void *prof, char *q, void *a2, void *a3, int mode, u16 heap);
extern void func_021FD640(int *);
void func_021DC638(int *a,int *state,char *p);
void func_021DC8EC(char *p,char *q);
void func_021DCBD8(char *p,void *manager,void *party,u16 heap);
void func_021DCDD8(char *p, char *q);
void func_021DCE28(char *p,char *unused);
extern const Descriptor d_021E32C8[];
extern const Pair d_021E32F0[];

/*
 * abi: DD0AC/DD0F4 retain caller-loaded r1.
 */
void func_021DC638(int *a,int *state,char *p)
{
    u32 x,y;
    switch(*state) {
    case 0: func_021FE784((int)(*(int * *)&((struct Obj24555 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=1;break;
    case 1: if(func_021FE7B0(*(int * *)&((struct Obj24556 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=2;break;
    case 2:
        if(((struct Obj00050 *)p)->fB0) func_021DCE28(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        else func_021DCE48(p,*(char * *)&((struct Obj00050 *)p)->fD0);
        func_021DD054(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021DD128(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=3;break;
    case 3: func_021FE784((int)(*(int * *)&((struct Obj24557 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);++*state;break;
    case 4: if(func_021FE7B0(*(int * *)&((struct Obj24558 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 5: ++*state;break;
    case 6:
        if(func_02035D20(&x,&y)) {
            if(func_021DD2FC(p,x,y)) *state=7;
            else if(func_021DD33C(p,x,y)) *state=10;
        }
        break;
    case 7: func_021FE784((int)(*(int * *)&((struct Obj24559 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 8: if(func_021FE7B0(*(int * *)&((struct Obj24560 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 9: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=13;break;
    case 10: func_021FE784((int)(*(int * *)&((struct Obj24561 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);++*state;break;
    case 11: if(func_021FE7B0(*(int * *)&((struct Obj24562 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) ++*state;break;
    case 12: func_021DD1D4(p,*(char * *)&((struct Obj00050 *)p)->fD0);func_021FD73C(a,(int)func_021DBC68);break;
    case 13: func_021DD0AC(p,*(char * *)&((struct Obj00050 *)p)->fD0);*state=14;break;
    case 14:
        func_021FD170(((struct Obj00050 *)p)->f18,(char *)(((struct Obj24563 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10),(void *)0x152);
        func_021FE784((int)(*(int * *)&((struct Obj24564 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,0);*state=15;break;
    case 15: if(func_021FE7B0(*(int * *)&((struct Obj24565 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=16;break;
    case 16: *state=17;break;
    case 17: func_02012DAC(((struct Obj24566 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28);*state=18;break;
    case 18:
        if(func_02012DD0(*(u8 * *)&((struct Obj24567 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f28)==2) {func_021FD860(*(int *)&((struct Obj00050 *)p)->fC,0,0);*state=19;}
        break;
    case 19: func_021FE784((int)(*(int * *)&((struct Obj24568 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC),2,3,1);*state=20;break;
    case 20: if(func_021FE7B0(*(int * *)&((struct Obj24569 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->fC)) *state=21;break;
    case 21:
        if(!func_02006254(0x701)) {
            func_021DD0F4(p,*(char * *)&((struct Obj00050 *)p)->fD0);
            **(int * *)&((struct Obj00050 *)p)->fD0=1;
            func_021F9C50(*(S * *)&((struct Obj24571 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f14);
            func_021FD744((int *)a);
        }
        break;
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-C: prior verified Thumb EXACT from ov183_func_021DF838.c header, blocker-r2.log, dsi/1.1p1 -O4,p; table 0x0209DDCC data a4.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned long long u64;
 * extern const u16 func_0200B98C_Table[];
 * u64 func_0200B98C(char *p,int selector,int index) {
 *   int i;u16 v;
 *   switch(selector) {
 *   case 0: v=((u16 *)p)[index];if(v>0x289)return 0;return v;
 *   case 1: return *(u8 *)(p+index+0x18)&0x7f;
 *   case 2: v=*(u16 *)(p+0x24);if(v>0x270f)return 0x270f;return v;
 *   case 3: for(i=0;i<0x29;i++)if(*(u16 *)(p+0x26)==func_0200B98C_Table[i])return i;return 0;
 *   case 4: return *(u64 *)(p+0x38);
 *   case 5: return *(u8 *)(p+0x2a);
 *   case 6: return (*(u8 *)(p+index+0x18)&0x80)>>7;
 *   case 7: return *(u8 *)(p+0x2b);
 *   default:return 0;
 *   }
 * }
 * lever: counter declared before context locals restores stack homes; named selector fixes call-result addition operand order (existing idioms).
 * abi: EE0C retains caller's sixth outgoing word (2), beyond callee's five used arguments.
 */
void func_021DC8EC(char *p,char *q)
{
    u16 record[4];
    int i;
    void *font;
    MsgBank *bank;
    WordSet *words;
    int ready;
    const Descriptor *d;
    char *slot;
    U16Vec *text;
    if(!*(int *)(p+0xd4)) {
        *(int *)(p+0xd4)=1;
        if(func_021DD228(*(void **)(p+0xc4))) func_021FB964((void *)(*(int *)(q+0x10)),7,*(u16 *)(p+0xb4));
        else func_021FB964((void *)(*(int *)(q+0x10)),6,*(u16 *)(p+0xb4));
        font=(void *)func_021FC20C(*(char **)(q+0x10));
        bank=(MsgBank *)func_021FC214(*(char **)(q+0x10));
        words=(WordSet *)func_021FC21C(*(char **)(q+0x10));
        for(i=0;i<5;i++) {
            d=&d_021E32C8[i];
            slot=p+i*4;
            *(void **)(slot+0x30)=func_021FC6A4(1,d->x,d->y,d->w,d->h,14,*(void **)(p+4),*(u16 *)(p+0xb4));
            switch(i) {
            case 0:
                {
                void *name;
                void *message;
                text=func_020457B0(128,*(u16 *)(p+0xb4));
                name=func_0200D6D0(*(void **)(p+0xc0),*(u16 *)(p+0xb4));
                message=func_02045EC0(bank,d->message);
                func_0201EE0C(words,0,name,func_0200D6EC(*(RecGet **)(p+0xc0)),1,2);
                func_0201F250(words,text,message);
                func_02045808((U16Vec *)name);func_02045808((U16Vec *)message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);
                ready=1;break;
                }
            case 1:
                {
                u32 selector;
                selector=func_0200B98C(*(void **)(p+0xc4),3,0);
                text=func_02045EC0(bank,selector+d->message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);ready=1;break;
                }
            case 2:
                {
                u64 value;
                u64 quotient;
                u32 low,middle,high;
                void *message;
                void *temporary;
                value=func_0200B98C(*(void **)(p+0xc4),4,0);
                low=value%100000ULL;
                quotient=value/100000ULL;
                middle=quotient%100000ULL;
                high=quotient/100000ULL;
                temporary=func_0200D774(*(GdsProfile **)(p+0xc0),(GdsRecord *)record,*(u16 *)(p+0xb4));
                if(temporary) {
                    message=func_02045EC0(bank,13);func_02045808((U16Vec *)temporary);
                } else message=func_02045EC0(bank,d->message);
                text=func_020457B0(128,*(u16 *)(p+0xb4));
                func_0201EFA4(words,2,low,5,2,1);func_0201EFA4(words,1,middle,5,2,1);func_0201EFA4(words,0,high,2,2,1);
                func_0201F250(words,text,message);
                func_021FC868(*(void **)(slot+0x30),0,1,0);func_02045808((U16Vec *)message);
                ready=1;break;
                }
            case 3:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    u32 count;
                    void *message;
                    count=func_0200B98C(*(void **)(p+0xc4),2,0);
                    text=func_020457B0(128,*(u16 *)(p+0xb4));
                    message=func_02045EC0(bank,d->message);
                    func_0201EFA4(words,0,count,4,0,1);func_0201F250(words,text,message);func_02045808((U16Vec *)message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            case 4:
                if(func_021DD25C(*(void **)(p+0xc4))) {
                    text=func_02045EC0(bank,d->message);
                    func_021FC868(*(void **)(slot+0x30),0,1,1);ready=1;
                } else ready=0;
                break;
            }
            if(ready) {
                func_021FC7C4(*(char **)(slot+0x30),text,font,0x3da0);func_02045808(text);
            }
        }
        func_021DCBD8(p,*(void **)(q+0x18),*(void **)(p+0xc4),*(u16 *)(p+0xb4));
    }
}

/*
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 */
void func_021DCBD8(char *p,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Pair *coords;
    char *slot;
    int mapping;
    archive=func_020490F4(7,(u16)((heap&0x7fff)|0x8000));
    *(void **)(p+0x48)=(void *)func_0204ACEC(archive,func_0201BC3C(),0,128,heap);
    mapping=func_0201BC40();
    *(void **)(p+0x4c)=(void *)func_0204AF28(archive,mapping,func_0201BCB4(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(func_021DD228(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=func_0200B98C(party,0,i);
            f=func_0200B98C(party,1,i);
            h=func_0200B98C(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Pair *)((u32)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        slot=p+j*4;
        *(void **)(slot+0x80)=0;
        *(u32 *)(slot+0x50)=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            *(u32 *)(slot+0x50)=func_0204A6C8(archive,func_0201BABC(v2,f2,h2,0),0,0,heap);
            func_02082BCC(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            *(void **)(p+count*4+0x80)=func_0204B294(manager,(u32)(*(void **)(slot+0x50)),(u32)(*(void **)(p+0x48)),(u32)(*(void **)(p+0x4c)),&pos,0,heap);
            func_0204B688(*(void **)(count*4+p+0x80),1);
            func_0204B6F4(*(void **)(p+count*4+0x80),func_0201BB5C(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    func_02049238(archive);
}

void func_021DCDD8(char *p, char *q)
{
    int flag;
    if(*(int *)(p+0x44)==0 && *(int *)(p+0xdc)==0) {
        *(int *)(p+0xdc)=1;
        flag=1;
        if(*(int *)(*(char **)(p+0xd0)+8)==0) flag=0;
        *(void **)(p+0x44)=func_021FD1C4((void *)(*(int *)(p+0xc0)),(char *)(*(int *)(q+0x10)),(void *)(*(int *)(q+0x18)),(void *)(*(int *)(p+4)),flag,*(unsigned short *)(p+0xb4));
    }
}

void func_021DCE28(char *p,char *unused) { if(((struct Obj00050 *)p)->fDC && *(int * *)&((struct Obj00050 *)p)->f44) { func_021FD640(*(int * *)&((struct Obj00050 *)p)->f44); *(int *)&((struct Obj00050 *)p)->f44=0; ((struct Obj00050 *)p)->fDC=0; } }
