/*
 * function: func_021E1E3C
 * address: 0x021E1E3C
 * packet: pkt_ov183_021E1E3C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: keep the copied u64 and quotient distinct; use the emitted _ull_mod runtime symbol.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_REC_Load 0x0200B570 thumb
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021E1DF0 0x021E1DF0 thumb ov183
 *   func_021FF54C 0x021FF54C thumb ov186
 *   func_021FF648 0x021FF648 thumb ov186
 *   func_021FF72C 0x021FF72C thumb ov186
 *   func_021FF67C 0x021FF67C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   _ll_udiv 0x0209C00C arm
 *   _ull_mod 0x0209C018 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj01275.h"
#include "../include/Obj24638.h"
#include "../include/Obj24639.h"
#include "../include/Obj24640.h"
#include "../include/Obj24641.h"
#include "../include/Obj24642.h"
#include "../include/Obj24643.h"
#include "../include/Obj24644.h"
#include "../include/Obj24645.h"
#include "../include/Obj24646.h"
#include "../include/Obj24647.h"
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {u32 a,b;} Pair;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
typedef unsigned short u16;
extern u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);
extern int *func_021FD73C(int *p, int v);
extern void func_021E1DF0(int *a, int *state, char *p);
typedef unsigned char  u8;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_021FF54C(char *p, int kind, const int *values);
extern int func_021FF648(char *p);
extern int func_021FF72C(char *p, int *out);
extern u32 func_021FF67C(u8 *p, unsigned long long *out);
extern int func_021FC214(char *),func_021FC21C(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021FD19C(char *p, void *q, void *text);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021F9C6C(void *);
extern int func_021FD744(int *a);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_021FD860(int,int,Pair *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void func_021E1E3C(int *task,int *state,char *p) {
    u32 out;
    u64 total;
    u32 msg,x,y; Pair pair;
    void *str,*expanded,*ws,*bank;
    u64 copy,quotient;
    int result;
    switch(*state) {
    case 0:
        BATTLE_REC_Load(GAME_DATA_GetSaveControl(((struct Obj24638 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f14),89,&out,0);
        if(out==1)*state=1;else func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 1:
        ((struct Obj01275 *)p)->f1C=0;func_021FF54C(((struct Obj24639 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,2,0);*state=2;break;
    case 2:
        ++((struct Obj01275 *)p)->f1C;
        if(func_021FF648(((struct Obj24640 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10)) {
            total=0;
            if(((struct Obj01275 *)p)->f1C>=96) {
                result=func_021FF72C(((struct Obj24641 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,(int *)(&msg));
                if(result==0) {
                    if(func_021FF67C(((struct Obj24642 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f10,&total)) {
                        bank=(void *)func_021FC214(*(char * *)&((struct Obj24643 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8);
                        ws=(void *)func_021FC21C(*(char * *)&((struct Obj24644 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8);
                        str=func_02045EC0(bank,334);expanded=STRBUF_Create(128,0x8059);
                        copy=total;quotient=copy/100000;
                        func_0201EFA4(ws,2,(u32)(copy%100000),5,2,1);
                        func_0201EFA4(ws,1,(u32)(quotient%100000),5,2,1);
                        func_0201EFA4(ws,0,(u32)(quotient/100000),2,2,1);
                        func_0201F250(ws,expanded,str);
                        func_021FD19C((char *)(((struct Obj01275 *)p)->fC),(void *)(((struct Obj24645 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8),expanded);
                        STRBUF_Delete(expanded);STRBUF_Delete(str);
                    }
                } else if(result==3) {
                    func_021F9C6C(((struct Obj24646 *)(*(char * *)&((struct Obj01275 *)p)->f18))->fC);func_021FD744(task);break;
                } else func_021FD170((char *)(((struct Obj01275 *)p)->fC),(char *)(((struct Obj24647 *)(*(char * *)&((struct Obj01275 *)p)->f18))->f8),(void *)msg);
                func_021FD860(((struct Obj01275 *)p)->f10,0,0);*state=4;
            }
        }break;
    case 3:func_021FD73C((int *)task,(int)func_021E1DF0);break;
    case 4:
        if(TOUCHPANEL_GetTrg()) {
            TOUCHPANEL_GetPointTrg(&x,&y);pair.a=x;pair.b=y;func_021FD860(((struct Obj01275 *)p)->f14,1,&pair);
            GFL_USE_PlaySeDefaultVolume(0x703);*state=3;
        }break;
    }
}
