/*
 * file:     wifilogin_disp_p11.c
 * unit:     yes
 * function: func_021D50BC, func_021D5214, func_021D532C, func_021D5528, func_021D5598, func_021D57D0
 * address:  0x021D50BC
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   sub_02040588 0x02040588 arm
 *   sub_020409B4 0x020409B4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   d_021D63E4 0x021D63E4 data a4
 *   d_021D63C4 0x021D63C4 data a4
 *   d_021D63A4 0x021D63A4 data a4
 *   d_021D6384 0x021D6384 data a4
 *   d_021D6404 0x021D6404 data a4
 *   d_021D6344 0x021D6344 data a4
 *   d_021D64E4 0x021D64E4 data a4
 *   d_021D6504 0x021D6504 data a4
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02021F64 0x02021F64 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02049238 0x02049238 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_02040618 0x02040618 arm
 *   sub_020490F4 0x020490F4 arm
 *   sub_02049B68 0x02049B68 arm
 *   sub_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   sub_0204A6C8 0x0204A6C8 arm
 *   sub_0204AC18 0x0204AC18 arm
 *   sub_0204AF28 0x0204AF28 arm
 *   sub_02049238 0x02049238 arm
 *   sub_0204B294 0x0204B294 arm
 *   sub_0204B92C 0x0204B92C arm
 *   sub_0204B3DC 0x0204B3DC arm
 *   sub_02005624 0x02005624 thumb
 *   func_021D58B4 0x021D58B4 thumb ov115
 *   func_02024230 0x02024230 thumb
 *   func_0204A48C 0x0204A48C arm
 *   func_0204B100 0x0204B100 arm
 *   func_021D5900 0x021D5900 thumb ov115
 *   d_020A1448 0x020A1448 data a4
 *   d_021D65E4 0x021D65E4 data a4
 */
#include "../../matched/include/Obj03251.h"
#include "../../matched/include/Obj00198.h"

struct Obj;
struct Cfg;
struct Bank;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct BgTemplate {
    u32 unk_00, unk_04, bufSize, unk_0c;
    u8 unk_10, unk_11, unk_12, unk_13;
    u32 unk_14;
    u8 unk_18, unk_19, unk_1a, unk_1b;
    u32 unk_1c;
} BgTemplate;

typedef unsigned short u16;

typedef short s16_021D5528;

typedef signed short s16_021D5598;

struct Rect { s16_021D5598 x,y; u16 z; u8 kind,mode; };

typedef signed int     s32;

