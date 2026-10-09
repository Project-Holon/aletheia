/*
 * file:     br_codein_p03.c
 * unit:     yes
 * function: func_021DF41C, func_021DF428, func_021DF5B8, func_021DF620, func_021DF838, func_021DF8F0, func_021DF920, func_021DF9C8, func_021DFA10, func_021DFB90, func_021DFC88, func_021DFCD4, func_021DFE98, func_021DFF78, func_021DFFB0, func_021E0044, func_021E0080, func_021E009C, func_021E00D8, func_021E0214, func_021E024C, func_021E02F8, func_021E037C, func_021E03B0, func_021E04C8, func_021E050C, func_021E05C4, func_021E0618
 * address:  0x021DF41C
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
 *   func_021FCDA8 0x021FCDA8 thumb ov186
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B714 0x0204B714 arm
 *   func_0204B784 0x0204B784 arm
 *   func_02049E74 0x02049E74 arm
 *   func_0204A9D0 0x0204A9D0 arm
 *   func_0204AB84 0x0204AB84 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200B98C 0x0200B98C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_0201C440 0x0201C440 thumb
 *   func_02025538 0x02025538 thumb
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   d_021E37A8 0x021E37A8 data a4
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_02012944 0x02012944 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021FB4CC 0x021FB4CC thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   d_021E3758 0x021E3758 data a4
 *   d_021E3728 0x021E3728 data a4
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021FFBD4 0x021FFBD4 thumb ov186
 *   func_021FFE5C 0x021FFE5C thumb ov186
 *   func_021FFE34 0x021FFE34 thumb ov186
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_021FFC9C 0x021FFC9C thumb ov186
 *   func_021FFE90 0x021FFE90 thumb ov186
 *   func_0201F898 0x0201F898 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_02025B64 0x02025B64 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   d_021E3780 0x021E3780 data a4
 *   d_021E372E 0x021E372E data a4
 *   func_021FC868 0x021FC868 thumb ov186
 *   d_021E37D8 0x021E37D8 data ov183
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   d_020A7370 0x020A7370 data a4
 *   g_021E3808     0x021E3808  data  ov183
 *   func_021E07A4 0x021E07A4 thumb ov183
 *   func_021E06D0 0x021E06D0 thumb ov183
 *   func_021E0774 0x021E0774 thumb ov183
 *   func_021E0808 0x021E0808 thumb ov183
 *   func_021E0754 0x021E0754 thumb ov183
 *   func_021E075C 0x021E075C thumb ov183
 *   func_021E0764 0x021E0764 thumb ov183
 */
#include "../../matched/include/Obj24619.h"
#include "../../matched/include/Obj02522.h"
#include "../../matched/include/Obj01765.h"
#include "../../matched/include/Obj02230.h"
#include "../../matched/include/Obj10749.h"
#include "../../matched/include/Obj14433.h"
#include "../../matched/include/Obj05476.h"
#include "../../matched/include/Obj05477.h"
#include "../../matched/include/Obj05478.h"
#include "../../matched/include/Obj24620.h"
#include "../../matched/include/Obj00277.h"
#include "../../matched/include/Obj00351.h"
#include "../../matched/include/Obj02523.h"
#include "../../matched/include/Obj04571.h"
#include "../../matched/include/Obj04572.h"
#include "../../matched/include/Obj24621.h"
#include "../../matched/include/Obj04573.h"
#include "../../matched/include/Obj08315.h"
#include "../../matched/include/Obj14434.h"
#include "../../matched/include/Obj02231.h"
#include "../../matched/include/Obj03330.h"
#include "../../matched/include/Obj04574.h"
#include "../../matched/include/Obj24622.h"
#include "../../matched/include/Obj24623.h"
#include "../../matched/include/Obj01767.h"
#include "../../matched/include/Obj04576.h"

struct Actor;
struct Obj;
struct Struct36;
struct Sub0204A9D0;
struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
struct Sub0200852CObj;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Object;
struct Source;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

struct State_021DF428 { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };

struct Pos { u16 x; short y; u16 z; u8 a,b; };

struct Entries { u32 species[6],form[6],gender[6]; };

typedef signed int     s32;

struct W { char pad[0x18]; u16 handles[5][6]; char gap[4]; void *objects[5][6]; };

struct State_021DF620 { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; char *sprites[5][6]; void *source; };

struct Rec { u32 w[9]; };

struct Sub { u8 pad[16]; u32 size,data; };

typedef int (*Method)(char *,int *);

struct Methods { Method init,update,finish; };

struct Request { u16 x,y,id; u8 flag,pad; };

struct Rec6 { u8 x,y,id,pad; u16 file; };

struct Rec8 { u8 a,b,c,d; void *value; };

