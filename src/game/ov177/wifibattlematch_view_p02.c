/*
 * file:     wifibattlematch_view_p02.c
 * unit:     yes
 * function: func_021E5D68, func_021E5EF8, func_021E5F24, func_021E6118, func_021E62A0, func_021E62CC, func_021E64C0, func_021E64C8
 * address:  0x021E5D68
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020413B0 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_021E6940 0x021E6940 thumb ov177
 *   func_021E6F20 0x021E6F20 thumb ov177
 *   func_021E72FC 0x021E72FC thumb ov177
 *   func_021E73E4 0x021E73E4 thumb ov177
 *   func_021E7454  0x021E7454  thumb ov177
 *   func_021E73B8  0x021E73B8  thumb ov177
 *   func_021E7270  0x021E7270  thumb ov177
 *   func_021E6EFC  0x021E6EFC  thumb ov177
 *   func_020307B0  0x020307B0  arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020407E8 0x020407E8 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021E6BE8 0x021E6BE8 thumb ov177
 *   func_021E6E8C   0x021E6E8C  thumb ov177
 */
#include "../../matched/include/Obj00133.h"
#include "../../matched/include/Obj05464.h"
#include "../../matched/include/Obj00133.h"
#include "../../matched/include/Obj05465.h"

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj;
struct U16Vec;
struct Actor;
struct PtS;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef enum 
{
  BG2 = 2,
  BG6 = 6
} Layer;

typedef struct 
{
  short x;
  short y;
} Pt_021E5D68;

typedef struct Work_021E5D68 Work_021E5D68;

typedef struct Info Info;

typedef struct {short x,y;} Pt_021E5EF8;

typedef struct {short x,y;} Pt_021E62CC;

typedef struct { short x, y; } Pt;

typedef struct {
    char pad0[0x16c];
    void *objs[22];      /* 0x16c */
    char pad1c4[0x200 - 0x1c4];
    unsigned count;      /* 0x200 */
    short baseX[22];     /* 0x204 */
    unsigned char bg;    /* 0x230 */
    char pad231[3];
    unsigned layer;      /* 0x234 */
} Work_021E64C0;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u32, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_020413B0(u8, u8, u8, u8, u8, u8);
extern void func_020409B4(u32);
extern void func_021E6940(Work_021E5D68 *, u32, const Info *, void *, int, void *, void *, void *, u16);
extern void func_021E6F20(Work_021E5D68 *, void *, void *, u16);
extern void func_021E72FC(u8 *, unsigned, unsigned, unsigned);
extern void func_021E73E4(char *, unsigned, void *, unsigned);
extern void func_0204B404(void *, const Pt_021E5D68 *, u16);
extern void func_021E7454(int *p);
extern void func_021E73B8(char *p);
extern void func_021E7270(char *p);
extern void func_021E6EFC(unsigned *p);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u32 func_020407E8(u32 layer);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021E6BE8(Work_021E5D68 *, const Info *, void *, int, void *, void *, void *, u16);
extern int func_021E6E8C(unsigned char *p, void *mgr);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020061E4(unsigned);
extern unsigned func_0209C2B0(unsigned, unsigned);
extern void func_02041EE4(u32 index, u32 a, u32 b);
char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
void func_021E5EF8(void *p);
void func_021E5F24(char *p, int mode, void *mgr, void *print, int font, u16 a5);
char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
void func_021E62A0(void *p);
void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5);
int func_021E64C0(unsigned char *p, void *mgr);
int func_021E64C8(Work_021E64C0 *w);
extern const char d_021E8DBC[];




