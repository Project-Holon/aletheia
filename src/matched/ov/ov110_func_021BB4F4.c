/*
 * function: PMSIV_CATEGORY_MakeKanaWindow
 * address: 0x021BB4F4
 * packet: pkt_ov110_021BB4F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero padding
 * lever: signed loop counter; string pointer declared before counter.
 * symbols:
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PMSI_SEARCH_GetKeyCount 0x021BB1F4 thumb ov110
 *   PMSI_SEARCH_GetKeyLabel 0x021BB1F8 thumb ov110
 *   PMSI_SEARCH_GetKeyPosition 0x021BB224 thumb ov110
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj03240.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef short s16;
extern u32 PMS_INPUT_VIEW_GetFont(u8 *);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int PMSI_SEARCH_GetKeyCount(void);
extern void PMSI_SEARCH_GetKeyLabel(u32,void *);
extern void PMSI_SEARCH_GetKeyPosition(u32,int *,int *);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void STRBUF_Delete(struct U16Vec *vec);
u8 *PMSIV_CATEGORY_MakeKanaWindow(u8 *p,u8 *q) {
    u32 n,w,a;
    void *str;
    int i;
    int x,y;
    w=PMS_INPUT_VIEW_GetFont(*(u8 * *)&((struct Obj03240 *)p)->f0);
    a=BMP_WIN_Create(1,1,8,30,14,12,1);
    str=STRBUF_Create(4,42);
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)a),15);
    n=PMSI_SEARCH_GetKeyCount();
    for(i=0;i<n;i++) {
        PMSI_SEARCH_GetKeyLabel(i,str);
        PMSI_SEARCH_GetKeyPosition(i,&x,&y);
        GF_FONT_SetTextColor(1,2,15);
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)a),x+5,y,str,(void *)w);
    }
    BMP_WIN_TransferChars((struct Descriptor *)a);
    STRBUF_Delete(str);
    p+=0x90;
    *(u32 *)&((struct Obj03240 *)p)->f0=a;
    return q+0x1a4;
}
