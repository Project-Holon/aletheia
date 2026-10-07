/*
 * file:     unit_0220BC70_p05.c
 * unit:     yes
 * function: func_0220D9B4, func_0220DA6C, func_0220DC04, func_0220DCA8, func_0220DD78, func_0220DE4C, func_0220DF20, func_0220E088, func_0220E13C, func_0220E168, func_0220E1D4, func_0220E22C, func_0220E25C, func_0220E27C, func_0220E2B4, func_0220E2F8, func_0220E340, func_0220E3F0, func_0220E460, func_0220E518
 * address:  0x0220D9B4
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02211AF4 0x02211AF4 data a1
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_02210DA8 0x02210DA8 thumb ov198
 *   func_0220C694 0x0220C694 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_02045738  0x02045738  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   d_02211B68     0x02211B68  data  ov198  a4
 *   d_02211B06 0x02211B06 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D6DC 0x0220D6DC thumb ov198
 *   d_02211B50 0x02211B50 data a1
 *   func_0220CDF0 0x0220CDF0 thumb ov198
 *   func_0220C2F8 0x0220C2F8 thumb ov198
 *   func_0220C714 0x0220C714 thumb ov198
 *   func_0220C8F0 0x0220C8F0 thumb ov198
 *   func_0220C9F0 0x0220C9F0 thumb ov198
 *   func_0220CAF0 0x0220CAF0 thumb ov198
 *   func_0220CBF0 0x0220CBF0 thumb ov198
 *   func_0220CCF0 0x0220CCF0 thumb ov198
 *   func_0220C398 0x0220C398 thumb ov198
 *   func_0220C42C 0x0220C42C thumb ov198
 *   func_0220CFC4 0x0220CFC4 thumb ov198
 *   d_02211B20 0x02211B20 data a1
 *   func_0220C5AC 0x0220C5AC thumb ov198
 *   func_0220D034 0x0220D034 thumb ov198
 *   func_0220D090 0x0220D090 thumb ov198
 *   func_0220D1BC 0x0220D1BC thumb ov198
 *   func_0220D218 0x0220D218 thumb ov198
 *   func_0220D348 0x0220D348 thumb ov198
 *   func_0220D3B4 0x0220D3B4 thumb ov198
 *   func_0220D418 0x0220D418 thumb ov198
 *   func_0220D494 0x0220D494 thumb ov198
 *   d_02211B0D 0x02211B0D data a1
 *   sub_0201BD28 0x0201BD28 thumb
 *   d_02211B2C 0x02211B2C data a1
 *   func_0220D628 0x0220D628 thumb ov198
 *   sub_0201C1F4 0x0201C1F4 thumb
 *   d_02211AF9 0x02211AF9 data a1
 *   func_02020FE4 0x02020FE4 thumb
 *   func_0220C60C 0x0220C60C thumb ov198
 *   func_0201F73C 0x0201F73C thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_0220B0B0 0x0220B0B0 thumb ov196
 *   func_0220B094 0x0220B094 thumb ov196
 *   func_0220B07C 0x0220B07C thumb ov196
 *   func_0220E584 0x0220E584 thumb ov198
 *   func_0220E5FC 0x0220E5FC thumb ov198
 *   func_0220E6E0 0x0220E6E0 thumb ov198
 *   func_0220F1F4 0x0220F1F4 thumb ov198
 *   func_02043598 0x02043598 arm
 *   func_020490F4  0x020490F4  arm
 *   func_020185F4  0x020185F4  thumb
 *   func_0201BA68  0x0201BA68  thumb
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_020275F8 0x020275F8 thumb
 *   func_02027610 0x02027610 thumb
 */
