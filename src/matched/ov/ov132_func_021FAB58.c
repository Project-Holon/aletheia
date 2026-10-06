/*
 * function: func_021FAB58
 * address: 0x021FAB58
 * packet: pkt_ov132_021FAB58
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02011290 0x02011290 thumb
 *   func_02011264 0x02011264 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02060614 0x02060614 arm
 *   func_021FADF8 0x021FADF8 thumb ov132
 *   func_02030DA4 0x02030DA4 arm
 */
#include "../include/Obj14093.h"
#include "../include/Obj23230.h"
#include "../include/Obj23231.h"
#include "../include/Obj23232.h"
#include "../include/Obj23233.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct ScriptVm;
extern struct ScriptVm *func_02011290(struct ScriptVm *vm);
extern void func_02011264(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
struct DList;
extern void *func_02060614(struct DList *list, void *elem);
extern void func_021FADF8(char *p, char *q);
extern void func_02030DA4(void *);
void func_021FAB58(char *p)
{
    u8 i;
    char **slot;
    void *cur;
    void *next;
    for (i = 0; i < 10; i++) {
        slot = (char **)(p + i * 4);
        if (slot[3] != 0) {
            func_02011290(((struct Obj23230 *)(slot[3]))->f4);
            func_02011264(((struct Obj23231 *)(slot[3]))->f4);
            if (((struct Obj23232 *)(slot[3]))->f16 & 8) func_020307B0(((struct Obj23233 *)(slot[3]))->fC);
            func_020307B0(slot[3]);
            slot[3] = 0;
        }
    }
    cur = func_02060614((struct DList *)(p + 0x38), 0);
    while (cur != 0) {
        next = func_02060614((struct DList *)(p + 0x38), cur);
        func_021FADF8(p, cur);
        cur = next;
    }
    func_02030DA4(((struct Obj14093 *)p)->f4);
    func_020307B0(((struct Obj14093 *)p)->f8);
    func_020307B0(p);
}
