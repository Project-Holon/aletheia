/*
 * file:     unit_021BCF9C.c
 * unit:     yes
 * function: func_021BCF9C, func_021BCFB4, func_021BD014, func_021BD038, func_021BD0BC, func_021BD0F0, func_021BD15C, func_021BD1A4, func_021BD318, func_021BD380, func_021BD3A8, func_021BD41C, func_021BD444, func_021BD4A8, func_021BD500, func_021BD558, func_021BD584, func_021BD5D8, func_021BD5FC, func_021BD63C, func_021BD678, func_021BD6A0, func_021BD6D0, func_021BD71C, func_021BD744, func_021BD778, func_021BD7A0, func_021BD7D4, func_021BD7E0, func_021BD814, func_021BD838, func_021BD864, func_021BD888
 * address:  0x021BCF9C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA828  0x021BA828  thumb  ov099
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   func_021BAAB8  0x021BAAB8  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 *   func_021BCC4C  0x021BCC4C  thumb  ov099
 *   func_021BDDF4  0x021BDDF4  thumb  ov099
 *   func_021BA928 0x021BA928 thumb ov099
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   func_021BBE7C  0x021BBE7C  thumb  ov099
 *   func_021BBD0C  0x021BBD0C  thumb  ov099
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   func_021BBA4C 0x021BBA4C thumb ov099
 *   func_021BBDD0 0x021BBDD0 thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BC0C4 0x021BC0C4 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   func_021BC090  0x021BC090  thumb  ov099
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_0200AE54  0x0200AE54  thumb
 *   func_021C282C  0x021C282C  thumb  ov099
 *   d_021C38EC     0x021C38EC  data  ov099  a4
 *   func_021BC104  0x021BC104  thumb  ov099
 *   func_021C18C8  0x021C18C8  thumb  ov099
 *   func_021BBEB4 0x021BBEB4 thumb ov099
 *   func_021BC06C 0x021BC06C thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 */
#include "work_types.h"
#include "../../matched/include/Obj22036.h"
#include "../../matched/include/Obj22037.h"
#include "../../matched/include/Obj18241.h"

struct BigObj;
struct Rec534;
struct Descriptor;
struct PrintSys;
struct Obj;
struct Entry;
struct Link;
struct Reg;
struct O;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BCF9C;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BCF9C;

typedef int BOOL;

typedef unsigned int u32_021BD0BC;

typedef unsigned long  u32_021BD0F0;

typedef unsigned long  u32_021BD15C;

typedef unsigned int u32_021BD1A4;

typedef signed int     s32_021BD15C;

typedef unsigned long  u32_021BD318;

typedef unsigned int u32_021BD380;

typedef signed long    s32;

typedef unsigned long  u32_021BD444;

typedef struct { u32_021BD444 v[8]; } Tbl8;

typedef unsigned int u32_021BD4A8;

typedef unsigned int u32_021BD500;

typedef unsigned int u32_021BD558;

typedef unsigned int   u32_021BD584;

typedef unsigned int   u32_021BD5FC;

typedef unsigned long  u32_021BD744;

typedef unsigned int u32_021BD778;

typedef unsigned long  u32_021BD7A0;

typedef unsigned int u32_021BD7E0;

typedef unsigned int u32_021BD814;

typedef unsigned long  u32_021BD838;

typedef unsigned long  u32_021BD864;

typedef unsigned int   u32_021BD888;

