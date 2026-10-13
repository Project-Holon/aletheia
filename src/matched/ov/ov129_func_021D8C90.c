/*
 * function: func_021D8C90
 * address: 0x021D8C90
 * packet: pkt_ov129_021D8C90
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9E48 0x021D9E48 thumb ov129
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_021DA320 0x021DA320 thumb ov129
 *   func_021D97CC 0x021D97CC thumb ov129
 *   func_021D97FC 0x021D97FC thumb ov129
 *   func_021D9E60 0x021D9E60 thumb ov129
 *   func_021D97B8 0x021D97B8 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 *   d_021DA830 0x021DA830 data a4
 *   d_021DA84C 0x021DA84C data a4
 */
#include "../include/Obj00361.h"
#include "../include/Obj00411.h"
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef struct { s16 x,y; } Pair;
typedef struct { int x,y; } Scale;
extern const int d_021DA830[], d_021DA84C[];
extern void func_021D9E48(char *,int,int);
struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021DA158(int x, int flag);
extern void func_021DA320(char *);
extern int func_021D97CC(u8 *p, int value);
extern int func_021D97FC(u8 *p, int value);
extern void func_021D9E60(u8 *p, int n);
extern void func_021D97B8(char *);
extern void func_021D8AF4(char *,int);
int func_021D8C90(char *p)
{
    int i,n;
    char *q;
    Scale scale;
    Pair first,second;
    switch(((struct Obj00361 *)p)->f234) {
    case 0:
        func_021D9E48(p,0,0);
        for(i=0;i<((struct Obj00361 *)p)->f23C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f18) {
                func_0204B454(((struct Obj00411 *)q)->fC,(struct PtS *)&first,0);
                first.x+=((struct Obj00411 *)q)->f14;
                first.y+=((struct Obj00411 *)q)->f16;
                func_0204B404(((struct Obj00411 *)q)->fC,(const struct Vec2 *)(&first),0);
                (((struct Obj00411 *)q)->f18)--;
                if(i>=((struct Obj00361 *)p)->f248 && i<((struct Obj00361 *)p)->f24C) {
                    scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
                if(i>=((struct Obj00361 *)p)->f250 && i<((struct Obj00361 *)p)->f254) {
                    scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                    scale.y=scale.x;
                    CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                    (((struct Obj00411 *)q)->f19)++;
                }
            }
        }
        for(i=0;i<2;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f168) {
                func_0204B454(((struct Obj00411 *)q)->f15C,(struct PtS *)&second,0);
                second.x+=((struct Obj00411 *)q)->f164;
                second.y+=((struct Obj00411 *)q)->f166;
                func_0204B404(((struct Obj00411 *)q)->f15C,(const struct Vec2 *)(&second),0);
                (((struct Obj00411 *)q)->f168)--;
            }
        }
        if(((struct Obj00361 *)p)->f18==0) {
            for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
                q=p+i*28;
                func_0204B878(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
                q=p+i*28;
                func_0204B878(((struct Obj00411 *)q)->fC,func_021DA158(((struct Obj00411 *)q)->f0,((struct Obj00411 *)q)->f8));
            }
            (((struct Obj00361 *)p)->f234)++;
        }
        (((struct Obj00361 *)p)->f238)++;
        break;
    case 1:
        for(i=((struct Obj00361 *)p)->f248;i<((struct Obj00361 *)p)->f24C;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA830[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        for(i=((struct Obj00361 *)p)->f250;i<((struct Obj00361 *)p)->f254;i++) {
            q=p+i*28;
            if(((struct Obj00411 *)q)->f19!=6) {
                scale.x=d_021DA84C[((struct Obj00411 *)q)->f19];
                scale.y=scale.x;
                CLACT_SetActorScale(((struct Obj00411 *)q)->fC,(struct Pair *)(&scale));
                (((struct Obj00411 *)q)->f19)++;
            }
        }
        (((struct Obj00361 *)p)->f238)++;
        if(((struct Obj00361 *)p)->f238==6) (((struct Obj00361 *)p)->f234)++;
        break;
    default:
        func_021DA320(p);
        if(((struct Obj00361 *)p)->f324==0) n=func_021D97CC((u8 *)p,((struct Obj00361 *)p)->f320);
        else n=func_021D97FC((u8 *)p,((struct Obj00361 *)p)->f320);
        func_021D9E60((u8 *)p,n);
        if(((struct Obj00361 *)p)->f240) func_021D9E48(p,0,1);
        func_021D97B8(p);
        func_021D8AF4(p,1);
        break;
    }
    return 0;
}