#include "../../matched/include/Obj00507.h"
#include "../../matched/include/Obj25183.h"
#include "../../matched/include/Obj25184.h"
#include "../../matched/include/Obj25185.h"
#include "../../matched/include/Obj25186.h"
#include "../../matched/include/Obj25187.h"
#include "../../matched/include/Obj25188.h"
#include "../../matched/include/Obj25189.h"
#include "../../matched/include/Obj25190.h"
#include "../../matched/include/Obj25191.h"
#include "../../matched/include/Obj25192.h"
#include "../../matched/include/Obj25193.h"
#include "../../matched/include/Obj02247.h"
#include "../../matched/include/Obj25194.h"
#include "../../matched/include/Obj25195.h"
#include "../../matched/include/Obj03351.h"
#include "../../matched/include/Obj25197.h"
#include "../../matched/include/Obj00172.h"
#include "../../matched/include/Obj25198.h"
#include "../../matched/include/Obj25199.h"
#include "../../matched/include/Obj25200.h"
#include "../../matched/include/Obj25201.h"
#include "../../matched/include/Obj25202.h"
#include "../../matched/include/Obj25203.h"
#include "../../matched/include/Obj25204.h"
#include "../../matched/include/Obj25205.h"
#include "../../matched/include/Obj25206.h"
#include "../../matched/include/Obj25207.h"
#include "../../matched/include/Obj25208.h"
#include "../../matched/include/Obj25209.h"
#include "../../matched/include/Obj25210.h"
#include "../../matched/include/Obj25211.h"

struct Descriptor;
struct Config;
struct Cfg;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct StrObj;
struct CharBuf;
struct Entry;
typedef unsigned char u8;

typedef struct { unsigned char low:7; unsigned char high:1; } Flags;

typedef unsigned short u16;

typedef unsigned int u32;

struct R {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};

typedef struct { char *volatile global; } Context;

typedef struct {u8 lo:4,hi:4;} Bits4;

typedef signed int s32;

