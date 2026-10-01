/*
 * unit: yes
 * function: func_021BB450, func_021BB4D8, func_021BB4E8, func_021BB4F8
 * address: 0x021BB450
 * packet: pkt_ov223_021BB450
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027858 0x02027858 thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 * Lead EXACT* ends at BB4D8; three 16-byte load/tail-call followers
 * complete the extent. Parent cleared these starts. The value local
 * assigns zero then conditionally one; a boolean expression reverses
 * the compare polarity. Template precedes items in declaration order.
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
struct U16Vec;
struct TaskMenu;
typedef struct Obj Obj;
struct Item { void *text; u16 color; unsigned value; };
struct TaskMenuTmpl {
    unsigned heapId;
    u8 count;
    u8 pad05[3];
    const void *unk08;
    unsigned unk0c;
    u8 pad10[2];
    u8 unk12;
    u8 unk13;
};
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *, void *);
extern void func_02045808(struct U16Vec *);
extern void func_02027858(struct TaskMenu *);
extern void func_02027974(Obj *);
extern unsigned func_020279E8(struct TaskMenu *);
void func_021BB450(char *p)
{
    struct TaskMenuTmpl tmpl;
    struct Item items[2];
    unsigned i;
    for (i = 0; i < 2; i++) {
        unsigned value;
        items[i].text = func_02045EC0(*(struct MsgBank **)(p + 0x234), i + 22);
        items[i].color = 0x39E3;
        value = 0;
        if (i != 0)
            value = 1;
        items[i].value = value;
    }
    tmpl.heapId = *(u16 *)p;
    tmpl.count = 2;
    tmpl.unk0c = 1;
    tmpl.pad10[0] = 32;
    tmpl.pad10[1] = 17;
    tmpl.unk12 = 9;
    tmpl.unk13 = 3;
    tmpl.unk08 = items;
    *(struct TaskMenu **)(p + 0x264) = func_02027778(&tmpl, *(void **)(p + 0x25C));
    for (i = 0; i < 2; i++)
        func_02045808(items[i].text);
}
void func_021BB4D8(char *p)
{
    func_02027858(*(struct TaskMenu **)(p + 0x264));
}
void func_021BB4E8(char *p)
{
    func_02027974(*(Obj **)(p + 0x264));
}
unsigned func_021BB4F8(char *p)
{
    return func_020279E8(*(struct TaskMenu **)(p + 0x264));
}
