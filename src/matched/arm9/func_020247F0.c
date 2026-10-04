/*
 * function: func_020247F0
 * address:  0x020247F0
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

struct Rec;
extern void func_02045C04(struct Rec *rec);
extern void func_020307B0(void *p);
void func_020247F0(char *p)
{
    int i;
    for (i = 0; i < 0xd; i++)
        func_02045C04((struct Rec *)(*(int *)(p + 4 + i * 4)));
    func_020307B0(p);
}
