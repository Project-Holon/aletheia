/*
 * file:     mystery_util_p16.c
 * unit:     yes
 * function: func_021DC030, func_021DC03C, func_021DC064, func_021DC08C, func_021DC4F0, func_021DC734, func_021DC9CC, func_021DCCE4, func_021DCEC4, func_021DCF54, func_021DCFA4, func_021DCFC8, func_021DD1FC, func_021DD240, func_021DD24C
 * address:  0x021DC030
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   d_021DF838 0x021DF838 data a4
 *   d_021DF848 0x021DF848 data a4
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203633C 0x0203633C arm
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021DDF5C 0x021DDF5C thumb ov121
 *   func_021DBDB8 0x021DBDB8 thumb ov121
 *   func_021DBF04 0x021DBF04 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DBA78 0x021DBA78 thumb ov121
 *   func_021DB528 0x021DB528 thumb ov121
 *   func_021DB478 0x021DB478 thumb ov121
 *   func_021DBA94 0x021DBA94 thumb ov121
 *   func_020061E4 0x020061E4 thumb
 *   data_021DF86E 0x021DF86E data a1
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9D4C 0x021D9D4C thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021DA038 0x021DA038 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021DA148 0x021DA148 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_02082BCC 0x02082BCC arm
 *   func_021DBC08 0x021DBC08 thumb ov121
 *   func_021DA2F0 0x021DA2F0 thumb ov121
 *   func_0200A170 0x0200A170 thumb
 *   func_0207D658 0x0207D658 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021DF86E 0x021DF86E data a1
 *   d_021DF86F 0x021DF86F data a1
 *   func_021DBCC8 0x021DBCC8 thumb ov121
 *   func_021DB938 0x021DB938 thumb ov121
 *   func_021DB54C 0x021DB54C thumb ov121
 *   func_020409B4 0x020409B4 arm
 *   func_021DA8B8 0x021DA8B8 thumb ov121
 *   func_021DE014 0x021DE014 thumb ov121
 *   func_0200A0C8 0x0200A0C8 thumb
 *   func_0200A2B8 0x0200A2B8 thumb
 *   func_0200A2D8 0x0200A2D8 thumb
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_021DA1BC 0x021DA1BC thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049238 0x02049238 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0204B570 0x0204B570 arm
 *   d_021DFBB0 0x021DFBB0 data a4
 *   d_021DF99C 0x021DF99C data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_021DA280 0x021DA280 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021DBDF4 0x021DBDF4 thumb ov121
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021DA338 0x021DA338 thumb ov121
 *   func_021DA3EC 0x021DA3EC thumb ov121
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   func_020173F0 0x020173F0 thumb
 *   func_020186C8 0x020186C8 thumb
 *   func_02017588 0x02017588 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017FA8 0x02017FA8 thumb
 *   func_0201808C 0x0201808C thumb
 *   func_020180F4 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   func_02045A98 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   func_020185C4 0x020185C4 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_02017EAC 0x02017EAC thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0202D6F4 0x0202D6F4 thumb
 *   d_021DFA14 0x021DFA14 data a4
 *   d_021DF8C0 0x021DF8C0 data a4
 *   g0209DF08 0x0209DF08 data a1
 *   g0209DF0C 0x0209DF0C data a1
 *   gMsgBank 0x020A7370 data
 */
#include "../../matched/include/Obj00061.h"
#include "../../matched/include/Obj00169.h"
#include "../../matched/include/Obj00253.h"
#include "../../matched/include/Obj01930.h"
#include "../../matched/include/Obj22906.h"
#include "../../matched/include/Obj00237.h"

#define W(k) (*(u32 *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
struct Obj;
struct Vec2;
struct Actor;
struct Mon;
struct MsgBank;
struct Strbuf;
struct Sub0200852CObj;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 low:1; u8 flag:1; u8 rest:6; } Bits;

typedef struct {short x,y;} Position;

typedef struct {u8 x,y,pad[6];} Coord_021DC08C;

typedef struct { u32 v[7]; u16 a,b,c,d; } Desc_021DC4F0;

typedef struct { short x,y; } Vec;

typedef struct { u8 x,y,pad[6]; } Coord_021DC4F0;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DC734;

typedef struct { u8 pad[0xAC8]; u32 row; u32 col; } Cur;

typedef struct {u32 v[7];u16 a,b,c,d;} Desc_021DCCE4;

typedef signed short s16;

typedef struct {u32 w[12];} Desc_021DCFC8;

typedef struct {u32 w[30];} Config;

typedef struct {s16 x,y,z;u8 a,b;} Record_021DCFC8;

typedef signed int     s32_021DCFC8;

typedef int s32_021DD24C;

typedef unsigned long long u64;

typedef struct { u32 w[51]; } Record_021DD24C;

typedef struct { u32 f0; u32 f4; void *f8; u32 fC; u16 f10; u16 f12; u16 f14; u16 pad; } DE;

typedef struct { DE e[5]; } Desc_021DD24C;

struct Rec {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10;
    u16 mv[4];
    u16 species;
    u8 form;
    u8 f1D;
    u16 f1E;
    u8 pad20[0x14];
    u8 f34;
    u8 f35;
    u8 f36;
    u8 f37;
    u16 f38;
    u16 f3A;
    u8 f3C;
    u8 f3D;
    u8 f3E;
    u8 f3F;
    u8 f40;
    u8 f41;
    u8 pad42;
    u8 iv0, iv1, iv2, iv6, iv7, iv3;
    u8 pad49;
    u16 f4A;
    u8 pad4C[0xE];
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 pad5D[0x4F];
    u32 fAC;
    u8 padB0[2];
    u8 fB2;
    u8 fB3;
    u8 fB4a:1;
    u8 fB4b:1;
};