struct Triple { int a,b,c; };

typedef struct {u32 words[10];} Config;

typedef struct {int a,b,c;} Triple;

typedef struct {u16 a,b,c;u8 flag,pad;} Params;

typedef struct {u8 a,b,c,d;u16 file,pad;} Record_021DF41C;

typedef struct Slot Slot;

typedef struct {u8 a,b,c,d;u16 file;} Record_021E009C;

struct Record_021E009C { u8 a, b, c, d; int value; };

typedef struct Rect { unsigned int x0, y0, x1, y1; } Rect;

struct Data { void *a, *b, *c, *d; u16 heap; u16 pad; void *e; };

typedef unsigned long long u64;

extern int func_021FCDA8(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void * func_02082BCC(void *,u32,u32);
extern u32 func_0201BABC(u32,u32,u32,u32),func_0201BB5C(u32,u32,u32,u32);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02049238(void *);
extern void func_0204AFD8(unsigned int);
extern void func_0204ADA4(unsigned int);
extern void func_0204A8D4(unsigned int);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_0204B714(struct Obj *o);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern void *func_02049E74(void *,u32,u32,u32,u16);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern void func_0204AB84(u32,struct Rec *);
extern u32 func_020307B0(void *p);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_020061E4(u32 a);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern u32 func_0201C440(void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD170(char *p, char *q, void *text);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern void func_021FBE54(char *base, u32 idx, u32 area);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FD820(char *);
extern void func_021FD15C(void *, int);
extern void func_02025588(void *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_021FE784(int,int,int,int);
extern int func_021FE7B0(int *);
extern int func_021FC830(u8 *p);
extern void func_021FD1BC(void *);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021FD854(char *);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern int func_021FC124(int,int,struct Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_021FD860(int,int,int *);
extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern int func_021FB4CC(u32 *p, int a1, int a2);
extern void func_021F9BA0(unsigned *ctx);
extern void func_021F9BF4(unsigned *,unsigned);
extern Slot *func_0201F81C(u32,u32);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern void *func_021FC8C8(Config *,u32);
extern void func_021FCC80(char *p);
extern u32 func_0201F868(void *p);
extern void func_021FCD0C(char *p);
extern void *func_0200CA1C(void *);
extern char *func_021FFBD4(void *, void *, int, int, int, int, int, u16);
extern void func_021FFE5C(char *);
extern unsigned func_021FFE34(char *p);
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern int func_021FFC9C(char *);
extern int func_021FFE90(int *, u16 *);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021FC21C(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 func_02025B64(u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC7C4(char *,void *,void *,u16);
extern struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries);
extern char *func_021E06D0(const struct Source *src, u16 heap);
extern void func_021E0774(char *p);
extern void func_021E0808(char *p);
extern void func_021E0754(char *p);
extern int func_021E075C(char *p);
extern unsigned long long func_021E0764(char *p);
int func_021DF41C(char *p);
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap);
void func_021DF5B8(char *p);
void func_021DF620(struct State_021DF620 *p,int first,short step,u16 heap);
void func_021DF838(int p, char *out);
int func_021DF8F0(int x, int y);
int func_021DF920(void *obj, int unused, char *q);
int func_021DF9C8(void *p, int unused, char *q, char *data);
int func_021DFA10(void *unused,u32 *state,int *q,char *p);
int func_021DFB90(char *p,char *q);
int func_021DFC88(char *p, char *q);
int func_021DFCD4(char *p,char *q);
int func_021DFE98(char *p,char *q);
int func_021DFF78(char *p, char *q);
int func_021DFFB0(char *p, char *q);
void func_021E0044(char *p, char *q);
int func_021E0080(char *p);
int func_021E009C(char *p, char *q);
int func_021E00D8(char *p,char *q);
int func_021E0214(char *p, char *q);
int func_021E024C(char *p, char *q);
void func_021E02F8(char *p, int *q);
void func_021E037C(char *p,char *q);
void func_021E03B0(char *p,char *q,int mode);
int func_021E04C8(void);
int func_021E050C(void *task, int unused, char *q);
int func_021E05C4(void *a, int unused, int *q, void **p);
int func_021E0618(int unused, int *state, int *q, int *p);
extern const struct Methods d_021E37A8[];
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern const Config d_021E3758;
extern const Record_021DF41C d_021E3728[];
extern const Config d_021E3780;
extern const Record_021E009C d_021E372E[];
extern const struct Record_021E009C d_021E37D8[];
extern int d_020A7370;
extern Rect g_021E3808[];




int func_021DF41C(char *p)
{
    return func_021FCDA8(*(char * *)&((struct Obj24619 *)p)->f4);
}




/*
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 */
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(p->source+0x1718);
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    i=0;
    p->shared0=func_0204ACEC(archive,func_0201BC3C(),0,0x80,heap);
    p->shared1=func_0204AF28(archive,func_0201BC40(),func_0201BCB4(),heap);
    func_02082BCC(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        func_021DF838((int)(p->source+i*0xc4),(char *)(&e));
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            p->indices[i][j]=func_0204A6C8(archive,func_0201BABC(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            p->sprites[i][j]=func_0204B294((void *)mgr,p->indices[i][j],p->shared0,p->shared1,&pos,0,heap);
            func_0204B6F4(p->sprites[i][j],func_0201BB5C(species,e.form[j],e.gender[j],0),0);
            func_0204B688(p->sprites[i][j],1);
            if(e.species[j]==0) func_0204B3DC(p->sprites[i][j],0);
            else func_0204B3DC(p->sprites[i][j],1);
        }
    }
    func_02049238(archive);
}




/*
 * trailing: two zero alignment bytes at 0x021DF61E
 * lever: padded struct array members prevent caching the element cursor across calls.
 */
void func_021DF5B8(char *p)
{
    int i, j;
    func_0204AFD8(((struct Obj02522 *)p)->f16);
    func_0204ADA4(((struct Obj02522 *)p)->f14);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 6; j++) {
            if (((struct W *)p)->objects[i][j] != 0) {
                func_0204A8D4(((struct W *)p)->handles[i][j]);
                func_0204B3B4(((struct W *)p)->objects[i][j]);
                ((struct W *)p)->objects[i][j] = 0;
            }
        }
    }
}




/*
 * Lever: short step spills first; i remains live after the first loop and
 * supplies the second loop's row; forward/back/loaded declaration order
 * gives the three 36-byte buffers at sp+7c, sp+58, sp+34.
 */
void func_021DF620(struct State_021DF620 *p,int first,short step,u16 heap)
{
    int i,j;
    char *src,*dst;
    u32 value;
    void *archive,*handle;
    struct Sub *data;
    struct Rec forward,back,loaded;
    struct Entries entries;
    u32 mode;
    for(i=0;i<5;i++) {
        for(j=0;j<6;j++) {
            if(step==1 && i!=4) {
                src=p->sprites[i+1][j]; dst=p->sprites[i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    func_0204B7C8(src,(struct Struct36 *)(&forward));
                    value=func_0204B714((struct Obj *)src);
                    func_0204B784(dst,(const struct Struct36 *)(&forward));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            } else if(step==-1 && i!=4) {
                src=p->sprites[3-i][j]; dst=p->sprites[4-i][j];
                if(func_0204B3F4((struct Obj *)src)) {
                    func_0204B7C8(src,(struct Struct36 *)(&back));
                    value=func_0204B714((struct Obj *)src);
                    func_0204B784(dst,(const struct Struct36 *)(&back));
                    func_0204B6F4((struct Obj *)dst,value,0);
                    func_0204B3DC((struct Obj *)dst,1);
                } else func_0204B3DC((struct Obj *)dst,0);
            }
        }
    }
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    if(step==-1) { --p->cursor; if(p->cursor<0) p->cursor=4; }
    for(j=0;j<6;j++) {
        if(step==1) i=4; else if(step==-1) i=0;
        func_021DF838((int)((u32)p->source+(i+first)*0xc4),(char *)&entries);
        if(entries.species[j]) {
            handle=func_02049E74(archive,func_0201BABC(entries.species[j],entries.form[j],entries.gender[j],0),0,(u32)&data,mode);
            func_0204A9D0(p->indices[p->cursor][j],(struct Sub0204A9D0 *)data);
            func_0204AB84(p->indices[p->cursor][j],&loaded);
            func_0204B784(p->sprites[i][j],(const struct Struct36 *)(&loaded));
            func_0204B6F4((struct Obj *)p->sprites[i][j],func_0201BB5C(entries.species[j],entries.form[j],entries.gender[j],0),0);
            func_020307B0(handle);
            func_0204B3DC((struct Obj *)p->sprites[i][j],1);
        } else func_0204B3DC((struct Obj *)p->sprites[i][j],0);
    }
    if(step==1) { ++p->cursor; if(p->cursor>4) p->cursor=0; }
    func_02049238(archive);
}




/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 * + *   typedef unsigned char u8;
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
 * checks: 1 full callee reads 3 args, 64-bit return; 2 no filed twin; 3 int base/long index unchanged (2/2); 4 named base and second declaration order close DIFF (2/2); 5 fresh idiom/neighbour reread, no stack-object residue. Both reorder variants consumed.
 */
void func_021DF838(int p, char *out)
{
    long i;
    int a, b, c;
    void *base;
    int special, n = 0;
    unsigned int count;
    func_02082BCC(out, 0, 0x48);
    base = (void *)(p + 0x80);
    switch ((int)func_0200B98C(base, 3, 0)) {
    case 16: case 17: case 18: case 19: case 22:
        special = 1;
        count = 9;
        break;
    default:
        special = 0;
        count = 6;
        break;
    }
    for (i = 0; i < count; i++) {
        if (special && i >= 3 && i <= 5) continue;
        a = func_0200B98C(base, 0, i);
        b = func_0200B98C(base, 1, i);
        c = func_0200B98C(base, 6, i);
        if (a >= 0x28B) a = 0;
        if (a != 0) {
            *(int *)(out + n * 4) = a;
            *(int *)(out + n * 4 + 0x18) = b;
            *(int *)(out + n * 4 + 0x30) = c;
            n++;
        }
    }
}




int func_021DF8F0(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) func_020061E4(0x703);
    return ok;
}




int func_021DF920(void *obj, int unused, char *q)
{
    char *p;
    int i;
    p = func_0203159C(obj, 0x58, func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC)));
    func_02082BCC(p, 0, 0x58);
    ((struct Obj01765 *)p)->f54 = func_021F9B9C((struct Obj24810 *)(*(char * *)&((struct Obj02230 *)q)->fC));
    ((struct Obj01765 *)p)->f48 = (void *)func_0201C440((void *)(((struct Obj01765 *)p)->f54));
    ((struct Obj01765 *)p)->f44 = func_02025538(((struct Obj01765 *)p)->f54, ((struct Obj02230 *)q)->f4);
    ((struct Obj01765 *)p)->f38 = (int)func_021FD12C(((struct Obj02230 *)q)->f8, (void *)(*(int *)&((struct Obj01765 *)p)->f48), ((struct Obj01765 *)p)->f54);
    func_021FD170((char *)(((struct Obj01765 *)p)->f38), (char *)(((struct Obj02230 *)q)->f8), (void *)0x6B);
    for (i = 0; i < 2; i++) {
        *(int *)(p + i * 4 + 0x3C) = (int)func_021FD760(*(int *)&((struct Obj02230 *)q)->f4, (char *)(((struct Obj02230 *)q)->f8), i, ((struct Obj01765 *)p)->f54);
    }
    ((struct Obj02230 *)q)->f14 = 0xFFFF;
    ((struct Obj02230 *)q)->f16 = 0xFF;
    ((struct Obj02230 *)q)->f17 = 0xFF;
    ((struct Obj02230 *)q)->f18 = 0x13;
    func_021FBE54((char *)(((struct Obj02230 *)q)->f8), 6, ((struct Obj01765 *)p)->f54);
    func_021E02F8(p, (int *)q);
    return 1;
}