char *func_021E5D68(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt_021E5D68 pos;
  Info *tmp;
  w = func_02030734(heap, 0x244, 0, d_021E8DBC, 0x27f);
  func_02082BCC(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    func_0207D63C((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    func_0207D63C((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (Info *) info;
  switch (*((u16 *) (info + 0xaa)))
  {
    case 0:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 3);
      func_020409B4((u8) layer);
      break;

    case 1:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 7);
      func_020409B4((u8) layer);
      break;

  }

  func_021E6940((Work_021E5D68 *) w, a, tmp, b, c, d, e, f, heap);
  func_021E6F20((Work_021E5D68 *) w, owner, record, heap);
  info += 0x9c;
  func_021E72FC((u8 *) w, *((u32 *) info), (u32) owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  func_0204B404(*((void **) (w + 0x188)), (const Pt_021E5D68 *)&pos, *((u32 *) (w + 0x234)));
  func_021E73E4(w, (u32) owner, table, heap);
  return w;
}





void func_021E5EF8(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E7454(p);
    func_021E73B8(p);
    func_021E7270(p);
    func_021E6EFC(p);
    func_020307B0(p);
}





/*
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`layer1=0x240;` before `layer1=0x234;`; `layer2=0x240;` before
 * `layer2=0x234;` and 1 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void func_021E5F24(char *p, int mode, void *mgr, void *print, int font, u16 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt_021E5EF8 pos;
    func_02043B5C(func_02045770(((struct Obj00133 *)p)->f20),0);
    i=0;
    func_021E7270(p);
    base=0x240;
    func_021E6F20((Work_021E5D68 *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-func_020407E8(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05464 *)q)->f1A8;
            if(o)func_0204B3DC(o,0);
            o=((struct Obj05464 *)q)->f16C;
            if(o)func_0204B3DC(o,0);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fB4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fB8=1;
        break;
    }
    func_02045808(s);
}




char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt_021E5D68 pos;
  Info *tmp;
  w = func_02030734(heap, 0x244, 0, d_021E8DBC, 0x354);
  func_02082BCC(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    func_0207D63C((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    func_0207D63C((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (Info *) info;
  switch (*((u16 *) (info + 0xa8)))
  {
    case 0:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 3);
      func_020409B4((u8) layer);
      break;

    case 1:
      func_020413B0(layer, 0, 0, 32, 5, 1);
      func_020413B0(layer, 0, 5, 32, 18, 7);
      func_020409B4((u8) layer);
      break;

  }

  func_021E6BE8((Work_021E5D68 *) w, tmp, a, b, c, d, e, heap);
  func_021E6F20((Work_021E5D68 *) w, owner, record, heap);
  info += 0x9c;
  func_021E72FC((u8 *) w, *((u32 *) info), (u32) owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  func_0204B404(*((void **) (w + 0x188)), (const Pt_021E5D68 *)&pos, *((u32 *) (w + 0x234)));
  func_021E73E4(w, (u32) owner, table, heap);
  return w;
}




void func_021E62A0(void *p)
{
    *(unsigned short *)0x04001050 = 0;
    func_021E7454(p);
    func_021E73B8(p);
    func_021E7270(p);
    func_021E6EFC(p);
    func_020307B0(p);
}


void func_021E62CC(char *p, int mode, void *mgr, void *print, int font, u32 a5)
{
    int i;
    void *s;
    int x;
    int base,layer1,secondary,layer2;
    Pt_021E62CC pos;
    func_02043B5C(func_02045770(((struct Obj00133 *)p)->f28),0);
    i=0;
    func_021E7270(p);
    base=0x240;
    func_021E6F20((Work_021E5D68 *)p,*(void **)(p+base),*(void **)(p+base-8),*(u16 *)(p+base-4));
    x=32-func_020407E8(*(u8 *)(p+base-16));
    layer1=0x234;
    layer2=0x234;
    secondary=0x1a8;
    base=0x16c;
    for(;i<6;i++) {
        void *o;
        char *q;
        pos.y=168;pos.x=x+i*32;
        q=p+i*4;
        o=*(void **)(q+base);
        if(o)func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer1));
        o=*(void **)(q+secondary);
        if(o) {
            pos.x+=12;pos.y+=8;
            func_0204B404(o, (const Pt_021E5D68 *)&pos, *(unsigned *)(p+layer2));
        }
    }
    switch(mode) {
    case 0:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,1);
        s=func_02045EC0(mgr,17);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 1:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,1);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,1);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,18);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    case 2:
        for(i=0;i<6;i++) {
            char *q;
            void *o;
            q=p+i*4;
            o=((struct Obj05465 *)q)->f1A8;
            if(o)func_0204B3DC(o,0);
            o=((struct Obj05465 *)q)->f16C;
            if(o)func_0204B3DC(o,0);
        }
        func_0204B3DC(((struct Obj00133 *)p)->f18C,0);
        s=func_02045EC0(mgr,19);
        func_0201C724(print,(u32)func_02045770(((struct Obj00133 *)p)->fC4),0,0,(u32)s,font,0x3c40);
        ((struct Obj00133 *)p)->fC8=1;
        break;
    }
    func_02045808(s);
}



/*
 * Unlabelled ov177 thunk hidden in a word run: forwards to func_021E6E8C.
 * Matched to supply the `matched` witness for the pending ov176 caller
 * func_0217D434.
 */
int func_021E64C0(unsigned char *p, void *mgr)
{
    return func_021E6E8C(p, mgr);
}


int func_021E64C8(Work_021E64C0 *w)
{
    int ret;
    int level;
    int i;
    Pt cur, pos;
    if (func_020407E8(w->bg) == 0)
        return 1;
    ret = 0;
    if (w->count == 0) {
        for (i = 0; i < 22; i++) {
            if (w->objs[i] != 0) {
                func_0204B454(w->objs[i], (struct PtS *)&cur, (unsigned short)w->layer);
                w->baseX[i] = cur.x;
            }
        }
        func_020061E4(0x63b);
    }
    level = func_0209C2B0(w->count << 8, 20) - 0x100;
    for (i = 0; i < 22; i++) {
        if (w->objs[i] != 0) {
            func_0204B454(w->objs[i], (struct PtS *)&pos, (unsigned short)w->layer);
            pos.x = w->baseX[i] - func_0209C2B0(w->count << 8, 20);
            func_0204B404(w->objs[i], (const Pt_021E5D68 *)&pos, w->layer);
        }
    }
    if (w->count++ >= 20) {
        level = 0;
        w->count = 0;
        ret = 1;
    }
    func_02041EE4((unsigned char)(w->bg + 1), (int)0, (int)level);
    func_02041EE4((unsigned char)w->bg, (int)0, (int)level);
    return ret;
}