extern void func_021BA828(char *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32_021BCF9C func_021BA858(char *p);
extern void func_021BA8EC(char *p);
extern void func_021BAAB8(char *p, int a, int b);
extern u32_021BCF9C KEY_GetTrg(void);
extern void func_021BCC4C(void *a);
extern int func_021BDDF4(char *p);
extern int func_021BA928();
extern u32_021BD0F0 GFL_NET_IsParentAid();
extern int func_021BCBBC(int a, int b, int *out);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void func_021BBE7C(char *p);
extern void func_021BBD0C(char *p, int a, int b);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32_021BD1A4 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern s32_021BD15C BMP_MENULIST_Main(struct Obj *o);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern void func_021BBA4C(char *p, void *x);
extern void func_021BBDD0(void *pv, int flag);
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BD1A4 *mask);
extern void func_021BC0C4(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKE_REGULATION_GetDataSize(void);
extern u32_021BD318 GFL_NET_SendData(u32_021BD318 entry, u32_021BD318 sendID, u32_021BD318 c, u32_021BD318 d, u32_021BD318 e, u32_021BD318 f, u32_021BD318 g, u32_021BD318 h);
extern void func_021BC090(char *p);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p, u32_021BD380 lo, u32_021BD380 hi);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *h, unsigned int a, unsigned int b);
extern u32_021BCF9C func_0200AE54(struct Reg *p, u32_021BCF9C id);
extern int func_021C282C(u8 *p);
extern void func_021BC104(char *p);
extern void func_021C18C8(char *p, int kind, int value);
extern void func_021BBEB4(struct O *p, int mask, u32_021BD4A8 a, int mode);
extern void func_021BC06C(char *);
extern void func_021BA874(void *, int);
extern void GFL_NET_SetAutoExit(u8 a0);
extern int GFL_NET_SetLoginOption(int);
int func_021BCF9C(char *p, int v);
int func_021BCFB4(char *p, int v);
int func_021BD014(char *p, int v);
int func_021BD038(char *p, int v);
int func_021BD0BC(char *p, int v);
int func_021BD0F0(char *p, int v);
int func_021BD15C(char *p, int v);
int func_021BD1A4(char *p, int v);
int func_021BD318(char *p, int v);
int func_021BD380(char *p, int v);
int func_021BD3A8(char *p, int v);
int func_021BD41C(char *p, int v);
int func_021BD444(char *p);
int func_021BD4A8(char *p, int ret);
int func_021BD500(char *p, int result);
int func_021BD558(char *p, int v);
int func_021BD584(char *p, int v);
int func_021BD5D8(char *p, int v);
int func_021BD5FC(char *p, int ret);
int func_021BD63C(char *p, int v);
int func_021BD678(char *p, int v);
int func_021BD6A0(char *p, int v);
int func_021BD6D0(char *p, int v);
int func_021BD71C(char *p, int v);
int func_021BD744(char *p, int v);
int func_021BD778(char *p, int v);
int func_021BD7A0(char *p, int v);
int func_021BD7D4(u8 *p, int b);
int func_021BD7E0(char *p, int v);
int func_021BD814(char *p, int v);
int func_021BD838(char *p, int v);
int func_021BD864(char *p, int v);
int func_021BD888(char *p, int v);
int func_021BD8C0(char *p, int v);
extern const Tbl8 d_021C38EC;










/*
 * Runs the setup for selector 0x61 and stamps it 0x1CC bytes in.
 */
int func_021BCF9C(char *p, int v)
{
    func_021BA828(p);
    ((Ov099Work *)p)->f1CC = 0x61;
    return v;
}










int func_021BCFB4(char *p, int v)
{
    int r;

    GF_FONT_SetDefaultTextColor();
    r = func_021BA858(p);
    if (r == -1) {
        return v;
    }
    if (r == 0) {
        ((Ov099Work *)p)->f1CC = 0x62;
        func_021BA8EC(p);
    } else {
        if ((unsigned)(((Ov099Work *)p)->f135C - 1) <= 1) {
            ((Ov099Work *)p)->f1353 = 0x4A;
            func_021BAAB8(p, 0x4A, 0);
        } else {
            ((Ov099Work *)p)->f1353 = 0x90;
        }
        ((Ov099Work *)p)->f1CC = 0x8A;
    }
    return v;
}










/*
 * Asks the arm9 predicate at 0x020362DC about the block; on a non-zero answer
 * stamps 0x6E in the byte at +0x1353 and selector 0x8A.  Returns the second
 * argument.  The predicate takes only the block.
 */
int func_021BD014(char *p, int v)
{
    if (KEY_GetTrg() != 0) {
        ((Ov099Work *)p)->f1353 = 0x6E;
        ((Ov099Work *)p)->f1CC = 0x8A;
    }
    return v;
}










int func_021BD038(char *p, int v)
{
    func_021BCC4C(p);
    if (func_021BDDF4(p) == 0) {
        switch (((Ov099Work *)p)->f135C) {
        case 3:
            ((Ov099Work *)p)->f1CC = 0x9D;
            func_021BAAB8(p, 0x68, 0);
            return v;
        case 2:
        case 4:
            ((Ov099Work *)p)->f1CC = 0x63;
            func_021BAAB8(p, 0x68, 0);
            return v;
        default:
            ((Ov099Work *)p)->f1CC = 0x96;
            func_021BAAB8(p, 0x68, 0);
            return v;
        }
    }
    ((Ov099Work *)p)->f1353 = 0x64;
    ((Ov099Work *)p)->f1CC = 0x8A;
    return v;
}









