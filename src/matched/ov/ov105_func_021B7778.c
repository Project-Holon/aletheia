/*
 * function: IRC_RESULT_Main
 * address: 0x021B7778
 * packet: pkt_ov105_021B7778
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 210-byte code; 021B784A..021B784C is two zero alignment bytes.
 * prototype: 7C94 tail-forwards u32 from own matched 0201C4E4;
 * caller tests r0. The owner's void declaration stays untouched.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_RESULT_RunPrintQueue 0x021B7C94 thumb ov105
 *   IRC_RESULT_UpdateTextWindow 0x021B7DAC thumb ov105
 *   IRC_RESULT_DrawScreen 0x021B78BC thumb ov105
 *   IRC_RESULT_UpdateRankFade 0x021B85A4 thumb ov105
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   COMPATIBLE_IRC_SYS_UpdateValueSync 0x021B63D0 thumb ov101
 */
#include "../include/Obj10249.h"
#include "../include/Obj22238.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Obj { u8 pad[0x78]; int busy; u8 pad7c[6]; u16 counter; } Obj;
extern void FADE_Start(u32,int,int,int);
extern int FADE_IsActive(void);
extern u32 IRC_RESULT_RunPrintQueue(u8 *);
extern int IRC_RESULT_UpdateTextWindow(u8 *,u8 *);
extern void IRC_RESULT_DrawScreen(u8 *),IRC_RESULT_UpdateRankFade(u8 *);
extern void IRC_APPBAR_Update(int);
extern int COMPATIBLE_IRC_SYS_UpdateValueSync(Obj *);
int IRC_RESULT_Main(void *a,u32 *state,void *b,u8 *p)
{
    Obj *object;
    switch(*state) {
    case 0: *state=1; break;
    case 1: FADE_Start(3,16,0,0); *state=2; break;
    case 2: if(!FADE_IsActive()) *state=3; break;
    case 3:
        (*(void (**)(u8 *,u16 *))(p+0x18c))(p,(u16 *)(p+0x190));
        if(((struct Obj10249 *)p)->f194) *state=4;
        break;
    case 4: FADE_Start(3,0,16,0); *state=5; break;
    case 5: if(!FADE_IsActive()) *state=6; break;
    case 6: return 1;
    }
    if(IRC_RESULT_RunPrintQueue(p+0xb0)) {
        IRC_RESULT_UpdateTextWindow(p+0xc0,p+0xb0);
        IRC_RESULT_UpdateTextWindow(p+0xd4,p+0xb0);
    }
    IRC_RESULT_DrawScreen(p);
    IRC_RESULT_UpdateRankFade(p+0x128);
    IRC_APPBAR_Update(((struct Obj10249 *)p)->f188);
    object=*(Obj * *)&((struct Obj22238 *)(*(u8 * *)&((struct Obj10249 *)p)->f1A4))->f4;
    if(object) COMPATIBLE_IRC_SYS_UpdateValueSync(object);
    return 0;
}
