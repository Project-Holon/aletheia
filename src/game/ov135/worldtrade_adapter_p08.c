/*
 * file:     worldtrade_adapter_p08.c
 * unit:     yes
 * function: func_021FCED4, func_021FCF28, func_021FCFC8
 * address:  0x021FCED4
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
 *   func_021FD0F4 0x021FD0F4 thumb ov135
 *   func_021FD2FC 0x021FD2FC thumb ov135
 *   func_021FD1E0 0x021FD1E0 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02043668  0x02043668  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040588  0x02040588  arm
 *   func_02040B94  0x02040B94  arm
 *   func_020434DC  0x020434DC  arm
 *   g_02203618  0x02203618  data  ov135
 *   g_02203628  0x02203628  data  ov135
 *   g_02203648  0x02203648  data  ov135
 *   sub_020403F4  0x020403F4  arm
 */
#include "../../matched/include/Obj03069.h"

struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

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

extern void func_021FD0F4(u8 *p);
extern void func_021FD2FC(u8 *p);
extern void func_021FD1E0(u8 *p);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *p);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_02043668(void);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_020435F4(u32 a);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void sub_020403F4(u32 i);
int func_021FCED4(unsigned char *p);
void func_021FCF28(int y);
void func_021FCFC8(void);
extern struct DispConfig g_02203618;
extern struct BgTemplate g_02203628;
extern struct BgTemplate g_02203648;

int func_021FCED4(unsigned char *p)
{
    ((struct Obj03069 *)p)->fEC0 = 0;
    func_021FD0F4(p);
    func_021FD2FC(p);
    func_021FD1E0(p);
    func_021FCFC8();
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)((struct Obj03069 *)p)->fD38, 0);
    func_021F4EC8(p);
    if (*(int *)&((struct Obj03069 *)p)->f12FC == 0)
        func_0203D34C(0, 0x48);
    return 0;
}


/*
 * Three-layer bring-up: the saved display config, layers 2 and 1 enabled
 * (only 2 020414EC'd) and layer 2's 0x20x0x48 tilemap cleared.
 */
void func_021FCF28(int y)
{
    struct DispConfig c = g_02203618;
    u32 v = func_02043668();

    func_0203FC28(&c);
    func_020435F4(v);
    {
        struct BgTemplate t = g_02203628;

        func_0203FCA0(2, &t, 0);
    }
    func_020414EC(2);
    func_02040588(2, 1);
    {
        struct BgTemplate t = g_02203648;

        func_0203FCA0(1, &t, 0);
    }
    func_02040588(1, 1);
    func_02040B94(2, 0x20, 0, 0x48);
    func_020434DC(8, 0);
}


/*
 * Poke channel 1 then channel 2.
 */
void func_021FCFC8(void)
{
    sub_020403F4(1);
    sub_020403F4(2);
}
