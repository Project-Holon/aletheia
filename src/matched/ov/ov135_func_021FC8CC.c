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
 *   STRBUF_Create  0x020457B0  arm
 *   func_02017E88  0x02017E88  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02202670  0x02202670  thumb
 *   func_02020F84  0x02020F84  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021F91A0  0x021F91A0  thumb
 *   func_021FC8A8  0x021FC8A8  thumb
 *   STRBUF_Delete  0x02045808  arm
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

struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_02202670(u32 a, u32 b, u32 c, u32 d);
extern void func_02020F84(void *dst, u32 entry, u32 heap);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern int func_021F91A0(void *p, void *b, u32 c, u32 d, u32 e, u16 f, void *g);
extern u16 func_021FC8A8(int mode);
extern void STRBUF_Delete(struct U16Vec *vec);

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

    nick = STRBUF_Create(0x1a, 0x48);
    ot = STRBUF_Create(0x26, 0x48);
    func_02017E88(mon, 0x73, (u32)nick);
    name = rec->name;
    mode = rec->mode;
    key = rec->key;
    lv = func_02017E88(mon, 6, 0);
    flag = func_02017E88(mon, 0xAD, 0);
    s4f = func_02045EC0(bank, 0x4F);
    smode = func_02045EC0(bank, tbl_02202EB0[mode]);
    s70 = func_02045EC0(bank, 0x70);
    func_0201EFA4(words, 3, key, 3, 0, 1);
    s71 = (void *)func_02202670((u32)words, (u32)bank, 0x71, 0x48);
    sname = func_02045EC0(names, name);
    func_02020F84(ot, (u16)lv, 0x48);
    s41 = func_02045EC0(bank, 0x41);
    for (i = 0; i < 6; i++) {
        BMP_Clear(BMP_WIN_GetBmp(win[i]), 0);
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
    STRBUF_Delete(s4f);
    STRBUF_Delete(ot);
    STRBUF_Delete(s70);
    STRBUF_Delete(s71);
    STRBUF_Delete(smode);
    STRBUF_Delete(nick);
    STRBUF_Delete(sname);
    STRBUF_Delete(s41);
}
