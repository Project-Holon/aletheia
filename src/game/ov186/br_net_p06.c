/*
 * file:     br_net_p06.c
 * unit:     yes
 * function: func_021FFF1C, func_021FFF28, func_021FFFCC, func_021FFFF8, func_022000D0, func_022000F0, func_0220014C, func_02200188
 * address:  0x021FFF1C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_0201F81C 0x0201F81C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F898 0x0201F898 thumb
 *   func_02045808 0x02045808 arm
 *   func_021FC8C8 0x021FC8C8 thumb ov186
 *   d_02200DAC 0x02200DAC data
 *   d_020A7370 0x020A7370 data
 *   d_02200CA8 0x02200CA8 data
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_02035C08 0x02035C08 arm
 *   func_02035D20 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   d_02200CD0 0x02200CD0 data a1
 *   func_0200D064 0x0200D064 thumb
 *   d_02200C94 0x02200C94 data a4
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02200D9C 0x02200D9C data a1
 */
#include "../../matched/include/Obj24877.h"
#include "../../matched/include/Obj14487.h"
#include "../../matched/include/Obj24878.h"
#include "../../matched/include/Obj06639.h"
#include "../../matched/include/Obj24879.h"

struct Slot;
struct MsgBank;
struct U16Vec;
struct Blk37;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct Work { char pad0[0x14]; unsigned char flags[9]; char pad1[7]; unsigned short heap; unsigned short pad2; char *owner; char pad3[0x10]; void *resource; char *slots[9]; char pad4[0xc]; int state; } Work;

typedef unsigned short u16;

typedef struct { const void *str; u32 param; } Slot;

typedef struct { u32 v[10]; } Config;

extern void func_021FB494(char *p);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *, void *, void *, void *, unsigned short);
extern void func_021FC734(u8 *p);
extern void func_020409B4(u32 index);
extern void func_021FBDA4(int,unsigned);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern Slot *func_0201F81C(u32,u32);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F898(struct Slot *table, u32 a, u32 b, u32 tag);
extern void func_02045808(struct U16Vec *vec);
extern void *func_021FC8C8(Config *,u32);
extern void func_021FCC80(char *);
extern u32 func_0201F868(void *p);
extern int func_02035C08(const void *);
extern unsigned int func_02035D20(unsigned int *outA, unsigned int *outB);
extern void func_021FD860(int, int, int *);
extern void func_020061E4(u32 a);
extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(void *, u8, u32);
void func_021FFF1C(char *p);
void func_021FFF28(Work *p);
void func_021FFFCC(u8 *p);
void func_021FFFF8(char *p);
void func_022000D0(u8 *p);
int func_022000F0(char *p);
int func_0220014C(void *p,u32 n,const u16 *ids);
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap);
extern char d_02200DAC[];
extern void *d_020A7370;
extern const Config d_02200CA8;
extern const char d_02200CD0[];
extern const u16 d_02200C94[];
extern const char d_02200D9C[];

void func_021FFF1C(char *p) {func_021FB494(((struct Obj24877 *)p)->f2C);}

void func_021FFF28(Work *p)
{
    int a, b, i;
    unsigned color;
    unsigned char x, y;
    p->state = 0;
    func_021FB964((void *)((int)p->owner), 20, p->heap);
    a = func_021FC20C(p->owner);
    b = func_021FC214(p->owner);
    for (i = 0; i < 9; i++) {
        x = (i % 5) * 6 + 2;
        y = 6;
        if (i < 5) y = 0;
        p->slots[i] = func_021FC6A4(4, (unsigned char)x, (unsigned char)(y + 4), (unsigned)4, 2, 14, p->resource, p->heap);
        color = 0x3da0;
        if (!p->flags[i]) color = 0x2da0;
        func_021FC868((u8 *)p->slots[i], (int)0, (int)0, (int)1);
        func_021FC754(p->slots[i], (void *)b, (void *)(i + 0x3a), (void *)a, color);
    }
}

void func_021FFFCC(u8 *p) { int i; for(i=0;i<9;i++) { u8 *q=p+(u32)i*4; func_021FC734(((struct Obj14487 *)q)->f40); *(u32 *)&((struct Obj14487 *)q)->f40=0; } func_020409B4(4); func_021FBDA4(((struct Obj24878 *)p)->f28,20); }

