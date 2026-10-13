/*
 * function: func_0220D418
 * address: 0x0220D418
 * packet: pkt_ov198_0220D418
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: the switch has no default; a selector outside 0..2 branches from
 *   0220D42C straight to the print tail with r7 (t) never assigned, as the
 *   image does. The earlier `default: return;` spelling was a guard the
 *   original lacks.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
struct U16Vec;
struct Descriptor;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_0220D418(char *p, int i, int selector)
{
    struct U16Vec *t;
    void *f;
    switch (selector) {
    case 0: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x41); break;
    case 1: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x40); break;
    case 2: t = func_02045EC0(*(struct MsgBank **)(p + 0x1EA0), 0x42); break;
    }
    f = *(void **)(p + 0x1EAC);
    PRINTSYS_PrintQueColor(f, (u32)func_02045770(*(struct Descriptor **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    STRBUF_Delete(t);
}
