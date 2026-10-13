/*
 * function: func_0220D9B4
 * address: 0x0220D9B4
 * packet: pkt_ov198_0220D9B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_02211AF4 0x02211AF4 data a1
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_0220DA6C 0x0220DA6C thumb ov198
 *   func_02210DA8 0x02210DA8 thumb ov198
 *   func_0220C694 0x0220C694 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00507.h"
typedef unsigned char u8;
typedef struct { unsigned char low:7; unsigned char high:1; } Flags;
struct Descriptor;
struct Config;
extern u8 d_02211AF4[];
extern void func_0220BDA0(u8 *p);
extern void func_0220DA6C(u8 *p, int idx);
extern int func_02210DA8(u8 *p);
extern void func_0220C694(char *, int, int);
extern int func_022110D4(u8 *,int);
extern void BMP_WIN_TransferChars(struct Descriptor *);
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
void func_0220D9B4(char *p)
{
    int state, id, i;
    void *obj;
    *(u8 * *)&((struct Obj00507 *)p)->f253C = d_02211AF4;
    func_0220BDA0((u8 *)p);
    func_0220DA6C((u8 *)p, (*(u8 **)p)[32]);
    state = func_02210DA8((u8 *)p);
    if (state == 2) id = 26;
    else if (state == 3) id = 27;
    else if (state == 4) id = 28;
    else if (state == 1) id = 29;
    else id = 21;
    func_0220C694(p,1,id);
    i = func_022110D4((u8 *)p, (*(u8 **)p)[32]);
    if (((Flags *)(p + i * 76 + 27))->high == 0) {
        func_0220C694(p,2,24);
        func_0220C694(p,3,25);
        return;
    }
    obj = ((struct Obj00507 *)p)->f1F80;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
    obj = ((struct Obj00507 *)p)->f1F88;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
}