int func_021BD0BC(char *p, int v)
{
    if (func_021BA928(p) == 0) return v;
    if (KEY_GetTrg() == 0) return v;
    ((Ov099Work *)p)->f1353 = 0x6e;
    ((Ov099Work *)p)->f1CC = 0x8a;
    return v;
}










int func_021BD0F0(char *p, int v)
{
    int t;
    int out;

    t = 0;
    if (GFL_NET_IsParentAid() == 0) {
        t = 1;
    }
    if (func_021BCBBC(((Ov099Work *)p)->f1348, ((Ov099Work *)p)->fCC, &out) != 0
        && ((Ov099Work *)p)->fCC == 0) {
        POKEPARTY_Copy(GAME_DATA_GetMyParty(((Ov099Work *)p)->fC4),
                      *(void **)((char *)((Ov099Work *)p)->f248 + t * 4 + 0x14));
        ((Ov099Work *)p)->f1CC = 0x67;
    } else {
        func_021BAAB8(p, 0x71, 0);
        ((Ov099Work *)p)->f1CC = 0x65;
    }
    return v;
}









int func_021BD15C(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }
    ((Ov099Work *)p)->f1354 = 2;
    func_021BBE7C(p);
    func_021BBD0C(p, (int)GAME_DATA_GetMyParty(((Ov099Work *)p)->fC4), ((Ov099Work *)p)->fCC);
    ((Ov099Work *)p)->f1CC = 0x66;
    return v;
}









int func_021BD1A4(char *p, int v)
{
    int five;
    void *q;
    int r;
    int out;
    u16 x[2];

    five = 0;
    q = *(void **)(p + 0x1b8);
    if (*(u8 *)(p + 0x1b0) != 0) {
        if (PRINTSYS_QUE_IsExistTarget(q, BMP_WIN_GetBmp(*(struct Descriptor **)(p + 0x1ac))) == 0) {
            BMP_WIN_TransferChars(*(struct Descriptor **)(p + 0x1ac));
            *(u8 *)(p + 0x1b0) = 0;
        }
    }
    r = BMP_MENULIST_Main(*(void **)(p + 0xbc));
    BMP_MENULIST_GetPos(*(void **)(p + 0xbc), &x[1], &x[0]);
    if (x[0] != *(u8 *)(p + 0x1354)) {
        *(u8 *)(p + 0x1354) = x[0];
        if (x[0] == 0) {
            func_021BBA4C(p, GAME_DATA_GetMyParty(*(void **)(p + 0xc4)));
            func_021BBDD0(p, 1);
        } else {
            func_021BBA4C(p, *(void **)(p + 0xcc));
            func_021BBDD0(p, 0);
        }
    }
    if (GFL_NET_IsParentAid() == 0) {
        five = 1;
    }
    switch (r) {
    case -1:
        return v;
    case -2:
        return v;
    case 0:
        if (func_021BCB70(*(void **)(p + 0x1348), *(void **)(p + 0xc4), (u32_021BD1A4 *)(&out)) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32_021BD1A4 *)(p + 0x1cc) = 0x6b;
            func_021BC0C4(p);
            return v;
        }
        POKEPARTY_Copy(GAME_DATA_GetMyParty(*(void **)(p + 0xc4)), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32_021BD1A4 *)(p + 0x1cc) = 0x67;
        break;
    case 1:
        if (func_021BCBBC((int)(*(void **)(p + 0x1348)), (int)(*(void **)(p + 0xcc)), &out) != 0) {
            func_021BAAB8(p, 0x68, 0);
            *(u32_021BD1A4 *)(p + 0x1cc) = 0x6c;
            func_021BC0C4(p);
            return v;
        }
        POKEPARTY_Copy(*(void **)(p + 0xcc), *(void **)(*(char **)(p + 0x248) + five * 4 + 0x14));
        *(u32_021BD1A4 *)(p + 0x1cc) = 0x67;
        break;
    }
    func_021BC0C4(p);
    func_021BA8EC(p);
    return v;
}








