/*
 * function: func_021BD948
 * address: 0x021BD948
 * packet: pkt_ov216_021BD948
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 * symbols:
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_SetAllButtonsEnabled 0x021B64A8 thumb ov067
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021BD7D4 0x021BD7D4 thumb ov216
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BD448 0x021BD448 thumb ov216
 *   TCBL_DeleteTask 0x02031194 arm
 *   d_021BDD88 0x021BDD88 data a1
 */
#include "../include/Obj00690.h"
#include "../include/Obj25787.h"
#include "../include/Obj25788.h"
#include "../include/Obj25789.h"
#include "../include/Obj25790.h"
#include "../include/Obj25791.h"
#include "../include/Obj25792.h"
#include "../include/Obj25793.h"
#include "../include/Obj25794.h"
#include "../include/Obj25795.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct TcblNode;
struct Obj;
struct PrintSys;
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void TOUCHBAR_SetAllButtonsEnabled(u8 *,u32);
extern u32 func_0201C6B4(const struct PrintSys *);
extern void func_021BD7D4(char *,u8,int,u8,int *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_021BD448(char *p);
extern void TCBL_DeleteTask(struct TcblNode *);
extern const u8 d_021BDD88[];
void func_021BD948(struct TcblNode *task,char *work)
{
    if(((struct Obj00690 *)work)->f5==0) {
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj25787 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124)!=-1)
            ((struct Obj00690 *)work)->f5=1;
    }
    if(func_0201C6B4(*(struct PrintSys * *)&((struct Obj25788 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f12C)==0) return;
    switch(((struct Obj00690 *)work)->f0) {
    case 0:
        if(((struct Obj00690 *)work)->f5==0) break;
        TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct Obj25789 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f124,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 1:
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25790 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E,1,((struct Obj00690 *)work)->f4,(int *)(work+8));
        func_021BD7D4(*(char * *)&((struct Obj00690 *)work)->f10,((struct Obj25791 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^1,d_021BDD88[((struct Obj00690 *)work)->f4],((struct Obj00690 *)work)->f4,(int *)(work+8));
        func_0204B3DC(*(struct Obj * *)&((struct Obj25792 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f264,0);
        func_0204B3DC(*(struct Obj * *)&((struct Obj25793 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f268,0);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 2:
        if(((struct Obj00690 *)work)->f8!=0) break;
        ((struct Obj25794 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f2E^=1;
        ((struct Obj25795 *)(*(char * *)&((struct Obj00690 *)work)->f10))->f30=((struct Obj00690 *)work)->f3;
        func_021BD448(((struct Obj00690 *)work)->f10);
        ++((struct Obj00690 *)work)->f0;
        return;
    case 3:
    default:
        --**(int * *)&((struct Obj00690 *)work)->f14;
        TCBL_DeleteTask(task);
        break;
    }
}
