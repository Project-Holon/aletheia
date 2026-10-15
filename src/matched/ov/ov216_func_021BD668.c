/*
 * function: BEACON_DETAIL_GRA_AddFadeTask
 * address: 0x021BD668
 * packet: pkt_ov216_021BD668
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 * symbols:
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BEACON_DETAIL_GRA_Callback 0x021BD6BC thumb ov216
 *   BEACON_DETAIL_GRA_PlaySe 0x021BCD00 thumb ov216
 */
#include "../include/Obj03943.h"
#include "../include/Obj25779.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
struct Tcbl;
struct TcblNode;
struct S02030FB4;
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct S02030FB4 *);
extern void MI_CpuFill8(void *, int, int);
extern void BEACON_DETAIL_GRA_Callback(struct TcblNode *task, u8 *p);
extern void BEACON_DETAIL_GRA_PlaySe(int);
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct S02030FB4 *)TCBL_AddTask(*(struct Tcbl * *)&((struct Obj25779 *)owner)->f18, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_Callback, 12, 0));
    MI_CpuFill8(work, 0, 12);
    ((struct Obj03943 *)work)->f0 = direction;
    if (((struct Obj03943 *)work)->f0 == 0) {
        ((struct Obj03943 *)work)->f3 = 0;
        ((struct Obj03943 *)work)->f4 = 8;
    } else {
        ((struct Obj03943 *)work)->f3 = 64;
        ((struct Obj03943 *)work)->f4 = -8;
    }
    ((struct Obj03943 *)work)->f1 = 8;
    BEACON_DETAIL_GRA_PlaySe(1357);
    *(int * *)&((struct Obj03943 *)work)->f8 = counter;
    ++*counter;
}
