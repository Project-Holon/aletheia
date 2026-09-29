/*
 * function: func_0216F31C
 * address:  0x0216F31C
 * packet:   pkt_ov010_0216F31C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct. Blocker: func_0200E714 (site +004C) is an unlabelled ARM9 Thumb
 * leaf (copies four halfwords to dst[idx*4]) whose only caller is this
 * function; no witness. Its C is parked: docs/notes/pkt_ov010_0200E714.c.txt
 * (register naming r3/r4 swapped).
 *
 * symbols:
 *   func_0216F088  0x0216F088  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E714  0x0200E714  thumb
 *   func_0202715C  0x0202715C  thumb
 */

typedef unsigned short u16;

extern int func_0216F088(void *p);
extern void func_02012EBC(int p);
extern int func_0200E6F0(void);
extern void func_0200E714(int a, int b, void *c);
extern void func_0202715C(void *p);

int func_0216F31C(char *a)
{
    char *w;
    u16 *src;
    int t;

    if (func_0216F088(a + 8) == 0)
        return 4;
    if (*(u16 **)(a + 0x14) != 0) {
        func_02012EBC(*(int *)(*(char **)(a + 0x18) + 4));
        t = func_0200E6F0();
        w = **(char ***)(a + 0x18);
        src = *(u16 **)(a + 0x14);
        *(u16 *)(w + 0x6c) = src[0];
        *(u16 *)(w + 0x6e) = src[1];
        *(u16 *)(w + 0x70) = src[2];
        *(u16 *)(w + 0x72) = src[3];
        func_0200E714(t, 0, *(void **)(a + 0x14));
        func_0202715C(*(void **)(a + 0x14));
    }
    return 1;
}