extern void func_0220BDA0(u8 *p);
extern int func_02210DA8(u8 *p);
extern void func_0220C694(char *, int, int);
extern int func_022110D4(u8 *,int);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u8 func_02045738(struct Descriptor *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D6DC(char *p, u8 *record, int slot);
extern void func_0220CDF0(u8 *p, int index);
extern void func_0220C714(u8 *p, int index);
extern void func_0220C8F0(char *,int);
extern void func_0220C2F8(u8 *p, int slot, int index, u16 value, u8 extra);
extern void func_0220C9F0(char *,int),func_0220CAF0(char *,int),func_0220CBF0(char *,int),func_0220CCF0(char *,int);
extern void func_0220C398(u8 *p, int slot, int index);
extern void func_0220C42C(char *,int,int);
extern void func_0220CFC4(char *,int);
extern void func_0220C5AC(char *,int,u16,u16);
extern void func_0220D034(char *,int),func_0220D090(char *,int,int);
extern void func_0220D1BC(char *,int),func_0220D218(char *,int,unsigned);
extern void func_0220D348(char *,int,int),func_0220D3B4(char *,int);
extern void func_0220D418(char *,int,int);
extern void func_0220D494(u8 *p, int slot, int a2, int a3);
extern unsigned sub_0201BD28(u16,unsigned);
extern void func_0220D628(char *,int);
extern u32 sub_0201C1F4(u16 id);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0220C60C(char *p, int id);
extern void func_0201F73C(void *,int,int,int);
extern void func_02043B5C(struct CharBuf *,u8);
extern unsigned func_0201DD78(unsigned,unsigned,unsigned);
extern int func_02012FFC(unsigned);
extern int func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern void func_0220B0B0(struct Entry *,int,u32);
extern void func_0220B094(char *,u8 *);
extern void func_0220B07C(void *);
extern void func_0220E584(char *);
extern void func_0220E5FC(char *);
extern void func_0220E6E0(char *);
extern void func_0220F1F4(u8 *p);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020185F4(void *p);
extern u32 func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern int func_0204ABF0(void *, unsigned, unsigned, unsigned, u16);
extern unsigned func_020275F8(unsigned);
extern unsigned func_02027610(unsigned);
void func_0220D9B4(char *p);
void func_0220DA6C(u8 *p, int idx);
void func_0220DC04(char *p);
void func_0220DCA8(char *p);
void func_0220DD78(char *p);
void func_0220DE4C(char *p);
void func_0220DF20(char *p);
void func_0220E088(char *p);
void func_0220E13C(u8 *p);
void func_0220E168(char *p);
void func_0220E1D4(u8 *p);
void func_0220E22C(u8 *p);
void func_0220E25C(u8 *p);
void func_0220E27C(u8 *p);
void func_0220E2B4(char *p);
void func_0220E2F8(char *p);
void func_0220E340(u8 *p);
void func_0220E3F0(char *p);
void func_0220E460(char *p);
void func_0220E518(char *p);
extern u8 d_02211AF4[];
extern u32 d_02211B68[];
extern u8 d_02211B06[];
extern const int d_02211B3C[];
extern u8 d_02211B50[];
extern u8 d_02211B20[];
extern u8 d_02211B0D[];
extern u8 d_02211B2C[];
extern u8 d_02211AF9[];

void func_0220D9B4(char *p)
{
    int state, id, i;
    void *obj;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF4;
    func_0220BDA0((u8 *)p);
    func_0220DA6C((u8 *)p, (*(u8 **)p)[32]);
    state = func_02210DA8((u8 *)p);
    if (state == 2) id = 26;
    else if (state == 3) id = 27;
    else if (state == 4) id = 28;
    else if (state == 1) id = 29;
    else id = 21;
    func_0220C694(p,1,id);
    i = func_022110D4((u8 *)p, (*(u8 **)p)[32]);
    if (((Flags *)(p + i * 76 + 27))->high == 0) {
        func_0220C694(p,2,24);
        func_0220C694(p,3,25);
        return;
    }
    obj = ((struct Obj00507 *)p)->f1F80;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
    obj = ((struct Obj00507 *)p)->f1F88;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}


static inline u8 center_x(int w)
{
    return w / 2;
}


static inline void put(u8 *p, void *win, void *sel, short x, u32 y, void *h, u16 color)
{
    func_0201C724(win, (u32)func_02045770(sel), x, y, (u32)h, *(u32 *)(*(u8 **)p + 0xc), color);
    *(u8 *)(p + 0x1F74) = 1;
}


/*
 * lever: 2026-10-05 (wD9r lane160): three source facts. (1) half is a narrow local: the centre is a static
 *   inline `u8 center_x(int w)` (signed /2) assigned to a `short half`, and t is u8; the put x and the callee x
 *   are short, so half reaches the first call with no s16 conversion and its reload stays below the outgoing
 *   stack stores. (2) The dirty flag store p[0x1F74] = 1 is inside the put helper, which keeps the 0x1EAC base
 *   in r5 across the arms and frees the msg2 arms for cross-jumping. (3) a short (not u8) half takes its
 *   declaration slot 0x18 above the window temps; a u8 half takes the lowest slot. Before: DIFF 153.
 */
void func_0220DA6C(u8 *p, int idx)
{
    void *msg;
    u32 off;
    void *o;
    struct R *rec;
    void *vec;
    u8 t;
    short half;
    void *msg2;
    int a;
    int b;
    u8 *base;
    int n;

    o = *(void **)(p + 0x1F70);
    n = func_022110D4(p, idx);
    base = p + 4;
    off = n * 0x4c;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, *(u16 *)(*(u8 **)p + 0x10));
    msg = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), d_02211B68[idx]);
    func_0201EEF4(*(struct WordSet **)(p + 0x1EA4), 0, *(void **)rec);
    msg2 = 0;
    func_0201F250(*(struct WordSet **)(p + 0x1EA4), vec, msg);
    func_02045808(msg);
    if (!rec->a1 && !rec->b2) {
        if (rec->b0 == 0) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x16);
        } else if (rec->b0 == 1) {
            msg2 = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x17);
        }
    }
    a = 0;
    t = func_0201D304(vec, *(u32 *)(*(u8 **)p + 0xc), 0);
    if (msg2 == 0) {
        b = 0;
    } else {
        a = (u8)func_0201D304(msg2, *(u32 *)(*(u8 **)p + 0xc), a);
        b = 8;
    }
    half = center_x(func_02045738(o) * 8 - t - a - b);
    put(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), half, 7, vec, 0x3DC0);
    func_02045808(vec);
    if (msg2 != 0) {
        if (rec->b0 == 0) {
            put(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x2960);
        } else {
            put(p, *(void **)(p + 0x1EAC), *(void **)(p + 0x1F70), b + (half + t), 8, msg2, 0x31A0);
        }
        func_02045808(msg2);
    }
}

void func_0220DC04(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211B06;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    func_0220C694((char *)p,5,24);
}

