/*
 * file:     un_select_p03.c
 * unit:     yes
 * function: func_021B9944, func_021B9964
 * address:  0x021B9944
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02023F98 0x02023F98 thumb
 *   func_02023EF4 0x02023EF4 thumb
 *   d_021BB088 0x021BB088 data ov218 a4
 *   func_02030734 0x02030734 arm
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0203101C 0x0203101C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

extern void func_02023F98(u32);
extern void func_02023EF4(void *,u16,s16,s16,u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern void func_0201F5BC(u32,u32,u32,u32,u16);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
void func_021B9944(void);
void *func_021B9964(u16 heap);
extern char d_021BB088[];

void func_021B9944(void)
{
    func_02023F98(1);
    func_02023EF4((void *)8,0,-8,60,1);
}

void *func_021B9964(u16 heap)
{
    char *p;
    void *window;
    p=func_02030734(heap,0x234,1,d_021BB088,0x3cc);
    *(u16 *)p=heap;
    func_02049B40(23,5,0,0x1c0,32,heap);
    func_0201F5BC(0,1,15,0,heap);
    *(void **)(p+0x14)=func_0201EC64(heap);
    *(void **)(p+8)=func_02045B38(0,2,229,heap);
    *(void **)(p+0x10)=(void *)func_0201C440((void *)heap);
    *(void **)(p+0xc)=func_0201D7EC(23,0,0,0,heap);
    *(void **)(p+0x18)=func_020457B0(1600,heap);
    *(void **)(p+0x1c)=func_020457B0(1600,heap);
    *(void **)(p+4)=func_0203101C(heap,heap,1,0);
    *(void **)(p+0x24)=(void *)func_020450F0(0,1,19,30,4,14,1);
    window=*(void **)(p+0x28)=(void *)func_020450F0(4,1,1,30,2,6,1);
    func_02043B5C(func_02045770(window),15);
    func_0201DD78(1,2,15);
    func_02045CAC(*(void **)(p+8),233,*(void **)(p+0x18));
    func_0201C7A4(func_02045770(window),4,0,*(void **)(p+0x18),*(void **)(p+0xc));
    func_02045334(window);
    func_02045374(window);
    func_02041B6C(func_02045730(window));
    return p;
}
