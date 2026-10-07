/*
 * function: func_02202B20
 * address:  0x02202B20
 * packet:   pkt_02202B20
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02034714  0x02034714  arm
 *
 * Acquire a message buffer from the message bank at +0xc, then take the
 * first of the eight +0x50 occupancy slots that is free: publish the
 * +0x10 word, clear then re-set the +0x14 byte flag, pass the +0x4 owner,
 * the +0x10 handle (through func_02045770), the two signed arguments, the
 * buffer, the +0 handle and 0x3DC8 to func_0201C724, mark the slot used,
 * and release the buffer.  All eight slots busy reports through
 * func_02034714.
 *
 * Second argument is dead (r1 is overwritten by the 0xfe index before any
 * use); the fifth arrives on the stack ([sp+0x30] is what proves arity
 * five).  Both pool words are plain constants, not relocations: 0x3DC8 is
 * the seventh argument to func_0201C724 and 0x02203F74 is the file/message
 * word of the func_02034714 report (the same raw-address assert shape as
 * func_021BA1B4).  The sibling func_022028C8 writes the identical
 * func_0201C724 report with a u16 stack argument instead of 0x3DC8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02202B20.c \
 *       --func func_02202B20 --addr 0x02202B20 --region ov135 \
 *       --thumb --cc 1.1p1 --flags=-O4,p
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct Slot {
    void *f10;
    u8    f14;
    u8    pad[3];
};

struct Obj {
    u32         f00;
    void       *f04;
    u32         f08;
    void       *f0c;
    struct Slot slots[8];
    u32         used[8];
};

#pragma thumb off
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_02034714(const char *expr, u32 line, const char *file);
#pragma thumb on

extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void func_02202B20(struct Obj *p, int arg1, void *arg2, int arg3, int arg4)
{
    void *buf = func_02045EC0(p->f0c, 0xfe);
    int i;

    for (i = 0; i < 8; i++) {
        if (p->used[i] == 0) {
            void *owner;
            void *h;

            p->slots[i].f10 = arg2;
            p->slots[i].f14 = 0;
            owner = p->f04;
            h = func_02045770(p->slots[i].f10);
            func_0201C724(owner, (u32)h, (s16)arg3, (s16)arg4, (u32)buf, p->f00, (int)0x3DC8);
            p->slots[i].f14 = 1;
            p->used[i] = 1;
            func_02045808(buf);
            return;
        }
    }
    func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
}