int func_021DF9C8(void *p, int unused, char *q, char *data)
{
    int i;
    func_021E037C(data, q);
    func_021FC0C8((char *)(((struct Obj14433 *)q)->f8), 6);
    for (i = 0; i < 2; i++) func_021FD820(*(char **)(data + i * 4 + 0x3c));
    func_021FD15C(((struct Obj10749 *)data)->f38, ((struct Obj14433 *)q)->f8);
    func_02025588(((struct Obj10749 *)data)->f44);
    func_0201C4C0(((struct Obj10749 *)data)->f48);
    func_020315D4(p);
    return 1;
}




int func_021DFA10(void *unused,u32 *state,int *q,char *p)
{
    int i;
    switch(*state) {
    case 0: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 1: func_021FE784(q[0],2,3,0); ++*state; break;
    case 2: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 3: if(d_021E37A8[*(int *)(p+0x4c)].update(p,q)) {
        if(((struct Obj05476 *)p)->f50==-1) *state=10; else *state=4;
    } break;
    case 4: func_021FE784(q[0],2,2,1); ++*state; break;
    case 5: if(func_021FE7B0((int *)q[0])) ++*state; break;
    case 6: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) {
        ((struct Obj05476 *)p)->f4C=((struct Obj05476 *)p)->f50; ++*state;
    } break;
    case 7: if(d_021E37A8[*(int *)(p+0x4c)].init(p,q)) ++*state; break;
    case 8: func_021FE784(q[0],2,2,0); ++*state; break;
    case 9: if(func_021FE7B0((int *)q[0])) *state=3; break;
    case 10: func_021FE784(q[0],2,3,1); ++*state; break;
    case 11: if(func_021FE7B0((int *)q[0])) *state=12; break;
    case 12: if(d_021E37A8[*(int *)(p+0x4c)].finish(p,q)) return 1; break;
    }
    for(i=0;i<3;i++) if(*(void **)(p+i*4)) func_021FC830(*(void **)(p+i*4));
    for(i=0;i<6;i++) if(*(void **)(p+0x20+i*4)) func_021FC830(*(void **)(p+0x20+i*4));
    if(((struct Obj05476 *)p)->f38) func_021FD1BC(((struct Obj05476 *)p)->f38);
    func_0201C4E4(((struct Obj05476 *)p)->f48);
    for(i=0;i<2;i++) func_021FD854(*(char **)(p+0x3c+i*4));
    return 0;
}




