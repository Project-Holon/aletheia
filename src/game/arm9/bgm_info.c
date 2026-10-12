/*
 * file:     bgm_info.c
 * unit:     yes
 * function: func_02005BC0, sub_02005C18, func_02005C28, func_02005C3C, func_02005C44, func_02005C4C, func_02005C64, func_02005C8C, func_02005CA4, func_02005CBC, func_02005CE0, func_02005D08, func_02005D14, func_02005D28, func_02005D34, func_02005D90, func_02005DA4, func_02005DAC, func_02005DE4, func_02005DF8, func_02005E04, func_02005E30, func_02005E50, func_02005E64, func_02005E9C, func_02005EB4, func_02005EE0, func_02005F24, sub_02005F38, sub_02005F5C, sub_02005F70, sub_02005F90, , func_02005FF4, func_02006118, func_02006138, func_02006148, func_0200616C, func_020061A4, func_020061E4, func_020061F0, func_020061F8, func_02006210, func_02006224, func_02006238, func_02006254, func_02006268, func_020062BC, func_02006300, func_02006368, func_02006394, func_020063B4, func_02006448, func_020064B8, func_020064F4, func_02006504, func_02006518, func_02006544, func_020065D8, func_020065FC, func_02006650, func_02006674, func_020066E8, func_02006734, func_02006740, func_0200674C, func_02006768, func_020067A4, func_020067D0, func_020067E0, func_02006868, func_02006948, func_02006984, func_020069D4, func_02006A64, func_02006A8C, func_02006AEC, func_02006B20, func_02006BB4, func_02006BD0, func_02006BE0, func_02006C00, func_02006C2C, func_02006CAC, func_02006CBC, sub_02006D44, sub_02006D64, sub_02006D94, func_02006DAC, func_02006DD8, func_02006E18, func_02006E2C, func_02006E40, func_02006E64, func_02006E7C, func_02006EA4
 * address:  0x02005BC0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g020AA260      0x020AA260  data
 *   g020AA414      0x020AA414  data
 *   func_02005FF4  0x02005FF4  thumb
 *   func_02005C3C  0x02005C3C  thumb
 *   func_02072758  0x02072758  arm
 *   func_020727B4  0x020727B4  arm
 *   func_02073108  0x02073108  arm
 *   sub_02005C18_State  0x020AA260  data
 *   func_02074758       0x02074758  arm
 *   func_02072794  0x02072794  arm
 *   sub_020058D0  0x020058D0  thumb
 *   sub_0200590C  0x0200590C  thumb
 *   sub_02005C4C_State  0x020AA260  data
 *   sub_02005C64_Obj    0x020AA354  data
 *   func_0208574C       0x0208574C  arm
 *   sub_02005CE0_State  0x020AA260  data
 *   sub_020059C8        0x020059C8  thumb
 *   func_02072D98       0x02072D98  arm
 *   func_02072E7C       0x02072E7C  arm
 *   func_02005CE0  0x02005CE0  thumb
 *   func_02005D14  0x02005D14  thumb
 *   func_02005924  0x02005924  thumb
 *   func_020055A8  0x020755A8  arm
 *   func_02005F90 0x02005F90 thumb
 *   sub_02005924   0x02005924  thumb
 *   func_020755A8  0x020755A8  arm
 *   func_02005FBC  0x02005FBC  thumb
 *   sub_02005E04_State  0x020AA260  data
 *   func_02072F5C       0x02072F5C  arm
 *   sub_02005E30_State  0x020AA260  data
 *   sub_02005E50_State  0x020AA260  data
 *   func_02072FA8  0x02072FA8  arm
 *   func_02072FC8  0x02072FC8  arm
 *   func_02073018  0x02073018  arm
 *   func_02073038  0x02073038  arm
 *   func_02073098  0x02073098  arm
 *   func_02072FE8  0x02072FE8  arm
 *   sub_02005F38_State  0x020AA260  data
 *   sub_02005D90        0x02005D90  thumb
 *   sub_02006368        0x02006368  thumb
 *   func_02072EE0       0x02072EE0  arm
 *   func_02072F34       0x02072F34  arm
 *   sub_02005FF4_State  0x020AA260  data
 *   sub_02006118_Table  0x020AA294  data
 *   sub_0200597C        0x0200597C  thumb
 *   sub_020059A0        0x020059A0  thumb
 *   _s32_div_f          0x0209C0A4  arm
 *   func_020746B0       0x020746B0  arm
 *   func_02072E9C       0x02072E9C  arm
 *   func_02085A38       0x02085A38  arm
 *   func_0207430C  0x0207430C  arm
 *   sub_0200616C_Table  0x020AA294  data
 *   sub_02006148        0x02006148  thumb
 *   func_02075560       0x02075560  arm
 *   func_02072EC8  0x02072EC8  arm
 *   sub_02006238_Table   0x020AA294  data
 *   sub_02006300_State   0x020AA260  data
 *   sub_02006300_Thread  0x020AA354  data
 *   sub_02006300_Stack   0x020AA9B4  data
 *   sub_02006224         0x02006224  thumb
 *   func_020853C0        0x020853C0  arm
 *   func_02074AC4        0x02074AC4  arm
 *   func_02085868        0x02085868  arm
 *   g_020AA260     0x020AA260  data
 *   g_020AA354     0x020AA354  data
 *   func_020855BC  0x020855BC  arm
 *   sub_02006394_State   0x020AA260  data
 *   sub_02006394_Thread  0x020AA354  data
 *   func_02074324  0x02074324  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074A98  0x02074A98  arm
 *   func_02074694  0x02074694  arm
 *   func_02074450  0x02074450  arm
 *   func_0207466C  0x0207466C  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *   g_02140484     0x02140484  data
 *   g_02140524     0x02140524  data
 *   g_02140504     0x02140504  data
 *   g_02140534     0x02140534  data
 *   g_02140488     0x02140488  data
 *   g_0209D8C0     0x0209D8C0  data
 *   func_020067D0  0x020067D0  thumb
 *   sub_02006544_State  0x02140484  data
 *   sub_02006674_File   0x020A7024  data
 *   sub_02006948        0x02006948  thumb
 *   func_02030734       0x02030734  arm
 *   func_02072CC4       0x02072CC4  arm
 *   func_020307B0       0x020307B0  arm
 *   func_02072A44  0x02072A44  arm
 *   func_02072AA0  0x02072AA0  arm
 *   func_0207457C  0x0207457C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_0208A638  0x0208A638  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_02072BDC  0x02072BDC  arm
 *   func_02072D20  0x02072D20  arm
 *   func_02072A88  0x02072A88  arm
 *   func_020067A4  0x020067A4  thumb
 *   func_02005C64  0x02005C64  thumb
 *   func_02006768  0x02006768  thumb
 *   func_020067E0  0x020067E0  thumb
 *   func_02006BE0  0x02006BE0  thumb
 *   func_02006868  0x02006868  thumb
 *   func_0200674C  0x0200674C  thumb
 *   func_02072C18  0x02072C18  arm
 *   func_02072C40  0x02072C40  arm
 *   sub_02006B20_Table  0x02140488  data
 *   func_020056EC  0x020056EC  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B64  0x02007B64  thumb
 *   func_02007B68  0x02007B68  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02007B44  0x02007B44  thumb
 *   g_020A703C   0x020A703C  data
 *   g_020A7030   0x020A7030  data
 *   g_02146164   0x02146164  data
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_0208B24C  0x0208B24C  arm
 *   func_02085D3C  0x02085D3C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed char    s8;
typedef unsigned long long u64;

#include "../../matched/include/Obj11220.h"
#include "../../matched/include/Obj01457.h"

struct Obj;
struct SNDTrackInfo;
struct Obj02072F5C;
struct Sub02006544Entry;
struct Sub02006948;
struct O;
struct S;
struct PerapVoice;
struct Sub02007084Ctrl;
struct Sub02007AC8Entry;

struct Sub02005C18State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

struct Sub02005C4CState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

struct Sub02005CE0State {
    u32   unk00;
    int (*unk04)(void *arg);
};

/* The wireless state block; src/matched/unit_02005F38.c has the whole of it,
 * this file touches one word. */
struct Su4State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
};



struct Su8State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u16 unk24;
    u16 unk26;
    u32 unk28;
    int unk2C;
    int unk30;
};


struct Sub02006118Entry {
    u32 unk00;
    u32 unk04;
};

struct SuCEntry {
    void *unk00;
    u32   unk04;
};

struct Su0State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
};


struct StructA {
    u8 pad[0x10];
    u32 unk10;
    u32 active;
};


struct Sub02006448Pair {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 unk0A;
};

struct Su8Head {
    u32 unk00 : 24;
    u32 unk03 : 8;
};

