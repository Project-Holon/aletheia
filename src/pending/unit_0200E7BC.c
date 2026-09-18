/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0200E7BC
 * packet:   pkt_0200E7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, 138 concrete bytes: the whole body is right -- all 12
 *           relocations resolve, the push set and frame match, the bitfield
 *           truncation matches -- but mwccarm binds the record pointer to
 *           r6 and the save object to r5 where the original swaps them
 *           (r5 = the base, r6 = the object, r7 = idx*32).  Seven spellings
 *           of the pointer (struct-pointer arithmetic, a separate offset
 *           local, a re-spelled field access, struct-typed and dummy-struct
 *           parameters) all leave the pair swapped; the decisive shuffle is
 *           the register-number tie between two live-across-call pointers.
 * function: func_0200E7BC, sub_0200E874, sub_0200E878
 *
 * symbols:
 *   func_02017E1C   0x02017E1C  thumb
 *   func_02045F5C   0x02045F5C  arm
 *   func_0201F41C   0x0201F41C  thumb
 *   func_02082BCC   0x02082BCC  arm
 *   g_020A7370      0x020A7370  data
 *
 * One record load out of the save object behind func_02017E1C, plus the two
 * unlabelled leaves that follow it (see below).  The record is 32 bytes
 * (`lsls r7, r1, #5`), its key is the second parameter and the third is the
 * object func_02017E1C reads from; every field is one call with its own
 * one-byte key, which is what makes the sequence so easy to read back:
 *
 *   0x9e -> the seven-bit field at +0x1a
 *   0x71 -> gates the byte at +0x1b: 0x0a's value if set, else 0xff
 *   0x00 -> the word at +0
 *   0x07 -> the word at +0x1c
 *   0x75 -> gates the 11-character name at +4: 0x74's value written straight
 *           into the record if set, else key 5's id handed to the message
 *           bank (func_02045F5C) and the buffer copied in with the
 *           wide-string bounded copy func_0201F41C
 *
 * then bit 0 of +0x1a is set to mark the record loaded.  The two fields of
 * that byte are the two halves of one bitfield, which is why the seven-bit
 * store truncates its argument to eight bits first (docs/idioms/
 * a-bitfields-base-type-shows-up-as-a-redundant-truncation-of-the-argument.md).
 *
 * The last two functions are unlabelled leaves: sub_0200E874 returns 0x10
 * and sub_0200E878 tail-calls the SDK's MI_CpuFill8 (arm -- the pool word is
 * even, so `bx r3` switches to ARM).  Both save nothing, so disasm.py prints
 * their bytes as part of the same `.word` run as the pool word in front of
 * them (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md), and the
 * listing's extent for func_0200E7BC therefore runs over all three.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Bits0200E7BC {
    u8 flag : 1;
    u8 val : 7;
};

struct Rec0200E7BC {
    u32 f0;
    u16 name[11];               /* +0x04 */
    u8  pad1a;                  /* +0x1a is the bitfield below */
    struct Bits0200E7BC bits;
    u8  b1b;                    /* +0x1b */
    u32 f1c;                    /* +0x1c */
};

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02045F5C(void *bank, u32 id, void *dest, u32 n);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
extern void func_02082BCC(void *dst, int value, u32 size);
extern u32 g_020A7370;

void func_0200E7BC(char *o, int idx, void *st)
{
    struct Rec0200E7BC *r = (struct Rec0200E7BC *)(o + idx * 32);

    r->bits.val = func_02017E1C(st, 0x9e, 0);
    if (func_02017E1C(st, 0x71, 0) != 0)
        r->b1b = func_02017E1C(st, 0xa, 0);
    else
        r->b1b = 0xff;
    r->f0 = func_02017E1C(st, 0, 0);
    r->f1c = func_02017E1C(st, 7, 0);
    if (func_02017E1C(st, 0x75, 0) != 0) {
        func_02017E1C(st, 0x74, (u32)r->name);
    } else {
        u16 buf[12];

        func_02045F5C((void *)g_020A7370, func_02017E1C(st, 5, 0),
                      buf, 0xb);
        func_0201F41C(buf, r->name, 0xb);
    }
    r->bits.flag = 1;
}

int sub_0200E874(void)
{
    return 0x10;
}

void sub_0200E878(void *dst)
{
    func_02082BCC(dst, 0, 0x10);
}
