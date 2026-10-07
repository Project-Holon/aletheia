/*
 * file:     unit_0220BC70_p08.c
 * unit:     yes
 * function: func_0220E9A0, func_0220EA30
 * address:  0x0220E9A0
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
 *   func_0220E82C 0x0220E82C thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0204B404 0x0204B404 arm
 *   func_0202136C 0x0202136C thumb
 *   func_0204B878 0x0204B878 arm
 */
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef struct {short x,y;} Pair;

typedef struct {u8 low:5;u8 flip:1;u8 high:2;} Flags;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_0220E82C(char *,void *,int,int);
extern void func_0220E7CC(u8 *,unsigned);
extern void func_0204B404(struct Obj *,const struct Vec2 *,u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0202136C(u32);
void func_0220E9A0(char *p,u8 *q,Pair *pos);
void func_0220EA30(u32 mode,u8 *p,const struct Vec2 *q);

void func_0220E9A0(char *p,u8 *q,Pair *pos)
{
    int first,index;
    char *base;
    if(((Flags *)(p+0x2175))->flip==0){first=25;index=8;}
    else{first=27;index=10;}
    base=p+0x1ebc;
    func_0220E82C(p,*(void **)(base+first*4),index,q[20]);
    func_0220E7CC(*(u8 **)(base+first*4),(unsigned)pos);
    if(q[20]!=q[21]){
        func_0220E82C(p,*(void **)(p+0x1ebc+(first+1)*4),index+1,q[21]);
        func_0220E7CC(*(u8 **)(p+0x1ebc+(first+1)*4),(unsigned)(pos+1));
    }
    ((Flags *)(p+0x2175))->flip^=1;
}

void func_0220EA30(u32 mode,u8 *p,const struct Vec2 *q) { if(mode==0)func_0204B404((struct Obj *)p,q,1);else {if(func_0202136C(mode)==1)func_0204B878((struct Obj *)p,1);else func_0204B878((struct Obj *)p,0);func_0220E7CC(p,(u32)q);} }
