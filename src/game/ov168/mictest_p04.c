/*
 * file:     mictest_p04.c
 * unit:     yes
 * function: func_021844C8, func_021845AC
 * address:  0x021844C8
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218449C 0x0218449C thumb ov168
 *   func_021845E0 0x021845E0 thumb ov168
 *   func_02184600 0x02184600 thumb ov168
 *   func_0204B878 0x0204B878 arm
 *   d_02184A40 0x02184A40 data a4
 */
#include "../../matched/include/Obj01947.h"
#include "../../matched/include/Obj04544.h"

struct Obj;
struct Bank;
struct CharBuf;
struct Descriptor;
struct Rec;
struct Node;
struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0218449C(void *);
extern int func_021845E0(char *p);
extern int func_02184600(char *,int,u16,int,void *);
extern void func_0204B878(struct Obj *p, u16 value);
void func_021844C8(int event, char *p);
int func_021845AC(u8 n);
extern unsigned d_02184A40;

void func_021844C8(int event, char *p)
{
    char *q;
    int n,anim;
    if(event==0){
        q=p+0xf8;
        n=func_0218449C(q);
        if(((struct Obj04544 *)q)->f20<n){
            anim=func_021845AC(n);
            ((struct Obj04544 *)q)->f20=n;
            ((struct Obj04544 *)q)->f24=1;
        }else{
            anim=func_021845AC(((struct Obj04544 *)q)->f20);
            ((struct Obj04544 *)q)->f20-=2;
        }
        if(anim!=0){
            if(((struct Obj04544 *)q)->f24!=0){
                func_0204B878(((struct Obj01947 *)p)->f8,1);
                ((struct Obj04544 *)q)->f24=0;
            }
            if(func_021845E0(p)){
                func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
            }else{
                --((struct Obj01947 *)p)->fE0;
                if(((struct Obj01947 *)p)->fE0==0){
                    func_02184600(p,((struct Obj01947 *)p)->f14C,128,64,((struct Obj01947 *)p)->f144);
                    ((struct Obj01947 *)p)->fE0=10;
                }
            }
            func_0204B878(((struct Obj01947 *)p)->f0,anim);
            func_0204B878(((struct Obj01947 *)p)->f4,anim);
        }else if(anim==0){
            func_0204B878(((struct Obj01947 *)p)->f8,0);
            func_0204B878(((struct Obj01947 *)p)->f0,0);
            func_0204B878(((struct Obj01947 *)p)->f4,0);
        }
        ++d_02184A40;
    }
}


int func_021845AC(u8 n) { if(n<=150)return 0;if(n>=151 && n<=162)return 1;if(n>=163 && n<=176)return 2;if(n>=177 && n<=197)return 3;if(n>=198)n=4;return n; }
