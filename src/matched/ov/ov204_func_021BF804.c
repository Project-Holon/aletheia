/*
 * function: func_021BF804
 * address: 0x021BF804
 * packet: pkt_ov204_021BF804
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_02015E04 0x02015E04 thumb

 */

struct Vec { int v[3]; };
typedef unsigned int   u32;
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_02015E04(void *);

int func_021BF804(char *p, unsigned int i, int step, int limit)
{
    struct Vec pos;
    char *base = p + 8;
    unsigned int off = i * 12;
    int done;
    func_02015C30(*(void **)(base + off), (u32 *)(&pos));
    done = 1;
    pos.v[0] += step;
    if (pos.v[0] != limit)
    {
        if ((step > 0 && pos.v[0] > limit) || (step < 0 && pos.v[0] < limit))
            pos.v[0] = limit;
        else
            done = 0;
    }
    func_02015C48(*(void **)(base + off), (u32 *)(&pos));
    if (*(unsigned int *)(p + off + 12) == 1)
        func_02015E04(*(void **)(base + off));
    return done;
}
