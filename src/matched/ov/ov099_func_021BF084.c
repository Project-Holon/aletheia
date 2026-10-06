/*
 * function: func_021BF084
 * address: 0x021BF084
 * packet: pkt_ov099_021BF084
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: duplicated calls in the final if/else-if preserve the branch-to-branch tail.
 * symbols:
 *   func_021BE788 0x021BE788 thumb ov099
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B99F4 0x021B99F4 thumb ov099
 *   func_021BE244 0x021BE244 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 *   func_021C1A14 0x021C1A14 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021B9968 0x021B9968 thumb ov099
 *   func_021C2028 0x021C2028 thumb ov099
 *   func_021BE21C 0x021BE21C thumb ov099
 *   func_02082D44 0x02082D44 arm
 *   func_021C207C 0x021C207C thumb ov099
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj22049.h"
typedef unsigned char u8;
extern int func_021BE788(char *);
typedef signed int     s32;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, unsigned int n);
extern void *func_021BE2A8(char *,int);
extern void func_021B99F4(char *,void *);
extern void func_021BE244(char *,void *);
extern void func_021C203C(char *,int);
extern void func_021C1A14(char *p, int b, void *c);
extern int func_021C23B8(int i);
extern void *func_021B9968(char *,int,int);
typedef unsigned int   u32;
extern void func_021C2028(char *p, int i, u8 v);
extern void func_021BE21C(char *,void *);
extern void func_02082D44(void *,void *,int);
extern void func_021C207C(char *);
extern void func_020061E4(u32 a);
int func_021BF084(char *p)
{
    int ret=func_021BE788(p);
    int removed=0;
    int added=0;
    int i,j,found;
    void *v;
    char *s;
    if(func_0203EFC8((const u8 *)(p+0x10),(const u8 *)(p+0x30),32)){
        for(i=0;i<32;i++){
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+j+0x10)==*(u8 *)(p+i+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x30)){
                v=func_021BE2A8(p,*(u8 *)(p+i+0x30));
                if(v){
                    func_021B99F4(p+0x274,v);
                    func_021BE244(p,v);
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                    func_021C1A14(p,*(u8 *)(p+i+0x30),(void *)33);
                    added=1;
                }else{
                    func_021C203C(p,*(u8 *)(p+i+0x30));
                }
            }
            found=0;
            for(j=0;j<32;j++){
                if(*(u8 *)(p+i+0x10)==*(u8 *)(p+j+0x30)){found=1;break;}
            }
            if(!found && *(u8 *)(p+i+0x10)){
                s=(char *)func_021C23B8(*(u8 *)(p+i+0x10)-1);
                v=func_021B9968(p+0x274,((struct Obj22049 *)s)->f14,*(u8 *)(p+i+0x10));
                if(v){
                    func_021C2028(p,*(u8 *)(p+i+0x10),2);
                    func_021BE21C(p,v);
                    removed=1;
                }else{
                    func_021C2028(p,*(u8 *)(p+i+0x10),1);
                }
            }
        }
        func_02082D44(p+0x10,p+0x30,32);
        if(removed || added)func_021C207C(p);
        if(removed==1){func_020061E4(0x676);}
        else if(added==1){func_020061E4(0x676);}
    }
    return ret;
}