typedef short s16_021D57D0;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void sub_02040588(unsigned char which, unsigned char enable);
extern void sub_020409B4(u8);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_02041300(u8, int, int, int, u8, u8, u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02082BCC(void *, u8, u32);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020862F0(void *, int);
extern void *func_020056A0(void *, void *, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02049238(void *);
extern void func_0207E3D0(void *, int, int);
extern void func_0207E468(void *, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void *sub_020490F4(u32 id, u32 heap);
extern void sub_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 sub_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 sub_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 sub_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 sub_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void sub_02049238(void *);
extern struct Obj *sub_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void sub_0204B92C(struct Obj *,u32);
extern void sub_0204B3DC(struct Obj *,u32);
extern void *sub_02005624(u32,u32,u32);
extern void func_021D58B4(void *,u8 *);
extern void func_02024230(s16_021D5598 *,u32,u16,int);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_021D5900(void *,u8 *);
void func_021D50BC(void *unused, unsigned long base);
void func_021D5214(void *unused, unsigned long base);
void func_021D532C(char *p);
void func_021D5528(void *unused, u8 *p);
void func_021D5598(u8 *p);
void func_021D57D0(u8 *p);
extern const BgTemplate d_021D63E4, d_021D63C4, d_021D63A4, d_021D6384;
extern const BgTemplate d_021D6404, d_021D6344, d_021D64E4, d_021D6504;
extern u8 d_020A1448[];
extern const u8 d_021D65E4[];


void func_021D50BC(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D63E4;
    func_0203FCA0((u8)base, &t0, 0);
    sub_02040588(base, 1);
    sub_020409B4(base);
    id1 = base + 1;
    t1 = d_021D63C4;
    func_0203FCA0((u8)id1, &t1, 0);
    sub_02040588(id1, 1);
    func_02040C14(id1, 0, 1, 0);
    func_02041300(id1, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id1);
    id2 = base + 2;
    t2 = d_021D63A4;
    func_0203FCA0((u8)id2, &t2, 0);
    sub_02040588(id2, 1);
    func_02040C14(id2, 0, 1, 0);
    func_02041300(id2, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id2);
    id3 = base + 3;
    t3 = d_021D6384;
    func_0203FCA0((u8)id3, &t3, 0);
    sub_02040588(id3, 1);
    func_02040C14(id3, 0, 1, 0);
    func_02041300(id3, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id3);
}


void func_021D5214(void *unused, unsigned long base)
{
    BgTemplate t0, t1, t2, t3;
    unsigned long id1, id2, id3;
    t0 = d_021D6404;
    func_0203FCA0((u8)base, &t0, 0);
    sub_02040588(base, 1);
    sub_020409B4(base);
    id1 = base + 1;
    t1 = d_021D6344;
    func_0203FCA0((u8)id1, &t1, 0);
    sub_02040588(id1, 1);
    func_02040C14(id1, 0, 1, 0);
    func_02041300(id1, 0, 0, 0, 32, 32, 17);
    sub_020409B4(id1);
    id2 = base + 2;
    t2 = d_021D64E4;
    func_0203FCA0((u8)id2, &t2, 0);
    sub_02040588(id2, 1);
    sub_020409B4(id2);
    id3 = base + 3;
    t3 = d_021D6504;
    func_0203FCA0((u8)id3, &t3, 0);
    sub_02040588(id3, 1);
    sub_020409B4(id3);
}

/*
 * note 2026-10-05 (wD9r lane S5): twin of ov123 func_021D9D3C (same callees, same loop); offsets differ only.
 */
void func_021D532C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0xc));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0xc));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0xc));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0xc));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0xc));
    heap = *(u16 *)(p + 0xc);
    func_02082BCC(p + 0x10, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x18, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f8, 0x1e0);
    func_020307B0(allocated);
    for (i = 0; i < 15; i++) {
        base1 = (u16 *)(p + 0x1f8);
        base0 = (u16 *)(p + 0x18);
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            for (m = 4; m < 11; m++) {
                func_02021F64(dst + m, base1 + j * 16 + m, 1, (u8)(k >> 8), cur[m + 12]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0(p + 0x1f8, 0x780);
    *(u32 *)(p + 0x14) = 1;
    *(void **)(p + 0x10) = func_020056A0((void *)func_021D5528, p + 0x10, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x97c) = 0;
    func_02049238(h);
}

void func_021D5528(void *unused, u8 *p) {
    if (((struct Obj03251 *)p)->f4 == 0) return;
    ((struct Obj03251 *)p)->f96B ^= 1;
    if (((struct Obj03251 *)p)->f96B & 1) return;
    func_0207E3D0(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    func_0207E468(p + 0x1f0 + ((struct Obj03251 *)p)->f968 * 32, 40, 14);
    ++((struct Obj03251 *)p)->f968;
    if (((struct Obj03251 *)p)->f968 >= 60) ((struct Obj03251 *)p)->f968 = 0;
    func_02040618(((struct Obj03251 *)p)->f96C, 2, 7);
}


/*
 * lever: an enum zero assigned after archive allocation and passed only in full-width outgoing zero slots preserves the independent literal register zeros.
 * checks: fixed one EXACT with all 26 relocations resolved; earlier typed permuter consumed and not repeated.
 * ABI: 49990 fifth argument is explicitly truncated16; B294 result
 *   is consumed by stores and setters despite its legacy void spelling.
 */
void func_021D5598(u8 *p)
{
    enum { Zero=0 } zero;
    u32 res;
    struct Rect a,b;
    res = (u32)sub_020490F4((u32)((void *)143), ((struct Obj00198 *)p)->fC);
    zero=Zero;
    sub_02049B68((void *)((u32)res),0,4,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f0 = sub_02049740((void *)((u32)res),7,4,zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),18,4,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),19,6,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),20,7,0,(u16)(((struct Obj00198 *)p)->f0),zero,0,((struct Obj00198 *)p)->fC);
    sub_02049B68((void *)((u32)res),0,0,zero,0,((struct Obj00198 *)p)->fC);
    ((struct Obj00198 *)p)->f4 = sub_02049740((void *)((u32)res),6,0,zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),15,0,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),16,1,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    func_02049990((void *)((u32)res),17,2,0,(u16)(((struct Obj00198 *)p)->f4),zero,0,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f990 = sub_0204A6C8((void *)((u32)res),9,0,1,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f98C = sub_0204AC18((void *)((u32)res),3,1,0,0,3,((struct Obj00198 *)p)->fC);
    *(int *)&((struct Obj00198 *)p)->f994 = sub_0204AF28((void *)((u32)res),12,25,((struct Obj00198 *)p)->fC);
    sub_02049238((void *)res);
    a.x=128; a.y=96; a.z=10; a.kind=0; a.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f99C = sub_0204B294((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&a,1,((struct Obj00198 *)p)->fC);
    sub_0204B92C(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    sub_0204B3DC(*(struct Obj * *)&((struct Obj00198 *)p)->f99C,1);
    b.x=128; b.y=96; b.z=11; b.kind=1; b.mode=2;
    *(struct Obj * *)&((struct Obj00198 *)p)->f9A0 = sub_0204B294((void *)((struct Obj00198 *)p)->f980,((struct Obj00198 *)p)->f990,((struct Obj00198 *)p)->f98C,((struct Obj00198 *)p)->f994,&b,1,((struct Obj00198 *)p)->fC);
    sub_0204B92C(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    sub_0204B3DC(*(struct Obj * *)&((struct Obj00198 *)p)->f9A0,1);
    func_0207D63C((void *)0x04000050,4,3,6,16);
    func_0207D63C((void *)0x04001050,8,21,6,16);
    ((struct Obj00198 *)p)->f988 = sub_02005624((u32)func_021D58B4,(u32)p,0);
    func_02024230((s16_021D5598 *)(p+0x9ca),192,1456,6144);
    ((struct Obj00198 *)p)->fB4A = 10;
}

void func_021D57D0(u8 *p) { func_0204A48C((const struct Cfg *)d_020A1448,(u32)d_021D65E4,*(u16 *)(p+12)); *(void **)(p+0x980)=func_0204B100(40,0,*(u16 *)(p+12)); *(void **)(p+0x984)=func_020056A0((void *)func_021D5900,p,0); }
