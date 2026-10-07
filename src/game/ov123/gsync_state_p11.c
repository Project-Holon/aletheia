/*
 * file:     gsync_state_p11.c
 * unit:     yes
 * function: func_021D6830, func_021D6934, func_021D6A70, func_021D6AA8, func_021D6AB8, func_021D6C48, func_021D6C90, func_021D6CD8
 * address:  0x021D6830
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_020A1B38 0x020A1B38 data a2
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   func_021D679C 0x021D679C thumb ov123
 *   func_020056EC 0x020056EC thumb
 *   func_021D67B4 0x021D67B4 thumb ov123
 *   func_021D6720 0x021D6720 thumb ov123
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_02049238 0x02049238 arm
 *   func_02020E60 0x02020E60 thumb
 *   func_02062A98 0x02062A98 arm
 *   func_02062A4C 0x02062A4C arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02019D30 0x02019D30 thumb
 *   func_0201BB5C 0x0201BB5C thumb
 *   func_0201BABC 0x0201BABC thumb
 *   func_0204B7C8 0x0204B7C8 arm
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../../matched/include/Obj03268.h"
#include "../../matched/include/Obj13981.h"
#include "../../matched/include/Obj22951.h"
#include "../../matched/include/Obj02474.h"

struct Actor;
struct PtS;
struct Obj;
struct Vec2;
struct ArcFile;
struct NitroFileHeader;
struct Struct36;
typedef unsigned short u16;

typedef short s16_021D6830;

struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };

struct Pos { s16_021D6830 x,y; };

struct Pair { int x,y; };

typedef unsigned int   u32;

typedef unsigned char  u8;

struct Obj { u8 pad[0x40f4]; struct Record records[30]; };

typedef signed short s16_021D6A70;

typedef signed char s8;

typedef signed short s16_021D6AA8;

typedef signed int s32;

typedef struct { u32 x[9]; } Desc;

typedef signed short s16_021D6CD8;

struct Point { s16_021D6CD8 x,y; u16 f4; u8 f6,f7; };

extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, unsigned int which);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B5C0(const struct Obj *o, struct Pair *p);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_021D679C(u8 *p);
extern u32 func_020056EC(u32 range);
extern void func_021D67B4(u8 *, int);
extern void func_021D6720(u8 *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *);
extern u32 func_02020E60(u16, int);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A4C(struct NitroFileHeader *file, void **out);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern u32 func_02019D30(u32 a, u32 n);
extern u32 func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void func_0204B7C8(const char *src, struct Struct36 *dst);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_020862F0(void *,int);
extern void func_0207E51C(void *,int,int);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021D6830(struct Record *p);
void func_021D6934(struct Obj *p);
void func_021D6A70(u8 *p,int i,int a,int b,int c);
void func_021D6AA8(char *p, int i, u16 v);
void func_021D6AB8(u8 *p);
void func_021D6C48(char *p,int i,void *h);
void func_021D6C90(char *p,int i,void *h);
void func_021D6CD8(u8 *p);
extern const s16_021D6830 d_020A1B38[][2];

/*
 * lever: spelled-out x assignments reuse its already-loaded halfword.
 */
void func_021D6830(struct Record *p)
{
    struct Pos pos;
    struct Pair scale;
    int a,b;
    if (p == 0) return;
    a = (s16_021D6830)(d_020A1B38[p->a >> 4][0] * 4) >> 12;
    b = (s16_021D6830)(d_020A1B38[p->b >> 4][0] * 3) >> 12;
    if (p->h) {
        func_0204B454(p->h, (struct PtS *)&pos, 0);
        pos.x = p->x + a + b;
        pos.y = (p->y + a + b + p->age) >> 2;
        if (p->age % 8 == 0) {
            if (p->x > 128) p->x = p->x - 1;
            else p->x = p->x + 1;
        }
        func_0204B404(p->h, (const struct Vec2 *)(&pos), 0);
        func_0204B3DC(p->h, 1);
        p->age++;
        if (pos.y > 25) {
            func_0204B5C0(p->h, &scale);
            scale.x -= 16;
            scale.y -= 16;
            if (scale.x < 0 || scale.y < 0) func_021D679C((u8 *)p);
            else func_0204B5AC(p->h, &scale);
        }
        if (pos.y > 50) func_021D679C((u8 *)p);
    } else p->g = 1;
    if (p->g == 0) {
        p->a += (u16)(func_020056EC(12) + 200);
        p->b -= (u16)(func_020056EC(12) + 666);
    }
}

/*
 * lever: bind i+20 to n before indexing, sharing its scaled address.
 */
