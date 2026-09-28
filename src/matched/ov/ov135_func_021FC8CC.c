/*
 * function: func_021FC8CC
 * address:  0x021FC8CC
 * packet:   pkt_021FC8CC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02017E88  0x02017E88  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02202670  0x02202670  thumb
 *   func_02020F84  0x02020F84  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021FC8A8  0x021FC8A8  thumb
 *   func_02045808  0x02045808  arm
 *   tbl_02202EB0   0x02202EB0  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    s16 name;
    s8 mode;
    s8 key;
    s8 val;
} Rec;

extern const u32 tbl_02202EB0[];

extern void *func_020457B0(u32 size, u32 heap);
extern u32 func_02017E88(void *mon, u32 id, void *v);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201EFA4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *func_02202670(void *words, void *msg, u32 id, u32 heap);
extern void func_02020F84(void *dst, u32 entry, u32 heap);
extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, u32 color);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 func_021FC8A8(int mode);
extern void func_02045808(void *p);

void func_021FC8CC(void *bank, void *names, void *words, void **win, void *mon, Rec *rec, void *g)
{
    u32 lv;
    void *sname;
    void *smode;
    void *s70;
    void *s71;
    void *s4f;
    void *s41;
    void *nick;
    void *ot;
    int mode;
    int name;
    u32 flag;
    int key;
    int i;

    nick = func_020457B0(0x1a, 0x48);
    ot = func_020457B0(0x26, 0x48);
    func_02017E88(mon, 0x73, nick);
    name = rec->name;
    mode = rec->mode;
    key = rec->key;
    lv = func_02017E88(mon, 6, 0);
    flag = func_02017E88(mon, 0xAD, 0);
    s4f = func_02045EC0(bank, 0x4F);
    smode = func_02045EC0(bank, tbl_02202EB0[mode]);
    s70 = func_02045EC0(bank, 0x70);
    func_0201EFA4(words, 3, key, 3, 0, 1);
    s71 = func_02202670(words, bank, 0x71, 0x48);
    sname = func_02045EC0(names, name);
    func_02020F84(ot, (u16)lv, 0x48);
    s41 = func_02045EC0(bank, 0x41);
    for (i = 0; i < 6; i++) {
        func_02043B5C(func_02045770(win[i]), 0);
    }
    func_021F91A0(win[0], nick, 0, 0, 0, 0x440, g);
    if (mode != 3 && flag != 0) {
        func_021F91A0(win[0], smode, 0x40, 0, 0, func_021FC8A8(mode), g);
    }
    func_021F91A0(win[1], sname, 1, 0, 0, 0x440, g);
    func_021F91A0(win[2], s70, 0, 0, 0, 0x440, g);
    func_021F91A0(win[3], s71, 0, 0, 0, 0x440, g);
    func_021F91A0(win[4], s4f, 0, 0, 0, 0x3C40, g);
    func_021F91A0(win[5], ot, 1, 0, 0, 0x440, g);
    func_021F91A0(win[6], s41, 0, 0, 0, 0x3C40, g);
    func_02045808(s4f);
    func_02045808(ot);
    func_02045808(s70);
    func_02045808(s71);
    func_02045808(smode);
    func_02045808(nick);
    func_02045808(sname);
    func_02045808(s41);
}
