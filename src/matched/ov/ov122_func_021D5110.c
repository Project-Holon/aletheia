/*
 * function: func_021D5110
 * address: 0x021D5110
 * packet: pkt_ov122_021D5110
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CF10 0x0203CF10 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045994 0x02045994 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 *   func_0204B898 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021D50B4 0x021D50B4 thumb ov122
 *   func_021D50DC 0x021D50DC thumb ov122
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_0201283C(const void *);
extern int func_020107FC(void *);
extern void *func_0203CF10(u32);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Obj;
struct SoundSys;
struct Strbuf;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 *func_0202E930(void *);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u32 func_0204B3F4(struct Obj *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7D0(void *, s16, s16, void *, void *, u16);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02041B6C(u32 bit);
extern void func_021D50B4(char *p, u32 n);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02012A30(const void *);
extern void func_02028A64(struct SoundSys *sys);
extern void func_02028A70(struct SoundSys *sys);
extern u16 func_0204B898(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021D50DC(char *);
void func_021D5110(char *p)
{
    int index;
    void *record, *text;
    index = func_020107FC(func_0201283C(*(void **)(p + 0x350)));
    if (index != -1) {
        record = func_0203CF10(index);
        text = func_020457B0(200, *(u16 *)(p + 0xc));
        func_02045994(text, func_0202E930(record), 8);
        if (!func_0204B3F4(*(void **)(p + 0x3a0))) {
            func_02045994(*(void **)(p + 0x58), func_0202E930(record), 8);
            func_02043B5C(func_02045770(*(void **)(p + 0x3c)), 0);
            func_0201C7D0(func_02045770(*(void **)(p + 0x3c)), 0, 0, *(void **)(p + 0x58), *(void **)(p + 0x4c), 0x39e3);
            func_02045334(*(void **)(p + 0x3c));
            func_02045374(*(void **)(p + 0x3c));
            func_0204B3DC(*(void **)(p + 0x3a0), 1);
            func_02041B6C(5);
            func_021D50B4(p, index);
        }
        func_02045808(text);
        func_02028A64(func_02012A30(*(void **)(p + 0x350)));
        if (func_0204B898(*(void **)(p + 0x39c)) == 15)
            func_0204B878(*(void **)(p + 0x39c), 16);
        if (func_0204B898(*(void **)(p + 0x394)) == 11) {
            func_0204B92C(*(void **)(p + 0x394), 1);
            func_0204B878(*(void **)(p + 0x394), 19);
        }
    } else {
        func_02028A70(func_02012A30(*(void **)(p + 0x350)));
        func_0204B3DC(*(void **)(p + 0x3a0), 0);
        func_02043B5C(func_02045770(*(void **)(p + 0x3c)), 0);
        func_02045334(*(void **)(p + 0x3c));
        func_021D50DC(p);
        if (func_0204B898(*(void **)(p + 0x394)) == 19) {
            func_0204B92C(*(void **)(p + 0x394), 0);
            func_0204B878(*(void **)(p + 0x394), 11);
        }
        if (func_0204B898(*(void **)(p + 0x39c)) == 16)
            func_0204B878(*(void **)(p + 0x39c), 15);
    }
}