struct Ctx {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fC;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
};

struct CtxB {
    u32 f0;
    u8 pad4[0xB4];
    u32 fB8;
    u32 fBC;
    u32 fC0;
    u32 fC4;
    u32 fC8;
    u32 fCC;
};

struct Out {
    u8 pad0[0xE0];
    u32 fE0;
    u16 fE4;
    u16 fE6;
    u8 padE8[0x118 - 0xE8];
    u16 heap;
    u8 pad11A[2];
    struct CtxB *b;
    struct Rec *a;
    void *c;
    u8 pad128[0xC];
    u32 f134;
    u32 f138;
    void *f13C;
    void *f140;
    void *f144;
};

extern int func_021DC024(void *);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_0203633C(void);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_021DDF5C(u8 *p);
extern void func_020061E4(u32 a);
extern int func_021DBDB8(char *);
extern int func_021DBF04(int *p);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_021D9E04(u8 *);
extern void func_021DBA78(u8 *p, int a);
extern void func_021DB528(char *,int);
extern void func_021DB478(char *,int,int,int,u16);
extern int func_021DBA94(char *);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void *func_021D9D4C(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void func_021D9F08(u8 *a, int b, int c, int d);
extern void *func_021DA038(const u8 *p, u16 heap);
extern int func_021DA178(char *p);
extern void func_021DA148(u8 *p);
extern void func_021D9E50(u8 *);
extern unsigned func_021D9FF8(u8 *p);
extern void func_02082BCC(void *,int,u32);
extern void func_021DBC08(struct Obj *o, int idx);
extern void func_021DA2F0(u8 *p, u32 i);
extern int func_0200A170(char *p);
extern void func_0207D658(u32,int,int);
extern void func_021DBCC8(struct Obj *o, u32 a, u32 b);
extern void func_021DB938(char *,int,u16);
extern void func_021DB54C(char *,int,int,int,u16,u16);
extern void func_020409B4(u32);
extern void func_021DA8B8(u32 *p);
extern int func_021DE014(char *p);
extern u32 func_0200A0C8(u8 *p);
extern void func_0200A2B8(void *a0, int a1);
extern int func_0200A2D8(void *a0, int a1);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_021DA1BC(void *,const char *,u32,u16,u8,u32,u32,int,u16);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021DCFC8 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *owner,unsigned int i,unsigned int j,unsigned int k,const void *position,unsigned short space,unsigned short heap);
extern void func_0204B688(struct Actor *actor, u32 value);
extern int func_0202D7C8(int a0);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern int func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D81C(void *,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_021DA280(u8 *p);
extern int func_021DA2C8(u8 *p);
extern void func_021DBDF4(void *out, const Record_021DD24C *src, void *p, u16 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_021DA338(char *p, u16 heap);
extern void func_021DA3EC(char *p, char *desc, void *dst);
extern u32 func_020056EC(u32 range);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017FA8(void *p);
extern u32 func_0201808C(void *p, u32 move);
extern void func_020180F4(void *p, int move);
extern void func_02018A00(void *p, u32 species, u32 arg);
extern u16 func_02045A98(void);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020185F0(void *p);
extern void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern void func_020185C4(void *p);
extern int func_0202D060(void);
extern u32 func_02017EAC(void *p);
extern s32_021DD24C func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_020185F4(void *p);
extern u32 func_0202D6F4(void *a0, void *mon, u32 a2, u32 a3);
int func_021DC030(u32 p);
int func_021DC03C(void *p);
int func_021DC064(void *p);
void func_021DC08C(void *task,u32 *state,char *p);
void func_021DC4F0(void *task,u32 *state,u8 *p);
void func_021DC734(void *task,u32 *state,char *p);
void func_021DC9CC(void *task,u32 *state,char *p);
void func_021DCCE4(void *arg,u32 *state,char *p);
void func_021DCEC4(void *arg,int *state,char *p);
void func_021DCF54(char *p,void *arc,int id,int index,u8 other,u16 heap);
void func_021DCFA4(u8 *p,int b,int c,u16 d);
void *func_021DCFC8(const Desc_021DCFC8 *p,u16 heap);
void func_021DD1FC(void **p);
int func_021DD240(void **p);
struct Out *func_021DD24C(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap);
extern const int d_021DF838[];
extern const int d_021DF848[];
extern const Coord_021DC08C data_021DF86E[];
extern u8 d_021DF86E[],d_021DF86F[];
extern char d_021DFBB0[];
extern const Config d_021DF99C;
extern const Desc_021DD24C d_021DFA14;
extern const u32 d_021DF8C0[];
extern u8 g0209DF08;
extern u8 g0209DF0C;
extern void *gMsgBank;

int func_021DC030(u32 p) { return ((Bits *)(p+184))->flag; }

int func_021DC03C(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 0 : 5; return add+d_021DF838[i]; }

int func_021DC064(void *p) { int i,add; i=func_021DC024(p); add=func_021DC030((u32)p) ? 3 : 0; return add+d_021DF848[i]; }

static inline int wrap(int value,int low,int high)
{
    if(value>high) return low;
    if(value<low) return high;
    return value;
}

/*
 * spelling: BF04 uses char-pointer arithmetic and a signed acc read, retaining the post-switch acc reload; raw integer address arithmetic was four bytes short.
 * interfaces: 02035C60's live r0 is consumed by this caller despite its legacy void definition.
 */
void func_021DC08C(void *task,u32 *state,char *p)
{
    u32 repeat;
    int delta,changed,count,next,direction;
    Position pos;
    switch(*state) {
    case 0:
        func_0204B3DC(((struct Obj00061 *)p)->fAF4,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAF8,1);
        func_0204B3DC(((struct Obj00061 *)p)->fAEC,1);
        repeat=func_0203633C();
        changed=0;delta=0;
        if(func_02035C60()) {
            ((struct Obj00061 *)p)->fAAC=*(void **)((u32)p+0xa7c+(u16)(((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)*4);
            if(((struct Obj00061 *)p)->fAAC) func_021DDF5C(((struct Obj00061 *)p)->fAAC);
        }
        if(repeat==512) delta=-1;
        else if(repeat==256) delta=1;
        else if(repeat&64) {
            func_020061E4(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=2;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 1:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=3;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 2: ((struct Obj00061 *)p)->fACC=0;break;
            case 3: ((struct Obj00061 *)p)->fACC=1;break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=2;
                else ((struct Obj00061 *)p)->fACC=3;
                break;
            }
            changed=1;
        } else if(repeat&128) {
            func_020061E4(0x548);
            switch(((struct Obj00061 *)p)->fACC) {
            case 0: ((struct Obj00061 *)p)->fACC=2;break;
            case 1: ((struct Obj00061 *)p)->fACC=3;break;
            case 2:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=0;
                else {((struct Obj00061 *)p)->fAE4=1;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 3:
                if(((struct Obj00061 *)p)->fAE0) ((struct Obj00061 *)p)->fACC=1;
                else {((struct Obj00061 *)p)->fAE4=0;((struct Obj00061 *)p)->fACC=4;}
                break;
            case 4:
                if(((struct Obj00061 *)p)->fAE4) ((struct Obj00061 *)p)->fACC=0;
                else ((struct Obj00061 *)p)->fACC=1;
                break;
            }
            changed=1;
        } else if(repeat&32) {
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==0 || ((struct Obj00061 *)p)->fACC==2) delta=-1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    --((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(repeat&16) {
            func_021DBDB8(p);
            if(((struct Obj00061 *)p)->fACC==1 || ((struct Obj00061 *)p)->fACC==3) delta=1;
            else if(((struct Obj00061 *)p)->fACC!=4) func_020061E4(0x548);
            if(((struct Obj00061 *)p)->fACC!=4) {
                if(((struct Obj00061 *)p)->fACC<=1) {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,0,1);
                } else {
                    ++((struct Obj00061 *)p)->fACC;
                    ((struct Obj00061 *)p)->fACC=wrap(((struct Obj00061 *)p)->fACC,2,3);
                }
                changed=1;
            }
        } else if(func_020362DC()&1) {
            if(((struct Obj00061 *)p)->fACC==4) {
                if(((struct Obj00061 *)p)->fAE0==0) {
                    func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                    func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                    func_020061E4(0x54c);
                    func_021DA8B0(task,(u32)func_021DCCE4);
                }
            } else if(func_021DBF04((int *)(p+40+220*((u32)*(int *)&((struct Obj00061 *)p)->fACC+*(u32 *)&((struct Obj00061 *)p)->fAC8*4)))) {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_020061E4(0x54c);
                if(((struct Obj00061 *)p)->fAE0) func_021DA8B0(task,(u32)func_021DC9CC);
                else func_021DA8B0(task,(u32)func_021DC4F0);
            }
        } else if(func_020362DC()&2) {
            func_020061E4(0x551);
            if(((struct Obj00061 *)p)->fAE0) {
                if(*(u8 * *)&((struct Obj00061 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00061 *)p)->fABC);((struct Obj00061 *)p)->fABC=0;}
                func_0204B3DC(((struct Obj00061 *)p)->fAF0,0);
                ((struct Obj00061 *)p)->fAE0=0;
            } else {
                func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
                func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
                func_021DA8B0(task,(u32)func_021DCCE4);
            }
        }
        if(delta) {
            count=func_021DBDB8(p);
            if(delta<0) {
                if(((struct Obj00061 *)p)->fAC8) next=((struct Obj00061 *)p)->fAC8-1;
                else next=count-1;
                direction=1;
            } else if(delta>0) {
                if(((struct Obj00061 *)p)->fAC8<count-1) next=((struct Obj00061 *)p)->fAC8+1;
                else next=0;
                direction=0;
            }
            func_020061E4(0x642);
            func_021DBA78((u8 *)p,direction);
            func_021DB528(p,0);
            func_021DB478(p,0,direction,next,((struct Obj00061 *)p)->f24);
            ((struct Obj00061 *)p)->fAC8=next;
            func_0204B3DC(((struct Obj00061 *)p)->fAEC,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF4,0);
            func_0204B3DC(((struct Obj00061 *)p)->fAF8,0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
            *state=1;
        }
        if(changed) {
            if((int)((struct Obj00061 *)p)->fACC<4) {
                pos.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
                pos.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
                func_0204B878(((struct Obj00061 *)p)->fAEC,0);
            } else {
                pos.x=176;pos.y=152;
                func_0204B878(((struct Obj00061 *)p)->fAEC,11);
            }
            func_0204B404(((struct Obj00061 *)p)->fAEC,(const struct Vec2 *)(&pos),0);
            ((struct Obj00061 *)p)->fBAC=0;
            ((struct Obj00061 *)p)->fA78=1;
        }
        break;
    case 1:
        if(func_021DBA94(p)) *state=0;
        break;
    }
}

void func_021DC4F0(void *task,u32 *state,u8 *p)
{
    Desc_021DC4F0 d;
    Vec v;
    int result;
    switch (*state) {
    case 0:
        if (!((struct Obj00169 *)p)->fABC) {
            ((struct Obj00169 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
            func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,116,0);
        *state=1;
        break;
    case 1:
        func_02082BCC(&d,0,36);
        d.v[0]=*(u32 *)&((struct Obj00169 *)p)->f1C; d.v[1]=*(u32 *)&((struct Obj00169 *)p)->f10; d.v[2]=*(u32 *)&((struct Obj00169 *)p)->f14;
        d.v[3]=117;d.v[4]=118;d.v[5]=119;d.v[6]=3;
        d.a=0;d.b=15;d.c=13;d.d=1;
        ((struct Obj00169 *)p)->fAC0=func_021DA038((const u8 *)(&d),((struct Obj00169 *)p)->f24);
        *state=2;
        break;
    case 2:
        result=func_021DA178(((struct Obj00169 *)p)->fAC0);
        ((struct Obj00169 *)p)->fBAC=0x7fff;
        if (result==-1) break;
        if (result==0) {
            ((struct Obj00169 *)p)->fAE0=1;
            v.x=data_021DF86E[*(u32 *)(p+0xacc)].x*8-24;
            v.y=data_021DF86E[*(u32 *)(p+0xacc)].y*8-8;
            func_0204B404(((struct Obj00169 *)p)->fAF0,(const struct Vec2 *)(&v),0);
            func_0204B3DC(((struct Obj00169 *)p)->fAF0,1);
            ((struct Obj00169 *)p)->fADE=((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4;
            if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
            if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
            if (!((struct Obj00169 *)p)->fABC) {
                ((struct Obj00169 *)p)->fABC=func_021D9D4C(0,15,((struct Obj00169 *)p)->f14,((struct Obj00169 *)p)->f10,29);
                func_021D9FFC(((struct Obj00169 *)p)->fABC,1,13);
            }
            func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,122,0);
            *state=6;
        } else if (result==1) {
            if (func_021DC030((u32)((void *)((u32)p+40+220*(((struct Obj00169 *)p)->fACC+((struct Obj00169 *)p)->fAC8*4))))) *state=7;
            else *state=3;
        } else if (result==2) *state=5;
        break;
    case 3:
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021D9F08(((struct Obj00169 *)p)->fABC,((struct Obj00169 *)p)->f1C,120,1);
        *state=4;
        break;
    case 4:
        if (func_021D9FF8(((struct Obj00169 *)p)->fABC)) *state=5;
        break;
    case 5:
        if (*(u8 * *)&((struct Obj00169 *)p)->fABC) {func_021D9E04(*(u8 * *)&((struct Obj00169 *)p)->fABC);((struct Obj00169 *)p)->fABC=0;}
        if (((struct Obj00169 *)p)->fAC0) {func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;}
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 6:
        func_021DA8B0(task,(u32)func_021DC08C);
        break;
    case 7:
        func_021DA148(((struct Obj00169 *)p)->fAC0);((struct Obj00169 *)p)->fAC0=0;
        func_021DA8B0(task,(u32)func_021DC734);
        break;
    }
    if (*(u8 * *)&((struct Obj00169 *)p)->fABC) func_021D9E50(*(u8 * *)&((struct Obj00169 *)p)->fABC);
}

static inline void window0(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000040=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000044=((y<<8)&0xff00)|(yy&255);
}

static inline void inside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}

static inline void outside(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x0400004a=v;
}

/*
 * lever: int coordinate locals retain table loads before SDK window plane writes; u8 locals were 4 bytes short.
 * volatile: display control 021DC82C/838/950/958; window registers 021DC84E..892.
 */
void func_021DC734(void *task,u32 *state,char *p)
{
    Desc_021DC734 d;
    u32 index=W(0xac8)*4+W(0xacc);
    int result;
    int x,y;
    switch(*state) {
    case 0:func_021D9F08(P(0xabc),W(28),123,1);*state=1;break;
    case 1:
        if(func_021D9FF8(P(0xabc))) {
            func_02082BCC(&d,0,36);
            d.v[0]=W(28);d.v[1]=W(16);d.v[2]=W(20);
            d.v[3]=124;d.v[4]=125;d.v[6]=2;
            d.a=0;d.b=15;d.c=13;d.d=1;
            P(0xac0)=func_021DA038((const u8 *)&d,H(36));
            *state=2;
        }
        break;
    case 2:
        result=func_021DA178((char *)P(0xac0));
        H(0xbac)=0x7fff;
        if(result!=-1) {
            func_021DA148(P(0xac0));P(0xac0)=0;
            if(!result) *state=3;
            else {
                if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
                func_021DA8B0(task,(u32)func_021DC08C);
            }
        }
        break;
    case 3:
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|0x2000;
        x=d_021DF86E[(u8)(index&3)*8];
        y=d_021DF86F[(u8)(index&3)*8];
        inside(30,1);
        window0(x*8,y*8,(x+12)*8,(y+7)*8);
        outside(30,0);*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}
        break;
    case 5:
        func_021DBC08((struct Obj *)p, index);
        func_021DB528(p,1);
        func_021DB478(p,1,0,W(0xac8),H(36));
        W(0xa78)=1;*state=6;break;
    case 6:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=7;}
        break;
    case 7:
        if(!func_0200A170((char *)P(12))) func_021DA2F0(P(0xab8),1);
        *(volatile u32 *)0x04000000 &= ~0xe000;
        *state=8;break;
    case 8:func_021D9F08(P(0xabc),W(28),121,1);*state=9;break;
    case 9:if(func_021D9FF8(P(0xabc))) *state=10;break;
    case 10:
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        func_021DA8B0(task,(u32)func_021DC08C);break;
    }
    if(P(0xabc)) func_021D9E50(P(0xabc));
}

static inline void window1(int x,int y,int xx,int yy)
{
    *(volatile u16 *)0x04000042=((x<<8)&0xff00)|(xx&255);
    *(volatile u16 *)0x04000046=((y<<8)&0xff00)|(yy&255);
}

static inline void inside0(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f)|(u32)planes;
    if(effect) v|=32;
    *(volatile u16 *)0x04000048=v;
}

static inline void inside1(int planes,int effect)
{
    u32 v=(*(volatile u16 *)0x04000048&~0x3f00)|((u32)planes<<8);
    if(effect) v|=32<<8;
    *(volatile u16 *)0x04000048=v;
}

/*
 * lever: index read through a two-field struct, but the row field is re-read as a plain int in the cases (a different type stops the CSE across the switch); previous-cell value shifted unsigned; col declared before row for the slot order. Twin shape: ov121 021DC734.
 * note: 2026-10-05 recoup P23L5: 8 B DIFF first form (asrs for lsrs and row/col slots swapped), then EXACT. Real extent 792 B, not the 46 B of the lane list.
 * volatile: display control 04000000, window registers 04000040..4A.
 */
void func_021DC9CC(void *task,u32 *state,char *p)
{
    u32 index=((Cur *)p)->col+((Cur *)p)->row*4;
    int here,there,mask;
    int x,y;
    u8 now,old;
    int col,row;
    switch(*state) {
    case 0:
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        W(0xae0)=0;
        if(index==H(0xade)) {
            func_0204B3DC((struct Obj *)P(0xaf0),0);
            func_021DA8B0(task,(u32)func_021DC08C);
            return;
        }
        *state=1;break;
    case 1:
        now=index&3;
        old=H(0xade)%4;
        here=((*(int *)(p+0xac8))==(index>>2));
        there=((*(int *)(p+0xac8))==((u32)H(0xade)>>2));
        mask=0;if(here) mask|=1;if(there) mask|=2;
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(mask<<13);
        if(here) {
            x=d_021DF86E[now*8];y=d_021DF86F[now*8];
            inside0(30,1);window0(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        if(there) {
            x=d_021DF86E[old*8];y=d_021DF86F[old*8];
            inside1(30,1);window1(x*8,y*8,(x+12)*8,(y+7)*8);
        }
        outside(30,0);*state=2;break;
    case 2:
        func_0207D658(0x04000050,30,W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=3;}break;
    case 3:
        func_021DBCC8((struct Obj *)p,index,H(0xade));func_020061E4(0x670);
        row=(u32)H(0xade)>>2;col=H(0xade)%4;
        there=((*(int *)(p+0xac8))==row);
        here=((*(int *)(p+0xac8))==(index>>2));
        if(here) {
            func_021DB938(p,1,W(0xacc));
            func_021DB54C(p,1,0,(*(int *)(p+0xac8)),W(0xacc),H(36));
        }
        if(there) {
            func_021DB938(p,1,col);
            func_021DB54C(p,1,0,row,col,H(36));
        }
        func_020409B4(3);W(0xa78)=1;*state=4;break;
    case 4:
        func_0207D658(0x04000050,30,16-W(0xae8)*16/30);
        if(W(0xae8)++>30) {W(0xae8)=0;*state=5;}break;
    case 5:*(volatile u32 *)0x04000000 &=~0xe000;*state=6;break;
    case 6:
        W(0xae0)=0;func_0204B3DC((struct Obj *)P(0xaf0),0);
        if(P(0xabc)) {func_021D9E04(P(0xabc));P(0xabc)=0;}
        func_021DA8B0(task,(u32)func_021DC08C);break;
    }
}

/*
 * lever: separate case-1 guard tests preserve the branch to the shared state store; a short-circuit guard gives DIFF404.
 */
void func_021DCCE4(void *arg,u32 *state,char *p)
{
    Desc_021DCCE4 d;
    int result;
    int ready;
    switch (*state) {
    case 0:
        *state=1;
        break;
    case 1:
        if (!((struct Obj00253 *)p)->f0) *state=5;
        else if (func_0200A0C8(((struct Obj00253 *)p)->fC)) *state=5;
        else *state=2;
        break;
    case 2:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,93,1);
        *state=3;
        break;
    case 3:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) {
            func_02082BCC(&d,0,36);
            d.v[0]=*(u32 *)&((struct Obj00253 *)p)->f1C;
            d.v[1]=*(u32 *)&((struct Obj00253 *)p)->f10;
            d.v[2]=*(u32 *)&((struct Obj00253 *)p)->f14;
            d.v[3]=124;
            d.v[4]=125;
            d.v[6]=2;
            d.a=0; d.b=15; d.c=13; d.d=1;
            ((struct Obj00253 *)p)->fAC0=func_021DA038((const u8 *)(&d),((struct Obj00253 *)p)->f24);
            *state=4;
        }
        break;
    case 4:
        result=func_021DA178(((struct Obj00253 *)p)->fAC0);
        ((struct Obj00253 *)p)->fBAC=0x7fff;
        if (result!=-1) {
            func_021DA148(((struct Obj00253 *)p)->fAC0);
            ((struct Obj00253 *)p)->fAC0=0;
            if (!result) *state=5;
            else {
                if (((struct Obj00253 *)p)->fABC) {
                    func_021D9E04(((struct Obj00253 *)p)->fABC);
                    ((struct Obj00253 *)p)->fABC=0;
                }
                func_021DA8B0(arg,(u32)func_021DC08C);
            }
        }
        break;
    case 5:
        if (((struct Obj00253 *)p)->fAD4) *state=6;
        else *state=10;
        break;
    case 6:
        if (!((struct Obj00253 *)p)->fABC) {
            ((struct Obj00253 *)p)->fABC=func_021D9CA4(0,15,((struct Obj00253 *)p)->f14,((struct Obj00253 *)p)->f10,29);
            func_021D9FFC(((struct Obj00253 *)p)->fABC,1,13);
        }
        func_021D9F08(((struct Obj00253 *)p)->fABC,((struct Obj00253 *)p)->f1C,115,2);
        *state=7;
        break;
    case 7:
        if (func_021D9FF8(((struct Obj00253 *)p)->fABC)) *state=8;
        break;
    case 8:
        ready=1;
        if (((struct Obj00253 *)p)->fAAC && !func_021DE014(((struct Obj00253 *)p)->fAAC)) ready=0;
        if (ready) {
            func_0200A2B8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20));
            *state=9;
        }
        break;
    case 9:
        if (func_0200A2D8(((struct Obj00253 *)p)->fC,(int)(((struct Obj00253 *)p)->f20))==2) *state=10;
        break;
    case 10:
        if (((struct Obj00253 *)p)->fABC) {
            func_021D9E04(((struct Obj00253 *)p)->fABC);
            ((struct Obj00253 *)p)->fABC=0;
        }
        func_021DA8B8(arg);
        break;
    }
    if (((struct Obj00253 *)p)->fABC) func_021D9E50(((struct Obj00253 *)p)->fABC);
}

void func_021DCEC4(void *arg,int *state,char *p)
{
    switch (*state) {
    case 0:
        if (!((struct Obj01930 *)p)->fABC)
            ((struct Obj01930 *)p)->fABC=func_021D9CA4(0,15,((struct Obj01930 *)p)->f14,((struct Obj01930 *)p)->f10,29);
        func_021D9FFC(((struct Obj01930 *)p)->fABC,1,13);
        func_021D9F08(((struct Obj01930 *)p)->fABC,((struct Obj01930 *)p)->f1C,92,1);
        *state=1; break;
    case 1:
        if (func_021D9FF8(((struct Obj01930 *)p)->fABC)) *state=2;
        break;
    case 2:
        if (((struct Obj01930 *)p)->fABC) {
            func_021D9E04(((struct Obj01930 *)p)->fABC);
            ((struct Obj01930 *)p)->fABC=0;
        }
        func_021DA8B0(arg,(u32)func_021DC08C);
        break;
    }
    if (((struct Obj01930 *)p)->fABC) func_021D9E50(((struct Obj01930 *)p)->fABC);
}

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DCF54(char *p,void *arc,int id,int index,u8 other,u16 heap)
{
    void *res;
    void *allocation;
    char *data;
    func_02082BCC(p,0,0x60);
    allocation=func_02049F78(arc,id,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22906 *)res)->fC;
    func_02082D44(data+index*32,p+0x40,32);
    func_02082D44(data+other*32,p+0x20,32);
    func_020307B0(allocation);
}

void func_021DCFA4(u8 *p,int b,int c,u16 d) {func_021DAB50((void *)b,(u16 *)p,d,c,(const u16 *)(p+32),(const u16 *)(p+64));}

/*
 * lever: const descriptor input places its loads before the outgoing heap store.
 * interfaces: D81C/D898 scalar stack words reproduce the aggregate layout; complete bodies and forwarding targets read no padding, key only low halfword.
 */
void *func_021DCFC8(const Desc_021DCFC8 *p,u16 heap)
{
    char *out;
    Config config;
    Record_021DCFC8 first;
    Record_021DCFC8 second;
    void *arc;
    void *arc2;
    out=func_02030734(heap,208,0,d_021DFBB0,0xcff);
    ((struct Obj00237 *)out)->f88=p->w[5];
    ((struct Obj00237 *)out)->f94=p->w[0];
    ((struct Obj00237 *)out)->f96=p->w[1];
    *(Desc_021DCFC8 *)(out+0xa0)=*p;
    if(p->w[0]<4) {
        ((struct Obj00237 *)out)->f9C=0;
        ((struct Obj00237 *)out)->f98=0;
        ((struct Obj00237 *)out)->f84=1;
    } else {
        ((struct Obj00237 *)out)->f9C=4;
        ((struct Obj00237 *)out)->f98=1;
        ((struct Obj00237 *)out)->f84=0;
    }
    config=d_021DF99C;
    ((struct Obj00237 *)out)->f0=func_021DA1BC((void *)1,(const char *)&config,5,((struct Obj00237 *)out)->fA4,((struct Obj00237 *)out)->fAC,((struct Obj00237 *)out)->fC8,((struct Obj00237 *)out)->fC0,((struct Obj00237 *)out)->fC4,heap);
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj00237 *)out)->f4=func_0204ABF0(arc,3,((struct Obj00237 *)out)->f98,(u16)(p->w[4]<<5),heap);
    *(int *)&((struct Obj00237 *)out)->fC=func_0204AF28(arc,33,36,heap);
    *(int *)&((struct Obj00237 *)out)->f8=func_0204A6C8(arc,12,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc);
    func_02082BCC(&first,0,8);
    first.x=216;first.y=22;
    ((struct Obj00237 *)out)->f1C=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f8,((struct Obj00237 *)out)->f4,((struct Obj00237 *)out)->fC,&first,((struct Obj00237 *)out)->f98,heap);
    func_0204B688(((struct Obj00237 *)out)->f1C,0);
    func_0204B3DC(((struct Obj00237 *)out)->f1C,0);
    arc2=(void *)func_0202D7C8(heap);
    *(int *)&((struct Obj00237 *)out)->f10=func_0202D7D8((int)arc2,1,0,0,0,0,0,((struct Obj00237 *)out)->f98,p->w[5]<<5,heap);
    *(int *)&((struct Obj00237 *)out)->f18=func_0202D898(1,0,0,0,0,0,2,((struct Obj00237 *)out)->f98,heap);
    *(int *)&((struct Obj00237 *)out)->f14=func_0202D81C(arc2,1,0,0,0,0,0,0,((struct Obj00237 *)out)->f98,heap);
    func_02049238(arc2);
    func_02082BCC(&second,0,8);
    second.x=184;second.y=112;second.b=p->w[0]&3;
    ((struct Obj00237 *)out)->f8C=second.b;
    ((struct Obj00237 *)out)->f90=p->w[1]&3;
    ((struct Obj00237 *)out)->f20=func_0204B294((void *)p->w[6],((struct Obj00237 *)out)->f14,((struct Obj00237 *)out)->f10,((struct Obj00237 *)out)->f18,&second,((struct Obj00237 *)out)->f98,heap);
    func_0204B570(((struct Obj00237 *)out)->f20,2);
    func_0204B688(((struct Obj00237 *)out)->f20,1);
    func_0204B3DC(((struct Obj00237 *)out)->f20,0);
    return out;
}

