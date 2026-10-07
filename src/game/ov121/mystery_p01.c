/*
 * file:     mystery_p01.c
 * unit:     yes
 * function: func_021D6660, func_021D67D4, func_021D6888, func_021D6924, func_021D6948, func_021D694C, func_021D6AEC, func_021D6C28, func_021D6C58, func_021D6C60, func_021D6C84, func_021D6CEC, func_021D6CF4, func_021D6D38
 * address:  0x021D6660
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
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020124F4 0x020124F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A300 0x0200A300 thumb
 *   func_021D9624 0x021D9624 thumb ov121
 *   func_021D9744 0x021D9744 thumb ov121
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_021DA854 0x021DA854 thumb ov121
 *   func_021D6D80 0x021D6D80 thumb ov121
 *   func_021D9CA4 0x021D9CA4 thumb ov121
 *   func_021D9FFC 0x021D9FFC thumb ov121
 *   func_021DE2A0 0x021DE2A0 thumb ov121
 *   func_021D91BC 0x021D91BC thumb ov121
 *   func_021D9254 0x021D9254 thumb ov121
 *   func_021D9288 0x021D9288 thumb ov121
 *   func_02005D90 0x02005D90 thumb
 *   ov114_id 0x00000072 data
 *   func_021D9228 0x021D9228 thumb ov121
 *   func_021DE2F0 0x021DE2F0 thumb ov121
 *   func_021D9E04 0x021D9E04 thumb ov121
 *   func_021DA890 0x021DA890 thumb ov121
 *   func_021D96C4 0x021D96C4 thumb ov121
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02087BCC 0x02087BCC arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   func_021DE300 0x021DE300 thumb ov121
 *   func_021DA898 0x021DA898 thumb ov121
 *   func_021D9718 0x021D9718 thumb ov121
 *   func_021D972C 0x021D972C thumb ov121
 *   func_021D9738 0x021D9738 thumb ov121
 *   func_021D9238 0x021D9238 thumb ov121
 *   func_021D9E50 0x021D9E50 thumb ov121
 *   func_021DA2C8 0x021DA2C8 thumb ov121
 *   func_021DA840 0x021DA840 thumb ov121
 *   func_021DA8AC 0x021DA8AC thumb ov121
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02040B94 0x02040B94 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02005728 0x02005728 thumb
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02049F34 0x02049F34 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 *   func_02030734 0x02030734 arm
 *   func_02050C04 0x02050C04 arm
 *   d_021DFB80 0x021DFB80 data ov121 a1
 */
#include "../../matched/include/Obj02176.h"
#include "../../matched/include/Obj01402.h"
#include "../../matched/include/Obj01403.h"
#include "../../matched/include/Obj22851.h"
#include "../../matched/include/Obj10404.h"
#include "../../matched/include/Obj22852.h"
#include "../../matched/include/Obj10405.h"
#include "../../matched/include/Obj13938.h"
#include "../../matched/include/Obj22853.h"
#include "../../matched/include/Obj22854.h"

struct Obj0203159C;
struct Big;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct S020315D4;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { s16 x,y,z; u8 a,b; } Record;

typedef signed int     s32;

