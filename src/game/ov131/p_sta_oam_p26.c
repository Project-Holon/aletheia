/*
 * file:     p_sta_oam_p26.c
 * unit:     yes
 * function: func_021D9EF0, func_021DA0B0
 * address:  0x021D9EF0
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02041570 0x02041570 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020409E0 0x020409E0 arm
 *   func_02040AE0 0x02040AE0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DB964 0x021DB964 thumb ov131
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B84C 0x0204B84C arm
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_021D618C 0x021D618C thumb ov131
 *   func_021D62B4 0x021D62B4 thumb ov131
 *   func_021DB6D0 0x021DB6D0 thumb ov131
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
#include "../../matched/include/Obj00136.h"
#include "../../matched/include/Obj00536.h"
#include "../../matched/include/Obj23161.h"
#include "../../matched/include/Obj23162.h"
#include "../../matched/include/Obj00112.h"
#include "../../matched/include/Obj01061.h"

struct Cfg;
struct Descriptor;
struct Obj;
struct Rec;
struct Struct36;
struct Vec2;
struct MsgBank;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct {u32 w[9];} Rec;

typedef struct {s16 x,y;} Point;

extern void func_02041570(int,u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_020409E0(u32,const void *,u32,u32);
extern void func_02040AE0(u32 index, const void *src, u32 mode);
extern void func_02041B6C(u32 bit);
extern void func_020410D0(u32,u32,u32,u32,u8,u32,u8,u8,u8,u8);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DB964(u8 *,void *,u8 *);
extern void *func_021D6064(u8 *);
extern u32 func_02017E88(void *,u32,u32);
extern void func_0204AB84(u32 idx, struct Rec *dst);
extern void func_0204B784(char *dst, const struct Struct36 *src);
extern u8 func_020275EC(int i);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B84C(void *,u32);
extern int func_021D60A4(char *p);
extern u32 func_02017E1C(void *,u32,u32);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021D618C(u8 *,void *,int,int,s16,u32);
extern void func_021D62B4(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
extern int func_021DB6D0(u32 a, u32 b, unsigned char c, u32 d);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
void func_021D9EF0(u8 *a,u8 *p);
void func_021DA0B0(u8 *a,u8 *p);

/*
 * extent: two zero alignment bytes at 021DA0AE follow the 446-byte body.
 * proof: i is a byte, i*24 <=6120. first/second remain full-word u32
 * results; unsigned address multiply/add preserve original modulo-2^32
 * lsl/add without invented selector bounds. 0204AB84 writes all nine words
 * before 0204B784 reads them; both Point halfwords are stored before use.
 */
void func_021D9EF0(u8 *a,u8 *p)
{
    Rec r1,r2;
    Point point;
    u8 i;
    void *cell;
    void *object;
    u32 first,second;
    func_02041570(4,0);
    for(i=8;i<=11;i++) {
        cell=*(void **)((p+i*4)+0x5c);
        func_02045334(cell);
        func_02045374(cell);
        func_020409B4(func_02045730(cell));
    }
    i=0;
    func_020409E0(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23161 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8,0);
    func_02040AE0(6,*(u8 * *)&((struct Obj00536 *)p)->f44+12,((struct Obj23162 *)(*(u8 * *)&((struct Obj00536 *)p)->f44))->f8);
    func_02041B6C(6);
    func_020410D0(5,0,0,32,3,(u32)(*(u8 * *)&((struct Obj00536 *)p)->f54+12),0,0,32,32);
    func_02041B6C(5);
    func_0204B3DC(((struct Obj00536 *)p)->f90,0);
    func_0204B3DC(((struct Obj00536 *)p)->f94,1);
    for(;i<p[0x2b];i++) func_021DB964(a,p,(p+0xb0)+i*24);
    object=func_021D6064(a);
    first=func_02017E88(object,174,0);
    second=func_02017E88(object,175,0);
    func_0204AB84(*(u32 *)(((u32)a+first*4u)+0x130u),(struct Rec *)(&r1));
    func_0204B784(((struct Obj00136 *)a)->f198,(const struct Struct36 *)(&r1));
    func_0204B6F4(((struct Obj00136 *)a)->f198,func_020275EC((u8)first),1);
    point.x=208;
    point.y=120;
    func_0204B404(((struct Obj00136 *)a)->f198,(const struct Vec2 *)(&point),0);
    func_0204B3DC(((struct Obj00136 *)a)->f198,1);
    func_0204B84C(((struct Obj00136 *)a)->f198,0);
    if(first!=second) {
        func_0204AB84(*(u32 *)(((u32)a+second*4u)+0x130u),(struct Rec *)(&r2));
        func_0204B784(((struct Obj00136 *)a)->f19C,(const struct Struct36 *)(&r2));
        func_0204B6F4(((struct Obj00136 *)a)->f19C,func_020275EC((u8)second),1);
        point.x=240;
        point.y=120;
        func_0204B404(((struct Obj00136 *)a)->f19C,(const struct Vec2 *)(&point),0);
        func_0204B3DC(((struct Obj00136 *)a)->f19C,1);
        func_0204B84C(((struct Obj00136 *)a)->f19C,0);
    } else func_0204B3DC(((struct Obj00136 *)a)->f19C,0);
}

