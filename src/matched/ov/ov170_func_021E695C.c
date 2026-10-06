/*
 * function: func_021E695C
 * address: 0x021E695C
 * packet: pkt_ov170_021E695C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Assign selection = 0 after the setter getter in case 1's else arm;
 *   a function-entry initializer hoists zero into the switch dispatch (256 B DIFF).
 * symbols:
 *   func_021DF040 0x021DF040 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23905.h"
#include "../include/Obj23906.h"
#include "../include/Obj23907.h"
#include "../include/Obj23908.h"
#include "../include/Obj23909.h"
#include "../include/Obj23910.h"
#include "../include/Obj23911.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern void func_021DF040(char *);
extern void func_021EC000(char *, int, int);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021ED888(char *, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EF3EC(struct WinMgr *mgr);
extern void func_020061E4(unsigned);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(u8 *);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *, int, int);
extern void func_021EE038(char *p, int a, int b, int c);
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EE364(char **, int, int);
extern void func_021DEFEC(char *p, int b);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
int func_021E695C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (((struct Obj23905 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194) {
    case 0:
        func_021DF040((char *)p);
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 4, 0);
        if (p[30] == 0) {
            func_021EF3A0(*(struct WinMgr * *)&((struct Obj23906 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        } else {
            func_021ED888(*(char * *)&((struct Obj00000 *)p)->f2C, 0);
            func_021ECB20((char *)p, 1, 1);
            func_021EF3EC(*(struct WinMgr * *)&((struct Obj23907 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        }
        func_020061E4(0x669);
        (((struct Obj23908 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 65);
    case 1:
        ((struct Obj23909 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194 = 0;
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        func_021EE038((char *)p, 0, 0, 1);
        if (p[30] == 0) {
            index = func_020260E0(((struct Obj23910 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            func_021EE364((char **)p, 7, index);
            func_021DEFEC((char *)p, index);
            func_021EF670(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 57;
        } else {
            index = func_020260E0(((struct Obj23911 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            func_021EE364((char **)p, 8, selection);
            func_021DEFEC((char *)p, selection + 30);
            func_021EF68C(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 70;
        }
    }
    return 65;
}
