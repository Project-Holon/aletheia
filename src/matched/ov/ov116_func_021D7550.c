/*
 * function: WIFI_BSUBWAY_GRAPHIC_StepWithInput
 * address: 0x021D7550
 * packet: pkt_ov116_021D7550
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: entry r0/r1 remain arguments to 7278,7324 and 81EC through dispatch.
 * symbols:
 *   func_021D69A8 0x021D69A8 thumb ov116
 *   func_021D69C0 0x021D69C0 thumb ov116
 *   func_021D69EC 0x021D69EC thumb ov116
 *   func_021D6A10 0x021D6A10 thumb ov116
 *   func_021D6A40 0x021D6A40 thumb ov116
 *   func_021D6A44 0x021D6A44 thumb ov116
 *   func_021D6A48 0x021D6A48 thumb ov116
 *   func_021D6A4C 0x021D6A4C thumb ov116
 *   func_021D6A5C 0x021D6A5C thumb ov116
 *   func_021D6AF0 0x021D6AF0 thumb ov116
 *   func_021D6B30 0x021D6B30 thumb ov116
 *   func_021D7278 0x021D7278 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTextParam 0x021D730C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_ParseCodeIn 0x021D7324 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateWindow 0x021D7B70 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteWindow 0x021D7C58 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_SetWord 0x021D8118 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateYesNo 0x021D8134 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_ProcessYesNo 0x021D8168 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon 0x021D8190 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon 0x021D81B4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartSave 0x021D81D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdateSave 0x021D81EC thumb ov116
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   func_02167ED8 0x02167ED8 arm ov009
 */
#include "../include/Obj00494.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Blk1AC;
extern u8 func_0200DC08(struct Blk1AC *p);
extern void func_021D69A8(u8 *,u8 *,u16),func_021D69EC(u8 *,u8 *,u16);
extern int func_021D69C0(u8 *,u8 *),func_021D6A10(u8 *,u8 *);
extern u16 func_021D6A40(u8 *),func_021D6A44(u8 *),func_021D6A48(u8 *);
extern int func_021D6A4C(unsigned char *p);
extern void func_021D6A5C(u8 *),func_021D6AF0(u8 *,void *),func_021D6B30(u8 *,void *);
extern void func_021D7278(u8 *,int);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p);
extern u32 WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *,u32),WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *),WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *,u32);
extern int WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
extern u32 WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(u8 *p);
extern int WIFI_BSUBWAY_GRAPHIC_UpdateSave(u8 *);
extern int FADE_IsActive(void);
extern void WIFI_BSUBWAY_GRAPHIC_SetWord(u8 *p, u32 i, u32 a, u32 b);
extern void WIFI_BSUBWAY_GRAPHIC_CreateYesNo(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_StartSave(u8 *);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int func_02167ED8(void *date, void *time);
struct BlkB90;
struct Stamp;
extern int func_0200DDD0(struct BlkB90 *p, u8 a, u8 b, const struct Stamp *q);
int WIFI_BSUBWAY_GRAPHIC_StepWithInput(u8 *p,int heap)
{
    int v,box;
    u32 n;
    u8 extra[12];
    u8 record[16];
    switch(((struct Obj00494 *)p)->fB6C) {
    case 0: func_021D69A8(p+0xb74,p+0x182c,(u32)func_0200DC08(((struct Obj00494 *)p)->f1858)); ++((struct Obj00494 *)p)->fB6C; break;
    case 1: if(func_021D69C0(p+0xb74,p+0x182c)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 2:
        WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); v=func_021D6A48(p+0xb74);
        WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)func_021D6A4C(p+0xb74)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,0); ++((struct Obj00494 *)p)->fB6C; break;
    case 3: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 4: FADE_Start((int)3,0,16,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 5: if(FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(p+4); ++((struct Obj00494 *)p)->fB6C; } break;
    case 6: func_021D7278(p,heap); ++((struct Obj00494 *)p)->fB6C; break;
    case 7: ((struct Obj00494 *)p)->fB70=WIFI_BSUBWAY_GRAPHIC_ParseCodeIn(p); WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(p); WIFI_BSUBWAY_GRAPHIC_CreateWindow(p+4,heap); FADE_Start((int)3,16,0,1); ++((struct Obj00494 *)p)->fB6C; break;
    case 8:
        if(FADE_IsActive()==0) {
            box=func_021D6A40(p+0xb74); n=((struct Obj00494 *)p)->fB70; v=func_021D6A48(p+0xb74);
            func_02167ED8(record,extra);
            if(n<1 || n>(u32)v) { ((struct Obj00494 *)p)->fB6C=16; break; }
            if(func_0200DDD0(((struct Obj00494 *)p)->f1854,box,n,(const struct Stamp *)record)!=0) { ((struct Obj00494 *)p)->fB6C=14; break; }
            func_021D69EC(p+0xb74,p+0x182c,((struct Obj00494 *)p)->fB70);
            v=func_021D6A44(p+0xb74); WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,0,v,(u32)func_021D6A4C(p+0xb74));
            WIFI_BSUBWAY_GRAPHIC_SetWord(p+4,1,func_021D6A40(p+0xb74),(u32)((void *)2)); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,1); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(p+4); ++((struct Obj00494 *)p)->fB6C;
        } break;
    case 9: if(func_021D6A10(p+0xb74,p+0x182c)!=0 && WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 10: func_021D6A5C(p+0xb74); func_021D6AF0(p+0xb74,((struct Obj00494 *)p)->f1854); func_021D6B30(p+0xb74,((struct Obj00494 *)p)->f1854); WIFI_BSUBWAY_GRAPHIC_StartSave(p); ++((struct Obj00494 *)p)->fB6C; break;
    case 11: if(WIFI_BSUBWAY_GRAPHIC_UpdateSave(p)!=0) { WIFI_BSUBWAY_GRAPHIC_DeleteTimeIcon(p+4); WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,3); ++((struct Obj00494 *)p)->fB6C; } break;
    case 12: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 13: return 1;
    case 14: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,2); ++((struct Obj00494 *)p)->fB6C; break;
    case 15: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ((struct Obj00494 *)p)->fB6C=2; break;
    case 16: WIFI_BSUBWAY_GRAPHIC_PrintMessage(p+4,4); ++((struct Obj00494 *)p)->fB6C; break;
    case 17: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(p+4)!=0) ++((struct Obj00494 *)p)->fB6C; break;
    case 18: WIFI_BSUBWAY_GRAPHIC_CreateYesNo(p+4); ++((struct Obj00494 *)p)->fB6C; break;
    case 19: v=(int)WIFI_BSUBWAY_GRAPHIC_ProcessYesNo(p+4); if(v==0) return 2; if(v==-2) ((struct Obj00494 *)p)->fB6C=2; break;
    }
    return 0;
}
