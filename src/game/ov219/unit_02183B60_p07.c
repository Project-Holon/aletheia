/*
 * file:     unit_02183B60_p07.c
 * unit:     yes
 * function: func_0218516C, func_0218519C, func_02185254, func_02185310, func_0218532C, func_0218544C
 * address:  0x0218516C
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F7A8 0x0201F7A8 thumb
 *   sub_020452E8 0x020452E8 arm
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02184968 0x02184968 thumb ov219
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02184D30 0x02184D30 thumb ov219
 *   func_02045808 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   d_02185DCB 0x02185DCB data ov219 a1
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045730 0x02045730 arm
 *   func_02185C84 0x02185C84 thumb ov219
 *   func_020452E8  0x020452E8  arm
 *   func_02185D08  0x02185D08  thumb  ov219
 *   func_02185D64  0x02185D64  thumb  ov219
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 */
#include "../../matched/include/Obj08451.h"
#include "../../matched/include/Obj01984.h"
#include "../../matched/include/Obj02934.h"
#include "../../matched/include/Obj14780.h"

struct Descriptor;
struct Obj;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct Cfg;
struct Record;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Record {struct Descriptor *descriptor;u8 active;};

typedef short s16;

extern void func_0201F7A8(void*,u32);
extern u32 sub_020452E8(struct Descriptor *d);
extern void func_0202020C(struct Obj*,u16*,u16*);
extern u32 func_0201F868(void *p);
extern struct U16Vec *func_020457B0(unsigned int capacity, unsigned int heapId);
extern u32 func_02184968(const u8 *p, int flag);
extern void func_0201F048(struct WordSet *,unsigned,unsigned),func_0201F094(struct WordSet *,unsigned,unsigned,unsigned);
extern void func_02045CAC(struct MsgBank *,unsigned,void *),func_0201F250(struct WordSet *,void *,void *);
extern void func_02184D30(char *,struct Record *,struct Descriptor *,void *,u8,u8);
extern void func_02045808(struct U16Vec *),func_0201F73C(void *,int,int,int),func_02045334(struct Descriptor *);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
extern u8 func_02045730(struct Descriptor *p);
extern int func_02185C84(unsigned,unsigned,void *,void *,unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02185D08(int *p);
extern int func_02185D64(int *p, int *q);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_02045CAC(struct MsgBank *,u32,void *);
void func_0218516C(u8*p);
void func_0218519C(char *p);
void func_02185254(char *p,unsigned key,unsigned member);
void func_02185310(char *p);
int func_0218532C(char *p, u32 *out);
void func_0218544C(char *p);
extern const unsigned char d_02185DCB[];

void func_0218516C(u8*p){func_0201F7A8(*(void* *)&((struct Obj08451 *)p)->fC018,0);sub_020452E8(*(struct Descriptor* *)&((struct Obj08451 *)p)->fC018);func_0202020C(*(struct Obj* *)&((struct Obj08451 *)p)->fC04C,0,0);func_0201F868(*(void* *)&((struct Obj08451 *)p)->fC050);}

/*
 * prototype: 457B0 heap input is explicitly narrowed to u16 in original;
 * retain all observed narrow inputs to matching4D30 stack-byte interface.
 */
void func_0218519C(char *p)
{
    struct U16Vec *dst,*src;
    dst=func_020457B0(1024,(u16)(((struct Obj01984 *)p)->f0));src=func_020457B0(1024,(u16)(((struct Obj01984 *)p)->f0));
    *(struct Descriptor * *)&((struct Obj01984 *)p)->fC040=(struct Descriptor *)func_02184968(d_02185DCB,1);
    func_0201F048(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,0,((struct Obj01984 *)p)->fC33C);
    func_0201F094(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,1,((struct Obj01984 *)p)->fC33C,((struct Obj01984 *)p)->fC340);
    func_02045CAC(*(struct MsgBank * *)&((struct Obj01984 *)p)->fC070,14,src);
    func_0201F250(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,dst,src);
    func_02184D30(p,(struct Record *)(p+0xc044),*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040,dst,0,0);
    func_02045808(src);func_02045808(dst);
    func_0201F73C(((struct Obj01984 *)p)->fC040,0,34,7);
    func_02045334(*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040);
}

/*
 * prototype: original truncates heap before 020457B0, and stack bytes before 02184D30; extern narrow widths preserve those visible operations.
 */
void func_02185254(char *p,unsigned key,unsigned member)
{
    void *first,*second,*object;
    first=func_020457B0(64,(u16)(((struct Obj02934 *)p)->f0));
    second=func_020457B0(64,(u16)(((struct Obj02934 *)p)->f0));
    ((struct Obj02934 *)p)->fC040=(void *)func_02184968(d_02185DCB,1);
    func_02185C84(key,member,first,second,((struct Obj02934 *)p)->f0);
    if(member!=0) func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,second,0,16);
    func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,first,0,0);
    func_02045808(second);
    func_02045808(first);
    func_0201F73C(((struct Obj02934 *)p)->fC040,0,34,7);
    object=((struct Obj02934 *)p)->fC040;
    func_02045334(object);
    func_02045374(object);
    func_02041B6C(func_02045730(object));
}


