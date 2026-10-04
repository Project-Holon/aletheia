/*
 * function: func_021BF744, func_021BF77C
 * unit: yes
 * address: 0x021BF744
 * packet: pkt_ov204_021BF744
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 10-byte getter follower 0x021BF77C is included; function_starts seed. Enum zero separates field and argument clears.
 * symbols:
 *   func_02016028 0x02016028 thumb
 *   func_02015E4C 0x02015E4C thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 */

extern void func_02016028(void *, unsigned int);
extern void func_02015E4C(void *);
typedef unsigned char  u8;
extern void func_021BF7F0(u8 *p);
extern void func_02015F2C(void *, void *, void (*)(void *, void *), int);

void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v)
{
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    func_02016028(*(void **)(base + off), flag);
    func_02015E4C(*(void **)(base + off));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = v;
    func_02015F2C(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}

unsigned int func_021BF77C(char *p, unsigned int i)
{
    return *(unsigned int *)(p + i * 12 + 12);
}