int func_021DFB90(char *p,char *q)
{
    int first,second,i;
    struct Request req;
    struct Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=func_021FC20C(*(char * *)&((struct Obj05478 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj05478 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj05478 *)q)->f8),26,((struct Obj05477 *)p)->f54);
    func_02082BCC(&req,0,8);
    func_021FC124(*(int *)&((struct Obj05478 *)q)->f8,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.x=r->x; req.y=r->y; req.id=r->id; req.flag=1;
        *(void **)(p+0xc+i*4)=func_021FB378(&req,r->file,0x60,1,((struct Obj05478 *)q)->f4,((struct Obj05477 *)p)->f44,first,second,&triple,((struct Obj05477 *)p)->f54);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)(p+i*4)=func_021FC6A4(4,s->a,s->b,s->c,s->d,14,((struct Obj05477 *)p)->f48,((struct Obj05477 *)p)->f54);
        func_021FC754(*(char **)(p+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    func_021FD170(((struct Obj05477 *)p)->f38,(char *)(*(int *)&((struct Obj05478 *)q)->f8),(void *)107);
    return 1;
}




int func_021DFC88(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (*(void **)(p + i * 4) != 0) {
            func_021FC734(*(void **)(p + i * 4));
            *(void **)(p + i * 4) = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(void **)(p + i * 4 + 12) != 0) {
            func_021FB494(*(void **)(p + i * 4 + 12));
            *(void **)(p + i * 4 + 12) = 0;
        }
    }
    func_020409B4(4);
    func_021FBDA4(((struct Obj24620 *)q)->f8, 26);
    return 1;
}



