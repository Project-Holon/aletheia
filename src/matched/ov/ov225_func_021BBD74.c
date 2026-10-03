/*
 * function: func_021BBD74
 * address:  0x021BBD74
 * packet:   pkt_021BBD74
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a graphics record: releases the p+0x24 handle, sizes the p+0x18
 * resource through func_02045770, resolves a slot word, and submits a
 * seven-argument call before marking p+0x30 and repointing the slot.
 *
 * symbols:
 *   func_0201C6EC    0x0201C6EC  thumb
 *   func_02045770    0x02045770  arm
 *   func_02043B5C    0x02043B5C  arm
 *   func_02045EC0    0x02045EC0  arm
 *   func_0201C724    0x0201C724  thumb
 *   func_02045808    0x02045808  arm
 *   func_021BBD28    0x021BBD28  thumb  ov225
 *   func_021B9E80    0x021B9E80  thumb  ov225
 */

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *p, void *q, int a, int b, void *c, int d, int e);
extern void func_02045808(struct U16Vec *vec);
extern void func_021BBD28(char *p);
extern void func_021B9E80(char *p, unsigned id);

void func_021BBD74(char *p)
{
    void *r;

    func_0201C6EC(*(void **)(p + 0x24));
    func_02043B5C(func_02045770(*(void **)(p + 0x18)), 0);
    r = func_02045EC0(*(void **)(*(char **)(p + 4) + 0x20),
                      *(u16 *)(*(char **)p + (*(unsigned char *)(p + 8) << 2) + 6));
    func_0201C724(*(void **)(p + 0x24), func_02045770(*(void **)(p + 0x18)),
                  4, 6, r, *(int *)(*(char **)(p + 4) + 0xc), 0x440);
    func_02045808(r);
    *(int *)(p + 0x30) = 1;
    func_021BBD28(p);
    func_021B9E80(*(void **)(p + 4),
                  *(u16 *)(*(char **)p + (*(unsigned char *)(p + 8) << 2) + 4));
}
