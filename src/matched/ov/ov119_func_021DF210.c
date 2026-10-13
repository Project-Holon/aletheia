/*
 * function: func_021DF210
 * address: 0x021DF210
 * packet: pkt_ov119_021DF210
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_02039CB4 0x02039CB4 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021DD24C 0x021DD24C thumb ov119
 *   func_021DD294 0x021DD294 thumb ov119
 *   func_021DD90C 0x021DD90C thumb ov119
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF1C8 0x021DF1C8 thumb ov119
 *   func_021DEDBC 0x021DEDBC thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021DAEF0 0x021DAEF0 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj22747.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_GetHandleNetID(struct Link *p);
struct Link;
extern unsigned func_02039CB4(struct Link *, unsigned, unsigned);
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern int func_021D8A24(void *);
extern int func_021DD24C(char *p);
extern void func_021DD294(char *p, int a, int b);
typedef unsigned char  u8;
extern void func_021DD90C(u8 *p, int i, int msg, int force);
extern void func_021E1024(void *);
extern void func_021D8E84(void *, int);
extern void func_021DF1C8(void *);
extern void func_021DEDBC(void *);
extern void func_021D9434(void *);
extern void func_021DAEF0(char *p);
void func_021DF210(char *p)
{
    unsigned a, b;
    volatile int v; /* memory-resident on purpose: the original keeps v in [sp] and reads it uninitialised on the fall-through path; a plain local takes r7 */
    a = GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle());
    b = 1 - a;
    if (!func_021D8A24(p)) {
        a = 0;
        b = 1;
    }
    if (func_021D8A24(p)) {
        if (!func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1A, 8)) {
            func_021DD24C(p);
            return;
        }
    }
    func_021DD294(p, 0, 0);
    ((struct Obj00001 *)p)->f11EA = 0;
    ((struct Obj00001 *)p)->f11E8 = 3;
    ((struct Obj00001 *)p)->f11E9 = 3;
    if (*(unsigned char *)(p + a + 0x11E0) == 10 && *(unsigned char *)(p + b + 0x11E0) == 10) {
        func_021DD90C((u8 *)p, 0, 1, 1);
        func_021DD90C((u8 *)p, 1, 1, 1);
        if (((struct Obj00001 *)p)->f118C == 3) {
            func_021D8E84(p, (int)func_021DF1C8);
        } else {
            func_021D8E84(p, (int)func_021DEDBC);
        }
        return;
    }
    if (*(unsigned char *)(p + a + 0x11E0) == 4 && *(unsigned char *)(p + b + 0x11E0) == 4) {
        ((struct Obj22747 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8 = 3;
        func_021D8E84(p, (int)func_021D9434);
        return;
    }
    if (*(unsigned char *)(p + b + 0x11E0) == 4) {
        v = 0x61;
    } else if (*(unsigned char *)(p + a + 0x11E0) == 4) {
        v = 0x66;
    }
    MSGDATA_ReadString(((struct Obj00001 *)p)->f720, v, ((struct Obj00001 *)p)->f738);
    func_021E1024(p);
    ((struct Obj00001 *)p)->f11E0 = 0;
    ((struct Obj00001 *)p)->f11E1 = 0;
    ((struct Obj00001 *)p)->f11E8 = 0;
    ((struct Obj00001 *)p)->f11E9 = 0;
    func_021D8E84(p, (int)func_021DAEF0);
}