/*
 * lever: A separate result!=3 guard around the three-case switch removes the extra 8-byte dense dispatch (460 to 452 B).
 */
int func_021DFCD4(char *p,char *q)
{
    int result=func_021E04C8();
    if(result!=3) {
    switch(result) {
    case 0: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f18=19;
        func_021E03B0(p,q,0);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)105);
        ((struct Obj00277 *)p)->f50=1;
        return 1;
    }
    case 1: {
        u32 x,y;
        int args[2];
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        ((struct Obj00351 *)q)->f14=0xffff;
        func_021E03B0(p,q,1);
        func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)106);
        ((struct Obj00277 *)p)->f50=2;
        return 1;
    }
    case 2: {
        void *v;
        int a,b;
        u32 x,y;
        int args[2];
        v=func_02012944(((struct Obj00351 *)q)->f10);
        a=func_0200856C(v);b=func_02008570(v);
        if(!a && !b) {
            func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)120);
            func_020061E4(0x704);
            break;
        }
        func_02035D20(&x,&y);args[0]=x;args[1]=y;
        func_021FD860(((struct Obj00277 *)p)->f40,1,args);
        func_020061E4(0x703);
        if(((struct Obj00351 *)q)->f16==255){((struct Obj00351 *)q)->f16=a;((struct Obj00351 *)q)->f17=b;}
        else{((struct Obj00351 *)q)->f16=255;((struct Obj00351 *)q)->f17=255;}
        func_021E03B0(p,q,2);
        return 0;
    }
    }
    }
    {
        u32 x,y;
        if(func_02035D20(&x,&y)) {
            if(func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC),x,y)) {
                int args[2];
                args[0]=x;args[1]=y;
                func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                ((struct Obj00277 *)p)->f50=-1;
                func_021F9BA0(((struct Obj00351 *)q)->fC);
                return 1;
            }
            if(func_021FB4CC((u32 *)(((struct Obj00277 *)p)->f10),x,y)) {
                if(((struct Obj00351 *)q)->f14!=0xffff || ((struct Obj00351 *)q)->f17!=255 || ((struct Obj00351 *)q)->f18!=19) {
                    int args[2];
                    args[0]=x;args[1]=y;
                    func_020061E4(0x703);
                    func_021FD860(((struct Obj00277 *)p)->f40,1,args);
                    ((struct Obj00277 *)p)->f50=-1;
                    func_021F9BF4(*(unsigned * *)&((struct Obj00351 *)q)->fC,5);
                    return 1;
                }
                func_020061E4(0x704);
                func_021FD170(((struct Obj00277 *)p)->f38,(char *)(*(int *)&((struct Obj00351 *)q)->f8),(void *)108);
            }
        }
    }
    return 0;
}



