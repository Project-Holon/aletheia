/*
 * file:     gds_rap.c
 * unit:     yes
 * function: func_021D6660, func_021D6770, func_021D67C8, func_021D6814, func_021D683C, func_021D68EC, func_021D6968, func_021D698C, func_021D69B4, func_021D69DC, func_021D6A08, func_021D6A34, func_021D6B40, func_021D6FB0, func_021D7060, func_021D7064, func_021D7120, func_021D7124, func_021D7154, func_021D71CC, func_021D71D8, func_021D730C, func_021D732C, func_021D7354, func_021D7374, func_021D73B8, func_021D73E0, func_021D73F0, func_021D7414, func_021D74B4, func_021D74D8, func_021D7520, func_021D7540, func_021D75E8, func_021D7630, func_021D76A8, func_021D76D8, func_021D7700, func_021D770C, func_021D7770, func_021D7808, func_021D7874, func_021D7A10, func_021D7BCC, func_021D7BDC, func_021D7C14, func_021D7C48, func_021D7C7C, func_021D7C90, func_021D7CAC
 * address:  0x021D6660
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8600 0x021D8600 arm ov125
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_021D8598 0x021D8598 arm ov125
 *   func_02034714 0x02034714 arm
 *   ov114_id 0x00000072 data
 *   d_021D8D00 0x021D8D00 data a4
 *   d_021D8D0C 0x021D8D0C data a4
 *   d_021D8D28 0x021D8D28 data a4
 *   func_021B99B8 0x021B99B8 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021D85B4 0x021D85B4 arm ov125
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   d_021D8C80 0x021D8C80 data a2
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D860C  0x021D860C  arm  ov125
 *   func_021D8654  0x021D8654  arm  ov125
 *   func_021D8694  0x021D8694  arm  ov125
 *   func_021D8754  0x021D8754  arm  ov125
 *   func_021D879C  0x021D879C  arm  ov125
 *   func_021D87FC  0x021D87FC  arm  ov125
 *   func_021D885C  0x021D885C  arm  ov125
 *   func_021D88BC  0x021D88BC  arm  ov125
 *   func_021D88F0  0x021D88F0  arm  ov125
 *   func_021B9748  0x021B9748  thumb  ov114
 *   func_021B9774  0x021B9774  thumb  ov114
 *   func_021B9790  0x021B9790  thumb  ov114
 *   func_021B97F4  0x021B97F4  thumb  ov114
 *   func_021B9800  0x021B9800  thumb  ov114
 *   func_021B98A0  0x021B98A0  thumb  ov114
 *   func_021B98D8  0x021B98D8  thumb  ov114
 *   func_021B98F8  0x021B98F8  thumb  ov114
 *   func_021B99DC  0x021B99DC  thumb  ov114
 *   func_021B99F0  0x021B99F0  thumb  ov114
 *   func_021B99F4  0x021B99F4  thumb  ov114
 *   func_021B9A14  0x021B9A14  thumb  ov114
 *   func_0200853C  0x0200853C  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb
 *   BATTLE_REC_GetBody  0x0200B91C  thumb
 *   BATTLE_REC_SetBodyCrc  0x0200BA44  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   d_020A7370  0x020A7370  data
 *   func_021D85DC 0x021D85DC arm ov125
 *   func_021D85E8 0x021D85E8 arm ov125
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   BATTLE_REC_EncodeWork 0x0200B4B8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_021D85F4 0x021D85F4 arm ov125
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0203F1FC 0x0203F1FC arm
 *   d_021D8D2C 0x021D8D2C data a4
 *   d_0214616C 0x0214616C data a4
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   func_020073D8 0x020073D8 thumb
 *   BATTLE_REC_Clear 0x0200B448 thumb
 *   func_02012E4C 0x02012E4C thumb
 *   func_02012E7C 0x02012E7C thumb
 *   func_020072A4 0x020072A4 thumb
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA040 0x021DA040 data a4
 *   func_021D7808 0x021D7808 arm ov125
 *   func_021D7CEC 0x021D7CEC arm ov125
 *   func_021D7D20 0x021D7D20 arm ov125
 *   func_021D8588 0x021D8588 arm ov125
 *   func_021D7CF4 0x021D7CF4 arm ov125
 *   func_021D7CD4 0x021D7CD4 arm ov125
 *   func_021D7F60 0x021D7F60 arm ov125
 *   func_021D858C 0x021D858C arm ov125
 *   func_021D8444 0x021D8444 arm ov125
 *   func_021D7E80 0x021D7E80 arm ov125
 *   func_021D7FA0 0x021D7FA0 arm ov125
 *   func_021D80E0 0x021D80E0 arm ov125
 *   func_021D824C 0x021D824C arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   func_021D8438 0x021D8438 arm ov125
 *   func_021D89EC 0x021D89EC arm ov125
 *   func_021D891C 0x021D891C arm ov125
 *   func_021D7D30 0x021D7D30 arm ov125
 *   func_02092344 0x02092344 arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0 0x0205A1B0 arm
 *   func_02086028  0x02086028  arm
 *   d_021DA174     0x021DA174  data  a4
 *   BATTLE_REC_SaveSeq  0x0200B67C  thumb  arm9
 *   BATTLE_REC_Encode  0x0200B908  thumb  arm9
 */

#include "../../matched/include/Obj03805.h"
#include "../../matched/include/Obj14003.h"
#include "../../matched/include/Obj02838.h"
#include "../../matched/include/Obj06472.h"
#include "../../matched/include/Obj22996.h"
#include "../../matched/include/Obj03806.h"
#include "../../matched/include/Obj14004.h"
#include "../../matched/include/Obj14005.h"
#include "../../matched/include/Obj14006.h"
#include "../../matched/include/Obj01060.h"
#include "../../matched/include/Obj00327.h"
#include "../../matched/include/Obj10460.h"
#include "../../matched/include/Obj22998.h"
#include "../../matched/include/Obj22999.h"
#include "../../matched/include/Obj23000.h"
#include "../../matched/include/Obj23004.h"
#include "../../matched/include/G_BattleRec.h"
#include "../../matched/include/Obj14011.h"

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))
#define OBJ (*(u8 **)(p + 0x404))
struct MsgBank;
struct U16Vec;
struct WordSet;
struct Rec;
struct ObjC4;
struct Big;
struct MsgData;
struct RecC4;
struct Sub0200852CObj;
struct BattleRec;
struct Ctrl;
struct Sub020072A4Ctrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[7]; } Blk;

typedef signed int     s32;

typedef struct { int words[32]; } Block128;

typedef struct { int words[108]; } Block432;

typedef int (*Callback)(void *, void *);