void func_0220DCA8(char *p) {
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B50;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    func_0220CDF0((u8 *)p,(*(u8 **)p)[32]);
    func_0220C2F8((u8 *)p,10,(*(u8 **)p)[32],0,0);
    func_02045334(((struct Obj00507 *)p)->f1FC0);
    func_0220C714((u8 *)p,(*(u8 **)p)[32]);
    func_0220C8F0(p,(*(u8 **)p)[32]);
    func_0220C9F0(p,(*(u8 **)p)[32]);
    func_0220CAF0(p,(*(u8 **)p)[32]);
    func_0220CBF0(p,(*(u8 **)p)[32]);
    func_0220CCF0(p,(*(u8 **)p)[32]);
    func_0220C398((u8 *)p,1,(*(u8 **)p)[32]);
    func_0220C42C(p,3,(*(u8 **)p)[32]);
    func_0220CFC4(p,(*(u8 **)p)[32]);
    func_0220C694(p,21,25);
}

void func_0220DD78(char *p) {
    u8 *owner;
    char *base,*rec;
    unsigned offset;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B20;
    func_0220BDA0((u8 *)p);
    owner=*(u8 * *)&((struct Obj00507 *)p)->f0;
    base=p+0x30+func_022110D4((u8 *)p,owner[32])*76;
    offset=owner[0x4b]*8;
    rec=base+offset;
    func_0220BEB8((u8 *)p,6,owner[32],0,0);
    func_0220C5AC(p,7,0,0);
    func_0220C4DC(p,*(u16 *)(base+offset),0,d_02211B3C[(*(u8 **)p)[0x4b]],0,0,0x3dc0);
    func_0220D034(p,8);
    func_0220D090(p,2,(u8)rec[6]);
    func_0220D1BC(p,9);
    func_0220D218(p,3,(u8)rec[7]);
    func_0220D348(p,4,*(u16 *)(base+offset));
    func_0220D3B4(p,10);
    func_0220D418(p,5,(u8)rec[5]);
    func_0220D494((u8 *)p,1,(u8)rec[2],(u8)rec[3]);
}