int func_021BD318(char *p, int v)
{
    int t;
    u32_021BD318 h;

    t = 0;
    if (GFL_NET_IsParentAid() == 0) {
        t = 1;
    }
    h = (u32_021BD318)GFL_NET_HANDLE_GetCurrentHandle();
    if (GFL_NET_SendData(h, 0xFF, 0xA07, POKE_REGULATION_GetDataSize(),
                      *(u32_021BD318 *)((char *)((Ov099Work *)p)->f248 + t * 4 + 0x14), 0, 0, 1) != 0) {
        func_021BAAB8(p, 0x4C, 0);
        func_021BC090(p);
        ((Ov099Work *)p)->f1CC = 0x98;
    }
    return v;
}







int func_021BD380(char *p, int v)
{
    if (func_021BA928(p) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 10);
        ((Ov099Work *)p)->f1CC = 0x68;
    }
    return v;
}








int func_021BD3A8(char *p, int v)
{
    int a;
    int b;
    int id;

    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0xA) != 0) {
        a = func_0200AE54((struct Reg *)(((Ov099Work *)p)->f1348), 2);
        b = func_0200AE54((struct Reg *)(((Ov099Work *)p)->f1348), 3);
        if (a == 3 && b == 3) {
            id = 0x92;
        } else if (a == 4 && b == 4) {
            id = 0x93;
        } else if (a == 6 && b == 6) {
            id = 0x94;
        } else {
            id = 0x91;
        }
        func_021BAAB8(p, id, 0);
        func_021BC090(p);
        ((Ov099Work *)p)->f1E0 = 0x78;
        ((Ov099Work *)p)->f1CC = 0x69;
    }
    return v;
}








int func_021BD41C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        int x = ((Ov099Work *)p)->f1E0;

        ((Ov099Work *)p)->f1E0 = x - 1;

        if (x < 0) {
            ((Ov099Work *)p)->f1CC = 0x6A;
        }
    }

    return v;
}








int func_021BD444(char *p)
{
    Tbl8 t;
    u32_021BD444 s;

    func_021C282C((u8 *)((Ov099Work *)p)->f8);
    ((Ov099Work *)p)->f1351 = 0;
    t = d_021C38EC;
    s = t.v[((Ov099Work *)p)->f134E + ((Ov099Work *)p)->f134C * 2];
    ((Ov099Work *)p)->f1D0 = s;
    func_021BC104(p);
    func_021BA8EC(p);
    func_021C18C8(p, 4, s);
    return 2;
}







int func_021BD4A8(char *p, int ret)
{
    int out;
    if (func_021BA928(p, ret) == 0) return ret;
    if (KEY_GetTrg() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(((Ov099Work *)p)->f1348), (const struct BigObj *)((int)((Ov099Work *)p)->fC4), (u32_021BD4A8 *)(&out));
        func_021BBEB4((struct O *)p, out, ((struct Obj22036 *)((u8 *)((Ov099Work *)p)->f248))->f48, 2);
        ((Ov099Work *)p)->f1CC = 0x6d;
    }
    return ret;
}







int func_021BD500(char *p, int result)
{
    int out;
    if (func_021BA928(p, result) == 0) return result;
    if (KEY_GetTrg() != 0) {
        func_021BA8EC(p);
        func_021BCBBC(((Ov099Work *)p)->f1348, ((Ov099Work *)p)->fCC, &out);
        func_021BBEB4((struct O *)p, out, ((struct Obj22037 *)((u8 *)((Ov099Work *)p)->f248))->f48, 3);
        ((Ov099Work *)p)->f1CC = 0x6d;
    }
    return result;
}







int func_021BD558(char *p, int v)
{
    if (KEY_GetTrg() != 0) {
        func_021BC06C(p);
        func_021BAAB8(p, 0x71, 0);
        ((Ov099Work *)p)->f1CC = 0x65;
    }
    return v;
}




int func_021BD584(char *p, int v)
{
    int t;
    t = func_021BA928(p);
    if (t == 0) return v;
    if (GFL_NET_IsParentAid() == 0) {
        func_021BA874(p, ((Ov099Work *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, 0);
        ((Ov099Work *)p)->f1CC = 0x6f;
    } else {
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10);
        ((Ov099Work *)p)->f1CC = 0x49;
    }
    return v;
}




int func_021BD5D8(char *p, int v)
{
    if (func_021BA928(p, v) == 0) {
        return v;
    }

    func_021BA828(p);
    ((Ov099Work *)p)->f1CC = 0x70;
    return v;
}






int func_021BD5FC(char *p, int ret)
{
    int v;
    GF_FONT_SetDefaultTextColor();
    v = func_021BA858(p);
    if (v == -1) return ret;
    if (v == 0) p[0x1353] = 0x44;
    else p[0x1353] = 0x4a;
    func_021BA8EC(p);
    ((Ov099Work *)p)->f1CC = 0x8a;
    return ret;
}






int func_021BD63C(char *p, int v)
{
    int state;
    func_021BA928(p);
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 10) != 0) {
        state = ((Ov099Work *)p)->f1357;
        if (state != 0) ((Ov099Work *)p)->f1CC = state;
        else ((Ov099Work *)p)->f1CC = 0x15;
        ((Ov099Work *)p)->f1357 = 0;
    }
    return v;
}