extern int func_02034AC4(int id);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *, int, int);
extern void *func_020124F4(u16 id);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A300(void *, void *, void *);
extern u8 *func_021D9624(int arg, u16 heap);
extern unsigned func_021D9744(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_021DA854(void *, void *, u16);
extern void func_021D6D80(void *a, int b, u8 *p);
extern void *func_021D9CA4(int a, u8 b, void *c, void *d, u16 heap);
extern void func_021D9FFC(u8 *p, int a, int b);
extern void *func_021DE2A0(void *arg, int heap);
extern void func_021D91BC(u8 *p, void *q, u16 h);
extern void func_021D9254(char *p, int n);
extern void func_021D9288(unsigned *p, unsigned v);
extern void func_02005D90(int, int);
extern void func_021D9228(void *);
extern void func_021DE2F0(u8 *p);
extern void func_021D9E04(u8 *p);
extern void func_021DA890(void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_021D96C4(u8 *p);
extern void func_0200A338(void *);
extern void func_02012704(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
extern void func_02087BCC(u32 parameter);
extern void func_02034A5C(int);
extern void func_02005D28(void);
extern void func_021DE300(char *p);
extern void func_021DA898(char *p);
extern void func_021D9718(u8 *p);
extern void func_021D972C(char *p);
extern void func_021D9738(char *p);
extern void func_021D9238(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_021D9E50(u8 *p);
extern int func_021DA2C8(u8 *p);
extern int func_021DA840(void **);
extern int func_021DA8AC(u32 *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern void func_02049238(void *);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern int func_0204ABF0(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u32 func_02005728(u32 range);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_0204ADEC(void *,void *,int);
extern s32 func_021DAAA4(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02050C04(int a, int b, int c, int d);
int func_021D6660(void *a, u32 b, u32 c);
int func_021D67D4(void *a, int b, int c, char *p);
int func_021D6888(int a, int b, int c, char *p);
void func_021D6924(u16 *p,u16 heap);
void func_021D6948(void *a0);
void func_021D694C(u16 *p,int mode);
void func_021D6AEC(char *p, void *owner, u16 heap);
void func_021D6C28(u8 *p);
void *func_021D6C58(u8 *p,int i);
void func_021D6C60(u8 *p,int heap);
void func_021D6C84(u8 *p);
void func_021D6CEC(u8 *p);
void func_021D6CF4(int *p, int heap);
void func_021D6D38(void *p);
extern char ov114_id[];
extern char ov_id[];
extern const char d_021DFB80[];

int func_021D6660(void *a, u32 b, u32 c)
{
    u8 *p;
    func_02034AC4((int)ov114_id);
    func_0203064C(1, 29, 0xA0000);
    p = func_0203159C(a, 0x69C, 29);
    func_02082BCC(p, 0, 0x69C);
    *(u32 *)(p + 0x3B4) = c;
    *(void **)(p + 0x3B8) = func_020124F4(29);
    *(void **)(p + 0x3BC) = func_0200A300(func_02012EBC(*(void **)(p + 0x3B8)), (void *)1, (void *)29);
    *(u8 **)(p + 0x394) = func_021D9624(1, 29);
    func_021D6924((u16 *)(p + 0x390), 29);
    func_021D6AEC((char *)(p + 0x294), (void *)func_021D9744((char *)*(u8 **)(p + 0x394)), 29);
    *(void **)(p + 0x398) = func_0201D7EC(23, 0, 0, 0, 29);
    *(u32 *)(p + 0x39C) = func_0201C440((void *)29);
    *(void **)(p + 0x3A4) = func_02045B38(0, 2, 0x50, 29);
    *(void **)(p + 0x3A0) = func_02045B38(0, 3, 0x9E, 29);
    *(void **)(p + 0x3A8) = func_0201EC64(29);
    *(void **)(p + 0x290) = func_021DA854(p, (void *)func_021D6D80, 29);
    *(void **)(p + 0x284) = func_021D9CA4(1, 15, *(void **)(p + 0x39C), *(void **)(p + 0x398), 29);
    func_021D9FFC(*(u8 **)(p + 0x284), 10, 14);
    *(void **)(p + 0x3B0) = func_021DE2A0(func_02012EBC(*(void **)(p + 0x3B8)), 29);
    func_021D91BC(p + 0x138, p + 0x294, 29);
    func_021D9254((char *)p + 0x138, 0);
    func_021D9288((unsigned int *)(p + 0x138), 1);
    func_02005D90(1154, 0xFFFF);
    return 1;
}

int func_021D67D4(void *a, int b, int c, char *p)
{
    func_021D9228(p + 0x138);
    func_021DE2F0(((struct Obj02176 *)p)->f3B0);
    if (((struct Obj02176 *)p)->f284) func_021D9E04(((struct Obj02176 *)p)->f284);
    func_021DA890(((struct Obj02176 *)p)->f290);
    func_0201ED04(((struct Obj02176 *)p)->f3A8);
    func_02045C04(((struct Obj02176 *)p)->f3A0);
    func_02045C04(((struct Obj02176 *)p)->f3A4);
    func_0201C4C0(((struct Obj02176 *)p)->f39C);
    func_0201D83C(((struct Obj02176 *)p)->f398);
    func_021D6C28((u8 *)(p + 0x294));
    func_021D6948(p + 0x390);
    func_021D96C4(((struct Obj02176 *)p)->f394);
    func_0200A338(((struct Obj02176 *)p)->f3BC);
    func_02012704(((struct Obj02176 *)p)->f3B8);
    func_020315D4(a);
    func_020306F0(29);
    func_02087BCC(0);
    func_02034A5C((int)ov_id);
    func_02005D28();
    return 1;
}

/*
 * follower: two zero padding bytes at 0x021D6922.
 */
int func_021D6888(int a, int b, int c, char *p)
{
    func_021DE300(((struct Obj01402 *)p)->f3B0);
    func_021DA898(((struct Obj01402 *)p)->f290);
    if (((struct Obj01402 *)p)->f394) {
        func_021D9718(((struct Obj01402 *)p)->f394);
        func_021D972C(((struct Obj01402 *)p)->f394);
        func_021D9738(((struct Obj01402 *)p)->f394);
    }
    func_021D9238(p + 0x138);
    func_0201C4E4(((struct Obj01402 *)p)->f39C);
    if (((struct Obj01402 *)p)->f284) func_021D9E50(((struct Obj01402 *)p)->f284);
    if (((struct Obj01402 *)p)->f28C) func_021DA2C8(((struct Obj01402 *)p)->f28C);
    if (((struct Obj01402 *)p)->f288) func_021DA2C8(((struct Obj01402 *)p)->f288);
    if (((struct Obj01402 *)p)->f270) func_021DA840(*(void ** *)&((struct Obj01402 *)p)->f270);
    if (func_021DA8AC(((struct Obj01402 *)p)->f290)) return 1;
    return 0;
}

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void func_021D6924(u16 *p,u16 heap)
{
    func_02082BCC(p,0,2);
    *p=heap;
    func_021D694C(p,0);
    func_02040588(6,1);
}

void func_021D6948(void *a0) { }

void func_021D694C(u16 *p,int mode)
{
    u16 heap=(*p&0x7fff)|0x8000;
    void *arc;
    switch (mode) {
    case 0:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,0,0,0,heap);
        func_02049B68(arc,6,4,0,128,heap);
        func_02049B68(arc,7,4,32,32,heap);
        func_02049658(arc,15,3,0,0,0,heap);
        func_02049658(arc,15,7,0,0,0,heap);
        func_020498F4(arc,31,3,0,0,0,heap);
        func_020498F4(arc,31,7,0,0,0,heap);
        func_02049238(arc);
        arc=func_020490F4(23,heap);
        func_02049B68(arc,5,0,480,32,heap);
        func_02049B68(arc,5,4,480,32,heap);
        func_02049238(arc);
        func_0201F5BC(1,10,14,0,heap);
        func_0201F5BC(0,1,13,0,heap);
        func_02040B94(1,32,0,heap);
        func_02040B94(0,32,0,heap);
        break;
    case 1:
        arc=func_020490F4(34,heap);
        func_02049B68(arc,6,4,0,192,heap);
        func_02049658(arc,15,6,0,0,0,heap);
        func_020498F4(arc,21,6,0,0,0,heap);
        func_02049238(arc);
        break;
    case 2:
        arc=func_020490F4(34,heap);
        func_02049658(arc,11,2,0,0,0,heap);
        func_020498F4(arc,28,2,0,0,0,heap);
        func_02049238(arc);
        break;
    }
}

/*
 * follower: two zero padding bytes at 0x021D6C26.
 * lever: spell the object slot as p+i*4+16; data precedes allocation in local declarations.
 * interfaces: ABF0 and B294 leave r0 live and this caller consumes it despite legacy void definitions.
 */
void func_021D6AEC(char *p, void *owner, u16 heap)
{
    void *res;
    Record point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=func_020490F4(34,heap);
    *(int *)&((struct Obj01403 *)p)->f0=func_0204ABF0(arc,8,2,0,heap);
    *(int *)&((struct Obj01403 *)p)->f8=func_0204AF28(arc,34,37,heap);
    *(int *)&((struct Obj01403 *)p)->f4=func_0204A6C8(arc,16,0,2,heap);
    allocation=func_02049F78(arc,8,(u32)(&res),heap);
    data=*(char * *)&((struct Obj22851 *)res)->fC;
    func_02082D44(data,p+0xda,32);
    data+=32;
    func_02082D44(data,p+0xba,32);
    func_020307B0(allocation);
    func_02049238(arc);
    func_02082BCC(&point,0,8);
    ((struct Obj01403 *)p)->fC=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->fC,0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=func_02005728(256);
        point.y=func_02005728(256)-bound;
        point.b=3;
        point.z=func_02005728(6)+3;
        *(void **)(p+i*4+16)=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
        func_0204B3DC(*(void **)(p+i*4+16),0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    ((struct Obj01403 *)p)->f94=func_0204B294((void *)owner,((struct Obj01403 *)p)->f4,((struct Obj01403 *)p)->f0,((struct Obj01403 *)p)->f8,&point,0,heap);
    func_0204B3DC(((struct Obj01403 *)p)->f94,0);
}

void func_021D6C28(u8 *p)
{
    int i;
    void *q;
    for(i=0;i<35;i++){
        q=*(void **)(p+i*4+12);
        if(q) func_0204B3B4(q);
    }
    func_0204ADA4((u32)(((struct Obj10404 *)p)->f0));
    func_0204A8D4((u32)(((struct Obj10404 *)p)->f4));
    func_0204AFD8((u32)(((struct Obj10404 *)p)->f8));
}

void *func_021D6C58(u8 *p,int i) { return *(void **)(p+i*4+12); }

void func_021D6C60(u8 *p,int heap)
{
    void *out;
    void *raw;
    raw=func_02049F34(34,8,(u32)(&out),heap);
    func_0204ADEC(((struct Obj22852 *)p)->f0,out,7);
    func_020307B0(raw);
}

static inline int wrap(int n, u16 *p)
{
    if (*p + n >= 65536) return *p + n - 65536;
    return *(volatile u16 *)&((struct Obj10405 *)p)->f0 + n;
}

/*
 * follower: two zero padding bytes at 0x021D6CEA.
 * volatile: 0x021D6C8E and 0x021D6CA6 read the same halfword; only the latter access is volatile.
 */
void func_021D6C84(u8 *p)
{
    int i;
    ((struct Obj13938 *)p)->f98 = wrap(1024, (u16 *)(p + 0x98));
    for (i = 0; i < 5; i++)
        func_021DAAA4(14, (u16 *)(p + 0x9a) + i, ((struct Obj13938 *)p)->f98, 0, (u8)i, *(u16 *)(p + 0xba + i * 2), *(u16 *)(p + 0xda + i * 2));
}

void func_021D6CEC(u8 *p) { ((struct Obj22853 *)p)->f98=0; }

void func_021D6CF4(int *p, int heap)
{
    void *v;
    func_02082BCC(p, 0, 16);
    p[3] = 1;
    v = func_02030734(heap, 0x4800, 0, d_021DFB80, 0x482);
    p[2] = (int)v;
    p[0] = (int)func_02050C04((int)v, 0x4800, 1, heap);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D6D38(void *p)
{
    func_020307B0(((struct Obj22854 *)p)->f8);
    func_02082BCC(p, 0, 0x10);
}