typedef struct { int count; char entries[1]; } List;

typedef unsigned long long u64;

typedef struct { u32 w[49]; } Rec;

extern int func_02034AC4(s32 handle);
extern void func_02082BCC(void *, int, u32);
extern int func_021D8600(int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern int func_021D8598(void *, const char *, int);
extern void func_02034714(const char *, u32, const char *);
extern void func_021B99B8(u8 *p);
extern void func_021B9838(u8 *p);
extern void func_021D85B4(void);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern void BATTLE_REC_GetModeLayout(u16, int *, int *);
extern struct ObjC4 *BATTLE_REC_GetWork(void);
extern void func_02082D44(const void *, void *, unsigned int);
extern unsigned func_021D85C0(void);
extern int func_021D860C(void *, u32);
extern int func_021D8654(int value, int n);
extern int func_021D8694(u32, void *, u32, u32);
extern int func_021D8754(void *, u32);
extern int func_021D879C(int value, int n);
extern int func_021D87FC(int value, int n);
extern int func_021D885C(int value, int n);
extern int func_021D88BC(u32, u32, u32, u32);
extern int func_021D88F0(u32, u32, u32);
extern int func_021B9748(u8 *);
extern void func_021B9774(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *);
extern u8 *func_021B9800(int a, int b, int c);
extern void func_021B98A0(u8 *p, int a, int b, int c);
extern void func_021B98D8(u8 *p, int a, int n);
extern int func_021B98F8(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B99F0(u8 *);
extern u32 func_021B99F4(u32 p, u32 i);
extern u8 *func_021B9A14(u8 *p, u32 i);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *BATTLE_REC_GetBody(void);
extern void BATTLE_REC_SetBodyCrc(struct RecC4 *p);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern void MSGDATA_ReadUnits(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern int func_021D85DC(void);
extern void BATTLE_REC_DecodeWork(void);
extern void BATTLE_REC_EncodeWork(void);
extern char *func_021D85E8(void);
extern int func_021D85F4(void);
extern void MI_CpuFill8(void *, int, unsigned int);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void BATTLE_REC_Encode(void *a, u32 b, u32 c);
extern u32 BATTLE_REC_SaveSeq(void *a, struct BattleRec *b, u32 c, u16 *state, u16 e);
extern unsigned int SAVE_CONTROL_LoadExtraSave(struct Ctrl *,unsigned int,unsigned char);
extern void *func_020073D8(void *,unsigned int,unsigned int);
extern void BATTLE_REC_Clear(void *);
extern void func_02012E4C(unsigned char *,unsigned int);
extern int func_02012E7C(char *,int);
extern void func_020072A4(struct Sub020072A4Ctrl *,unsigned int);
int func_021D6660(char *p, char *a);
void func_021D6770(char *p);
int func_021D67C8(char *p, const Block128 *a, const Block432 *b);
int func_021D6814(char *p,int v);
int func_021D683C(char *p, void *src);
int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other);
int func_021D6968(char *p);
int func_021D698C(char *p);
int func_021D69B4(char *p);
int func_021D69DC(char *p,int a,int b);
int func_021D6A08(char *p,int a,int b);
int func_021D6A34(char *p);
int func_021D6B40(u8 *p, int *done);
int func_021D6FB0(char *p);
int func_021D7060(void);
int func_021D7064(char *p, const u16 *s);
int func_021D7120(void);
void func_021D7124(char *p, int unused, int k, int a3);
int func_021D7154(int a, int index, int *outer, int *inner);
void func_021D71CC(const void *src,void *dst,u32 n);
int func_021D71D8(char *p);
int func_021D72EC(char *p, int **out);
void func_021D72F8(char *p);
int func_021D730C(char *p);
int func_021D732C(char *p, const unsigned short *s);
int func_021D7354(char *p, const unsigned short *s);
int func_021D7374(char *a, void **out, int max);
int func_021D73B8(char *p, const unsigned short *s);
unsigned long long func_021D73E0(char *a0);
int func_021D73F0(char *p, const unsigned short *s);
int func_021D7414(char *unused, char *dst, int n);
int func_021D74B4(char *p, const unsigned short *s);
int func_021D74D8(void *unused, char **out);
int func_021D7520(char *p, const unsigned short *s);
int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c);
void func_021D75C0(void);
int func_021D75E8(int a, int x, int y, u16 *state, int b, u16 c);
int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c);
void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id);
int func_021D76D8(char *p,int id);
char *func_021D7700(void);
extern char ov114_id[];
extern const char d_021D8D00[];
extern const char d_021D8D0C[];
extern char d_021D8D28[];
extern const u16 d_021D8C80[][2];
extern void *d_020A7370;
extern char d_021D8D2C[];
extern struct BattleRec *d_0214616C;



int func_021D6660(char *p, char *a)
{
    func_02034AC4((int)ov114_id);
    func_02082BCC(p, 0, 0x5A4);
    *(u32 *)(p + 0x13C) = *(u16 *)(a + 4);
    *(u32 *)p = *(u32 *)(a + 8);
    *(u32 *)(p + 0x494) = *(u32 *)(a + 0xC);
    *(Blk *)(p + 0x148) = *(Blk *)(a + 0x10);
    *(int *)(p + 0x144) = -1;
    *(u32 *)(p + 0x3D8) = 0x55F4;
    *(u32 *)(p + 0x3DC) = 0x55F4;
    *(void **)(p + 0x3AC) = func_02030734(*(u16 *)(a + 4), func_021D8600(-1), 0, d_021D8D00, 0x84);
    func_02082BCC(*(void **)(p + 0x3AC), 0, func_021D8600(-1));
    *(int *)(p + 0x3E4) = (int)func_02045B38(0, 2, 0xE8, *(u16 *)(a + 4));
    *(int *)(p + 0x3E8) = (int)func_0201EC64(*(u16 *)(a + 4));
    *(int *)(p + 0x3EC) = (int)func_020457B0(0x100, *(u16 *)(a + 4));
    *(u32 *)(p + 4) = *(u32 *)a;
    p[8] = 0x15;
    p[9] = 2;
    if (func_021D8598(p + 4, d_021D8D0C, 0x3071) != 1)
        func_02034714(d_021D8D28, 0, d_021D8D28);
    *(u32 *)(p + 0x3B4) = 1;
    *(u32 *)(p + 0x3B0) = 1;
    return 1;
}


