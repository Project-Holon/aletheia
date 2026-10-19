/*
 * function: BOX2_MAIN_PushNameScene
 * address: 0x021DF38C
 * packet: pkt_ov170_021DF38C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   func_02030734 0x02030734 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0200785C 0x0200785C thumb
 *   NAMEIN_SETUP_CreateArgs 0x0216BFD4 thumb ov010
 *   PROCSYS_Push 0x02031348 arm
 *   d_021F1400 0x021F1400 data a1
 *   gNameInProcData 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 * data: callback descriptor belongs to ov194 loaded by PROCSYS_Push.
 */
#include "../include/Obj10650.h"
typedef struct { void *task; void *text; } Request;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Big;
struct U16Vec;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_GetBlock(void *sys);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0200785C(void *save, unsigned box, void *dest);
extern int *NAMEIN_SETUP_CreateArgs(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);
extern void PROCSYS_Push(void *p, int a, const void *b, void *c);
extern const char d_021F1400[];
extern const unsigned gNameInProcData[];
extern const char ov194_id[];
int BOX2_MAIN_PushNameScene(char *p)
{
    int value;
    Request *r;
    value = (int)MISC_GetBlock(GAME_DATA_GetSaveControl((*(void ***)p)[0]));
    r = func_02030734(0x4B, 8, 1, d_021F1400, 0xF1F);
    r->text = STRBUF_Create(20, 0x4B);
    func_0200785C((*(void ***)p)[1], ((struct Obj10650 *)p)->f14, r->text);
    r->task = NAMEIN_SETUP_CreateArgs(0x4B, 2, 0, 0, 8, (int)r->text, value);
    PROCSYS_Push(((struct Obj10650 *)p)->f4, (int)ov194_id, gNameInProcData, r->task);
    *(Request * *)&((struct Obj10650 *)p)->fC = r;
    return 0;
}
