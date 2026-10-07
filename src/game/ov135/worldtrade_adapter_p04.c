/*
 * file:     worldtrade_adapter_p04.c
 * unit:     yes
 * function: func_021FBF6C, func_021FBFB0, func_021FC008, func_021FC014, func_021FC06C, func_021FC174, func_021FC188, func_021FC1C0, func_021FC2A4
 * address:  0x021FBF6C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_021FB240  0x021FB240  thumb
 *   func_020307B0  0x020307B0  arm
 *   tbl_02203324 0x02203324 data a4
 *   tbl_022033F8 0x022033F8 data a4
 *   func_021F88D8  0x021F88D8  thumb  ov135
 *   func_0200ADB4 0x0200ADB4 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_0202208C 0x0202208C thumb
 *   func_021FC528 0x021FC528 thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_021FC2C0 0x021FC2C0 thumb ov135
 *   func_021FC3E0 0x021FC3E0 thumb ov135
 *   func_021FC360 0x021FC360 thumb ov135
 *   func_021FC8CC 0x021FC8CC thumb ov135
 *   func_021FCA8C 0x021FCA8C thumb ov135
 *   func_021F886C 0x021F886C thumb ov135
 *   func_021F8290 0x021F8290 thumb ov135
 *   func_021FCB54 0x021FCB54 thumb ov135
 *   g_02203CF0  0x02203CF0  data  ov135
 *   func_021FC3D0 0x021FC3D0 thumb ov135
 *   func_021FC568 0x021FC568 thumb ov135
 *   func_021FC4E4 0x021FC4E4 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_02043598  0x02043598  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   g_022034AC  0x022034AC  data  ov135
 *   g_022034DC  0x022034DC  data  ov135
 *   g_022034BC  0x022034BC  data  ov135
 *   g_022034FC  0x022034FC  data  ov135
 *   sub_020403F4  0x020403F4  arm
 */
#include "../../matched/include/Obj00287.h"

struct Obj;
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x1C];
    u32 item;
    u8 pad20[0x2C - 0x20];
    u32 f2C;
} Menu;

typedef struct { int first; int count; } Span;

typedef signed int s32;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
extern u32 func_020307B0(void *p);
extern int func_021F88D8(u32 id, u32 *start);
extern void *func_0200ADB4(void *);
extern void *func_020185F0(void *);
extern void *func_020084F4(void *);
extern int func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021FC528(char *);
extern void func_021FFFE8(u8 *,u32,u32);
extern void func_021FC2C0(void *);
extern void func_021FC3E0(void *);
extern void func_021FC360(char *);
extern void func_021FC8CC(void *,void *,void *,void **,void *,void *,void *);
extern void func_021FCA8C(void *,void *,void *,void *,void *,void *);
extern int func_021F886C(int,int,int);
extern void func_021F8290(void *,void *,int,u8 *,u32,int,int,void *);
extern void func_021FCB54(void *);
extern void func_021FC3D0(u8 *p);
extern void func_021FC568(char *p);
extern void func_021FC4E4(char *);
extern void func_022000E4(char *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021F4EC8(u8 *p);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02041570(int channel, u16 val);
extern void sub_020403F4(u32 i);
int func_021FBF6C(Menu *m, u32 idx);
int func_021FBFB0(void *p, int idx);
int func_021FC008(void *p, u32 a);
int func_021FC014(void *p, int idx);
int func_021FC06C(u8 *p);
void func_021FC174(u8 *p);
int func_021FC188(u8 *p);
void func_021FC1C0(void);
void func_021FC2A4(void);
extern const int tbl_02203324[];
extern const Span tbl_022033F8[];
extern void *g_02203CF0[];
extern struct DispConfig g_022034AC;
extern struct BgTemplate g_022034DC;
extern struct BgTemplate g_022034BC;
extern struct BgTemplate g_022034FC;


int func_021FBF6C(Menu *m, u32 idx)
{
    u32 n;
    int start;
    int end;
    u16 *list;
    int r;

    list = func_021F8498(0x48, 0, &n);
    func_021F84BC(idx, &start, &end);
    n = end - start;
    r = func_021FB240(m->f2C, m->item, n, list, start, end);
    func_020307B0(list);
    return r;
}

int func_021FBFB0(void *p, int idx)
{
    int base;
    int i;
    base = tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (func_021FBF6C(p, base + i) > 0) return 1;
        }
    } else {
        if (func_021FBF6C(p, base) > 0) return 1;
    }
    return 0;
}