struct Sub02006544Voice {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8  unk1C;
    u8  unk1D;
    u8  lo : 4;
    u8  hi : 4;
    u8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

struct Sub02006544Pair {
    u16 lo;
    u16 hi;
};

struct Sub02006544Entry {
    u32   unk00;
    void *unk04;
    u32   unk08;
    u32   unk0C;
    void *unk10;
    u32   unk14;
    u32   unk18;
    s8    unk1C;
    s8    unk1D;
    u8    unk1E : 4;
    u8    unk1E_4 : 4;
    u8    unk1F;
    u32   unk20;
    u32   unk24;
    u8    unk28;
    u32   unk2C;
    u32   unk30;
};

struct Sub02006544State {
    u16 unk00;
    u16 unk02;
    struct Sub02006544Entry entries[3];
    u16 cur;
    u16 count;
    u32 unkA4;
    u32 unkA8;
    u8  unkAC;
};


struct Sub020067E0Block {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8  unk0C[0x30];
    u32 unk3C;
};

struct Sub020067E0Wave {
    u16 unk00;
    u16 unk02;
    u16 unk04;
};

struct Sub02006948 {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
};

struct Sub02006B20Chan {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    s8  unk1C;
    s8  unk1D;
    s8  unk1E;
    s8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

struct Sub02006CBCObj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
};

extern void  func_02005FF4(void);
extern u32 *func_02005C3C(void);
extern void  func_02072758(void);
extern u32 func_020727B4(void);
extern int   func_02073108(struct Obj *o, int trackNo, struct SNDTrackInfo *trackInfo);
extern void func_02074758(void **a0);
extern void func_02072794(u32 v);
extern u16  sub_020058D0(void);
extern u32 *sub_0200590C(void);
extern int func_0208574C(void *arg);
extern void sub_020059C8(void);
extern void func_02072D98(u32 idx, u32 val);
extern void func_02072E7C(void **r0, int fadeFrame);
extern int   func_02005CE0(void *arg);
extern void  func_02005D14(void);
extern int   func_02005924(u32 a);
extern u32 func_020755A8(u32 slot, int a, int b, int c, u32 d);
extern void func_02005F90(void);
extern int sub_02005924(unsigned int a);
extern void func_02005FBC(void);
extern void func_02072E8C(u32 a, void *p);
extern void func_02072F5C(struct Obj02072F5C * volatile *pp, u32 a, u32 b);
extern void func_02073058(struct Obj *slot, u32 key, u32 f);
extern void func_02073078(struct Obj *slot, u32 key, u32 f);
extern int func_02005A00(void);
extern int func_02005900(void);
extern int func_02005A4C(void);
extern void   func_02072FA8(struct Obj *slot, u32 key, u32 f);
extern void   func_02072FC8(struct Obj *slot, u32 key, u32 f);
extern void func_02073018(struct Obj *o, u32 v, u32 w);
extern void func_02073038(struct Obj *o, u32 v, u32 w);
extern void func_02073098(struct Obj *o, u32 v);
extern void   func_02072FE8(struct Obj *slot, u32 a, int b);
extern void sub_02005D90(u32 a, u16 b);
extern void sub_02006368(void);
extern s32 func_02072EE0(u32 tag);
extern void func_02072F34(u32 *req, int level);
extern void sub_0200597C(void);
extern int  sub_020059A0(u32 a);
extern void func_020746B0(int p0);
extern void func_02072E9C(void **r0);
extern void func_02085A38(u32 msec);
extern u8 *func_0207430C(int index);
extern int  sub_02006148(u32 a);
extern u32 func_02075560(u32 a, u32 b);
extern u16 func_02072EC8(u32 idx);
extern int sub_02006224(u32 a0);
extern u32 func_02074AC4(u32 a, u32 b, u32 c);
extern void func_020853C0(u32 *thread, void (*entry)(void *), void *arg,
                          u32 *stack, u32 size, u32 prio);
extern void func_02085868(u32 *thread);
extern void func_020855BC(void *arg);
extern void sub_020746B0(int p0);
extern void sub_02085A38(u32 v);
extern u32 sub_020755A8(u32 a, int b, int c, int d, u32 e);
extern void *func_02074324(int index);
extern void *func_020743EC(int index);
extern u32 func_02074A98(u32 a, u32 b);
extern void   func_02074694(u32 a, u32 b);
extern void *func_02074450(int index);
extern u32 func_0207466C(u32 idx);
extern void func_0208A640(u32 *a, u32 b, u32 c);
extern u32  func_0208A674(u32 a, u32 b);
extern void func_020067D0(struct Sub02006544Entry *e);
extern void  sub_02006948(struct Sub02006948 *e);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02072CC4(struct O *o);
extern u32 func_020307B0(void *p);
extern u32  func_02072A44(u32 kind);
extern int  func_02072AA0(u32 channel, u32 a, void *data, u32 b, u32 c,
                          u32 length, u32 loop, u8 volume, u32 rate, u8 pan);
extern u32  func_0207457C(u32 group);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void *func_0208A638(char *p);
extern void func_02072BDC(u32 a);
extern void func_02072D20(u32 a);
extern void func_02072A88(u32 *a);
extern void func_020067A4(struct Sub02006544Entry *p);
extern int  func_02005C64(void);
extern u16 func_02006768(void);
extern int func_020067E0(struct Sub02006544Entry *e, unsigned int v);
extern void func_02006BE0(u8 *a, unsigned int b);
extern int  func_02006868(struct Sub02006544Entry *voice);
extern u8 func_0200674C(u8 volume);
extern void func_02072C18(struct S *s, u32 v);
extern void func_02072C40(u32 a, u32 b);
extern u32   func_020056EC(u32 x);
extern u32   func_02007B50(void *p);
extern u8 *func_02007B64(struct PerapVoice *p);
extern void func_02007B68(s8 *dest, const s8 *src);
extern void  func_02048F4C(void *dst, u32 archive_id, u32 member);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);
extern void  func_02082BCC(void *p, u32 v, u32 n);
extern unsigned int func_0208BEF0(unsigned int status);
extern unsigned int func_0208BF38(unsigned int gain);
extern void  func_0208B24C(void);
extern int   func_02085D3C(void);
extern void  func_027047C0(u32 a, char *b);
void func_02005BC0(void);
void sub_02005C18(void);
void func_02005C28(u32 a0);
u32 *sub_02005C3C(void);
u16 sub_02005C44(void);
u32 sub_02005C4C(void);
int sub_02005C64(void);
int sub_02005C8C(void);
void sub_02005CA4(int a, u32 mask);
void sub_02005CBC(u32 value, u32 mask);
int sub_02005CE0(void *arg);
void sub_02005D08(int (*hook)(void *arg));
void sub_02005D14(void);
void sub_02005D28(void);
void *func_02005D34(u32 a0, u32 a1);
asm void ArrayDeleteAt(void);
void func_02005DA4(unsigned int a, unsigned short b, int c, int d);
void sub_02005DAC(void *arg);
void func_02005DE4(void *p);
void sub_02005DF8(u32 a);
void sub_02005E04(u32 a, u32 b);
void sub_02005E30(u32 a);
int sub_02005E50(void);
int func_02005E64(void);
int func_02005E9C(void);
void func_02005EB4(u32 a0);
void sub_02005EE0(u32 a, u32 b, u32 c, u32 d);
void func_02005F24(u32 a0, u32 a1);
int sub_02005F38(void);
void sub_02005F5C(void);
void sub_02005F70(u32 a, u16 b, int c, int d);
void sub_02005F90(void);
void sub_02005FBC(void);
void sub_02005FF4(void);
void sub_02006118(void);
u32 *sub_02006138(int i);
int func_02006148(u32 a0);
void sub_0200616C(void *arg, int i);
void sub_020061A4(u32 a, u32 b);
void sub_020061E4(u32 a);
void sub_020061F0(u32 a, u32 b);
void sub_020061F8(int i);
void sub_02006210(void);
int func_02006224(u32 a0);
int sub_02006238(void);
int sub_02006254(u32 a);
void sub_02006268(int i, u32 a, u32 b, u32 c);
void sub_020062BC(int i, u32 level);
void sub_020062D8(u32 *arg);
void sub_020062EC(u32 *arg);
void sub_02006300(u32 a, int mode);
void func_02006368(void);
int sub_02006394(void);
u32 func_020063B4(u8 *a0, u32 *a1, u32 a2);
int func_02006448(u32 a0, u32 a1, u32 a2);
int sub_020064B8(u32 a, u32 b, u32 c, u32 d);
void sub_020064F4(u32 a);
void sub_02006504(void);
void sub_02006518(void);
void func_02006544(u16 a0, u32 a1, u32 a2);
void sub_020065D8(void);
void sub_020065FC(void);
int sub_02006650(void);
void sub_02006674(int n, u32 heap);
void sub_020066E8(void);
void sub_02006734(u8 volume);
void sub_02006740(void);
u8 sub_0200674C(u8 volume);
u16 sub_02006768(void);
void sub_020067A4(struct Sub02006544Entry *e);
void sub_020067D0(struct Sub02006544Entry *e);
int sub_020067E0(struct Sub02006544Entry *e, u32 id);
int sub_02006868(struct Sub02006544Entry *e);
void func_02006948(struct Sub02006948 *p);
u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
int func_02006A64(u32 idx);
void func_02006A8C(u32 idx, int delta);
void func_02006AEC(u32 idx, u32 delta);
s8 sub_02006B20(u32 i);
u32 sub_02006B3C(u32 i);
u32 sub_02006B5C(u32 i);
u32 sub_02006B78(u32 i);
u32 sub_02006B94(u32 i);
void sub_02006BB4(u32 i);
u32 sub_02006BD0(u32 i);
void sub_02006BE0(u8 *p, u32 n);
void sub_02006C00(u32 species, u32 form, u32 *out);
u32 func_02006C2C(u32 species, u32 form, void **rec, void **owner, u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch);
void sub_02006CAC(void **out);
void func_02006CBC(u16 heap);
extern u8 g020AA260[];
extern u8 g020AA414[];
extern struct Sub02005C18State sub_02005C18_State;
extern struct Sub02005C4CState sub_02005C4C_State;
extern u8 sub_02005C64_Obj[];
extern struct Sub02005CE0State sub_02005CE0_State;
extern struct Su4State sub_02005E04_State;
extern struct Su4State sub_02005E30_State;
extern struct Su4State sub_02005E50_State;
extern struct Su8State sub_02005F38_State;
extern struct Su8State sub_02005FF4_State;
extern struct Sub02006118Entry sub_02006118_Table[];
extern struct SuCEntry sub_0200616C_Table[];
extern struct Su0State sub_02006300_State;
extern struct SuCEntry sub_02006238_Table[];
extern u32 sub_02006300_Thread[];
extern u32 sub_02006300_Stack[];
extern struct StructA g_020AA260;
extern u8 g_020AA354[];
extern struct Su0State sub_02006394_State;
extern u32 sub_02006394_Thread[];
extern u16 g_02140484;
extern u8  g_02140524[];
extern u8  g_02140504[];
extern u8  g_02140534[];
extern struct Sub02006544Voice g_02140488[];
extern struct Sub02006544Pair  g_0209D8C0[];
extern struct Sub02006544State sub_02006544_State;
extern const char sub_02006674_File[];
extern struct Sub02006B20Chan sub_02006B20_Table[];
extern char g_020A703C[];
extern char g_020A7030[];
extern void *g_02146164;

/*
 * Closest C for the console-init body: shut the console down, arm the two
 * handlers, take the 0x1a-byte record block from the console object, then
 * walk all 16 slots, OR-ing the occupancy bit for every slot the slot probe
 * accepts, and finally tick the delay counter at +8 down by one.
 *
 * The global is spelled as an expression at every use rather than held in a
 * named u8 *: the image re-materialises 0x020AA260 from its pool word at
 * +0042 for the tail, which a named local suppresses.
 *
 * Byte-correct as written (the earlier DIFF's 29 concrete bytes are gone): the
 * two changes that closed it were spelling the global as an expression at
 * every use instead of binding it to a named `u8 *` local -- which is what
 * makes the tail re-materialise 0x020AA260 from its pool word at +0042 -- and
 * reading the delay counter into a named local `v` so the load is reused by
 * the store.
 *
 * PARKED AT MATCH*.  Four of the seven sites have no witness outside this
 * range: func_02072758 and func_020727B4 (called only from here image-wide),
 * func_02073108 (likewise) and the record block g020AA414, whose only pool
 * word in the image is this function's own.  The third call and both other
 * relocations resolve (`label` x1/x5, `literal` x18).  The trailing `*` is the
 * unlabelled follower at 0x02005C18 (matched as src/matched/unit_02005C18.c)
 * making disasm.py's extent run to 0x02005C28.
 */