/*
 * Addresses are Black-image addresses.
 */
void func_02185310(char *p)
{
    char *q = p + 0xc040;
    func_0201F7A8((void *)(((struct Obj14780 *)q)->f0), 0);
    func_020452E8((struct Descriptor *)(((struct Obj14780 *)q)->f0));
}


/*
 * 2026-10-05 (wD9 lane12): EXACT. The wrap value was a ternary local t merged at a join and stored
 *   to ylo and yhi after it. Writing the stores in each arm (`if (lo2 > 0) yhi = ylo = lo2 - 0x10000;
 *   else yhi = ylo = lo2 + 0x10000;`) gives lo2 r6 and spills yhi, as in the image (tail merging
 *   rebuilds the shared two-store join). See docs/idioms/two-long-lived-values-in-each-others-registers.md.
 * 2026-10-05 (wD8 lane10): still DIFF 91 bytes. Re-read the listing: semantics match (ylo [sp,#0x10], yhi
 *   [sp,#0xc], hi2 [sp,#8], lo2 r6; wrap order lo2-=, hi2+=, ylo-=, yhi+=). No new test closed the r6 swap.
 * 2026-10-05 (wD7 lane14): still DIFF 91 bytes. Re-derived the middle part: no logic error found. Tried: ylo = ternary; yhi = ylo
 *   (no t local, same 91); ylo/yhi as a two-element local array (mwcc scalarises it, 98).
 * 2026-10-05 (wD6 lane16): still DIFF 91 bytes. Tried: else arm as lo2 = ylo; hi2 = yhi (order swap) and the abs test
 *   as a ternary inside the if: no change. Callee 02185D08 reads only r0 (no missing argument).
 * 2026-10-05 (wD5 lane05): DIFF 91 bytes (was 163). Fixes: no e record pointer local (each
 *   field read as *(T *)(p + i * 0x30 + K), loop colours now exact); no cx/cy locals; every use reads
 *   *(int *)(p + 0xC2F4/0xC2F8) directly (CSE gives the original load order; prologue now exact up to
 *   +0x3A). Residue: yhi takes r6 and lo2 is spilled to [sp,#0xc]; the original has lo2 in r6 and yhi
 *   in [sp,#0xc] (a pure swap of the two, all else follows). No change from: lo2 assigned directly
 *   (no y16 temp), declaring lo2 last or before yhi, `yhi = ylo = t`, the ternary as an if/else on
 *   ylo, a struct Ent array for the 0x30 records (worse, hoists p+0x18). lo2/hi2 set before the if
 *   (no else) does give lo2 r6 but loses the else block (257).
 * 2026-10-05 (wD4 lane19): still DIFF 163 bytes. Tried the constant in a local (int off = 0xC2F4; p[off], p[off+4], and for the reload): mwcc folds it, no change.
 * 2026-10-04 (wD2 lane 09): 284 vs 288 bytes, 163 bytes differ, same frame.
 * Semantics read from the listing (x,y at +0xC2F4/+0xC2F8, count at +0x14,
 * 0x30-byte records, s16 fields +0x18/+0x1a, u16 flag +0x40). Residue: the
 * original keeps only lo2 (r6) in a register and spills ylo/yhi/hi2; ours puts
 * yhi in r6, so the wrap test and the range test swap order, and the loop
 * colours ex/ey/e as r1/r2/r0 instead of r0/r1/r2. Tried: lo2/hi2 set through
 * y16 before the temp (89->163 bytes better than the first draft), declaring
 * lo2/hi2 first (169, worse). Not tried: wrap test through different locals.
 */