int func_021DFE98(char *p,char *q)
{
    int first,second,i;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj04571 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj04571 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj04571 *)q)->f8),27,((struct Obj02523 *)p)->f54);
    *(Slot * *)&((struct Obj02523 *)p)->f14=func_0201F81C(19,((struct Obj02523 *)p)->f54);
    for(i=0;i<19;i++)func_0201F878((Slot *)((u32)*(Slot * *)&((struct Obj02523 *)p)->f14+i*8),second,i+205,i,((struct Obj02523 *)p)->f54);
    cfg=d_021E3758;
    cfg.words[0]=*(u32 *)&((struct Obj02523 *)p)->f14;cfg.words[1]=19;
    cfg.words[5]=*(u32 *)&((struct Obj04571 *)q)->f8;cfg.words[6]=((struct Obj04571 *)q)->f4;
    ((struct Obj02523 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02523 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)&((struct Obj04571 *)q)->f8, 6, (struct Triple *)&triple);
    params.a=d_021E3728[0].a;params.b=d_021E3728[0].b;params.c=d_021E3728[0].c;params.flag=1;
    ((struct Obj02523 *)p)->fC=func_021FB378(&params,d_021E3728[0].file,96,1,*(int *)&((struct Obj04571 *)q)->f4,((struct Obj02523 *)p)->f44,first,second,&triple,((struct Obj02523 *)p)->f54);
    return 1;
}



int func_021DFF78(char *p, char *q)
{
    if (((struct Obj04572 *)p)->fC) {
        func_021FB494(((struct Obj04572 *)p)->fC);
        ((struct Obj04572 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04572 *)p)->f18);
    ((struct Obj04572 *)p)->f18 = 0;
    func_0201F868(((struct Obj04572 *)p)->f14);
    ((struct Obj04572 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24621 *)q)->f8, 27);
    func_020409B4(4);
    return 1;
}



int func_021DFFB0(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00351 *)q)->f18 = selected;
        func_021E03B0(p, q, 0);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}



void func_021E0044(char *p, char *q)
{
    *(char * *)&((struct Obj04573 *)p)->f1C = func_021FFBD4(func_0200CA1C(((struct Obj08315 *)q)->f10), ((struct Obj08315 *)q)->f8, ((struct Obj08315 *)q)->f4, ((struct Obj04573 *)p)->f44, ((struct Obj08315 *)q)->f0, ((struct Obj04573 *)p)->f3C, ((struct Obj04573 *)p)->f40, ((struct Obj04573 *)p)->f54);
    func_021FFE5C(*(char * *)&((struct Obj04573 *)p)->f1C);
    func_021FFE34(*(char * *)&((struct Obj04573 *)p)->f1C);
}



int func_021E0080(char *p)
{
    func_021FFE70(((struct Obj14434 *)p)->f1C);
    func_021FFC6C(((struct Obj14434 *)p)->f1C);
    func_020409B4(4);
    return 1;
}


/*
 * lever: Repeat the reset store in both result arms, with return 1 shared after them; hoisting the store removes the branch at 0x021E00C8.
 */
int func_021E009C(char *p, char *q)
{
    u16 out;
    int result;
    func_021FFC9C(*(char * *)&((struct Obj00277 *)p)->f1C);
    result = func_021FFE90(*(int * *)&((struct Obj00277 *)p)->f1C, &out);
    if (result) {
        if (result == 2) {
            ((struct Obj00351 *)q)->f14 = out;
            func_021E03B0(p, q, 1);
            ((struct Obj00277 *)p)->f50 = 0;
        } else {
            ((struct Obj00277 *)p)->f50 = 0;
        }
        return 1;
    }
    return 0;
}


