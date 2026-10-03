/*
 * function: func_021DD3DC
 * address:  0x021DD3DC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD314  0x021DD314  thumb  ov170
 *   func_021EDAB0  0x021EDAB0  thumb  ov170
 *
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */


typedef unsigned int u32;

extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *p);
extern void func_020075B0(int, int, int, int);
extern void func_021DD314(char *, int, unsigned);
extern void func_021EDAB0(char *, int);
void func_021DD3DC(char *p, unsigned char *a)
{
    int x = (int)func_020185F4(func_0201AB28(*(void **)(*(int *)p + 8),
                                        *(unsigned short *)(a + 4) - 0x1e));
    func_020075B0(*(int *)(*(int *)p + 4), *(unsigned char *)(p + 0x14),
                  *(unsigned short *)(a + 2), x);
    func_021DD314(p, *(unsigned char *)(p + 0x14), *(unsigned short *)(a + 4));
    func_021EDAB0(p, *(unsigned char *)(p + 0x14));
}