/*
 * Hand the second argument to func_021F88D8 with a scratch word.
 */
int func_021FC008(void *p, u32 a)
{
    u32 tmp;

    return func_021F88D8(a, &tmp);
}

int func_021FC014(void *p, int idx)
{
    int base;
    int i;
    base = tbl_02203324[idx];
    if (tbl_022033F8[idx].count > 0) {
        for (i = 0; i < tbl_022033F8[idx].count; i++) {
            if (func_021FC008(p, base + i) > 0) return 1;
        }
    } else {
        if (func_021FC008(p, base) > 0) return 1;
    }
    return 0;
}

/*
 * note: 2026-10-05 recoup: func_0202208C declared with an int return (first-check lever). With void the
 *   literal 1 stayed in r4 for the stack store, r1, r2 and the return (4 B differ); with int the
 *   constants are rematerialised as in the original. The other callees stay void as in their matched files.
 */
int func_021FC06C(u8 *p)
{
    void *mon;
    int index;
    mon=func_0200ADB4(*(void **)(*(u8 **)p));
    func_021FC528((char *)p);
    func_021FC1C0();
    func_021FFFE8(p,0,0);
    func_021FC2C0(p);
    func_021FC3E0(p);
    func_021FC360((char *)p);
    func_021FC8CC(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(void **)(p+0xB68),(void **)(p+0xD90),func_020185F0(mon),p+0x1D0,p+0xFA0);
    func_021FCA8C(*(void **)(p+0xB6C),p+0xDAC,func_020084F4(*(void **)(*(u8 **)p+0x1C)),mon,p+0xDC0,p+0xFA0);
    index=func_021F886C(*(s8 *)(p+0x1D7),*(s8 *)(p+0x1D8),0);
    func_021F8290(*(void **)(p+0xB6C),*(void **)(p+0xB70),*(int *)(p+0xB68),p+0xDB4,*(s16 *)(p+0x1D4),*(s8 *)(p+0x1D6),index,p+0xFA0);
    func_021FCB54(mon);
    func_0202208C((void *)3,1,1,0,6,1,0x48);
    *(u32 *)(p+0x28)=0;
    *(u32 *)(p+0x12E4)=0;
    return 1;
}


/*
 * State-table dispatch through the table at 0x02203CF0.
 */
void func_021FC174(u8 *p)
{
    ((void (*)(u8 *))g_02203CF0[*(u32 *)(p + 0x28)])(p);
}

int func_021FC188(u8 *p) {func_021FC3D0(p);func_021FC568((char *)p);func_021FC4E4((char *)p);func_021FC2A4();func_022000E4((char *)p);func_0204B3DC(((struct Obj00287 *)p)->fD38,0);func_021F4EC8(p);return 0;}


/*
 * Three-layer bring-up after the display restore, with engine-B plane 0x16
 * toggled and layers 2 and 3 both 020414EC'd and tilemap-cleared.
 */
void func_021FC1C0(void)
{
    struct DispConfig c = g_022034AC;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    func_02043598(0x16, 1);
    {
        struct BgTemplate t = g_022034DC;
        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_022034BC;
        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    {
        struct BgTemplate t = g_022034FC;
        func_0203FCA0(3, &t, 0);
    }
    func_020414EC(3);
    func_02040588(3, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_02040B94(3, 0x20, 0, 0x48);
}


/*
 * Poke the channel-selection helper with 0, 1, 2, 3 in turn.
 */
void func_021FC2A4(void)
{
    sub_020403F4(0);
    sub_020403F4(1);
    sub_020403F4(2);
    sub_020403F4(3);
}
