/*
 * function: func_0206DDA4
 * address:  0x0206DDA4
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
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
 *
 * symbols:
 *   g_0214BAB4     0x0214BAB4  data
 *   func_02082B0C  0x02082B0C  arm
 *   func_02082AA8  0x02082AA8  arm
 *   func_0206DB80  0x0206DB80  arm
 *   func_0206DBDC  0x0206DBDC  arm
 */

typedef unsigned int u32;

struct GxList { u32 count; u32 cmds[1]; };
struct GxState { struct GxList *list; volatile u32 unk_04; };
extern struct GxState g_0214BAB4;

extern void func_02082B0C(const void *src, void *dst, u32 n);
extern void func_02082AA8(const void *src, void *dst, u32 n);
extern void func_0206DB80(void);
extern void func_0206DBDC(void);

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

