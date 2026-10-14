/*
 * function: WORLDTRADE_SERVER_StartNameCheck
 * address: 0x02201258
 * packet: pkt_ov135_02201258
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0217BC44 0x0217BC44 arm ov009
 */
#include "../include/Obj06520.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct U16Vec;
struct Strbuf;
extern struct U16Vec *STRBUF_Create(u32, u32);
extern void STRBUF_SetStringN(struct Strbuf *,const u16 *,u32);
extern u16 *STRBUF_GetChars(struct U16Vec *);
extern u16 STRBUF_GetLength(struct U16Vec *);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_Delete(struct U16Vec *);
extern void MI_CpuFill8(void *, int, u32);
extern int func_0217BC44(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
int WORLDTRADE_SERVER_StartNameCheck(u8 *p)
{
    struct U16Vec *s;
    u16 *text;
    u32 i;
    u16 c;
    s=STRBUF_Create(8,0x48);
    STRBUF_SetStringN((struct Strbuf *)s,(u16 *)(p+0x1F4),8);
    MI_CpuFill8(p+0x1300,0,0x28);
    ((struct Obj06520 *)p)->f1324=0x48;
    text=STRBUF_GetChars(s);
    for(i=0;i<STRBUF_GetLength(s)+1;i++) {
        c=*(u16 *)((u32)text+i*2);
        if(c==STRBUF_GetEosChar()) *(u16 *)((u32)p+i*2+0x1300)=0;
        else *(u16 *)((u32)p+i*2+0x1300)=c;
    }
    ((struct Obj06520 *)p)->f1318=(u32)(p+0x1300);
    ((struct Obj06520 *)p)->f1320=0;
    func_0217BC44((short unsigned int **)(p+0x1318),1,0,0,(char *)(p+0x131C),(int *)(p+0x1320),0x80);
    STRBUF_Delete(s);
    ((struct Obj06520 *)p)->f28=5;
    ((struct Obj06520 *)p)->fF8C=0;
    return 2;
}
