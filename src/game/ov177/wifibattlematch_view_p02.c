/*
 * file:     wifibattlematch_view_p02.c
 * unit:     yes
 * function: func_021E5568, func_021E55C8
 * address:  0x021E5568
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021E8B00 0x021E8B00 data a4
 *   d_021E8B5C 0x021E8B5C data a4
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */
struct BgTemplate;
struct DispConfig;
typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } Entry_021E5568;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 id; u32 template[8]; u32 type; u32 enable; } Entry_021E55C8;

extern void func_02082BCC(void *, unsigned, unsigned);
extern void func_0203F8F4(unsigned short);
extern void func_02045088(unsigned short);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
void func_021E5568(void *p, unsigned short heap);
void func_021E55C8(void *p);
extern const unsigned d_021E8B00[];
extern const Entry_021E5568 d_021E8B5C[];

void func_021E5568(void *p, unsigned short heap)
{
    unsigned i;
    func_02082BCC(p, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const Entry_021E5568 *e = &d_021E8B5C[i];
        unsigned id = e->id;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        func_020414AC(id);
        func_02040588(id, e->enable);
    }
}


void func_021E55C8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021E8B5C[i].id);
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}