/*
 *   021FFFF8..022000D0. Singleton tu --suggest-split confirms no viable cut.
 *   Existing Ilias-owned unit_02045C44.c function verified EXACT344 with
 *   read-only fixed-flag one (ARM9-45CAC.log). No ARM9 file/shard writes.
 *   Its function: header lists only func_02045C44, omitting func_02045CAC.
 *   Verified C follows, using that unit's declarations:
 *   void func_02045CAC(struct MsgBank *bank, u32 index, void *dest) {
 *     u32 size; struct MsgEntry *e;
 *     if (index >= bank->file->count) { func_0204581C(dest); return; }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *       u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *       func_0204960C(bank->stream, pos + (index * 8 + 4));
 *       func_020495F4(bank->stream, 8, &bank->cache); e = &bank->cache;
 *     } else { e = (struct MsgEntry *)((u8 *)bank->base + 4) + index; }
 *     if (bank->resident == 0) {
 *       void *buf; size = e->len * 2;
 *       buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),
 *                         size, 0, g_020A7E8C, 0xd6);
 *       if (buf != 0) {
 *         func_0204960C(bank->stream, e->off + (bank->origin
 *                       + bank->file->langOff[bank->langIndex]));
 *         func_020495F4(bank->stream, size, buf);
 *         func_02045A00(dest, buf, e->len); func_020307B0(buf);
 *       }
 *     } else { func_02045A00(dest, (u8 *)bank->base + e->off, e->len); }
 *     func_02045E04(dest, index);
 *   }
 */
void func_021FFFF8(char *p)
{
    Config cfg;
    void *str;
    u32 i;
    *(u32 *)(p+0x70)=1;
    func_021FB964((void *)(*(int *)(p+0x28)),21,*(u16 *)(p+0x24));
    if (*(void **)(p+0x64)) func_02034714(d_02200DAC,0,d_02200DAC);
    if (*(void **)(p+0x68)) func_02034714(d_02200DAC,0,d_02200DAC);
    *(Slot **)(p+0x64)=func_0201F81C(*(u32 *)(p+0x8c),*(u16 *)(p+0x24));
    str=func_020457B0(11,*(u16 *)(p+0x24));
    for(i=0;i<*(u32 *)(p+0x8c);i++) {
        func_02045CAC(d_020A7370,(*(u16 **)(p+0x88))[i],str);
        func_0201F898((struct Slot *)(*(Slot **)(p+0x64)+i),(u32)str,(*(u16 **)(p+0x88))[i],*(u16 *)(p+0x24));
    }
    func_02045808(str);
    cfg=d_02200CA8;
    cfg.v[0]=*(u32 *)(p+0x64);
    cfg.v[1]=*(u32 *)(p+0x8c);
    cfg.v[5]=*(u32 *)(p+0x28);
    cfg.v[6]=*(u32 *)(p+0x34);
    cfg.v[7]=*(u32 *)(p+0x74);
    cfg.v[8]=*(u32 *)(p+0x78);
    *(void **)(p+0x68)=func_021FC8C8(&cfg,*(u16 *)(p+0x24));
}

void func_022000D0(u8 *p) { func_021FCC80(*(char * *)&((struct Obj06639 *)p)->f68); *(u32 *)&((struct Obj06639 *)p)->f68=0; func_0201F868(((struct Obj06639 *)p)->f64); *(u32 *)&((struct Obj06639 *)p)->f64=0; func_021FBDA4(((struct Obj06639 *)p)->f28,21); }

int func_022000F0(char *p)
{
    int x, y, args[2];
    int index = func_02035C08(d_02200CD0);
    if (index != -1) {
        if (*(unsigned char *)(p + index + 0x14)) {
            func_02035D20((unsigned int *)(&x), (unsigned int *)(&y));
            args[0] = x;
            args[1] = y;
            func_021FD860(((struct Obj24879 *)p)->f78, 1, args);
            func_020061E4(0x703);
            return index;
        }
        func_020061E4(0x704);
    }
    return 9;
}

/*
 * lever: unsigned table indices preserve load scheduling; raw address casts differ by 12 bytes.
 */
int func_0220014C(void *p,u32 n,const u16 *ids) { u32 i; u32 end; int found; end=d_02200C94[n+1];found=0;for(i=d_02200C94[n];i<end;i++) { if(func_0200D064(p,*(const u16 *)((u32)ids+i*2)))found=1; }return found; }

/*
 * lever: loop-2 store written as two statements (dst[filled] = ...; filled++;) with braced
 *   loop and if bodies; the one-line dst[filled++] form left a 3-register rotation (18 B).
 */
u16 *func_02200188(void *p, u32 index, const u16 *table, u32 *out, u16 heap)
{
    u32 end, start;
    u16 *dst;
    int filled;
    int count, bytes;
    end = d_02200C94[index + 1];
    count = 0;
    start = d_02200C94[index];
    for (filled = start; filled < end; filled++) {
        if (func_0200D064(p, table[filled])) {
            count++;
        }
    }
    bytes = count * 2;
    dst = func_02030734(heap, bytes, 0, d_02200D9C, 0x3c3);
    filled = 0;
    func_02082BCC(dst, 0, bytes);
    for (; start < end; start++) {
        if (func_0200D064(p, table[start])) {
            dst[filled] = table[start];
            filled++;
        }
    }
    if (out) *out = filled;
    return dst;
}
