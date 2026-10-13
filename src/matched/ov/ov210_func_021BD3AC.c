/*
 * function: func_021BD3AC
 * address:  0x021BD3AC
 * packet:   pkt_ov210_021BD3AC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (wD5 lane14): EXACT. func_021BFE84 takes the state byte as a
 *   second argument (its matched body uses n); the r1 load was that argument.
 * 2026-10-05 (wD4 lane16): re-read; still the single r1/r0 load at the 0x79 test after func_021C9460. No change tried that moved it (callee arity cannot explain it: the load is after the call).
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (2 bytes: ldrb r1/cmp r1,#0x79 in the image, r0 in ours). Also tried the 0x79 test through a u32 local and p[0x2BB]++ for the tail; no change. Lesson from func_021BE010 (same overlay): a callee that takes the byte as a second argument with r0 untouched explains an r1 load, but no call here does.
 *
 * 2026-10-02 (wave C2 lane 03): re-checked, still the same two bytes at
 * 0x021BD448: the image loads the 0x2bb byte into r1 before `cmp #0x79`.
 * The path into this compare falls through from `func_021C9460(p[0x2cc])`;
 * no later call takes the byte as a second argument (checked
 * 021BED04, 021BED10, 021BFE84).  Next idea: look at the callers' use of
 * func_021C9460 with a second argument.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_StopAllSe  0x02006210  thumb
 *   func_021BCC2C  0x021BCC2C  thumb  ov210
 *   func_021BCF38  0x021BCF38  thumb  ov210
 *   func_021BECF8  0x021BECF8  thumb  ov210
 *   func_021BED04  0x021BED04  thumb  ov210
 *   func_021BED10  0x021BED10  thumb  ov210
 *   func_021BE820  0x021BE820  thumb  ov210
 *   func_021BFE84  0x021BFE84  thumb  ov210
 *   func_021C9428  0x021C9428  thumb  ov212
 *   func_021C9460  0x021C9460  thumb  ov212
 *   func_021C9468  0x021C9468  thumb  ov212
 *
 * Re-verified 2026-09-27 (DIFF fixer lane): size-exact, 2 concrete bytes.
 * The three func_021C94xx symbols were wrongly hinted ov210; they live in
 * ov212's window (ov212 is co-resident with ov210), so the hints are
 * corrected to ov212 and 13 of 14 relocations now resolve.  The two differing
 * bytes are the image's `ldrb r1,[r4,r5] / cmp r1,#0x79` versus the compile's
 * `ldrb r0,... / cmp r0,#0x79` (the dead argument register is reused for the
 * load) -- the same allocator tell as func_021B6984/func_021BEA54.  The last
 * site, func_021C9460, is a Thumb-shaped linker stub (`ldr r3,[pc,#0];
 * bx r3; .word 0x020307B0`) that disasm emits as an unlabelled .word run, so
 * the `veneer` class cannot attest it; only the ARM stub shape attests
 * (docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md).
 *
 * Update 2026-09-27 (recursive MATCH unblocker): 0x021C9460 was matched
 * bottom-up as src/matched/ov212_func_021C9460.c (EXACT, pkt_ov212_021C9460),
 * so the +0096 site now resolves `matched` and all 14 relocations resolve.
 * The verdict is unchanged DIFF on the same two concrete bytes (the r1/r0
 * allocator tell above); target matching cannot promote it.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Search;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GFL_USE_StopAllSe(void);
extern void func_021BCC2C(char *p);
extern void func_021BCF38(u8 *p);
extern void func_021BECF8(void *);
extern void func_021BED04(void *);
extern void func_021BED10(void *);
extern void func_021BE820(u8 *p);
extern void func_021BFE84(int p, int n);
extern int func_021C9428(int, int, int);
extern void func_021C9460(int);
extern int func_021C9468(struct Search *p, u16 heap, u16 *outCount, u16 **out);

int func_021BD3AC(unsigned char *p)
{
    unsigned short v;
    int w;
    int r;

    if (p[0x2BB] == 0) {
        GFL_USE_PlaySeDefaultVolume(0x63F);
        func_021BCC2C((char *)p);
        func_021BECF8(p);
        func_021BE820(p);
    }
    if (p[0x2BB] == 0x64)
        GFL_USE_StopAllSe();
    if (p[0x2BB] == 1) {
        func_021BCF38(p);
        *(int *)(p + 0x2CC) =
            func_021C9428(*(int *)(*(int *)p + 4), *(int *)(*(int *)p + 8), 0x807B);
        *(int *)(p + 0x2D0) = 0;
    }
    if (p[0x2BB] >= 2) {
        if (*(int *)(p + 0x2D0) == 0) {
            r = func_021C9468((struct Search *)(*(int *)(p + 0x2CC)), 0x69, &v, (u16 **)(&w));
            *(int *)(p + 0x2D0) = r;
            if (r == 1) {
                *(unsigned short *)(*(int *)p + 0x14) = v;
                *(int *)(*(int *)p + 0x10) = w;
                func_021C9460(*(int *)(p + 0x2CC));
            }
        }
    }
    if (p[0x2BB] == 0x79) {
        if (*(int *)(p + 0x2D0) == 1) {
            if (*(unsigned short *)(*(int *)p + 0x14) != 0) {
                GFL_USE_PlaySeDefaultVolume(0x76F);
                func_021BED04(p);
            } else {
                GFL_USE_PlaySeDefaultVolume(0x557);
                func_021BED10(p);
            }
            p[0x2BB] = 0;
            return 8;
        }
    } else {
        func_021BFE84((int)p, p[0x2BB]);
        p[0x2BB] = p[0x2BB] + 1;
    }
    return 7;
}
