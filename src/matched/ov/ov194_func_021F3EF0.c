/*
 * function: func_021F3EF0
 * address: 0x021F3EF0
 * packet: pkt_ov194_021F3EF0
 * region: ov194
 * status: EXACT
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F164 0x0201F164 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   STRBUF_Clone 0x02045874 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Clear 0x0204581C arm
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   func_021F46B4 0x021F46B4 thumb ov194
 */
#include "../include/Obj03900.h"
#include "../include/Obj04591.h"
typedef unsigned int u32;
typedef unsigned short u16;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern int NAMEIN_SETUP_IsCanceled(int *);
extern void NAMEIN_SETUP_CopyName(int *,int);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
typedef unsigned char  u8;
struct CharBuf;
struct Rec3;
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201F164(struct WordSet *p, u32 i, u32 a, u32 b);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void STRBUF_Clear(struct U16Vec *vec);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
/* The caller consumes R0 returned by the legacy void forwarding wrapper. */
extern int PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021F46B4(unsigned char *p, int *state);
void func_021F3EF0(char *p,char *q,int *w,u32 heap)
{
    void *set=func_0201EC64(heap);
    if(NAMEIN_SETUP_IsCanceled(w)) func_0201EEF4(set,0,(void *)w[2]);
    else {
        int text=(int)STRBUF_Clone((struct U16Vec *)w[8],heap);
        NAMEIN_SETUP_CopyName(w,text);
        func_0201EE0C(set,0,(void *)text,0,0,0);
        STRBUF_Delete((struct U16Vec *)text);
    }
    func_0201F164(set,1,w[4],w[5]);
    if(((struct Obj04591 *)p)->f0) PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj04591 *)p)->f0));
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj03900 *)q)->f14)),((struct Obj03900 *)q)->f20);
    STRBUF_Clear(((struct Obj03900 *)q)->f1C);
    func_0201F250(set,((struct Obj03900 *)q)->f1C,(void *)w[3]);
    ((struct Obj04591 *)p)->f0=PRINTSYS_PrintStream(((struct Obj03900 *)q)->f14,0,0,*(u32 *)&((struct Obj03900 *)q)->f1C,((struct Obj03900 *)q)->f4,func_02012FFC(),((struct Obj04591 *)p)->f4,2,heap,((struct Obj03900 *)q)->f20);
    ((struct Obj04591 *)p)->fE=0;
    *(void (**)(void))(p+8)=(void (*)(void))func_021F46B4;
    ((struct Obj04591 *)p)->fC=60;
    func_0201ED04(set);
}
