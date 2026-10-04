/*
 * function: func_021FA6CC
 * address: 0x021FA6CC
 * packet: pkt_ov132_021FA6CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: 1 fresh 9730/9768 show and 25EA4/23F60/B3DC/B9A0/B98C bodies confirm arities; 2 fresh A5B0/A64C/A7E0 no full twin; 3 u8/const-char pointer unchanged; 4 struct-field, chained-assignment and enum-zero idioms; 5 fresh directory/neighbours.
 * spelling: enum-typed one/zero locals retain separate constant webs; literals and enum-typed stores alone left six differing bytes. Prior permuter300 was not repeated.
 * symbols:
 *   table 0x021FDC20 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_0207D658 0x0207D658 arm
 *   func_021F9730 0x021F9730 thumb ov132
 *   func_021F9768 0x021F9768 thumb ov132
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020355D8 0x020355D8 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B98C 0x0204B98C arm
 */
#include "../include/Obj00914.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef enum { FLAG_ZERO, FLAG_ONE } Flag;
typedef struct {u8 bytes[12];} Key;
typedef struct {s16 x,y;} Pos;
extern const Key table;
extern int func_02035C08(const void *);
struct Obj;
extern void func_0207D658(unsigned long,int,int),func_021F9730(void *,int),func_0204B9A0(void *),func_0204B3DC(struct Obj *,unsigned int),func_0204B404(void *,const Pos *,u32),func_020355D8(u8);
extern int func_021F9768(char *p);
extern u32 func_0204B3F4(void *),func_0204B98C(void *);
void func_021FA6CC(char *p)
{
    Key key;
    Pos pos;
    int hit;
    Flag one,zero;
    if(((struct Obj00914 *)p)->fC==1) {
        key=table;
        hit=func_02035C08(&key);
        func_0207D658(0x04001050,16,0);
        if(hit!=-1 && *(u16 *)(p+0x48+hit*2)!=255 && *(int *)(p+0x40+hit*4)==0) {
            if(hit==0) func_021F9730(((struct Obj00914 *)p)->f4,7);
            else func_021F9730(((struct Obj00914 *)p)->f4,8);
            func_0207D658(0x04001050,16,-8);
            one=FLAG_ONE;
            zero=FLAG_ZERO;
            *(u32 *)(p+0x40+hit*4)=one;
            *(u32 *)&((struct Obj00914 *)p)->f10=one;
            *(u32 *)&((struct Obj00914 *)p)->fC=zero;
            ((struct Obj00914 *)p)->f14=hit;
            pos.x=hit==0?32:224;
            pos.y=128;
            func_0204B9A0(((struct Obj00914 *)p)->f5C);
            func_0204B3DC(((struct Obj00914 *)p)->f5C,1);
            func_0204B404(((struct Obj00914 *)p)->f5C,&pos,1);
            func_020355D8(1);
        }
    }
    if(((struct Obj00914 *)p)->f14!=2) {
        if(func_021F9768(((struct Obj00914 *)p)->f4)==0) {
            if(((struct Obj00914 *)p)->f10==0) {
                ((struct Obj00914 *)p)->fC=1;
                func_0204B3DC(*(void **)(p+0x4c+((struct Obj00914 *)p)->f14*4),0);
                func_0204B3DC(*(void **)(p+0x54+((struct Obj00914 *)p)->f14*4),0);
                ((struct Obj00914 *)p)->f14=2;
            }
        } else {
            if(((struct Obj00914 *)p)->f10==1) ((struct Obj00914 *)p)->f10=0;
        }
    }
    if(func_0204B3F4(((struct Obj00914 *)p)->f5C)==1) {
        if(func_0204B98C(((struct Obj00914 *)p)->f5C)==0) func_0204B3DC(((struct Obj00914 *)p)->f5C,0);
    }
}