void func_021DD1FC(void **p)
{
    func_0204B3B4(p[8]);
    func_0204A8D4((u32)p[5]);
    func_0204AFD8((u32)p[6]);
    func_0204ADA4((u32)p[4]);
    func_0204B3B4(p[7]);
    func_0204A8D4((u32)p[2]);
    func_0204AFD8((u32)p[3]);
    func_0204ADA4((u32)p[1]);
    func_021DA280(p[0]);
    func_020307B0(p);
}

int func_021DD240(void **p) {return func_021DA2C8(*p);}


struct Out *func_021DD24C(Record_021DD24C *a, struct CtxB *b, void *c, u16 heap)
{
    struct Out *out;
    struct Ctx ctx;
    Desc_021DD24C desc;
    void *res;
    u16 idx;
    void *t4;
    int flags;
    void *mon;
    void *gs;
    u8 day;
    u32 month;
    u16 year;
    u32 mode;
    u32 gender;
    u64 rnd;
    u32 species;
    u16 level;
    u16 hid;
    u32 id16;
    u32 id;
    u64 id64;

    out = func_02030734(heap, 0x148, 0, d_021DFBB0, 0xDD4);
    func_02082BCC(out, 0, 0x148);
    out->heap = heap;
    out->a = (struct Rec *)a;
    out->b = b;
    out->c = c;
    func_02082BCC(&ctx, 0, 0x24);
    ctx.f0 = 0;
    ctx.f8 = b->fB8;
    ctx.fC = b->fBC;
    ctx.f10 = b->fC4;
    ctx.f14 = b->fC8;
    ctx.f18 = b->fCC;
    ctx.f1C = b->fC0;
    ctx.f20 = (u32)c;
    func_021DBDF4(out, a, &ctx, heap);
    desc = d_021DFA14;
    id16 = (heap & 0x7fff) | 0x8000;
    desc.e[1].f8 = func_020457B0(0x25, (u16)id16);
    func_02045994(desc.e[1].f8, (const u16 *)((char *)out->a + 0x60), 0x24);
    if (out->a->fB4b)
        idx = out->a->fB2 + 0x19d;
    else
        idx = out->a->fB2 + 0x9d;
    desc.e[2].f8 = func_02045EC0((void *)b->fC0, idx);
    desc.e[4].f8 = func_020457B0(0x80, heap);
    flags = out->a->fAC;
    t4 = func_02045EC0((void *)b->fC0, 0x9a);
    res = 0;
    func_0201EFA4((void *)b->fCC, 0, (u16)(flags >> 16), 4, 1, 1);
    func_0201EFA4((void *)b->fCC, 1, (u8)(flags >> 8), 2, 0, 1);
    func_0201EFA4((void *)b->fCC, 2, (u8)flags, 2, 0, 1);
    func_0201F250((void *)b->fCC, desc.e[4].f8, t4);
    out->f144 = func_021DA338(*(void **)b, heap);
    func_021DA3EC(out->f144, (char *)(&desc), (void *)b->fC8);
    func_02045808(desc.e[1].f8);
    func_02045808(desc.e[2].f8);
    func_02045808(desc.e[4].f8);
    func_02045808(t4);
    if (func_021DC024(out) == 1) {
        struct Rec *r = out->a;
        u16 mv[4];
        u8 iv[6];
        int i;
        u32 k;
        u32 ivs;

        gs = out->c;
        hid = id16;
        level = r->f5B;
        id = r->f0;
        species = r->species;
        gender = r->f35;
        mode = r->f36;

        iv[0] = r->iv0;
        iv[1] = r->iv1;
        iv[2] = r->iv2;
        iv[3] = r->iv7;
        iv[4] = r->iv3;
        iv[5] = r->iv6;
        mv[0] = r->mv[0];
        mv[1] = r->mv[1];
        mv[2] = r->mv[2];
        mv[3] = r->mv[3];
        if (r->fB3 == 1 && species <= 0x289 && species != 0 && level <= 0x64 && r->f10 <= 0x289 - 0x17) {
            if (level == 0)
                level = (u16)(func_020056EC(0x64) + 1);
            if (r->f0 == 0)
                id = func_02008530((const struct Sub0200852CObj *)func_02012944(gs));
            if (gender == 0xff)
                gender = 2;
            for (i = 0; i < 6; i++) {
                if (iv[i] == 0xff)
                    iv[i] = func_020056EC(0x20);
            }
            id64 = id;
            mon = func_020173F0((u16)species, level, id, 0, hid);
            ivs = (iv[0] & 31) | ((iv[1] & 31) << 5) | ((iv[2] & 31) << 10) | ((iv[3] & 31) << 15) | ((iv[4] & 31) << 20) | ((iv[5] & 31) << 25);
            if (mode == 4)
                mode = (u8)func_020056EC(3);
            switch (mode) {
            case 0:
                i = 0;
                break;
            case 1:
                i = 1;
                break;
            case 2:
                i = 0;
                break;
            case 3:
                i = 2;
                break;
            default:
                res = 0;
                goto end;
            }
            if (r->f8 != 0)
                rnd = r->f8;
            else {
                if (r->f37 == 0)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 0);
                else if (r->f37 == 1)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 2);
                else if (r->f37 == 2)
                    rnd = func_020186C8(id, (u16)species, r->form, gender, i, 1);
            }
            func_02017588(mon, r->species, level, id64, ivs, rnd);
            func_02017E40(mon, 6, r->f10);
            func_02017FA8(mon);
            for (i = 0; i < 4; i++) {
                u16 m = mv[i];
                if (m != 0 && m < 0x230) {
                    if (func_0201808C(mon, m) == 0xffff)
                        func_020180F4(mon, m);
                }
            }
            if (r->f8 == 0 && mode == 2)
                func_02018A00(mon, species, r->form);
            func_02017E40(mon, 0x6f, r->form);
            if (r->fE != 0 && r->fE <= 0x19)
                func_02017E40(mon, 0x98, r->fE);
            else
                func_02017E40(mon, 0x98, 4);
            if (r->f3C != 0)
                func_02017E40(mon, 0x99, r->f3C);
            func_02017E40(mon, 0x13, r->f3D);
            func_02017E40(mon, 0x14, r->f3E);
            func_02017E40(mon, 0x15, r->f3F);
            func_02017E40(mon, 0x16, r->f40);
            func_02017E40(mon, 0x17, r->f41);
            func_02017E40(mon, 0x18, r->f41);
            for (k = 0; k < 15; k++) {
                if (r->fC & (1 << k))
                    func_02017E40(mon, d_021DF8C0[k], 1);
            }
            if (r->f4 == 0)
                func_02017E40(mon, 0x77, g0209DF08);
            else
                func_02017E40(mon, 0x77, r->f4);
            if (r->f1D == 0)
                func_02017E40(mon, 0xc, g0209DF0C);
            else
                func_02017E40(mon, 0xc, r->f1D);
            if (r->f1E == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f1E != func_02045A98())
                func_02017E40(mon, 0x74, (u32)&r->f1E);
            {
                u32 v = r->f34;
                if (v == 0xff)
                    v = (u8)func_020056EC(0x19);
                func_02017E40(mon, 0x70, v);
            }
            func_02017E40(mon, 0x95, r->f38);
            func_02017E40(mon, 0x96, r->f3A);
            if (r->f4A == 0) {
                func_020307B0(mon);
                res = 0;
                goto end;
            }
            if (r->f4A == func_02045A98())
                func_02017E40(mon, 0x8e, (u32)func_020084F4(func_02012944(gs)));
            else
                func_02017E40(mon, 0x8e, (u32)&r->f4A);
            {
                u32 v = r->f5A;
                if (v <= 2)
                    func_02017E40(mon, 0x9a, v);
                else {
                    v = func_02008550((const struct Sub0200852CObj *)func_02012944(gs));
                    func_02017E40(mon, 0x9a, v);
                }
            }
            if (r->f5C != 0) {
                void *s;
                func_02017E40(mon, 0x4c, 1);
                s = func_02045EC0(gMsgBank, 0x28a);
                func_02017E40(mon, 0x73, (u32)s);
                func_02045808(s);
                func_02017E40(mon, 9, 10);
            }
            {
                int w = r->fAC;
                u32 loc;
                year = w >> 16;
                month = (u8)(w >> 8);
                day = w;
                loc = r->f5C ? r->f38 : r->f3A;
                func_0202F2AC(func_020185F0(mon), loc, year - 2000, month, day);
            }
            func_020185C4(mon);
            res = 0;
            if (func_02017E1C(mon, 3, 0) != 0)
                func_020307B0(mon);
            else
                res = mon;
            goto end;
        }
    end:
        {
            void *arc = (void *)func_0202D7C8((u16)id16);
            u32 a0, a1, a2, a3;
            out->fE4 = r->species;
            out->fE6 = r->form;
            out->fE0 = r->f5C;
            a0 = func_0202D060();
            a1 = func_02017E1C(res, 5, 0);
            a2 = func_02017E1C(res, 0x6f, 0);
            a3 = func_02017E1C(res, 0x6e, 0);
            idx = func_0202D0D4(a0, a1, a2, a3, func_02017EAC(res), 0, func_02017E1C(res, 0x4c, 0));
            out->f13C = func_02049F78(arc, idx, (u32)(&out->f140), out->heap);
            out->f134 = (u32)func_0202D6F4(&out->f138, func_020185F4(res), 0, out->heap);
            func_020307B0(res);
            func_02049238(arc);
        }
    }
    return out;
}
