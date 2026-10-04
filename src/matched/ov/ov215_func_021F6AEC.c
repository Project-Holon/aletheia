/*
 * function: func_021F6AEC
 * address: 0x021F6AEC
 * packet: pkt_ov215_021F6AEC
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: FX float rounding macro; translation z shares the constructor's -50<<16 literal.
 * symbols:
 *   table 0x021F7384 data a4
 *   func_02017270 0x02017270 thumb
 *   func_02015FF0 0x02015FF0 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_02015CAC 0x02015CAC thumb
 *   func_02015F0C 0x02015F0C thumb
 *   func_02015F1C 0x02015F1C thumb
 *   func_02015F14 0x02015F14 thumb
 *   func_02015C78 0x02015C78 thumb
 *   func_02015E04 0x02015E04 thumb
 *   _fgr 0x0209BBB0 arm
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _ffix 0x0209C494 arm
 *   _fmul 0x0209C77C arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fdiv 0x0209CE10 arm
 */
#include "../include/Obj02262.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct {int x,y,z;} Vec;
typedef struct {u32 species;float x,y;} Entry;
extern const Entry table[];
extern void *func_02017270(void *,void *,u32,u32,u32,u32);
extern void func_02015FF0(char *,int);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02015C48(void *,u32 *);
extern void func_02015CAC(void *,u32 *);
extern u16 func_02015F0C(void *);
extern s16 func_02015F1C(void *);
extern s16 func_02015F14(void *);
extern void func_02015C78(void *,u32 *);
extern void func_02015E04(void *);
#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))
void func_021F6AEC(char *p)
{
    Vec trans,scale,delta;
    u32 species;
    u8 i=0;
    float angle,y,x;
    ((struct Obj02262 *)p)->f34=func_02017270(((struct Obj02262 *)p)->f30,((struct Obj02262 *)p)->f4,0,0,0xfff42000,0xffce0000);
    func_02015FF0(*(char * *)&((struct Obj02262 *)p)->f34,1);
    species=func_02017E1C(((struct Obj02262 *)p)->f4,171,0);
    if(species!=650){
        for(;i<4;i++){
            if(species==table[i].species){
                trans.x=FIX(table[i].x);
                trans.y=FIX(table[i].y);
                trans.z=0xffce0000;
                func_02015C48(((struct Obj02262 *)p)->f34,(u32 *)&trans);
                break;
            }
        }
    }
    scale.x=65536;scale.y=65536;scale.z=4096;
    func_02015CAC(((struct Obj02262 *)p)->f34,(u32 *)&scale);
    angle=(float)func_02015F0C(((struct Obj02262 *)p)->f34);
    y=(float)func_02015F1C(((struct Obj02262 *)p)->f34);
    x=(float)func_02015F14(((struct Obj02262 *)p)->f34);
    if(angle>96.0f)angle=96.0f;
    y=(96.0f-angle)/2.0f+y;
    x=0.0f-x;
    delta.x=FIX(x);delta.y=FIX(y);delta.z=0;
    func_02015C78(((struct Obj02262 *)p)->f34,(u32 *)&delta);
    func_02015E04(((struct Obj02262 *)p)->f34);
}