void func_02005BC0(void)
{
    u8 *p;
    int i;
    u32 v;

    func_02005FF4();
    func_02072758();
    func_020727B4();
    p = (u8 *)func_02005C3C();
    *(u16 *)g020AA260 = 0;
    for (i = 0; i < 0x10; i++) {
        if (func_02073108((struct Obj *)p, i, (struct SNDTrackInfo *)(g020AA414 + i * 0x1a)) == 1) {
            *(u16 *)g020AA260 |= (u16)(1 << i);
        }
    }
    v = *(u32 *)(g020AA260 + 8);
    if (v != 0) {
        *(u32 *)(g020AA260 + 8) = v - 1;
    }
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Sixteen bytes with no prologue that disasm.py does not label, because a
 * tail call saves nothing and its prologue sweep only recognises a function
 * that saves `lr`.  It reads one field of the state block and tail calls the
 * ARM routine at 0x02074758 with it, which in Thumb is `ldr` the address out
 * of the literal pool and `bx`: the compiler cannot encode a direct branch
 * to a different section, let alone one that changes instruction set, so the
 * target arrives as an ABS32 the linker fills in with the Thumb bit clear.
 */
void sub_02005C18(void)
{
    func_02074758((void **)sub_02005C18_State.unk10);
}

/*
 * `func_02072794(a0 != 1)`: the boolean is materialised in place of the
 * parameter (r0), so the fall-through arm carries the literal 1 and the
 * `beq` jumps to the 0.  Writing it as a `v = 1; if (a0 == 1) v = 0;` local
 * makes the compiler allocate a second register and shifts all nine bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005C28.c \
 *       --func func_02005C28 --addr 0x02005C28 --cc 1.1p1 --thumb
 */
void func_02005C28(u32 a0)
{
    func_02072794(a0 != 1);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Two eight byte forwarders, one `ldr r3, [pc]` and one `bx r3` each.  Both
 * targets are Thumb and both are reached from elsewhere in the image, so the
 * two pool words resolve with the Thumb bit set and the ranges are EXACT.
 * The pair is worth keeping as a unit because it is the cheapest possible
 * demonstration that a tail call to a function in another section is always
 * a pool word: there is nothing else in either function.
 */
u32 *sub_02005C3C(void)
{
    return sub_0200590C();
}

u16 sub_02005C44(void)
{
    return sub_020058D0();
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Three predicates.  sub_02005C8C carries no label, because it saves
 * nothing: it reads the DS interrupt enable register at 0x04000210 and
 * reports one bit of it.  0x04000210 reaches the literal pool as a plain
 * constant with no relocation, while the mask 0x80000 does not reach the
 * pool at all: `movs r0, #2` and `lsls r0, r0, #0x12` is two halfwords
 * against the four bytes a pool word plus its `ldr` would cost, so any
 * constant that is a small value shifted left is built rather than loaded.
 */
u32 sub_02005C4C(void)
{
    if (sub_02005C4C_State.unk1C == 0) {
        return sub_020058D0();
    }
    return sub_02005C4C_State.unk28;
}

int sub_02005C64(void)
{
    if (sub_02005C4C_State.unk14 == 0) {
        return 0;
    }
    if (func_0208574C(sub_02005C64_Obj) != 0) {
        return 0;
    }
    return 1;
}

int sub_02005C8C(void)
{
    if (*(volatile u32 *)0x04000210 & 0x80000) {
        return 1;
    }
    return 0;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02005D14, sub_02005D28
 *
 * A bit-per-channel broadcast and the callback hook that goes with it.
 *
 * sub_02005CA4 forwards its second argument without ever mentioning it: the
 * original never touches r1 between entry and either call, which is what a
 * parameter that is only ever passed on looks like.  The one thing to get
 * right is that both arms call the same function with a different first
 * argument rather than computing the argument and calling once; written as
 * `sub_02005CBC(a == 1 ? 0x7F : 0, b)` the compiler folds the two calls into
 * one and the function is four bytes shorter.
 */
void sub_02005CA4(int a, u32 mask)
{
    if (a == 1) {
        sub_02005CBC(0x7F, mask);
    } else {
        sub_02005CBC(0, mask);
    }
}

void sub_02005CBC(u32 value, u32 mask)
{
    int i;

    for (i = 0; i < 5; i++) {
        if ((1 << i) & mask) {
            func_02072D98(i, value);
        }
    }
}

int sub_02005CE0(void *arg)
{
    if (sub_02005C64() == 0) {
        return 1;
    }
    if (sub_02005CE0_State.unk04 == 0) {
        return 0;
    }
    return sub_02005CE0_State.unk04(arg);
}

void sub_02005D08(int (*hook)(void *arg))
{
    sub_02005CE0_State.unk04 = hook;
}

void sub_02005D14(void)
{
    func_02072E7C((void **)sub_0200590C(), 0);
    sub_020059C8();
}

void sub_02005D28(void)
{
    sub_02005F90();
    sub_02005D14();
}

/*
 *           candidates); the four early exits are all concrete.
 *
 * Open one connection slot of `size` bytes and register it: three guards,
 * each with its own `return 0` epilogue (so they are separate `if`s and not
 * a shared exit), then the slot-descriptor creation call whose first argument
 * is the slot pointer sub_0200590C returns, and a trailing `!= 0xFFFF` test
 * that re-runs the registration for the parent key.
 *
 * The third failure return reads r6 (the zero the two `-1` arguments were
 * derived from) rather than rematerialising `movs r0, #0`, which is why it is
 * spelled as a return of the same local the earlier statements used.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02005D34.c \
 *       --func func_02005D34 --addr 0x02005D34 --cc 1.1p1 --thumb
 */
void *func_02005D34(u32 a0, u32 a1)
{
    void *r;
    int   zero;

    zero = 0;
    if (func_02005CE0((void *)a0) == 0) {
        return 0;
    }
    func_02005D14();
    if (func_02005924(a0) == 0) {
        return 0;
    }
    r = (void *)func_020755A8((u32)sub_0200590C(), 0, -1, -1, a0);
    if (r == 0) {
        return (void *)zero;
    }
    if (a1 != 0xFFFF) {
        func_02005EB4(a1);
    }
    return r;
}

asm void ArrayDeleteAt(void)
{
    push {r3, r4, r5, lr}
    add r5, r0, #0
    add r4, r1, #0
    bl func_02005F90
    add r0, r5, #0
    add r1, r4, #0
    bl func_02005D34
    pop {r3, r4, r5, pc}
}

/*
 * Wrapper that forwards all four arguments to sub_02005F70.  Seeded in
 * layout/function_starts.txt from its only caller, the bl at ov012
 * 0x021745D0 (w6_fix18).
 */
void func_02005DA4(unsigned int a, unsigned short b, int c, int d)
{
    sub_02005F70(a, b, c, d);
}

/*
 * One function of a translation unit, matched as a byte range.  Written
 * from the disassembly in asm/arm9/src/000_02004000.s.
 *
 * It is recorded as a unit rather than as a single function because its
 * section is 54 bytes and the next function starts at 0x02005DE4, so the
 * extent disasm.py infers for it runs two bytes long over the linker's
 * `00 00` fill and a per-function entry would read EXACT*.  The byte range
 * comparison is over the 54 bytes the section actually occupies.
 *
 * Two guarded steps of a wireless session teardown, each abandoning the
 * function when its predicate comes back zero, and a five argument call
 * whose fifth argument goes on the stack.
 *
 * The detail worth recording is the two -1 arguments.  The original builds
 * them as
 *
 *   movs r1, #6
 *   subs r2, r1, #7
 *   adds r3, r2, #0
 *
 * that is, it derives -1 from the 6 it has just materialised for the
 * previous argument rather than spending a `movs`/`mvns` pair on it.  That
 * is a peephole on two constants that happen to be live at the same time and
 * says nothing about the source, which is a plain call with the literals
 * written out.
 *
 * The near miss this header used to record ran 0x02005DE4 through
 * 0x02005E64 and is now mostly closed.  Three of the four calls involved
 * reach func_02072F5C, from 0x02005E16 and 0x02005E22 inside sub_02005E04
 * and from 0x02005E40 inside sub_02005E30, so they are not short of evidence
 * at all: they are short of a cut.  Matched as one range all three witnesses
 * are inside the bytes under test; cut between the two functions, each file
 * is the other's witness.  That is src/matched/unit_02005DF8.c and
 * src/matched/unit_02005E30.c, both EXACT, and `python tools/match.py tu
 * --suggest-split` is what found the cut.  sub_02005E50 was already matched
 * on its own as src/matched/sub_02005E50.c.
 *
 * sub_02005DE4, 20 bytes, stays open, and no cut can help: it is the only
 * caller of 0x02072E8C anywhere in the 3.9 MB image, overlays included, so
 * the single witness for that call is the call itself.  It closes the day
 * the image acquires a second caller.  See "The honesty rule" in
 * docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02005DAC.c \
 *       --func sub_02005DAC --addr 0x02005DAC --cc 1.1p1 --thumb
 */
void sub_02005DAC(void *arg)
{
    sub_02005F90();
    if (sub_02005CE0(arg) == 0) {
        return;
    }
    sub_02005D14();
    if (sub_02005924((unsigned int)arg) == 0) {
        return;
    }
    func_020755A8((u32)sub_0200590C(), 6, -1, -1, (u32)arg);
}

/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */
void func_02005DE4(void *p)
{
    func_02005FBC();
    func_02072E8C((u32)sub_0200590C(), p);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Two of the five functions of the range the header of
 * src/matched/unit_02005DAC.c recorded as a near miss.  sub_02005E04 sets the
 * link's two power levels and remembers the first of them in the state block;
 * sub_02005DF8 is the twelve byte forwarder that supplies the fixed second
 * argument 0x7F.
 *
 * Why this is its own byte range, and where the file boundary comes from.
 * func_02072F5C is reached from exactly three `blx` sites in the whole image:
 * 0x02005E16 and 0x02005E22 inside sub_02005E04, and 0x02005E40 inside
 * sub_02005E30.  Matched as one range with sub_02005E30 all three witnesses
 * are inside the bytes under test, the honesty rule discards them all and the
 * range caps at MATCH.  Cut here, each of the two files is the other's
 * witness and both come out EXACT: this file's two sites attest
 * src/matched/unit_02005E30.c and that file's one site attests these two.
 * The cut cannot go anywhere else, because sub_02005DF8's pool word is the
 * only reference to sub_02005E04 in the image, so those two have to share a
 * range and be `local` to each other.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * `python tools/match.py tu --suggest-split`, which is what found the cut.
 *
 * sub_02005DE4, the function immediately before this range, stays open and is
 * deliberately not in this file.  It is the only caller of 0x02072E8C
 * anywhere in the image, so the single witness for that call is the call
 * itself: no cut can put it outside the range under test, and the address is
 * an ARM library routine that cannot be made `local` either.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005DF8.c \
 *       --addr 0x02005DF8 --thumb
 */
void sub_02005DF8(u32 a)
{
    sub_02005E04(a, 0x7F);
}

void sub_02005E04(u32 a, u32 b)
{
    sub_02005FBC();
    func_02072F5C((struct Obj02072F5C * volatile*)sub_0200590C(), 0, 0);
    func_02072F5C((struct Obj02072F5C * volatile*)sub_0200590C(), b, a);
    sub_02005E04_State.unk08 = a;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The one-level form of src/matched/unit_02005DF8.c's sub_02005E04: the same
 * state settle, one call instead of two, and the same word of the state block
 * written back.
 *
 * Its own byte range for an evidence reason and not a source one.  The three
 * `blx` sites that reach func_02072F5C image wide are 0x02005E16, 0x02005E22
 * and 0x02005E40; the first two are in unit_02005DF8.c and the third is this
 * function, so the two files witness each other's calls and neither may hold
 * all three.  See the header of unit_02005DF8.c and
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 *
 * The function after this range, sub_02005E50, is already matched on its own
 * as src/matched/sub_02005E50.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005E30.c \
 *       --addr 0x02005E30 --thumb
 */
void sub_02005E30(u32 a)
{
    sub_02005FBC();
    func_02072F5C((struct Obj02072F5C * volatile*)sub_0200590C(), 0, a);
    sub_02005E30_State.unk08 = a;
}

/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * Original (20 bytes, leaf, one ABS32 literal):
 *   ldr  r0, [pc, #0xc]   ; &sub_02005E50_State
 *   ldr  r0, [r0, #8]
 *   cmp  r0, #0
 *   beq  .zero
 *   movs r0, #1
 *   bx   lr
 *  .zero:
 *   movs r0, #0
 *   bx   lr
 *
 * The two-exit branch shape is what a boolean-valued != 0 compiles to in
 * Thumb, where there is no conditional move.  Returning the field itself
 * would have been three instructions with no branch at all.
 *
 * The pool word is an ABS32 relocation, resolved to the address declared
 * above; eighteen other functions load the same address from their own
 * pools.
 */
int sub_02005E50(void)
{
    return sub_02005E50_State.unk08 != 0;
}

int func_02005E64(void)
{
    sub_02005FBC();
    func_02072FA8((struct Obj *)sub_0200590C(), 0xFFFF, 0);
    func_02073058((struct Obj *)sub_0200590C(), 0xFFFF, 0);
    func_02073078((struct Obj *)sub_0200590C(), 0xFFFF, 0x10);
    return func_02005A00();
}

int func_02005E9C(void)
{
    int r;

    sub_02005FBC();
    r = func_02005900();
    if (r != 0) {
        func_02005D14();
        return func_02005A4C();
    }
    return r;
}

/*
 * Unregister one event from the connection slot's event list: the key handed
 * back is the one's complement of the argument, truncated to 16 bits by the
 * `lsls #16`/`lsrs #16` pair the conversion emits.  0xFFFF is a pool word
 * rather than a `movs`-able constant and is reused as the first call's
 * second argument, which is why it is loaded into a callee-saved register
 * before the first call instead of being rematerialised.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005EB4.c \
 *       --func func_02005EB4 --addr 0x02005EB4 --cc 1.1p1 --thumb
 */
void func_02005EB4(u32 a0)
{
    u16 key = (u16)(a0 ^ 0xFFFF);

    func_02072FA8((struct Obj *)sub_0200590C(), 0xFFFF, 0);
    if (key != 0) {
        func_02072FC8((struct Obj *)sub_0200590C(), key, 1);
    }
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Three optional fields of a request, each skipped when the caller passes
 * -1.  The -1 is rebuilt with `movs`/`mvns` before each of the three tests
 * rather than held in a register across them, which is what an inline
 * constant in three separate comparisons looks like: a variable would have
 * been allocated a register once.
 */
void sub_02005EE0(u32 a, u32 b, u32 c, u32 d)
{
    u32 *req = sub_0200590C();

    if (b != -1) {
        func_02073098((struct Obj *)req, b);
    }
    if (c != -1) {
        func_02073018((struct Obj *)req, a, c);
    }
    if (d != -1) {
        func_02073038((struct Obj *)req, a, d);
    }
}

/*
 * Forward two arguments onto one event of the current connection slot:
 * `slot` is the result of sub_0200590C (0x0200590C, matched) and stays in r0
 * across the two parameter moves, which is why the two `adds rN, rN, #0`
 * copies appear after the call rather than before it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02005F24.c \
 *       --func func_02005F24 --addr 0x02005F24 --cc 1.1p1 --thumb
 */
void func_02005F24(u32 a0, u32 a1)
{
    func_02072FE8((struct Obj *)sub_0200590C(), a0, (int)a1);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02005FBC
 *
 * The setup and teardown of the connection request block at 0x020AA260.
 * The range stops at 0x02005FF4 rather than running on to 0x02006148 for an
 * evidence reason: func_02072F34 is called from five places image wide and
 * four of them are inside sub_02005FF4, so the two files witness each
 * other's calls.
 *
 * sub_02005F5C ends in a tail call to sub_02005F90, which is in this same
 * range, and it still goes through a literal pool and `bx r3` rather than a
 * branch: one section per function means the compiler cannot encode the
 * displacement even to its own neighbour, and the pool word is an ABS32 the
 * linker fills in.  Here that makes the site `local` and costs no image
 * evidence at all.
 */
int sub_02005F38(void)
{
    if (sub_020058D0() == 0) {
        return 0;
    }
    if (func_02072EE0(sub_020058D0()) != 0) {
        return 1;
    }
    return 0;
}

void sub_02005F5C(void)
{
    sub_02005F38_State.unk2C = 60;
    sub_02005F38_State.unk30 = 60;
    sub_02005F90();
}

void sub_02005F70(u32 a, u16 b, int c, int d)
{
    sub_02005F38_State.unk26 = b;
    sub_02005F38_State.unk28 = a;
    sub_02005F38_State.unk2C = d;
    sub_02005F38_State.unk30 = c;
    sub_02005F38_State.unk24 = c;
    sub_02006368();
    sub_02005F38_State.unk20 = 0;
    sub_02005F38_State.unk1C = 1;
}

void sub_02005F90(void)
{
    sub_02005F38_State.unk1C = 0;
    sub_02005F38_State.unk26 = 0xFFFF;
    sub_02005F38_State.unk28 = 0;
    sub_02005F38_State.unk24 = 0;
    func_02072F34(sub_0200590C(), 0x7F);
    sub_02005F38_State.unk20 = 0;
    sub_02006368();
}

void sub_02005FBC(void)
{
    u32 id;

    if (sub_02005F38_State.unk1C != 1) {
        return;
    }
    id = sub_020058D0();
    if (id != sub_02005F38_State.unk28) {
        while (sub_02005F38_State.unk20 != 0) {
            sub_02005FF4();
        }
        sub_02005D90(sub_02005F38_State.unk28, sub_02005F38_State.unk26);
    }
    sub_02005F90();
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The three state connection pump, plus the initialiser and the address-of
 * accessor for the five entry table at 0x020AA294.
 *
 * sub_02005FF4 is where the signal strength bar comes from: `unk24` counts
 * up towards `unk2C` while the current access point matches the one being
 * connected to and back down towards zero when it does not, and the value
 * handed to func_02072F34 is `unk24 * 0x7F / unk2C` or `unk24 * 0x7F /
 * unk30`.  Both divisions are signed, so they call the compiler's own
 * `_s32_div_f` helper rather than `_u32_div_f`: `unk24` is a `u16` that
 * promotes to `int` and the two limits are `int`.  Getting that wrong is not
 * a codegen difference but a relocation with a different symbol name, and
 * the name is what the harness resolves against.
 *
 * sub_02006138 carries no label: it is `lsls`, `adds`, `adds`, `bx lr`, the
 * address of one table entry's second word, and it saves nothing, so
 * disasm.py's prologue sweep cannot see it.
 */
void sub_02005FF4(void)
{
    u32 *req = sub_0200590C();
    u16 id = sub_020058D0();

    if (sub_02005FF4_State.unk1C == 0) {
        return;
    }
    switch (sub_02005FF4_State.unk20) {
    case 0:
        if (id != 0) {
            if (id != sub_02005FF4_State.unk28) {
                if (sub_02005FF4_State.unk24 != 0) {
                    sub_02005FF4_State.unk24--;
                    func_02072F34(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk30);
                    return;
                }
                func_02072F34(req, 0);
            } else {
                if (sub_02005FF4_State.unk24 < sub_02005FF4_State.unk2C) {
                    sub_02005FF4_State.unk24++;
                    func_02072F34(req, sub_02005FF4_State.unk24 * 0x7F /
                                       sub_02005FF4_State.unk2C);
                    return;
                }
                sub_02005F90();
                return;
            }
        }
        sub_02005D14();
        if (sub_02005FF4_State.unk28 == 0) {
            sub_02005F90();
            return;
        }
        func_020746B0(0x1300);
        sub_02006300(sub_02005FF4_State.unk28, 0);
        sub_02005FF4_State.unk24 = 0;
        sub_02005FF4_State.unk20 = 1;
        return;
    case 1:
        if (sub_02006394() == 1) {
            sub_0200597C();
            sub_02006300(sub_02005FF4_State.unk28, 1);
            sub_02005FF4_State.unk20 = 2;
            return;
        }
        func_02085A38(1);
        return;
    case 2:
        if (sub_02006394() == 1) {
            func_020746B0(0);
            sub_020059A0(sub_02005FF4_State.unk28);
            func_020755A8((u32)sub_0200590C(), 0, -1, -1,
                          sub_02005FF4_State.unk28);
            func_02072F34(req, 0);
            sub_02005FF4_State.unk20 = 0;
            return;
        }
        func_02085A38(1);
        return;
    }
}

void sub_02006118(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        sub_02006118_Table[i].unk00 = 0;
        func_02072E9C((void **)(&sub_02006118_Table[i].unk04));
    }
}

u32 *sub_02006138(int i)
{
    return &sub_02006118_Table[i].unk04;
}

/*
 * Two `return 1`s cross-jump into one block, and the block lands between the
 * second test and the body - which is what makes the second branch `blo`
 * (branch on the *acceptance* test to the body) rather than the `bhs` a
 * conjunction emits.  So the source has the two guards in this order, each
 * with its own return, and the last `return 1` is the one that ends up as
 * the shared block.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006148.c \
 *       --func func_02006148 --addr 0x02006148 --cc 1.1p1 --thumb
 */
int func_02006148(u32 a0)
{
    if (a0 < 0x546) {
        goto fail;
    }
    if (a0 < 0x81B) {
        goto ok;
    }
fail:
    return 1;
ok:
    return func_0207430C(a0)[5] - 1;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_020061F8, sub_02006210
 *
 * Registering and tearing down the five entries of the table at 0x020AA294,
 * and three forwarders over sub_020061A4.  sub_020061E4 and sub_020061F0
 * both tail call it through the same pool word, the first supplying a -1 for
 * the second argument and the second passing both of its own straight
 * through, which is four bytes of code and one relocation each.
 */
void sub_0200616C(void *arg, int i)
{
    if (sub_02005CE0(arg) == 0) {
        return;
    }
    sub_0200616C_Table[i].unk00 = 0;
    if (func_020755A8((u32)(&sub_0200616C_Table[i].unk04), i + 1, -1, -1, (u32)arg) == 1) {
        sub_0200616C_Table[i].unk00 = arg;
    }
}

void sub_020061A4(u32 a, u32 b)
{
    int i;

    if (sub_02005CE0((void *)a) == 0) {
        return;
    }
    i = sub_02006148(a);
    sub_0200616C_Table[i].unk00 = 0;
    if (func_02075560((u32)(&sub_0200616C_Table[i].unk04), a) != 1) {
        return;
    }
    sub_0200616C_Table[i].unk00 = (void *)a;
    if (b < 0x80) {
        sub_020062BC(i, b);
    }
}

void sub_020061E4(u32 a)
{
    sub_020061A4(a, -1);
}

void sub_020061F0(u32 a, u32 b)
{
    sub_020061A4(a, b);
}

void sub_020061F8(int i)
{
    func_02072E7C((void **)(&sub_0200616C_Table[i].unk04), 0);
}

void sub_02006210(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        sub_020061F8(i);
    }
}

/*
 * `a0` is incremented in place before the call, so the source added one to
 * the parameter rather than passing a computed local; the boolean comes back
 * as two `return` constants rather than a shared tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006224.c \
 *       --func func_02006224 --addr 0x02006224 --cc 1.1p1 --thumb
 */
int func_02006224(u32 a0)
{
    return func_02072EC8(a0 + 1) != 0;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_020062D8, sub_020062EC, sub_02006300
 *
 * The two thread bodies and the routine that starts one.  sub_020062D8 and
 * sub_020062EC carry no label: both are six instructions with no prologue
 * that dereference the thread argument, read one field of the state block
 * and tail call func_02074AC4 with a different constant, and the only
 * references to them in the image are the two pool words of sub_02006300
 * immediately below.  That is why the three have to be one byte range:
 * outside it neither thread body has a witness, and inside it both are
 * `local`.
 *
 * sub_02006300's call to func_020853C0 is an OS thread creation: the thread
 * object at 0x020AA354, the entry point, the argument, the stack at
 * 0x020AA9B4, and 0x400 and 0x11 on the stack for the stack size and the
 * priority.  The argument, 0x020AA26C, is the address of the state block's
 * own `unk0C` field, which is the word sub_02006300 has just written, so it
 * reaches the relocation as the state symbol with an addend of 0xC rather
 * than as an object of its own.
 */
int sub_02006238(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (sub_02006224(i) == 1) {
            return 1;
        }
    }
    return 0;
}

int sub_02006254(u32 a)
{
    if (func_02072EE0(a) != 0) {
        return 1;
    }
    return 0;
}

void sub_02006268(int i, u32 a, u32 b, u32 c)
{
    if (a != -1) {
        func_02073098((struct Obj *)(&sub_02006238_Table[i].unk04), a);
    }
    if (b != -1) {
        func_02073018((struct Obj *)(&sub_02006238_Table[i].unk04), 0xFFFF, b);
    }
    if (c != -1) {
        func_02073038((struct Obj *)(&sub_02006238_Table[i].unk04), 0xFFFF, c);
    }
}

void sub_020062BC(int i, u32 level)
{
    if (level > 0x7F) {
        level = 0x7F;
    }
    func_02072F34(&sub_02006238_Table[i].unk04, level);
}

void sub_020062D8(u32 *arg)
{
    func_02074AC4(*arg, 3, sub_02006300_State.unk10);
}

void sub_020062EC(u32 *arg)
{
    func_02074AC4(*arg, 4, sub_02006300_State.unk10);
}

void sub_02006300(u32 a, int mode)
{
    sub_02006300_State.unk0C = a;
    sub_02006368();
    switch (mode) {
    case 0:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))sub_020062D8,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    case 1:
        func_020853C0(sub_02006300_Thread, (void (*)(void *))sub_020062EC,
                      &sub_02006300_State.unk0C, sub_02006300_Stack,
                      0x400, 0x11);
        break;
    }
    func_02085868(sub_02006300_Thread);
    sub_02006300_State.unk14 = (u32)sub_02006300_Thread;
}

/*
 * Deactivates background task: checks g_020AA260.active, verifies status
 * via func_0208574C(&g_020AA354), terminates via func_020855BC, and resets active flag.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006368.c \
 *       --func func_02006368 --addr 0x02006368 --cc 1.1p1 --thumb
 */
void func_02006368(void)
{
    if (g_020AA260.active != 0) {
        if (func_0208574C(g_020AA354) == 0) {
            func_020855BC(g_020AA354);
            g_020AA260.active = 0;
        }
    }
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * "Has the worker thread finished."  A thread that was never started counts
 * as finished, which is the early `return 1`.
 *
 * Near miss, recorded here because this file is what survived of the range.
 * sub_020063B4, 0x020063B4..0x02006448, is the caller-driven version of the
 * three state pump that sub_02005FF4 runs off its own state word, with the
 * state behind a pointer the caller owns.  Every call, constant and field
 * access in it is reproduced and its first 0x20 bytes are byte identical,
 * but the best shape found is 64 bytes out and all 64 are block placement:
 * the original cross-jumps three tails that no spelling tried here makes
 * this compiler merge the same way.  Specifically, states 0 and 1 share one
 * copy of the `sub_02006300` call with the two arguments set up beforehand;
 * the `stop` path and the two normal paths share one copy of the store back
 * through the state pointer; the two `func_02085A38(2)` error exits share
 * one block placed between the last case and the common `return 0`; and
 * case 1 reaches that block through a two byte `b` bridge rather than
 * branching to it directly.  Twelve source shapes were tried, crossing a
 * merged tail against a duplicated one, a `mode` temporary against inlined
 * calls, `goto` against `break`, and a fallthrough `err:` label against a
 * second `return 0`.  The count moves between 64 and 153 and never reaches
 * zero, and what is left is all in the compiler's block ordering rather
 * than in the source, which is where enumerating shapes stops being the
 * cheap method.
 */
int sub_02006394(void)
{
    if (sub_02006394_State.unk14 == 0) {
        return 1;
    }
    return func_0208574C(sub_02006394_Thread);
}

/*
 * A three-state step function: `*a1` is the state, it advances at most one
 * step per call and every arm reports 0 except the step out of state 2,
 * which reports 1.
 *
 * The a2 == 1 arm is deliberately NOT an early `return 0;`.  Written that
 * way (`*a1 = 0; return 0;` then the switch) the compiler duplicates the
 * `str r0, [r4]` into the arm and emits its own epilogue, 150 bytes and
 * four bytes of extra code; with the arm falling through to one shared
 * `return 0;` at the end of the function the two `*a1 = <r0>` stores
 * cross-jump into the single `str r0, [r4]` at +0x3C and the arm is
 * `movs r0, #0 / b +0x3C`.  That single `str` is then the merge point for
 * three different paths (a2 == 1 storing 0, the state-0 arm and the
 * state-1 arm storing `*a1 + 1`).
 *
 * The `bne` at +0x0A jumps PAST the whole then-arm into the switch, so the
 * a2 == 1 arm is the fall-through and the switch is the `else` -- an `if`
 * whose then-arm is small enough to keep inline and whose else-arm is the
 * long one.
 *
 * `z - 1` in the state-2 arm is two `-1` arguments; the compiler keeps the
 * zero in r6 and derives both from `subs r2, r6, #1` instead of loading
 * each `movs r0, #1 / rsbs`, and the second argument to sub_020755A8 is
 * the leftover result of sub_0200590C, which takes none (see
 * docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the listing extent runs to 148 bytes because the follower saves
 * no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020063B4.c \
 *       --func func_020063B4 --addr 0x020063B4 --cc 1.1p1 --thumb
 */
u32 func_020063B4(u8 *a0, u32 *a1, u32 a2)
{
    if (a2 == 1) {
        sub_02005D14();
        sub_02006368();
        *a1 = 0;
    } else {
        switch (*a1) {
        case 0:
            sub_020746B0(0x1300);
            sub_02006300((u32)a0, 0);
            (*a1)++;
            break;
        case 1:
            if (sub_02006394() == 1) {
                sub_0200597C();
                sub_02006300((u32)a0, 1);
                (*a1)++;
            } else {
                sub_02085A38(2);
            }
            break;
        case 2:
            if (sub_02006394() == 1) {
                s32 z = 0;

                sub_020746B0(0);
                sub_020059A0((u32)a0);
                sub_020755A8((u32)sub_0200590C(), 0, z - 1, z - 1, (u32)a0);
                (*a1)++;
                return 1;
            }
            sub_02085A38(2);
            break;
        default:
            break;
        }
    }
    return 0;
}

/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A98 is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_020063B4.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A98 - reached from the identical `blx` in
 *           src/matched/func_02006448.c's loop only, so `label` has no
 *           witness outside the compared range and the callee is not
 *           matched.  All 102 concrete bytes and every other site are right.
 *
 * The four-voice "open with these handles" path: resolve the handle block,
 * split its header word and its halfword, and rebuild the table from it;
 * then check every one of the four 16-bit entries against 0xFFFF and bail
 * with 0 the first time a registration call fails (the loop counter is the
 * only thing the failure arm does not need, which is why the zero is
 * rematerialised rather than loaded from a local).
 *
 * The header word and the halfword at +4 are two separate loads before the
 * second call, and the *first* one goes to the stack slot the tail uses -
 * so the source read them in that order and passed them to func_020743EC
 * swapped (`func_020743EC(halfword, word)`).  The word at +0 of the returned
 * block is a full 32-bit load: it is the same field family as the four
 * halfwords at +4, but the first member is a `u32`, and spelling it as one
 * changes `ldrh` to `ldr` and nothing else.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006448.c \
 *       --func func_02006448 --addr 0x02006448 --cc 1.1p1 --thumb
 */
int func_02006448(u32 a0, u32 a1, u32 a2)
{
    u32 *hdr;
    struct Sub02006448Pair *q;
    u32 word;
    u16 half;
    u32 v;
    int i;

    hdr = func_02074324(a2);
    word = hdr[0];
    half = ((struct Obj11220 *)hdr)->f4;
    q = func_020743EC(half);
    v = q->unk00;
    sub_0200597C();
    for (i = 0; i < 4; i++) {
        if (*(u16 *)((char *)q + 4 + i * 2) != 0xFFFF) {
            if (func_02074A98(*(u16 *)((char *)q + 4 + i * 2),
                              g_020AA260.unk10) == 0) {
                return 0;
            }
        }
    }
    func_02074694(v, a1);
    func_02074694(word, a0);
    sub_020059A0(a2);
    return 1;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Two lookups, each abandoning the function when it comes back NULL, then
 * one call whose third argument is the result of another.
 *
 * The low 24 bits of the first word are read with a `lsls #8` / `lsrs #8`
 * pair, which is a 24 bit unsigned bitfield and not a mask.  Written as
 * `*p & 0xFFFFFF` this compiler puts 0x00FFFFFF in a literal pool and emits
 * `ldr` plus `ands`, six bytes against two and a pool word more; written as
 * `*p << 8 >> 8` it folds the two shifts back into exactly that `ands`.
 * Only a bitfield declaration survives the folding, so the shift pair is
 * evidence that the first word of this object is declared as bitfields.
 */
int sub_020064B8(u32 a, u32 b, u32 c, u32 d)
{
    struct Su8Head *p;
    u32 *q;

    p = func_02074450(a);
    if (p == 0) {
        return 0;
    }
    q = (u32 *)func_0207466C(p->unk00);
    if (q == 0) {
        return 0;
    }
    func_0208A640(q, b, func_0208A674(c, d));
    return 1;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Three short entry points that take the current connection slot's payload
 * from sub_0200590C, which is the last function of
 * src/matched/unit_020057DC.c, and hand it to the library.  sub_02006518 is
 * the odd one: it does not use the slot at all but looks the same object up
 * twice, through two different library entry points, with the same constant
 * 0x3F2, and shuts both results down.  0x3F2 is past the range of a Thumb
 * `movs` immediate, so it arrives in r4 through a literal pool word and is
 * used twice from there.
 */
void sub_020064F4(u32 a)
{
    func_02075560((u32)sub_0200590C(), a);
}

void sub_02006504(void)
{
    func_02072E7C((void **)sub_0200590C(), 0);
    sub_020059C8();
}

void sub_02006518(void)
{
    u32 a = *(u32 *)func_020743EC(0x3F2);
    u32 b = *(u32 *)func_02074324(0x3F2);

    func_02074694(a, 0);
    func_02074694(b, 0);
}

/*
 *           (unit_020066E8.c) and its call site resolves.  Remaining
 *           blockers are three data globals (g_02140484, g_0209D8C0,
 *           g_02140534) with no witness outside this range; --suggest-split
 *           offers nothing (single function, all witnesses internal).
 *           outside 02006544..020065D8.  All 124 concrete bytes and every
 *           other site are right (4 of 7 relocations resolved).
 *
 * Initialise the three mixer voices of the sound driver: publish the voice
 * count as a halfword, clear the driver's status byte, and for each of the
 * three 0x34-byte voices clear the enable word, copy the two 4-bit
 * pan/format fields out of the halfword table at 0x0209D8C0 (they are
 * adjacent `u8`-based bitfields, which is why the incoming halfword is
 * narrowed to 8 bits and the second one is shifted up by four into position
 * - see docs/idioms/a-bitfields-base-type-shows-up-as-a-redundant-truncation-
 * of-the-argument.md), then reset the voice.  Voice 0 also gets the same
 * pointer in both of its buffer slots.
 *
 * The three globals really are three separate symbols and not one struct:
 * the pool words are 0x02140524 and 0x02140504 outright, with 0x0C and
 * 0x20/0x22/0x24/0x28 as *instruction* offsets, so declaring one base and
 * adding the deltas would change the relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006544.c \
 *       --func func_02006544 --addr 0x02006544 --cc 1.1p1 --thumb
 */
void func_02006544(u16 a0, u32 a1, u32 a2)
{
    struct Sub02006544Voice *p;
    int i;

    g_02140484 = a0;
    g_02140524[0xC] = 0x7F;
    for (i = 0; i < 3; i++) {
        p = &g_02140488[i];
        p->unk00 = 0;
        p->lo = (u8)g_0209D8C0[i].lo;
        p->hi = (u8)g_0209D8C0[i].hi;
        func_020067D0((struct Sub02006544Entry *)p);
        if (i == 0) {
            p->unk04 = (u32)g_02140534;
            p->unk10 = (u32)g_02140534;
        }
    }
    *(u16 *)(g_02140504 + 0x22) = 1;
    *(u16 *)(g_02140504 + 0x20) = 0;
    *(u32 *)(g_02140504 + 0x24) = a1;
    *(u32 *)(g_02140504 + 0x28) = a2;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The four functions that walk the three element voice array.
 *
 * There is one object here, not five.  sub_02006544_State is a single
 * 0xB0 byte record at 0x02140484: a halfword, three 0x34 byte entries at
 * +0x04, and a tail of five scalars at +0xA0.  The tail is reached through
 * literal pool words holding 0x02140504 and 0x02140524, which are the same
 * symbol with the addends 0x80 and 0xA0, because the Thumb immediate cannot
 * reach 0xA0 bytes from the symbol itself.  Which addend the compiler picks
 * follows the reach of the access width: the base is the field offset with
 * the low bits of the reach masked off, 0x7F for a word, 0x3F for a
 * halfword, 0x1F for a byte, so the word and halfword group at +0xA0..+0xA8
 * shares the base 0x02140504 and the byte at +0xAC gets 0x02140524.
 * Reading each pool word as a separate object is the wrong conclusion and
 * costs the file its relocations.
 *
 * sub_02006674 passes 0x020A7024 to the debug allocator at 0x02030734 with
 * the line number 0x105, and the bytes at 0x020A7024 spell "pm_voice.c", so
 * this run is that file.  The string is named by one literal pool word in
 * the image and it is this function's own, so the `literal` class discards
 * its only witness; the `string` class carries it, because
 * "wb_sound_data.sdat" ends with its NUL at 0x020A7022 and one byte of
 * padding puts the next string at 0x020A7024 by construction.
 *
 * sub_02006650 carries no label in the generated listing, because it saves
 * nothing: it is four instructions of loop, an early `return 1` and a
 * `return 0`, and `disasm.py` prints it as a run of `.word`s.  It is also
 * the reason this range and the next one can be matched at all.  The pool
 * word at 0x02006670 is one of the only two in the image that hold
 * 0x02140484, the other being 0x020065C0 inside sub_02006544, so each of
 * those two functions is the outside witness the other ranges need.
 *
 * The near miss immediately before this range is sub_02006544,
 * 0x02006544..0x020065D8, 148 bytes.  Evidence class `literal`, witness
 * census 1 image wide and 1 inside the range: the halfword pair table at
 * 0x0209D8C0 that its loop indexes is named by exactly one literal pool
 * word in the whole 3.9 MB image, 0x020065CC, which is sub_02006544's own
 * pool.  0x0209D8C0 is read only data in the image, so `label`, `veneer`
 * and `string` cannot apply and `literal` is the only class available; no
 * cut helps, because the witness is the pool word of the very function that
 * needs it.  It closes the day anything else in the image loads that
 * address.
 */
void sub_020065D8(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        struct Sub02006544Entry *e = &sub_02006544_State.entries[i];

        if (e->unk00 == 1) {
            sub_02006948((struct Sub02006948 *)e);
        }
    }
}

void sub_020065FC(void)
{
    struct Sub02006544Entry *e;
    int i;
    u32 a;
    u32 b;

    for (i = 0; i < sub_02006544_State.count; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk00 == 1) {
            a = func_02072CC4((struct O *)e->unk14);
            if (e->unk2C == 1) {
                b = func_02072CC4((struct O *)e->unk18);
            } else {
                b = 0;
            }
            if (a == 0 && b == 0) {
                sub_02006948((struct Sub02006948 *)e);
            }
        }
    }
}

int sub_02006650(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (sub_02006544_State.entries[i].unk00 == 1) {
            return 1;
        }
    }
    return 0;
}

void sub_02006674(int n, u32 heap)
{
    struct Sub02006544Entry *e;
    int i;

    sub_020065D8();
    if (n > 2) {
        n = 2;
    }
    for (i = 1; i < n + 1; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk04 == 0) {
            void *p = func_02030734(heap, 0x5C30, 1, sub_02006674_File, 0x105);

            e->unk04 = p;
            e->unk10 = p;
            e->unk30 = 1;
        }
    }
    sub_02006544_State.count = n + 1;
    sub_02006544_State.cur = 0;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02006768, sub_020067A4, sub_020067D0
 *
 * The teardown, the master volume pair, the round robin picker and the two
 * entry reset routines.  Three of the seven carry no label, because they
 * save nothing: sub_02006734 and sub_02006740 are a two instruction setter
 * and its reset, and sub_020067D0 is two stores and a tail call through a
 * pool word into sub_020067A4, which is the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes.
 *
 * _s32_div_f, at 0x0209C0A4, is the signed 32 bit division helper, the
 * counterpart of the `_u32_div_f` at 0x0209C2B0 that
 * docs/idioms/runtime-helper-reloc.md records.  sub_0200674C scales a u8 by
 * the master volume and both operands promote to `int`, so the signed
 * helper is what that source shape produces; nothing in the C names it.
 *
 * Why this range starts here and not one function earlier: sub_020065D8 is
 * called from exactly two places in the whole image, 0x0200667C inside
 * sub_02006674 and 0x020066EA inside sub_020066E8.  Put both in one range
 * and the honesty rule discards both witnesses and the site is unresolved;
 * cut between them, as src/matched/unit_020065D8.c and this file do, and
 * each call is the other's outside witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 */
void sub_020066E8(void)
{
    struct Sub02006544Entry *e;
    int i;

    sub_020065D8();
    for (i = 0; i < sub_02006544_State.count; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk04 != 0 && e->unk30 == 1) {
            func_020307B0(e->unk04);
            sub_020067D0(e);
        }
    }
    sub_02006544_State.count = 1;
    sub_02006544_State.cur = 0;
}

void sub_02006734(u8 volume)
{
    sub_02006544_State.unkAC = volume;
}

void sub_02006740(void)
{
    sub_02006544_State.unkAC = 0x7F;
}

u8 sub_0200674C(u8 volume)
{
    return (u8)(volume * sub_02006544_State.unkAC / 0x7F);
}

u16 sub_02006768(void)
{
    struct Sub02006544Entry *e;
    u16 cur;

    cur = sub_02006544_State.cur;
    e = &sub_02006544_State.entries[cur];
    if (e->unk00 == 1) {
        sub_02006948((struct Sub02006948 *)e);
    }
    if (sub_02006544_State.cur < sub_02006544_State.count - 1) {
        sub_02006544_State.cur = sub_02006544_State.cur + 1;
    } else {
        sub_02006544_State.cur = 0;
    }
    return cur;
}

void sub_020067A4(struct Sub02006544Entry *e)
{
    e->unk08 = 0;
    e->unk1C = 0;
    e->unk1D = 0;
    e->unk24 = 0;
    e->unk0C = 0x3443;
    e->unk20 = 0x64E1;
    e->unk28 = 0x40;
    e->unk2C = 0;
    e->unk10 = e->unk04;
}

void sub_020067D0(struct Sub02006544Entry *e)
{
    e->unk04 = 0;
    e->unk30 = 0;
    sub_020067A4(e);
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The loader and the player.  sub_020067E0 resolves an id to a resource,
 * reads the header at the end of the loaded block and fills in the entry's
 * four playback fields; sub_02006868 opens one or two channels for the
 * entry and marks it running.
 *
 * Three things in here are worth keeping.
 *
 * The first word of the object func_02074450 returns is read with a
 * `lsls #8` / `lsrs #8` pair, which is a 24 bit unsigned bitfield and not a
 * mask; src/matched/unit_020064B8.c matched the same object through the
 * same entry point and
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the
 * finding.
 *
 * The byte at +0x1E of an entry is two four bit unsigned bitfields, not one
 * value: sub_02006868 reads it twice, once as `lsls #0x1C` / `lsrs #0x1C`
 * and once as `lsls #0x18` / `lsrs #0x1C`, and passes each to
 * func_02072A44.  The same byte is written in sub_02006544 with a
 * `bics`/`orrs` pair against 0x0F and against 0xF0.  The first declared
 * field is the low nibble, so this front end allocates a `u8` bitfield from
 * the least significant end.
 *
 * The pair of `blx 0x0209C00C` with `asrs r3, r2, #0x1f` in front of each is
 * one 64 bit division chained twice, not two 32 bit ones: the helper takes
 * the dividend in r0:r1 and returns it in r0:r1, so the second call consumes
 * the first call's result.  The constant it starts from is
 * 0x7FD87F8000, which is 16756991 * 0x8000, and 16756991 is half the DS
 * system clock; only its low word is in a literal pool, because the high
 * word 0x7F fits a `movs`.  The `asrs` is the sign extension of an `int`
 * operand to the 64 bit type of the dividend, which is what a `u16` field
 * promoted to `int` and then converted costs.
 *
 * The two functions of this range are separated from the two before them
 * and from sub_02006948 after them by what the evidence allows rather than
 * by taste.  sub_020067A4's only branch in the image is the `bl` at
 * 0x0200697C inside sub_02006948, so a range holding both has no witness for
 * it; ending this range at 0x02006948 leaves the pool word at 0x020067DC,
 * which is the other kind of witness for the same address, outside it.
 *
 * The near miss immediately after this range is sub_02006948,
 * 0x02006948..0x02006984, 60 bytes.  Evidence class `label`, witness census
 * 2 image wide and 2 inside the range, for each of three separate targets:
 * func_02072BDC is branched to from 0x0200694E and 0x02006966, func_02072D20
 * from 0x02006954 and 0x0200696C, and func_02072A88 from 0x0200695A and
 * 0x02006972, and every one of those six sites is inside sub_02006948
 * itself.  ov172 holds the words 0x02072A88 and 0x02072BDC in its own
 * literal pools, but overlay pool words are deliberately not admitted to
 * the `literal` class, and nothing anywhere branches to those three
 * addresses from outside this one function.  No cut helps, because the
 * witnesses are the calls the function has to make.  Each closes the day a
 * second caller appears.
 */
int sub_020067E0(struct Sub02006544Entry *e, u32 id)
{
    struct Su8Head *p;
    struct Sub020067E0Block *block;
    struct Sub020067E0Wave *wave;
    u32 handle;
    u32 size;
    int r;

    p = func_02074450(id);
    if (p == 0) {
        return 0;
    }
    handle = func_0207457C(p->unk00);
    if (handle == 0) {
        return 0;
    }
    r = func_020745A4(p->unk00, e->unk04, handle, 0);
    if (r == -1) {
        return 0;
    }
    if (r != handle) {
        return 0;
    }
    block = e->unk04;
    wave = (struct Sub020067E0Wave *)((u8 *)block + block->unk3C);
    func_0208A638((char *)block);
    size = block->unk08 - block->unk3C;
    e->unk10 = (u8 *)wave + 0xC;
    e->unk08 = size - 0xC;
    e->unk0C = wave->unk02;
    e->unk20 = (u32)(0x7FD87F8000ULL / wave->unk02 / wave->unk04);
    return 1;
}

int sub_02006868(struct Sub02006544Entry *e)
{
    int v;

    if (e->unk04 == 0) {
        return 0;
    }
    if (e->unk08 == 0) {
        return 0;
    }
    e->unk14 = func_02072A44(e->unk1E);
    if (e->unk14 == 0) {
        return 0;
    }
    if (func_02072AA0(e->unk14, 0, e->unk10, 0, 0, e->unk08, e->unk0C,
                      sub_0200674C(e->unk1C), e->unk20, e->unk28) == 0) {
        return 0;
    }
    if (e->unk2C == 1) {
        e->unk18 = func_02072A44(e->unk1E_4);
        if (e->unk18 == 0) {
            return 0;
        }
        v = e->unk1C + e->unk1D;
        if (v < 0) {
            v = 0;
        }
        if (v > 0x7F) {
            v = 0x7F;
        }
        if (func_02072AA0(e->unk18, 0, e->unk10, 0, 0, e->unk08, e->unk0C,
                          sub_0200674C((u8)v), e->unk20 + e->unk24,
                          e->unk28) == 0) {
            return 0;
        }
    }
    e->unk00 = 1;
    return 1;
}

/*
 * promoted: from src/pending 2026-09-19, no C change: blockers 0x02072A88
 *           (src/matched/func_02072A88.c, ../1.2/sp2) and 0x02072BDC
 *           (src/matched/func_02072BDC.c, ../2.0/sp2) are filed and
 *           0x02072D20 was already a manifest entry, so all seven sites
 *           resolve through the `matched` class.  EXACT* not EXACT: the
 *           follower at 0x0200697A carries no label, nothing else differs.
 *
 * Tear down one voice: three calls on the object's object pointer at +0x14,
 * the same three on the second one at +0x18 when +0x2C is 1, then clear the
 * first word and re-initialise.  The +0x14 load is repeated before each call
 * because the callees are extern and may write it back, so the source reads
 * the field again rather than caching it in a local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006948.c \
 *       --func func_02006948 --addr 0x02006948 --cc 1.1p1 --thumb
 */
void func_02006948(struct Sub02006948 *p)
{
    func_02072BDC(p->unk14);
    func_02072D20(p->unk14);
    func_02072A88((u32 *)p->unk14);
    if (p->unk2C == 1) {
        func_02072BDC(p->unk18);
        func_02072D20(p->unk18);
        func_02072A88((u32 *)p->unk18);
    }
    p->unk00 = 0;
    func_020067A4((struct Sub02006544Entry *)p);
}

/*
 * Eight parameters: four arrive in registers and four in the caller's stack
 * frame, which this function copies down into its own outgoing argument area
 * (the `sub sp, #0x14` plus the saved r3 is exactly that home area).  The
 * wait loop is an `if` around a `do`/`while` rather than one `while`, because
 * `v = 2` is emitted *after* the first test and the back edge skips it.
 *
 * PROMOTED, no C change: this file was parked at MATCH on 02006A64 above and
 * became EXACT the moment pkt_02006948's shard was written - the `matched`
 * class needs only that the callee has an EXACT entry of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006984.c \
 *       --func func_02006984 --addr 0x02006984 --cc 1.1p1 --thumb
 */
u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3,
                  u32 a4, u32 a5, u32 a6, u32 a7)
{
    u32 v;

    if (func_02005C64() == 1) {
        v = 2;
        do {
            func_02085A38(v);
        } while (func_02005C64() == 1);
    }
    v = (u16)func_020069D4(a0, a1, a2, a3, a4, a5, a6, a7);
    func_02006A64(v);
    return v;
}

/*
 * Eight arguments: four in r0..r3 and four on the stack at [sp+0x30]..
 * [sp+0x3c], which is what makes the frame 0x1c: four words of outgoing
 * stack-argument area at sp+0..sp+0xc plus three locals at sp+0x10, sp+0x14
 * and sp+0x18.
 *
 * a1 is spilled to the [sp+0x10] slot because it is live across the first
 * 3-argument indirect call; the index comes back from func_02006768 and is
 * spilled to [sp+0x14] because it is the return value.
 *
 * The struct at 0x02140504 is used twice off the same pool word: its +0x24
 * slot is the three-argument prologue call and its +0x28 slot the
 * eight-argument one whose last four arguments are the four pointers
 * e+8, e+0xc, e+0x20, e+0x1c, written to the outgoing area in that order.
 *
 * Both data addresses are declared as extern ARRAYS, not as numeric
 * constants: spelled `(int *)(0x02140504)` the pair is folded into one
 * base plus `subs #0xa0`, which costs a callee-saved register, a dead
 * `push {r3}` and four bytes of frame.
 */
int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8)
{
    int buf;
    int idx;
    char *e;

    (*(void (**)(int, int, int *))(g_02140504 + 0x24))(a0, a1, &buf);
    idx = func_02006768();
    e = (char *)&g_02140488[idx];
    if (*(int *)&((struct Obj01457 *)e)->f0 == 1)
        func_02006948((struct Sub02006948 *)e);
    if ((*(int (**)(int, int, int, char *, char *, char *, char *, char *))(
             g_02140504 + 0x28))(a0, a1, a8, e + 0x10, e + 8, e + 0xc, e + 0x20, e + 0x1c) == 0)
        func_020067E0((struct Sub02006544Entry *)e, (unsigned int)buf);
    if (a7 != 0)
        func_02006BE0(*(u8 * *)&((struct Obj01457 *)e)->f10, ((struct Obj01457 *)e)->f8);
    e[0x28] = (u8)a2;
    *(int *)&((struct Obj01457 *)e)->f2C = a3;
    e[0x1d] = (u8)a5;
    ((struct Obj01457 *)e)->f24 = a6;
    return idx;
}

/*
 * Free voice `idx`: 0x34-byte entries off the global at 0x02140488.  The
 * index is scaled into the parameter rather than into a pointer local, and
 * the base + index expression is recomputed for the second call, so the
 * source wrote the address expression twice.  The test is on the *word* at
 * +0 of the entry (`[r0]` through the same base register), not on the call
 * result.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006A64.c \
 *       --func func_02006A64 --addr 0x02006A64 --cc 1.1p1 --thumb
 */
int func_02006A64(u32 idx)
{
    if (func_02006868((struct Sub02006544Entry *)&g_02140488[idx]) == 0) {
        func_02006948((struct Sub02006948 *)&g_02140488[idx]);
        return 0;
    }
    return 1;
}

/*
 * Pan two voices by a signed delta: both fields at +0x1C and +0x1D are
 * `s8` (the loads are `ldrsb`, see
 * docs/idioms/ldrsh-register-offset-is-signedness.md), each is clamped to
 * [0, 0x7F] with what is written as two separate `if`s - the `bpl`/`ble`
 * pair is a signed compare on the *sum*, which is why the clamp is on the
 * int-typed result rather than on the byte.  The second field's value is
 * re-narrowed to a byte before it is passed on, so the call takes a u8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006A8C.c \
 *       --func func_02006A8C --addr 0x02006A8C --cc 1.1p1 --thumb
 */
void func_02006A8C(u32 idx, int delta)
{
    struct Sub02006544Voice *p;
    int v;

    p = &g_02140488[idx];
    if (p->unk00 == 0) {
        return;
    }
    v = *(signed char *)&p->unk1C + delta;
    if (v < 0) {
        v = 0;
    }
    if (v > 0x7F) {
        v = 0x7F;
    }
    p->unk1C = (u8)v;
    func_02072C18((struct S *)p->unk14, func_0200674C(p->unk1C));
    if (p->unk2C == 1) {
        v = *(signed char *)&p->unk1C + *(signed char *)&p->unk1D;
        if (v < 0) {
            v = 0;
        }
        if (v > 0x7F) {
            v = 0x7F;
        }
        func_02072C18((struct S *)p->unk14, func_0200674C((u8)v));
    }
}

/*
 * Advance a voice's sample cursor by `delta`: the sum is stored first and
 * the stored value is what is passed to the first call, so the source kept
 * it in a local and stored through the pointer before the call.  The second
 * call re-reads both the cursor and the length, which is why it is written
 * as the same pointed-to additions again rather than reusing the local.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006AEC.c \
 *       --func func_02006AEC --addr 0x02006AEC --cc 1.1p1 --thumb
 */
void func_02006AEC(u32 idx, u32 delta)
{
    struct Sub02006544Voice *p;
    u32 v;

    p = &g_02140488[idx];
    if (p->unk00 == 0) {
        return;
    }
    v = p->unk20 + delta;
    p->unk20 = v;
    func_02072C40(p->unk14, v);
    if (p->unk2C == 1) {
        func_02072C40(p->unk18, p->unk20 + p->unk24);
    }
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           sub_02006B94, sub_02006BB4, sub_02006BD0, sub_02006BE0,
 *           sub_02006C00
 *
 * Nine consecutive functions of the sound channel file.  The object is a
 * table of 0x34 byte channel records at 0x02140488, seventeen literal pools
 * in the region hold its address, and the index arithmetic is a `muls` by
 * 0x34 rather than a shift because the size is not a power of two.
 *
 * Six of the nine carry no label in the generated listing, because a getter
 * that saves nothing has no prologue for disasm.py's sweep to fire on and
 * lands in the listing as a run of `.word`s:
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  They are
 * sub_02006B20, sub_02006B3C, sub_02006B5C, sub_02006B78, sub_02006B94,
 * sub_02006BD0 and sub_02006C00.
 *
 * Three details pin the source:
 *
 *  - sub_02006B20 returns the field at +0x1C with a register offset `ldrsb`,
 *    which is the only evidence anywhere in the range that the field is
 *    signed: docs/idioms/ldrsh-register-offset-is-signedness.md.  The
 *    neighbouring 0x1D is read the same way by sub_02006A8C above.
 *  - sub_02006BB4 computes `&Table[i]` only inside the `if`, where every
 *    other function in the run computes it before the test.  That is the
 *    difference between subscripting the table twice and binding a local
 *    pointer first, and it is two instructions.
 *  - sub_02006C00's guard is `if (species < 1 && species > 649)`, with a
 *    conjunction and not a disjunction.  For unsigned operands that is
 *    unsatisfiable, so the `*out = 1` arm is dead code, but it is what the
 *    bytes say: `cmp r0, #1` / `bhs` and `cmp r0, r3` / `bls` both branch
 *    past it, which is the `||` shape with both tests negated.  Written with
 *    `||` the two branches invert and land on the other arm.  The constants
 *    are the national dex range, 1 to 649, and the pair 492 / 650 the second
 *    test maps is a species with a second form.
 *
 * What is left out below this range, and why.  The whole run
 * 0x02006A64..0x02006D3C reproduces every concrete byte as one compile and
 * comes out MATCH, so none of the five functions held out is a codegen
 * failure; every one of them is blocked by the honesty rule, and the census
 * is from `tu --suggest-split`.
 *
 *   0x02006A64  40 bytes.  `label`: func_02006868 has one witness image wide
 *               and it is the `bl` at 0x02006A70 inside this very function.
 *               No cut can free it.
 *   0x02006A8C  96 bytes.  `label`: func_02072C18 has two witnesses image
 *               wide, 0x02006AB8 and 0x02006AE2, and both are inside this one
 *               function, so the pairwise split of
 *               docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md
 *               does not reach it.
 *   0x02006AEC  52 bytes.  The same shape one function later: func_02072C40
 *               has exactly two witnesses, 0x02006B04 and 0x02006B16, both
 *               inside it.
 *   0x02006C2C  128 bytes.  `label`: func_02007B64 and func_02007B68 have one
 *               witness each, the `bl`s at 0x02006C6E and 0x02006C78 inside
 *               this function.  Its guard chain is
 *               docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md.
 *   0x02006CBC  128 bytes.  Three sites at once.  `label`: func_027047C0 is
 *               named only by the `blx` at 0x02006D22 inside it.  `literal`:
 *               0x020A703C, which spells "snd_mic.c" and is the original file
 *               name of this range, and 0x020A7030, are each named by one pool
 *               word and it is this function's own.  The `string` class does
 *               not reach either: the run in front of 0x020A703C is not
 *               printable ASCII, and 0x020A7030 is itself that run.  Its
 *               allocate, clear and store sequence is
 *               docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md.
 *
 * Between the last two sits 0x02006D3C, four bytes of ARM followed by its
 * pointer word: `ldr pc, [pc, #-4]` over 0x027047C0.  That is a linker
 * veneer, so no C produces it, and the `veneer` class refuses it as well
 * because 0x027047C0 is not inside any region of layout/layout.json and so
 * cannot be shown to name code.  The Thumb side of the range therefore ends
 * at 0x02006D3C and resumes at 0x02006D44 in
 * src/matched/unit_02006D44.c.
 */
s8 sub_02006B20(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk1C;
}

u32 sub_02006B3C(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0x64E1;
    }
    return chan->unk20;
}

u32 sub_02006B5C(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk10;
}

u32 sub_02006B78(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0;
    }
    return chan->unk08;
}

u32 sub_02006B94(u32 i)
{
    struct Sub02006B20Chan *chan = &sub_02006B20_Table[i];

    if (chan->unk00 == 0) {
        return 0x3443;
    }
    return chan->unk0C;
}

void sub_02006BB4(u32 i)
{
    if (sub_02006B20_Table[i].unk00 == 1) {
        func_02006948((struct Sub02006948 *)&sub_02006B20_Table[i]);
    }
}

u32 sub_02006BD0(u32 i)
{
    return sub_02006B20_Table[i].unk00;
}

void sub_02006BE0(u8 *p, u32 n)
{
    u32 i;

    for (i = 0; i < n / 2; i++) {
        u8 t = p[i];

        p[i] = p[n - 1 - i];
        p[n - 1 - i] = t;
    }
}

void sub_02006C00(u32 species, u32 form, u32 *out)
{
    if (species < 1 && species > 649) {
        *out = 1;
        return;
    }
    if (species == 492 && form == 1) {
        *out = 650;
        return;
    }
    *out = species;
}

/*
 * The reader for a/1/9/4, the per-species cry parameter table.  It sits in
 * pm_voice.c (the __FILE__ strings either side of it in the image are
 * pm_voice.c at 0x020066E0 and snd_mic.c at 0x02006D2C), and it is the only
 * call site in the whole image that loads archive id 194.
 *
 * func_02048F4C(dst, archive_id, member) copies one member into a
 * caller-supplied buffer, and here the buffer is four bytes, matching
 * a/1/9/4's 652 fixed 4-byte records.  Only the halfword at +2 is used:
 * its low byte is written to *cryPitch, and the value's range over the
 * whole archive is 97..127, i.e. a 7-bit playback parameter.  The u16 at
 * +0 is not touched by this function.
 *
 * The member index is the species id, which the special case pins down
 * exactly: `species == 441` is Chatot, the one species whose cry is a
 * recorded sample rather than a played bank note.  441 is rematerialised
 * as 194 + 247 off the register that already holds the archive id
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md),
 * which is why the same literal appears twice in the C and once in the
 * bytes.  On that path the two sample-rate outputs are overwritten with
 * 0x1FF4, the pitch byte with 0x78 = 120 (inside the table's own 97..127
 * range), and the third output with func_020056EC(0x2000) + 0x8000.
 *
 * Content constant note: 441 is a national species id and 652 is the
 * record count of Black's a/1/9/4.  Neither is expected to move in White,
 * but both are data-side numbers, so they are called out here rather than
 * assumed shared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02006C2C.c \
 *       --func func_02006C2C --addr 0x02006C2C --cc 1.1p1 --thumb
 */
u32 func_02006C2C(u32 species, u32 form, void **rec, void **owner,
                  u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch)
{
    u16 entry[2];

    func_02048F4C(entry, 194, species);
    *cryPitch = (u8)entry[1];
    if (rec == 0) {
        return 0;
    }
    if (species == 441 && form == 0 && func_02007B50(rec[0]) == 1) {
        func_02007B68(owner[0], (const s8 *)func_02007B64(rec[0]));
        *rate1 = 0x1FF4;
        *rate2 = 0x1FF4;
        *cryPitch = 0x78;
        *addr = func_020056EC(0x2000) + 0x8000;
        return 1;
    }
    return 0;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One function, sixteen bytes, alone in its own range because both of its
 * neighbours are held out by the honesty rule and a matched range has to be
 * contiguous.  The near miss census for the two, 0x02006C2C before it and
 * 0x02006CBC after it, is in the header of src/matched/unit_02006B20.c.
 *
 * func_020070A4 takes no argument: it is a lazily initialised singleton
 * getter and never reads r0.  The incoming r0 here is only saved into r4 and
 * used as the destination of the store, so the call is nested rather than
 * sequenced, and the result of func_02007B44 is written through the argument.
 * func_02007B44 is `sub_020071CC(sys, 0x24)` in src/matched/unit_02007AC8.c,
 * the save block lookup, so what this writes is a pointer to save block 0x24.
 */
void sub_02006CAC(void **out)
{
    *out = func_02007B44(func_020070A4());
}

/*
 *           word 0x027047C0 lies outside every region of layout/layout.json,
 *           so the `veneer` class refuses the call.  All 112 concrete bytes
 *           and every other site are right.
 *
 * Allocate and publish the two sound blocks: a 0x28-byte driver object and
 * a 0x2014-byte sample pool, both with the same string at 0x020A703C as
 * their `__FILE__`-style argument (0x59 and 0x5f are the two line numbers,
 * and only the first is a pool word - see
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).  The
 * sample pool is linked into the object at +0x24 before the hardware is
 * poked, the bitfield at +0x20 has its low bit cleared and set again
 * (`bics` for the clear), and the finished object is stored at 0x02146164.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006CBC.c \
 *       --func func_02006CBC --addr 0x02006CBC --cc 1.1p1 --thumb
 */
void func_02006CBC(u16 heap)
{
    struct Sub02006CBCObj *p;
    void *pool;

    p = func_02030734(heap, 0x28, 0, g_020A703C, 0x59);
    func_02082BCC(p, 0, 0x28);
    pool = func_02030734(heap, 0x2014, 0, g_020A703C, 0x5f);
    func_02082BCC(pool, 0, 0x2014);
    p->unk24 = (u32)pool;
    func_0208BEF0(1);
    func_0208BF38(2);
    p->unk20 = (p->unk20 & ~1u) | 1u;
    func_0208B24C();
    if (func_02085D3C() == 1) {
        func_027047C0(0, g_020A7030);
    }
    g_02146164 = p;
}



struct Sub02006D44Obj {
    u32   unk00[7];
    u32   unk1C;
    u32   unk20_0 : 1;
    u32   unk20_1 : 31;
    void *unk24;
};

struct Sub02006DACParam {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
};

struct Sub02006DACObj {
    struct Sub02006DACParam unk00;
    u32 unk1C;
};

struct Sub02006E2CObj {
    u32 unk00[9];
    u32 unk24;
};

struct Sub02006E40Obj {
    u8   count;
    u8   pad01[3];
    u16 *unk04;
    u8  *unk08;
};

extern void PM_SetAmp(u32 on);
extern u32 MIC_AdjustLimitedSampling(const struct Sub02006DACParam *param);
extern u32 func_02006E2C(void);
extern void func_02007BD0(struct PerapVoice *p, const s8 *src);
extern void func_02048F74(void *dst, u32 archive_id, u32 member, u32 mode, u32 *size_out);
void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap);
void func_02006E18(void *a0);
u32 sub_02006E2C(void);
struct Sub02006E40Obj *sub_02006E40(u32 heap);
void sub_02006D44(void);
void sub_02006D64(u32 n);
u32 sub_02006D94(void);
extern struct Sub02006D44Obj *sub_02006D44_Ptr;
extern struct Sub02006DACObj *sub_02006DAC_Ptr;
extern struct Sub02006E2CObj *sub_02006E2C_Ptr;
extern const char sub_02006E40_File[];

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of "snd_mic.c": the teardown of the microphone object and the two
 * functions that own the counter at +0x20.  The object is the one
 * src/matched/unit_02006DAC.c and src/matched/sub_02006E2C.c reach through
 * the same pointer at 0x02146164: seven words of MICAutoParam at +0, a flag
 * word at +0x1C, the packed word at +0x20 and the sampling buffer at +0x24,
 * which is 0x28 bytes and is exactly what the constructor at 0x02006CBC
 * allocates and clears.
 *
 * The word at +0x20 is two unsigned bitfields, one bit at bit 0 and thirty
 * one bits at bit 1, and all three functions here turn on that declaration:
 *
 *  - sub_02006D94 reads the wide field with a bare `lsrs r0, r0, #1` and no
 *    mask, which is only correct because the field runs to the top of the
 *    word.  A plain u32 shifted by hand gives the same instruction here but
 *    not in sub_02006D64;
 *  - sub_02006D64 writes it back with `movs r0, #1` / `ands r2, r0` /
 *    `lsrs r0, r1, #1` / `adds` / `lsls r0, r0, #1` / `orrs r0, r2`, which is
 *    the read modify write of a bitfield that has to preserve bit 0.  Written
 *    as `w = (w & 1) | ((((w >> 1) + n) << 1))` this compiler materialises the
 *    mask differently and reorders the two halves;
 *  - sub_02006D64 tests bit 0 with `lsls #0x1f` / `lsrs #0x1f`, the one bit
 *    case of docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md.
 *
 * The range starts at 0x02006D44 rather than earlier because 0x02006D3C is
 * four bytes of ARM: `ldr pc, [pc, #-4]` over the pointer word at 0x02006D40,
 * a linker veneer, which no compiler input produces.  What is left out below
 * it is recorded in the header of src/matched/unit_02006B20.c.
 */
void sub_02006D44(void)
{
    PM_SetAmp(0);
    func_020307B0(sub_02006D44_Ptr->unk24);
    func_020307B0(sub_02006D44_Ptr);
}

void sub_02006D64(u32 n)
{
    struct Sub02006D44Obj *obj = sub_02006D44_Ptr;

    if (obj->unk20_0) {
        if (sub_02006D94() == 0) {
            obj->unk20_1 += n;
        }
    }
}

u32 sub_02006D94(void)
{
    if (sub_02006D44_Ptr->unk20_1 > 0xB4) {
        return 1;
    }
    return 0;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The microphone sampling request and its one caller.  The record both
 * functions pass around is seven words, and the SDK call at 0x0208B500 is
 * MIC_AdjustLimitedSampling in layout/symbols_sdk.txt, so the record is a
 * MICAutoParam: type, buffer, size, rate, loop flag, callback and callback
 * argument, in that order, which is exactly the seven stores sub_02006DD8
 * makes and exactly the 0x1C bytes sub_02006DAC copies.  The fields are
 * still spelled unkXX here because only the SDK call attests the shape, not
 * the meaning of the two constants.
 *
 * sub_02006DAC reads the global pointer at 0x02021664 twice, once for the
 * flag word at +0x1C and once for the copy, because the store through the
 * first load can alias the pointer itself and the compiler has to reload it.
 * That reload is not a second variable in the source.  The copy is the
 * unrolled aggregate assignment of
 * docs/idioms/aggregate-assignment-is-ldm-stm.md: 0x1C bytes is three
 * ldm/stm pairs and a trailing ldr/str, and it says the seven words are one
 * nested struct rather than seven fields.
 *
 * The two constants sub_02006DD8 stores come out of literal pools, and the
 * round down of the first is emitted as a live test and mask rather than
 * folded: `movs r0, #0x1f; tst r0, r1; beq; movs r0, #0x1f; bics r1, r0`,
 * with the mask materialised twice because Thumb has no immediate bic.  The
 * compiler does not constant fold it even though the value is a pool word,
 * so the guard is in the source and not an artefact.
 *
 * What is left out of this range, and why, is sub_02006E18 at
 * 0x02006E18..0x02006E2A, eighteen bytes that reproduce every concrete byte
 * and cap at MATCH.  It is `sub_02007BD0(a, sub_02006E2C());` and the
 * evidence for 0x02007BD0 is the `bl` at 0x02006E24 inside that very
 * the function list: the census is one witness image wide, one of them inside the
 * range, so no cut can free it.  The `literal` class has nothing either,
 * because no pool word anywhere in the image holds 0x02007BD0.  It closes
 * the day a second caller of 0x02007BD0 appears, exactly like 0x02005DE4 and
 * 0x02005A98 in the near-miss register of docs/MATCHING.md.  Note that
 * sub_02006E2C itself is fine either way: it has two callers, 0x02006DE4 in
 * this range and 0x02006E1C in sub_02006E18, so whichever of the two files a
 * range holds, the other is its witness.
 */
u32 sub_02006DAC(const struct Sub02006DACParam *param)
{
    u32 r = MIC_AdjustLimitedSampling(param);

    sub_02006DAC_Ptr->unk1C = 1;
    sub_02006DAC_Ptr->unk00 = *param;
    return r;
}

u32 sub_02006DD8(void *a, u32 b)
{
    struct Sub02006DACParam param;

    param.unk00 = 2;
    param.unk04 = sub_02006E2C();
    param.unk08 = 0x1FF4;
    if (param.unk08 & 0x1F) {
        param.unk08 &= ~0x1Fu;
    }
    param.unk0C = 0x1001;
    param.unk10 = 0;
    param.unk14 = (u32)a;
    param.unk18 = b;
    return sub_02006DAC(&param);
}

void func_02006E18(void *a0)
{
    void *res = (void *)func_02006E2C();
    func_02007BD0(a0, res);
}

/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * Original (20 bytes, leaf, one ABS32 literal):
 *   ldr  r0, [pc, #0xc]   ; &sub_02006E2C_Ptr
 *   movs r1, #0x1f
 *   ldr  r0, [r0]
 *   ldr  r0, [r0, #0x24]
 *   adds r0, #0x1f
 *   bics r0, r1
 *   bx   lr
 *
 * Round a size up to a multiple of 32.  The mask is materialised in r1 and
 * applied with bics because Thumb has no immediate form of bic; the
 * compiler hoists the movs above both loads, which is the schedule the
 * original shows.
 *
 * The pool word is an ABS32 relocation, resolved to the address declared
 * above; five other functions load the same address from their own pools.
 */
u32 sub_02006E2C(void)
{
    return (sub_02006E2C_Ptr->unk24 + 0x1F) & ~0x1Fu;
}

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte record holding a count and two parallel arrays: a u16 key
 * array at +4 and a u8 value array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the key array returning the value at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `k = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
struct Sub02006E40Obj *sub_02006E40(u32 heap)
{
    struct Sub02006E40Obj *obj = func_02030734(
        heap, sizeof(struct Sub02006E40Obj), 0, sub_02006E40_File, 0x47);

    sub_02006EA4(obj, heap);
    return obj;
}

void sub_02006E64(struct Sub02006E40Obj *obj)
{
    func_020307B0(obj->unk04);
    func_020307B0(obj->unk08);
    func_020307B0(obj);
}

u8 sub_02006E7C(const struct Sub02006E40Obj *obj, u16 key)
{
    int i;

    for (i = 0; i < obj->count; i++) {
        if (key == obj->unk04[i]) {
            return obj->unk08[i];
        }
    }
    return 0;
}

void sub_02006EA4(struct Sub02006E40Obj *obj, u32 heap)
{
    int i;
    int k;

    k = 0;
    func_02048F74(obj, 0x57, 0, k, (u32 *)1);
    k++;
    obj->unk04 = func_02030734(heap, obj->count * 2, 0, sub_02006E40_File,
                               0xAF);
    obj->unk08 = func_02030734(heap, obj->count, 0, sub_02006E40_File, 0xB0);
    for (i = 0; i < obj->count; i++) {
        func_02048F74(&obj->unk04[i], 0x57, 0, k, (u32 *)2);
        func_02048F74(&obj->unk08[i], 0x57, 0, k + 2, (u32 *)1);
        k += 3;
    }
}
