/*
 * file:     br_codein_p19.c
 * unit:     yes
 * function: func_021DF41C, func_021DF428, func_021DF5B8, func_021DF620, func_021DF838, func_021DF8F0
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
 */
#include "../../matched/include/Obj24619.h"
#include "../../matched/include/Obj02522.h"

struct Actor;
struct Obj;
struct Struct36;
struct Sub0204A9D0;
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

extern int func_021FCDA8(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02082BCC(void *,u32,u32);
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
int func_021DF41C(char *p);
void func_021DF428(struct State_021DF428 *p,u32 mgr,u16 heap);
void func_021DF5B8(char *p);
void func_021DF620(struct State_021DF620 *p,int first,short step,u16 heap);
void func_021DF838(int p, char *out);
int func_021DF8F0(int x, int y);

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
