/*
 * function: func_021CB5F0
 * address:  0x021CB5F0
 * packet:   pkt_021CB5F0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds the six per-party "battle handicap" bytes and writes them to the
 * output record.  Reads the record's u16 fields 0xc and 0x13, asks the
 * battle dispatcher func_02019C90 for a base value per entry of the six
 * entry table at 0x021EFDC0 (6-byte records: u8 at +0, u16 at +2, u16 at
 * +4), doubles them when the mode field 0x12 is 0xd7, then walks the table
 * again to add func_021D805C's value for the entry whose +4 field matches
 * and to fold each result into the savedata record 0x97 through the
 * func_02017E1C/func_02017E40 read/write pair, clamped at 0xff.  The final
 * switch on the loop index is the image's, not a source choice: the table
 * at 0x021CB6F4 is six four-byte arms, case i storing the byte at
 * a2[5 + i].  Ends by releasing the savedata record.
 *
 * symbols:
 *   g_021EFDC0      0x021EFDC0  data  ov093
 *   func_021D5444   0x021D5444  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021D5B40   0x021D5B40  thumb ov093
 *   func_021D5844   0x021D5844  thumb ov093
 *   func_021D805C   0x021D805C  thumb ov093
 *   func_02019C90   0x02019C90  thumb arm9
 *   func_02017D30   0x02017D30  thumb arm9
 *   func_02017D70   0x02017D70  thumb arm9
 *   func_02017E1C   0x02017E1C  thumb arm9
 *   func_02017E40   0x02017E40  thumb arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct T6 { u8 f0; u8 f1; u16 f2; u16 f4; };
extern struct T6 g_021EFDC0[];

extern u16 func_021D5444(void *p);
extern int func_021D59B4(u8 *p, int k);
extern u16 func_021D5B40(void *p);
extern void *func_021D5844(void *m);
extern u32 func_021D805C(u32 v, u32 n);

extern u32 func_02019C90(void *p, u32 a, u32 b);
extern u32 func_02017D30(void *p);
extern u32 func_02017D70(void *p, u32 f);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_02017E40(void *p, u32 id, u32 v);

void func_021CB5F0(u32 *a0, u8 *a1, u8 *a2)
{
    u8 buf[6];
    u8 i;
    u16 v6;
    u32 m;
    u32 t;
    void *rec;
    u32 sv;

    m = func_021D5444(a1);
    v6 = (u16)func_021D59B4(a1, 0x13);
    for (i = 0; i < 6; i++) {
        buf[i] = (u8)func_02019C90((void *)m, v6, g_021EFDC0[i].f0);
    }
    if (func_021D5B40(a0) == 0xd7) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        t = g_021EFDC0[i].f4;
        if (t == func_021D5B40(a0)) {
            buf[i] = (u8)(buf[i] + (u8)func_021D805C(t, 2));
        }
    }
    rec = func_021D5844(a0);
    sv = func_02017D30(rec);
    if (func_02017E1C(rec, 0x97, 0) != 0) {
        for (i = 0; i < 6; i++) {
            buf[i] = buf[i] * 2;
        }
    }
    for (i = 0; i < 6; i++) {
        u8 v;
        u32 w;

        v = buf[i];
        if (v == 0) {
            continue;
        }
        t = g_021EFDC0[i].f2;
        w = func_02017E1C(rec, t, 0) + v;
        if (w > 0xff) {
            w = 0xff;
        }
        func_02017E40(rec, t, w);
        switch (i) {
        case 0: a2[5] = v; break;
        case 1: a2[6] = v; break;
        case 2: a2[7] = v; break;
        case 3: a2[8] = v; break;
        case 4: a2[9] = v; break;
        case 5: a2[0xa] = v; break;
        }
    }
    func_02017D70(rec, sv);
}