int func_021BD678(char *p, int v)
{
    func_021BA928(p);
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        ((Ov099Work *)p)->f1CC = 0x48;
    }
    return v;
}






int func_021BD6A0(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10);
    ((Ov099Work *)p)->f135C = 0;
    ((Ov099Work *)p)->f1CC = 0x9c;
    return v;
}






int func_021BD6D0(char *p, int v)
{
    int zero;
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10) == 0) return v;
    zero = 0;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        func_021BAAB8(p, 0x7c, zero);
    } else {
        func_021BAAB8(p, 0x7d, zero);
    }
    ((Ov099Work *)p)->f1CC = 0x8e;
    return v;
}






int func_021BD71C(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    ((Ov099Work *)p)->f1CC = 0xa9;
    return v;
}






int func_021BD744(char *p, int v)
{
    u32_021BD744 x = (unsigned int)((Ov099Work *)p)->f135C;

    if (x - 2 <= 1) {
        func_021BAAB8(p, 0x7D, 0);
    } else {
        func_021BAAB8(p, 0x7C, 0);
    }

    ((Ov099Work *)p)->f135C = 0;
    ((Ov099Work *)p)->f1CC = 0x8E;
    return v;
}





int func_021BD778(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    ((Ov099Work *)p)->f1CC = 0x99;
    return v;
}




int func_021BD7A0(char *p, int v)
{
    u32_021BD7A0 x = (unsigned int)((Ov099Work *)p)->f135C;

    if (x - 2 <= 1) {
        func_021BAAB8(p, 0x7C, 0);
    } else {
        func_021BAAB8(p, 0x7D, 0);
    }

    ((Ov099Work *)p)->f135C = 0;
    ((Ov099Work *)p)->f1CC = 0x8E;
    return v;
}



/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
int func_021BD7D4(u8 *p, int b)
{
    *(u32_021BCF9C *)(p + 0x1cc) = 0x15;
    return b;
}


int func_021BD7E0(char *p, int v)
{
    func_021C18C8(p, 1, 2);
    if (GFL_NET_IsParentAid() != 0) func_021BAAB8(p, 0x73, 0);
    else func_021BAAB8(p, 0x72, 0);
    ((Ov099Work *)p)->f1CC = 0x8e;
    return v;
}



int func_021BD814(char *p, int v)
{
    int zero = 0;
    GFL_NET_SetAutoExit(zero);
    GFL_NET_SetLoginOption(zero);
    ((Ov099Work *)p)->f1E0 = zero;
    ((Ov099Work *)p)->f1CC = 0x91;
    return v;
}




int func_021BD838(char *p, int v)
{
    u8 b = ((struct Obj18241 *)((char *)((Ov099Work *)p)->f248))->f45;
    int a;

    if (b != 0) {
        a = 0x48;
    } else {
        a = 0x49;
    }

    func_021BAAB8(p, a, 0);
    ((Ov099Work *)p)->f1CC = 0x7E;
    return v;
}




/*
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x7F.
 */
int func_021BD864(char *p, int v)
{
    if (func_021BA928(p) == 0) {
        return v;
    }

    func_021BA828(p);
    ((Ov099Work *)p)->f1CC = 0x7F;
    return v;
}



int func_021BD888(char *p, int v)
{
    int t;
    GF_FONT_SetDefaultTextColor();
    t = func_021BA858(p);
    if (t == -1) return v;
    if (t == 0) {
        ((Ov099Work *)p)->f1CC = 0x80;
    } else {
        ((Ov099Work *)p)->f1CC = 0x86;
    }
    func_021BA8EC(p);
    return v;
}



int func_021BD8C0(char *p, int v)
{
    ((Ov099Work *)p)->f1353 = 0x4a;
    ((Ov099Work *)p)->f1CC = 0x8a;
    return v;
}