/*
 * semantics: full-word results retained; only explicit u8 call arguments
 * narrow. No signed arithmetic or caller-domain assumptions.
 * prototype: 618C final stack argument is full u32 here: original stores
 * B6D0 result directly at 021DA182, with no u16 truncation; its body reads
 * only low 16 bits at 021D61A6. Narrow extern adds five absent shift pairs.
 */
void func_021DA0B0(u8 *a,u8 *p)
{
    void *data;
    u32 selected;
    int one;
    void *o1,*o2,*o3,*o4,*o5,*o6,*o7;
    u32 value;
    void *t1,*t2,*str;
    data=(void *)func_021D60A4((char *)a);
    selected=func_02017E1C(data,112,0);
    one=1;
    func_021D618C(a,((struct Obj01061 *)p)->f5C,110,25,one,15424);
    o1=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o1,0,func_02017E1C(data,160,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o1,119,89,one,1088);
    func_0201ED04(o1);
    func_021D618C(a,((struct Obj01061 *)p)->f5C,117,93,one,1088);
    o2=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o2,0,func_02017E1C(data,161,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f5C),o2,118,121,one,1088);
    func_0201ED04(o2);
    func_021D618C(a,((struct Obj01061 *)p)->f64,111,one,one,func_021DB6D0((u32)a,(u32)p,selected,one));
    o3=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o3,0,func_02017E1C(data,162,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f64),o3,120,105,one,1088);
    func_0201ED04(o3);
    func_021D618C(a,((struct Obj01061 *)p)->f68,112,one,one,func_021DB6D0((u32)a,(u32)p,selected,2));
    o4=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o4,0,func_02017E1C(data,163,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f68),o4,121,105,one,1088);
    func_0201ED04(o4);
    func_021D618C(a,((struct Obj01061 *)p)->f6C,113,one,one,func_021DB6D0((u32)a,(u32)p,selected,3));
    o5=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o5,0,func_02017E1C(data,165,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f6C),o5,122,105,one,1088);
    func_0201ED04(o5);
    func_021D618C(a,((struct Obj01061 *)p)->f70,114,one,one,func_021DB6D0((u32)a,(u32)p,selected,4));
    o6=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o6,0,func_02017E1C(data,166,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f70),o6,123,105,one,1088);
    func_0201ED04(o6);
    func_021D618C(a,((struct Obj01061 *)p)->f74,115,one,one,func_021DB6D0((u32)a,(u32)p,selected,5));
    o7=func_0201EC64(((struct Obj00112 *)a)->f0);
    func_0201EFA4(o7,0,func_02017E1C(data,164,0),3,one,one);
    func_021D62B4(a,(unsigned int)(((struct Obj01061 *)p)->f74),o7,124,105,one,1088);
    func_0201ED04(o7);
    func_021D618C(a,((struct Obj01061 *)p)->f78,116,5,one,15424);
    value=func_02017E1C(data,10,0);
    t1=func_02045B38(0,2,183,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t1,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),5,17,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t1);
    t2=func_02045B38(0,2,182,((struct Obj00112 *)a)->f0);
    str=func_02045EC0(t2,value);
    func_0201C724(((struct Obj00112 *)a)->f84,(int)func_02045770(((struct Obj01061 *)p)->f78),65,one,(u32)str,*(int *)&((struct Obj00112 *)a)->f80,1088);
    func_02045808(str);
    func_02045C04(t2);
    ((struct Obj01061 *)p)->f4=one;
}