int func_021E00D8(char *p,char *q)
{
    int first,second,a,b;
    void *v,*text,*data;
    int ws;
    Config cfg;
    Triple triple;
    Params params;
    first=func_021FC20C(*(char * *)&((struct Obj03330 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj03330 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj03330 *)q)->f8),28,((struct Obj02231 *)p)->f54);
    text=func_020457B0(128,((struct Obj02231 *)p)->f54);
    v=func_02012944(((struct Obj03330 *)q)->f10);
    a=func_0200856C(v);b=func_02008570(v);
    ws=func_021FC21C(*(char * *)&((struct Obj03330 *)q)->f8);
    data=func_02045EC0((void *)second,125);
    if(!func_02025B64(a))func_0201F048((void *)ws,0,a);
    else func_0201F094((void *)ws,0,a,b);
    func_0201F250((void *)ws,text,data);
    func_02045808(data);
    *(Slot * *)&((struct Obj02231 *)p)->f14=func_0201F81C(1,((struct Obj02231 *)p)->f54);
    func_0201F898(*(Slot * *)&((struct Obj02231 *)p)->f14,(u32)text,0,((struct Obj02231 *)p)->f54);
    func_02045808(text);
    cfg=d_021E3780;
    cfg.words[0]=*(u32 *)&((struct Obj02231 *)p)->f14;cfg.words[1]=1;
    cfg.words[5]=*(u32 *)&((struct Obj03330 *)q)->f8;cfg.words[6]=((struct Obj03330 *)q)->f4;
    ((struct Obj02231 *)p)->f18=func_021FC8C8(&cfg,((struct Obj02231 *)p)->f54);
    func_02082BCC(&params,0,8);
    func_021FC124(*(int *)&((struct Obj03330 *)q)->f8, 6, (struct Triple *)&triple);
    params.a=d_021E372E[0].a;params.b=d_021E372E[0].b;params.c=d_021E372E[0].c;params.flag=1;
    ((struct Obj02231 *)p)->fC=func_021FB378(&params,d_021E372E[0].file,96,1,*(int *)&((struct Obj03330 *)q)->f4,((struct Obj02231 *)p)->f44,first,second,&triple,((struct Obj02231 *)p)->f54);
    return 1;
}


int func_021E0214(char *p, char *q)
{
    if (((struct Obj04574 *)p)->fC) {
        func_021FB494(((struct Obj04574 *)p)->fC);
        ((struct Obj04574 *)p)->fC = 0;
    }
    func_021FCC80(((struct Obj04574 *)p)->f18);
    ((struct Obj04574 *)p)->f18 = 0;
    func_0201F868(((struct Obj04574 *)p)->f14);
    ((struct Obj04574 *)p)->f14 = 0;
    func_021FBDA4(((struct Obj24622 *)q)->f8, 28);
    func_020409B4(4);
    return 1;
}


/*
 * trailing: two zero alignment bytes at 0x021E02F6
 */
int func_021E024C(char *p, char *q)
{
    int selected, pressed;
    unsigned int x, y;
    func_021FCD0C(((struct Obj00277 *)p)->f18);
    selected = func_021FCDA8(((struct Obj00277 *)p)->f18);
    pressed = func_02035D20(&x, &y);
    pressed &= func_021FB4B4((unsigned int *)(((struct Obj00277 *)p)->fC), x, y);
    if (selected != -1) {
        unsigned int x1, y1;
        int args[2];
        void *v;
        int a;
        func_02035D20(&x1, &y1);
        args[0] = x1;
        args[1] = y1;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        v = func_02012944(((struct Obj00351 *)q)->f10);
        a = func_0200856C(v);
        ((struct Obj00351 *)q)->f17 = func_02008570(v);
        ((struct Obj00351 *)q)->f16 = a;
        func_021E03B0(p, q, 2);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    } else if (pressed != 0) {
        unsigned int x2, y2;
        int args[2];
        func_02035D20(&x2, &y2);
        args[0] = x2;
        args[1] = y2;
        func_021FD860(((struct Obj00277 *)p)->f40, 1, args);
        ((struct Obj00277 *)p)->f50 = 0;
        return 1;
    }
    return 0;
}


