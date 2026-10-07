/*
 * function: func_021F8358
 * address:  0x021F8358
 * packet:   pkt_021F8358
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   tbl_02202EB0  0x02202EB0  data  a4
 *   func_02202670  0x02202670  thumb
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021F7F80  0x021F7F80  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u16 species;
    u8 form;
    u8 gender;
} MonTag;

extern const u32 tbl_02202EB0[];

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02018438(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern int func_021F91A0(void *win, void *str, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 func_021F7F80(int mode);
extern void func_02045808(struct U16Vec *vec);

void func_021F8358(void *bank, void *ws, void **win, void *mon, MonTag *out, void *g)
{
    int i;
    int form;
    void *title;
    void *place;
    void *name;
    void *tmp;
    u32 has;
    u32 gender;

    name = func_020457B0(0xB, 0x48);
    tmp = func_020457B0(0xB, 0x48);
    func_02017E88(mon, 0x73, (u32)name);
    form = func_02017E88(mon, 0x6E, 0) + 1;
    gender = func_02018438(mon);
    has = func_02017E88(mon, 0xAD, 0);
    title = func_02045EC0(bank, 0x6E);
    func_0201EFA4(ws, 3, gender, 3, 0, 1);
    place = (void *)func_02202670((u32)ws, (u32)bank, 0x72, 0x48);
    if (form != 3) {
        func_02045CAC(bank, tbl_02202EB0[form], tmp);
    }
    for (i = 0; i < 3; i++) {
        func_02043B5C(func_02045770(win[i]), 0);
    }
    func_021F91A0(win[0], title, 1, 0, 0, 0x3C40, g);
    func_021F91A0(win[1], name, 0, 0, 0, 0x3C40, g);
    func_021F91A0(win[2], place, 0, 0, 2, 0x3C40, g);
    if (form != 3 && has != 0) {
        func_021F91A0(win[1], tmp, 0x46, 0, 0, func_021F7F80(form - 1), g);
    }
    out->species = func_02017E88(mon, 5, 0);
    out->form = form;
    out->gender = gender;
    func_02045808(place);
    func_02045808(tmp);
    func_02045808(name);
    func_02045808(title);
}