int func_0218532C(char *p, u32 *out)
{
    int ret = 0;
    int xlo, xhi, ylo, yhi, lo2, hi2;
    u32 i;
    u32 best;
    u32 bestd;
    int cur[2];

    xlo = (s16)(*(int *)(p + 0xC2F4) - 0x80);
    xhi = (s16)(*(int *)(p + 0xC2F4) + 0x80);
    ylo = (s16)(*(int *)(p + 0xC2F8) - 0x80);
    yhi = (s16)(*(int *)(p + 0xC2F8) + 0x80);
    best = *(u32 *)(p + 0x14);
    bestd = 0x100;
    cur[0] = *(int *)(p + 0xC2F4);
    cur[1] = *(int *)(p + 0xC2F8);
    func_02185D08(cur);
    {
        int d = yhi - ylo;
        if (d < 0) d = -d;
        if (d > 0x100) {
            lo2 = (s16)*(int *)(p + 0xC2F8);
            hi2 = lo2;
            if (lo2 > 0)
                yhi = ylo = lo2 - 0x10000;
            else
                yhi = ylo = lo2 + 0x10000;
            lo2 -= 0x80;
            hi2 += 0x80;
            ylo -= 0x80;
            yhi += 0x80;
        } else {
            hi2 = yhi;
            lo2 = ylo;
        }
    }
    for (i = 0; i < *(u32 *)(p + 0x14); i++) {
        int ex = *(s16 *)(p + i * 0x30 + 0x18);
        if (ex > xlo && ex < xhi) {
            int ey = *(s16 *)(p + i * 0x30 + 0x1a);
            if ((ey > ylo && ey < yhi) || (ey > lo2 && ey < hi2)) {
                if (*(u16 *)(p + i * 0x30 + 0x40) != 0) {
                    int pt[2];
                    u32 dd;
                    pt[0] = ex;
                    pt[1] = *(s16 *)(p + i * 0x30 + 0x1a);
                    func_02185D08(pt);
                    dd = func_02185D64(cur, pt);
                    if (dd < bestd) {
                        bestd = dd;
                        best = i;
                    }
                }
            }
        }
    }
    *out = best;
    if (best != *(u32 *)(p + 0x14))
        ret = 1;
    return ret;
}

/*
 * lever: distinct outer buffer and block-scoped first/second buffers settle the eight-byte r4/r6 swap.
 * blocker-C: 02045CAC verified EXACT, 344B, scratch arm9-blocker.log;
 * copied unchanged from unit_02045C44.c, using dsi/1.1p1 -O4,p --arm.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void func_020495F4(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void func_0204581C(void *);
 * extern void func_02045A00(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         func_020495F4(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,g_020A7E8C,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream,size,buf);
 *             func_02045A00(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 *
 * prototype: caller narrows allocation heap to u16 immediately before each call.
 */
void func_0218544C(char *p)
{
    struct U16Vec *buffer;
    u32 selected;
    if(*(u32 *)(p+0xC350)==0) {
        buffer=func_020457B0(1024,(u16)(*(u32 *)p));
        func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
        func_02045CAC(*(struct MsgBank **)(p+0xC070),15,buffer);
        func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),buffer,0,0);
        func_02045808(buffer);
    } else {
        struct U16Vec *first,*second;
        if(func_0218532C(p,&selected)) {
            first=func_020457B0(64,(u16)(*(u32 *)p));
            second=func_020457B0(64,(u16)(*(u32 *)p));
            func_02043B5C(func_02045770(*(struct Descriptor **)(p+0xC01C)),15);
            func_02185C84(*(u16 *)(p+selected*48+66),*(u16 *)(p+selected*48+68),first,second,*(u32 *)p);
            if(*(u16 *)(p+selected*48+68)!=0)
                func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),second,0,16);
            func_02184D30(p,(struct Record *)(p+0xC020),*(struct Descriptor **)(p+0xC01C),first,0,0);
            func_02045808(second);
            func_02045808(first);
            *(int *)(p+0xC2F4)=*(s16 *)(p+selected*48+24);
            *(int *)(p+0xC2F8)=*(s16 *)(p+selected*48+26);
        } else *(u32 *)(p+0xC350)=0;
    }
    func_02045334(*(struct Descriptor **)(p+0xC01C));
}
