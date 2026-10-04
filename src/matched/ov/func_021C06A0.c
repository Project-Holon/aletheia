/*
 * function: func_021C06A0
 * address:  0x021C06A0
 * packet:   pkt_021C06A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Frees the second word of every entry whose first word is 2.
 */


struct Obj;
extern void func_0204B3B4(struct Obj *p);

typedef struct {
    char pad[0x1e0];
    int arr[0x7a];
} S;

void func_021C06A0(int unused, S *s)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (s->arr[i * 2] == 2)
            func_0204B3B4((struct Obj *)s->arr[i * 2 + 1]);
    }
}