void func_021D6770(char *p)
{
    if (((struct Obj03805 *)p)->f404) {
        func_021B99B8(((struct Obj03805 *)p)->f404);
        func_021B9838(((struct Obj03805 *)p)->f404);
    }
    func_021D85B4();
    ((struct Obj03805 *)p)->f3B4 = 0;
    func_02045808(((struct Obj03805 *)p)->f3EC);
    func_0201ED04(((struct Obj03805 *)p)->f3E8);
    func_02045C04(((struct Obj03805 *)p)->f3E4);
    func_020307B0(((struct Obj03805 *)p)->f3AC);
    func_02034A5C((int)ov114_id);
}


int func_021D67C8(char *p, const Block128 *a, const Block432 *b)
{
    if (!func_021D730C(p)) return 0;
    *(Block128 *)(p + 0x174) = *a;
    *(Block432 *)(p + 0x1f4) = *b;
    p[0x401] = 0x3c;
    ((struct Obj14003 *)p)->f3D8 = 0x5208;
    return 1;
}


int func_021D6814(char *p,int v) {if(!func_021D730C(p))return 0;*(u16 *)&((struct Obj02838 *)p)->f3A4=v;((struct Obj02838 *)p)->f3D8=0x5209;return 1;}


int func_021D683C(char *p, void *src)
{
    char *r;
    char *out;
    char *base;
    int outer, inner;
    int n, m;
    int i;
    r = func_021D7700();
    if (!func_021D730C(p)) return 0;
    BATTLE_REC_GetModeLayout(((struct Obj22996 *)r)->fA6, &n, &m);
    base = r + 0xd00;
    out = p + 0x498;
    for (i = 0; i < 12; i++) {
        if (!func_021D7154((int)p, i, &outer, &inner)) break;
        func_021D71CC(base + outer * 676 + inner * 112 + 50, out + i * 22, 11);
    }
    ((struct Obj06472 *)p)->f5A0 = 0;
    p[0x403] = 0;
    *(char * *)&((struct Obj06472 *)p)->f174 = r;
    func_02082D44(src, BATTLE_REC_GetWork(), 128);
    p[0x401] = 60;
    ((struct Obj06472 *)p)->f3D8 = 0x55f0;
    return 1;
}


int func_021D68EC(char *p, int id, unsigned int index, int mode, u8 other)
{
    if (!func_021D730C(p)) return 0;
    if (index >= 20) func_02034714(d_021D8D28, 0, d_021D8D28);
    func_02082BCC(p + 0x174, 0, 16);
    ((struct Obj03806 *)p)->f174 = id;
    ((struct Obj03806 *)p)->f176 = d_021D8C80[index][0];
    ((struct Obj03806 *)p)->f178 = d_021D8C80[index][1];
    ((struct Obj03806 *)p)->f17A = mode;
    ((struct Obj03806 *)p)->f17B = other;
    ((struct Obj03806 *)p)->f17C = 100;
    ((struct Obj03806 *)p)->f3E0 = 0;
    ((struct Obj03806 *)p)->f3D8 = 0x55f1;
    return 1;
}


int func_021D6968(char *p) {if(!func_021D730C(p))return 0;((struct Obj14004 *)p)->f3E0=1;((struct Obj14004 *)p)->f3D8=0x55f1;return 1;}


int func_021D698C(char *p) {if(!func_021D730C(p))return 0;((struct Obj14005 *)p)->f3E0=2;((struct Obj14005 *)p)->f3D8=0x55f1;return 1;}


int func_021D69B4(char *p) {if(!func_021D730C(p))return 0;((struct Obj14006 *)p)->f3E0=3;((struct Obj14006 *)p)->f3D8=0x55f1;return 1;}


int func_021D69DC(char *p,int a,int b) {if(!func_021D730C(p))return 0;((struct Obj02838 *)p)->f3A4=a;((struct Obj02838 *)p)->f3A8=b;((struct Obj02838 *)p)->f3D8=0x55f2;return 1;}


int func_021D6A08(char *p,int a,int b) {if(!func_021D730C(p))return 0;((struct Obj02838 *)p)->f3A4=a;((struct Obj02838 *)p)->f3A8=b;((struct Obj02838 *)p)->f3D8=0x55f3;return 1;}


int func_021D6A34(char *p)
{
    int result;
    if (((struct Obj01060 *)p)->f3B4 == 1) {
        if (((struct Obj01060 *)p)->f3D8 != 0x55f4) {
            if (((struct Obj01060 *)p)->f401 != 0) {
                (((struct Obj01060 *)p)->f401)--;
            } else {
                switch (func_021D85C0()) {
                case 1: case 7: case 8: case 9:
                    if (func_021D6B40((u8 *)p, &result) == 1) {
                        ((struct Obj01060 *)p)->f3D8 = 0x55f4;
                        ((struct Obj01060 *)p)->f402 = 0;
                        if (result == 1) {
                            ((struct Obj01060 *)p)->f168 = 2;
                            ((struct Obj01060 *)p)->f16C = 0x55f0;
                            ((struct Obj01060 *)p)->f170 = ((struct Obj01060 *)p)->f493;
                            ((struct Obj01060 *)p)->f164 = 1;
                            if (*(Callback *)&((struct Obj01060 *)p)->f154 != 0)
                                (*(Callback *)(p + 0x154))(((struct Obj01060 *)p)->f148, p + 0x164);
                        }
                    }
                    break;
                case 0: case 2: case 3: case 4: case 5: case 6:
                default: break;
                }
            }
        }
        func_021D6FB0(p);
        if (*(Callback *)&((struct Obj01060 *)p)->f3FC != 0) {
            if ((*(Callback *)(p + 0x3fc))(p, p + 0x3f0) == 1) {
                *(Callback *)&((struct Obj01060 *)p)->f3FC = 0;
                if (*(Callback *)&((struct Obj01060 *)p)->f3F0 != 0) {
                    (*(Callback *)(p + 0x3f0))(((struct Obj01060 *)p)->f148, p + 0x164);
                    *(Callback *)&((struct Obj01060 *)p)->f3F0 = 0;
                }
                func_02082BCC(p + 0x3f0, 0, 16);
                ((struct Obj01060 *)p)->f3DC = 0x55f4;
            }
        }
    }
    return 1;
}




/*
 * 2026-10-05 (wD9r lane109): EXACT. The 0x55F1 inner switch is written out as an expanded inline:
 *   r = 0; cases 0..2 set r and break; case 3 sets t and `goto join`; then `t = r; join: ret = t;`.
 *   t is declared first, so the merged ret/t/r value keeps an early local's spill slot ([sp,#8]);
 *   a real static inline helper put it in the inline return temp's slot ([sp]).
 */
