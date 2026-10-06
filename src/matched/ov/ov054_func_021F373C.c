/*
 * function: func_021F373C
 * address:  0x021F373C
 * packet:   pkt_ov054_021F373C
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 2026-10-05 (wave D5 lane 02): arm9 func_0202B93C re-verified EXACT (Thumb) and filed as src/matched/arm9/func_0202B93C.c; unresolved site clears once labelled.
 * 2026-10-05 (wD4 lane19): still MATCH*. Blocked by arm9 0x0202B93C (parked MATCH in src/pending/arm9, no label).
 *
 * 2026-10-04 (wave D2 lane 14): re-checked, still MATCH. func_0202B93C is parked as MATCH in
 * src/pending/arm9/func_0202B93C.c; its callee func_0202BA9C (Thumb, 30 bytes, copies two 3-word
 * vectors to p+0xC and p+0x18) is now EXACT in src/matched/arm9/func_0202BA9C.c. The remaining
 * unresolved site (+0034) needs 0x0202B93C and 0x0202BA9C to be labelled or in a shard.
 *
 * Blocker (older note): func_0202B93C (arm9, unlabelled tail-call stub, Ilias's) has no
 * witness.  Its verified C (MATCH, 8 bytes):
 *   extern void func_0202BA9C(int, void *, void *);
 *   void func_0202B93C(int a, void *b, void *c) { func_0202BA9C(a, b, c); }
 *   symbols: func_0202BA9C 0x0202BA9C thumb
 * Callee 0x021F3918 (ov054, 36 B) is unmatched but resolves sole-ref/code.
 *
 * symbols:
 *   func_021897BC  0x021897BC  thumb
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218EC2C  0x0218EC2C  thumb  ov021
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0202B93C  0x0202B93C  thumb
 *   func_021C4DE4  0x021C4DE4  thumb  ov021
 *   func_021F393C  0x021F393C  thumb  ov054
 *   func_021F3918  0x021F3918  thumb  ov054
 */

extern void *func_021897BC(int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_02188C58(void *p);
extern u32 func_0218EC2C(u8 *p);
extern void func_02048AE8(void *, void *);
extern void func_02048B30(void *, void *);
extern void func_0202B93C(int, void *, void *);
extern int func_021C4DE4(int, int);
extern int func_021F393C(char *, int);
extern void func_021F3918(char *, int);

void func_021F373C(int a)
{
    int i;
    char *p;
    void *cam;
    int v[3];
    int w[3];

    p = (char *)func_021897BC(a, 0);
    cam = (void *)func_0218EC2C(func_02188C58((void *)a));
    func_02048AE8(cam, v);
    func_02048B30(cam, w);
    func_0202B93C(*(int *)(p + 4), v, w);
    for (i = 0; i < 2; i++) {
        int *e = (int *)(p + i * 4);
        if (e[4] > 0) {
            e[4]--;
            if (e[4] <= 0)
                func_021F393C(p, i);
        } else if (func_021C4DE4(e[2], 0x1000)) {
            func_021F3918(p, i);
        }
    }
}
