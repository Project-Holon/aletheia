/*
 * file:     br_codein_p09.c
 * unit:     yes
 * function: func_021DD1D4, func_021DD228, func_021DD25C, func_021DD27C, func_021DD2BC
 * address:  0x021DD1D4
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_0200B98C 0x0200B98C thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj00050.h"
#include "../../matched/include/Obj06598.h"
#include "../../matched/include/Obj10731.h"
#include "../../matched/include/Obj24575.h"
#include "../../matched/include/Obj24576.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

extern void func_021FC734(u8 *p);
extern void func_020409B4(unsigned int);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD15C(void *, int);
extern unsigned long long func_0200B98C(u8 *p, int selector, int index);
extern void func_021FD860(int obj, int one, int *args);
extern void func_020061E4(u32 a);
void func_021DD1D4(char *p, char *q);
int func_021DD228(void *p);
int func_021DD25C(void *p);
int func_021DD27C(char *p, int a, int b);
int func_021DD2BC(char *p, int a, int b);

/*
 * trailing: 2 zero alignment bytes at 0x021DD226
 */
void func_021DD1D4(char *p, char *q)
{
    int i;
    char *slot;
    if (((struct Obj00050 *)p)->fE4) {
        for (i = 0; i < 2; i++) {
            slot = p + i * 4;
            if (((struct Obj10731 *)slot)->f28) {
                func_021FC734(((struct Obj10731 *)slot)->f28);
                *(int *)&((struct Obj10731 *)slot)->f28 = 0;
            }
        }
        func_020409B4(4);
        func_021FBDA4(((struct Obj06598 *)q)->f10, 30);
        if (((struct Obj00050 *)p)->f18) {
            func_021FD15C(((struct Obj00050 *)p)->f18, ((struct Obj06598 *)q)->f10);
            *(int *)&((struct Obj00050 *)p)->f18 = 0;
        }
        ((struct Obj00050 *)p)->fE4 = 0;
    }
}

/*
 * 2026-10-05 (D8 lane19): re-verified, status unchanged; sole blocker is arm9 callee 0x0200B98C (no witness outside the caller). Needs a label seed. Source is byte-correct; no C change possible.
 * blocker-symbols: func_0200B98C_Table 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 func_0200B98C_Table[];
 *   u64 func_0200B98C(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1: return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == func_0200B98C_Table[i]) return i;
 *           }
 *           return 0;
 *       case 4: return *(u64 *)(p + 0x38);
 *       case 5: return *(u8 *)(p + 0x2A);
 *       case 6: return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7: return *(u8 *)(p + 0x2B);
 *       default: return 0;
 *       }
 *   }
 */
int func_021DD228(void *p) { switch((int)func_0200B98C(p,3,0)) { case 16: case 17: case 18: case 19: case 22: return 1; case 20: case 21: default: return 0; } }

int func_021DD25C(void *p) { int result; int v; result=0; v=(int)func_0200B98C(p,3,0); if(v==20) goto yes; if(v==21) goto yes; if(v!=22) goto no; yes: return 1; no: return result; }

int func_021DD27C(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x40) <= 0x88) &
             ((unsigned int)(b - 0x10) <= 0x20);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24575 *)p)->f10, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}

int func_021DD2BC(char *p, int a, int b)
{
    int ok = ((unsigned int)(a - 0x50) <= 0x60) &
             ((unsigned int)(b - 0x38) <= 0x40);
    if (ok) {
        int args[2];
        args[0] = a;
        args[1] = b;
        func_021FD860(((struct Obj24576 *)p)->f10, 1, args);
        func_020061E4(0x703);
    }
    return ok;
}