int func_021D6B40(u8 *p, int *done)
{
    int t;
    int n, m;
    int idx, sub;
    int n2, m2;
    int ret;
    int r;
    char *base;
    char *base2;
    int i;
    u8 *h;
    int a, b;
    u8 x;

    *done = 0;
    ret = 0;
    switch (*(int *)(p + 0x3d8)) {
    case 0x5208:
        ret = func_021D860C(p + 0x174, W(0x3ac));
        break;
    case 0x5209:
        ret = func_021D8654(H(0x3a4), W(0x3ac));
        break;
    case 0x55f0:
        switch (B(0x402)) {
        case 0:
            base = func_021D7700();
            if (OBJ != 0)
                func_02034714(d_021D8D28, ret, d_021D8D28);
            OBJ = func_021B9800((u16)W(0x13c), func_0200853C((const struct Sub0200852CObj *)func_02012944((void *)W(0))), W(0x494));
            func_021B98A0(OBJ, (u16)W(0x13c), 0x540, 3);
            BATTLE_REC_GetModeLayout(*(u16 *)(base + 0xa6), &n, &m);
            B(0x490) = 0;
            for (i = 0; i < n; i++) {
                func_021B98D8(OBJ, (int)(base + 0xd00 + i * 0x2a4), *(u16 *)(base + i * 0x2a4 + 0xcfe) * 0x70);
                B(0x490) += (u8)*(u16 *)(base + i * 0x2a4 + 0xcfe);
            }
            if (!func_021B98F8(OBJ))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            if (!(func_021B9748(OBJ) == 0 ? 1 : 0))
                func_02034714(d_021D8D28, 0, d_021D8D28);
            B(0x402)++;
            break;
        case 1:
            a = func_021B99DC(OBJ);
            b = func_021B9790(OBJ);
            if (a != 200 && b != 15) {
                switch (func_021B99DC(OBJ)) {
                case 0x190: B(0x493) = 0x96; break;
                case 0x191: B(0x493) = 0x97; break;
                case 0x198: B(0x493) = 0x98; break;
                default: B(0x493) = 0x99; break;
                }
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                *done = 1;
                return 1;
            }
            if (b == 0) {
                h = func_021B97F4(OBJ);
                if (func_021B99F0(h) == 0) {
                    B(0x492) = 0;
                    func_02082D44(func_021B9A14(h, B(0x490)), p + 0x40a, 0x80);
                    for (i = 0; i < B(0x490); i++)
                        W(0x48c) = func_021B99F4((u32)h, i);
                    B(0x402)++;
                } else {
                    base2 = func_021D7700();
                    if (B(0x403) == 1)
                        B(0x492) = 1;
                    BATTLE_REC_GetModeLayout(*(u16 *)(base2 + 0xa6), &n2, &m2);
                    for (i = 0; i < B(0x490); i++) {
                        W(0x48c) = func_021B99F4((u32)h, i);
                        if (W(0x48c) != 0 && B(0x403) == 0) {
                            if (!func_021D7154((int)p, i, &idx, &sub))
                                break;
                            {
                                char *e = base2 + 0xd00 + idx * 0x2a4 + sub * 0x70;
                                MSGDATA_ReadUnits(d_020A7370, *(u16 *)(e + 6), (u16 *)(e + 0x32), 11);
                            }
                            W(0x5a0) = 1;
                        }
                    }
                    if (B(0x403) == 0) {
                        BATTLE_REC_SetBodyCrc((struct RecC4 *)BATTLE_REC_GetBody());
                        B(0x402) = 0;
                        B(0x403)++;
                    } else {
                        B(0x402)++;
                    }
                }
                func_021B99B8(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                break;
            }
            if (b != 15 && OBJ != 0) {
                func_021B99B8(OBJ);
                func_021B9774(OBJ);
                func_021B9838(OBJ);
                OBJ = 0;
                return 1;
            }
            return 0;
        case 2:
            func_02012EBC((struct Big *)W(0));
            func_021D75C0();
            B(0x402)++;
            break;
        case 3:
            ret = func_021D8694(W(0x174), p + 0x40a, 0x80, W(0x3ac));
            break;
        }
        break;
    case 0x55f1:
        r = 0;
        switch (W(0x3e0)) {
        case 0:
            r = func_021D8754(p + 0x174, W(0x3ac));
            break;
        case 1:
            r = func_021D879C(0x64, W(0x3ac));
            break;
        case 2:
            r = func_021D885C(0x64, W(0x3ac));
            break;
        case 3:
            t = func_021D87FC(0x64, W(0x3ac));
            goto join;
            break;
        }
        t = r;
    join:
        ret = t;
        break;
    case 0x55f2:
        ret = func_021D88BC(W(0x3a4), W(0x3a8), 0x64, W(0x3ac));
        break;
    case 0x55f3:
        ret = func_021D88F0(W(0x3a4), W(0x3a8), W(0x3ac));
        break;
    default:
        func_02034714(d_021D8D28, 0, d_021D8D28);
        break;
    }
    if (ret == 1)
        W(0x3dc) = W(0x3d8);
    return ret;
}



int func_021D6FB0(char *p)
{
    unsigned int state;
    if (((struct Obj00327 *)p)->f3DC == 0x55f4) return 1;
    state = func_021D85C0();
    ((struct Obj00327 *)p)->f140 = state;
    if (state != ((struct Obj00327 *)p)->f144) {
        switch (state) {
        case 7:
            ((struct Obj00327 *)p)->f168 = 1;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = 7;
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = func_021D7120;
            break;
        case 8:
            ((struct Obj00327 *)p)->f3FC = func_021D7060;
            func_021D71D8(p);
            break;
        case 9:
            ((struct Obj00327 *)p)->f168 = 0;
            ((struct Obj00327 *)p)->f16C = 0;
            ((struct Obj00327 *)p)->f170 = func_021D85DC();
            ((struct Obj00327 *)p)->f164 = 1;
            ((struct Obj00327 *)p)->f3FC = func_021D7120;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        default: break;
        }
        ((struct Obj00327 *)p)->f144 = ((struct Obj00327 *)p)->f140;
    }
    return 1;
}



int func_021D7060(void) { return 1; }



int func_021D7064(char *p, const u16 *s)
{
    char *base;
    char *out;
    char *r;
    int outer, inner;
    int n, m;
    int i;
    int *obj;
    int result;
    if (s[2] == 0 && ((struct Obj10460 *)p)->f5A0 != 0) {
        r = func_021D7700();
        BATTLE_REC_DecodeWork();
        BATTLE_REC_GetModeLayout(((struct Obj22998 *)r)->fA6, &n, &m);
        i = 0;
        out = p + 0x498;
        base = r + 0xd00;
        for (; i < 12; i++) {
            if (!func_021D7154((int)p, i, &outer, &inner)) break;
            func_021D71CC(out + i * 22, base + outer * 676 + inner * 112 + 50, 11);
        }
        BATTLE_REC_SetBodyCrc((struct RecC4 *)BATTLE_REC_GetBody());
        BATTLE_REC_EncodeWork();
    }
    obj = (int *)func_021D85E8();
    result = func_021D75E8(((struct Obj10460 *)p)->f0, obj[1], obj[2], (u16 *)(s + 2), (int)(s + 3), (u16)((struct Obj10460 *)p)->f13C);
    if (result == 2 || result == 3) return 1;
    return 0;
}



int func_021D7120(void) { return 1; }




void func_021D7124(char *p, int unused, int k, int a3)
{
    if ((k == 3 || k == 6) && *(u8 **)(p + 0x404) != 0) {
        func_021B99B8(*(u8 **)(p + 0x404));
        func_021B9774(*(u8 **)(p + 0x404));
        func_021B9838(*(u8 **)(p + 0x404));
        *(int *)(p + 0x404) = 0;
    }
}



int func_021D7154(int a, int index, int *outer, int *inner)
{
    char *p;
    int n, other;
    int i;
    i = 0;
    p = func_021D7700();
    BATTLE_REC_GetModeLayout(((struct Obj22999 *)p)->fA6, &n, &other);
    for (*outer = 0; *outer < n; ++*outer) {
        for (*inner = 0; *inner < *(u16 *)(p + *outer * 676 + 0xcfe); ++*inner) {
            if (i == index) return 1;
            ++i;
        }
    }
    return 0;
}



void func_021D71CC(const void *src,void *dst,u32 n) {func_02082D44(src,dst,n*2);}



int func_021D71D8(char *p)
{
    const u16 *state;
    int result = 1;
    state = (const u16 *)func_021D85E8();
    func_021D85F4();
    if (((struct Obj00327 *)p)->f3DC != state[0]) func_02034714(d_021D8D28, 0, d_021D8D28);
    ((struct Obj00327 *)p)->f3F0 = 0;
    switch (state[0]) {
    case 0: break;
    case 21000:
        result = func_021D732C(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f14C;
        break;
    case 21001:
        result = func_021D7354(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f150;
        break;
    case 22000:
        result = func_021D73B8(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f154;
        if (result == 1) ((struct Obj00327 *)p)->f3FC = (void *)func_021D7064;
        break;
    case 22001:
        result = func_021D73F0(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f158;
        break;
    case 22002:
        result = func_021D74B4(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f15C;
        break;
    case 22003:
        result = func_021D7520(p, state);
        ((struct Obj00327 *)p)->f3F0 = ((struct Obj00327 *)p)->f160;
        break;
    }
    if (result == 0) {
        ((struct Obj00327 *)p)->f168 = 2;
        ((struct Obj00327 *)p)->f16C = state[0];
        ((struct Obj00327 *)p)->f170 = state[1];
        ((struct Obj00327 *)p)->f164 = 1;
    } else ((struct Obj00327 *)p)->f164 = 0;
    return result;
}



int func_021D72EC(char *p, int **out)
{
    *out = (int *)(p + 0x164);
    return ((struct Obj23000 *)p)->f164;
}



void func_021D72F8(char *p)
{
    MI_CpuFill8(p + 0x164, 0, 16);
}



int func_021D730C(char *p) { if (*(unsigned int *)&((struct Obj02838 *)p)->f3D8==0x55f4 && ((struct Obj02838 *)p)->f3DC==0x55f4) return 1; return 0; }



int func_021D732C(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: break; default: break; } return r; }



int func_021D7354(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }



int func_021D7374(char *a, void **out, int max)
{
    int p;
    char *base;
    int n;
    int i;
    p = (int)(func_021D85E8() + 4);
    n = ((struct Obj23004 *)p)->f0;
    if (n > max) n = max;
    base = (char *)(p + 4);
    for (i = 0; i < n; i++) out[i] = base + i * 572 + 12;
    for (; i < max; i++) out[i] = 0;
    return n;
}



int func_021D73B8(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: case 7: break; default: break; } return r; }



unsigned long long func_021D73E0(char *a0) { int *p=(int *)func_021D85E8(); return *(unsigned long long *)(p+1); }



int func_021D73F0(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }




/*
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
 */
int func_021D7414(char *unused, char *dst, int n)
{
    int *g = (int *)func_021D85E8();
    int *hdr = g + 1;
    char *base;
    int cnt;
    int i;

    cnt = hdr[0];
    if (cnt > n) {
        cnt = n;
        func_02034714(d_021D8D2C, 0, d_021D8D2C);
    }
    func_02082BCC(dst, 0, n * 0xC4);
    i = 0;
    base = (char *)hdr + 4;
    for (i = 0; i < cnt; i++) {
        char *e = base + i * 0xD0;
        u64 id = *(u64 *)(e + 4);
        if (*(u64 *)(e + 0xC4) != id) {
            *(u64 *)(e + 0xC4) = id;
            *(u16 *)(e + 0xCC) = func_0203F1FC((const u8 *)(e + 0x8C), 0x38);
        }
        *(Rec *)(dst + i * 0xC4) = *(Rec *)(e + 0xC);
    }
    return cnt;
}



int func_021D74B4(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }



int func_021D74D8(void *unused, char **out)
{
    char *p = (char *)func_021D85E8();
    char *s = p + 4;
    u64 id;

    *out = s + 0xC;
    id = *(u64 *)(p + 8);
    if (*(u64 *)(s + 0xC4) != id) {
        *(u64 *)(s + 0xC4) = id;
        *(u16 *)(*out + 0xC0) = func_0203F1FC((u8 *)(*out + 0x80), 0x38);
    }
    return *(int *)(p + 8);
}



int func_021D7520(char *p, const unsigned short *s) { int r=0; switch (s[1]) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }



int func_021D7540(void *a, int x, int mode, u16 *state, u16 *b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        if (mode == 1) {
            *(unsigned char *)(((char *)d_0214616C) + 0xaa) = mode;
            *(u16 *)(((char *)d_0214616C) + 0xa8) = 57985;
            *(u16 *)(((char *)d_0214616C) + 0xc0) = func_0203F1FC((const u8 *)(((char *)d_0214616C) + 0x80), 56);
        }
        value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
        BATTLE_REC_Encode(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(a, (struct BattleRec *)((char *)d_0214616C), x, b, c);
    }
    return 0;
}



void func_021D75C0(void)
{
    unsigned int value;
    value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
    BATTLE_REC_Encode(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
}



int func_021D75E8(int a, int x, int y, u16 *state, int b, u16 c)
{
    char *p;
    switch (*state) {
    case 0:
        p = ((char *)d_0214616C);
        ((struct Obj14011 *)p)->fB8 = x;
        ((struct Obj14011 *)p)->fBC = y;
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq((void *)a, (struct BattleRec *)((char *)d_0214616C), 0, (u16 *)b, c);
    }
    return 0;
}



int func_021D7630(void *a, int x, u16 *state, u16 *b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        *(unsigned char *)(((char *)d_0214616C) + 0xaa) = 1;
        *(u16 *)(((char *)d_0214616C) + 0xa8) = 57985;
        *(u16 *)(((char *)d_0214616C) + 0xc0) = func_0203F1FC((const u8 *)(((char *)d_0214616C) + 0x80), 56);
        value = *(u16 *)(((char *)d_0214616C) + 0x18a0);
        BATTLE_REC_Encode(((char *)d_0214616C) + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(a, (struct BattleRec *)((char *)d_0214616C), x, b, c);
    }
    return 0;
}



void func_021D76A8(unsigned char *p,unsigned char heap,unsigned int id) {void *s=func_02012EBC((struct Big *)p); SAVE_CONTROL_LoadExtraSave(s,id,heap); BATTLE_REC_Clear(func_020073D8(s,id,0)); func_02012E4C(p,id);}



int func_021D76D8(char *p,int id) {void *s=func_02012EBC((struct Big *)p); int r=func_02012E7C(p,id); if(r==2 || r==3) func_020072A4(s,id); return r;}



char *func_021D7700(void) { return ((char *)d_0214616C); }

#pragma thumb off


#include "../../matched/include/G_Clear.h"

#define D(o) (*(int *)(((char *)&d_021D9E40) + (o)))
typedef struct { int words[78]; } Record;

typedef struct { Record record; int f138; char pad13c[4]; char name[256]; char pad240[24]; int f258; char pad25c[16]; int f26c; } State;

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 2 bytes (+CC/+D0, str/cmp use r4 instead of the call result r0). Tried (all identical output): chained `*(int *)&hdr = sz = f(id)`, `sz = *(int *)&hdr = f(id)`, `hdr = tmp = f(); sz = tmp`, `sz = tmp = f(); hdr = tmp`, assignment inside the if condition, tmp unsigned, callee returning unsigned, sz parameter unsigned, hdr stored first and compared through hdr then copied to sz (before or after the check). The same str r0/cmp r0 shape appears for the global store D(0x25c) = f(); if (D(0x25c) == -1) in this function, so the original probably compared a value the compiler did not merge with sz.
 */
/*
 * 2026-10-05 (wave D5 lane09): DIFF, 2 bytes unchanged. Reading: the original keeps the call result in
 *   r0 for the hdr store and the -1 compare and copies it to r4, so the result temp is NOT coalesced
 *   with sz (it is coalesced with r0); in every draft form it is coalesced with sz. Tried: hdr as a
 *   union {u8 b[4]; int i;} with member stores/compare (no address-of; worse, byte copy loses the
 *   add r5,sp,#0 pointer), a separate `size` local for both arms (identical). Next: find a use that
 *   makes the result temp interfere with sz (old sz live after the call).
 */
/*
 * 2026-10-05 (wave D6 lane02): DIFF, 2 bytes unchanged. Callee check: func_021D891C(int n) takes one
 *   argument (matched), so no hidden argument. Tried: the copy to sz after the -1 check (sz = tmp
 *   at the end of the else arm, identical), sz as the address-taken source of the 4-byte copy
 *   (h = &sz: the parameter goes to the stack, 365 bytes worse; hdr is a separate local at [sp]).
 *   Reading: the result temp is coalesced with sz in every form; the original coalesces it with r0.
 */
/*
 * 2026-10-05 (wave D7 lane07): DIFF, 2 bytes unchanged (+CC str, +D0 cmp use r4, image r0).
 *   Tried (all identical, 2 bytes): if/else polarity swapped (`if (sz == -1)` first: 54 bytes worse,
 *   so the then-arm is sz != -1); tmp declared in the inner block; tmp declared last; the call
 *   through a static inline helper (returning the value, or also storing hdr through a W4 pointer);
 *   the dead parameter x reused as the result temp; sz = f(id) with the check read through
 *   `*(int *)&hdr`. Comparing the result against the old sz (== -1 in that arm) makes the old sz
 *   live across the call: 380 bytes worse (frame changes). Reading: mwcc coalesces the call
 *   result with sz in every source form; the image keeps it in r0. No source lever found.
 */
/*
 * 2026-10-05 (wave D8 lane08): DIFF, 2 bytes unchanged. Tried: one temp for both arms (`tmp = sz + 0x140` in
 *  the then-arm, `tmp = f(id)` in the else-arm, hdr stored from tmp in each arm, `sz = tmp` after the join):
 *  identical 2 bytes, the call result is still coalesced with the size register r4.
 */
/*
 * 2026-10-05 (wave D9r lane10): DIFF, 2 bytes unchanged. Tried: a static inline Load(&sz, &hdr, id) that stores the
 *  result through both pointers and returns it for the -1 test; `sz = f(id); hdr = sz; if (*(int *)&hdr == -1)`.
 *  Both identical (2 B). The result is still coalesced with sz.
 */
typedef struct { int w[0x138 / 4]; } Blob;

/*
 * 2026-10-05 (wave D9 lane16): DIFF, 2 bytes unchanged. Reading only: the image uses the call result r0 for the
 *  hdr store and the -1 compare the same way as the earlier `D(0x25c) = f(id); if (D(0x25c) == -1)`, so the
 *  else-arm value was probably never a named local before the check. All forms of that (store to hdr, compare
 *  hdr, copy to sz) are listed above as tried and give identical output. New tests: D(0x260) = x written in each
 *  arm (221 B worse, the store is not merged up); result stored only into hdr, compared through hdr, and
 *  `sz = *(int *)&hdr` at the end of the else arm (identical 2 B).
 */
/*
 * 2026-10-05 (wD9r lane46): DIFF, 2 bytes unchanged. Tried: hdr as a plain int local (address taken only for the
 *  byte copy) instead of the W4 struct: identical 2 B. Reading: the image pattern (mov r4,r0; then uses of r0)
 *  needs the call result to interfere with sz; no source form tried so far makes it do that.
 */
/*
 * 2026-10-05 (wD9r lane59): DIFF, 2 bytes unchanged. Tried: the call result and tmp as `long` (a non-int type,
 *  to block the copy coalesce) and sz as a `long` parameter: identical 2 B. hdr written in both arms with no sz
 *  update and `sz = *(int *)&hdr` once after the join: 209 B worse (reload from the stack). Reading: the else-arm
 *  call result must interfere with sz to stay in r0; no natural use found that makes it interfere.
 */
/*
 * 2026-10-05 (wD9r lane80): DIFF, 2 bytes unchanged in the draft. Tried: both -1 error paths through one shared
 *  `err:` label (goto from the D(0x25c) check): 416 B, the error blocks merge and the base register changes, so the
 *  image has two separate error copies. Reading: func_021D891C (matched) returns size + 0x140, so the then-arm
 *  `sz + 0x140` and the else-arm call give the same quantity; the call result still coalesces with sz.
 */
/*
 * 2026-10-05 (wD9r lane88): DIFF, 2 bytes unchanged. Callee prototypes checked against the matched definitions
 *  (func_021D891C int(int), func_021D89EC int(int), func_021D7C7C void(int), func_021D7D30 returns its tail call):
 *  no mismatch that matters here. Tried: one `tmp` local reused for both -1 checks (D(0x25c) = tmp and the else-arm
 *  result, so tmp has two definitions and cannot be propagated); else-arm as `else if ((*(int *)&hdr = sz = f(id))
 *  == -1)`; result stored only to hdr, tested as tmp, `sz = *(int *)&hdr` last. All identical (2 B, str/cmp on r4).
 */
/*
 * 2026-10-05 (wD9r lane100): DIFF, 2 bytes unchanged in the draft. Twin search: no other function in src/matched or
 *  asm/overlays has the addne #0x140 / sz - 0x140 shape (only ov125 itself), so no twin to copy. Tried: the -1 error
 *  block as a static inline check helper `chk(v)` (sets D(0x13c)=9, D(0x250)=2, returns 0/1), called with sz, with the
 *  chained `*(int *)&hdr = sz = f(id)`, and a `chk2(&hdr, v)` that also stores hdr: all 456 B, 211 differ (the helper
 *  return merges badly; the call result is still coalesced with r4).
 */
/*
 * 2026-10-05 (wD9r lane119): DIFF, 2 bytes unchanged. Reading: our output also has `mov r4, r0` after the call;
 *  only the store and compare read r4 instead of r0, so the result temp is coalesced with sz and the copy is the
 *  call-result move. Tried the zero-valued-local add (docs/idioms/a-self-move-after-a-call-is-an-add-of-a-zero-valued-local.md)
 *  to stop the coalesce: `sz = tmp + z` with the existing z set to 0 at the top, and `sz = tmp + pad` /
 *  `sz = pad + tmp` with a fresh zero local (set at the top or in the else arm). All identical (2 B): in ARM the
 *  zero add folds before coalescing.
 */
/*
 * 2026-10-05 (wD9r lane133): DIFF, 2 bytes unchanged. Tried: `register int tmp;` (the storage class can change
 *  coalescing in some front ends): identical 2 B. Reading: the image shape (copy to r4 first, then str/cmp on r0)
 *  is what a phi copy placed at the end of the else block and scheduled up would give; every C form tried names
 *  one size variable in both arms, so mwcc coalesces the result into it. A ternary join would need the -1 check
 *  on the then-arm too, which the image does not have.
 */
/*
 * 2026-10-05 (wD9r lane149): DIFF, 2 bytes unchanged. Tried the join-copy reading: two size variables, one per arm
 *  (n1 = sz + 0x140 / n2 = f(id), each stored to hdr, merged into `size` at the end of each arm, `sz = size` after the
 *  join); `size = sz` copied first and used in both arms; the else arm ends `sz = *(int *)&hdr`; the call inside the
 *  else-if condition with the copy in a final else; the result held in the later pointer variable p, and in z. All
 *  identical 2 B: ours emits `mov r4, r0` then str/cmp on r4, so the result temp is still merged with the size.
 */
/*
 * 2026-10-05 (wD9r lane160): DIFF, 2 bytes unchanged. Tried the narrow-type levers of this wave: `unsigned short id`
 *  parameter (the id is only stored as a halfword): identical 2 B; the result temp and the callee return as unsigned
 *  int compared with 0xFFFFFFFF: identical; sz assigned from the call and the check read through `*(int *)&hdr`:
 *  identical; the check as `tmp + 1 == 0`: 472 B (the -1 constant in r8 is lost). The call result still coalesces
 *  with sz (r4).
 */
typedef struct { unsigned char b[4]; } W4;

extern void func_021D8588(void);
extern int func_021D7CF4(void);
extern int func_021D7CD4(void);
extern char *func_02094798(char *, const char *);
extern void func_021D7F60(void);
extern void func_021D858C(void);
extern int func_021D8444(void);
extern int func_021D7E80(void);
extern int func_021D7FA0(void);
extern int func_021D80E0(void);
extern int func_021D824C(void);
extern void func_021D7CC0(void);
extern void func_021D8438(int);
extern int func_021D89EC(int);
extern int func_021D891C(int);
extern int func_021D7D30(void);
extern void *func_02092344(void *, const void *, unsigned);
extern char *func_0205A16C(int, int);
extern void func_0205A1B0(int,int,int);
extern void func_02086028(void *);
int func_021D7770(const char *a, unsigned short b, Record *src);
void func_021D7808(void);
void func_021D7874(void);
int func_021D7A10(int id, void *buf, int x, int sz);
unsigned int func_021D7BCC(void);
char *func_021D7BDC(void);
int func_021D7C14(void);
int func_021D7C48(void);
char *func_021D7C7C(int a);
void func_021D7C90(int p);
void func_021D7CAC(void);
extern State d_021D9E40;
extern char d_021DA040[];
extern char d_021DA174[];



static inline Record *copy(Record *dst, const Record *src) { *dst = *src; return dst; }



void func_021D770C(void)
{
    func_021D7808();
    __builtin__clear(&d_021D9E40, sizeof(Record));
    d_021D9E40.f138 = 0;
    d_021D9E40.name[0] = 0;
    *(short *)(d_021DA040 + 0x40) = 0;
    func_021D7CEC(d_021DA040);
    func_021D7D20();
}

int func_021D7770(const char *a, unsigned short b, Record *src)
{
    if (src) {
        d_021D9E40.record = *src;
        d_021D9E40.f138 = 0;
    }
    func_021D8588();
    if (!func_021D7CF4()) return 0;
    func_021D7CD4();
    func_02094798(d_021D9E40.name, a);
    *(short *)(d_021DA040 + 0x40) = b;
    d_021D9E40.f258 = 0;
    d_021D9E40.f26c = -1;
    func_021D7808();
    return 1;
}



void func_021D7808(void) {
 func_021D7F60();
 if(((int *)&d_021D9E40)[0x258/4]) {
  func_021D7C90(((int *)&d_021D9E40)[0x258/4]);
  ((int *)&d_021D9E40)[0x258/4]=0;
 }
 ((int *)&d_021D9E40)[0x244/4]=15;
 ((int *)&d_021D9E40)[0x248/4]=30;
 ((int *)&d_021D9E40)[0x24c/4]=30;
 ((int *)&d_021D9E40)[0x254/4]=0;
 ((int *)&d_021D9E40)[0x25c/4]=0;
 ((int *)&d_021D9E40)[0x260/4]=0;
 ((int *)&d_021D9E40)[0x264/4]=0;
 ((int *)&d_021D9E40)[0x268/4]=0;
 ((int *)&d_021D9E40)[0x13c/4]=1;
 ((int *)&d_021D9E40)[0x250/4]=0;
 func_021D858C();
}



/*
 * lever: case 6 uses an explicit nested if for the error-13 split; the ternary spelling compiled four bytes short.
 */
void func_021D7874(void)
{
    int finish, next;
    for (;;) {
        finish = 0;
        switch (((int *)&d_021D9E40)[0x13c/4]) {
        case 0: case 1: case 7: case 8: case 9:
            finish = 1;
            break;
        case 2:
            if (!func_021D8444()) {
                next = ((int *)&d_021D9E40)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 3;
            func_021D7CAC();
            ((int *)&d_021D9E40)[0x13c/4] = next;
            break;
        case 3:
            if (!func_021D7E80()) {
                next = ((int *)&d_021D9E40)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 4;
            func_021D7CAC();
            ((int *)&d_021D9E40)[0x13c/4] = next;
            break;
        case 4:
            if (!func_021D7FA0()) {
                next = ((int *)&d_021D9E40)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 5;
            func_021D7CAC();
            ((int *)&d_021D9E40)[0x13c/4] = next;
            break;
        case 5:
            if (!func_021D80E0()) {
                next = ((int *)&d_021D9E40)[0x250/4] == 13 ? 7 : 9;
                finish = 1;
            } else next = 6;
            if (((int *)&d_021D9E40)[0x258/4]) {
                func_021D7C90(((int *)&d_021D9E40)[0x258/4]);
                ((int *)&d_021D9E40)[0x258/4] = 0;
            }
            func_021D7CAC();
            ((int *)&d_021D9E40)[0x13c/4] = next;
            break;
        case 6:
            if (!func_021D824C()) {
                if (((int *)&d_021D9E40)[0x250/4] == 13) next = 7;
                else next = 9;
            } else {
                next = 8;
            }
            finish = 1;
            func_021D7CAC();
            ((int *)&d_021D9E40)[0x13c/4] = next;
            break;
        }
        if (finish != 0) break;
        if (((int *)&d_021D9E40)[0x268/4] == 1) {
            ((int *)&d_021D9E40)[0x13c/4] = 7;
            ((int *)&d_021D9E40)[0x250/4] = 13;
            break;
        }
        func_021D7CC0();
        func_021D8438(1);
    }
    func_021D7CC0();
}



static inline void cp4(W4 *d, const W4 *s) { *d = *s; }



/*
 * 2026-10-05 (user decision): the long long temp for the call result is accepted as plausible original design (a 64-bit size type).
 * note 2026-10-04 wD3 lane14: complete draft, 2 bytes differ (listing +CC,+D0): in the sz==-1 path the original stores and compares the callee result r0 (str r0,[sp]; cmp r0,r8) after mov r4,r0; ours uses r4. Tried tmp then sz order, sz assigned after check, common-tail store with tmp. The 4-byte hdr copy is written as byte copies through an unsigned char pointer (add r5,sp,#0 matches only that way).
 */
int func_021D7A10(int id, void *buf, int x, int sz)
{
    int tmp;
    W4 hdr;
    char *p;
    char *q;
    unsigned char *h;
    int z;
    func_021D7CAC();
    switch (D(0x13c)) {
    case 0: case 2: case 3: case 4: case 5: case 6:
        func_021D7CC0();
        D(0x13c) = 9;
        D(0x250) = 1;
        return 0;
    case 7:
    case 8:
    case 9:
        func_021D7808();
        break;
    }
    func_021D7CC0();
    D(0x25c) = func_021D89EC(id);
    if (D(0x25c) == -1) {
        D(0x13c) = 9;
        D(0x250) = 2;
        return 0;
    }
    D(0x260) = x;
    if (sz != -1) {
        sz += 0x140;
        *(int *)&hdr = sz;
    } else {
        long long v = func_021D891C(id);
        sz = (int)v;
        *(int *)&hdr = (int)v;
        if ((int)v == -1) {
            D(0x13c) = 9;
            D(0x250) = 2;
            return 0;
        }
    }
    p = func_021D7C7C(sz);
    D(0x258) = (int)p;
    if (p == 0) return 0;
    D(0x254) = sz;
    h = (unsigned char *)&hdr;
    p[0] = h[0]; p[1] = h[1]; p[2] = h[2]; p[3] = h[3];
    q = *(char **)&D(0x258);
    *(unsigned short *)(q + 4) = id;
    *(Blob *)(q + 8) = *(Blob *)((char *)&d_021D9E40);
    z = 0;
    *(unsigned short *)(q + 6) = z;
    func_02092344(q + 0x140, buf, sz - 0x140);
    D(0x13c) = 2;
    func_021D7CAC();
    if (func_021D7D30() == 0) {
        D(0x13c) = 9;
        D(0x250) = 6;
        func_021D7CC0();
        return z;
    }
    func_021D7CC0();
    return 1;
}




/*
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves.
 *
 * Addresses are Black-image addresses.
 */
unsigned int func_021D7BCC(void)
{
    return ((unsigned int *)&d_021D9E40)[0x4f];
}


char *func_021D7BDC(void) {func_021D7CAC(); if(func_021D7BCC()!=8){func_021D7CC0();return 0;} func_021D7CC0();return *(char **)(((char *)&d_021D9E40)+0x260)+4;}


int func_021D7C14(void){func_021D7CAC();if(func_021D7BCC()!=8){func_021D7CC0();return -1;}else{func_021D7CC0();return *(int*)(((char *)&d_021D9E40)+0x25c);}}


int func_021D7C48(void){func_021D7CAC();if(func_021D7BCC()!=9){func_021D7CC0();return 0;}else{func_021D7CC0();return *(int*)(((char *)&d_021D9E40)+0x250);}}



/*
 * Addresses are Black-image addresses.
 */
char *func_021D7C7C(int a)
{
    return func_0205A16C(0, a);
}


void func_021D7C90(int p){if(p)func_0205A1B0(0,p,0);}



void func_021D7CAC(void)
{
    func_02086028(d_021DA174);
}
