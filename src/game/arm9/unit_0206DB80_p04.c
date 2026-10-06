/*
 * file:     unit_0206DB80_p04.c
 * unit:     yes
 * function: func_0206DDA4, func_0206DE88
 * address:  0x0206DDA4
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214BAB4     0x0214BAB4  data
 *   func_02082B0C  0x02082B0C  arm
 *   func_02082AA8  0x02082AA8  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0206DBDC  0x0206DBDC  arm
 *   func_0207DC98    0x0207DC98  arm
 *   func_0207BDE0    0x0207BDE0  arm
 *   func_0207DCC8    0x0207DCC8  arm
 */
typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };

struct GxState { struct GxList *list; volatile u32 unk_04; };

extern void func_02082B0C(const void *src, void *dst, u32 n);
extern void func_02082AA8(const void *src, void *dst, u32 n);
extern void func_0206DB80(void);
extern void func_0206DBDC(void);
extern u32  func_0207DC98(void *p);
extern void func_0207BDE0(void *p, void *q);
extern u32  func_0207DCC8(void *p);
void func_0206DDA4(u32 cmd, const void *params, u32 n);
void func_0206DE88(void *a, void *b);
extern struct GxState g_0214BAB4;


/*
 * NitroSystem G3D NNS_G3dGeBufferOP_N (gecom.c): append op + num argument
 * words to the current geometry command buffer while a display-list send is
 * in flight and the buffer has room (0xc0 words); otherwise flush the buffer
 * (func_0206DB80) or wait out the send (func_0206DBDC), then write op to
 * GXFIFO 0x04000400 and send the arguments after it (func_02082AA8).
 *
 * The last 46 bytes were one hoisted load: the fix is that the in-flight word
 * at +4 is a VOLATILE FIELD of the one global (never CSE'd between the
 * list != 0 and list == 0 arms), not a second volatile declaration of the
 * same address. Under dsi/1.1p1 the same C pushes {r3-r7,lr}; pinned
 * ../2.0/sp2 as the rest of the cluster.
 */
void func_0206DDA4(u32 cmd, const void *params, u32 n)
{
    if (g_0214BAB4.list != 0) {
        if (g_0214BAB4.unk_04 != 0) {
            u32 count = g_0214BAB4.list->count;
            if (count + 1 + n <= 0xc0) {
                g_0214BAB4.list->count = count + 1;
                g_0214BAB4.list->cmds[count] = cmd;
                if (n == 0)
                    return;
                func_02082B0C(params,
                              &g_0214BAB4.list->cmds[g_0214BAB4.list->count],
                              n * 4);
                g_0214BAB4.list->count += n;
                return;
            }
        }
        if (g_0214BAB4.list->count != 0) {
            func_0206DB80();
        } else if (g_0214BAB4.unk_04 != 0) {
            func_0206DBDC();
        }
    } else if (g_0214BAB4.unk_04 != 0) {
        func_0206DBDC();
    }
    *(u32 *)0x04000400 = cmd;
    func_02082AA8(params, (void *)0x04000400, n * 4);
}


/*
 * The 3D-engine reset path: drain the pending display list (func_0206DB80),
 * zero GXFIFO's control words at 0x04000440/0x04000444/0x04000454, then, if a
 * matrix block was given, spin func_0207DC98 on a 0x40-byte stack scratch
 * until it reports ready and hand the pair to func_0207BDE0; if a second block
 * was given, spin func_0207DCC8 on it; finally write 1 to 0x04000448 and 2 to
 * 0x04000440 (the store to 0x04000440 is spelled `str r0, [r1, #-8]` off the
 * 0x04000448 pool word, so the two are one base in the original too).
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, and the sibling
 * src/matched/func_0206DB80.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DE88.c \
 *       --func func_0206DE88 --addr 0x0206DE88 --cc ../2.0/sp2 --arm
 */
void func_0206DE88(void *a, void *b)
{
    u32 tmp[0x10];

    func_0206DB80();
    *(u32 *)0x04000440 = 0;
    *(u32 *)0x04000444 = 0;
    *(u32 *)0x04000454 = 0;
    if (a != 0) {
        while (func_0207DC98(tmp) != 0)
            ;
        func_0207BDE0(tmp, a);
    }
    if (b != 0) {
        while (func_0207DCC8(b) != 0)
            ;
    }
    *(u32 *)0x04000448 = 1;
    *(u32 *)0x04000440 = 2;
}