void func_021D6934(struct Obj *p)
{
    int active = 0;
    int i,n;
    for (i = 0; i < 20; i++) {
        if (p->records[i].c && !p->records[i].g) {
            func_021D6830(&p->records[i]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 20; i++) {
            n = func_020056EC(20);
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D67B4((u8 *)p, n);
                break;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        n = i + 20;
        if (p->records[n].c && !p->records[n].g) {
            func_021D6830(&p->records[n]);
            active = 1;
        }
    }
    if (active == 0) {
        for (i = 0; i < 10; i++) {
            n = func_020056EC(10) + 20;
            if (!p->records[n].c && p->records[n].d) {
                p->records[n].c = 1;
                p->records[n].x = func_020056EC(128) + 64;
                p->records[n].y = 0;
                func_021D6720((u8 *)p, n);
                return;
            }
        }
    }
}

void func_021D6A70(u8 *p,int i,int a,int b,int c){if(a!=0 && a<=493){*(s16_021D6A70 *)(p+(u32)i*24+0x4104)=a;*(s16_021D6A70 *)(p+(u32)i*24+0x4106)=b;if(c>2)c=0;*(s16_021D6A70 *)((u32)p+(u32)i*24+0x4108)=c;}}


void func_021D6AA8(char *p, int i, u16 v)
{
    *(u16 *)(p + i * 0x18 + 0x4104) = v;
}

/*
 * lever: declare out2 before out to place out at sp+0x3c, out2 at sp+0x40.
 */
void func_021D6AB8(u8 *p)
{
    void *h;
    void *h2;
    void *buf;
    void *buf2;
    u8 *out2;
    u8 *out;
    int i,n,species,form,gender;
    u32 value;
    u16 id;
    h = func_020490F4(25, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 20; i++) {
        species = ((struct Obj *)p)->records[i].d;
        if (species) {
            buf = func_02049250(h,func_02020E60(species,2),((struct Obj03268 *)p)->f43C4);
            func_02062A98(buf,(void **)(&out));
            func_02082D44(((struct Obj22951 *)out)->fC,p+0xbc+i*0x224,32);
            func_020307B0(buf);
            buf2 = func_02049250(h,func_02020E60(species,1),((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((struct Obj13981 *)out2)->f14,p+0xdc+i*0x224,512);
            func_020307B0(buf2);
        }
    }
    func_02049238(h);
    h2 = func_020490F4(7, ((struct Obj03268 *)p)->f43C4);
    for (i = 0; i < 10; i++) {
        n = i+20;
        species = ((struct Obj *)p)->records[n].d;
        if (species) {
            gender = ((struct Obj *)p)->records[n].f;
            form = (int)func_02019D30((u16)species,(u8)(((struct Obj *)p)->records[n].e));
            value = func_0201BB5C(species,form,gender,0);
            id = func_0201BABC(species,form,gender,0);
            buf2 = func_02049250(h2,id,((struct Obj03268 *)p)->f43C4);
            func_02062A4C(buf2,(void **)(&out2));
            func_02082D44(((struct Obj13981 *)out2)->f14,p+0xdc+n*0x224,512);
            func_020307B0(buf2);
            *(u32 *)(p+n*0x224+0x2dc) = value;
        }
    }
    func_02049238(h2);
}

/*
 * extent: two bytes zero alignment padding follow the return.
 */
void func_021D6C48(char *p,int i,void *h)
{
    Desc d;
    func_0204B7C8(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_0204B6F4(h,(u8)(*(u32 *)(p+i*0x224+0x2dc)),1);
}

void func_021D6C90(char *p,int i,void *h)
{
    Desc d;
    func_0204B7C8(h,(struct Struct36 *)(&d));
    func_02082D44(p+0xdc+i*0x224,(void *)(d.x[1]+0x6400000),0x200);
    func_020862F0(p+0xbc+i*0x224,0x20);
    func_0207E51C(p+0xbc+i*0x224,0x100,0x20);
}

/*
 * lever: narrow the helper result through a named u16 local before the call.
 */
void func_021D6CD8(u8 *p)
{
    struct Point pt;
    void *h;
    u16 n;
    h=func_020490F4(7,((struct Obj02474 *)p)->f43C4);
    n=func_0201BABC(1,0,0,0);
    ((struct Obj02474 *)p)->f44=(void *)func_0204A6C8(h,n,0,0,((struct Obj02474 *)p)->f43C4);
    pt.x=133; pt.y=128; pt.f4=0; pt.f6=3; pt.f7=2;
    ((struct Obj02474 *)p)->fB4=func_0204B294((void *)((struct Obj02474 *)p)->fC,(u32)((struct Obj02474 *)p)->f44,((struct Obj02474 *)p)->f28,((struct Obj02474 *)p)->f5C,&pt,0,((struct Obj02474 *)p)->f43C4);
    func_0204B92C(((struct Obj02474 *)p)->fB4,0);
    func_0204B3DC(((struct Obj02474 *)p)->fB4,0);
    func_02049238(h);
}
