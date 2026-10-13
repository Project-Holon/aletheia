/*
 * function: func_02210420
 * address: 0x02210420
 * packet: pkt_ov198_02210420
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_ExeEnd 0x020221B8 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BGWINFRM_Delete 0x0202CA0C thumb
 *   func_02210774 0x02210774 thumb ov198
 *   func_0220E74C 0x0220E74C thumb ov198
 *   func_0220BE04 0x0220BE04 thumb ov198
 *   func_022105E4 0x022105E4 thumb ov198
 *   TCBL_Destroy 0x02031140 arm
 *   func_022119E8 0x022119E8 thumb ov198
 *   func_0220AF64 0x0220AF64 thumb ov196
 *   sub_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01006.h"
#include "../include/Obj25239.h"
#include "../include/Obj25240.h"
#include "../include/Obj25241.h"
#include "../include/Obj25243.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;struct Rec3;struct Obj;struct S02031140;struct Node;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern u32 WIPE_SYS_EndCheck(void);
extern void WIPE_SYS_ExeEnd(void);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *obj);
extern void func_02210774(u8 *p);
extern void func_0220E74C(char *);
extern void func_0220BE04(u8 *p);
extern void func_022105E4(void);
extern void TCBL_Destroy(struct S02031140 *);
extern u32 func_022119E8(u8 *);
extern void func_0220AF64(void *);
extern void sub_02030EAC(struct Node *);
extern u32 func_020307B0(void *p);
int func_02210420(struct Node *task,char *p)
{
    if(((struct Obj01006 *)p)->f2540==1) {
        if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC)==0) {
            if(((struct Obj25239 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01006 *)p)->f1EAC);
            else return 0;
        }
        if(WIPE_SYS_EndCheck()==0) {
            if(((struct Obj25240 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f34==1) WIPE_SYS_ExeEnd();
            else return 0;
        }
        if(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0) PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj01006 *)p)->f1EB0);
        if(*(struct Obj * *)&((struct Obj01006 *)p)->f2194) BGWINFRM_Delete((struct WinMgr *)(*(struct Obj * *)&((struct Obj01006 *)p)->f2194));
        func_02210774((u8 *)p);
        func_0220E74C(p);
        func_0220BE04((u8 *)p);
        func_022105E4();
        TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01006 *)p)->f1D4);
        func_022119E8((u8 *)p);
        func_0220AF64(((struct Obj01006 *)p)->f2188);
        if(((struct Obj01006 *)p)->f218C==1) **(u8 * *)&((struct Obj25241 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=1;
        else **(u8 * *)&((struct Obj25243 *)(*(char * *)&((struct Obj01006 *)p)->f0))->f44=0;
    }
    (*(u8 **)p)[0x4c]=1;
    sub_02030EAC(task);
    func_020307B0(p);
    return 1;
}