void func_021E02F8(char *p, int *q)
{
    int first, second, i;
    const struct Record_021E009C *r;
    first = func_021FC20C((char *)q[2]);
    second = func_021FC214((char *)q[2]);
    func_021FB964((void *)q[2], 25, ((struct Obj01765 *)p)->f54);
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)(p + i * 4 + 0x20) = func_021FC6A4(1, r->a, r->b, r->c, r->d, 14, ((struct Obj01765 *)p)->f48, ((struct Obj01765 *)p)->f54);
        func_021FC868(*(void **)(p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)(p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}


/*
 * extent: final two bytes are alignment padding.
 */
void func_021E037C(char *p,char *q){int i;for(i=0;i<6;i++){if(*(void **)(p+i*4+0x20)){func_021FC734(*(void **)(p+i*4+0x20));*(void **)(p+i*4+0x20)=0;}}func_021FBDA4(((struct Obj24623 *)q)->f8,25);func_020409B4(1);}


void func_021E03B0(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=func_021FC20C(*(char * *)&((struct Obj00351 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj00351 *)q)->f8);
    switch(mode) {
    case 0:
        if(((struct Obj00351 *)q)->f18!=19)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)(((struct Obj00351 *)q)->f18+205),(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(((struct Obj00351 *)q)->f14!=0xffff)func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)d_020A7370,(void *)(u32)((struct Obj00351 *)q)->f14,(void *)first,0x3da0);
        else func_021FC754(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(((struct Obj00351 *)q)->f16==255 && ((struct Obj00351 *)q)->f17==255) {
            func_021FC754(*(char * *)&((struct Obj00277 *)p)->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=func_021FC21C(*(char * *)&((struct Obj00351 *)q)->f8);
        data=func_02045EC0((void *)second,24);
        text=func_020457B0(128,((struct Obj00277 *)p)->f54);
        if(!func_02025B64(((struct Obj00351 *)q)->f16))func_0201F048((void *)ws,0,((struct Obj00351 *)q)->f16);
        else func_0201F094((void *)ws,0,((struct Obj00351 *)q)->f16,((struct Obj00351 *)q)->f17);
        func_0201F250((void *)ws,text,data);
        func_021FC7C4(*(char * *)&((struct Obj00277 *)p)->f34,text,(void *)first,0x3da0);
        func_02045808(data);func_02045808(text);
        break;
    }
}



/*
 * Hit-test a point against a table of three rectangles; returns the index
 * of the first hit, or 3 when none (or when no point is available).
 */
int func_021E04C8(void)
{
    unsigned int x, y;
    int i;

    if (func_02035D20(&x, &y)) {
        for (i = 0; i < 3; i++) {
            const Rect *r = &g_021E3808[i];
            if (x - r->x0 <= r->x1 - r->x0 && y - r->y0 <= r->y1 - r->y0) {
                return i;
            }
        }
    }
    return 3;
}


/*
 * extent: 021E05C2 alignment padding.
 */
int func_021E050C(void *task, int unused, char *q)
{
    struct Data *p;
    int entries[3];
    func_021FC20C((char *)(*(int *)&((struct Obj01767 *)q)->f8));
    func_021FC214(*(char * *)&((struct Obj01767 *)q)->f8);
    p = func_0203159C(task, 24, func_021F9B9C(((struct Obj01767 *)q)->fC));
    func_02082BCC(p, 0, 24);
    p->heap = func_021F9B9C(((struct Obj01767 *)q)->fC);
    func_021FB964((void *)(*(int *)&((struct Obj01767 *)q)->f8), 29, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 11, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 12, p->heap);
    func_021FBE54(*(char * *)&((struct Obj01767 *)q)->f8, 6, p->heap);
    p->e = func_021FD760((unsigned int)(((struct Obj01767 *)q)->f4), (char *)(*(int *)&((struct Obj01767 *)q)->f8), 1, p->heap);
    entries[0] = 2;
    entries[1] = 5;
    entries[2] = 5;
    p->a = func_021E07A4(p->heap, 12, ((struct Obj01767 *)q)->f4, (void *)(*(int *)&((struct Obj01767 *)q)->f8), p->e, entries);
    p->b = func_021E06D0(p->a, p->heap);
    p->d = (void *)func_0201C440((void *)p->heap);
    p->c = func_021FD12C(*(int *)&((struct Obj01767 *)q)->f8, p->d, p->heap);
    func_021FD170(p->c, (char *)(*(int *)&((struct Obj01767 *)q)->f8), (void *)104);
    return 1;
}


/*
 * extent: 021E0616 alignment padding; next owned function starts 021E0618.
 */
int func_021E05C4(void *a, int unused, int *q, void **p)
{
    func_021FD15C((void *)((int)p[2]), q[2]);
    func_021E0774(p[1]);
    func_021E0808(p[0]);
    func_0201C4C0(p[3]);
    func_021FD820(p[5]);
    func_021FBDA4(q[2], 29);
    func_021FC0C8((char *)q[2], 6);
    func_021FC0C8((char *)q[2], 12);
    func_021FC0C8((char *)q[2], 11);
    func_020315D4(a);
    return 1;
}


/*
 * extent: 021E06CE alignment padding.
 */
int func_021E0618(int unused, int *state, int *q, int *p)
{
    switch (*state) {
    case 0:
        func_021FE784(q[0], 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0((int *)q[0])) *state = 2;
        break;
    case 2:
        func_021E0754((char *)p[1]);
        switch (func_021E075C((char *)p[1])) {
        case 1: func_021F9BA0((unsigned int *)q[3]); *state = 3; break;
        case 2: ((struct Obj04576 *)q)->f10 = func_021E0764((char *)p[1]); func_021F9BF4((unsigned int *)q[3], 2); *state = 3; break;
        }
        break;
    case 3:
        func_021FE784(q[0], 2, 3, 1);
        *state = 4;
        break;
    case 4:
        if (func_021FE7B0((int *)q[0])) *state = 5;
        break;
    case 5: return 1;
    }
    if (p[2]) func_021FD1BC((void *)p[2]);
    func_0201C4E4((struct PrintSys *)p[3]);
    func_021FD854((char *)p[5]);
    return 0;
}
