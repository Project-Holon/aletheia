/*
 * function: func_021BBC34
 * address: 0x021BBC34
 * packet: pkt_ov099_021BBC34
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes r0 from empty hook020185F4 and void-declared0204B294; extern returns retain those live results.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 a,b,c; u8 d,e; } Rec;
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *, u32);
extern void *func_020185F4(void *);
extern u32 func_0201BA68(void *);
typedef signed int     s32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *);
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
void func_021BBC34(char *p, void *a, int k, u32 o)
{
    int i,n;
    char *base,*dst;
    void *mon;
    Rec rec;
    n = func_0201AA18(a);
    for (i=0;i<n;i++) {
        base = p + k*4;
        mon = func_020185F4(func_0201AB28(a,i));
        rec.a = i*40+22;
        rec.b = 54;
        rec.c = 0;
        rec.d = 0;
        rec.e = 0;
        dst = base+i*4;
        *(int *)(dst+0x118) = func_0204A6C8((void *)o,func_0201BA68(mon),0,0,0x21);
        *(u32 *)(dst+0x150) = (u32)func_0204B294((void *)*(u32 *)(p+0x110),*(u32 *)(dst+0x118),*(u32 *)(p+0x148),*(u32 *)(p+0x14c),&rec,0,0x21);
        func_0204B6F4(*(void **)(dst+0x150),func_0201BBE8(mon),1);
    }
}
