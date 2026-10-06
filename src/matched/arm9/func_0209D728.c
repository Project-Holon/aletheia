/*
 * unit:     no
 * function: func_0209D728
 * address:  0x0209D728
 * packet:   pkt_0209D728
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocked:  the only occurrences of 0x02153FB4 and 0x02153FB8 in the image are the two
 *           pool words at 0x0209D76C and 0x0209D770, inside this function's own compared
 *           range, so the data class has no outside witness. MATCH, byte-exact.
 * symbols:
 *   g_02153FB4  0x02153FB4  data
 *   g_02153FB8  0x02153FB8  data
 */

typedef unsigned char u8;

typedef struct
{
    u8 b[12];
} Ent;

extern int   g_02153FB4;
extern Ent   g_02153FB8[];
typedef unsigned int   u32;
struct Node;
extern void func_0209D850(u32 a, u32 b, struct Node *node);

int func_0209D728(int a)
{
    int r = 0;

    if (g_02153FB4 == 0x40)
        return -1;

    func_0209D850(r, a, (struct Node *)(&g_02153FB8[g_02153FB4++]));
    return r;
}