void func_0220DE4C(char *p) {
    long i;
    int offset;
    char *base,*rec;
    u16 value;
    u8 local[8];
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B0D;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base=p+0x30;
    for(i=0;i<4u;i++) {
        offset=i*8;
        value=((u16 *)(rec=base+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76))[i*4];
        if(value==0) *(u8 *)(p+offset+0x1f7c)=1;
        else {
            func_0220C4DC(p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC(p,(u8 *)(rec+offset),i+1);
        }
    }
    func_0220C4DC(p,((struct Obj25183 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5,0x53,65535,7,0x3dc0);
    local[2]=sub_0201BD28(((struct Obj25184 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
    local[3]=local[2];
    func_0220D6DC(p,(u8 *)local,5);
}

void func_0220DF20(char *p) {
    unsigned index,offset,type;
    char *base,*rec;
    *(u8 * *)&((struct Obj00507 *)p)->f253C=d_02211B2C;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    func_0220C5AC(p,2,0,0);
    func_0220D034(p,4);
    func_0220D1BC(p,5);
    func_0220D3B4(p,9);
    index=(*(u8 **)p)[0x4b];
    if(index<4) {
        base=p+0x30+func_022110D4((u8 *)p,(*(u8 **)p)[32])*76;
        offset=index*8;
        rec=base+offset;
        func_0220C4DC(p,*(u16 *)(base+offset),1,d_02211B3C[index],0,0,0x3dc0);
        func_0220D090(p,6,(u8)rec[6]);
        func_0220D218(p,7,(u8)rec[7]);
        func_0220D348(p,8,*(u16 *)(base+offset));
        func_0220D418(p,10,(u8)rec[5]);
        func_0220D494((u8 *)p,3,(u8)rec[2],(u8)rec[3]);
    } else {
        type=sub_0201BD28(((struct Obj25185 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,5);
        func_0220C4DC(p,((struct Obj25186 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,1,0x53,0,0,0x3dc0);
        func_0220D348(p,8,((struct Obj25187 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26);
        if(sub_0201C1F4(((struct Obj25188 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26)==1) func_0220D090(p,6,0);
        else func_0220D090(p,6,sub_0201BD28(((struct Obj25189 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,4));
        func_0220D218(p,7,sub_0201BD28(((struct Obj25190 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,3));
        func_0220D418(p,10,sub_0201BD28(((struct Obj25191 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f26,2));
        func_0220D494((u8 *)p,3,type,type);
    }
    func_0220D628(p,11);
}

void func_0220E088(char *p)
{
    long i;
    int index, offset;
    char *base, *rec;
    u16 value;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF9;
    func_0220BDA0((u8 *)p);
    func_0220BEB8((u8 *)p,0,(*(u8 **)p)[32],0,0);
    base = (char *)p + 0x30;
    for (i=0; i<4u; i++) {
        offset = i * 8;
        value = ((u16 *)(rec = base + func_022110D4((u8 *)p,(*(u8 **)p)[32]) * 76))[i * 4];
        if (value == 0) *(u8 *)(p + offset + 0x1f7c) = 1;
        else {
            func_0220C4DC((char *)p,value,i+1,d_02211B3C[i],65535,7,0x3dc0);
            func_0220D6DC((char *)p,(u8 *)(rec+offset),i+1);
        }
    }
    if (func_02020FE4((void *)(((struct Obj25192 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f24),40,((struct Obj25193 *)(*(char * *)&((struct Obj00507 *)p)->f0))->f10) == 0)
        func_0220C60C((char *)p,104);
}

void func_0220E13C(u8 *p){func_0201F73C(((struct Obj02247 *)p)->f1F68,2,1,14);func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj02247 *)p)->f1F68),15);func_0220E168((char *)p);}

/*
 * volatile: global pointer re-read at 0220E17C and 0220E196 before func_0201CCE4.
 */
void func_0220E168(char *p)
{
    int v;
    void *obj;
    v = func_02012FFC(func_0201DD78(1,2,0));
    ((struct Obj02247 *)p)->f1EB0 = func_0201CCE4(*(unsigned *)&((struct Obj02247 *)p)->f1F68,0,0,*(unsigned *)&((struct Obj02247 *)p)->f1EA8,((struct Obj25194 *)(((Context *)p)->global))->fC,v,((struct Obj02247 *)p)->f1D4,10,((struct Obj25195 *)(((Context *)p)->global))->f10,15);
    obj = ((struct Obj02247 *)p)->f1F68;
    func_02045334(obj);
    func_02045374(obj);
    func_02041B6C(func_02045730(obj));
}

/*
 * lever: the row pointer p + 4 + idx * 0x4c is one statement before the
 *   func_02045EC0 allocation, so p + 4 (r6) and idx * 0x4c (r7) stay live
 *   across it and the allocation result spills to [sp]; computing the row
 *   address only at its use (the earlier note's base + i) left t in r7 and
 *   rematerialised p + 4 after the call (DIFF 16).
 */
void func_0220E1D4(u8 *p)
{
    u8 *row;
    void *t;
    row = p + 4 + func_022110D4(p, (*(u8 **)p)[32]) * 0x4c;
    t = func_02045EC0(*(struct MsgBank **)(p + 0x1ea0), 105);
    func_0201EEF4(*(struct WordSet **)(p + 0x1ea4), 0, *(void **)row);
    func_0201EF34(*(struct WordSet **)(p + 0x1ea4), 1, 373);
    func_0201F250(*(struct WordSet **)(p + 0x1ea4), *(void **)(p + 0x1ea8), t);
    func_02045808(t);
}

/*
 * evidence: enum offset k retained across the call; j saves k+0x10 before k-=0xb4. Parenthesised offsets and the sequenced local match the 48-byte original.
 */
void func_0220E22C(u8 *p){enum{K=0x1f60}k=K;u32 j;func_0220B0B0((struct Entry *)(p+k),*(int *)(p+(k-0xb4)),2);j=k+0x10;k-=0xb4;func_0220B0B0((struct Entry *)(p+j),*(int *)(p+k),p[0x2174]);}

void func_0220E25C(u8 *p){func_0220B094((char *)p+0x1f70,*(u8 * *)&((struct Obj03351 *)p)->f253C);func_0220E27C(p);}

void func_0220E27C(u8 *p){if(((Bits4 *)(p+0x2177))->hi==1){func_0201F73C(((struct Obj25197 *)p)->f1F60,2,1,14);func_0220B07C(p+0x1f60);((Bits4 *)(p+0x2177))->hi=0;}}

/*
 * extent: 0220E2F6 alignment padding.
 */
void func_0220E2B4(char *p)
{
    func_0220E2F8(p);
    func_0220E340((u8 *)p);
    func_0220E3F0(p);
    func_0220E518(p);
    func_0220E460(p);
    func_0220E584(p);
    func_0220E5FC(p);
    func_0220E6E0(p);
    func_0220F1F4((u8 *)p);
    func_02043598(16, 1);
}

void func_0220E2F8(char *p)
{
    unsigned int i;
    for (i = 0; i < 26; i++) *(int *)(p + i * 4 + 0x24a4) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x250c) = -1;
    for (i = 0; i < 6; i++) *(int *)(p + i * 4 + 0x2524) = -1;
}


/*
 * pass 2 2026-10-06 P2L21: EXACT (was 9 bytes off, arc/arr r6/r7 swap). Closing form: the A6C8 call and the
 *   array store written in each if/else arm, with the store address as integer arithmetic
 *   `*(int *)((u32)p + 0x24A4 + i * 4)` (no named array pointer; LICM hoists p + 0x24A4, the ov097 021F6F88
 *   `icons + i * 4` style). Either part alone stays at 9 bytes (named arr in both arms, or the integer
 *   address with one join store). EXACT in --lang c99 and --lang c.
 */
void func_0220E340(u8 *p)
{
    void *arc;
    u16 i;

    arc = func_020490F4(7, (u16)((*(u16 *)(*(u8 **)p + 0x10) & 0x7FFF) | 0x8000));
    for (i = 0; i < 6; i++) {
        u8 *e = p + i * 0x4C;
        if (*(u16 *)(e + 8) != 0) {
            *(int *)((u32)p + 0x24A4 + i * 4) = func_0204A6C8(arc, func_0201BA68(func_020185F4(*(void **)(e + 4))), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        } else {
            *(int *)((u32)p + 0x24A4 + i * 4) = func_0204A6C8(arc, func_0201BABC(0, 0, 0, 0), 0, 1, *(u16 *)(*(u8 **)p + 0x10));
        }
    }
    *(int *)(p + 0x250C) = func_0204ACEC(arc, func_0201BC3C(), 1, 0, *(u16 *)(*(u8 **)p + 0x10));
    *(s32 *)(p + 0x2524) = func_0204AF28(arc, func_0201BC78(), func_0201BCEC(), *(u16 *)(*(u8 **)p + 0x10));
    func_02049238(arc);
}

void func_0220E3F0(char *p)
{
    void *owner;
    owner = func_020490F4(83,(u16)((((struct Obj25198 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f24BC = func_0204A6C8(owner, 12, 0, 1, ((struct Obj25199 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2510 = func_0204ABF0(owner, 11, 1, 96, ((struct Obj25200 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2528 = func_0204AF28(owner, 13, 16, ((struct Obj25201 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}

void func_0220E460(char *p)
{
    void *owner;
    unsigned i;
    owner = func_020490F4(83,(u16)((((struct Obj25202 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f2518 = func_0204ABF0(owner, 33, 1, 160, ((struct Obj25203 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2530 = func_0204AF28(owner, 59, 62, ((struct Obj25204 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    for (i = 8; i <= 21; i++)
        ((int *)(p + 0x24a4))[i] = func_0204A6C8(owner, func_020275F8(0), 0, 1, ((struct Obj25205 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f24FC = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25206 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2500 = func_0204A6C8(owner, func_02027610(0), 0, 1, ((struct Obj25207 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}

void func_0220E518(char *p)
{
    void *owner;
    owner = func_020490F4(83,(u16)((((struct Obj25208 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10 & 0x7fff) | 0x8000));
    ((struct Obj00172 *)p)->f24C0 = func_0204A6C8(owner, 65, 0, 1, ((struct Obj25209 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f2514 = func_0204ABF0(owner, 66, 1, 128, ((struct Obj25210 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    ((struct Obj00172 *)p)->f252C = func_0204AF28(owner, 67, 70, ((struct Obj25211 *)(*(char * *)&((struct Obj00172 *)p)->f0))->f10);
    func_02049238(owner);
}
