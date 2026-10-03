/*
 * function: func_0216869C
 * address:  0x0216869C
 * packet:   pkt_ov010_0216869C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through func_02017E1C goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 *
 * symbols:
 *   func_02017528  0x02017528  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02045924  0x02045924  arm
 *   func_02045808  0x02045808  arm
 *   func_02018430  0x02018430  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct BattleMon {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 ivs;            /* 0x14 */
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 f20;             /* 0x20 */
    u8 f21;             /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 f38;             /* 0x38 */
} BattleMon;

struct Mon;
struct Sav;
struct Strbuf;
struct U16Vec;
extern void func_02017528(struct Sav *p);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020185B0(void *p, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02018430(void *p);

void func_0216869C(const BattleMon *src, void *mon)
{
    u16 name[11];
    void *buf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *n;

    func_02017528(mon);
    func_02017588(mon, src->species, 50, (u64)-1, src->ivs & 0x3FFFFFFF, src->pid);
    func_02017E40(mon, 0x6F, (u8)src->form);
    func_02017E40(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        func_02017E40(mon, 0x36 + i, src->moves[i]);
        func_02017E40(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = func_02017E1C(mon, 0x42 + i, 0);
        func_02017E40(mon, 0x3A + i, pp);
    }
    func_02017E40(mon, 7, src->otId);
    func_02017E40(mon, 0xD, src->ev[0]);
    func_02017E40(mon, 0xE, src->ev[1]);
    func_02017E40(mon, 0xF, src->ev[2]);
    func_02017E40(mon, 0x10, src->ev[3]);
    func_02017E40(mon, 0x11, src->ev[4]);
    func_02017E40(mon, 0x12, src->ev[5]);
    func_02017E40(mon, 0xA, src->f20);
    func_02017E40(mon, 9, src->f21);
    func_020185B0(mon, src->f38);
    buf = func_020457B0(11, 4);
    eos = func_02045A98();
    n = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = n[i];
    name[i - 1] = eos;
    func_02045924(buf, name);
    func_02017E40(mon, 0x73, (u32)buf);
    func_02045808(buf);
    func_02017E40(mon, 0xC, src->lang);
    func_02017E40(mon, 0x9E, func_02018430(mon));
}
