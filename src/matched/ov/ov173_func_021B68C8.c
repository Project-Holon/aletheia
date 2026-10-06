/*
 * function: func_021B68C8
 * address: 0x021B68C8
 * packet: pkt_ov173_021B68C8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021B817C 0x021B817C thumb ov173
 *   func_021B7F50 0x021B7F50 thumb ov173
 *   func_021B80EC 0x021B80EC thumb ov173
 *   func_021B80A4 0x021B80A4 thumb ov173
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 *   func_021B80C4 0x021B80C4 thumb ov173
 *   func_021B7438 0x021B7438 thumb ov173
 *   func_021B71C4 0x021B71C4 thumb ov173
 *   func_021B70D8 0x021B70D8 thumb ov173
 *   func_021B7F64 0x021B7F64 thumb ov173
 *   func_021B7FD0 0x021B7FD0 thumb ov173
 */
#include "../include/Obj00362.h"
#include "../include/Obj24153.h"
#include "../include/Obj24154.h"
#include "../include/Obj24155.h"
#include "../include/Obj24156.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sound;
extern u8 func_020260E0(struct Sound *);
extern int func_02025DE8(struct Sound *);
extern int func_02035C60(void);
extern void func_020061E4(unsigned);
extern int func_021B817C(char *p);
extern int func_021B7F50(char *);
extern int func_021B80EC(char *,u16);
extern int func_021B80A4(char *,u16);
extern void func_021B7EB0(char *,int);
extern int func_021B80C4(u8 *p, u16 n);
extern u16 func_021B7438(char **);
extern void func_021B71C4(char *,int);
extern void func_021B70D8(char *);
extern void func_021B7F64(char *);
extern void func_021B7FD0(u8 *,int);
int func_021B68C8(char *p)
{
    u32 v;
    ((struct Obj00362 *)p)->f1CC=func_020260E0(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    v=func_02025DE8(*(struct Sound * *)&((struct Obj00362 *)p)->f1C8);
    switch(v) {
    case 0:case 1:case 2:case 3:
        if(func_02035C60()==0) {
            if(((struct Obj24153 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8) {
                func_020061E4(0x54c);
                return func_021B817C(p);
            }
        } else {
            if(((struct Obj24154 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16+v < ((struct Obj00362 *)p)->f1B8)
                func_020061E4(0x54c);
        }
        break;
    case 4:case 5:break;
    case 6:case 8:
        func_020061E4(0x54c);
        if(func_021B7F50(p)) return func_021B80EC(p,14);
        else return func_021B80A4(p,14);
    case -2:
        func_020061E4(0x54c);
        func_021B7EB0(p,0);
        return func_021B80A4(p,14);
    case 7:
        if(func_021B7F50(p)) {
            func_020061E4(0x54c);
            return func_021B80C4((u8 *)p,15);
        }
        break;
    case -8:
        if(((struct Obj24155 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16!=0) {
            func_020061E4(0x54c);
            --((struct Obj24156 *)(*(char * *)&((struct Obj00362 *)p)->f0))->f16;
            func_021B71C4(p,func_021B7438((char **)p));
            func_021B70D8(p);
            func_021B7F64(p);
            func_021B7FD0((u8 *)p,-1);
        }
        break;
    case -4:case -3:case -1:break;
    }
    return 1;
}
