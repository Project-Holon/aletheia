/*
 * function: func_021BD134
 * address:  0x021BD134
 * packet:   pkt_ov172_021BD134
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *
 * Prints message msgId into the text window at +0x30: clears it, draws the string with the context's font and colour 0x440, frees the string, schedules the window transfer and marks the window shown (+0x24) with no pending wait (+0x38).
 */

typedef unsigned long u32;

extern u32 func_021BE034(void *p);
extern u32 func_021BE03C(void *p);
extern u32 func_021BE044(void *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct U16Vec;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, u32 text, u32 f, u32 color);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_021BE34C(void *p);

void func_021BD134(void *ctx, char *st, u32 msgId)
{
    u32 font = func_021BE034(ctx);
    u32 msgs = func_021BE03C(ctx);
    u32 sys = func_021BE044(ctx);
    u32 str;

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(st + 0x30))), 0xf);
    str = (u32)func_02045EC0((struct MsgBank *)msgs, msgId);
    func_0201C724(sys, (u32)func_02045770((struct Descriptor *)*(u32 *)(st + 0x30)), 0, 0, str, font, 0x440);
    func_02045808((struct U16Vec *)str);
    func_0201F73C((void *)(*(u32 *)(st + 0x30)), 2, 0x140, 9);
    *(u32 *)(st + 0x24) = 1;
    *(u32 *)(st + 0x38) = 0;
    func_021BE34C(ctx);
}
