/*
 * file:     script_command_p11.c
 * unit:     yes
 * function: func_021FD2B8, func_021FD328
 * address:  0x021FD2B8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020173E8 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj08175.h"
#include "../../matched/include/Obj14128.h"
#include "../../matched/include/Obj14129.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern u32 func_020173E8(void);
extern int func_02008468(void);
extern int func_020084BC(const u16 *values);
extern void func_02082D44(void *,void *,u32);
void func_021FD2B8(int a,int b,int c,char *p);
void *func_021FD328(int a,char *p);

/*
 * follower: loop leaf filed as ov132_func_021FD328.c.
 */
void func_021FD2B8(int a,int b,int c,char *p)
{
    u8 i;
    int n;
    u32 m,k;
    char *q,*s;
    int flag;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char * *)&((struct Obj14128 *)p)->f13C;
        k=i*(m+4+n);
        m=func_02008468();
        n=m+4+func_020173E8();
        s=p+i*0x30;
        func_02082D44(q+k,((struct Obj08175 *)s)->f8C,n);
        flag=func_020084BC(((struct Obj08175 *)s)->f84)==0 ? 1 : 0;
        ((struct Obj08175 *)s)->f60=flag;
        ((struct Obj08175 *)s)->f68=flag;
    }
    ((struct Obj14128 *)p)->f158=1;
}

void *func_021FD328(int a,char *p)
{
    u8 i;
    for(i=0;i<4;i++) *(int *)(p+i*0x30+0x68)=0;
    ((struct Obj14129 *)p)->f158=0;
    return ((struct Obj14129 *)p)->f13C;
}
